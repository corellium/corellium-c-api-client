#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cluster_config_coordinator_config_pipedrive.h"



static cluster_config_coordinator_config_pipedrive_t *cluster_config_coordinator_config_pipedrive_create_internal(
    char *token
    ) {
    cluster_config_coordinator_config_pipedrive_t *cluster_config_coordinator_config_pipedrive_local_var = malloc(sizeof(cluster_config_coordinator_config_pipedrive_t));
    if (!cluster_config_coordinator_config_pipedrive_local_var) {
        return NULL;
    }
    cluster_config_coordinator_config_pipedrive_local_var->token = token;

    cluster_config_coordinator_config_pipedrive_local_var->_library_owned = 1;
    return cluster_config_coordinator_config_pipedrive_local_var;
}

__attribute__((deprecated)) cluster_config_coordinator_config_pipedrive_t *cluster_config_coordinator_config_pipedrive_create(
    char *token
    ) {
    return cluster_config_coordinator_config_pipedrive_create_internal (
        token
        );
}

void cluster_config_coordinator_config_pipedrive_free(cluster_config_coordinator_config_pipedrive_t *cluster_config_coordinator_config_pipedrive) {
    if(NULL == cluster_config_coordinator_config_pipedrive){
        return ;
    }
    if(cluster_config_coordinator_config_pipedrive->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cluster_config_coordinator_config_pipedrive_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cluster_config_coordinator_config_pipedrive->token) {
        free(cluster_config_coordinator_config_pipedrive->token);
        cluster_config_coordinator_config_pipedrive->token = NULL;
    }
    free(cluster_config_coordinator_config_pipedrive);
}

cJSON *cluster_config_coordinator_config_pipedrive_convertToJSON(cluster_config_coordinator_config_pipedrive_t *cluster_config_coordinator_config_pipedrive) {
    cJSON *item = cJSON_CreateObject();

    // cluster_config_coordinator_config_pipedrive->token
    if (!cluster_config_coordinator_config_pipedrive->token) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "token", cluster_config_coordinator_config_pipedrive->token) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

cluster_config_coordinator_config_pipedrive_t *cluster_config_coordinator_config_pipedrive_parseFromJSON(cJSON *cluster_config_coordinator_config_pipedriveJSON){

    cluster_config_coordinator_config_pipedrive_t *cluster_config_coordinator_config_pipedrive_local_var = NULL;

    // cluster_config_coordinator_config_pipedrive->token
    cJSON *token = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_config_pipedriveJSON, "token");
    if (cJSON_IsNull(token)) {
        token = NULL;
    }
    if (!token) {
        goto end;
    }

    
    if(!cJSON_IsString(token))
    {
    goto end; //String
    }


    cluster_config_coordinator_config_pipedrive_local_var = cluster_config_coordinator_config_pipedrive_create_internal (
        strdup(token->valuestring)
        );

    return cluster_config_coordinator_config_pipedrive_local_var;
end:
    return NULL;

}
