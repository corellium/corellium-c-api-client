#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "report_modification_result.h"


char* report_modification_result_status_ToString(corellium_api_report_modification_result_STATUS_e status) {
    char* statusArray[] =  { "NULL", "inserted", "deleted", "updated", "ignored", "errored" };
    return statusArray[status];
}

corellium_api_report_modification_result_STATUS_e report_modification_result_status_FromString(char* status){
    int stringToReturn = 0;
    char *statusArray[] =  { "NULL", "inserted", "deleted", "updated", "ignored", "errored" };
    size_t sizeofArray = sizeof(statusArray) / sizeof(statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(status, statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static report_modification_result_t *report_modification_result_create_internal(
    char *check_id,
    char *property,
    corellium_api_report_modification_result_STATUS_e status,
    char *error
    ) {
    report_modification_result_t *report_modification_result_local_var = malloc(sizeof(report_modification_result_t));
    if (!report_modification_result_local_var) {
        return NULL;
    }
    report_modification_result_local_var->check_id = check_id;
    report_modification_result_local_var->property = property;
    report_modification_result_local_var->status = status;
    report_modification_result_local_var->error = error;

    report_modification_result_local_var->_library_owned = 1;
    return report_modification_result_local_var;
}

__attribute__((deprecated)) report_modification_result_t *report_modification_result_create(
    char *check_id,
    char *property,
    corellium_api_report_modification_result_STATUS_e status,
    char *error
    ) {
    return report_modification_result_create_internal (
        check_id,
        property,
        status,
        error
        );
}

void report_modification_result_free(report_modification_result_t *report_modification_result) {
    if(NULL == report_modification_result){
        return ;
    }
    if(report_modification_result->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "report_modification_result_free");
        return ;
    }
    listEntry_t *listEntry;
    if (report_modification_result->check_id) {
        free(report_modification_result->check_id);
        report_modification_result->check_id = NULL;
    }
    if (report_modification_result->property) {
        free(report_modification_result->property);
        report_modification_result->property = NULL;
    }
    if (report_modification_result->error) {
        free(report_modification_result->error);
        report_modification_result->error = NULL;
    }
    free(report_modification_result);
}

cJSON *report_modification_result_convertToJSON(report_modification_result_t *report_modification_result) {
    cJSON *item = cJSON_CreateObject();

    // report_modification_result->check_id
    if (!report_modification_result->check_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "checkId", report_modification_result->check_id) == NULL) {
    goto fail; //String
    }


    // report_modification_result->property
    if (!report_modification_result->property) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "property", report_modification_result->property) == NULL) {
    goto fail; //String
    }


    // report_modification_result->status
    if (corellium_api_report_modification_result_STATUS_NULL == report_modification_result->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", report_modification_result_status_ToString(report_modification_result->status)) == NULL)
    {
    goto fail; //Enum
    }


    // report_modification_result->error
    if(report_modification_result->error) {
    if(cJSON_AddStringToObject(item, "error", report_modification_result->error) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

report_modification_result_t *report_modification_result_parseFromJSON(cJSON *report_modification_resultJSON){

    report_modification_result_t *report_modification_result_local_var = NULL;

    // report_modification_result->check_id
    cJSON *check_id = cJSON_GetObjectItemCaseSensitive(report_modification_resultJSON, "checkId");
    if (cJSON_IsNull(check_id)) {
        check_id = NULL;
    }
    if (!check_id) {
        goto end;
    }

    
    if(!cJSON_IsString(check_id))
    {
    goto end; //String
    }

    // report_modification_result->property
    cJSON *property = cJSON_GetObjectItemCaseSensitive(report_modification_resultJSON, "property");
    if (cJSON_IsNull(property)) {
        property = NULL;
    }
    if (!property) {
        goto end;
    }

    
    if(!cJSON_IsString(property))
    {
    goto end; //String
    }

    // report_modification_result->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(report_modification_resultJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    corellium_api_report_modification_result_STATUS_e statusVariable;
    
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = report_modification_result_status_FromString(status->valuestring);

    // report_modification_result->error
    cJSON *error = cJSON_GetObjectItemCaseSensitive(report_modification_resultJSON, "error");
    if (cJSON_IsNull(error)) {
        error = NULL;
    }
    if (error) { 
    if(!cJSON_IsString(error) && !cJSON_IsNull(error))
    {
    goto end; //String
    }
    }


    report_modification_result_local_var = report_modification_result_create_internal (
        strdup(check_id->valuestring),
        strdup(property->valuestring),
        statusVariable,
        error && !cJSON_IsNull(error) ? strdup(error->valuestring) : NULL
        );

    return report_modification_result_local_var;
end:
    return NULL;

}
