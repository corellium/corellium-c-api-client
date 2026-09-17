#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "ProjectsAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096


// Create a project
//
// **Required role:** Domain administrator.  Create a new project in the authenticated user's domain.
//
project_t*
ProjectsAPI_v3CreateProject(apiClient_t *apiClient, create_project_body_t *create_project_body)
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
    char *localVarPath = strdup("/v3/projects");





    // Body Param
    cJSON *localVarSingleItemJSON_create_project_body = NULL;
    if (create_project_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_create_project_body = create_project_body_convertToJSON(create_project_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_create_project_body);
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
    //    printf("%s\n","The created project.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","The project payload is invalid.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Authentication required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Domain administrator permissions required.");
    //}
    //nonprimitive not container
    project_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ProjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = project_parseFromJSON(ProjectsAPIlocalVarJSON);
        cJSON_Delete(ProjectsAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_create_project_body) {
        cJSON_Delete(localVarSingleItemJSON_create_project_body);
        localVarSingleItemJSON_create_project_body = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Add a project key
//
// **Required role:** Domain administrator or project administrator.  Add an authorized key to a project.
//
project_key_t*
ProjectsAPI_v3CreateProjectKey(apiClient_t *apiClient, char *projectId, create_project_key_body_t *create_project_key_body)
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
    char *localVarPath = strdup("/v3/projects/{projectId}/keys");

    if(!projectId)
        goto end;


    // Path Params
    long sizeOfPathParams_projectId = strlen(projectId)+3 + sizeof("{ projectId }") - 1;
    if(projectId == NULL) {
        goto end;
    }
    char* localVarToReplace_projectId = malloc(sizeOfPathParams_projectId);
    sprintf(localVarToReplace_projectId, "{%s}", "projectId");

    localVarPath = strReplace(localVarPath, localVarToReplace_projectId, projectId);



    // Body Param
    cJSON *localVarSingleItemJSON_create_project_key_body = NULL;
    if (create_project_key_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_create_project_key_body = create_project_key_body_convertToJSON(create_project_key_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_create_project_key_body);
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
    //    printf("%s\n","The added authorized key.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","The supplied public key is invalid.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Authentication required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Domain administrator or project administrator permissions required. This deployment is not licensed for SSH key pairing.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","No project with the given identifier.");
    //}
    //nonprimitive not container
    project_key_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ProjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = project_key_parseFromJSON(ProjectsAPIlocalVarJSON);
        cJSON_Delete(ProjectsAPIlocalVarJSON);
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
    free(localVarToReplace_projectId);
    if (localVarSingleItemJSON_create_project_key_body) {
        cJSON_Delete(localVarSingleItemJSON_create_project_key_body);
        localVarSingleItemJSON_create_project_key_body = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Delete a project
//
// **Required role:** Domain administrator.  Delete a project. The project must contain no devices.
//
void
ProjectsAPI_v3DeleteProject(apiClient_t *apiClient, char *projectId)
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
    char *localVarPath = strdup("/v3/projects/{projectId}");

    if(!projectId)
        goto end;


    // Path Params
    long sizeOfPathParams_projectId = strlen(projectId)+3 + sizeof("{ projectId }") - 1;
    if(projectId == NULL) {
        goto end;
    }
    char* localVarToReplace_projectId = malloc(sizeOfPathParams_projectId);
    sprintf(localVarToReplace_projectId, "{%s}", "projectId");

    localVarPath = strReplace(localVarPath, localVarToReplace_projectId, projectId);


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
    //    printf("%s\n","The project was deleted.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Authentication required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Domain administrator permissions required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 409) {
    //    printf("%s\n","The project still contains devices and cannot be deleted.");
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
    free(localVarToReplace_projectId);

}

// Delete a project key
//
// **Required role:** Domain administrator or project administrator.  Remove an authorized key from a project.
//
void
ProjectsAPI_v3DeleteProjectKey(apiClient_t *apiClient, char *projectId, char *keyId)
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
    char *localVarPath = strdup("/v3/projects/{projectId}/keys/{keyId}");

    if(!projectId)
        goto end;
    if(!keyId)
        goto end;


    // Path Params
    long sizeOfPathParams_projectId = strlen(projectId)+3 + strlen(keyId)+3 + sizeof("{ projectId }") - 1;
    if(projectId == NULL) {
        goto end;
    }
    char* localVarToReplace_projectId = malloc(sizeOfPathParams_projectId);
    sprintf(localVarToReplace_projectId, "{%s}", "projectId");

    localVarPath = strReplace(localVarPath, localVarToReplace_projectId, projectId);

    // Path Params
    long sizeOfPathParams_keyId = strlen(projectId)+3 + strlen(keyId)+3 + sizeof("{ keyId }") - 1;
    if(keyId == NULL) {
        goto end;
    }
    char* localVarToReplace_keyId = malloc(sizeOfPathParams_keyId);
    sprintf(localVarToReplace_keyId, "{%s}", "keyId");

    localVarPath = strReplace(localVarPath, localVarToReplace_keyId, keyId);


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
    //    printf("%s\n","The authorized key was removed.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Authentication required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Domain administrator or project administrator permissions required.");
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
    free(localVarToReplace_projectId);
    free(localVarToReplace_keyId);

}

// Fetch firmware assets for a project
//
// Relays a set of firmware asset URLs to the firmware service, which downloads the assets server-side and stores them for the project's domain.
//
fetch_firmware_assets_response_t*
ProjectsAPI_v3FetchProjectFirmwareAssets(apiClient_t *apiClient, char *projectId, fetch_firmware_assets_body_t *fetch_firmware_assets_body)
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
    char *localVarPath = strdup("/v3/projects/{projectId}/firmware-assets");

    if(!projectId)
        goto end;


    // Path Params
    long sizeOfPathParams_projectId = strlen(projectId)+3 + sizeof("{ projectId }") - 1;
    if(projectId == NULL) {
        goto end;
    }
    char* localVarToReplace_projectId = malloc(sizeOfPathParams_projectId);
    sprintf(localVarToReplace_projectId, "{%s}", "projectId");

    localVarPath = strReplace(localVarPath, localVarToReplace_projectId, projectId);



    // Body Param
    cJSON *localVarSingleItemJSON_fetch_firmware_assets_body = NULL;
    if (fetch_firmware_assets_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_fetch_firmware_assets_body = fetch_firmware_assets_body_convertToJSON(fetch_firmware_assets_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_fetch_firmware_assets_body);
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
    //    printf("%s\n","The fetch result reported by the firmware service.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","The asset URL payload is invalid.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Authentication required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Permission denied.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","No project with the given identifier.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 409) {
    //    printf("%s\n","Fetching firmware assets is disabled on this cluster.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 503) {
    //    printf("%s\n","The firmware service is currently unavailable.");
    //}
    //nonprimitive not container
    fetch_firmware_assets_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ProjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = fetch_firmware_assets_response_parseFromJSON(ProjectsAPIlocalVarJSON);
        cJSON_Delete(ProjectsAPIlocalVarJSON);
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
    free(localVarToReplace_projectId);
    if (localVarSingleItemJSON_fetch_firmware_assets_body) {
        cJSON_Delete(localVarSingleItemJSON_fetch_firmware_assets_body);
        localVarSingleItemJSON_fetch_firmware_assets_body = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get a project
//
// Retrieve a single project by identifier.
//
project_t*
ProjectsAPI_v3GetProject(apiClient_t *apiClient, char *projectId)
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
    char *localVarPath = strdup("/v3/projects/{projectId}");

    if(!projectId)
        goto end;


    // Path Params
    long sizeOfPathParams_projectId = strlen(projectId)+3 + sizeof("{ projectId }") - 1;
    if(projectId == NULL) {
        goto end;
    }
    char* localVarToReplace_projectId = malloc(sizeOfPathParams_projectId);
    sprintf(localVarToReplace_projectId, "{%s}", "projectId");

    localVarPath = strReplace(localVarPath, localVarToReplace_projectId, projectId);


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
    //    printf("%s\n","The requested project.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Authentication required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Permission denied.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","No project with the given identifier.");
    //}
    //nonprimitive not container
    project_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ProjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = project_parseFromJSON(ProjectsAPIlocalVarJSON);
        cJSON_Delete(ProjectsAPIlocalVarJSON);
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
    free(localVarToReplace_projectId);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get image upload status
//
// Check resumable upload status for a project image or download the image file.
//
binary_t*
ProjectsAPI_v3GetProjectImageUpload(apiClient_t *apiClient, char *projectId, char *type, char *imageId, char *name, double *resumableChunkNumber)
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
    char *localVarPath = strdup("/v3/projects/{projectId}/image-upload/{type}/{imageId}/{name}");

    if(!projectId)
        goto end;
    if(!type)
        goto end;
    if(!imageId)
        goto end;
    if(!name)
        goto end;


    // Path Params
    long sizeOfPathParams_projectId = strlen(projectId)+3 + strlen(type)+3 + strlen(imageId)+3 + strlen(name)+3 + sizeof("{ projectId }") - 1;
    if(projectId == NULL) {
        goto end;
    }
    char* localVarToReplace_projectId = malloc(sizeOfPathParams_projectId);
    sprintf(localVarToReplace_projectId, "{%s}", "projectId");

    localVarPath = strReplace(localVarPath, localVarToReplace_projectId, projectId);

    // Path Params
    long sizeOfPathParams_type = strlen(projectId)+3 + strlen(type)+3 + strlen(imageId)+3 + strlen(name)+3 + sizeof("{ type }") - 1;
    if(type == NULL) {
        goto end;
    }
    char* localVarToReplace_type = malloc(sizeOfPathParams_type);
    sprintf(localVarToReplace_type, "{%s}", "type");

    localVarPath = strReplace(localVarPath, localVarToReplace_type, type);

    // Path Params
    long sizeOfPathParams_imageId = strlen(projectId)+3 + strlen(type)+3 + strlen(imageId)+3 + strlen(name)+3 + sizeof("{ imageId }") - 1;
    if(imageId == NULL) {
        goto end;
    }
    char* localVarToReplace_imageId = malloc(sizeOfPathParams_imageId);
    sprintf(localVarToReplace_imageId, "{%s}", "imageId");

    localVarPath = strReplace(localVarPath, localVarToReplace_imageId, imageId);

    // Path Params
    long sizeOfPathParams_name = strlen(projectId)+3 + strlen(type)+3 + strlen(imageId)+3 + strlen(name)+3 + sizeof("{ name }") - 1;
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



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
    list_addElement(localVarHeaderType,"application/octet-stream"); //produces
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
    //    printf("%s\n","An empty JSON object when a probed chunk is already stored, the image bytes when the file is stored locally, or the image metadata when no file has been stored yet.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 204) {
    //    printf("%s\n","The probed chunk is not stored yet and still needs to be uploaded.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 302) {
    //    printf("%s\n","The image is stored in S3; follow the Location header to download it.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","The image identifier is invalid or the image record is missing.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Authentication required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Permission denied.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","No image with the given identifier.");
    //}
    //primitive return type simple binary
    binary_t* elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300)
        elementToReturn = instantiate_binary_t(apiClient->dataReceived, apiClient->dataReceivedLen);

    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_projectId);
    free(localVarToReplace_type);
    free(localVarToReplace_imageId);
    free(localVarToReplace_name);
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get project network log
//
// Retrieve the egress network connection log for a project as plain text.
//
char*
ProjectsAPI_v3GetProjectNetworkLog(apiClient_t *apiClient, char *projectId)
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
    char *localVarPath = strdup("/v3/projects/{projectId}/network/log");

    if(!projectId)
        goto end;


    // Path Params
    long sizeOfPathParams_projectId = strlen(projectId)+3 + sizeof("{ projectId }") - 1;
    if(projectId == NULL) {
        goto end;
    }
    char* localVarToReplace_projectId = malloc(sizeOfPathParams_projectId);
    sprintf(localVarToReplace_projectId, "{%s}", "projectId");

    localVarPath = strReplace(localVarPath, localVarToReplace_projectId, projectId);


    list_addElement(localVarHeaderType,"text/plain"); //produces
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
    //    printf("%s\n","The project network connection log.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Authentication required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Permission denied.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","No project with the given identifier.");
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
    
    free(localVarPath);
    free(localVarToReplace_projectId);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get project network status
//
// Retrieve the egress network connection status for a project.
//
network_status_t*
ProjectsAPI_v3GetProjectNetworkStatus(apiClient_t *apiClient, char *projectId)
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
    char *localVarPath = strdup("/v3/projects/{projectId}/network/status");

    if(!projectId)
        goto end;


    // Path Params
    long sizeOfPathParams_projectId = strlen(projectId)+3 + sizeof("{ projectId }") - 1;
    if(projectId == NULL) {
        goto end;
    }
    char* localVarToReplace_projectId = malloc(sizeOfPathParams_projectId);
    sprintf(localVarToReplace_projectId, "{%s}", "projectId");

    localVarPath = strReplace(localVarPath, localVarToReplace_projectId, projectId);


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
    //    printf("%s\n","The project network connection status.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Authentication required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Permission denied.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","No project with the given identifier.");
    //}
    //nonprimitive not container
    network_status_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ProjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = network_status_parseFromJSON(ProjectsAPIlocalVarJSON);
        cJSON_Delete(ProjectsAPIlocalVarJSON);
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
    free(localVarToReplace_projectId);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get project VPN configuration
//
// Retrieve the project VPN configuration. A project VPN allows a client (e.g. a researcher's computer) to connect into the virtual devices within the project. The response media type follows the requested format: 'ovpn' returns a text OpenVPN profile, any other value returns a binary Tunnelblick zip.
//
char*
ProjectsAPI_v3GetProjectVpnConfig(apiClient_t *apiClient, char *projectId, char *format)
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
    char *localVarPath = strdup("/v3/projects/{projectId}/vpnconfig/{format}");

    if(!projectId)
        goto end;
    if(!format)
        goto end;


    // Path Params
    long sizeOfPathParams_projectId = strlen(projectId)+3 + strlen(format)+3 + sizeof("{ projectId }") - 1;
    if(projectId == NULL) {
        goto end;
    }
    char* localVarToReplace_projectId = malloc(sizeOfPathParams_projectId);
    sprintf(localVarToReplace_projectId, "{%s}", "projectId");

    localVarPath = strReplace(localVarPath, localVarToReplace_projectId, projectId);

    // Path Params
    long sizeOfPathParams_format = strlen(projectId)+3 + strlen(format)+3 + sizeof("{ format }") - 1;
    if(format == NULL) {
        goto end;
    }
    char* localVarToReplace_format = malloc(sizeOfPathParams_format);
    sprintf(localVarToReplace_format, "{%s}", "format");

    localVarPath = strReplace(localVarPath, localVarToReplace_format, format);


    list_addElement(localVarHeaderType,"application/x-openvpn-profile"); //produces
    list_addElement(localVarHeaderType,"application/zip"); //produces
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
    //    printf("%s\n","The VPN configuration, as a text OpenVPN profile or a binary Tunnelblick zip.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","The project does not have an active VPN IP or port.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Authentication required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Permission denied.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","No project with the given identifier.");
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
    
    free(localVarPath);
    free(localVarToReplace_projectId);
    free(localVarToReplace_format);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// List project instances
//
// List the instances belonging to a project.
//
project_instance_list_t*
ProjectsAPI_v3ListProjectInstances(apiClient_t *apiClient, char *projectId, double *limit, double *offset, char *name)
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
    char *localVarPath = strdup("/v3/projects/{projectId}/instances");

    if(!projectId)
        goto end;


    // Path Params
    long sizeOfPathParams_projectId = strlen(projectId)+3 + sizeof("{ projectId }") - 1;
    if(projectId == NULL) {
        goto end;
    }
    char* localVarToReplace_projectId = malloc(sizeOfPathParams_projectId);
    sprintf(localVarToReplace_projectId, "{%s}", "projectId");

    localVarPath = strReplace(localVarPath, localVarToReplace_projectId, projectId);



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
    //    printf("%s\n","Paginated list of instances in the project.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Authentication required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Permission denied.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","No project with the given identifier.");
    //}
    //nonprimitive not container
    project_instance_list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ProjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = project_instance_list_parseFromJSON(ProjectsAPIlocalVarJSON);
        cJSON_Delete(ProjectsAPIlocalVarJSON);
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
    free(localVarToReplace_projectId);
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// List project keys
//
// List the authorized keys for a project.
//
project_key_list_t*
ProjectsAPI_v3ListProjectKeys(apiClient_t *apiClient, char *projectId, double *limit, double *offset)
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
    char *localVarPath = strdup("/v3/projects/{projectId}/keys");

    if(!projectId)
        goto end;


    // Path Params
    long sizeOfPathParams_projectId = strlen(projectId)+3 + sizeof("{ projectId }") - 1;
    if(projectId == NULL) {
        goto end;
    }
    char* localVarToReplace_projectId = malloc(sizeOfPathParams_projectId);
    sprintf(localVarToReplace_projectId, "{%s}", "projectId");

    localVarPath = strReplace(localVarPath, localVarToReplace_projectId, projectId);



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
    //    printf("%s\n","Paginated list of authorized keys.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Authentication required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","This deployment is not licensed for SSH key pairing.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","No project with the given identifier.");
    //}
    //nonprimitive not container
    project_key_list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ProjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = project_key_list_parseFromJSON(ProjectsAPIlocalVarJSON);
        cJSON_Delete(ProjectsAPIlocalVarJSON);
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
    free(localVarToReplace_projectId);
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// List projects
//
// List the projects the authenticated user can access.
//
project_list_t*
ProjectsAPI_v3ListProjects(apiClient_t *apiClient, double *limit, double *offset, char *name)
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
    char *localVarPath = strdup("/v3/projects");





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
    //    printf("%s\n","Paginated list of projects.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Authentication required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Permission denied.");
    //}
    //nonprimitive not container
    project_list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ProjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = project_list_parseFromJSON(ProjectsAPIlocalVarJSON);
        cJSON_Delete(ProjectsAPIlocalVarJSON);
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Update a project
//
// Update a project's name, settings, or quotas. This is the single canonical way to change project settings: fields provided in `settings` are merged into the project's existing settings, so omitted fields are preserved.
//
project_t*
ProjectsAPI_v3PatchProject(apiClient_t *apiClient, char *projectId, patch_project_body_t *patch_project_body)
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
    char *localVarPath = strdup("/v3/projects/{projectId}");

    if(!projectId)
        goto end;


    // Path Params
    long sizeOfPathParams_projectId = strlen(projectId)+3 + sizeof("{ projectId }") - 1;
    if(projectId == NULL) {
        goto end;
    }
    char* localVarToReplace_projectId = malloc(sizeOfPathParams_projectId);
    sprintf(localVarToReplace_projectId, "{%s}", "projectId");

    localVarPath = strReplace(localVarPath, localVarToReplace_projectId, projectId);



    // Body Param
    cJSON *localVarSingleItemJSON_patch_project_body = NULL;
    if (patch_project_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_patch_project_body = patch_project_body_convertToJSON(patch_project_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_patch_project_body);
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
    //    printf("%s\n","The updated project.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","The update payload is invalid, or the network connection cannot be changed while instances are active.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Authentication required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Permission denied.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","No project with the given identifier.");
    //}
    //nonprimitive not container
    project_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ProjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = project_parseFromJSON(ProjectsAPIlocalVarJSON);
        cJSON_Delete(ProjectsAPIlocalVarJSON);
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
    free(localVarToReplace_projectId);
    if (localVarSingleItemJSON_patch_project_body) {
        cJSON_Delete(localVarSingleItemJSON_patch_project_body);
        localVarSingleItemJSON_patch_project_body = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Pre-authorize a VPN configuration download
//
// Pre-authorize a VPN configuration download. Returns a short-lived signed token that authorizes the download without an Authorization header, so it can be embedded in a plain download URL: GET /v1/preauthed-vpn-configs/{token}/{filename}. The token carries the client identifier and the format, and expires with the calling session token.
//
vpn_config_preauthorization_t*
ProjectsAPI_v3PreauthVpnConfig(apiClient_t *apiClient, char *projectId, char *filename)
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
    char *localVarPath = strdup("/v3/projects/{projectId}/preauth-vpn-config/{filename}");

    if(!projectId)
        goto end;
    if(!filename)
        goto end;


    // Path Params
    long sizeOfPathParams_projectId = strlen(projectId)+3 + strlen(filename)+3 + sizeof("{ projectId }") - 1;
    if(projectId == NULL) {
        goto end;
    }
    char* localVarToReplace_projectId = malloc(sizeOfPathParams_projectId);
    sprintf(localVarToReplace_projectId, "{%s}", "projectId");

    localVarPath = strReplace(localVarPath, localVarToReplace_projectId, projectId);

    // Path Params
    long sizeOfPathParams_filename = strlen(projectId)+3 + strlen(filename)+3 + sizeof("{ filename }") - 1;
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
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","A short-lived signed token.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","The project does not have an active VPN IP or port.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Authentication required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Permission denied.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","No project with the given identifier.");
    //}
    //nonprimitive not container
    vpn_config_preauthorization_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ProjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = vpn_config_preauthorization_parseFromJSON(ProjectsAPIlocalVarJSON);
        cJSON_Delete(ProjectsAPIlocalVarJSON);
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
    free(localVarToReplace_projectId);
    free(localVarToReplace_filename);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Upload image chunk
//
// Upload a chunk of a project image using the resumable upload protocol. Creates the image record on the first chunk if it does not yet exist. This is the upload used while creating a device, before any instance exists to own the image.
//
object_t*
ProjectsAPI_v3PutProjectImageUpload(apiClient_t *apiClient, char *projectId, char *type, char *imageId, char *name, binary_t* body, double *resumableChunkNumber, double *resumableChunkSize, double *resumableCurrentChunkSize, double *resumableTotalSize, double *resumableTotalChunks, char *corelliumChecksum, char *flavor, char *x_corellium_image_encoding, int *x_corellium_image_encapsulated, double *x_corellium_total_file_size, char *x_corellium_image_password)
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
    char *localVarPath = strdup("/v3/projects/{projectId}/image-upload/{type}/{imageId}/{name}");

    if(!projectId)
        goto end;
    if(!type)
        goto end;
    if(!imageId)
        goto end;
    if(!name)
        goto end;


    // Path Params
    long sizeOfPathParams_projectId = strlen(projectId)+3 + strlen(type)+3 + strlen(imageId)+3 + strlen(name)+3 + sizeof("{ projectId }") - 1;
    if(projectId == NULL) {
        goto end;
    }
    char* localVarToReplace_projectId = malloc(sizeOfPathParams_projectId);
    sprintf(localVarToReplace_projectId, "{%s}", "projectId");

    localVarPath = strReplace(localVarPath, localVarToReplace_projectId, projectId);

    // Path Params
    long sizeOfPathParams_type = strlen(projectId)+3 + strlen(type)+3 + strlen(imageId)+3 + strlen(name)+3 + sizeof("{ type }") - 1;
    if(type == NULL) {
        goto end;
    }
    char* localVarToReplace_type = malloc(sizeOfPathParams_type);
    sprintf(localVarToReplace_type, "{%s}", "type");

    localVarPath = strReplace(localVarPath, localVarToReplace_type, type);

    // Path Params
    long sizeOfPathParams_imageId = strlen(projectId)+3 + strlen(type)+3 + strlen(imageId)+3 + strlen(name)+3 + sizeof("{ imageId }") - 1;
    if(imageId == NULL) {
        goto end;
    }
    char* localVarToReplace_imageId = malloc(sizeOfPathParams_imageId);
    sprintf(localVarToReplace_imageId, "{%s}", "imageId");

    localVarPath = strReplace(localVarPath, localVarToReplace_imageId, imageId);

    // Path Params
    long sizeOfPathParams_name = strlen(projectId)+3 + strlen(type)+3 + strlen(imageId)+3 + strlen(name)+3 + sizeof("{ name }") - 1;
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



    // header parameters
    char *keyHeader_x_corellium_image_encoding = NULL;
    char * valueHeader_x_corellium_image_encoding = 0;
    keyValuePair_t *keyPairHeader_x_corellium_image_encoding = 0;
    if (x_corellium_image_encoding) {
        keyHeader_x_corellium_image_encoding = strdup("x-corellium-image-encoding");
        valueHeader_x_corellium_image_encoding = strdup((x_corellium_image_encoding));
        keyPairHeader_x_corellium_image_encoding = keyValuePair_create(keyHeader_x_corellium_image_encoding, valueHeader_x_corellium_image_encoding);
        list_addElement(localVarHeaderParameters,keyPairHeader_x_corellium_image_encoding);
    }


    // header parameters
    char *keyHeader_x_corellium_image_encapsulated = NULL;
    int valueHeader_x_corellium_image_encapsulated = 0;
    keyValuePair_t *keyPairHeader_x_corellium_image_encapsulated = 0;
    if (x_corellium_image_encapsulated) {
        keyHeader_x_corellium_image_encapsulated = strdup("x-corellium-image-encapsulated");
        valueHeader_x_corellium_image_encapsulated = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueHeader_x_corellium_image_encapsulated, MAX_NUMBER_LENGTH, "%d", *x_corellium_image_encapsulated);
        keyPairHeader_x_corellium_image_encapsulated = keyValuePair_create(keyHeader_x_corellium_image_encapsulated, &valueHeader_x_corellium_image_encapsulated);
        list_addElement(localVarHeaderParameters,keyPairHeader_x_corellium_image_encapsulated);
    }


    // header parameters
    char *keyHeader_x_corellium_total_file_size = NULL;
    double valueHeader_x_corellium_total_file_size = 0;
    keyValuePair_t *keyPairHeader_x_corellium_total_file_size = 0;
    if (x_corellium_total_file_size) {
        keyHeader_x_corellium_total_file_size = strdup("x-corellium-total-file-size");
        valueHeader_x_corellium_total_file_size = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueHeader_x_corellium_total_file_size, MAX_NUMBER_LENGTH, "%d", *x_corellium_total_file_size);
        keyPairHeader_x_corellium_total_file_size = keyValuePair_create(keyHeader_x_corellium_total_file_size, &valueHeader_x_corellium_total_file_size);
        list_addElement(localVarHeaderParameters,keyPairHeader_x_corellium_total_file_size);
    }


    // header parameters
    char *keyHeader_x_corellium_image_password = NULL;
    char * valueHeader_x_corellium_image_password = 0;
    keyValuePair_t *keyPairHeader_x_corellium_image_password = 0;
    if (x_corellium_image_password) {
        keyHeader_x_corellium_image_password = strdup("x-corellium-image-password");
        valueHeader_x_corellium_image_password = strdup((x_corellium_image_password));
        keyPairHeader_x_corellium_image_password = keyValuePair_create(keyHeader_x_corellium_image_password, valueHeader_x_corellium_image_password);
        list_addElement(localVarHeaderParameters,keyPairHeader_x_corellium_image_password);
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

    // query parameters
    char *keyQuery_flavor = NULL;
    char * valueQuery_flavor = NULL;
    keyValuePair_t *keyPairQuery_flavor = 0;
    if (flavor)
    {
        keyQuery_flavor = strdup("flavor");
        valueQuery_flavor = strdup((flavor));
        keyPairQuery_flavor = keyValuePair_create(keyQuery_flavor, valueQuery_flavor);
        list_addElement(localVarQueryParameters,keyPairQuery_flavor);
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
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Chunk accepted. The body is an empty JSON object.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid chunk or upload parameters, unreadable body, or a missing/mismatched corelliumChecksum for a firmware upload.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Authentication required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Permission denied.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","No image with the given identifier.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 507) {
    //    printf("%s\n","The image pool does not have enough space for this upload.");
    //}
    //nonprimitive not container
    object_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ProjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = object_parseFromJSON(ProjectsAPIlocalVarJSON);
        cJSON_Delete(ProjectsAPIlocalVarJSON);
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
    list_freeList(localVarHeaderParameters);
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_projectId);
    free(localVarToReplace_type);
    free(localVarToReplace_imageId);
    free(localVarToReplace_name);
    if (keyHeader_x_corellium_image_encoding) {
        free(keyHeader_x_corellium_image_encoding);
        keyHeader_x_corellium_image_encoding = NULL;
    }
    if (valueHeader_x_corellium_image_encoding) {
        free(valueHeader_x_corellium_image_encoding);
        valueHeader_x_corellium_image_encoding = NULL;
    }
    free(keyPairHeader_x_corellium_image_encoding);
    if (keyHeader_x_corellium_image_encapsulated) {
        free(keyHeader_x_corellium_image_encapsulated);
        keyHeader_x_corellium_image_encapsulated = NULL;
    }
    free(keyPairHeader_x_corellium_image_encapsulated);
    if (keyHeader_x_corellium_total_file_size) {
        free(keyHeader_x_corellium_total_file_size);
        keyHeader_x_corellium_total_file_size = NULL;
    }
    free(keyPairHeader_x_corellium_total_file_size);
    if (keyHeader_x_corellium_image_password) {
        free(keyHeader_x_corellium_image_password);
        keyHeader_x_corellium_image_password = NULL;
    }
    if (valueHeader_x_corellium_image_password) {
        free(valueHeader_x_corellium_image_password);
        valueHeader_x_corellium_image_password = NULL;
    }
    free(keyPairHeader_x_corellium_image_password);
    free(localVarBodyParameters);
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
    if(keyQuery_resumableTotalSize){
        free(keyQuery_resumableTotalSize);
        keyQuery_resumableTotalSize = NULL;
    }
    if(valueQuery_resumableTotalSize){
        free(valueQuery_resumableTotalSize);
        valueQuery_resumableTotalSize = NULL;
    }
    if(keyPairQuery_resumableTotalSize){
        keyValuePair_free(keyPairQuery_resumableTotalSize);
        keyPairQuery_resumableTotalSize = NULL;
    }
    if(keyQuery_resumableTotalChunks){
        free(keyQuery_resumableTotalChunks);
        keyQuery_resumableTotalChunks = NULL;
    }
    if(valueQuery_resumableTotalChunks){
        free(valueQuery_resumableTotalChunks);
        valueQuery_resumableTotalChunks = NULL;
    }
    if(keyPairQuery_resumableTotalChunks){
        keyValuePair_free(keyPairQuery_resumableTotalChunks);
        keyPairQuery_resumableTotalChunks = NULL;
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
    if(keyQuery_flavor){
        free(keyQuery_flavor);
        keyQuery_flavor = NULL;
    }
    if(valueQuery_flavor){
        free(valueQuery_flavor);
        valueQuery_flavor = NULL;
    }
    if(keyPairQuery_flavor){
        keyValuePair_free(keyPairQuery_flavor);
        keyPairQuery_flavor = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

