#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "ClusterAdministrationFirmwareServiceAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096


// Add firmware assets via the firmware service
//
// Proxies a request to the firmware service to add firmware assets.
//
char*
ClusterAdministrationFirmwareServiceAPI_v1CreateAssetsFirmwareService(apiClient_t *apiClient, object_t *body)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v1/cluster/firmware-service/firmware-assets");





    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_body = object_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
    list_addElement(localVarHeaderType,"text/html"); //produces
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 201) {
    //    printf("%s\n","Created");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
    //}
    //primitive return type simple string
    char* elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300)
        elementToReturn = strdup((char*)apiClient->dataReceived);

    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Create a new Image
//
// Create a new Image. Accepts multipart/form-data (with optional file upload) or application/json (metadata only).
//
image_v1_t*
ClusterAdministrationFirmwareServiceAPI_v1CreateImage(apiClient_t *apiClient, image_creation_options_t *image_creation_options)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v1/images");





    // Body Param
    cJSON *localVarSingleItemJSON_image_creation_options = NULL;
    if (image_creation_options != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_image_creation_options = image_creation_options_convertToJSON(image_creation_options);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_image_creation_options);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","application/json");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 201) {
    //    printf("%s\n","application/json");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","application/json");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 507) {
    //    printf("%s\n","Insufficient Storage");
    //}
    //nonprimitive not container
    image_v1_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ClusterAdministrationFirmwareServiceAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = image_v1_parseFromJSON(ClusterAdministrationFirmwareServiceAPIlocalVarJSON);
        cJSON_Delete(ClusterAdministrationFirmwareServiceAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (localVarSingleItemJSON_image_creation_options) {
        cJSON_Delete(localVarSingleItemJSON_image_creation_options);
        localVarSingleItemJSON_image_creation_options = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Delete a firmware asset by its URL
//
// Proxies a request to the firmware service to delete a firmware asset by URL.
//
void
ClusterAdministrationFirmwareServiceAPI_v1DeleteAssetFirmwareService(apiClient_t *apiClient, char *assetURL)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v1/cluster/firmware-service/firmware-assets/{assetURL}");

    if(!assetURL)
        goto end;


    // Path Params
    long sizeOfPathParams_assetURL = strlen(assetURL)+3 + sizeof("{ assetURL }") - 1;
    if(assetURL == NULL) {
        goto end;
    }
    char* localVarToReplace_assetURL = malloc(sizeOfPathParams_assetURL);
    sprintf(localVarToReplace_assetURL, "{%s}", "assetURL");

    localVarPath = strReplace(localVarPath, localVarToReplace_assetURL, assetURL);


    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "DELETE");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 204) {
    //    printf("%s\n","No Content");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
    //}
    //No return type
end:
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_assetURL);

}

// Delete a firmware by filename from the firmware service
//
// Proxies a request to the firmware service to delete a firmware by filename.
//
void
ClusterAdministrationFirmwareServiceAPI_v1DeleteFirmwareFirmwareService(apiClient_t *apiClient, char *filename)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v1/cluster/firmware-service/firmwares/{filename}");

    if(!filename)
        goto end;


    // Path Params
    long sizeOfPathParams_filename = strlen(filename)+3 + sizeof("{ filename }") - 1;
    if(filename == NULL) {
        goto end;
    }
    char* localVarToReplace_filename = malloc(sizeOfPathParams_filename);
    sprintf(localVarToReplace_filename, "{%s}", "filename");

    localVarPath = strReplace(localVarPath, localVarToReplace_filename, filename);


    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "DELETE");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 204) {
    //    printf("%s\n","No Content");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 409) {
    //    printf("%s\n","Conflict");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
    //}
    //No return type
end:
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_filename);

}

