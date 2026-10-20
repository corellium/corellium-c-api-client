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
// **Required role:** Cluster administrator.  Adds firmware assets to the cluster, so firmware that needs them can boot. Returns 201 with the firmware service's response message. Requires a cluster administrator. For a single project, `POST /v3/projects/{projectId}/firmware-assets` fetches missing assets by URL; on air-gapped deployments, upload them and use `POST /v3/images/install-firmware-assets`.
//
char*
FirmwareServiceAPI_v3CreateFirmwareAssets(apiClient_t *apiClient, object_t *body);


// Delete a firmware
//
// **Required role:** Cluster administrator.  Removes a firmware build from the cluster firmware catalog, so it can no longer be chosen when creating devices. Identify it by its filename from `v3ListFirmwares`. Requires a cluster administrator.  This endpoint proxies the request to the firmware service. A filename the service no longer has is a successful no-op: both a successful upstream delete and an upstream \"not there\" answer 204, and repeated calls return 204 as well. A firmware-service outage or refusal is still reported as a failure.
//
void
FirmwareServiceAPI_v3DeleteFirmware(apiClient_t *apiClient, char *filename);


// Delete a firmware asset
//
// **Required role:** Cluster administrator.  Removes a firmware asset from the cluster. Firmware that needs it can no longer boot until it is added again. Requires a cluster administrator.  This endpoint proxies the request to the firmware service. An asset the service no longer has is a successful no-op: both a successful upstream delete and an upstream \"not there\" answer 204, and repeated calls return 204 as well. A firmware-service outage or refusal is still reported as a failure.
//
void
FirmwareServiceAPI_v3DeleteFirmwareAsset(apiClient_t *apiClient, char *assetUrl);


// Get extended firmware asset info
//
// **Required role:** Cluster administrator.  Shows where a firmware asset is used: the firmware builds that need it and the devices using those builds. Check this before deleting an asset. Requires a cluster administrator.
//
extended_firmware_asset_info_t*
FirmwareServiceAPI_v3GetFirmwareAssetExtended(apiClient_t *apiClient, char *assetUrl);


// Get firmware service configuration
//
// **Required role:** Cluster administrator.  Returns the settings of the cluster firmware service: the cluster-wide catalog of operating-system builds that devices can be created from (what `GET /v3/models/{model}/software` lists). Settings control things such as whether firmware is downloaded and cached. Requires a cluster administrator. Change them with `v3PatchFirmwareServiceConfig`.
//
firmware_service_config_t*
FirmwareServiceAPI_v3GetFirmwareServiceConfig(apiClient_t *apiClient);


// List firmware assets
//
// **Required role:** Cluster administrator.  Lists the firmware assets stored in the cluster: side files some firmware needs in order to boot, such as Apple decryption keys. A firmware build lists the asset URLs it needs; device creation fails if one is missing. Requires a cluster administrator. Results are paginated.
//
firmware_asset_list_t*
FirmwareServiceAPI_v3ListFirmwareAssets(apiClient_t *apiClient, double *limit, double *offset, char *search, char *order, firmware_asset_filter_t *filter);


// List firmware service devices
//
// **Required role:** Cluster administrator.  Lists the device models the firmware service has firmware records for. Requires a cluster administrator. Results are paginated.
//
firmware_device_list_t*
FirmwareServiceAPI_v3ListFirmwareDevices(apiClient_t *apiClient, double *limit, double *offset, char *search, char *order, char *type, char *model, char *name, char *platform, char *hwModel);


// List firmwares
//
// **Required role:** Cluster administrator.  Lists the firmware builds in the cluster firmware catalog, including builds installed with `POST /v3/images/install-firmware`. Requires a cluster administrator. Results are paginated. Users see the builds for one model with `GET /v3/models/{model}/software`.
//
firmware_list_t*
FirmwareServiceAPI_v3ListFirmwares(apiClient_t *apiClient, double *limit, double *offset, char *search, char *order, char *filename, char *model, char *type, char *version, char *buildId, char *firmwareAssets, char *corelliumChecksum, int *installed);


// Update firmware service configuration
//
// **Required role:** Cluster administrator.  Changes firmware service settings. Send only the settings you want to change; they are merged into the current settings, and the full result is returned. Requires a cluster administrator.
//
firmware_service_settings_t*
FirmwareServiceAPI_v3PatchFirmwareServiceConfig(apiClient_t *apiClient, patch_firmware_service_config_body_t *patch_firmware_service_config_body);


