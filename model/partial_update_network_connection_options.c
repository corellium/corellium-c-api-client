#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "partial_update_network_connection_options.h"



static partial_update_network_connection_options_t *partial_update_network_connection_options_create_internal(
    char *name,
    update_network_connection_options_config_t *config,
    int force
    ) {
    partial_update_network_connection_options_t *partial_update_network_connection_options_local_var = malloc(sizeof(partial_update_network_connection_options_t));
    if (!partial_update_network_connection_options_local_var) {
        return NULL;
    }
    partial_update_network_connection_options_local_var->name = name;
    partial_update_network_connection_options_local_var->config = config;
    partial_update_network_connection_options_local_var->force = force;

    partial_update_network_connection_options_local_var->_library_owned = 1;
    return partial_update_network_connection_options_local_var;
}

__attribute__((deprecated)) partial_update_network_connection_options_t *partial_update_network_connection_options_create(
    char *name,
    update_network_connection_options_config_t *config,
    int force
    ) {
    return partial_update_network_connection_options_create_internal (
        name,
        config,
        force
        );
}

void partial_update_network_connection_options_free(partial_update_network_connection_options_t *partial_update_network_connection_options) {
    if(NULL == partial_update_network_connection_options){
        return ;
    }
    if(partial_update_network_connection_options->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "partial_update_network_connection_options_free");
        return ;
    }
    listEntry_t *listEntry;
    if (partial_update_network_connection_options->name) {
        free(partial_update_network_connection_options->name);
        partial_update_network_connection_options->name = NULL;
    }
    if (partial_update_network_connection_options->config) {
        update_network_connection_options_config_free(partial_update_network_connection_options->config);
        partial_update_network_connection_options->config = NULL;
    }
    free(partial_update_network_connection_options);
}

cJSON *partial_update_network_connection_options_convertToJSON(partial_update_network_connection_options_t *partial_update_network_connection_options) {
    cJSON *item = cJSON_CreateObject();

    // partial_update_network_connection_options->name
    if(partial_update_network_connection_options->name) {
    if(cJSON_AddStringToObject(item, "name", partial_update_network_connection_options->name) == NULL) {
    goto fail; //String
    }
    }


    // partial_update_network_connection_options->config
    if(partial_update_network_connection_options->config) {
    cJSON *config_local_JSON = update_network_connection_options_config_convertToJSON(partial_update_network_connection_options->config);
    if(config_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "config", config_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // partial_update_network_connection_options->force
    if(partial_update_network_connection_options->force) {
    if(cJSON_AddBoolToObject(item, "force", partial_update_network_connection_options->force) == NULL) {
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

partial_update_network_connection_options_t *partial_update_network_connection_options_parseFromJSON(cJSON *partial_update_network_connection_optionsJSON){

    partial_update_network_connection_options_t *partial_update_network_connection_options_local_var = NULL;

    // define the local variable for partial_update_network_connection_options->config
    update_network_connection_options_config_t *config_local_nonprim = NULL;

    // partial_update_network_connection_options->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(partial_update_network_connection_optionsJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // partial_update_network_connection_options->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(partial_update_network_connection_optionsJSON, "config");
    if (cJSON_IsNull(config)) {
        config = NULL;
    }
    if (config) { 
    config_local_nonprim = update_network_connection_options_config_parseFromJSON(config); //nonprimitive
    }

    // partial_update_network_connection_options->force
    cJSON *force = cJSON_GetObjectItemCaseSensitive(partial_update_network_connection_optionsJSON, "force");
    if (cJSON_IsNull(force)) {
        force = NULL;
    }
    if (force) { 
    if(!cJSON_IsBool(force))
    {
    goto end; //Bool
    }
    }


    partial_update_network_connection_options_local_var = partial_update_network_connection_options_create_internal (
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        config ? config_local_nonprim : NULL,
        force ? force->valueint : 0
        );

    return partial_update_network_connection_options_local_var;
end:
    if (config_local_nonprim) {
        update_network_connection_options_config_free(config_local_nonprim);
        config_local_nonprim = NULL;
    }
    return NULL;

}
