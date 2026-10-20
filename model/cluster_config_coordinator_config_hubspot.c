#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cluster_config_coordinator_config_hubspot.h"



static cluster_config_coordinator_config_hubspot_t *cluster_config_coordinator_config_hubspot_create_internal(
    char *access_token,
    char *hubspot_contact_link
    ) {
    cluster_config_coordinator_config_hubspot_t *cluster_config_coordinator_config_hubspot_local_var = malloc(sizeof(cluster_config_coordinator_config_hubspot_t));
    if (!cluster_config_coordinator_config_hubspot_local_var) {
        return NULL;
    }
    cluster_config_coordinator_config_hubspot_local_var->access_token = access_token;
    cluster_config_coordinator_config_hubspot_local_var->hubspot_contact_link = hubspot_contact_link;

    cluster_config_coordinator_config_hubspot_local_var->_library_owned = 1;
    return cluster_config_coordinator_config_hubspot_local_var;
}

__attribute__((deprecated)) cluster_config_coordinator_config_hubspot_t *cluster_config_coordinator_config_hubspot_create(
    char *access_token,
    char *hubspot_contact_link
    ) {
    return cluster_config_coordinator_config_hubspot_create_internal (
        access_token,
        hubspot_contact_link
        );
}

void cluster_config_coordinator_config_hubspot_free(cluster_config_coordinator_config_hubspot_t *cluster_config_coordinator_config_hubspot) {
    if(NULL == cluster_config_coordinator_config_hubspot){
        return ;
    }
    if(cluster_config_coordinator_config_hubspot->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cluster_config_coordinator_config_hubspot_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cluster_config_coordinator_config_hubspot->access_token) {
        free(cluster_config_coordinator_config_hubspot->access_token);
        cluster_config_coordinator_config_hubspot->access_token = NULL;
    }
    if (cluster_config_coordinator_config_hubspot->hubspot_contact_link) {
        free(cluster_config_coordinator_config_hubspot->hubspot_contact_link);
        cluster_config_coordinator_config_hubspot->hubspot_contact_link = NULL;
    }
    free(cluster_config_coordinator_config_hubspot);
}

cJSON *cluster_config_coordinator_config_hubspot_convertToJSON(cluster_config_coordinator_config_hubspot_t *cluster_config_coordinator_config_hubspot) {
    cJSON *item = cJSON_CreateObject();

    // cluster_config_coordinator_config_hubspot->access_token
    if (!cluster_config_coordinator_config_hubspot->access_token) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "accessToken", cluster_config_coordinator_config_hubspot->access_token) == NULL) {
    goto fail; //String
    }


    // cluster_config_coordinator_config_hubspot->hubspot_contact_link
    if (!cluster_config_coordinator_config_hubspot->hubspot_contact_link) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "hubspotContactLink", cluster_config_coordinator_config_hubspot->hubspot_contact_link) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

cluster_config_coordinator_config_hubspot_t *cluster_config_coordinator_config_hubspot_parseFromJSON(cJSON *cluster_config_coordinator_config_hubspotJSON){

    cluster_config_coordinator_config_hubspot_t *cluster_config_coordinator_config_hubspot_local_var = NULL;

    // cluster_config_coordinator_config_hubspot->access_token
    cJSON *access_token = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_config_hubspotJSON, "accessToken");
    if (cJSON_IsNull(access_token)) {
        access_token = NULL;
    }
    if (!access_token) {
        goto end;
    }

    
    if(!cJSON_IsString(access_token))
    {
    goto end; //String
    }

    // cluster_config_coordinator_config_hubspot->hubspot_contact_link
    cJSON *hubspot_contact_link = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_config_hubspotJSON, "hubspotContactLink");
    if (cJSON_IsNull(hubspot_contact_link)) {
        hubspot_contact_link = NULL;
    }
    if (!hubspot_contact_link) {
        goto end;
    }

    
    if(!cJSON_IsString(hubspot_contact_link))
    {
    goto end; //String
    }


    cluster_config_coordinator_config_hubspot_local_var = cluster_config_coordinator_config_hubspot_create_internal (
        strdup(access_token->valuestring),
        strdup(hubspot_contact_link->valuestring)
        );

    return cluster_config_coordinator_config_hubspot_local_var;
end:
    return NULL;

}
