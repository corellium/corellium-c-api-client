#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "instance_netdump_state.h"



static instance_netdump_state_t *instance_netdump_state_create_internal(
    char *hash,
    char *info,
    int enabled
    ) {
    instance_netdump_state_t *instance_netdump_state_local_var = malloc(sizeof(instance_netdump_state_t));
    if (!instance_netdump_state_local_var) {
        return NULL;
    }
    instance_netdump_state_local_var->hash = hash;
    instance_netdump_state_local_var->info = info;
    instance_netdump_state_local_var->enabled = enabled;

    instance_netdump_state_local_var->_library_owned = 1;
    return instance_netdump_state_local_var;
}

__attribute__((deprecated)) instance_netdump_state_t *instance_netdump_state_create(
    char *hash,
    char *info,
    int enabled
    ) {
    return instance_netdump_state_create_internal (
        hash,
        info,
        enabled
        );
}

void instance_netdump_state_free(instance_netdump_state_t *instance_netdump_state) {
    if(NULL == instance_netdump_state){
        return ;
    }
    if(instance_netdump_state->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "instance_netdump_state_free");
        return ;
    }
    listEntry_t *listEntry;
    if (instance_netdump_state->hash) {
        free(instance_netdump_state->hash);
        instance_netdump_state->hash = NULL;
    }
    if (instance_netdump_state->info) {
        free(instance_netdump_state->info);
        instance_netdump_state->info = NULL;
    }
    free(instance_netdump_state);
}

cJSON *instance_netdump_state_convertToJSON(instance_netdump_state_t *instance_netdump_state) {
    cJSON *item = cJSON_CreateObject();

    // instance_netdump_state->hash
    if(instance_netdump_state->hash) {
    if(cJSON_AddStringToObject(item, "hash", instance_netdump_state->hash) == NULL) {
    goto fail; //String
    }
    }


    // instance_netdump_state->info
    if(instance_netdump_state->info) {
    if(cJSON_AddStringToObject(item, "info", instance_netdump_state->info) == NULL) {
    goto fail; //String
    }
    }


    // instance_netdump_state->enabled
    if(instance_netdump_state->enabled) {
    if(cJSON_AddBoolToObject(item, "enabled", instance_netdump_state->enabled) == NULL) {
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

instance_netdump_state_t *instance_netdump_state_parseFromJSON(cJSON *instance_netdump_stateJSON){

    instance_netdump_state_t *instance_netdump_state_local_var = NULL;

    // instance_netdump_state->hash
    cJSON *hash = cJSON_GetObjectItemCaseSensitive(instance_netdump_stateJSON, "hash");
    if (cJSON_IsNull(hash)) {
        hash = NULL;
    }
    if (hash) { 
    if(!cJSON_IsString(hash) && !cJSON_IsNull(hash))
    {
    goto end; //String
    }
    }

    // instance_netdump_state->info
    cJSON *info = cJSON_GetObjectItemCaseSensitive(instance_netdump_stateJSON, "info");
    if (cJSON_IsNull(info)) {
        info = NULL;
    }
    if (info) { 
    if(!cJSON_IsString(info) && !cJSON_IsNull(info))
    {
    goto end; //String
    }
    }

    // instance_netdump_state->enabled
    cJSON *enabled = cJSON_GetObjectItemCaseSensitive(instance_netdump_stateJSON, "enabled");
    if (cJSON_IsNull(enabled)) {
        enabled = NULL;
    }
    if (enabled) { 
    if(!cJSON_IsBool(enabled))
    {
    goto end; //Bool
    }
    }


    instance_netdump_state_local_var = instance_netdump_state_create_internal (
        hash && !cJSON_IsNull(hash) ? strdup(hash->valuestring) : NULL,
        info && !cJSON_IsNull(info) ? strdup(info->valuestring) : NULL,
        enabled ? enabled->valueint : 0
        );

    return instance_netdump_state_local_var;
end:
    return NULL;

}
