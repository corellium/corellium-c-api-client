#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "AssessmentsAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096


// Create an assessment.
//
// Creates a new assessment for one app on the instance. This is always the first call. It does not start recording anything; it only checks the device and saves the assessment in status `new`.  **Before you call it:** - The instance must be powered on. - The device must be jailbroken (iOS) or rooted (Android), and its model must support MATRIX (`mast: true` in `GET /v3/models`). Otherwise the request is rejected; currently this can come back as a server error rather than a 400, so check these conditions before calling. - The app must already be installed. `bundleId` is the app's identifier (for example `com.android.egg`); the app's name and version are read from the device and stored on the assessment. - Every earlier assessment on this instance must be `complete` or `failed`. Only one assessment can be in progress per instance at a time. - Android: the web interface asks for at least 4 CPU cores and 4 GB of RAM before it offers MATRIX. This API does not check those values, but with too little memory monitoring can fail with an out-of-memory error.  **Optional inputs.** `wordlistId` and `fridaScriptId` point to files you upload beforehand with `POST /v3/images`; see those fields for details.  **Response.** The new assessment's `id` and `status` (`new`). Save the `id`; every later call needs it. Next call: `v3StartMonitoring`.  **How a MATRIX assessment works.** MATRIX tests one installed app for mobile security problems (for example insecure storage, weak crypto, or sensitive data sent over the network). It first records what the app does while you use it, then runs its checks against that recording and the device, and finally produces a report. Call these operations in order:  1. `v3CreateAssessment` with the app's `bundleId`. Status: `new`. 2. `v3StartMonitoring`. Status goes `startingMonitoring`, then `monitoring`. 3. Use the app on the device through the normal display or an automation tool. Exercise the features you care about. Keep the app open. 4. `v3StopMonitoring`. Status goes `stoppingMonitoring`, then `readyForTesting`. 5. `v3RunTests`. Status goes `testing`, then `complete` or `failed`. 6. Poll `v3GetAssessmentById` every few seconds until the status is `complete` or `failed`. Testing can take several minutes. 7. `v3DownloadReport` to get the results as HTML or JSON. 8. Optional: `v3CreateReportModification` to mark findings as not applicable or change their severity.  Steps 2, 4 and 5 return as soon as the work has started. The request succeeding does not mean the step has finished; always wait for the next status before making the next call. If any step ends in `failed`, the assessment cannot continue: delete it and start again.  Create, start monitoring, stop monitoring, run tests, and delete require the instance to be powered on. Get, list, update status, download, and the report-modification calls do not.
//
assessment_id_status_t*
AssessmentsAPI_v3CreateAssessment(apiClient_t *apiClient, char *instanceId, create_assessment_input_t *create_assessment_input)
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
    char *localVarPath = strdup("/v3/services/matrix/{instanceId}/assessments");

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
        cJSON *AssessmentsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = assessment_id_status_parseFromJSON(AssessmentsAPIlocalVarJSON);
        cJSON_Delete(AssessmentsAPIlocalVarJSON);
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
// Adjusts findings in a finished report, for example to record that a failure does not apply to your app. The assessment must have status `complete`. Your changes are stored separately from the original report. Saving them immediately recalculates the assessment's `results` counts and score. The HTML download shows the adjusted findings; the JSON download contains the original report plus a `modifications` array.  Send an array. Each item names a check with `checkId` (as shown in the report) and one `property` to change: - `outcome`: set `value` to `na` to mark the check \"not applicable\", or `fail` to undo that. - `severity`: set `value` to a different severity level for the check. - `evidence_<n>` (for example `evidence_0`): set `suppressed` to `true` to hide the n-th piece of evidence for the check, or `false` to show it again. Do not send `value`.  The response has one entry per item, saying whether it was applied or why it was ignored. To undo a change, use `v3DeleteReportModification`.
//
list_t*
AssessmentsAPI_v3CreateReportModification(apiClient_t *apiClient, char *instanceId, char *assessmentId, list_t *report_modification_input)
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
    char *localVarPath = strdup("/v3/services/matrix/{instanceId}/assessments/{assessmentId}/report-modification");

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
        cJSON *AssessmentsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(AssessmentsAPIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, AssessmentsAPIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( AssessmentsAPIlocalVarJSON);
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
// Permanently deletes an assessment and the data that belongs to it: - the assessment record, - the generated report, - the wordlist file it used (if any), - the monitoring data MATRIX recorded for this app, - temporary MATRIX files on the device.  The Frida script file, if one was used, is **not** deleted; remove it yourself with `DELETE /v3/images/{imageId}` if you no longer need it.  The instance must be powered on, because MATRIX removes its files from the device. Delete a `failed` assessment before creating a new one for the same instance. Unlike most v3 delete endpoints, an unknown `assessmentId` returns 404 rather than 204.
//
void
AssessmentsAPI_v3DeleteAssessment(apiClient_t *apiClient, char *instanceId, char *assessmentId)
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
    char *localVarPath = strdup("/v3/services/matrix/{instanceId}/assessments/{assessmentId}");

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
// Undoes report changes made with `v3CreateReportModification`, so the affected findings return to their original values. The assessment must have status `complete`. Send an array of `{ checkId, property }` items that identify the changes to remove. The response has one entry per item saying whether it was removed.
//
list_t*
AssessmentsAPI_v3DeleteReportModification(apiClient_t *apiClient, char *instanceId, char *assessmentId, list_t *delete_modification_input)
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
    char *localVarPath = strdup("/v3/services/matrix/{instanceId}/assessments/{assessmentId}/report-modification");

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
        cJSON *AssessmentsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        if(!cJSON_IsArray(AssessmentsAPIlocalVarJSON)) {
            return 0;//nonprimitive container
        }
        elementToReturn = list_createList();
        cJSON *VarJSON;
        cJSON_ArrayForEach(VarJSON, AssessmentsAPIlocalVarJSON)
        {
            if(!cJSON_IsObject(VarJSON))
            {
               // return 0;
            }
            char *localVarJSONToChar = cJSON_Print(VarJSON);
            list_addElement(elementToReturn , localVarJSONToChar);
        }

        cJSON_Delete( AssessmentsAPIlocalVarJSON);
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
// Downloads the full report of a finished assessment. The assessment must have status `complete`; otherwise the request fails with 400.  Choose the format with `format`: - `html` (default): a single, self-contained HTML page for people to read. Save it with an `.html` extension and open it in a browser. - `json`: the report data for programs, plus an `activity` array (up to 100 recent events for the assessment) and a `modifications` array listing the changes made with `v3CreateReportModification`. The report data itself is the original, unmodified result; apply the entries in `modifications` yourself if your program needs the adjusted view.  The HTML report applies your modifications when it is generated, so download again after changing findings. The instance does not need to be powered on.
//
char*
AssessmentsAPI_v3DownloadReport(apiClient_t *apiClient, char *instanceId, char *assessmentId, char *format)
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
    char *localVarPath = strdup("/v3/services/matrix/{instanceId}/assessments/{assessmentId}/download");

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
// Returns everything known about one assessment. Use it to: - **Wait for a step to finish.** Poll after `v3StartMonitoring`, `v3StopMonitoring` and `v3RunTests`, and check `status` before making the next call. - **Find out why it failed.** When `status` is `failed`, `error` may contain a short reason. - **Read a summary of the results.** Once `status` is `complete`, `results` holds the pass/fail counts and the MATRIX score, and `reportId` is set. Use `v3DownloadReport` for the full findings.  Returns 404 if no assessment has this ID.
//
assessment_t*
AssessmentsAPI_v3GetAssessmentById(apiClient_t *apiClient, char *instanceId, char *assessmentId)
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
    char *localVarPath = strdup("/v3/services/matrix/{instanceId}/assessments/{assessmentId}");

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
        cJSON *AssessmentsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = assessment_parseFromJSON(AssessmentsAPIlocalVarJSON);
        cJSON_Delete(AssessmentsAPIlocalVarJSON);
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
// Lists the assessments for an instance, one page at a time. Use it to find earlier assessments, check whether one is still running before creating a new one, or build a history view.  **Paging.** Returns at most `limit` assessments (default 100), skipping the first `offset` (default 0). `total` is the number of assessments that match your filters; keep increasing `offset` by `limit` until `offset` is at least `total`.  **Sorting and filtering.** Results are newest first unless you set `sort`. Filters such as `status`, `name` and `createdAt` can be combined; only assessments matching all of them are returned.
//
paginated_assessments_t*
AssessmentsAPI_v3GetAssessmentsByInstanceId(apiClient_t *apiClient, char *instanceId, char *targetInstanceId, double *limit, double *offset, char *sort, char *name, char *version, char *status, char *createdBy, char *wordlist, char *frida, char *corelliumVersion, char *createdAt)
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
    char *localVarPath = strdup("/v3/services/matrix/{instanceId}/instances/{targetInstanceId}/assessments");

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
    char *keyQuery_sort = NULL;
    char * valueQuery_sort = NULL;
    keyValuePair_t *keyPairQuery_sort = 0;
    if (sort)
    {
        keyQuery_sort = strdup("sort");
        valueQuery_sort = strdup((sort));
        keyPairQuery_sort = keyValuePair_create(keyQuery_sort, valueQuery_sort);
        list_addElement(localVarQueryParameters,keyPairQuery_sort);
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
    char *keyQuery_status = NULL;
    char * valueQuery_status = NULL;
    keyValuePair_t *keyPairQuery_status = 0;
    if (status)
    {
        keyQuery_status = strdup("status");
        valueQuery_status = strdup((status));
        keyPairQuery_status = keyValuePair_create(keyQuery_status, valueQuery_status);
        list_addElement(localVarQueryParameters,keyPairQuery_status);
    }

    // query parameters
    char *keyQuery_createdBy = NULL;
    char * valueQuery_createdBy = NULL;
    keyValuePair_t *keyPairQuery_createdBy = 0;
    if (createdBy)
    {
        keyQuery_createdBy = strdup("createdBy");
        valueQuery_createdBy = strdup((createdBy));
        keyPairQuery_createdBy = keyValuePair_create(keyQuery_createdBy, valueQuery_createdBy);
        list_addElement(localVarQueryParameters,keyPairQuery_createdBy);
    }

    // query parameters
    char *keyQuery_wordlist = NULL;
    char * valueQuery_wordlist = NULL;
    keyValuePair_t *keyPairQuery_wordlist = 0;
    if (wordlist)
    {
        keyQuery_wordlist = strdup("wordlist");
        valueQuery_wordlist = strdup((wordlist));
        keyPairQuery_wordlist = keyValuePair_create(keyQuery_wordlist, valueQuery_wordlist);
        list_addElement(localVarQueryParameters,keyPairQuery_wordlist);
    }

    // query parameters
    char *keyQuery_frida = NULL;
    char * valueQuery_frida = NULL;
    keyValuePair_t *keyPairQuery_frida = 0;
    if (frida)
    {
        keyQuery_frida = strdup("frida");
        valueQuery_frida = strdup((frida));
        keyPairQuery_frida = keyValuePair_create(keyQuery_frida, valueQuery_frida);
        list_addElement(localVarQueryParameters,keyPairQuery_frida);
    }

    // query parameters
    char *keyQuery_corelliumVersion = NULL;
    char * valueQuery_corelliumVersion = NULL;
    keyValuePair_t *keyPairQuery_corelliumVersion = 0;
    if (corelliumVersion)
    {
        keyQuery_corelliumVersion = strdup("corelliumVersion");
        valueQuery_corelliumVersion = strdup((corelliumVersion));
        keyPairQuery_corelliumVersion = keyValuePair_create(keyQuery_corelliumVersion, valueQuery_corelliumVersion);
        list_addElement(localVarQueryParameters,keyPairQuery_corelliumVersion);
    }

    // query parameters
    char *keyQuery_createdAt = NULL;
    char * valueQuery_createdAt = NULL;
    keyValuePair_t *keyPairQuery_createdAt = 0;
    if (createdAt)
    {
        keyQuery_createdAt = strdup("createdAt");
        valueQuery_createdAt = strdup((createdAt));
        keyPairQuery_createdAt = keyValuePair_create(keyQuery_createdAt, valueQuery_createdAt);
        list_addElement(localVarQueryParameters,keyPairQuery_createdAt);
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
    //    printf("%s\n","A page of assessments for the instance.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid query parameters.");
    //}
    //nonprimitive not container
    paginated_assessments_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *AssessmentsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = paginated_assessments_parseFromJSON(AssessmentsAPIlocalVarJSON);
        cJSON_Delete(AssessmentsAPIlocalVarJSON);
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
    free(localVarToReplace_instanceId);
    free(localVarToReplace_targetInstanceId);
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
    if(keyQuery_sort){
        free(keyQuery_sort);
        keyQuery_sort = NULL;
    }
    if(valueQuery_sort){
        free(valueQuery_sort);
        valueQuery_sort = NULL;
    }
    if(keyPairQuery_sort){
        keyValuePair_free(keyPairQuery_sort);
        keyPairQuery_sort = NULL;
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
    if(keyQuery_status){
        free(keyQuery_status);
        keyQuery_status = NULL;
    }
    if(valueQuery_status){
        free(valueQuery_status);
        valueQuery_status = NULL;
    }
    if(keyPairQuery_status){
        keyValuePair_free(keyPairQuery_status);
        keyPairQuery_status = NULL;
    }
    if(keyQuery_createdBy){
        free(keyQuery_createdBy);
        keyQuery_createdBy = NULL;
    }
    if(valueQuery_createdBy){
        free(valueQuery_createdBy);
        valueQuery_createdBy = NULL;
    }
    if(keyPairQuery_createdBy){
        keyValuePair_free(keyPairQuery_createdBy);
        keyPairQuery_createdBy = NULL;
    }
    if(keyQuery_wordlist){
        free(keyQuery_wordlist);
        keyQuery_wordlist = NULL;
    }
    if(valueQuery_wordlist){
        free(valueQuery_wordlist);
        valueQuery_wordlist = NULL;
    }
    if(keyPairQuery_wordlist){
        keyValuePair_free(keyPairQuery_wordlist);
        keyPairQuery_wordlist = NULL;
    }
    if(keyQuery_frida){
        free(keyQuery_frida);
        keyQuery_frida = NULL;
    }
    if(valueQuery_frida){
        free(valueQuery_frida);
        valueQuery_frida = NULL;
    }
    if(keyPairQuery_frida){
        keyValuePair_free(keyPairQuery_frida);
        keyPairQuery_frida = NULL;
    }
    if(keyQuery_corelliumVersion){
        free(keyQuery_corelliumVersion);
        keyQuery_corelliumVersion = NULL;
    }
    if(valueQuery_corelliumVersion){
        free(valueQuery_corelliumVersion);
        valueQuery_corelliumVersion = NULL;
    }
    if(keyPairQuery_corelliumVersion){
        keyValuePair_free(keyPairQuery_corelliumVersion);
        keyPairQuery_corelliumVersion = NULL;
    }
    if(keyQuery_createdAt){
        free(keyQuery_createdAt);
        keyQuery_createdAt = NULL;
    }
    if(valueQuery_createdAt){
        free(valueQuery_createdAt);
        valueQuery_createdAt = NULL;
    }
    if(keyPairQuery_createdAt){
        keyValuePair_free(keyPairQuery_createdAt);
        keyPairQuery_createdAt = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Update an assessment status.
//
// Sets the assessment's `status` field directly. **Most clients should never call this.** `v3StartMonitoring`, `v3StopMonitoring` and `v3RunTests` change the status for you and also do the actual work; this call only changes the stored value.  The server does not check that the new status is a valid next step, and changing it does not start or stop any monitoring or testing. Setting a status by hand can leave an assessment claiming to be in a state it is not really in. Returns the updated assessment, or 404 if no assessment has this ID.
//
assessment_t*
AssessmentsAPI_v3PatchAssessment(apiClient_t *apiClient, char *instanceId, char *assessmentId, update_assessment_input_t *update_assessment_input)
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
    char *localVarPath = strdup("/v3/services/matrix/{instanceId}/assessments/{assessmentId}");

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
        cJSON *AssessmentsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = assessment_parseFromJSON(AssessmentsAPIlocalVarJSON);
        cJSON_Delete(AssessmentsAPIlocalVarJSON);
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
// Runs the MATRIX security checks (step 5). Call it once the status is `readyForTesting`. The instance must be powered on and must stay on until testing finishes.  The checks run in the background and can take several minutes. This call returns right away with the status `testing`. Poll `v3GetAssessmentById` until it is `complete` (then call `v3DownloadReport`) or `failed`.  **Running only some checks.** The request body is optional; with no body every applicable check runs. To narrow it down, set `grep` to text or a regular expression. A check runs if the pattern matches its check ID, its group ID or its category ID. For example `masvs-storage` runs every storage check and `masvs-storage-2-android-8` runs one check. Set `invert` to `true` to run every check except the matching ones.
//
assessment_id_status_t*
AssessmentsAPI_v3RunTests(apiClient_t *apiClient, char *instanceId, char *assessmentId, test_assessment_input_t *test_assessment_input)
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
    char *localVarPath = strdup("/v3/services/matrix/{instanceId}/assessments/{assessmentId}/test");

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
        cJSON *AssessmentsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = assessment_id_status_parseFromJSON(AssessmentsAPIlocalVarJSON);
        cJSON_Delete(AssessmentsAPIlocalVarJSON);
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
// Starts recording what the app does (step 2). Call it after `v3CreateAssessment`, when the assessment's status is `new`. The instance must be powered on.  MATRIX attaches to the app in the background, which can take a while. This call returns 204 as soon as that work has started, with the status set to `startingMonitoring`. Poll `v3GetAssessmentById`: - `monitoring`: recording has begun. Now use the app on the device. Go through the features you want tested: sign in, open screens, enter and save data, make network requests. MATRIX can only report on behavior it observed. Keep the app open until you stop monitoring. - `failed`: see `error`. Common causes are too little device RAM and the app failing to launch.  When you have finished using the app, call `v3StopMonitoring`.
//
void
AssessmentsAPI_v3StartMonitoring(apiClient_t *apiClient, char *instanceId, char *assessmentId)
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
    char *localVarPath = strdup("/v3/services/matrix/{instanceId}/assessments/{assessmentId}/start");

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
// Stops recording (step 4). Call it once the status is `monitoring` and you have finished using the app. The instance must be powered on.  MATRIX detaches from the app and saves what it recorded in the background. This call returns 204 as soon as that has started, with the status set to `stoppingMonitoring`. Poll `v3GetAssessmentById` until the status is `readyForTesting`, then call `v3RunTests`. If it becomes `failed`, check `error`.
//
void
AssessmentsAPI_v3StopMonitoring(apiClient_t *apiClient, char *instanceId, char *assessmentId)
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
    char *localVarPath = strdup("/v3/services/matrix/{instanceId}/assessments/{assessmentId}/stop");

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

