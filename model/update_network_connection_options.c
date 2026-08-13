#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "update_network_connection_options.h"



static update_network_connection_options_t *update_network_connection_options_create_internal(
    char *name,
    object_t *config,
    int force
    ) {
    update_network_connection_options_t *update_network_connection_options_local_var = malloc(sizeof(update_network_connection_options_t));
    if (!update_network_connection_options_local_var) {
        return NULL;
    }
    update_network_connection_options_local_var->name = name;
    update_network_connection_options_local_var->config = config;
    update_network_connection_options_local_var->force = force;

    update_network_connection_options_local_var->_library_owned = 1;
    return update_network_connection_options_local_var;
}

__attribute__((deprecated)) update_network_connection_options_t *update_network_connection_options_create(
    char *name,
    object_t *config,
    int force
    ) {
    return update_network_connection_options_create_internal (
        name,
        config,
        force
        );
}

void update_network_connection_options_free(update_network_connection_options_t *update_network_connection_options) {
    if(NULL == update_network_connection_options){
        return ;
    }
    if(update_network_connection_options->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "update_network_connection_options_free");
        return ;
    }
    listEntry_t *listEntry;
    if (update_network_connection_options->name) {
        free(update_network_connection_options->name);
        update_network_connection_options->name = NULL;
    }
    if (update_network_connection_options->config) {
        object_free(update_network_connection_options->config);
        update_network_connection_options->config = NULL;
    }
    free(update_network_connection_options);
}

cJSON *update_network_connection_options_convertToJSON(update_network_connection_options_t *update_network_connection_options) {
    cJSON *item = cJSON_CreateObject();

    // update_network_connection_options->name
    if (!update_network_connection_options->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", update_network_connection_options->name) == NULL) {
    goto fail; //String
    }


    // update_network_connection_options->config
    if(update_network_connection_options->config) {
    cJSON *config_object = object_convertToJSON(update_network_connection_options->config);
    if(config_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "config", config_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // update_network_connection_options->force
    if(update_network_connection_options->force) {
    if(cJSON_AddBoolToObject(item, "force", update_network_connection_options->force) == NULL) {
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

update_network_connection_options_t *update_network_connection_options_parseFromJSON(cJSON *update_network_connection_optionsJSON){

    update_network_connection_options_t *update_network_connection_options_local_var = NULL;

    // update_network_connection_options->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(update_network_connection_optionsJSON, "name");
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

    // update_network_connection_options->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(update_network_connection_optionsJSON, "config");
    if (cJSON_IsNull(config)) {
        config = NULL;
    }
    object_t *config_local_object = NULL;
    if (config) { 
    config_local_object = object_parseFromJSON(config); //object
    }

    // update_network_connection_options->force
    cJSON *force = cJSON_GetObjectItemCaseSensitive(update_network_connection_optionsJSON, "force");
    if (cJSON_IsNull(force)) {
        force = NULL;
    }
    if (force) { 
    if(!cJSON_IsBool(force))
    {
    goto end; //Bool
    }
    }


    update_network_connection_options_local_var = update_network_connection_options_create_internal (
        strdup(name->valuestring),
        config ? config_local_object : NULL,
        force ? force->valueint : 0
        );

    return update_network_connection_options_local_var;
end:
    return NULL;

}
