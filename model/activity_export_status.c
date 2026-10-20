#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "activity_export_status.h"


char* activity_export_status_status_ToString(corellium_api_activity_export_status_STATUS_e status) {
    char* statusArray[] =  { "NULL", "in-progress", "complete", "error", "" };
    return statusArray[status];
}

corellium_api_activity_export_status_STATUS_e activity_export_status_status_FromString(char* status){
    int stringToReturn = 0;
    char *statusArray[] =  { "NULL", "in-progress", "complete", "error", "" };
    size_t sizeofArray = sizeof(statusArray) / sizeof(statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(status, statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static activity_export_status_t *activity_export_status_create_internal(
    corellium_api_activity_export_status_STATUS_e status
    ) {
    activity_export_status_t *activity_export_status_local_var = malloc(sizeof(activity_export_status_t));
    if (!activity_export_status_local_var) {
        return NULL;
    }
    activity_export_status_local_var->status = status;

    activity_export_status_local_var->_library_owned = 1;
    return activity_export_status_local_var;
}

__attribute__((deprecated)) activity_export_status_t *activity_export_status_create(
    corellium_api_activity_export_status_STATUS_e status
    ) {
    return activity_export_status_create_internal (
        status
        );
}

void activity_export_status_free(activity_export_status_t *activity_export_status) {
    if(NULL == activity_export_status){
        return ;
    }
    if(activity_export_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "activity_export_status_free");
        return ;
    }
    listEntry_t *listEntry;
    free(activity_export_status);
}

cJSON *activity_export_status_convertToJSON(activity_export_status_t *activity_export_status) {
    cJSON *item = cJSON_CreateObject();

    // activity_export_status->status
    if(activity_export_status->status != corellium_api_activity_export_status_STATUS_NULL) {
    if(cJSON_AddStringToObject(item, "status", activity_export_status_status_ToString(activity_export_status->status)) == NULL)
    {
    goto fail; //Enum
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

activity_export_status_t *activity_export_status_parseFromJSON(cJSON *activity_export_statusJSON){

    activity_export_status_t *activity_export_status_local_var = NULL;

    // activity_export_status->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(activity_export_statusJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    corellium_api_activity_export_status_STATUS_e statusVariable;
    if (status) { 
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = activity_export_status_status_FromString(status->valuestring);
    }


    activity_export_status_local_var = activity_export_status_create_internal (
        status ? statusVariable : corellium_api_activity_export_status_STATUS_NULL
        );

    return activity_export_status_local_var;
end:
    return NULL;

}
