#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"
#include "../model/api_conflict_error.h"
#include "../model/api_error.h"
#include "../model/api_not_found_error.h"
#include "../model/create_image_body.h"
#include "../model/get_firmware_info_body.h"
#include "../model/image.h"
#include "../model/image_firmware_info.h"
#include "../model/image_list.h"
#include "../model/install_firmware_assets_body.h"
#include "../model/install_firmware_assets_response.h"
#include "../model/install_firmware_body.h"
#include "../model/install_firmware_response.h"
#include "../model/install_firmware_status_response.h"
#include "../model/insufficient_storage_error.h"
#include "../model/object.h"
#include "../model/upload_size_error.h"
#include "../model/user_error_response.h"


// Create an image
//
// Creates a new Image record, optionally uploading file contents in the same request.   Two content types are supported:   - `application/json`: creates metadata only. The caller subsequently uploads the file via     [`uploadImageData`](#operation/uploadImageData). Returns 201.   - `multipart/form-data`: creates metadata and uploads the file in a single request. Returns 200.   The `fullPath` field references a file already present on the server's local filesystem and bypasses the upload step entirely; this is intended for cluster-internal use.   For firmware images, this is step 1 of the install workflow — see [`installFirmware`](#operation/installFirmware) or [`installFirmwareAssets`](#operation/installFirmwareAssets).
//
image_t*
ImagesAPI_v3CreateImage(apiClient_t *apiClient, create_image_body_t *create_image_body);


// Delete an image
//
// Permanently deletes the image. This action cannot be undone. Deleting an already-deleted image returns 404.
//
void
ImagesAPI_v3DeleteImage(apiClient_t *apiClient, char *imageId);


// Get image metadata
//
// Returns metadata for a single image. File contents are not returned; use [`downloadImageFile`](#operation/downloadImageFile) to fetch contents.
//
image_t*
ImagesAPI_v3GetImage(apiClient_t *apiClient, char *imageId);


// Check whether an image chunk was already uploaded
//
// Probes whether a single chunk of a chunked upload is already stored, so an interrupted upload can resume without re-sending data. Used together with [`uploadImageChunk`](#operation/uploadImageChunk).   Returns 200 when the chunk is present and 204 when it still needs to be uploaded. The chunk is identified exactly as in the upload request, by `resumableChunkNumber`, `resumableChunkSize` and `resumableCurrentChunkSize`, all of which are required. The image must already exist; an unknown `imageId` is a 404 rather than a 204.
//
object_t*
ImagesAPI_v3GetImageChunk(apiClient_t *apiClient, char *imageId, double *resumableChunkNumber, double *resumableChunkSize, double *resumableCurrentChunkSize);


// Get firmware info embedded in an image
//
// Extracts and returns the firmware metadata embedded in an uploaded image (IPSW, COREIMG, CLBI, UFD, or extension). For an encrypted image, supply `password` to decrypt it. Set `extended` to also resolve the matching supported device model.
//
image_firmware_info_t*
ImagesAPI_v3GetImageFirmwareInfo(apiClient_t *apiClient, char *imageId, get_firmware_info_body_t *get_firmware_info_body);


// Get install-firmware task status
//
// Returns the current status of a firmware installation task previously created via [`installFirmware`](#operation/installFirmware). Clients should poll this endpoint until `status` is `complete` or `error`.
//
install_firmware_status_response_t*
ImagesAPI_v3GetInstallFirmwareStatus(apiClient_t *apiClient, char *taskId);


// Install firmware cluster-wide
//
// Installs an uploaded firmware image for cluster-wide use. On success the source Image is deleted from the Images store, since ownership transfers to the firmware service. Installation runs asynchronously; this endpoint returns a `taskId` that callers must poll via [`getInstallFirmwareStatus`](#operation/getInstallFirmwareStatus).   **This is step 3 of the firmware-install workflow:**   1. [`createImage`](#operation/createImage) with `{ name, type: 'fw' }` → returns an `imageId`.   2. [`uploadImageData`](#operation/uploadImageData) with the firmware file → uploads contents.   3. **`installFirmware`** with `{ imageId }` → returns a `taskId`.   4. [`getInstallFirmwareStatus`](#operation/getInstallFirmwareStatus) → poll until `status` is `complete` or `error`.   Large firmware blobs (~10 GB) are supported; installation has a 45-minute server-side timeout.
//
install_firmware_response_t*
ImagesAPI_v3InstallFirmware(apiClient_t *apiClient, install_firmware_body_t *install_firmware_body);


