#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v3_delete_network_connection_request.h"



static v3_delete_network_connection_request_t *v3_delete_network_connection_request_create_internal(
    int force
    ) {
    v3_delete_network_connection_request_t *v3_delete_network_connection_request_local_var = malloc(sizeof(v3_delete_network_connection_request_t));
    if (!v3_delete_network_connection_request_local_var) {
        return NULL;
    }
    v3_delete_network_connection_request_local_var->force = force;

    v3_delete_network_connection_request_local_var->_library_owned = 1;
    return v3_delete_network_connection_request_local_var;
}

__attribute__((deprecated)) v3_delete_network_connection_request_t *v3_delete_network_connection_request_create(
    int force
    ) {
    return v3_delete_network_connection_request_create_internal (
        force
        );
}

void v3_delete_network_connection_request_free(v3_delete_network_connection_request_t *v3_delete_network_connection_request) {
    if(NULL == v3_delete_network_connection_request){
        return ;
    }
    if(v3_delete_network_connection_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v3_delete_network_connection_request_free");
        return ;
    }
    listEntry_t *listEntry;
    free(v3_delete_network_connection_request);
}

cJSON *v3_delete_network_connection_request_convertToJSON(v3_delete_network_connection_request_t *v3_delete_network_connection_request) {
    cJSON *item = cJSON_CreateObject();

    // v3_delete_network_connection_request->force
    if(v3_delete_network_connection_request->force) {
    if(cJSON_AddBoolToObject(item, "force", v3_delete_network_connection_request->force) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v3_delete_network_connection_request_t *v3_delete_network_connection_request_parseFromJSON(cJSON *v3_delete_network_connection_requestJSON){

    v3_delete_network_connection_request_t *v3_delete_network_connection_request_local_var = NULL;

    // v3_delete_network_connection_request->force
    cJSON *force = cJSON_GetObjectItemCaseSensitive(v3_delete_network_connection_requestJSON, "force");
    if (cJSON_IsNull(force)) {
        force = NULL;
    }
    if (force) { 
    if(!cJSON_IsBool(force))
    {
    goto end; //Bool
    }
    }


    v3_delete_network_connection_request_local_var = v3_delete_network_connection_request_create_internal (
        force ? force->valueint : 0
        );

    return v3_delete_network_connection_request_local_var;
end:
    return NULL;

}
