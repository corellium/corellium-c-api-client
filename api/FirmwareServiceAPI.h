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
#include "../model/extended_firmware_asset_info.h"
#include "../model/firmware_asset_filter.h"
#include "../model/firmware_asset_list.h"
#include "../model/firmware_device_list.h"
#include "../model/firmware_list.h"
#include "../model/firmware_service_config.h"
#include "../model/firmware_service_settings.h"
#include "../model/object.h"
#include "../model/patch_firmware_service_config_body.h"
#include "../model/user_error_response.h"


// Add firmware assets
//
// **Required role:** Cluster administrator.  Adds firmware assets to the cluster firmware service.
//
char*
FirmwareServiceAPI_v3CreateFirmwareAssets(apiClient_t *apiClient, object_t *body);


// Delete a firmware
//
// **Required role:** Cluster administrator.  Deletes the firmware identified by the given filename from the cluster firmware service.
//
void
FirmwareServiceAPI_v3DeleteFirmware(apiClient_t *apiClient, char *filename);


// Delete a firmware asset
//
// **Required role:** Cluster administrator.  Deletes the firmware asset identified by the given asset URL from the cluster firmware service.
//
void
FirmwareServiceAPI_v3DeleteFirmwareAsset(apiClient_t *apiClient, char *assetUrl);


// Get extended firmware asset info
//
// **Required role:** Cluster administrator.  Returns the firmwares and instances associated with a firmware asset.
//
extended_firmware_asset_info_t*
FirmwareServiceAPI_v3GetFirmwareAssetExtended(apiClient_t *apiClient, char *assetUrl);


// Get firmware service configuration
//
// **Required role:** Cluster administrator.  Returns the current configuration of the cluster firmware service.
//
firmware_service_config_t*
FirmwareServiceAPI_v3GetFirmwareServiceConfig(apiClient_t *apiClient);


// List firmware assets
//
// **Required role:** Cluster administrator.  Returns a paginated list of firmware assets available in the cluster firmware service.
//
firmware_asset_list_t*
FirmwareServiceAPI_v3ListFirmwareAssets(apiClient_t *apiClient, double *limit, double *offset, char *search, char *order, firmware_asset_filter_t *filter);


// List firmware service devices
//
// **Required role:** Cluster administrator.  Returns a paginated list of devices known to the cluster firmware service.
//
firmware_device_list_t*
FirmwareServiceAPI_v3ListFirmwareDevices(apiClient_t *apiClient, double *limit, double *offset, char *search, char *order, char *type, char *model, char *name, char *platform, char *hwModel);


// List firmwares
//
// **Required role:** Cluster administrator.  Returns a paginated list of firmwares available in the cluster firmware service.
//
firmware_list_t*
FirmwareServiceAPI_v3ListFirmwares(apiClient_t *apiClient, double *limit, double *offset, char *search, char *order, char *filename, char *model, char *type, char *version, char *buildId, char *firmwareAssets, char *corelliumChecksum, int *installed);


// Update firmware service configuration
//
// **Required role:** Cluster administrator.  Updates the cluster firmware service configuration and returns the merged result.
//
firmware_service_settings_t*
FirmwareServiceAPI_v3PatchFirmwareServiceConfig(apiClient_t *apiClient, patch_firmware_service_config_body_t *patch_firmware_service_config_body);