// Install firmware assets cluster-wide
//
// Installs an uploaded firmware-assets JSON blob for cluster-wide use. On success the source Image is deleted from the Images store. The blob is forwarded to the firmware service, which merges it into the cluster-wide firmware-assets manifest.   **This is step 3 of the firmware-assets-install workflow:**   1. [`createImage`](#operation/createImage) with `{ name: 'fcs-keys.json', type: 'fwasset' }` → returns an `imageId`.   2. [`uploadImageData`](#operation/uploadImageData) with the assets file → uploads contents.   3. **`installFirmwareAssets`** with `{ imageId }` → installs the assets.   Unlike [`installFirmware`](#operation/installFirmware), this endpoint completes synchronously and returns the firmware service's response message directly; there is no task to poll.
//
install_firmware_assets_response_t*
ImagesAPI_v3InstallFirmwareAssets(apiClient_t *apiClient, install_firmware_assets_body_t *install_firmware_assets_body);


// List image metadata
//
// Returns metadata for all authenticated user images. Optionally filtered by project. File contents are not returned; use [`downloadImageFile`](#operation/downloadImageFile) to fetch contents.
//
image_list_t*
ImagesAPI_v3ListImages(apiClient_t *apiClient, double *limit, double *offset, char *projectId);


// Upload one chunk of an image file
//
// Uploads a single chunk of an Image previously created via [`createImage`](#operation/createImage), using the resumable upload protocol. This is the recommended way to upload large images: the transfer survives interruptions, because any chunk can be re-sent and already-stored chunks can be skipped.   **Chunked upload workflow:**   1. [`createImage`](#operation/createImage) with `{ name, type, encoding }` → returns an `imageId`.   2. Split the file into fixed-size chunks and **`uploadImageChunk`** each one with the      `resumable*` query parameters describing it. Chunks may be uploaded in any order and      concurrently.   3. Optionally probe a chunk with [`getImageChunk`](#operation/getImageChunk) before      (re-)sending it, so an interrupted upload only re-sends what is missing.   The image is finalized automatically by the request that completes the chunk set, so the last chunk to arrive also validates `corelliumChecksum` (when supplied) and runs the firmware post-processing. Re-sending a chunk that was already stored is safe. If the upload fails for any reason other than a retryable transport error, the partially uploaded image is deleted, so the client must create a new image record before retrying.   The image's `encoding` and `encapsulated` settings are fixed when the record is created by [`createImage`](#operation/createImage) and cannot be changed by a chunk request.
//
void
ImagesAPI_v3UploadImageChunk(apiClient_t *apiClient, char *imageId, double *resumableChunkNumber, double *resumableChunkSize, double *resumableCurrentChunkSize, double *resumableTotalSize, double *resumableTotalChunks, binary_t* body, char *resumableIdentifier, char *resumableFilename, char *resumableRelativePath, char *resumableType, char *corelliumChecksum, char *x_corellium_total_file_size);


// Upload image file contents
//
// Uploads file contents into an Image previously created via [`createImage`](#operation/createImage). The image's owning project must have sufficient remaining quota. Accepts multipart/form-data; the optional `corelliumChecksum` query parameter, when supplied, is verified against the upload.   This endpoint uploads the whole file in a single request. For large images (firmware in particular) upload the file in chunks instead — see [`uploadImageChunk`](#operation/uploadImageChunk).
//
image_t*
ImagesAPI_v3UploadImageData(apiClient_t *apiClient, char *imageId, binary_t* file, char *corelliumChecksum);


