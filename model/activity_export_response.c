#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "activity_export_response.h"



static activity_export_response_t *activity_export_response_create_internal(
    char *id
    ) {
    activity_export_response_t *activity_export_response_local_var = malloc(sizeof(activity_export_response_t));
    if (!activity_export_response_local_var) {
        return NULL;
    }
    activity_export_response_local_var->id = id;

    activity_export_response_local_var->_library_owned = 1;
    return activity_export_response_local_var;
}

__attribute__((deprecated)) activity_export_response_t *activity_export_response_create(
    char *id
    ) {
    return activity_export_response_create_internal (
        id
        );
}

void activity_export_response_free(activity_export_response_t *activity_export_response) {
    if(NULL == activity_export_response){
        return ;
    }
    if(activity_export_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "activity_export_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (activity_export_response->id) {
        free(activity_export_response->id);
        activity_export_response->id = NULL;
    }
    free(activity_export_response);
}

cJSON *activity_export_response_convertToJSON(activity_export_response_t *activity_export_response) {
    cJSON *item = cJSON_CreateObject();

    // activity_export_response->id
    if (!activity_export_response->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", activity_export_response->id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

activity_export_response_t *activity_export_response_parseFromJSON(cJSON *activity_export_responseJSON){

    activity_export_response_t *activity_export_response_local_var = NULL;

    // activity_export_response->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(activity_export_responseJSON, "id");
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


    activity_export_response_local_var = activity_export_response_create_internal (
        strdup(id->valuestring)
        );

    return activity_export_response_local_var;
end:
    return NULL;

}
