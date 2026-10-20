#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/api_error.h"
#include "../model/config_response.h"
#include "../model/deployment_version.h"


// Get deployment configuration
//
// Returns how this Corellium deployment is set up: its version, whether it is on-site or cloud, whether it is air-gapped, the sign-in providers offered, limits such as the per-device snapshot limit (`snapshotLimit`) and the maximum kernel and ramdisk upload sizes, and which optional features are turned on. Needs no sign-in, so a client can call it first to adapt to the deployment before the user signs in. Build-time feature flags may add further boolean properties beyond those listed.
//
config_response_t*
ConfigAPI_v3GetConfig(apiClient_t *apiClient);


// Get the platform version
//
// Returns which version of the Corellium platform you are talking to: the product version (for example `7.4.0-28212`), plus the build it came from. Include it when reporting a problem to support, or check it to see whether a feature you need is available on this deployment.
//
deployment_version_t*
ConfigAPI_v3GetVersion(apiClient_t *apiClient);


