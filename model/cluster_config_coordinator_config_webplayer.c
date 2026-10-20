#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cluster_config_coordinator_config_webplayer.h"



static cluster_config_coordinator_config_webplayer_t *cluster_config_coordinator_config_webplayer_create_internal(
    double inactivity_delete_timeout,
    double inactivity_shutdown_timeout
    ) {
    cluster_config_coordinator_config_webplayer_t *cluster_config_coordinator_config_webplayer_local_var = malloc(sizeof(cluster_config_coordinator_config_webplayer_t));
    if (!cluster_config_coordinator_config_webplayer_local_var) {
        return NULL;
    }
    cluster_config_coordinator_config_webplayer_local_var->inactivity_delete_timeout = inactivity_delete_timeout;
    cluster_config_coordinator_config_webplayer_local_var->inactivity_shutdown_timeout = inactivity_shutdown_timeout;

    cluster_config_coordinator_config_webplayer_local_var->_library_owned = 1;
    return cluster_config_coordinator_config_webplayer_local_var;
}

__attribute__((deprecated)) cluster_config_coordinator_config_webplayer_t *cluster_config_coordinator_config_webplayer_create(
    double inactivity_delete_timeout,
    double inactivity_shutdown_timeout
    ) {
    return cluster_config_coordinator_config_webplayer_create_internal (
        inactivity_delete_timeout,
        inactivity_shutdown_timeout
        );
}

void cluster_config_coordinator_config_webplayer_free(cluster_config_coordinator_config_webplayer_t *cluster_config_coordinator_config_webplayer) {
    if(NULL == cluster_config_coordinator_config_webplayer){
        return ;
    }
    if(cluster_config_coordinator_config_webplayer->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cluster_config_coordinator_config_webplayer_free");
        return ;
    }
    listEntry_t *listEntry;
    free(cluster_config_coordinator_config_webplayer);
}

cJSON *cluster_config_coordinator_config_webplayer_convertToJSON(cluster_config_coordinator_config_webplayer_t *cluster_config_coordinator_config_webplayer) {
    cJSON *item = cJSON_CreateObject();

    // cluster_config_coordinator_config_webplayer->inactivity_delete_timeout
    if (!cluster_config_coordinator_config_webplayer->inactivity_delete_timeout) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "inactivityDeleteTimeout", cluster_config_coordinator_config_webplayer->inactivity_delete_timeout) == NULL) {
    goto fail; //Numeric
    }


    // cluster_config_coordinator_config_webplayer->inactivity_shutdown_timeout
    if (!cluster_config_coordinator_config_webplayer->inactivity_shutdown_timeout) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "inactivityShutdownTimeout", cluster_config_coordinator_config_webplayer->inactivity_shutdown_timeout) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

cluster_config_coordinator_config_webplayer_t *cluster_config_coordinator_config_webplayer_parseFromJSON(cJSON *cluster_config_coordinator_config_webplayerJSON){

    cluster_config_coordinator_config_webplayer_t *cluster_config_coordinator_config_webplayer_local_var = NULL;

    // cluster_config_coordinator_config_webplayer->inactivity_delete_timeout
    cJSON *inactivity_delete_timeout = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_config_webplayerJSON, "inactivityDeleteTimeout");
    if (cJSON_IsNull(inactivity_delete_timeout)) {
        inactivity_delete_timeout = NULL;
    }
    if (!inactivity_delete_timeout) {
        goto end;
    }

    
    if(!cJSON_IsNumber(inactivity_delete_timeout))
    {
    goto end; //Numeric
    }

    // cluster_config_coordinator_config_webplayer->inactivity_shutdown_timeout
    cJSON *inactivity_shutdown_timeout = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_config_webplayerJSON, "inactivityShutdownTimeout");
    if (cJSON_IsNull(inactivity_shutdown_timeout)) {
        inactivity_shutdown_timeout = NULL;
    }
    if (!inactivity_shutdown_timeout) {
        goto end;
    }

    
    if(!cJSON_IsNumber(inactivity_shutdown_timeout))
    {
    goto end; //Numeric
    }


    cluster_config_coordinator_config_webplayer_local_var = cluster_config_coordinator_config_webplayer_create_internal (
        inactivity_delete_timeout->valuedouble,
        inactivity_shutdown_timeout->valuedouble
        );

    return cluster_config_coordinator_config_webplayer_local_var;
end:
    return NULL;

}
