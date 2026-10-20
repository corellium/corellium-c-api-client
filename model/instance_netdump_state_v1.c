#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "instance_netdump_state_v1.h"



static instance_netdump_state_v1_t *instance_netdump_state_v1_create_internal(
    char *hash,
    char *info,
    int enabled
    ) {
    instance_netdump_state_v1_t *instance_netdump_state_v1_local_var = malloc(sizeof(instance_netdump_state_v1_t));
    if (!instance_netdump_state_v1_local_var) {
        return NULL;
    }
    instance_netdump_state_v1_local_var->hash = hash;
    instance_netdump_state_v1_local_var->info = info;
    instance_netdump_state_v1_local_var->enabled = enabled;

    instance_netdump_state_v1_local_var->_library_owned = 1;
    return instance_netdump_state_v1_local_var;
}

__attribute__((deprecated)) instance_netdump_state_v1_t *instance_netdump_state_v1_create(
    char *hash,
    char *info,
    int enabled
    ) {
    return instance_netdump_state_v1_create_internal (
        hash,
        info,
        enabled
        );
}

void instance_netdump_state_v1_free(instance_netdump_state_v1_t *instance_netdump_state_v1) {
    if(NULL == instance_netdump_state_v1){
        return ;
    }
    if(instance_netdump_state_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "instance_netdump_state_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (instance_netdump_state_v1->hash) {
        free(instance_netdump_state_v1->hash);
        instance_netdump_state_v1->hash = NULL;
    }
    if (instance_netdump_state_v1->info) {
        free(instance_netdump_state_v1->info);
        instance_netdump_state_v1->info = NULL;
    }
    free(instance_netdump_state_v1);
}

cJSON *instance_netdump_state_v1_convertToJSON(instance_netdump_state_v1_t *instance_netdump_state_v1) {
    cJSON *item = cJSON_CreateObject();

    // instance_netdump_state_v1->hash
    if(instance_netdump_state_v1->hash) {
    if(cJSON_AddStringToObject(item, "hash", instance_netdump_state_v1->hash) == NULL) {
    goto fail; //String
    }
    }


    // instance_netdump_state_v1->info
    if(instance_netdump_state_v1->info) {
    if(cJSON_AddStringToObject(item, "info", instance_netdump_state_v1->info) == NULL) {
    goto fail; //String
    }
    }


    // instance_netdump_state_v1->enabled
    if(instance_netdump_state_v1->enabled) {
    if(cJSON_AddBoolToObject(item, "enabled", instance_netdump_state_v1->enabled) == NULL) {
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

instance_netdump_state_v1_t *instance_netdump_state_v1_parseFromJSON(cJSON *instance_netdump_state_v1JSON){

    instance_netdump_state_v1_t *instance_netdump_state_v1_local_var = NULL;

    // instance_netdump_state_v1->hash
    cJSON *hash = cJSON_GetObjectItemCaseSensitive(instance_netdump_state_v1JSON, "hash");
    if (cJSON_IsNull(hash)) {
        hash = NULL;
    }
    if (hash) { 
    if(!cJSON_IsString(hash) && !cJSON_IsNull(hash))
    {
    goto end; //String
    }
    }

    // instance_netdump_state_v1->info
    cJSON *info = cJSON_GetObjectItemCaseSensitive(instance_netdump_state_v1JSON, "info");
    if (cJSON_IsNull(info)) {
        info = NULL;
    }
    if (info) { 
    if(!cJSON_IsString(info) && !cJSON_IsNull(info))
    {
    goto end; //String
    }
    }

    // instance_netdump_state_v1->enabled
    cJSON *enabled = cJSON_GetObjectItemCaseSensitive(instance_netdump_state_v1JSON, "enabled");
    if (cJSON_IsNull(enabled)) {
        enabled = NULL;
    }
    if (enabled) { 
    if(!cJSON_IsBool(enabled))
    {
    goto end; //Bool
    }
    }


    instance_netdump_state_v1_local_var = instance_netdump_state_v1_create_internal (
        hash && !cJSON_IsNull(hash) ? strdup(hash->valuestring) : NULL,
        info && !cJSON_IsNull(info) ? strdup(info->valuestring) : NULL,
        enabled ? enabled->valueint : 0
        );

    return instance_netdump_state_v1_local_var;
end:
    return NULL;

}
