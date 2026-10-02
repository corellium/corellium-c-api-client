#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "ImagesAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096


// Create an image
//
// Creates an image: a stored file such as firmware, a kernel, a partition, or a MATRIX wordlist. Every upload starts here. The response is the new image, including its `id`.  **Choosing how to upload the file:**   - **Two steps (recommended).** Send this request as `application/json` without a file; it returns **201**. Then upload the contents with [`uploadImageData`](#tag/images/POST/v3/images/{imageId}) (one request) or [`uploadImageChunk`](#tag/images/PUT/v3/images/{imageId}/file) (in pieces, resumable, best for large files). This is the only way to have the server verify the file against a `corelliumChecksum`.   - **One step.** Send this request as `multipart/form-data` with the file in a `file` part; it returns **200** once the file is stored. Put the `type` field before the `file` part. Convenient for small files, but no checksum verification.  The response body is the same image in both cases; the status code (201 or 200) tells you whether the file was included.  **Where the image lives** depends on the optional IDs:   - `instanceId` set: attached to that device. Replaces the device's existing image of the same type.   - `projectId` set: stored in that project and counted against its quota.   - Neither: a domain-level image. Domain-level `fw` and `clbi` images are also offered when you create a device, in addition to installed firmware. See the `projectId` and `instanceId` fields for side effects.  Other upload endpoints (`PUT /v3/projects/{projectId}/image-upload/...`, `PUT /v3/instances/{instanceId}/image-upload/...`, `PUT /v3/domain/image-upload/...`) use the same chunked protocol but create the image on the first chunk instead of requiring this call. They exist mainly for the web interface; new code should use this endpoint followed by [`uploadImageChunk`](#tag/images/PUT/v3/images/{imageId}/file).  `name` is not unique; sending the same request twice creates two images. For firmware, continue with [`installFirmware`](#tag/images/POST/v3/images/install-firmware) or [`installFirmwareAssets`](#tag/images/POST/v3/images/install-firmware-assets).
//
image_t*
ImagesAPI_v3CreateImage(apiClient_t *apiClient, create_image_body_t *create_image_body)
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
    char *localVarPath = strdup("/v3/images");





    // Body Param
    cJSON *localVarSingleItemJSON_create_image_body = NULL;
    if (create_image_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_create_image_body = create_image_body_convertToJSON(create_image_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_create_image_body);
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
    //    printf("%s\n","Image created with file uploaded (multipart).");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 201) {
    //    printf("%s\n","Image metadata created (JSON only); upload separately.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Missing or invalid image fields.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","The instance named by &#x60;instanceId&#x60; does not exist.");
    //}
    //nonprimitive not container
    image_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ImagesAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = image_parseFromJSON(ImagesAPIlocalVarJSON);
        cJSON_Delete(ImagesAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_create_image_body) {
        cJSON_Delete(localVarSingleItemJSON_create_image_body);
        localVarSingleItemJSON_create_image_body = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Delete an image
//
// Permanently deletes the image. This action cannot be undone.  Deletion is synchronous. Deletes are idempotent: an unknown `imageId`, or an image that has already been deleted, is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing.
//
void
ImagesAPI_v3DeleteImage(apiClient_t *apiClient, char *imageId)
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
    char *localVarPath = strdup("/v3/images/{imageId}");

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
    //    printf("%s\n","Image deleted; empty body.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
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
    free(localVarToReplace_imageId);

}

// Get image metadata
//
// Returns metadata for a single image. File contents are not returned by this endpoint.
//
image_t*
ImagesAPI_v3GetImage(apiClient_t *apiClient, char *imageId)
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
    char *localVarPath = strdup("/v3/images/{imageId}");

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
    //    printf("%s\n","Image metadata.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","No image with the given imageId.");
    //}
    //nonprimitive not container
    image_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ImagesAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = image_parseFromJSON(ImagesAPIlocalVarJSON);
        cJSON_Delete(ImagesAPIlocalVarJSON);
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
    free(localVarToReplace_imageId);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Check whether an image chunk was already uploaded
//
// Probes whether a single chunk of a chunked upload is already stored, so an interrupted upload can resume without re-sending data. Used together with [`uploadImageChunk`](#tag/images/PUT/v3/images/{imageId}/file).   Returns 200 when the chunk is present and 204 when it still needs to be uploaded. The chunk is identified exactly as in the upload request, by `resumableChunkNumber`, `resumableChunkSize` and `resumableCurrentChunkSize`, all of which are required. The image must already exist; an unknown `imageId` is a 404 rather than a 204.
//
object_t*
ImagesAPI_v3GetImageChunk(apiClient_t *apiClient, char *imageId, double *resumableChunkNumber, double *resumableChunkSize, double *resumableCurrentChunkSize)
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
    char *localVarPath = strdup("/v3/images/{imageId}/file");

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



    // query parameters
    char *keyQuery_resumableChunkNumber = NULL;
    char * valueQuery_resumableChunkNumber = NULL;
    keyValuePair_t *keyPairQuery_resumableChunkNumber = 0;
    if (resumableChunkNumber)
    {
        keyQuery_resumableChunkNumber = strdup("resumableChunkNumber");
        valueQuery_resumableChunkNumber = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_resumableChunkNumber, MAX_NUMBER_LENGTH, "%d", *resumableChunkNumber);
        keyPairQuery_resumableChunkNumber = keyValuePair_create(keyQuery_resumableChunkNumber, valueQuery_resumableChunkNumber);
        list_addElement(localVarQueryParameters,keyPairQuery_resumableChunkNumber);
    }

    // query parameters
    char *keyQuery_resumableChunkSize = NULL;
    char * valueQuery_resumableChunkSize = NULL;
    keyValuePair_t *keyPairQuery_resumableChunkSize = 0;
    if (resumableChunkSize)
    {
        keyQuery_resumableChunkSize = strdup("resumableChunkSize");
        valueQuery_resumableChunkSize = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_resumableChunkSize, MAX_NUMBER_LENGTH, "%d", *resumableChunkSize);
        keyPairQuery_resumableChunkSize = keyValuePair_create(keyQuery_resumableChunkSize, valueQuery_resumableChunkSize);
        list_addElement(localVarQueryParameters,keyPairQuery_resumableChunkSize);
    }

    // query parameters
    char *keyQuery_resumableCurrentChunkSize = NULL;
    char * valueQuery_resumableCurrentChunkSize = NULL;
    keyValuePair_t *keyPairQuery_resumableCurrentChunkSize = 0;
    if (resumableCurrentChunkSize)
    {
        keyQuery_resumableCurrentChunkSize = strdup("resumableCurrentChunkSize");
        valueQuery_resumableCurrentChunkSize = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_resumableCurrentChunkSize, MAX_NUMBER_LENGTH, "%d", *resumableCurrentChunkSize);
        keyPairQuery_resumableCurrentChunkSize = keyValuePair_create(keyQuery_resumableCurrentChunkSize, valueQuery_resumableCurrentChunkSize);
        list_addElement(localVarQueryParameters,keyPairQuery_resumableCurrentChunkSize);
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
    //    printf("%s\n","The chunk is already stored; empty JSON body.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 204) {
    //    printf("%s\n","The chunk is missing and still needs to be uploaded.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid or missing chunk parameters.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","No permission for the image&#39;s project, or the image is site-wide and the caller is not a domain (on-site) or cloud administrator.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","No image with the given imageId.");
    //}
    //nonprimitive not container
    object_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ImagesAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = object_parseFromJSON(ImagesAPIlocalVarJSON);
        cJSON_Delete(ImagesAPIlocalVarJSON);
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
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_imageId);
    if(keyQuery_resumableChunkNumber){
        free(keyQuery_resumableChunkNumber);
        keyQuery_resumableChunkNumber = NULL;
    }
    if(valueQuery_resumableChunkNumber){
        free(valueQuery_resumableChunkNumber);
        valueQuery_resumableChunkNumber = NULL;
    }
    if(keyPairQuery_resumableChunkNumber){
        keyValuePair_free(keyPairQuery_resumableChunkNumber);
        keyPairQuery_resumableChunkNumber = NULL;
    }
    if(keyQuery_resumableChunkSize){
        free(keyQuery_resumableChunkSize);
        keyQuery_resumableChunkSize = NULL;
    }
    if(valueQuery_resumableChunkSize){
        free(valueQuery_resumableChunkSize);
        valueQuery_resumableChunkSize = NULL;
    }
    if(keyPairQuery_resumableChunkSize){
        keyValuePair_free(keyPairQuery_resumableChunkSize);
        keyPairQuery_resumableChunkSize = NULL;
    }
    if(keyQuery_resumableCurrentChunkSize){
        free(keyQuery_resumableCurrentChunkSize);
        keyQuery_resumableCurrentChunkSize = NULL;
    }
    if(valueQuery_resumableCurrentChunkSize){
        free(valueQuery_resumableCurrentChunkSize);
        valueQuery_resumableCurrentChunkSize = NULL;
    }
    if(keyPairQuery_resumableCurrentChunkSize){
        keyValuePair_free(keyPairQuery_resumableCurrentChunkSize);
        keyPairQuery_resumableCurrentChunkSize = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get firmware info embedded in an image
//
// Reads the version information built into an uploaded firmware file, without installing it or creating a device. Use it to check what a file is before you install it or create a device from it: which operating-system version and build it contains, and which device models it supports.  Works on these kinds of uploaded files: an Apple iOS firmware file (IPSW), a Corellium firmware package (`.coreimg`), a Cellebrite firmware image, a Cellebrite extraction (UFD), and a Corellium extension. The image must be fully uploaded first; see [`createImage`](#tag/images/POST/v3/images).  The request body is optional:   - `password`: needed only if the file is encrypted. A wrong password returns 400.   - `extended`: set to `true` to also get chip and board details and the supported device model this firmware matches (`device`). Use the matched model's `flavor` when you create an instance.  Returns 404 if the image does not exist, or if the file contains no version information that can be read (for example, it is not firmware).
//
image_firmware_info_t*
ImagesAPI_v3GetImageFirmwareInfo(apiClient_t *apiClient, char *imageId, get_firmware_info_body_t *get_firmware_info_body)
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
    char *localVarPath = strdup("/v3/images/{imageId}/fwinfo");

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



    // Body Param
    cJSON *localVarSingleItemJSON_get_firmware_info_body = NULL;
    if (get_firmware_info_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_get_firmware_info_body = get_firmware_info_body_convertToJSON(get_firmware_info_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_get_firmware_info_body);
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
    //    printf("%s\n","Firmware info parsed from the image.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid request body, or the supplied password is wrong.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","No permission for the image&#39;s project.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","No image with the given imageId, no firmware info file inside it, or the info was unparseable.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 409) {
    //    printf("%s\n","The image backing file is not currently accessible.");
    //}
    //nonprimitive not container
    image_firmware_info_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ImagesAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = image_firmware_info_parseFromJSON(ImagesAPIlocalVarJSON);
        cJSON_Delete(ImagesAPIlocalVarJSON);
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
    free(localVarToReplace_imageId);
    if (localVarSingleItemJSON_get_firmware_info_body) {
        cJSON_Delete(localVarSingleItemJSON_get_firmware_info_body);
        localVarSingleItemJSON_get_firmware_info_body = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get install-firmware task status
//
// Returns the current status of a firmware installation task previously created via [`installFirmware`](#tag/images/POST/v3/images/install-firmware). Clients should poll this endpoint until `status` is `complete` or `error`.
//
install_firmware_status_response_t*
ImagesAPI_v3GetInstallFirmwareStatus(apiClient_t *apiClient, char *taskId)
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
    char *localVarPath = strdup("/v3/images/install-firmware/{taskId}");

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
    //    printf("%s\n","Task status.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","The request was invalid, for example a missing or malformed field. The body says which field; fix it before retrying.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","No install-firmware task with the given taskId.");
    //}
    //nonprimitive not container
    install_firmware_status_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ImagesAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = install_firmware_status_response_parseFromJSON(ImagesAPIlocalVarJSON);
        cJSON_Delete(ImagesAPIlocalVarJSON);
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

// Install firmware cluster-wide
//
// Makes an uploaded `fw` image available for creating devices across the whole cluster. After it is installed, the firmware appears in `GET /v3/models/{model}/software` for the matching model and can be chosen when creating an instance.  **Workflow:**   1. [`createImage`](#tag/images/POST/v3/images) with `{ \"name\": \"...\", \"type\": \"fw\", \"encoding\": \"plain\" }` as JSON. Keep the returned `id`.   2. Upload the file with [`uploadImageData`](#tag/images/POST/v3/images/{imageId}) or, for large files, [`uploadImageChunk`](#tag/images/PUT/v3/images/{imageId}/file). Supplying `corelliumChecksum` there lets the server verify the file.   3. **`installFirmware`** with `{ \"imageId\": \"<id>\" }`. Returns a `taskId`.   4. Poll [`getInstallFirmwareStatus`](#tag/images/GET/v3/images/install-firmware/{taskId}) with the `taskId` until `status` is `complete` or `error`.  **What happens.** The server hands the file to the firmware service and returns 201 with a `taskId` as soon as the hand-off succeeds; installation continues in the background and can take a long time (up to 45 minutes for files around 10 GB). The source image is deleted from `/v3/images` at the moment of hand-off, before installation finishes. If installation then fails, upload the file again to retry.  A 400 can mean the firmware service rejected the image's checksum. Check that the file uploaded completely and, if you supplied `corelliumChecksum`, that it was correct.
//
install_firmware_response_t*
ImagesAPI_v3InstallFirmware(apiClient_t *apiClient, install_firmware_body_t *install_firmware_body)
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
    char *localVarPath = strdup("/v3/images/install-firmware");





    // Body Param
    cJSON *localVarSingleItemJSON_install_firmware_body = NULL;
    if (install_firmware_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_install_firmware_body = install_firmware_body_convertToJSON(install_firmware_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_install_firmware_body);
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
    //    printf("%s\n","Install task accepted.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid request body, or firmware checksum rejected.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","No firmware-type Image with the given imageId.");
    //}
    //nonprimitive not container
    install_firmware_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ImagesAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = install_firmware_response_parseFromJSON(ImagesAPIlocalVarJSON);
        cJSON_Delete(ImagesAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_install_firmware_body) {
        cJSON_Delete(localVarSingleItemJSON_install_firmware_body);
        localVarSingleItemJSON_install_firmware_body = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Install firmware assets cluster-wide
//
// Installs an uploaded firmware-assets JSON blob for cluster-wide use. On success the source Image is deleted from the Images store. The blob is forwarded to the firmware service, which merges it into the cluster-wide firmware-assets manifest.   **This is step 3 of the firmware-assets-install workflow:**   1. [`createImage`](#tag/images/POST/v3/images) with `{ name: 'fcs-keys.json', type: 'fwasset' }` → returns an `imageId`.   2. [`uploadImageData`](#tag/images/POST/v3/images/{imageId}) with the assets file → uploads contents.   3. **`installFirmwareAssets`** with `{ imageId }` → installs the assets.   Unlike [`installFirmware`](#tag/images/POST/v3/images/install-firmware), this endpoint completes synchronously and returns the firmware service's response message directly; there is no task to poll.
//
install_firmware_assets_response_t*
ImagesAPI_v3InstallFirmwareAssets(apiClient_t *apiClient, install_firmware_assets_body_t *install_firmware_assets_body)
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
    char *localVarPath = strdup("/v3/images/install-firmware-assets");





    // Body Param
    cJSON *localVarSingleItemJSON_install_firmware_assets_body = NULL;
    if (install_firmware_assets_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_install_firmware_assets_body = install_firmware_assets_body_convertToJSON(install_firmware_assets_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_install_firmware_assets_body);
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
    //    printf("%s\n","Assets installed (or no-op if assets already present).");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid request body, or image contents are not valid JSON.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","No fwasset-type Image with the given imageId, or image is on a remote coordinator.");
    //}
    //nonprimitive not container
    install_firmware_assets_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ImagesAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = install_firmware_assets_response_parseFromJSON(ImagesAPIlocalVarJSON);
        cJSON_Delete(ImagesAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_install_firmware_assets_body) {
        cJSON_Delete(localVarSingleItemJSON_install_firmware_assets_body);
        localVarSingleItemJSON_install_firmware_assets_body = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// List image metadata
//
// Lists the images you can see: images in your projects plus domain-level images. File contents are not included; use the download or upload endpoints for those.  Set `projectId` to list only one project's images. Results are paginated with `limit` and `offset`.  Installed firmware is not listed here: once `installFirmware` hands an image off, it disappears from this list and shows up in `GET /v3/models/{model}/software` instead.
//
image_list_t*
ImagesAPI_v3ListImages(apiClient_t *apiClient, double *limit, double *offset, char *projectId)
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
    char *localVarPath = strdup("/v3/images");





    // query parameters
    char *keyQuery_limit = NULL;
    char * valueQuery_limit = NULL;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_limit, MAX_NUMBER_LENGTH, "%d", *limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, valueQuery_limit);
        list_addElement(localVarQueryParameters,keyPairQuery_limit);
    }

    // query parameters
    char *keyQuery_offset = NULL;
    char * valueQuery_offset = NULL;
    keyValuePair_t *keyPairQuery_offset = 0;
    if (offset)
    {
        keyQuery_offset = strdup("offset");
        valueQuery_offset = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_offset, MAX_NUMBER_LENGTH, "%d", *offset);
        keyPairQuery_offset = keyValuePair_create(keyQuery_offset, valueQuery_offset);
        list_addElement(localVarQueryParameters,keyPairQuery_offset);
    }

    // query parameters
    char *keyQuery_projectId = NULL;
    char * valueQuery_projectId = NULL;
    keyValuePair_t *keyPairQuery_projectId = 0;
    if (projectId)
    {
        keyQuery_projectId = strdup("projectId");
        valueQuery_projectId = strdup((projectId));
        keyPairQuery_projectId = keyValuePair_create(keyQuery_projectId, valueQuery_projectId);
        list_addElement(localVarQueryParameters,keyPairQuery_projectId);
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
    //    printf("%s\n","Paginated list of image metadata.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    //nonprimitive not container
    image_list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ImagesAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = image_list_parseFromJSON(ImagesAPIlocalVarJSON);
        cJSON_Delete(ImagesAPIlocalVarJSON);
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
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    if(keyQuery_limit){
        free(keyQuery_limit);
        keyQuery_limit = NULL;
    }
    if(valueQuery_limit){
        free(valueQuery_limit);
        valueQuery_limit = NULL;
    }
    if(keyPairQuery_limit){
        keyValuePair_free(keyPairQuery_limit);
        keyPairQuery_limit = NULL;
    }
    if(keyQuery_offset){
        free(keyQuery_offset);
        keyQuery_offset = NULL;
    }
    if(valueQuery_offset){
        free(valueQuery_offset);
        valueQuery_offset = NULL;
    }
    if(keyPairQuery_offset){
        keyValuePair_free(keyPairQuery_offset);
        keyPairQuery_offset = NULL;
    }
    if(keyQuery_projectId){
        free(keyQuery_projectId);
        keyQuery_projectId = NULL;
    }
    if(valueQuery_projectId){
        free(valueQuery_projectId);
        valueQuery_projectId = NULL;
    }
    if(keyPairQuery_projectId){
        keyValuePair_free(keyPairQuery_projectId);
        keyPairQuery_projectId = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Upload one chunk of an image file
//
// Uploads a single chunk of an Image previously created via [`createImage`](#tag/images/POST/v3/images), using the resumable upload protocol. This is the recommended way to upload large images: the transfer survives interruptions, because any chunk can be re-sent and already-stored chunks can be skipped.   **Chunked upload workflow:**   1. [`createImage`](#tag/images/POST/v3/images) with `{ name, type, encoding }` → returns an `imageId`.   2. Split the file into fixed-size chunks and **`uploadImageChunk`** each one with the      `resumable*` query parameters describing it. Chunks may be uploaded in any order and      concurrently.   3. Optionally probe a chunk with [`getImageChunk`](#tag/images/GET/v3/images/{imageId}/file) before      (re-)sending it, so an interrupted upload only re-sends what is missing.   The image is finalized automatically by the request that completes the chunk set, so the last chunk to arrive also validates `corelliumChecksum` (when supplied) and runs the firmware post-processing. Re-sending a chunk that was already stored is safe. If the upload fails for any reason other than a retryable transport error, the partially uploaded image is deleted, so the client must create a new image record before retrying.   The image's `encoding` and `encapsulated` settings are fixed when the record is created by [`createImage`](#tag/images/POST/v3/images) and cannot be changed by a chunk request.
//
void
ImagesAPI_v3UploadImageChunk(apiClient_t *apiClient, char *imageId, double *resumableChunkNumber, double *resumableChunkSize, double *resumableCurrentChunkSize, double *resumableTotalSize, double *resumableTotalChunks, binary_t* body, char *resumableIdentifier, char *resumableFilename, char *resumableRelativePath, char *resumableType, char *corelliumChecksum, char *x_corellium_total_file_size)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = list_createList();
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v3/images/{imageId}/file");

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



    // header parameters
    char *keyHeader_x_corellium_total_file_size = NULL;
    char * valueHeader_x_corellium_total_file_size = 0;
    keyValuePair_t *keyPairHeader_x_corellium_total_file_size = 0;
    if (x_corellium_total_file_size) {
        keyHeader_x_corellium_total_file_size = strdup("x-corellium-total-file-size");
        valueHeader_x_corellium_total_file_size = strdup((x_corellium_total_file_size));
        keyPairHeader_x_corellium_total_file_size = keyValuePair_create(keyHeader_x_corellium_total_file_size, valueHeader_x_corellium_total_file_size);
        list_addElement(localVarHeaderParameters,keyPairHeader_x_corellium_total_file_size);
    }


    // query parameters
    char *keyQuery_resumableChunkNumber = NULL;
    char * valueQuery_resumableChunkNumber = NULL;
    keyValuePair_t *keyPairQuery_resumableChunkNumber = 0;
    if (resumableChunkNumber)
    {
        keyQuery_resumableChunkNumber = strdup("resumableChunkNumber");
        valueQuery_resumableChunkNumber = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_resumableChunkNumber, MAX_NUMBER_LENGTH, "%d", *resumableChunkNumber);
        keyPairQuery_resumableChunkNumber = keyValuePair_create(keyQuery_resumableChunkNumber, valueQuery_resumableChunkNumber);
        list_addElement(localVarQueryParameters,keyPairQuery_resumableChunkNumber);
    }

    // query parameters
    char *keyQuery_resumableChunkSize = NULL;
    char * valueQuery_resumableChunkSize = NULL;
    keyValuePair_t *keyPairQuery_resumableChunkSize = 0;
    if (resumableChunkSize)
    {
        keyQuery_resumableChunkSize = strdup("resumableChunkSize");
        valueQuery_resumableChunkSize = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_resumableChunkSize, MAX_NUMBER_LENGTH, "%d", *resumableChunkSize);
        keyPairQuery_resumableChunkSize = keyValuePair_create(keyQuery_resumableChunkSize, valueQuery_resumableChunkSize);
        list_addElement(localVarQueryParameters,keyPairQuery_resumableChunkSize);
    }

    // query parameters
    char *keyQuery_resumableCurrentChunkSize = NULL;
    char * valueQuery_resumableCurrentChunkSize = NULL;
    keyValuePair_t *keyPairQuery_resumableCurrentChunkSize = 0;
    if (resumableCurrentChunkSize)
    {
        keyQuery_resumableCurrentChunkSize = strdup("resumableCurrentChunkSize");
        valueQuery_resumableCurrentChunkSize = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_resumableCurrentChunkSize, MAX_NUMBER_LENGTH, "%d", *resumableCurrentChunkSize);
        keyPairQuery_resumableCurrentChunkSize = keyValuePair_create(keyQuery_resumableCurrentChunkSize, valueQuery_resumableCurrentChunkSize);
        list_addElement(localVarQueryParameters,keyPairQuery_resumableCurrentChunkSize);
    }

    // query parameters
    char *keyQuery_resumableTotalSize = NULL;
    char * valueQuery_resumableTotalSize = NULL;
    keyValuePair_t *keyPairQuery_resumableTotalSize = 0;
    if (resumableTotalSize)
    {
        keyQuery_resumableTotalSize = strdup("resumableTotalSize");
        valueQuery_resumableTotalSize = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_resumableTotalSize, MAX_NUMBER_LENGTH, "%d", *resumableTotalSize);
        keyPairQuery_resumableTotalSize = keyValuePair_create(keyQuery_resumableTotalSize, valueQuery_resumableTotalSize);
        list_addElement(localVarQueryParameters,keyPairQuery_resumableTotalSize);
    }

    // query parameters
    char *keyQuery_resumableTotalChunks = NULL;
    char * valueQuery_resumableTotalChunks = NULL;
    keyValuePair_t *keyPairQuery_resumableTotalChunks = 0;
    if (resumableTotalChunks)
    {
        keyQuery_resumableTotalChunks = strdup("resumableTotalChunks");
        valueQuery_resumableTotalChunks = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_resumableTotalChunks, MAX_NUMBER_LENGTH, "%d", *resumableTotalChunks);
        keyPairQuery_resumableTotalChunks = keyValuePair_create(keyQuery_resumableTotalChunks, valueQuery_resumableTotalChunks);
        list_addElement(localVarQueryParameters,keyPairQuery_resumableTotalChunks);
    }

    // query parameters
    char *keyQuery_resumableIdentifier = NULL;
    char * valueQuery_resumableIdentifier = NULL;
    keyValuePair_t *keyPairQuery_resumableIdentifier = 0;
    if (resumableIdentifier)
    {
        keyQuery_resumableIdentifier = strdup("resumableIdentifier");
        valueQuery_resumableIdentifier = strdup((resumableIdentifier));
        keyPairQuery_resumableIdentifier = keyValuePair_create(keyQuery_resumableIdentifier, valueQuery_resumableIdentifier);
        list_addElement(localVarQueryParameters,keyPairQuery_resumableIdentifier);
    }

    // query parameters
    char *keyQuery_resumableFilename = NULL;
    char * valueQuery_resumableFilename = NULL;
    keyValuePair_t *keyPairQuery_resumableFilename = 0;
    if (resumableFilename)
    {
        keyQuery_resumableFilename = strdup("resumableFilename");
        valueQuery_resumableFilename = strdup((resumableFilename));
        keyPairQuery_resumableFilename = keyValuePair_create(keyQuery_resumableFilename, valueQuery_resumableFilename);
        list_addElement(localVarQueryParameters,keyPairQuery_resumableFilename);
    }

    // query parameters
    char *keyQuery_resumableRelativePath = NULL;
    char * valueQuery_resumableRelativePath = NULL;
    keyValuePair_t *keyPairQuery_resumableRelativePath = 0;
    if (resumableRelativePath)
    {
        keyQuery_resumableRelativePath = strdup("resumableRelativePath");
        valueQuery_resumableRelativePath = strdup((resumableRelativePath));
        keyPairQuery_resumableRelativePath = keyValuePair_create(keyQuery_resumableRelativePath, valueQuery_resumableRelativePath);
        list_addElement(localVarQueryParameters,keyPairQuery_resumableRelativePath);
    }

    // query parameters
    char *keyQuery_resumableType = NULL;
    char * valueQuery_resumableType = NULL;
    keyValuePair_t *keyPairQuery_resumableType = 0;
    if (resumableType)
    {
        keyQuery_resumableType = strdup("resumableType");
        valueQuery_resumableType = strdup((resumableType));
        keyPairQuery_resumableType = keyValuePair_create(keyQuery_resumableType, valueQuery_resumableType);
        list_addElement(localVarQueryParameters,keyPairQuery_resumableType);
    }

    // query parameters
    char *keyQuery_corelliumChecksum = NULL;
    char * valueQuery_corelliumChecksum = NULL;
    keyValuePair_t *keyPairQuery_corelliumChecksum = 0;
    if (corelliumChecksum)
    {
        keyQuery_corelliumChecksum = strdup("corelliumChecksum");
        valueQuery_corelliumChecksum = strdup((corelliumChecksum));
        keyPairQuery_corelliumChecksum = keyValuePair_create(keyQuery_corelliumChecksum, valueQuery_corelliumChecksum);
        list_addElement(localVarQueryParameters,keyPairQuery_corelliumChecksum);
    }

    // Body Param
    localVarBodyParameters = malloc(body->len);
    memcpy(localVarBodyParameters, body->data, body->len);
    localVarBodyLength = body->len;
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/octet-stream"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "PUT");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 204) {
    //    printf("%s\n","Chunk stored; empty body.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid chunk parameters, checksum mismatch, chunk size differing from the block size of corelliumChecksum, or a missing corelliumChecksum for an airgapped firmware upload.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","No permission for the image&#39;s project, or the image is site-wide and the caller is not a domain (on-site) or cloud administrator.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","No image with the given imageId; create it before uploading chunks.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 413) {
    //    printf("%s\n","The upload exceeds the project&#39;s storage quota, or the size limit for this image type (ramdisk, kernel).");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 507) {
    //    printf("%s\n","The local image pool does not have enough free space for this upload.");
    //}
    //No return type
end:
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    list_freeList(localVarQueryParameters);
    list_freeList(localVarHeaderParameters);
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_imageId);
    if (keyHeader_x_corellium_total_file_size) {
        free(keyHeader_x_corellium_total_file_size);
        keyHeader_x_corellium_total_file_size = NULL;
    }
    if (valueHeader_x_corellium_total_file_size) {
        free(valueHeader_x_corellium_total_file_size);
        valueHeader_x_corellium_total_file_size = NULL;
    }
    free(keyPairHeader_x_corellium_total_file_size);
    free(localVarBodyParameters);
    if(keyQuery_resumableIdentifier){
        free(keyQuery_resumableIdentifier);
        keyQuery_resumableIdentifier = NULL;
    }
    if(valueQuery_resumableIdentifier){
        free(valueQuery_resumableIdentifier);
        valueQuery_resumableIdentifier = NULL;
    }
    if(keyPairQuery_resumableIdentifier){
        keyValuePair_free(keyPairQuery_resumableIdentifier);
        keyPairQuery_resumableIdentifier = NULL;
    }
    if(keyQuery_resumableIdentifier){
        free(keyQuery_resumableIdentifier);
        keyQuery_resumableIdentifier = NULL;
    }
    if(keyPairQuery_resumableIdentifier){
        keyValuePair_free(keyPairQuery_resumableIdentifier);
        keyPairQuery_resumableIdentifier = NULL;
    }
    if(keyQuery_resumableFilename){
        free(keyQuery_resumableFilename);
        keyQuery_resumableFilename = NULL;
    }
    if(valueQuery_resumableFilename){
        free(valueQuery_resumableFilename);
        valueQuery_resumableFilename = NULL;
    }
    if(keyPairQuery_resumableFilename){
        keyValuePair_free(keyPairQuery_resumableFilename);
        keyPairQuery_resumableFilename = NULL;
    }
    if(keyQuery_resumableFilename){
        free(keyQuery_resumableFilename);
        keyQuery_resumableFilename = NULL;
    }
    if(keyPairQuery_resumableFilename){
        keyValuePair_free(keyPairQuery_resumableFilename);
        keyPairQuery_resumableFilename = NULL;
    }
    if(keyQuery_resumableRelativePath){
        free(keyQuery_resumableRelativePath);
        keyQuery_resumableRelativePath = NULL;
    }
    if(valueQuery_resumableRelativePath){
        free(valueQuery_resumableRelativePath);
        valueQuery_resumableRelativePath = NULL;
    }
    if(keyPairQuery_resumableRelativePath){
        keyValuePair_free(keyPairQuery_resumableRelativePath);
        keyPairQuery_resumableRelativePath = NULL;
    }
    if(keyQuery_resumableRelativePath){
        free(keyQuery_resumableRelativePath);
        keyQuery_resumableRelativePath = NULL;
    }
    if(keyPairQuery_resumableRelativePath){
        keyValuePair_free(keyPairQuery_resumableRelativePath);
        keyPairQuery_resumableRelativePath = NULL;
    }
    if(keyQuery_resumableType){
        free(keyQuery_resumableType);
        keyQuery_resumableType = NULL;
    }
    if(valueQuery_resumableType){
        free(valueQuery_resumableType);
        valueQuery_resumableType = NULL;
    }
    if(keyPairQuery_resumableType){
        keyValuePair_free(keyPairQuery_resumableType);
        keyPairQuery_resumableType = NULL;
    }
    if(keyQuery_resumableType){
        free(keyQuery_resumableType);
        keyQuery_resumableType = NULL;
    }
    if(keyPairQuery_resumableType){
        keyValuePair_free(keyPairQuery_resumableType);
        keyPairQuery_resumableType = NULL;
    }
    if(keyQuery_corelliumChecksum){
        free(keyQuery_corelliumChecksum);
        keyQuery_corelliumChecksum = NULL;
    }
    if(valueQuery_corelliumChecksum){
        free(valueQuery_corelliumChecksum);
        valueQuery_corelliumChecksum = NULL;
    }
    if(keyPairQuery_corelliumChecksum){
        keyValuePair_free(keyPairQuery_corelliumChecksum);
        keyPairQuery_corelliumChecksum = NULL;
    }
    if(keyQuery_corelliumChecksum){
        free(keyQuery_corelliumChecksum);
        keyQuery_corelliumChecksum = NULL;
    }
    if(keyPairQuery_corelliumChecksum){
        keyValuePair_free(keyPairQuery_corelliumChecksum);
        keyPairQuery_corelliumChecksum = NULL;
    }

}

