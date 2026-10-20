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
// Creates an image: a stored file such as firmware, a kernel, a partition, or a MATRIX wordlist. Every upload starts here. The response is the new image, including its `id`.  **Choosing how to upload the file:**   - **Two steps (recommended).** Send this request as `application/json` without a file; it returns **201**. Then upload the contents with [`uploadImageData`](#tag/images/POST/v3/images/{imageId}) (one request) or [`uploadImageChunk`](#tag/images/PUT/v3/images/{imageId}/file) (in pieces, resumable, best for large files). This is the only way to have the server verify the file against a `corelliumChecksum`.   - **One step.** Send this request as `multipart/form-data` with the file in a `file` part; it returns **200** once the file is stored. Put the `type` field before the `file` part. Convenient for small files, but no checksum verification.  The response body is the same image in both cases; the status code (201 or 200) tells you whether the file was included.  **Where the image lives** depends on the optional IDs:   - `instanceId` set: attached to that device. Replaces the device's existing image of the same type.   - `projectId` set: stored in that project and counted against its quota.   - Neither: a domain-level image. Domain-level `fw` and `clbi` images are also offered when you create a device, in addition to installed firmware. See the `projectId` and `instanceId` fields for side effects.  Other upload endpoints (`PUT /v3/projects/{projectId}/image-upload/...`, `PUT /v3/instances/{instanceId}/image-upload/...`, `PUT /v3/domain/image-upload/...`) use the same chunked protocol but create the image on the first chunk instead of requiring this call. They exist mainly for the web interface; new code should use this endpoint followed by [`uploadImageChunk`](#tag/images/PUT/v3/images/{imageId}/file).  `name` is not unique; sending the same request twice creates two images. For firmware, continue with [`installFirmware`](#tag/images/POST/v3/images/install-firmware) or [`installFirmwareAssets`](#tag/images/POST/v3/images/install-firmware-assets).
//
image_t*
ImagesAPI_v3CreateImage(apiClient_t *apiClient, create_image_body_t *create_image_body);


// Delete an image
//
// Permanently deletes the image. This action cannot be undone.  Deletion is synchronous. Deletes are idempotent: an unknown `imageId`, or an image that has already been deleted, is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing.
//
void
ImagesAPI_v3DeleteImage(apiClient_t *apiClient, char *imageId);


// Get image metadata
//
// Returns metadata for a single image. File contents are not returned by this endpoint.
//
image_t*
ImagesAPI_v3GetImage(apiClient_t *apiClient, char *imageId);


// Check whether an image chunk was already uploaded
//
// Probes whether a single chunk of a chunked upload is already stored, so an interrupted upload can resume without re-sending data. Used together with [`uploadImageChunk`](#tag/images/PUT/v3/images/{imageId}/file).   Returns 200 when the chunk is present and 204 when it still needs to be uploaded. The chunk is identified exactly as in the upload request, by `resumableChunkNumber`, `resumableChunkSize` and `resumableCurrentChunkSize`, all of which are required. The image must already exist; an unknown `imageId` is a 404 rather than a 204.
//
object_t*
ImagesAPI_v3GetImageChunk(apiClient_t *apiClient, char *imageId, double *resumableChunkNumber, double *resumableChunkSize, double *resumableCurrentChunkSize);


// Get firmware info embedded in an image
//
// Reads the version information built into an uploaded firmware file, without installing it or creating a device. Use it to check what a file is before you install it or create a device from it: which operating-system version and build it contains, and which device models it supports.  Works on these kinds of uploaded files: an Apple iOS firmware file (IPSW), a Corellium firmware package (`.coreimg`), a Cellebrite firmware image, a Cellebrite extraction (UFD), and a Corellium extension. The image must be fully uploaded first; see [`createImage`](#tag/images/POST/v3/images).  The request body is optional:   - `password`: needed only if the file is encrypted. A wrong password returns 400.   - `extended`: set to `true` to also get chip and board details and the supported device model this firmware matches (`device`). Use the matched model's `flavor` when you create an instance.  Returns 404 if the image does not exist, or if the file contains no version information that can be read (for example, it is not firmware).
//
image_firmware_info_t*
ImagesAPI_v3GetImageFirmwareInfo(apiClient_t *apiClient, char *imageId, get_firmware_info_body_t *get_firmware_info_body);


// Get install-firmware task status
//
// Returns the current status of a firmware installation task previously created via [`installFirmware`](#tag/images/POST/v3/images/install-firmware). Clients should poll this endpoint until `status` is `complete` or `error`.
//
install_firmware_status_response_t*
ImagesAPI_v3GetInstallFirmwareStatus(apiClient_t *apiClient, char *taskId);


