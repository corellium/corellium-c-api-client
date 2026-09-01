#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "update_network_connection_body.h"



static update_network_connection_body_t *update_network_connection_body_create_internal(
    char *name,
    network_connection_config_t *config,
    int force
    ) {
    update_network_connection_body_t *update_network_connection_body_local_var = malloc(sizeof(update_network_connection_body_t));
    if (!update_network_connection_body_local_var) {
        return NULL;
    }
    update_network_connection_body_local_var->name = name;
    update_network_connection_body_local_var->config = config;
    update_network_connection_body_local_var->force = force;

    update_network_connection_body_local_var->_library_owned = 1;
    return update_network_connection_body_local_var;
}

__attribute__((deprecated)) update_network_connection_body_t *update_network_connection_body_create(
    char *name,
    network_connection_config_t *config,
    int force
    ) {
    return update_network_connection_body_create_internal (
        name,
        config,
        force
        );
}

void update_network_connection_body_free(update_network_connection_body_t *update_network_connection_body) {
    if(NULL == update_network_connection_body){
        return ;
    }
    if(update_network_connection_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "update_network_connection_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (update_network_connection_body->name) {
        free(update_network_connection_body->name);
        update_network_connection_body->name = NULL;
    }
    if (update_network_connection_body->config) {
        network_connection_config_free(update_network_connection_body->config);
        update_network_connection_body->config = NULL;
    }
    free(update_network_connection_body);
}

cJSON *update_network_connection_body_convertToJSON(update_network_connection_body_t *update_network_connection_body) {
    cJSON *item = cJSON_CreateObject();

    // update_network_connection_body->name
    if (!update_network_connection_body->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", update_network_connection_body->name) == NULL) {
    goto fail; //String
    }


    // update_network_connection_body->config
    if(update_network_connection_body->config) {
    cJSON *config_local_JSON = network_connection_config_convertToJSON(update_network_connection_body->config);
    if(config_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "config", config_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // update_network_connection_body->force
    if(update_network_connection_body->force) {
    if(cJSON_AddBoolToObject(item, "force", update_network_connection_body->force) == NULL) {
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

update_network_connection_body_t *update_network_connection_body_parseFromJSON(cJSON *update_network_connection_bodyJSON){

    update_network_connection_body_t *update_network_connection_body_local_var = NULL;

    // define the local variable for update_network_connection_body->config
    network_connection_config_t *config_local_nonprim = NULL;

    // update_network_connection_body->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(update_network_connection_bodyJSON, "name");
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

    // update_network_connection_body->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(update_network_connection_bodyJSON, "config");
    if (cJSON_IsNull(config)) {
        config = NULL;
    }
    if (config) { 
    config_local_nonprim = network_connection_config_parseFromJSON(config); //nonprimitive
    }

    // update_network_connection_body->force
    cJSON *force = cJSON_GetObjectItemCaseSensitive(update_network_connection_bodyJSON, "force");
    if (cJSON_IsNull(force)) {
        force = NULL;
    }
    if (force) { 
    if(!cJSON_IsBool(force))
    {
    goto end; //Bool
    }
    }


    update_network_connection_body_local_var = update_network_connection_body_create_internal (
        strdup(name->valuestring),
        config ? config_local_nonprim : NULL,
        force ? force->valueint : 0
        );

    return update_network_connection_body_local_var;
end:
    if (config_local_nonprim) {
        network_connection_config_free(config_local_nonprim);
        config_local_nonprim = NULL;
    }
    return NULL;

}