// Upload image file contents
//
// Uploads the whole file for an image created with [`createImage`](#tag/images/POST/v3/images), in a single `multipart/form-data` request with the file in the `file` part. Returns the updated image, whose `size` and checksums are now filled in.  Supply `corelliumChecksum` to have the server verify the file: if the uploaded contents do not match, the upload is rejected with 400 and the image is removed. Compute it with the same algorithm and block size you pass in the value (`algorithm$blockSize$hash`).  The upload counts against the owning project's storage quota. If the connection drops, the whole file must be sent again. For large images (firmware in particular) use [`uploadImageChunk`](#tag/images/PUT/v3/images/{imageId}/file), which can resume.
//
image_t*
ImagesAPI_v3UploadImageData(apiClient_t *apiClient, char *imageId, binary_t* file, char *corelliumChecksum)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v3/images/{imageId}");

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



    // query parameters
    char *keyQuery_corelliumChecksum = NULL;
    char * valueQuery_corelliumChecksum = NULL;
    keyValuePair_t *keyPairQuery_corelliumChecksum = 0;
    if (corelliumChecksum)
    {
        keyQuery_corelliumChecksum = strdup("corelliumChecksum");
        valueQuery_corelliumChecksum = strdup((corelliumChecksum));
        keyPairQuery_corelliumChecksum = keyValuePair_create(keyQuery_corelliumChecksum, valueQuery_corelliumChecksum);
        list_addElement(localVarQueryParameters,keyPairQuery_corelliumChecksum);
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
    //    printf("%s\n","Upload accepted; updated image metadata returned.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid upload or checksum mismatch.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Not signed in: the &#x60;Authorization: Bearer &lt;token&gt;&#x60; header is missing, or the token is invalid or expired. Get a new token and retry.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","No image with the given imageId.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 409) {
    //    printf("%s\n","An image with conflicting identity already exists.");
    //}
    //nonprimitive not container
    image_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ImagesAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = image_parseFromJSON(ImagesAPIlocalVarJSON);
        cJSON_Delete(ImagesAPIlocalVarJSON);
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
    list_freeList(localVarQueryParameters);
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_imageId);
    if(keyQuery_corelliumChecksum){
        free(keyQuery_corelliumChecksum);
        keyQuery_corelliumChecksum = NULL;
    }
    if(valueQuery_corelliumChecksum){
        free(valueQuery_corelliumChecksum);
        valueQuery_corelliumChecksum = NULL;
    }
    if(keyPairQuery_corelliumChecksum){
        keyValuePair_free(keyPairQuery_corelliumChecksum);
        keyPairQuery_corelliumChecksum = NULL;
    }
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

