#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "instance_agent_state_v1.h"



static instance_agent_state_v1_t *instance_agent_state_v1_create_internal(
    char *hash,
    char *info
    ) {
    instance_agent_state_v1_t *instance_agent_state_v1_local_var = malloc(sizeof(instance_agent_state_v1_t));
    if (!instance_agent_state_v1_local_var) {
        return NULL;
    }
    instance_agent_state_v1_local_var->hash = hash;
    instance_agent_state_v1_local_var->info = info;

    instance_agent_state_v1_local_var->_library_owned = 1;
    return instance_agent_state_v1_local_var;
}

__attribute__((deprecated)) instance_agent_state_v1_t *instance_agent_state_v1_create(
    char *hash,
    char *info
    ) {
    return instance_agent_state_v1_create_internal (
        hash,
        info
        );
}

void instance_agent_state_v1_free(instance_agent_state_v1_t *instance_agent_state_v1) {
    if(NULL == instance_agent_state_v1){
        return ;
    }
    if(instance_agent_state_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "instance_agent_state_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (instance_agent_state_v1->hash) {
        free(instance_agent_state_v1->hash);
        instance_agent_state_v1->hash = NULL;
    }
    if (instance_agent_state_v1->info) {
        free(instance_agent_state_v1->info);
        instance_agent_state_v1->info = NULL;
    }
    free(instance_agent_state_v1);
}

cJSON *instance_agent_state_v1_convertToJSON(instance_agent_state_v1_t *instance_agent_state_v1) {
    cJSON *item = cJSON_CreateObject();

    // instance_agent_state_v1->hash
    if(instance_agent_state_v1->hash) {
    if(cJSON_AddStringToObject(item, "hash", instance_agent_state_v1->hash) == NULL) {
    goto fail; //String
    }
    }


    // instance_agent_state_v1->info
    if(instance_agent_state_v1->info) {
    if(cJSON_AddStringToObject(item, "info", instance_agent_state_v1->info) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

instance_agent_state_v1_t *instance_agent_state_v1_parseFromJSON(cJSON *instance_agent_state_v1JSON){

    instance_agent_state_v1_t *instance_agent_state_v1_local_var = NULL;

    // instance_agent_state_v1->hash
    cJSON *hash = cJSON_GetObjectItemCaseSensitive(instance_agent_state_v1JSON, "hash");
    if (cJSON_IsNull(hash)) {
        hash = NULL;
    }
    if (hash) { 
    if(!cJSON_IsString(hash) && !cJSON_IsNull(hash))
    {
    goto end; //String
    }
    }

    // instance_agent_state_v1->info
    cJSON *info = cJSON_GetObjectItemCaseSensitive(instance_agent_state_v1JSON, "info");
    if (cJSON_IsNull(info)) {
        info = NULL;
    }
    if (info) { 
    if(!cJSON_IsString(info) && !cJSON_IsNull(info))
    {
    goto end; //String
    }
    }


    instance_agent_state_v1_local_var = instance_agent_state_v1_create_internal (
        hash && !cJSON_IsNull(hash) ? strdup(hash->valuestring) : NULL,
        info && !cJSON_IsNull(info) ? strdup(info->valuestring) : NULL
        );

    return instance_agent_state_v1_local_var;
end:
    return NULL;

}