// Fetch extended firmware-asset details including instances and associated IPSWs
//
// Retrieves extended information about a firmware including all instances using it and associated firmware assets.
//
extended_firmware_asset_info_v1_t*
ClusterAdministrationFirmwareServiceAPI_v1GetAssetExtendedFirmwareService(apiClient_t *apiClient, char *assetURL)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v1/cluster/firmware-service/firmware-assets/{assetURL}/extended");

    if(!assetURL)
        goto end;


    // Path Params
    long sizeOfPathParams_assetURL = strlen(assetURL)+3 + sizeof("{ assetURL }") - 1;
    if(assetURL == NULL) {
        goto end;
    }
    char* localVarToReplace_assetURL = malloc(sizeOfPathParams_assetURL);
    sprintf(localVarToReplace_assetURL, "{%s}", "assetURL");

    localVarPath = strReplace(localVarPath, localVarToReplace_assetURL, assetURL);


    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
    //}
    //nonprimitive not container
    extended_firmware_asset_info_v1_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ClusterAdministrationFirmwareServiceAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = extended_firmware_asset_info_v1_parseFromJSON(ClusterAdministrationFirmwareServiceAPIlocalVarJSON);
        cJSON_Delete(ClusterAdministrationFirmwareServiceAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_assetURL);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Fetch firmware service configuration
//
// Returns a firmware service configuration object
//
void
ClusterAdministrationFirmwareServiceAPI_v1GetConfigFirmwareService(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v1/cluster/firmware-service/config");




    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","application/json");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
    //}
    //No return type
end:
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);

}

// Query install firmware request status.
//
// Returns the status of an install firmware request.
//
install_firmware_response_v1_t*
ClusterAdministrationFirmwareServiceAPI_v1GetInstallFirmwareStatus(apiClient_t *apiClient, char *taskId)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v1/images/install-firmware/{taskId}");

    if(!taskId)
        goto end;


    // Path Params
    long sizeOfPathParams_taskId = strlen(taskId)+3 + sizeof("{ taskId }") - 1;
    if(taskId == NULL) {
        goto end;
    }
    char* localVarToReplace_taskId = malloc(sizeOfPathParams_taskId);
    sprintf(localVarToReplace_taskId, "{%s}", "taskId");

    localVarPath = strReplace(localVarPath, localVarToReplace_taskId, taskId);


    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","application/json");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not Found");
    //}
    //nonprimitive not container
    install_firmware_response_v1_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ClusterAdministrationFirmwareServiceAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = install_firmware_response_v1_parseFromJSON(ClusterAdministrationFirmwareServiceAPIlocalVarJSON);
        cJSON_Delete(ClusterAdministrationFirmwareServiceAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_taskId);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Installs a firmware for cluster-wide use
