#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cluster_config_maintenance.h"



static cluster_config_maintenance_t *cluster_config_maintenance_create_internal(
    char *message,
    char *header
    ) {
    cluster_config_maintenance_t *cluster_config_maintenance_local_var = malloc(sizeof(cluster_config_maintenance_t));
    if (!cluster_config_maintenance_local_var) {
        return NULL;
    }
    cluster_config_maintenance_local_var->message = message;
    cluster_config_maintenance_local_var->header = header;

    cluster_config_maintenance_local_var->_library_owned = 1;
    return cluster_config_maintenance_local_var;
}

__attribute__((deprecated)) cluster_config_maintenance_t *cluster_config_maintenance_create(
    char *message,
    char *header
    ) {
    return cluster_config_maintenance_create_internal (
        message,
        header
        );
}

void cluster_config_maintenance_free(cluster_config_maintenance_t *cluster_config_maintenance) {
    if(NULL == cluster_config_maintenance){
        return ;
    }
    if(cluster_config_maintenance->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cluster_config_maintenance_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cluster_config_maintenance->message) {
        free(cluster_config_maintenance->message);
        cluster_config_maintenance->message = NULL;
    }
    if (cluster_config_maintenance->header) {
        free(cluster_config_maintenance->header);
        cluster_config_maintenance->header = NULL;
    }
    free(cluster_config_maintenance);
}

cJSON *cluster_config_maintenance_convertToJSON(cluster_config_maintenance_t *cluster_config_maintenance) {
    cJSON *item = cJSON_CreateObject();

    // cluster_config_maintenance->message
    if(cluster_config_maintenance->message) {
    if(cJSON_AddStringToObject(item, "message", cluster_config_maintenance->message) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config_maintenance->header
    if(cluster_config_maintenance->header) {
    if(cJSON_AddStringToObject(item, "header", cluster_config_maintenance->header) == NULL) {
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

cluster_config_maintenance_t *cluster_config_maintenance_parseFromJSON(cJSON *cluster_config_maintenanceJSON){

    cluster_config_maintenance_t *cluster_config_maintenance_local_var = NULL;

    // cluster_config_maintenance->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(cluster_config_maintenanceJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (message) { 
    if(!cJSON_IsString(message) && !cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // cluster_config_maintenance->header
    cJSON *header = cJSON_GetObjectItemCaseSensitive(cluster_config_maintenanceJSON, "header");
    if (cJSON_IsNull(header)) {
        header = NULL;
    }
    if (header) { 
    if(!cJSON_IsString(header) && !cJSON_IsNull(header))
    {
    goto end; //String
    }
    }


    cluster_config_maintenance_local_var = cluster_config_maintenance_create_internal (
        message && !cJSON_IsNull(message) ? strdup(message->valuestring) : NULL,
        header && !cJSON_IsNull(header) ? strdup(header->valuestring) : NULL
        );

    return cluster_config_maintenance_local_var;
end:
    return NULL;

}