// Install firmware cluster-wide
//
// Makes an uploaded `fw` image available for creating devices across the whole cluster. After it is installed, the firmware appears in `GET /v3/models/{model}/software` for the matching model and can be chosen when creating an instance.  **Workflow:**   1. [`createImage`](#tag/images/POST/v3/images) with `{ \"name\": \"...\", \"type\": \"fw\", \"encoding\": \"plain\" }` as JSON. Keep the returned `id`.   2. Upload the file with [`uploadImageData`](#tag/images/POST/v3/images/{imageId}) or, for large files, [`uploadImageChunk`](#tag/images/PUT/v3/images/{imageId}/file). Supplying `corelliumChecksum` there lets the server verify the file.   3. **`installFirmware`** with `{ \"imageId\": \"<id>\" }`. Returns a `taskId`.   4. Poll [`getInstallFirmwareStatus`](#tag/images/GET/v3/images/install-firmware/{taskId}) with the `taskId` until `status` is `complete` or `error`.  **What happens.** The server hands the file to the firmware service and returns 201 with a `taskId` as soon as the hand-off succeeds; installation continues in the background and can take a long time (up to 45 minutes for files around 10 GB). The source image is deleted from `/v3/images` at the moment of hand-off, before installation finishes. If installation then fails, upload the file again to retry.  A 400 can mean the firmware service rejected the image's checksum. Check that the file uploaded completely and, if you supplied `corelliumChecksum`, that it was correct.
//
install_firmware_response_t*
ImagesAPI_v3InstallFirmware(apiClient_t *apiClient, install_firmware_body_t *install_firmware_body);


// Install firmware assets cluster-wide
//
// Installs an uploaded firmware-assets JSON blob for cluster-wide use. On success the source Image is deleted from the Images store. The blob is forwarded to the firmware service, which merges it into the cluster-wide firmware-assets manifest.   **This is step 3 of the firmware-assets-install workflow:**   1. [`createImage`](#tag/images/POST/v3/images) with `{ name: 'fcs-keys.json', type: 'fwasset' }` → returns an `imageId`.   2. [`uploadImageData`](#tag/images/POST/v3/images/{imageId}) with the assets file → uploads contents.   3. **`installFirmwareAssets`** with `{ imageId }` → installs the assets.   Unlike [`installFirmware`](#tag/images/POST/v3/images/install-firmware), this endpoint completes synchronously and returns the firmware service's response message directly; there is no task to poll.
//
install_firmware_assets_response_t*
ImagesAPI_v3InstallFirmwareAssets(apiClient_t *apiClient, install_firmware_assets_body_t *install_firmware_assets_body);


// List image metadata
//
// Lists the images you can see: images in your projects plus domain-level images. File contents are not included; use the download or upload endpoints for those.  Set `projectId` to list only one project's images. Results are paginated with `limit` and `offset`.  Installed firmware is not listed here: once `installFirmware` hands an image off, it disappears from this list and shows up in `GET /v3/models/{model}/software` instead.
//
image_list_t*
ImagesAPI_v3ListImages(apiClient_t *apiClient, double *limit, double *offset, char *projectId);


// Upload one chunk of an image file
//
// Uploads a single chunk of an Image previously created via [`createImage`](#tag/images/POST/v3/images), using the resumable upload protocol. This is the recommended way to upload large images: the transfer survives interruptions, because any chunk can be re-sent and already-stored chunks can be skipped.   **Chunked upload workflow:**   1. [`createImage`](#tag/images/POST/v3/images) with `{ name, type, encoding }` → returns an `imageId`.   2. Split the file into fixed-size chunks and **`uploadImageChunk`** each one with the      `resumable*` query parameters describing it. Chunks may be uploaded in any order and      concurrently.   3. Optionally probe a chunk with [`getImageChunk`](#tag/images/GET/v3/images/{imageId}/file) before      (re-)sending it, so an interrupted upload only re-sends what is missing.   The image is finalized automatically by the request that completes the chunk set, so the last chunk to arrive also validates `corelliumChecksum` (when supplied) and runs the firmware post-processing. Re-sending a chunk that was already stored is safe. If the upload fails for any reason other than a retryable transport error, the partially uploaded image is deleted, so the client must create a new image record before retrying.   The image's `encoding` and `encapsulated` settings are fixed when the record is created by [`createImage`](#tag/images/POST/v3/images) and cannot be changed by a chunk request.
//
void
ImagesAPI_v3UploadImageChunk(apiClient_t *apiClient, char *imageId, double *resumableChunkNumber, double *resumableChunkSize, double *resumableCurrentChunkSize, double *resumableTotalSize, double *resumableTotalChunks, binary_t* body, char *resumableIdentifier, char *resumableFilename, char *resumableRelativePath, char *resumableType, char *corelliumChecksum, char *x_corellium_total_file_size);


// Upload image file contents
//
// Uploads the whole file for an image created with [`createImage`](#tag/images/POST/v3/images), in a single `multipart/form-data` request with the file in the `file` part. Returns the updated image, whose `size` and checksums are now filled in.  Supply `corelliumChecksum` to have the server verify the file: if the uploaded contents do not match, the upload is rejected with 400 and the image is removed. Compute it with the same algorithm and block size you pass in the value (`algorithm$blockSize$hash`).  The upload counts against the owning project's storage quota. If the connection drops, the whole file must be sent again. For large images (firmware in particular) use [`uploadImageChunk`](#tag/images/PUT/v3/images/{imageId}/file), which can resume.
//
image_t*
ImagesAPI_v3UploadImageData(apiClient_t *apiClient, char *imageId, binary_t* file, char *corelliumChecksum);


