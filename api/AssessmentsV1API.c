#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "AssessmentsV1API.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096


// Create an assessment.
//
// Creates a new MATRIX assessment for the instance. Existing assessments must be complete or failed and the instance must be powered on.
//
assessment_id_status_t*
AssessmentsV1API_v1CreateAssessment(apiClient_t *apiClient, char *instanceId, create_assessment_input_t *create_assessment_input)
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
    char *localVarPath = strdup("/v1/services/matrix/{instanceId}/assessments");

    if(!instanceId)
        goto end;


    // Path Params
    long sizeOfPathParams_instanceId = strlen(instanceId)+3 + sizeof("{ instanceId }") - 1;
    if(instanceId == NULL) {
        goto end;
    }
    char* localVarToReplace_instanceId = malloc(sizeOfPathParams_instanceId);
    sprintf(localVarToReplace_instanceId, "{%s}", "instanceId");

    localVarPath = strReplace(localVarPath, localVarToReplace_instanceId, instanceId);



    // Body Param
    cJSON *localVarSingleItemJSON_create_assessment_input = NULL;
    if (create_assessment_input != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_create_assessment_input = create_assessment_input_convertToJSON(create_assessment_input);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_create_assessment_input);
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
    //    printf("%s\n","The created assessment identifier and status.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid request — for example the instance is powered off, an existing assessment is still in progress, or the assessment is not in the required state for this action.");
    //}
    //nonprimitive not container
    assessment_id_status_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *AssessmentsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = assessment_id_status_parseFromJSON(AssessmentsV1APIlocalVarJSON);
        cJSON_Delete(AssessmentsV1APIlocalVarJSON);
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
    free(localVarToReplace_instanceId);
    if (localVarSingleItemJSON_create_assessment_input) {
        cJSON_Delete(localVarSingleItemJSON_create_assessment_input);
        localVarSingleItemJSON_create_assessment_input = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Create report modifications.
//
// Applies one or more modifications (outcome, severity, or evidence suppression) to a completed assessment report.
//
list_t*
AssessmentsV1API_v1CreateReportModification(apiClient_t *apiClient, char *instanceId, char *assessmentId, list_t *report_modification_input)
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
    char *localVarPath = strdup("/v1/services/matrix/{instanceId}/assessments/{assessmentId}/report-modification");

    if(!instanceId)
        goto end;
    if(!assessmentId)
        goto end;


    // Path Params
    long sizeOfPathParams_instanceId = strlen(instanceId)+3 + strlen(assessmentId)+3 + sizeof("{ instanceId }") - 1;
    if(instanceId == NULL) {
        goto end;
    }
    char* localVarToReplace_instanceId = malloc(sizeOfPathParams_instanceId);
    sprintf(localVarToReplace_instanceId, "{%s}", "instanceId");

    localVarPath = strReplace(localVarPath, localVarToReplace_instanceId, instanceId);

    // Path Params
    long sizeOfPathParams_assessmentId = strlen(instanceId)+3 + strlen(assessmentId)+3 + sizeof("{ assessmentId }") - 1;
    if(assessmentId == NULL) {
        goto end;
    }
    char* localVarToReplace_assessmentId = malloc(sizeOfPathParams_assessmentId);
    sprintf(localVarToReplace_assessmentId, "{%s}", "assessmentId");

    localVarPath = strReplace(localVarPath, localVarToReplace_assessmentId, assessmentId);



    // Body Param
    //notstring
    cJSON *localVar_report_modification_input = NULL;
    cJSON *localVarItemJSON_report_modification_input = NULL;
    cJSON *localVarSingleItemJSON_report_modification_input = NULL;
    if (report_modification_input != NULL)
    {
        localVarItemJSON_report_modification_input = cJSON_CreateObject();
        localVarSingleItemJSON_report_modification_input = cJSON_AddArrayToObject(localVarItemJSON_report_modification_input, "report_modification_input");
        if (localVarSingleItemJSON_report_modification_input == NULL)
        {
            // nonprimitive container

            goto end;
        }
    }

    listEntry_t *report_modification_inputBodyListEntry;
    list_ForEach(report_modification_inputBodyListEntry, report_modification_input)
    {
        localVar_report_modification_input = report_modification_input_convertToJSON(report_modification_inputBodyListEntry->data);
        if(localVar_report_modification_input == NULL)
        {
            goto end;
        }
        cJSON_AddItemToArray(localVarSingleItemJSON_report_modification_input, localVar_report_modification_input);
        localVarBodyParameters = cJSON_Print(localVarItemJSON_report_modification_input);
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
    //    printf("%s\n","The result of each requested modification.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","The assessment is not complete, so its report cannot be modified.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Assessment not found.");
    //}
    list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *AssessmentsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(AssessmentsV1APIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, AssessmentsV1APIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( AssessmentsV1APIlocalVarJSON);
        cJSON_Delete( VarJSON);
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
    free(localVarToReplace_instanceId);
    free(localVarToReplace_assessmentId);
    if (localVarItemJSON_report_modification_input) {
        cJSON_Delete(localVarItemJSON_report_modification_input);
        localVarItemJSON_report_modification_input = NULL;
    }
    if (localVarSingleItemJSON_report_modification_input) {
        cJSON_Delete(localVarSingleItemJSON_report_modification_input);
        localVarSingleItemJSON_report_modification_input = NULL;
    }
    if (localVar_report_modification_input) {
        cJSON_Delete(localVar_report_modification_input);
        localVar_report_modification_input = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Delete an assessment.
//
// Deletes an assessment. The instance must be powered on.
//
void
AssessmentsV1API_v1DeleteAssessment(apiClient_t *apiClient, char *instanceId, char *assessmentId)
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
    char *localVarPath = strdup("/v1/services/matrix/{instanceId}/assessments/{assessmentId}");

    if(!instanceId)
        goto end;
    if(!assessmentId)
        goto end;


    // Path Params
    long sizeOfPathParams_instanceId = strlen(instanceId)+3 + strlen(assessmentId)+3 + sizeof("{ instanceId }") - 1;
    if(instanceId == NULL) {
        goto end;
    }
    char* localVarToReplace_instanceId = malloc(sizeOfPathParams_instanceId);
    sprintf(localVarToReplace_instanceId, "{%s}", "instanceId");

    localVarPath = strReplace(localVarPath, localVarToReplace_instanceId, instanceId);

    // Path Params
    long sizeOfPathParams_assessmentId = strlen(instanceId)+3 + strlen(assessmentId)+3 + sizeof("{ assessmentId }") - 1;
    if(assessmentId == NULL) {
        goto end;
    }
    char* localVarToReplace_assessmentId = malloc(sizeOfPathParams_assessmentId);
    sprintf(localVarToReplace_assessmentId, "{%s}", "assessmentId");

    localVarPath = strReplace(localVarPath, localVarToReplace_assessmentId, assessmentId);


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
    //    printf("%s\n","The assessment was deleted.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid request — for example the instance is powered off, an existing assessment is still in progress, or the assessment is not in the required state for this action.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Assessment not found.");
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
    free(localVarToReplace_instanceId);
    free(localVarToReplace_assessmentId);

}

// Delete report modifications.
//
// Removes one or more previously applied report modifications from a completed assessment.
//
list_t*
AssessmentsV1API_v1DeleteReportModification(apiClient_t *apiClient, char *instanceId, char *assessmentId, list_t *delete_modification_input)
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
    char *localVarPath = strdup("/v1/services/matrix/{instanceId}/assessments/{assessmentId}/report-modification");

    if(!instanceId)
        goto end;
    if(!assessmentId)
        goto end;


    // Path Params
    long sizeOfPathParams_instanceId = strlen(instanceId)+3 + strlen(assessmentId)+3 + sizeof("{ instanceId }") - 1;
    if(instanceId == NULL) {
        goto end;
    }
    char* localVarToReplace_instanceId = malloc(sizeOfPathParams_instanceId);
    sprintf(localVarToReplace_instanceId, "{%s}", "instanceId");

    localVarPath = strReplace(localVarPath, localVarToReplace_instanceId, instanceId);

    // Path Params
    long sizeOfPathParams_assessmentId = strlen(instanceId)+3 + strlen(assessmentId)+3 + sizeof("{ assessmentId }") - 1;
    if(assessmentId == NULL) {
        goto end;
    }
    char* localVarToReplace_assessmentId = malloc(sizeOfPathParams_assessmentId);
    sprintf(localVarToReplace_assessmentId, "{%s}", "assessmentId");

    localVarPath = strReplace(localVarPath, localVarToReplace_assessmentId, assessmentId);



    // Body Param
    //notstring
    cJSON *localVar_delete_modification_input = NULL;
    cJSON *localVarItemJSON_delete_modification_input = NULL;
    cJSON *localVarSingleItemJSON_delete_modification_input = NULL;
    if (delete_modification_input != NULL)
    {
        localVarItemJSON_delete_modification_input = cJSON_CreateObject();
        localVarSingleItemJSON_delete_modification_input = cJSON_AddArrayToObject(localVarItemJSON_delete_modification_input, "delete_modification_input");
        if (localVarSingleItemJSON_delete_modification_input == NULL)
        {
            // nonprimitive container

            goto end;
        }
    }

    listEntry_t *delete_modification_inputBodyListEntry;
    list_ForEach(delete_modification_inputBodyListEntry, delete_modification_input)
    {
        localVar_delete_modification_input = delete_modification_input_convertToJSON(delete_modification_inputBodyListEntry->data);
        if(localVar_delete_modification_input == NULL)
        {
            goto end;
        }
        cJSON_AddItemToArray(localVarSingleItemJSON_delete_modification_input, localVar_delete_modification_input);
        localVarBodyParameters = cJSON_Print(localVarItemJSON_delete_modification_input);
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
                    "DELETE");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","The result of each requested modification removal.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","The assessment is not complete, so its report modifications cannot be removed.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Assessment not found.");
    //}
    list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *AssessmentsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(AssessmentsV1APIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, AssessmentsV1APIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( AssessmentsV1APIlocalVarJSON);
        cJSON_Delete( VarJSON);
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
    free(localVarToReplace_instanceId);
    free(localVarToReplace_assessmentId);
    if (localVarItemJSON_delete_modification_input) {
        cJSON_Delete(localVarItemJSON_delete_modification_input);
        localVarItemJSON_delete_modification_input = NULL;
    }
    if (localVarSingleItemJSON_delete_modification_input) {
        cJSON_Delete(localVarSingleItemJSON_delete_modification_input);
        localVarSingleItemJSON_delete_modification_input = NULL;
    }
    if (localVar_delete_modification_input) {
        cJSON_Delete(localVar_delete_modification_input);
        localVar_delete_modification_input = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Download an assessment report.
//
// Downloads the rendered assessment report. The assessment must be complete and have a generated report.
//
char*
AssessmentsV1API_v1DownloadReport(apiClient_t *apiClient, char *instanceId, char *assessmentId, char *format)
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
    char *localVarPath = strdup("/v1/services/matrix/{instanceId}/assessments/{assessmentId}/download");

    if(!instanceId)
        goto end;
    if(!assessmentId)
        goto end;


    // Path Params
    long sizeOfPathParams_instanceId = strlen(instanceId)+3 + strlen(assessmentId)+3 + sizeof("{ instanceId }") - 1;
    if(instanceId == NULL) {
        goto end;
    }
    char* localVarToReplace_instanceId = malloc(sizeOfPathParams_instanceId);
    sprintf(localVarToReplace_instanceId, "{%s}", "instanceId");

    localVarPath = strReplace(localVarPath, localVarToReplace_instanceId, instanceId);

    // Path Params
    long sizeOfPathParams_assessmentId = strlen(instanceId)+3 + strlen(assessmentId)+3 + sizeof("{ assessmentId }") - 1;
    if(assessmentId == NULL) {
        goto end;
    }
    char* localVarToReplace_assessmentId = malloc(sizeOfPathParams_assessmentId);
    sprintf(localVarToReplace_assessmentId, "{%s}", "assessmentId");

    localVarPath = strReplace(localVarPath, localVarToReplace_assessmentId, assessmentId);



    // query parameters
    char *keyQuery_format = NULL;
    char * valueQuery_format = NULL;
    keyValuePair_t *keyPairQuery_format = 0;
    if (format)
    {
        keyQuery_format = strdup("format");
        valueQuery_format = strdup((format));
        keyPairQuery_format = keyValuePair_create(keyQuery_format, valueQuery_format);
        list_addElement(localVarQueryParameters,keyPairQuery_format);
    }
    list_addElement(localVarHeaderType,"text/html"); //produces
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
    //    printf("%s\n","The rendered report, as HTML or JSON per the requested format.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","The assessment is not complete, so its report cannot be downloaded.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Assessment not found.");
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
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_instanceId);
    free(localVarToReplace_assessmentId);
    if(keyQuery_format){
        free(keyQuery_format);
        keyQuery_format = NULL;
    }
    if(valueQuery_format){
        free(valueQuery_format);
        valueQuery_format = NULL;
    }
    if(keyPairQuery_format){
        keyValuePair_free(keyPairQuery_format);
        keyPairQuery_format = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get an assessment by ID.
//
// Returns the full assessment record.
//
assessment_t*
AssessmentsV1API_v1GetAssessmentById(apiClient_t *apiClient, char *instanceId, char *assessmentId)
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
    char *localVarPath = strdup("/v1/services/matrix/{instanceId}/assessments/{assessmentId}");

    if(!instanceId)
        goto end;
    if(!assessmentId)
        goto end;


    // Path Params
    long sizeOfPathParams_instanceId = strlen(instanceId)+3 + strlen(assessmentId)+3 + sizeof("{ instanceId }") - 1;
    if(instanceId == NULL) {
        goto end;
    }
    char* localVarToReplace_instanceId = malloc(sizeOfPathParams_instanceId);
    sprintf(localVarToReplace_instanceId, "{%s}", "instanceId");

    localVarPath = strReplace(localVarPath, localVarToReplace_instanceId, instanceId);

    // Path Params
    long sizeOfPathParams_assessmentId = strlen(instanceId)+3 + strlen(assessmentId)+3 + sizeof("{ assessmentId }") - 1;
    if(assessmentId == NULL) {
        goto end;
    }
    char* localVarToReplace_assessmentId = malloc(sizeOfPathParams_assessmentId);
    sprintf(localVarToReplace_assessmentId, "{%s}", "assessmentId");

    localVarPath = strReplace(localVarPath, localVarToReplace_assessmentId, assessmentId);


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
    //    printf("%s\n","The requested assessment.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Assessment not found.");
    //}
    //nonprimitive not container
    assessment_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *AssessmentsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = assessment_parseFromJSON(AssessmentsV1APIlocalVarJSON);
        cJSON_Delete(AssessmentsV1APIlocalVarJSON);
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
    free(localVarToReplace_instanceId);
    free(localVarToReplace_assessmentId);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// List assessments for an instance.
//
// Returns a list of assessments for the given instance.
//
list_t*
AssessmentsV1API_v1GetAssessmentsByInstanceId(apiClient_t *apiClient, char *instanceId, char *targetInstanceId)
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
    char *localVarPath = strdup("/v1/services/matrix/{instanceId}/instances/{targetInstanceId}/assessments");

    if(!instanceId)
        goto end;
    if(!targetInstanceId)
        goto end;


    // Path Params
    long sizeOfPathParams_instanceId = strlen(instanceId)+3 + strlen(targetInstanceId)+3 + sizeof("{ instanceId }") - 1;
    if(instanceId == NULL) {
        goto end;
    }
    char* localVarToReplace_instanceId = malloc(sizeOfPathParams_instanceId);
    sprintf(localVarToReplace_instanceId, "{%s}", "instanceId");

    localVarPath = strReplace(localVarPath, localVarToReplace_instanceId, instanceId);

    // Path Params
    long sizeOfPathParams_targetInstanceId = strlen(instanceId)+3 + strlen(targetInstanceId)+3 + sizeof("{ targetInstanceId }") - 1;
    if(targetInstanceId == NULL) {
        goto end;
    }
    char* localVarToReplace_targetInstanceId = malloc(sizeOfPathParams_targetInstanceId);
    sprintf(localVarToReplace_targetInstanceId, "{%s}", "targetInstanceId");

    localVarPath = strReplace(localVarPath, localVarToReplace_targetInstanceId, targetInstanceId);


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
    //    printf("%s\n","A list of assessments for the instance.");
    //}
    list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *AssessmentsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(AssessmentsV1APIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, AssessmentsV1APIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( AssessmentsV1APIlocalVarJSON);
        cJSON_Delete( VarJSON);
    }
    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_instanceId);
    free(localVarToReplace_targetInstanceId);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Update an assessment status.
//
// Updates the lifecycle status of an assessment.
//
assessment_t*
AssessmentsV1API_v1PatchAssessment(apiClient_t *apiClient, char *instanceId, char *assessmentId, update_assessment_input_t *update_assessment_input)
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
    char *localVarPath = strdup("/v1/services/matrix/{instanceId}/assessments/{assessmentId}");

    if(!instanceId)
        goto end;
    if(!assessmentId)
        goto end;


    // Path Params
    long sizeOfPathParams_instanceId = strlen(instanceId)+3 + strlen(assessmentId)+3 + sizeof("{ instanceId }") - 1;
    if(instanceId == NULL) {
        goto end;
    }
    char* localVarToReplace_instanceId = malloc(sizeOfPathParams_instanceId);
    sprintf(localVarToReplace_instanceId, "{%s}", "instanceId");

    localVarPath = strReplace(localVarPath, localVarToReplace_instanceId, instanceId);

    // Path Params
    long sizeOfPathParams_assessmentId = strlen(instanceId)+3 + strlen(assessmentId)+3 + sizeof("{ assessmentId }") - 1;
    if(assessmentId == NULL) {
        goto end;
    }
    char* localVarToReplace_assessmentId = malloc(sizeOfPathParams_assessmentId);
    sprintf(localVarToReplace_assessmentId, "{%s}", "assessmentId");

    localVarPath = strReplace(localVarPath, localVarToReplace_assessmentId, assessmentId);



    // Body Param
    cJSON *localVarSingleItemJSON_update_assessment_input = NULL;
    if (update_assessment_input != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_update_assessment_input = update_assessment_input_convertToJSON(update_assessment_input);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_update_assessment_input);
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
    //    printf("%s\n","The updated assessment.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Assessment not found.");
    //}
    //nonprimitive not container
    assessment_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *AssessmentsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = assessment_parseFromJSON(AssessmentsV1APIlocalVarJSON);
        cJSON_Delete(AssessmentsV1APIlocalVarJSON);
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
    free(localVarToReplace_instanceId);
    free(localVarToReplace_assessmentId);
    if (localVarSingleItemJSON_update_assessment_input) {
        cJSON_Delete(localVarSingleItemJSON_update_assessment_input);
        localVarSingleItemJSON_update_assessment_input = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Run assessment tests.
//
// Executes the MATRIX checks for an assessment. The assessment must have status \"readyForTesting\" and the instance must be powered on.
//
assessment_id_status_t*
AssessmentsV1API_v1RunTests(apiClient_t *apiClient, char *instanceId, char *assessmentId, test_assessment_input_t *test_assessment_input)
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
    char *localVarPath = strdup("/v1/services/matrix/{instanceId}/assessments/{assessmentId}/test");

    if(!instanceId)
        goto end;
    if(!assessmentId)
        goto end;


    // Path Params
    long sizeOfPathParams_instanceId = strlen(instanceId)+3 + strlen(assessmentId)+3 + sizeof("{ instanceId }") - 1;
    if(instanceId == NULL) {
        goto end;
    }
    char* localVarToReplace_instanceId = malloc(sizeOfPathParams_instanceId);
    sprintf(localVarToReplace_instanceId, "{%s}", "instanceId");

    localVarPath = strReplace(localVarPath, localVarToReplace_instanceId, instanceId);

    // Path Params
    long sizeOfPathParams_assessmentId = strlen(instanceId)+3 + strlen(assessmentId)+3 + sizeof("{ assessmentId }") - 1;
    if(assessmentId == NULL) {
        goto end;
    }
    char* localVarToReplace_assessmentId = malloc(sizeOfPathParams_assessmentId);
    sprintf(localVarToReplace_assessmentId, "{%s}", "assessmentId");

    localVarPath = strReplace(localVarPath, localVarToReplace_assessmentId, assessmentId);



    // Body Param
    cJSON *localVarSingleItemJSON_test_assessment_input = NULL;
    if (test_assessment_input != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_test_assessment_input = test_assessment_input_convertToJSON(test_assessment_input);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_test_assessment_input);
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
    //    printf("%s\n","The assessment identifier and its new status.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid request — for example the instance is powered off, an existing assessment is still in progress, or the assessment is not in the required state for this action.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Assessment not found.");
    //}
    //nonprimitive not container
    assessment_id_status_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *AssessmentsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = assessment_id_status_parseFromJSON(AssessmentsV1APIlocalVarJSON);
        cJSON_Delete(AssessmentsV1APIlocalVarJSON);
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
    free(localVarToReplace_instanceId);
    free(localVarToReplace_assessmentId);
    if (localVarSingleItemJSON_test_assessment_input) {
        cJSON_Delete(localVarSingleItemJSON_test_assessment_input);
        localVarSingleItemJSON_test_assessment_input = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Start assessment monitoring.
//
// Begins device monitoring for an assessment. The assessment must have status \"new\" and the instance must be powered on.
//
void
AssessmentsV1API_v1StartMonitoring(apiClient_t *apiClient, char *instanceId, char *assessmentId)
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
    char *localVarPath = strdup("/v1/services/matrix/{instanceId}/assessments/{assessmentId}/start");

    if(!instanceId)
        goto end;
    if(!assessmentId)
        goto end;


    // Path Params
    long sizeOfPathParams_instanceId = strlen(instanceId)+3 + strlen(assessmentId)+3 + sizeof("{ instanceId }") - 1;
    if(instanceId == NULL) {
        goto end;
    }
    char* localVarToReplace_instanceId = malloc(sizeOfPathParams_instanceId);
    sprintf(localVarToReplace_instanceId, "{%s}", "instanceId");

    localVarPath = strReplace(localVarPath, localVarToReplace_instanceId, instanceId);

    // Path Params
    long sizeOfPathParams_assessmentId = strlen(instanceId)+3 + strlen(assessmentId)+3 + sizeof("{ assessmentId }") - 1;
    if(assessmentId == NULL) {
        goto end;
    }
    char* localVarToReplace_assessmentId = malloc(sizeOfPathParams_assessmentId);
    sprintf(localVarToReplace_assessmentId, "{%s}", "assessmentId");

    localVarPath = strReplace(localVarPath, localVarToReplace_assessmentId, assessmentId);


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
    //if (apiClient->response_code == 204) {
    //    printf("%s\n","Monitoring was started.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid request — for example the instance is powered off, an existing assessment is still in progress, or the assessment is not in the required state for this action.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Assessment not found.");
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
    free(localVarToReplace_instanceId);
    free(localVarToReplace_assessmentId);

}

// Stop assessment monitoring.
//
// Stops device monitoring for an assessment. The assessment must have status \"monitoring\" and the instance must be powered on.
//
void
AssessmentsV1API_v1StopMonitoring(apiClient_t *apiClient, char *instanceId, char *assessmentId)
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
    char *localVarPath = strdup("/v1/services/matrix/{instanceId}/assessments/{assessmentId}/stop");

    if(!instanceId)
        goto end;
    if(!assessmentId)
        goto end;


    // Path Params
    long sizeOfPathParams_instanceId = strlen(instanceId)+3 + strlen(assessmentId)+3 + sizeof("{ instanceId }") - 1;
    if(instanceId == NULL) {
        goto end;
    }
    char* localVarToReplace_instanceId = malloc(sizeOfPathParams_instanceId);
    sprintf(localVarToReplace_instanceId, "{%s}", "instanceId");

    localVarPath = strReplace(localVarPath, localVarToReplace_instanceId, instanceId);

    // Path Params
    long sizeOfPathParams_assessmentId = strlen(instanceId)+3 + strlen(assessmentId)+3 + sizeof("{ assessmentId }") - 1;
    if(assessmentId == NULL) {
        goto end;
    }
    char* localVarToReplace_assessmentId = malloc(sizeOfPathParams_assessmentId);
    sprintf(localVarToReplace_assessmentId, "{%s}", "assessmentId");

    localVarPath = strReplace(localVarPath, localVarToReplace_assessmentId, assessmentId);


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
    //if (apiClient->response_code == 204) {
    //    printf("%s\n","Monitoring was stopped.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid request — for example the instance is powered off, an existing assessment is still in progress, or the assessment is not in the required state for this action.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Assessment not found.");
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
    free(localVarToReplace_instanceId);
    free(localVarToReplace_assessmentId);

}

