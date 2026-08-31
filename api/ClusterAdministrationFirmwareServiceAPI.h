#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"
#include "../model/api_conflict_error_v1.h"
#include "../model/api_error_v1.h"
#include "../model/api_not_found_error_v1.h"
#include "../model/device.h"
#include "../model/extended_firmware_asset_info_v1.h"
#include "../model/firmware_asset_v1.h"
#include "../model/firmware_service_configuration.h"
#include "../model/firmware_v1.h"
#include "../model/image_creation_options.h"
#include "../model/image_v1.h"
#include "../model/install_firmware_assets_body_v1.h"
#include "../model/install_firmware_assets_response_v1.h"
#include "../model/install_firmware_body_v1.h"
#include "../model/install_firmware_response_v1.h"
#include "../model/insufficient_storage_error_v1.h"
#include "../model/object.h"
#include "../model/user_error_v1.h"


// Add firmware assets via the firmware service
//
// Proxies a request to the firmware service to add firmware assets.
//
char*
ClusterAdministrationFirmwareServiceAPI_v1CreateAssetsFirmwareService(apiClient_t *apiClient, object_t *body);


// Create a new Image
//
// Create a new Image. Accepts multipart/form-data (with optional file upload) or application/json (metadata only).
//
image_v1_t*
ClusterAdministrationFirmwareServiceAPI_v1CreateImage(apiClient_t *apiClient, image_creation_options_t *image_creation_options);


// Delete a firmware asset by its URL
//
// Proxies a request to the firmware service to delete a firmware asset by URL.
//
void
ClusterAdministrationFirmwareServiceAPI_v1DeleteAssetFirmwareService(apiClient_t *apiClient, char *assetURL);


// Delete a firmware by filename from the firmware service
//
// Proxies a request to the firmware service to delete a firmware by filename.
//
void
ClusterAdministrationFirmwareServiceAPI_v1DeleteFirmwareFirmwareService(apiClient_t *apiClient, char *filename);


// Fetch extended firmware-asset details including instances and associated IPSWs
//
// Retrieves extended information about a firmware including all instances using it and associated firmware assets.
//
extended_firmware_asset_info_v1_t*
ClusterAdministrationFirmwareServiceAPI_v1GetAssetExtendedFirmwareService(apiClient_t *apiClient, char *assetURL);


// Fetch firmware service configuration
//
// Returns a firmware service configuration object
//
void
ClusterAdministrationFirmwareServiceAPI_v1GetConfigFirmwareService(apiClient_t *apiClient);


// Query install firmware request status.
//
// Returns the status of an install firmware request.
//
install_firmware_response_v1_t*
ClusterAdministrationFirmwareServiceAPI_v1GetInstallFirmwareStatus(apiClient_t *apiClient, char *taskId);


// Installs a firmware for cluster-wide use
//
// Takes an uploaded firmware image and installs it for cluster-wide use.  The firmware is then removed from Images.  In order to install a firmware, you need to follow a 4-step process. First, POST /v1/images/ with { name: string, type: 'fw' } using content-type application/json to acquire an imageId.  Second, upload the firmware file via a multipart/form-data POST to /v1/images/:imageId.  Third, POST /v1/images/install-firmware with { imageId: string } using content-type application/json to acquire a taskId.  Fourth, you can poll the state of the installation via GET /v1/images/install-firmware/:taskId.
//
install_firmware_response_v1_t*
ClusterAdministrationFirmwareServiceAPI_v1InstallFirmware(apiClient_t *apiClient, install_firmware_body_v1_t *install_firmware_body_v1);


// Installs firmware assets for cluster-wide use
//
// Takes an uploaded firmware assets blob image and installs it for cluster-wide use.  The image is then removed from Images.  This endpoint is synchronous: it forwards the asset JSON to the firmware service and returns the firmware service's response message directly. There is no task ID and no polling endpoint.  Installing firmware assets is a 3-step process. First, POST /v1/images/ with { name: string, type: 'fwasset' } using content-type application/json to acquire an imageId. name should be something like 'fcs-keys.json'  Second, upload the firmware assets file via a multipart/form-data POST to /v1/images/:imageId.  Third, POST /v1/images/install-firmware-assets with { imageId: string; } using content-type application/json. The response body is `{ message: string }` describing what the firmware service did with the assets.
//
install_firmware_assets_response_v1_t*
ClusterAdministrationFirmwareServiceAPI_v1InstallFirmwareAssets(apiClient_t *apiClient, install_firmware_assets_body_v1_t *install_firmware_assets_body_v1);


// Fetch firmware assets from the firmware service
//
// Proxies a request to the firmware service to retrieve a list of firmware assets.
//
list_t*
ClusterAdministrationFirmwareServiceAPI_v1ListAssetsFirmwareService(apiClient_t *apiClient, double limit, double offset, char *order, char *search);


// Fetch devices from the firmware service
//
// Proxies a request to the firmware service to retrieve a list of devices.
//
list_t*
ClusterAdministrationFirmwareServiceAPI_v1ListDevicesFirmwareService(apiClient_t *apiClient, double limit, double offset, char *search, char *order, char *type, char *model, char *name, char *platform);


// Fetch firmwares from the firmware service
//
// Proxies a request to the firmware service to retrieve a list of firmwares.
//
list_t*
ClusterAdministrationFirmwareServiceAPI_v1ListFirmwaresFirmwareService(apiClient_t *apiClient, double limit, double offset, char *search, char *order, char *filename, char *model, char *type, char *version, char *buildid, char *firmware_assets, int *installed);


// Update firmware service configuration
//
// Updates firmware service configuration
//
void
ClusterAdministrationFirmwareServiceAPI_v1PatchConfigFirmwareService(apiClient_t *apiClient, firmware_service_configuration_t *firmware_service_configuration);


// Upload Image Data
//
// If the active project has enough remaining quota, updates an Image with the contents of the request body.
//
image_v1_t*
ClusterAdministrationFirmwareServiceAPI_v1UploadImageData(apiClient_t *apiClient, char *imageId, char *corelliumChecksum, binary_t* file);


