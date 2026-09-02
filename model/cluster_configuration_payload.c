#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cluster_configuration_payload.h"



static cluster_configuration_payload_t *cluster_configuration_payload_create_internal(
    double snapshot_limit,
    coordinator_config_v1_t *coordinator_config,
    ai_tools_config_v1_t *ai_tools_config
    ) {
    cluster_configuration_payload_t *cluster_configuration_payload_local_var = malloc(sizeof(cluster_configuration_payload_t));
    if (!cluster_configuration_payload_local_var) {
        return NULL;
    }
    cluster_configuration_payload_local_var->snapshot_limit = snapshot_limit;
    cluster_configuration_payload_local_var->coordinator_config = coordinator_config;
    cluster_configuration_payload_local_var->ai_tools_config = ai_tools_config;

    cluster_configuration_payload_local_var->_library_owned = 1;
    return cluster_configuration_payload_local_var;
}

__attribute__((deprecated)) cluster_configuration_payload_t *cluster_configuration_payload_create(
    double snapshot_limit,
    coordinator_config_v1_t *coordinator_config,
    ai_tools_config_v1_t *ai_tools_config
    ) {
    return cluster_configuration_payload_create_internal (
        snapshot_limit,
        coordinator_config,
        ai_tools_config
        );
}

void cluster_configuration_payload_free(cluster_configuration_payload_t *cluster_configuration_payload) {
    if(NULL == cluster_configuration_payload){
        return ;
    }
    if(cluster_configuration_payload->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cluster_configuration_payload_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cluster_configuration_payload->coordinator_config) {
        coordinator_config_v1_free(cluster_configuration_payload->coordinator_config);
        cluster_configuration_payload->coordinator_config = NULL;
    }
    if (cluster_configuration_payload->ai_tools_config) {
        ai_tools_config_v1_free(cluster_configuration_payload->ai_tools_config);
        cluster_configuration_payload->ai_tools_config = NULL;
    }
    free(cluster_configuration_payload);
}

cJSON *cluster_configuration_payload_convertToJSON(cluster_configuration_payload_t *cluster_configuration_payload) {
    cJSON *item = cJSON_CreateObject();

    // cluster_configuration_payload->snapshot_limit
    if(cluster_configuration_payload->snapshot_limit) {
    if(cJSON_AddNumberToObject(item, "snapshotLimit", cluster_configuration_payload->snapshot_limit) == NULL) {
    goto fail; //Numeric
    }
    }


    // cluster_configuration_payload->coordinator_config
    if(cluster_configuration_payload->coordinator_config) {
    cJSON *coordinator_config_local_JSON = coordinator_config_v1_convertToJSON(cluster_configuration_payload->coordinator_config);
    if(coordinator_config_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "coordinatorConfig", coordinator_config_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // cluster_configuration_payload->ai_tools_config
    if(cluster_configuration_payload->ai_tools_config) {
    cJSON *ai_tools_config_local_JSON = ai_tools_config_v1_convertToJSON(cluster_configuration_payload->ai_tools_config);
    if(ai_tools_config_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "aiToolsConfig", ai_tools_config_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

cluster_configuration_payload_t *cluster_configuration_payload_parseFromJSON(cJSON *cluster_configuration_payloadJSON){

    cluster_configuration_payload_t *cluster_configuration_payload_local_var = NULL;

    // define the local variable for cluster_configuration_payload->coordinator_config
    coordinator_config_v1_t *coordinator_config_local_nonprim = NULL;

    // define the local variable for cluster_configuration_payload->ai_tools_config
    ai_tools_config_v1_t *ai_tools_config_local_nonprim = NULL;

    // cluster_configuration_payload->snapshot_limit
    cJSON *snapshot_limit = cJSON_GetObjectItemCaseSensitive(cluster_configuration_payloadJSON, "snapshotLimit");
    if (cJSON_IsNull(snapshot_limit)) {
        snapshot_limit = NULL;
    }
    if (snapshot_limit) { 
    if(!cJSON_IsNumber(snapshot_limit))
    {
    goto end; //Numeric
    }
    }

    // cluster_configuration_payload->coordinator_config
    cJSON *coordinator_config = cJSON_GetObjectItemCaseSensitive(cluster_configuration_payloadJSON, "coordinatorConfig");
    if (cJSON_IsNull(coordinator_config)) {
        coordinator_config = NULL;
    }
    if (coordinator_config) { 
    coordinator_config_local_nonprim = coordinator_config_v1_parseFromJSON(coordinator_config); //nonprimitive
    }

    // cluster_configuration_payload->ai_tools_config
    cJSON *ai_tools_config = cJSON_GetObjectItemCaseSensitive(cluster_configuration_payloadJSON, "aiToolsConfig");
    if (cJSON_IsNull(ai_tools_config)) {
        ai_tools_config = NULL;
    }
    if (ai_tools_config) { 
    ai_tools_config_local_nonprim = ai_tools_config_v1_parseFromJSON(ai_tools_config); //nonprimitive
    }


    cluster_configuration_payload_local_var = cluster_configuration_payload_create_internal (
        snapshot_limit ? snapshot_limit->valuedouble : 0,
        coordinator_config ? coordinator_config_local_nonprim : NULL,
        ai_tools_config ? ai_tools_config_local_nonprim : NULL
        );

    return cluster_configuration_payload_local_var;
end:
    if (coordinator_config_local_nonprim) {
        coordinator_config_v1_free(coordinator_config_local_nonprim);
        coordinator_config_local_nonprim = NULL;
    }
    if (ai_tools_config_local_nonprim) {
        ai_tools_config_v1_free(ai_tools_config_local_nonprim);
        ai_tools_config_local_nonprim = NULL;
    }
    return NULL;

}
