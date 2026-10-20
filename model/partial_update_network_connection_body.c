#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "partial_update_network_connection_body.h"



static partial_update_network_connection_body_t *partial_update_network_connection_body_create_internal(
    char *name,
    network_connection_config_t *config,
    int force
    ) {
    partial_update_network_connection_body_t *partial_update_network_connection_body_local_var = malloc(sizeof(partial_update_network_connection_body_t));
    if (!partial_update_network_connection_body_local_var) {
        return NULL;
    }
    partial_update_network_connection_body_local_var->name = name;
    partial_update_network_connection_body_local_var->config = config;
    partial_update_network_connection_body_local_var->force = force;

    partial_update_network_connection_body_local_var->_library_owned = 1;
    return partial_update_network_connection_body_local_var;
}

__attribute__((deprecated)) partial_update_network_connection_body_t *partial_update_network_connection_body_create(
    char *name,
    network_connection_config_t *config,
    int force
    ) {
    return partial_update_network_connection_body_create_internal (
        name,
        config,
        force
        );
}

void partial_update_network_connection_body_free(partial_update_network_connection_body_t *partial_update_network_connection_body) {
    if(NULL == partial_update_network_connection_body){
        return ;
    }
    if(partial_update_network_connection_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "partial_update_network_connection_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (partial_update_network_connection_body->name) {
        free(partial_update_network_connection_body->name);
        partial_update_network_connection_body->name = NULL;
    }
    if (partial_update_network_connection_body->config) {
        network_connection_config_free(partial_update_network_connection_body->config);
        partial_update_network_connection_body->config = NULL;
    }
    free(partial_update_network_connection_body);
}

cJSON *partial_update_network_connection_body_convertToJSON(partial_update_network_connection_body_t *partial_update_network_connection_body) {
    cJSON *item = cJSON_CreateObject();

    // partial_update_network_connection_body->name
    if(partial_update_network_connection_body->name) {
    if(cJSON_AddStringToObject(item, "name", partial_update_network_connection_body->name) == NULL) {
    goto fail; //String
    }
    }


    // partial_update_network_connection_body->config
    if(partial_update_network_connection_body->config) {
    cJSON *config_local_JSON = network_connection_config_convertToJSON(partial_update_network_connection_body->config);
    if(config_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "config", config_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // partial_update_network_connection_body->force
    if(partial_update_network_connection_body->force) {
    if(cJSON_AddBoolToObject(item, "force", partial_update_network_connection_body->force) == NULL) {
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

partial_update_network_connection_body_t *partial_update_network_connection_body_parseFromJSON(cJSON *partial_update_network_connection_bodyJSON){

    partial_update_network_connection_body_t *partial_update_network_connection_body_local_var = NULL;

    // define the local variable for partial_update_network_connection_body->config
    network_connection_config_t *config_local_nonprim = NULL;

    // partial_update_network_connection_body->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(partial_update_network_connection_bodyJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // partial_update_network_connection_body->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(partial_update_network_connection_bodyJSON, "config");
    if (cJSON_IsNull(config)) {
        config = NULL;
    }
    if (config) { 
    config_local_nonprim = network_connection_config_parseFromJSON(config); //nonprimitive
    }

    // partial_update_network_connection_body->force
    cJSON *force = cJSON_GetObjectItemCaseSensitive(partial_update_network_connection_bodyJSON, "force");
    if (cJSON_IsNull(force)) {
        force = NULL;
    }
    if (force) { 
    if(!cJSON_IsBool(force))
    {
    goto end; //Bool
    }
    }


    partial_update_network_connection_body_local_var = partial_update_network_connection_body_create_internal (
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        config ? config_local_nonprim : NULL,
        force ? force->valueint : 0
        );

    return partial_update_network_connection_body_local_var;
end:
    if (config_local_nonprim) {
        network_connection_config_free(config_local_nonprim);
        config_local_nonprim = NULL;
    }
    return NULL;

}
