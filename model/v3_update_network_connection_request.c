#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v3_update_network_connection_request.h"



static v3_update_network_connection_request_t *v3_update_network_connection_request_create_internal(
    char *name,
    v3_update_network_connection_request_config_t *config,
    int force
    ) {
    v3_update_network_connection_request_t *v3_update_network_connection_request_local_var = malloc(sizeof(v3_update_network_connection_request_t));
    if (!v3_update_network_connection_request_local_var) {
        return NULL;
    }
    v3_update_network_connection_request_local_var->name = name;
    v3_update_network_connection_request_local_var->config = config;
    v3_update_network_connection_request_local_var->force = force;

    v3_update_network_connection_request_local_var->_library_owned = 1;
    return v3_update_network_connection_request_local_var;
}

__attribute__((deprecated)) v3_update_network_connection_request_t *v3_update_network_connection_request_create(
    char *name,
    v3_update_network_connection_request_config_t *config,
    int force
    ) {
    return v3_update_network_connection_request_create_internal (
        name,
        config,
        force
        );
}

void v3_update_network_connection_request_free(v3_update_network_connection_request_t *v3_update_network_connection_request) {
    if(NULL == v3_update_network_connection_request){
        return ;
    }
    if(v3_update_network_connection_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v3_update_network_connection_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v3_update_network_connection_request->name) {
        free(v3_update_network_connection_request->name);
        v3_update_network_connection_request->name = NULL;
    }
    if (v3_update_network_connection_request->config) {
        v3_update_network_connection_request_config_free(v3_update_network_connection_request->config);
        v3_update_network_connection_request->config = NULL;
    }
    free(v3_update_network_connection_request);
}

cJSON *v3_update_network_connection_request_convertToJSON(v3_update_network_connection_request_t *v3_update_network_connection_request) {
    cJSON *item = cJSON_CreateObject();

    // v3_update_network_connection_request->name
    if (!v3_update_network_connection_request->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v3_update_network_connection_request->name) == NULL) {
    goto fail; //String
    }


    // v3_update_network_connection_request->config
    if(v3_update_network_connection_request->config) {
    cJSON *config_local_JSON = v3_update_network_connection_request_config_convertToJSON(v3_update_network_connection_request->config);
    if(config_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "config", config_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v3_update_network_connection_request->force
    if(v3_update_network_connection_request->force) {
    if(cJSON_AddBoolToObject(item, "force", v3_update_network_connection_request->force) == NULL) {
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

v3_update_network_connection_request_t *v3_update_network_connection_request_parseFromJSON(cJSON *v3_update_network_connection_requestJSON){

    v3_update_network_connection_request_t *v3_update_network_connection_request_local_var = NULL;

    // define the local variable for v3_update_network_connection_request->config
    v3_update_network_connection_request_config_t *config_local_nonprim = NULL;

    // v3_update_network_connection_request->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v3_update_network_connection_requestJSON, "name");
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

    // v3_update_network_connection_request->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(v3_update_network_connection_requestJSON, "config");
    if (cJSON_IsNull(config)) {
        config = NULL;
    }
    if (config) { 
    config_local_nonprim = v3_update_network_connection_request_config_parseFromJSON(config); //nonprimitive
    }

    // v3_update_network_connection_request->force
    cJSON *force = cJSON_GetObjectItemCaseSensitive(v3_update_network_connection_requestJSON, "force");
    if (cJSON_IsNull(force)) {
        force = NULL;
    }
    if (force) { 
    if(!cJSON_IsBool(force))
    {
    goto end; //Bool
    }
    }


    v3_update_network_connection_request_local_var = v3_update_network_connection_request_create_internal (
        strdup(name->valuestring),
        config ? config_local_nonprim : NULL,
        force ? force->valueint : 0
        );

    return v3_update_network_connection_request_local_var;
end:
    if (config_local_nonprim) {
        v3_update_network_connection_request_config_free(config_local_nonprim);
        config_local_nonprim = NULL;
    }
    return NULL;

}
