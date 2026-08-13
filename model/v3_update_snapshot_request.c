#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v3_update_snapshot_request.h"



static v3_update_snapshot_request_t *v3_update_snapshot_request_create_internal(
    char *name
    ) {
    v3_update_snapshot_request_t *v3_update_snapshot_request_local_var = malloc(sizeof(v3_update_snapshot_request_t));
    if (!v3_update_snapshot_request_local_var) {
        return NULL;
    }
    v3_update_snapshot_request_local_var->name = name;

    v3_update_snapshot_request_local_var->_library_owned = 1;
    return v3_update_snapshot_request_local_var;
}

__attribute__((deprecated)) v3_update_snapshot_request_t *v3_update_snapshot_request_create(
    char *name
    ) {
    return v3_update_snapshot_request_create_internal (
        name
        );
}

void v3_update_snapshot_request_free(v3_update_snapshot_request_t *v3_update_snapshot_request) {
    if(NULL == v3_update_snapshot_request){
        return ;
    }
    if(v3_update_snapshot_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v3_update_snapshot_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v3_update_snapshot_request->name) {
        free(v3_update_snapshot_request->name);
        v3_update_snapshot_request->name = NULL;
    }
    free(v3_update_snapshot_request);
}

cJSON *v3_update_snapshot_request_convertToJSON(v3_update_snapshot_request_t *v3_update_snapshot_request) {
    cJSON *item = cJSON_CreateObject();

    // v3_update_snapshot_request->name
    if (!v3_update_snapshot_request->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v3_update_snapshot_request->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v3_update_snapshot_request_t *v3_update_snapshot_request_parseFromJSON(cJSON *v3_update_snapshot_requestJSON){

    v3_update_snapshot_request_t *v3_update_snapshot_request_local_var = NULL;

    // v3_update_snapshot_request->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v3_update_snapshot_requestJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }


    v3_update_snapshot_request_local_var = v3_update_snapshot_request_create_internal (
        strdup(name->valuestring)
        );

    return v3_update_snapshot_request_local_var;
end:
    return NULL;

}
