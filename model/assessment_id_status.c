#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "assessment_id_status.h"


char* assessment_id_status_status_ToString(corellium_api_assessment_id_status_STATUS_e status) {
    char* statusArray[] =  { "NULL", "new", "startingMonitoring", "monitoring", "stoppingMonitoring", "readyForTesting", "testing", "complete", "failed" };
    return statusArray[status];
}

corellium_api_assessment_id_status_STATUS_e assessment_id_status_status_FromString(char* status){
    int stringToReturn = 0;
    char *statusArray[] =  { "NULL", "new", "startingMonitoring", "monitoring", "stoppingMonitoring", "readyForTesting", "testing", "complete", "failed" };
    size_t sizeofArray = sizeof(statusArray) / sizeof(statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(status, statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static assessment_id_status_t *assessment_id_status_create_internal(
    char *id,
    corellium_api_assessment_id_status_STATUS_e status
    ) {
    assessment_id_status_t *assessment_id_status_local_var = malloc(sizeof(assessment_id_status_t));
    if (!assessment_id_status_local_var) {
        return NULL;
    }
    assessment_id_status_local_var->id = id;
    assessment_id_status_local_var->status = status;

    assessment_id_status_local_var->_library_owned = 1;
    return assessment_id_status_local_var;
}

__attribute__((deprecated)) assessment_id_status_t *assessment_id_status_create(
    char *id,
    corellium_api_assessment_id_status_STATUS_e status
    ) {
    return assessment_id_status_create_internal (
        id,
        status
        );
}

void assessment_id_status_free(assessment_id_status_t *assessment_id_status) {
    if(NULL == assessment_id_status){
        return ;
    }
    if(assessment_id_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "assessment_id_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (assessment_id_status->id) {
        free(assessment_id_status->id);
        assessment_id_status->id = NULL;
    }
    free(assessment_id_status);
}

cJSON *assessment_id_status_convertToJSON(assessment_id_status_t *assessment_id_status) {
    cJSON *item = cJSON_CreateObject();

    // assessment_id_status->id
    if (!assessment_id_status->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", assessment_id_status->id) == NULL) {
    goto fail; //String
    }


    // assessment_id_status->status
    if (corellium_api_assessment_id_status_STATUS_NULL == assessment_id_status->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", assessment_id_status_status_ToString(assessment_id_status->status)) == NULL)
    {
    goto fail; //Enum
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

assessment_id_status_t *assessment_id_status_parseFromJSON(cJSON *assessment_id_statusJSON){

    assessment_id_status_t *assessment_id_status_local_var = NULL;

    // assessment_id_status->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(assessment_id_statusJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }

    // assessment_id_status->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(assessment_id_statusJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    corellium_api_assessment_id_status_STATUS_e statusVariable;
    
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = assessment_id_status_status_FromString(status->valuestring);


    assessment_id_status_local_var = assessment_id_status_create_internal (
        strdup(id->valuestring),
        statusVariable
        );

    return assessment_id_status_local_var;
end:
    return NULL;

}
