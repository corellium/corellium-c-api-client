#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "update_assessment_input.h"


char* update_assessment_input_status_ToString(corellium_api_update_assessment_input_STATUS_e status) {
    char* statusArray[] =  { "NULL", "new", "startingMonitoring", "monitoring", "stoppingMonitoring", "readyForTesting", "testing", "complete", "failed" };
    return statusArray[status];
}

corellium_api_update_assessment_input_STATUS_e update_assessment_input_status_FromString(char* status){
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

static update_assessment_input_t *update_assessment_input_create_internal(
    corellium_api_update_assessment_input_STATUS_e status
    ) {
    update_assessment_input_t *update_assessment_input_local_var = malloc(sizeof(update_assessment_input_t));
    if (!update_assessment_input_local_var) {
        return NULL;
    }
    update_assessment_input_local_var->status = status;

    update_assessment_input_local_var->_library_owned = 1;
    return update_assessment_input_local_var;
}

__attribute__((deprecated)) update_assessment_input_t *update_assessment_input_create(
    corellium_api_update_assessment_input_STATUS_e status
    ) {
    return update_assessment_input_create_internal (
        status
        );
}

void update_assessment_input_free(update_assessment_input_t *update_assessment_input) {
    if(NULL == update_assessment_input){
        return ;
    }
    if(update_assessment_input->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "update_assessment_input_free");
        return ;
    }
    listEntry_t *listEntry;
    free(update_assessment_input);
}

cJSON *update_assessment_input_convertToJSON(update_assessment_input_t *update_assessment_input) {
    cJSON *item = cJSON_CreateObject();

    // update_assessment_input->status
    if (corellium_api_update_assessment_input_STATUS_NULL == update_assessment_input->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", update_assessment_input_status_ToString(update_assessment_input->status)) == NULL)
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

update_assessment_input_t *update_assessment_input_parseFromJSON(cJSON *update_assessment_inputJSON){

    update_assessment_input_t *update_assessment_input_local_var = NULL;

    // update_assessment_input->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(update_assessment_inputJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    corellium_api_update_assessment_input_STATUS_e statusVariable;
    
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = update_assessment_input_status_FromString(status->valuestring);


    update_assessment_input_local_var = update_assessment_input_create_internal (
        statusVariable
        );

    return update_assessment_input_local_var;
end:
    return NULL;

}
