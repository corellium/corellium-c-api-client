#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cluster_config_coordinator_config_ensure_domain_quotas.h"



static cluster_config_coordinator_config_ensure_domain_quotas_t *cluster_config_coordinator_config_ensure_domain_quotas_create_internal(
    double cores
    ) {
    cluster_config_coordinator_config_ensure_domain_quotas_t *cluster_config_coordinator_config_ensure_domain_quotas_local_var = malloc(sizeof(cluster_config_coordinator_config_ensure_domain_quotas_t));
    if (!cluster_config_coordinator_config_ensure_domain_quotas_local_var) {
        return NULL;
    }
    cluster_config_coordinator_config_ensure_domain_quotas_local_var->cores = cores;

    cluster_config_coordinator_config_ensure_domain_quotas_local_var->_library_owned = 1;
    return cluster_config_coordinator_config_ensure_domain_quotas_local_var;
}

__attribute__((deprecated)) cluster_config_coordinator_config_ensure_domain_quotas_t *cluster_config_coordinator_config_ensure_domain_quotas_create(
    double cores
    ) {
    return cluster_config_coordinator_config_ensure_domain_quotas_create_internal (
        cores
        );
}

void cluster_config_coordinator_config_ensure_domain_quotas_free(cluster_config_coordinator_config_ensure_domain_quotas_t *cluster_config_coordinator_config_ensure_domain_quotas) {
    if(NULL == cluster_config_coordinator_config_ensure_domain_quotas){
        return ;
    }
    if(cluster_config_coordinator_config_ensure_domain_quotas->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cluster_config_coordinator_config_ensure_domain_quotas_free");
        return ;
    }
    listEntry_t *listEntry;
    free(cluster_config_coordinator_config_ensure_domain_quotas);
}

cJSON *cluster_config_coordinator_config_ensure_domain_quotas_convertToJSON(cluster_config_coordinator_config_ensure_domain_quotas_t *cluster_config_coordinator_config_ensure_domain_quotas) {
    cJSON *item = cJSON_CreateObject();

    // cluster_config_coordinator_config_ensure_domain_quotas->cores
    if (!cluster_config_coordinator_config_ensure_domain_quotas->cores) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "cores", cluster_config_coordinator_config_ensure_domain_quotas->cores) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

cluster_config_coordinator_config_ensure_domain_quotas_t *cluster_config_coordinator_config_ensure_domain_quotas_parseFromJSON(cJSON *cluster_config_coordinator_config_ensure_domain_quotasJSON){

    cluster_config_coordinator_config_ensure_domain_quotas_t *cluster_config_coordinator_config_ensure_domain_quotas_local_var = NULL;

    // cluster_config_coordinator_config_ensure_domain_quotas->cores
    cJSON *cores = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_config_ensure_domain_quotasJSON, "cores");
    if (cJSON_IsNull(cores)) {
        cores = NULL;
    }
    if (!cores) {
        goto end;
    }

    
    if(!cJSON_IsNumber(cores))
    {
    goto end; //Numeric
    }


    cluster_config_coordinator_config_ensure_domain_quotas_local_var = cluster_config_coordinator_config_ensure_domain_quotas_create_internal (
        cores->valuedouble
        );

    return cluster_config_coordinator_config_ensure_domain_quotas_local_var;
end:
    return NULL;

}