//
// Takes an uploaded firmware image and installs it for cluster-wide use.  The firmware is then removed from Images.  In order to install a firmware, you need to follow a 4-step process. First, POST /v1/images/ with { name: string, type: 'fw' } using content-type application/json to acquire an imageId.  Second, upload the firmware file via a multipart/form-data POST to /v1/images/:imageId.  Third, POST /v1/images/install-firmware with { imageId: string } using content-type application/json to acquire a taskId.  Fourth, you can poll the state of the installation via GET /v1/images/install-firmware/:taskId.
//
install_firmware_response_v1_t*
ClusterAdministrationFirmwareServiceAPI_v1InstallFirmware(apiClient_t *apiClient, install_firmware_body_v1_t *install_firmware_body_v1)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v1/images/install-firmware");





    // Body Param
    cJSON *localVarSingleItemJSON_install_firmware_body_v1 = NULL;
    if (install_firmware_body_v1 != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_install_firmware_body_v1 = install_firmware_body_v1_convertToJSON(install_firmware_body_v1);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_install_firmware_body_v1);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 201) {
    //    printf("%s\n","application/json");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not Found");
    //}
    //nonprimitive not container
    install_firmware_response_v1_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ClusterAdministrationFirmwareServiceAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = install_firmware_response_v1_parseFromJSON(ClusterAdministrationFirmwareServiceAPIlocalVarJSON);
        cJSON_Delete(ClusterAdministrationFirmwareServiceAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (localVarSingleItemJSON_install_firmware_body_v1) {
        cJSON_Delete(localVarSingleItemJSON_install_firmware_body_v1);
        localVarSingleItemJSON_install_firmware_body_v1 = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Installs firmware assets for cluster-wide use
//
// Takes an uploaded firmware assets blob image and installs it for cluster-wide use.  The image is then removed from Images.  This endpoint is synchronous: it forwards the asset JSON to the firmware service and returns the firmware service's response message directly. There is no task ID and no polling endpoint.  Installing firmware assets is a 3-step process. First, POST /v1/images/ with { name: string, type: 'fwasset' } using content-type application/json to acquire an imageId. name should be something like 'fcs-keys.json'  Second, upload the firmware assets file via a multipart/form-data POST to /v1/images/:imageId.  Third, POST /v1/images/install-firmware-assets with { imageId: string; } using content-type application/json. The response body is `{ message: string }` describing what the firmware service did with the assets.
//
install_firmware_assets_response_v1_t*
ClusterAdministrationFirmwareServiceAPI_v1InstallFirmwareAssets(apiClient_t *apiClient, install_firmware_assets_body_v1_t *install_firmware_assets_body_v1)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v1/images/install-firmware-assets");





    // Body Param
    cJSON *localVarSingleItemJSON_install_firmware_assets_body_v1 = NULL;
    if (install_firmware_assets_body_v1 != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_install_firmware_assets_body_v1 = install_firmware_assets_body_v1_convertToJSON(install_firmware_assets_body_v1);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_install_firmware_assets_body_v1);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 201) {
    //    printf("%s\n","application/json");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not Found");
    //}
    //nonprimitive not container
    install_firmware_assets_response_v1_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ClusterAdministrationFirmwareServiceAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = install_firmware_assets_response_v1_parseFromJSON(ClusterAdministrationFirmwareServiceAPIlocalVarJSON);
        cJSON_Delete(ClusterAdministrationFirmwareServiceAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (localVarSingleItemJSON_install_firmware_assets_body_v1) {
        cJSON_Delete(localVarSingleItemJSON_install_firmware_assets_body_v1);
        localVarSingleItemJSON_install_firmware_assets_body_v1 = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Fetch firmware assets from the firmware service
//
// Proxies a request to the firmware service to retrieve a list of firmware assets.
//
list_t*
ClusterAdministrationFirmwareServiceAPI_v1ListAssetsFirmwareService(apiClient_t *apiClient, double limit, double offset, char *order, char *search)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v1/cluster/firmware-service/firmware-assets");





    // query parameters
    char *keyQuery_limit = NULL;
    double valueQuery_limit ;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = (limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, &valueQuery_limit);
        list_addElement(localVarQueryParameters,keyPairQuery_limit);
    }

    // query parameters
    char *keyQuery_offset = NULL;
    double valueQuery_offset ;
    keyValuePair_t *keyPairQuery_offset = 0;
    if (offset)
    {
        keyQuery_offset = strdup("offset");
        valueQuery_offset = (offset);
        keyPairQuery_offset = keyValuePair_create(keyQuery_offset, &valueQuery_offset);
        list_addElement(localVarQueryParameters,keyPairQuery_offset);
    }

    // query parameters
    char *keyQuery_order = NULL;
    char * valueQuery_order = NULL;
    keyValuePair_t *keyPairQuery_order = 0;
    if (order)
    {
        keyQuery_order = strdup("order");
        valueQuery_order = strdup((order));
        keyPairQuery_order = keyValuePair_create(keyQuery_order, valueQuery_order);
        list_addElement(localVarQueryParameters,keyPairQuery_order);
    }

    // query parameters
    char *keyQuery_search = NULL;
    char * valueQuery_search = NULL;
    keyValuePair_t *keyPairQuery_search = 0;
    if (search)
    {
        keyQuery_search = strdup("search");
        valueQuery_search = strdup((search));
        keyPairQuery_search = keyValuePair_create(keyQuery_search, valueQuery_search);
        list_addElement(localVarQueryParameters,keyPairQuery_search);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","application/json");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
    //}
    list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ClusterAdministrationFirmwareServiceAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(ClusterAdministrationFirmwareServiceAPIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, ClusterAdministrationFirmwareServiceAPIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( ClusterAdministrationFirmwareServiceAPIlocalVarJSON);
        cJSON_Delete( VarJSON);
    }
    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    if(keyQuery_limit){
        free(keyQuery_limit);
        keyQuery_limit = NULL;
    }
    if(keyPairQuery_limit){
        keyValuePair_free(keyPairQuery_limit);
        keyPairQuery_limit = NULL;
    }
    if(keyQuery_offset){
        free(keyQuery_offset);
        keyQuery_offset = NULL;
    }
    if(keyPairQuery_offset){
        keyValuePair_free(keyPairQuery_offset);
        keyPairQuery_offset = NULL;
    }
    if(keyQuery_order){
        free(keyQuery_order);
        keyQuery_order = NULL;
    }
    if(valueQuery_order){
        free(valueQuery_order);
        valueQuery_order = NULL;
    }
    if(keyPairQuery_order){
        keyValuePair_free(keyPairQuery_order);
        keyPairQuery_order = NULL;
    }
    if(keyQuery_search){
        free(keyQuery_search);
        keyQuery_search = NULL;
    }
    if(valueQuery_search){
        free(valueQuery_search);
        valueQuery_search = NULL;
    }
    if(keyPairQuery_search){
        keyValuePair_free(keyPairQuery_search);
        keyPairQuery_search = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Fetch devices from the firmware service
//
// Proxies a request to the firmware service to retrieve a list of devices.
//
list_t*
ClusterAdministrationFirmwareServiceAPI_v1ListDevicesFirmwareService(apiClient_t *apiClient, double limit, double offset, char *search, char *order, char *type, char *model, char *name, char *platform)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v1/cluster/firmware-service/devices");





    // query parameters
    char *keyQuery_limit = NULL;
    double valueQuery_limit ;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = (limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, &valueQuery_limit);
        list_addElement(localVarQueryParameters,keyPairQuery_limit);
    }

    // query parameters
    char *keyQuery_offset = NULL;
    double valueQuery_offset ;
    keyValuePair_t *keyPairQuery_offset = 0;
    if (offset)
    {
        keyQuery_offset = strdup("offset");
        valueQuery_offset = (offset);
        keyPairQuery_offset = keyValuePair_create(keyQuery_offset, &valueQuery_offset);
        list_addElement(localVarQueryParameters,keyPairQuery_offset);
    }

    // query parameters
    char *keyQuery_search = NULL;
    char * valueQuery_search = NULL;
    keyValuePair_t *keyPairQuery_search = 0;
    if (search)
    {
        keyQuery_search = strdup("search");
        valueQuery_search = strdup((search));
        keyPairQuery_search = keyValuePair_create(keyQuery_search, valueQuery_search);
        list_addElement(localVarQueryParameters,keyPairQuery_search);
    }

    // query parameters
    char *keyQuery_order = NULL;
    char * valueQuery_order = NULL;
    keyValuePair_t *keyPairQuery_order = 0;
    if (order)
    {
        keyQuery_order = strdup("order");
        valueQuery_order = strdup((order));
        keyPairQuery_order = keyValuePair_create(keyQuery_order, valueQuery_order);
        list_addElement(localVarQueryParameters,keyPairQuery_order);
    }

    // query parameters
    char *keyQuery_type = NULL;
    char * valueQuery_type = NULL;
    keyValuePair_t *keyPairQuery_type = 0;
    if (type)
    {
        keyQuery_type = strdup("type");
        valueQuery_type = strdup((type));
        keyPairQuery_type = keyValuePair_create(keyQuery_type, valueQuery_type);
        list_addElement(localVarQueryParameters,keyPairQuery_type);
    }

    // query parameters
    char *keyQuery_model = NULL;
    char * valueQuery_model = NULL;
    keyValuePair_t *keyPairQuery_model = 0;
    if (model)
    {
        keyQuery_model = strdup("model");
        valueQuery_model = strdup((model));
        keyPairQuery_model = keyValuePair_create(keyQuery_model, valueQuery_model);
        list_addElement(localVarQueryParameters,keyPairQuery_model);
    }

    // query parameters
    char *keyQuery_name = NULL;
    char * valueQuery_name = NULL;
    keyValuePair_t *keyPairQuery_name = 0;
    if (name)
    {
        keyQuery_name = strdup("name");
        valueQuery_name = strdup((name));
        keyPairQuery_name = keyValuePair_create(keyQuery_name, valueQuery_name);
        list_addElement(localVarQueryParameters,keyPairQuery_name);
    }

    // query parameters
    char *keyQuery_platform = NULL;
    char * valueQuery_platform = NULL;
    keyValuePair_t *keyPairQuery_platform = 0;
    if (platform)
    {
        keyQuery_platform = strdup("platform");
        valueQuery_platform = strdup((platform));
        keyPairQuery_platform = keyValuePair_create(keyQuery_platform, valueQuery_platform);
        list_addElement(localVarQueryParameters,keyPairQuery_platform);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
    //}
    list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ClusterAdministrationFirmwareServiceAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(ClusterAdministrationFirmwareServiceAPIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, ClusterAdministrationFirmwareServiceAPIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( ClusterAdministrationFirmwareServiceAPIlocalVarJSON);
        cJSON_Delete( VarJSON);
    }
    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    if(keyQuery_limit){
        free(keyQuery_limit);
        keyQuery_limit = NULL;
    }
    if(keyPairQuery_limit){
        keyValuePair_free(keyPairQuery_limit);
        keyPairQuery_limit = NULL;
    }
    if(keyQuery_offset){
        free(keyQuery_offset);
        keyQuery_offset = NULL;
    }
    if(keyPairQuery_offset){
        keyValuePair_free(keyPairQuery_offset);
        keyPairQuery_offset = NULL;
    }
    if(keyQuery_search){
        free(keyQuery_search);
        keyQuery_search = NULL;
    }
    if(valueQuery_search){
        free(valueQuery_search);
        valueQuery_search = NULL;
    }
    if(keyPairQuery_search){
        keyValuePair_free(keyPairQuery_search);
        keyPairQuery_search = NULL;
    }
    if(keyQuery_order){
        free(keyQuery_order);
        keyQuery_order = NULL;
    }
    if(valueQuery_order){
        free(valueQuery_order);
        valueQuery_order = NULL;
    }
    if(keyPairQuery_order){
        keyValuePair_free(keyPairQuery_order);
        keyPairQuery_order = NULL;
    }
    if(keyQuery_type){
        free(keyQuery_type);
        keyQuery_type = NULL;
    }
    if(valueQuery_type){
        free(valueQuery_type);
        valueQuery_type = NULL;
    }
    if(keyPairQuery_type){
        keyValuePair_free(keyPairQuery_type);
        keyPairQuery_type = NULL;
    }
    if(keyQuery_model){
        free(keyQuery_model);
        keyQuery_model = NULL;
    }
    if(valueQuery_model){
        free(valueQuery_model);
        valueQuery_model = NULL;
    }
    if(keyPairQuery_model){
        keyValuePair_free(keyPairQuery_model);
        keyPairQuery_model = NULL;
    }
    if(keyQuery_name){
        free(keyQuery_name);
        keyQuery_name = NULL;
    }
    if(valueQuery_name){
        free(valueQuery_name);
        valueQuery_name = NULL;
    }
    if(keyPairQuery_name){
        keyValuePair_free(keyPairQuery_name);
        keyPairQuery_name = NULL;
    }
    if(keyQuery_platform){
        free(keyQuery_platform);
        keyQuery_platform = NULL;
    }
    if(valueQuery_platform){
        free(valueQuery_platform);
        valueQuery_platform = NULL;
    }
    if(keyPairQuery_platform){
        keyValuePair_free(keyPairQuery_platform);
        keyPairQuery_platform = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Fetch firmwares from the firmware service
//
// Proxies a request to the firmware service to retrieve a list of firmwares.
//
list_t*
ClusterAdministrationFirmwareServiceAPI_v1ListFirmwaresFirmwareService(apiClient_t *apiClient, double limit, double offset, char *search, char *order, char *filename, char *model, char *type, char *version, char *buildid, char *firmware_assets, int *installed)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v1/cluster/firmware-service/firmwares");





    // query parameters
    char *keyQuery_limit = NULL;
    double valueQuery_limit ;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = (limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, &valueQuery_limit);
        list_addElement(localVarQueryParameters,keyPairQuery_limit);
    }

    // query parameters
    char *keyQuery_offset = NULL;
    double valueQuery_offset ;
    keyValuePair_t *keyPairQuery_offset = 0;
    if (offset)
    {
        keyQuery_offset = strdup("offset");
        valueQuery_offset = (offset);
        keyPairQuery_offset = keyValuePair_create(keyQuery_offset, &valueQuery_offset);
        list_addElement(localVarQueryParameters,keyPairQuery_offset);
    }

    // query parameters
    char *keyQuery_search = NULL;
    char * valueQuery_search = NULL;
    keyValuePair_t *keyPairQuery_search = 0;
    if (search)
    {
        keyQuery_search = strdup("search");
        valueQuery_search = strdup((search));
        keyPairQuery_search = keyValuePair_create(keyQuery_search, valueQuery_search);
        list_addElement(localVarQueryParameters,keyPairQuery_search);
    }

    // query parameters
    char *keyQuery_order = NULL;
    char * valueQuery_order = NULL;
    keyValuePair_t *keyPairQuery_order = 0;
    if (order)
    {
        keyQuery_order = strdup("order");
        valueQuery_order = strdup((order));
        keyPairQuery_order = keyValuePair_create(keyQuery_order, valueQuery_order);
        list_addElement(localVarQueryParameters,keyPairQuery_order);
    }

    // query parameters
    char *keyQuery_filename = NULL;
    char * valueQuery_filename = NULL;
    keyValuePair_t *keyPairQuery_filename = 0;
    if (filename)
    {
        keyQuery_filename = strdup("filename");
        valueQuery_filename = strdup((filename));
        keyPairQuery_filename = keyValuePair_create(keyQuery_filename, valueQuery_filename);
        list_addElement(localVarQueryParameters,keyPairQuery_filename);
    }

    // query parameters
    char *keyQuery_model = NULL;
    char * valueQuery_model = NULL;
    keyValuePair_t *keyPairQuery_model = 0;
    if (model)
    {
        keyQuery_model = strdup("model");
        valueQuery_model = strdup((model));
        keyPairQuery_model = keyValuePair_create(keyQuery_model, valueQuery_model);
        list_addElement(localVarQueryParameters,keyPairQuery_model);
    }

    // query parameters
    char *keyQuery_type = NULL;
    char * valueQuery_type = NULL;
    keyValuePair_t *keyPairQuery_type = 0;
    if (type)
    {
        keyQuery_type = strdup("type");
        valueQuery_type = strdup((type));
        keyPairQuery_type = keyValuePair_create(keyQuery_type, valueQuery_type);
        list_addElement(localVarQueryParameters,keyPairQuery_type);
    }

    // query parameters
    char *keyQuery_version = NULL;
    char * valueQuery_version = NULL;
    keyValuePair_t *keyPairQuery_version = 0;
    if (version)
    {
        keyQuery_version = strdup("version");
        valueQuery_version = strdup((version));
        keyPairQuery_version = keyValuePair_create(keyQuery_version, valueQuery_version);
        list_addElement(localVarQueryParameters,keyPairQuery_version);
    }

    // query parameters
    char *keyQuery_buildid = NULL;
    char * valueQuery_buildid = NULL;
    keyValuePair_t *keyPairQuery_buildid = 0;
    if (buildid)
    {
        keyQuery_buildid = strdup("buildid");
        valueQuery_buildid = strdup((buildid));
        keyPairQuery_buildid = keyValuePair_create(keyQuery_buildid, valueQuery_buildid);
        list_addElement(localVarQueryParameters,keyPairQuery_buildid);
    }

    // query parameters
    char *keyQuery_firmware_assets = NULL;
    char * valueQuery_firmware_assets = NULL;
    keyValuePair_t *keyPairQuery_firmware_assets = 0;
    if (firmware_assets)
    {
        keyQuery_firmware_assets = strdup("firmware_assets");
        valueQuery_firmware_assets = strdup((firmware_assets));
        keyPairQuery_firmware_assets = keyValuePair_create(keyQuery_firmware_assets, valueQuery_firmware_assets);
        list_addElement(localVarQueryParameters,keyPairQuery_firmware_assets);
    }

    // query parameters
    char *keyQuery_installed = NULL;
    char * valueQuery_installed = NULL;
    keyValuePair_t *keyPairQuery_installed = 0;
    if (installed)
    {
        keyQuery_installed = strdup("installed");
        valueQuery_installed = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_installed, MAX_NUMBER_LENGTH, "%d", *installed);
        keyPairQuery_installed = keyValuePair_create(keyQuery_installed, valueQuery_installed);
        list_addElement(localVarQueryParameters,keyPairQuery_installed);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
    //}
    list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ClusterAdministrationFirmwareServiceAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(ClusterAdministrationFirmwareServiceAPIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, ClusterAdministrationFirmwareServiceAPIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( ClusterAdministrationFirmwareServiceAPIlocalVarJSON);
        cJSON_Delete( VarJSON);
    }
    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    if(keyQuery_limit){
        free(keyQuery_limit);
        keyQuery_limit = NULL;
    }
    if(keyPairQuery_limit){
        keyValuePair_free(keyPairQuery_limit);
        keyPairQuery_limit = NULL;
    }
    if(keyQuery_offset){
        free(keyQuery_offset);
        keyQuery_offset = NULL;
    }
    if(keyPairQuery_offset){
        keyValuePair_free(keyPairQuery_offset);
        keyPairQuery_offset = NULL;
    }
    if(keyQuery_search){
        free(keyQuery_search);
        keyQuery_search = NULL;
    }
    if(valueQuery_search){
        free(valueQuery_search);
        valueQuery_search = NULL;
    }
    if(keyPairQuery_search){
        keyValuePair_free(keyPairQuery_search);
        keyPairQuery_search = NULL;
    }
    if(keyQuery_order){
        free(keyQuery_order);
        keyQuery_order = NULL;
    }
    if(valueQuery_order){
        free(valueQuery_order);
        valueQuery_order = NULL;
    }
    if(keyPairQuery_order){
        keyValuePair_free(keyPairQuery_order);
        keyPairQuery_order = NULL;
    }
    if(keyQuery_filename){
        free(keyQuery_filename);
        keyQuery_filename = NULL;
    }
    if(valueQuery_filename){
        free(valueQuery_filename);
        valueQuery_filename = NULL;
    }
    if(keyPairQuery_filename){
        keyValuePair_free(keyPairQuery_filename);
        keyPairQuery_filename = NULL;
    }
    if(keyQuery_model){
        free(keyQuery_model);
        keyQuery_model = NULL;
    }
    if(valueQuery_model){
        free(valueQuery_model);
        valueQuery_model = NULL;
    }
    if(keyPairQuery_model){
        keyValuePair_free(keyPairQuery_model);
        keyPairQuery_model = NULL;
    }
    if(keyQuery_type){
        free(keyQuery_type);
        keyQuery_type = NULL;
    }
    if(valueQuery_type){
        free(valueQuery_type);
        valueQuery_type = NULL;
    }
    if(keyPairQuery_type){
        keyValuePair_free(keyPairQuery_type);
        keyPairQuery_type = NULL;
    }
    if(keyQuery_version){
        free(keyQuery_version);
        keyQuery_version = NULL;
    }
    if(valueQuery_version){
        free(valueQuery_version);
        valueQuery_version = NULL;
    }
    if(keyPairQuery_version){
        keyValuePair_free(keyPairQuery_version);
        keyPairQuery_version = NULL;
    }
    if(keyQuery_buildid){
        free(keyQuery_buildid);
        keyQuery_buildid = NULL;
    }
    if(valueQuery_buildid){
        free(valueQuery_buildid);
        valueQuery_buildid = NULL;
    }
    if(keyPairQuery_buildid){
        keyValuePair_free(keyPairQuery_buildid);
        keyPairQuery_buildid = NULL;
    }
    if(keyQuery_firmware_assets){
        free(keyQuery_firmware_assets);
        keyQuery_firmware_assets = NULL;
    }
    if(valueQuery_firmware_assets){
        free(valueQuery_firmware_assets);
        valueQuery_firmware_assets = NULL;
    }
    if(keyPairQuery_firmware_assets){
        keyValuePair_free(keyPairQuery_firmware_assets);
        keyPairQuery_firmware_assets = NULL;
    }
    if(keyQuery_installed){
        free(keyQuery_installed);
        keyQuery_installed = NULL;
    }
    if(valueQuery_installed){
        free(valueQuery_installed);
        valueQuery_installed = NULL;
    }
    if(keyPairQuery_installed){
        keyValuePair_free(keyPairQuery_installed);
        keyPairQuery_installed = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Update firmware service configuration
//
// Updates firmware service configuration
//
void
ClusterAdministrationFirmwareServiceAPI_v1PatchConfigFirmwareService(apiClient_t *apiClient, firmware_service_configuration_t *firmware_service_configuration)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v1/cluster/firmware-service/config");





    // Body Param
    cJSON *localVarSingleItemJSON_firmware_service_configuration = NULL;
    if (firmware_service_configuration != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_firmware_service_configuration = firmware_service_configuration_convertToJSON(firmware_service_configuration);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_firmware_service_configuration);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "PATCH");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","application/json");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Not found");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
    //}
    //No return type
end:
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (localVarSingleItemJSON_firmware_service_configuration) {
        cJSON_Delete(localVarSingleItemJSON_firmware_service_configuration);
        localVarSingleItemJSON_firmware_service_configuration = NULL;
    }
    free(localVarBodyParameters);

}

// Upload Image Data
//
// If the active project has enough remaining quota, updates an Image with the contents of the request body.
//
image_v1_t*
ClusterAdministrationFirmwareServiceAPI_v1UploadImageData(apiClient_t *apiClient, char *imageId, char *corelliumChecksum, binary_t* file)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v1/images/{imageId}");

    if(!imageId)
        goto end;


    // Path Params
    long sizeOfPathParams_imageId = strlen(imageId)+3 + sizeof("{ imageId }") - 1;
    if(imageId == NULL) {
        goto end;
    }
    char* localVarToReplace_imageId = malloc(sizeOfPathParams_imageId);
    sprintf(localVarToReplace_imageId, "{%s}", "imageId");

    localVarPath = strReplace(localVarPath, localVarToReplace_imageId, imageId);



    // form parameters
    char *keyForm_corelliumChecksum = NULL;
    char * valueForm_corelliumChecksum = 0;
    keyValuePair_t *keyPairForm_corelliumChecksum = 0;
    if (corelliumChecksum != NULL)
    {
        keyForm_corelliumChecksum = strdup("corelliumChecksum");
        valueForm_corelliumChecksum = strdup((corelliumChecksum));
        keyPairForm_corelliumChecksum = keyValuePair_create(keyForm_corelliumChecksum,valueForm_corelliumChecksum);
        list_addElement(localVarFormParameters,keyPairForm_corelliumChecksum);
    }

    // form parameters
    char *keyForm_file = NULL;
    binary_t* valueForm_file = 0;
    keyValuePair_t *keyPairForm_file = 0;
    if (file != NULL)
    {
        keyForm_file = strdup("file");
        valueForm_file = file;
        keyPairForm_file = keyValuePair_create(keyForm_file, &valueForm_file);
        list_addElement(localVarFormParameters,keyPairForm_file); //file adding
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","application/json");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","application/json");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 409) {
    //    printf("%s\n","Conflict");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 507) {
    //    printf("%s\n","Insufficient Storage");
    //}
    //nonprimitive not container
    image_v1_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ClusterAdministrationFirmwareServiceAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = image_v1_parseFromJSON(ClusterAdministrationFirmwareServiceAPIlocalVarJSON);
        cJSON_Delete(ClusterAdministrationFirmwareServiceAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_imageId);
    if (keyForm_corelliumChecksum) {
        free(keyForm_corelliumChecksum);
        keyForm_corelliumChecksum = NULL;
    }
    if (valueForm_corelliumChecksum) {
        free(valueForm_corelliumChecksum);
        valueForm_corelliumChecksum = NULL;
    }
    free(keyPairForm_corelliumChecksum);
    if (keyForm_file) {
        free(keyForm_file);
        keyForm_file = NULL;
    }
//    free(fileVar_file->data);
//    free(fileVar_file);
    free(keyPairForm_file);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

