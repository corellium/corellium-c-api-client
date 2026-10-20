#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cluster_config_coordinator_config_hypertune.h"



static cluster_config_coordinator_config_hypertune_t *cluster_config_coordinator_config_hypertune_create_internal(
    char *token,
    char *branch_name,
    char *init_data_path
    ) {
    cluster_config_coordinator_config_hypertune_t *cluster_config_coordinator_config_hypertune_local_var = malloc(sizeof(cluster_config_coordinator_config_hypertune_t));
    if (!cluster_config_coordinator_config_hypertune_local_var) {
        return NULL;
    }
    cluster_config_coordinator_config_hypertune_local_var->token = token;
    cluster_config_coordinator_config_hypertune_local_var->branch_name = branch_name;
    cluster_config_coordinator_config_hypertune_local_var->init_data_path = init_data_path;

    cluster_config_coordinator_config_hypertune_local_var->_library_owned = 1;
    return cluster_config_coordinator_config_hypertune_local_var;
}

__attribute__((deprecated)) cluster_config_coordinator_config_hypertune_t *cluster_config_coordinator_config_hypertune_create(
    char *token,
    char *branch_name,
    char *init_data_path
    ) {
    return cluster_config_coordinator_config_hypertune_create_internal (
        token,
        branch_name,
        init_data_path
        );
}

void cluster_config_coordinator_config_hypertune_free(cluster_config_coordinator_config_hypertune_t *cluster_config_coordinator_config_hypertune) {
    if(NULL == cluster_config_coordinator_config_hypertune){
        return ;
    }
    if(cluster_config_coordinator_config_hypertune->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cluster_config_coordinator_config_hypertune_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cluster_config_coordinator_config_hypertune->token) {
        free(cluster_config_coordinator_config_hypertune->token);
        cluster_config_coordinator_config_hypertune->token = NULL;
    }
    if (cluster_config_coordinator_config_hypertune->branch_name) {
        free(cluster_config_coordinator_config_hypertune->branch_name);
        cluster_config_coordinator_config_hypertune->branch_name = NULL;
    }
    if (cluster_config_coordinator_config_hypertune->init_data_path) {
        free(cluster_config_coordinator_config_hypertune->init_data_path);
        cluster_config_coordinator_config_hypertune->init_data_path = NULL;
    }
    free(cluster_config_coordinator_config_hypertune);
}

cJSON *cluster_config_coordinator_config_hypertune_convertToJSON(cluster_config_coordinator_config_hypertune_t *cluster_config_coordinator_config_hypertune) {
    cJSON *item = cJSON_CreateObject();

    // cluster_config_coordinator_config_hypertune->token
    if (!cluster_config_coordinator_config_hypertune->token) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "token", cluster_config_coordinator_config_hypertune->token) == NULL) {
    goto fail; //String
    }


    // cluster_config_coordinator_config_hypertune->branch_name
    if(cluster_config_coordinator_config_hypertune->branch_name) {
    if(cJSON_AddStringToObject(item, "branchName", cluster_config_coordinator_config_hypertune->branch_name) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config_coordinator_config_hypertune->init_data_path
    if(cluster_config_coordinator_config_hypertune->init_data_path) {
    if(cJSON_AddStringToObject(item, "initDataPath", cluster_config_coordinator_config_hypertune->init_data_path) == NULL) {
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

cluster_config_coordinator_config_hypertune_t *cluster_config_coordinator_config_hypertune_parseFromJSON(cJSON *cluster_config_coordinator_config_hypertuneJSON){

    cluster_config_coordinator_config_hypertune_t *cluster_config_coordinator_config_hypertune_local_var = NULL;

    // cluster_config_coordinator_config_hypertune->token
    cJSON *token = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_config_hypertuneJSON, "token");
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

    // cluster_config_coordinator_config_hypertune->branch_name
    cJSON *branch_name = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_config_hypertuneJSON, "branchName");
    if (cJSON_IsNull(branch_name)) {
        branch_name = NULL;
    }
    if (branch_name) { 
    if(!cJSON_IsString(branch_name) && !cJSON_IsNull(branch_name))
    {
    goto end; //String
    }
    }

    // cluster_config_coordinator_config_hypertune->init_data_path
    cJSON *init_data_path = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_config_hypertuneJSON, "initDataPath");
    if (cJSON_IsNull(init_data_path)) {
        init_data_path = NULL;
    }
    if (init_data_path) { 
    if(!cJSON_IsString(init_data_path) && !cJSON_IsNull(init_data_path))
    {
    goto end; //String
    }
    }


    cluster_config_coordinator_config_hypertune_local_var = cluster_config_coordinator_config_hypertune_create_internal (
        strdup(token->valuestring),
        branch_name && !cJSON_IsNull(branch_name) ? strdup(branch_name->valuestring) : NULL,
        init_data_path && !cJSON_IsNull(init_data_path) ? strdup(init_data_path->valuestring) : NULL
        );

    return cluster_config_coordinator_config_hypertune_local_var;
end:
    return NULL;

}
