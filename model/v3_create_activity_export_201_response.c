#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v3_create_activity_export_201_response.h"



static v3_create_activity_export_201_response_t *v3_create_activity_export_201_response_create_internal(
    char *id
    ) {
    v3_create_activity_export_201_response_t *v3_create_activity_export_201_response_local_var = malloc(sizeof(v3_create_activity_export_201_response_t));
    if (!v3_create_activity_export_201_response_local_var) {
        return NULL;
    }
    v3_create_activity_export_201_response_local_var->id = id;

    v3_create_activity_export_201_response_local_var->_library_owned = 1;
    return v3_create_activity_export_201_response_local_var;
}

__attribute__((deprecated)) v3_create_activity_export_201_response_t *v3_create_activity_export_201_response_create(
    char *id
    ) {
    return v3_create_activity_export_201_response_create_internal (
        id
        );
}

void v3_create_activity_export_201_response_free(v3_create_activity_export_201_response_t *v3_create_activity_export_201_response) {
    if(NULL == v3_create_activity_export_201_response){
        return ;
    }
    if(v3_create_activity_export_201_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v3_create_activity_export_201_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v3_create_activity_export_201_response->id) {
        free(v3_create_activity_export_201_response->id);
        v3_create_activity_export_201_response->id = NULL;
    }
    free(v3_create_activity_export_201_response);
}

cJSON *v3_create_activity_export_201_response_convertToJSON(v3_create_activity_export_201_response_t *v3_create_activity_export_201_response) {
    cJSON *item = cJSON_CreateObject();

    // v3_create_activity_export_201_response->id
    if (!v3_create_activity_export_201_response->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", v3_create_activity_export_201_response->id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v3_create_activity_export_201_response_t *v3_create_activity_export_201_response_parseFromJSON(cJSON *v3_create_activity_export_201_responseJSON){

    v3_create_activity_export_201_response_t *v3_create_activity_export_201_response_local_var = NULL;

    // v3_create_activity_export_201_response->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(v3_create_activity_export_201_responseJSON, "id");
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


    v3_create_activity_export_201_response_local_var = v3_create_activity_export_201_response_create_internal (
        strdup(id->valuestring)
        );

    return v3_create_activity_export_201_response_local_var;
end:
    return NULL;

}
