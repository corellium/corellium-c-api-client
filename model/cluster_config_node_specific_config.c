#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cluster_config_node_specific_config.h"



static cluster_config_node_specific_config_t *cluster_config_node_specific_config_create_internal(
    char *az,
    char *external_ip,
    char *node_id
    ) {
    cluster_config_node_specific_config_t *cluster_config_node_specific_config_local_var = malloc(sizeof(cluster_config_node_specific_config_t));
    if (!cluster_config_node_specific_config_local_var) {
        return NULL;
    }
    cluster_config_node_specific_config_local_var->az = az;
    cluster_config_node_specific_config_local_var->external_ip = external_ip;
    cluster_config_node_specific_config_local_var->node_id = node_id;

    cluster_config_node_specific_config_local_var->_library_owned = 1;
    return cluster_config_node_specific_config_local_var;
}

__attribute__((deprecated)) cluster_config_node_specific_config_t *cluster_config_node_specific_config_create(
    char *az,
    char *external_ip,
    char *node_id
    ) {
    return cluster_config_node_specific_config_create_internal (
        az,
        external_ip,
        node_id
        );
}

void cluster_config_node_specific_config_free(cluster_config_node_specific_config_t *cluster_config_node_specific_config) {
    if(NULL == cluster_config_node_specific_config){
        return ;
    }
    if(cluster_config_node_specific_config->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cluster_config_node_specific_config_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cluster_config_node_specific_config->az) {
        free(cluster_config_node_specific_config->az);
        cluster_config_node_specific_config->az = NULL;
    }
    if (cluster_config_node_specific_config->external_ip) {
        free(cluster_config_node_specific_config->external_ip);
        cluster_config_node_specific_config->external_ip = NULL;
    }
    if (cluster_config_node_specific_config->node_id) {
        free(cluster_config_node_specific_config->node_id);
        cluster_config_node_specific_config->node_id = NULL;
    }
    free(cluster_config_node_specific_config);
}

cJSON *cluster_config_node_specific_config_convertToJSON(cluster_config_node_specific_config_t *cluster_config_node_specific_config) {
    cJSON *item = cJSON_CreateObject();

    // cluster_config_node_specific_config->az
    if(cluster_config_node_specific_config->az) {
    if(cJSON_AddStringToObject(item, "az", cluster_config_node_specific_config->az) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config_node_specific_config->external_ip
    if(cluster_config_node_specific_config->external_ip) {
    if(cJSON_AddStringToObject(item, "externalIp", cluster_config_node_specific_config->external_ip) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config_node_specific_config->node_id
    if(cluster_config_node_specific_config->node_id) {
    if(cJSON_AddStringToObject(item, "nodeId", cluster_config_node_specific_config->node_id) == NULL) {
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

cluster_config_node_specific_config_t *cluster_config_node_specific_config_parseFromJSON(cJSON *cluster_config_node_specific_configJSON){

    cluster_config_node_specific_config_t *cluster_config_node_specific_config_local_var = NULL;

    // cluster_config_node_specific_config->az
    cJSON *az = cJSON_GetObjectItemCaseSensitive(cluster_config_node_specific_configJSON, "az");
    if (cJSON_IsNull(az)) {
        az = NULL;
    }
    if (az) { 
    if(!cJSON_IsString(az) && !cJSON_IsNull(az))
    {
    goto end; //String
    }
    }

    // cluster_config_node_specific_config->external_ip
    cJSON *external_ip = cJSON_GetObjectItemCaseSensitive(cluster_config_node_specific_configJSON, "externalIp");
    if (cJSON_IsNull(external_ip)) {
        external_ip = NULL;
    }
    if (external_ip) { 
    if(!cJSON_IsString(external_ip) && !cJSON_IsNull(external_ip))
    {
    goto end; //String
    }
    }

    // cluster_config_node_specific_config->node_id
    cJSON *node_id = cJSON_GetObjectItemCaseSensitive(cluster_config_node_specific_configJSON, "nodeId");
    if (cJSON_IsNull(node_id)) {
        node_id = NULL;
    }
    if (node_id) { 
    if(!cJSON_IsString(node_id) && !cJSON_IsNull(node_id))
    {
    goto end; //String
    }
    }


    cluster_config_node_specific_config_local_var = cluster_config_node_specific_config_create_internal (
        az && !cJSON_IsNull(az) ? strdup(az->valuestring) : NULL,
        external_ip && !cJSON_IsNull(external_ip) ? strdup(external_ip->valuestring) : NULL,
        node_id && !cJSON_IsNull(node_id) ? strdup(node_id->valuestring) : NULL
        );

    return cluster_config_node_specific_config_local_var;
end:
    return NULL;

}
