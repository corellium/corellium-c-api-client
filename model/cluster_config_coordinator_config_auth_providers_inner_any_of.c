#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cluster_config_coordinator_config_auth_providers_inner_any_of.h"



static cluster_config_coordinator_config_auth_providers_inner_any_of_t *cluster_config_coordinator_config_auth_providers_inner_any_of_create_internal(
    char *provider
    ) {
    cluster_config_coordinator_config_auth_providers_inner_any_of_t *cluster_config_coordinator_config_auth_providers_inner_any_of_local_var = malloc(sizeof(cluster_config_coordinator_config_auth_providers_inner_any_of_t));
    if (!cluster_config_coordinator_config_auth_providers_inner_any_of_local_var) {
        return NULL;
    }
    cluster_config_coordinator_config_auth_providers_inner_any_of_local_var->provider = provider;

    cluster_config_coordinator_config_auth_providers_inner_any_of_local_var->_library_owned = 1;
    return cluster_config_coordinator_config_auth_providers_inner_any_of_local_var;
}

__attribute__((deprecated)) cluster_config_coordinator_config_auth_providers_inner_any_of_t *cluster_config_coordinator_config_auth_providers_inner_any_of_create(
    char *provider
    ) {
    return cluster_config_coordinator_config_auth_providers_inner_any_of_create_internal (
        provider
        );
}

void cluster_config_coordinator_config_auth_providers_inner_any_of_free(cluster_config_coordinator_config_auth_providers_inner_any_of_t *cluster_config_coordinator_config_auth_providers_inner_any_of) {
    if(NULL == cluster_config_coordinator_config_auth_providers_inner_any_of){
        return ;
    }
    if(cluster_config_coordinator_config_auth_providers_inner_any_of->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cluster_config_coordinator_config_auth_providers_inner_any_of_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cluster_config_coordinator_config_auth_providers_inner_any_of->provider) {
        free(cluster_config_coordinator_config_auth_providers_inner_any_of->provider);
        cluster_config_coordinator_config_auth_providers_inner_any_of->provider = NULL;
    }
    free(cluster_config_coordinator_config_auth_providers_inner_any_of);
}

cJSON *cluster_config_coordinator_config_auth_providers_inner_any_of_convertToJSON(cluster_config_coordinator_config_auth_providers_inner_any_of_t *cluster_config_coordinator_config_auth_providers_inner_any_of) {
    cJSON *item = cJSON_CreateObject();

    // cluster_config_coordinator_config_auth_providers_inner_any_of->provider
    if (!cluster_config_coordinator_config_auth_providers_inner_any_of->provider) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "provider", cluster_config_coordinator_config_auth_providers_inner_any_of->provider) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

cluster_config_coordinator_config_auth_providers_inner_any_of_t *cluster_config_coordinator_config_auth_providers_inner_any_of_parseFromJSON(cJSON *cluster_config_coordinator_config_auth_providers_inner_any_ofJSON){

    cluster_config_coordinator_config_auth_providers_inner_any_of_t *cluster_config_coordinator_config_auth_providers_inner_any_of_local_var = NULL;

    // cluster_config_coordinator_config_auth_providers_inner_any_of->provider
    cJSON *provider = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_config_auth_providers_inner_any_ofJSON, "provider");
    if (cJSON_IsNull(provider)) {
        provider = NULL;
    }
    if (!provider) {
        goto end;
    }

    
    if(!cJSON_IsString(provider))
    {
    goto end; //String
    }


    cluster_config_coordinator_config_auth_providers_inner_any_of_local_var = cluster_config_coordinator_config_auth_providers_inner_any_of_create_internal (
        strdup(provider->valuestring)
        );

    return cluster_config_coordinator_config_auth_providers_inner_any_of_local_var;
end:
    return NULL;

}
