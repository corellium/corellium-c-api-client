#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v3_get_activity_export_status_200_response.h"


char* v3_get_activity_export_status_200_response_status_ToString(corellium_api_v3_get_activity_export_status_200_response_STATUS_e status) {
    char* statusArray[] =  { "NULL", "in-progress", "complete", "error", "" };
    return statusArray[status];
}

corellium_api_v3_get_activity_export_status_200_response_STATUS_e v3_get_activity_export_status_200_response_status_FromString(char* status){
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

static v3_get_activity_export_status_200_response_t *v3_get_activity_export_status_200_response_create_internal(
    corellium_api_v3_get_activity_export_status_200_response_STATUS_e status
    ) {
    v3_get_activity_export_status_200_response_t *v3_get_activity_export_status_200_response_local_var = malloc(sizeof(v3_get_activity_export_status_200_response_t));
    if (!v3_get_activity_export_status_200_response_local_var) {
        return NULL;
    }
    v3_get_activity_export_status_200_response_local_var->status = status;

    v3_get_activity_export_status_200_response_local_var->_library_owned = 1;
    return v3_get_activity_export_status_200_response_local_var;
}

__attribute__((deprecated)) v3_get_activity_export_status_200_response_t *v3_get_activity_export_status_200_response_create(
    corellium_api_v3_get_activity_export_status_200_response_STATUS_e status
    ) {
    return v3_get_activity_export_status_200_response_create_internal (
        status
        );
}

void v3_get_activity_export_status_200_response_free(v3_get_activity_export_status_200_response_t *v3_get_activity_export_status_200_response) {
    if(NULL == v3_get_activity_export_status_200_response){
        return ;
    }
    if(v3_get_activity_export_status_200_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v3_get_activity_export_status_200_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(v3_get_activity_export_status_200_response);
}

cJSON *v3_get_activity_export_status_200_response_convertToJSON(v3_get_activity_export_status_200_response_t *v3_get_activity_export_status_200_response) {
    cJSON *item = cJSON_CreateObject();

    // v3_get_activity_export_status_200_response->status
    if(v3_get_activity_export_status_200_response->status != corellium_api_v3_get_activity_export_status_200_response_STATUS_NULL) {
    if(cJSON_AddStringToObject(item, "status", v3_get_activity_export_status_200_response_status_ToString(v3_get_activity_export_status_200_response->status)) == NULL)
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

v3_get_activity_export_status_200_response_t *v3_get_activity_export_status_200_response_parseFromJSON(cJSON *v3_get_activity_export_status_200_responseJSON){

    v3_get_activity_export_status_200_response_t *v3_get_activity_export_status_200_response_local_var = NULL;

    // v3_get_activity_export_status_200_response->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v3_get_activity_export_status_200_responseJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    corellium_api_v3_get_activity_export_status_200_response_STATUS_e statusVariable;
    if (status) { 
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = v3_get_activity_export_status_200_response_status_FromString(status->valuestring);
    }


    v3_get_activity_export_status_200_response_local_var = v3_get_activity_export_status_200_response_create_internal (
        status ? statusVariable : corellium_api_v3_get_activity_export_status_200_response_STATUS_NULL
        );

    return v3_get_activity_export_status_200_response_local_var;
end:
    return NULL;

}
