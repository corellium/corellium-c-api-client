#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cluster_config_coordinator_config_auth_providers_inner.h"



static cluster_config_coordinator_config_auth_providers_inner_t *cluster_config_coordinator_config_auth_providers_inner_create_internal(
    char *provider,
    char *discovery_url,
    char *client_id,
    char *client_secret,
    char *label,
    int invited_only
    ) {
    cluster_config_coordinator_config_auth_providers_inner_t *cluster_config_coordinator_config_auth_providers_inner_local_var = malloc(sizeof(cluster_config_coordinator_config_auth_providers_inner_t));
    if (!cluster_config_coordinator_config_auth_providers_inner_local_var) {
        return NULL;
    }
    cluster_config_coordinator_config_auth_providers_inner_local_var->provider = provider;
    cluster_config_coordinator_config_auth_providers_inner_local_var->discovery_url = discovery_url;
    cluster_config_coordinator_config_auth_providers_inner_local_var->client_id = client_id;
    cluster_config_coordinator_config_auth_providers_inner_local_var->client_secret = client_secret;
    cluster_config_coordinator_config_auth_providers_inner_local_var->label = label;
    cluster_config_coordinator_config_auth_providers_inner_local_var->invited_only = invited_only;

    cluster_config_coordinator_config_auth_providers_inner_local_var->_library_owned = 1;
    return cluster_config_coordinator_config_auth_providers_inner_local_var;
}

__attribute__((deprecated)) cluster_config_coordinator_config_auth_providers_inner_t *cluster_config_coordinator_config_auth_providers_inner_create(
    char *provider,
    char *discovery_url,
    char *client_id,
    char *client_secret,
    char *label,
    int invited_only
    ) {
    return cluster_config_coordinator_config_auth_providers_inner_create_internal (
        provider,
        discovery_url,
        client_id,
        client_secret,
        label,
        invited_only
        );
}

void cluster_config_coordinator_config_auth_providers_inner_free(cluster_config_coordinator_config_auth_providers_inner_t *cluster_config_coordinator_config_auth_providers_inner) {
    if(NULL == cluster_config_coordinator_config_auth_providers_inner){
        return ;
    }
    if(cluster_config_coordinator_config_auth_providers_inner->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cluster_config_coordinator_config_auth_providers_inner_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cluster_config_coordinator_config_auth_providers_inner->provider) {
        free(cluster_config_coordinator_config_auth_providers_inner->provider);
        cluster_config_coordinator_config_auth_providers_inner->provider = NULL;
    }
    if (cluster_config_coordinator_config_auth_providers_inner->discovery_url) {
        free(cluster_config_coordinator_config_auth_providers_inner->discovery_url);
        cluster_config_coordinator_config_auth_providers_inner->discovery_url = NULL;
    }
    if (cluster_config_coordinator_config_auth_providers_inner->client_id) {
        free(cluster_config_coordinator_config_auth_providers_inner->client_id);
        cluster_config_coordinator_config_auth_providers_inner->client_id = NULL;
    }
    if (cluster_config_coordinator_config_auth_providers_inner->client_secret) {
        free(cluster_config_coordinator_config_auth_providers_inner->client_secret);
        cluster_config_coordinator_config_auth_providers_inner->client_secret = NULL;
    }
    if (cluster_config_coordinator_config_auth_providers_inner->label) {
        free(cluster_config_coordinator_config_auth_providers_inner->label);
        cluster_config_coordinator_config_auth_providers_inner->label = NULL;
    }
    free(cluster_config_coordinator_config_auth_providers_inner);
}

cJSON *cluster_config_coordinator_config_auth_providers_inner_convertToJSON(cluster_config_coordinator_config_auth_providers_inner_t *cluster_config_coordinator_config_auth_providers_inner) {
    cJSON *item = cJSON_CreateObject();

    // cluster_config_coordinator_config_auth_providers_inner->provider
    if (!cluster_config_coordinator_config_auth_providers_inner->provider) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "provider", cluster_config_coordinator_config_auth_providers_inner->provider) == NULL) {
    goto fail; //String
    }


    // cluster_config_coordinator_config_auth_providers_inner->discovery_url
    if (!cluster_config_coordinator_config_auth_providers_inner->discovery_url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "discoveryUrl", cluster_config_coordinator_config_auth_providers_inner->discovery_url) == NULL) {
    goto fail; //String
    }


    // cluster_config_coordinator_config_auth_providers_inner->client_id
    if (!cluster_config_coordinator_config_auth_providers_inner->client_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "clientId", cluster_config_coordinator_config_auth_providers_inner->client_id) == NULL) {
    goto fail; //String
    }


    // cluster_config_coordinator_config_auth_providers_inner->client_secret
    if (!cluster_config_coordinator_config_auth_providers_inner->client_secret) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "clientSecret", cluster_config_coordinator_config_auth_providers_inner->client_secret) == NULL) {
    goto fail; //String
    }


    // cluster_config_coordinator_config_auth_providers_inner->label
    if (!cluster_config_coordinator_config_auth_providers_inner->label) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "label", cluster_config_coordinator_config_auth_providers_inner->label) == NULL) {
    goto fail; //String
    }


    // cluster_config_coordinator_config_auth_providers_inner->invited_only
    if (!cluster_config_coordinator_config_auth_providers_inner->invited_only) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "invitedOnly", cluster_config_coordinator_config_auth_providers_inner->invited_only) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

cluster_config_coordinator_config_auth_providers_inner_t *cluster_config_coordinator_config_auth_providers_inner_parseFromJSON(cJSON *cluster_config_coordinator_config_auth_providers_innerJSON){

    cluster_config_coordinator_config_auth_providers_inner_t *cluster_config_coordinator_config_auth_providers_inner_local_var = NULL;

    // cluster_config_coordinator_config_auth_providers_inner->provider
    cJSON *provider = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_config_auth_providers_innerJSON, "provider");
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

    // cluster_config_coordinator_config_auth_providers_inner->discovery_url
    cJSON *discovery_url = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_config_auth_providers_innerJSON, "discoveryUrl");
    if (cJSON_IsNull(discovery_url)) {
        discovery_url = NULL;
    }
    if (!discovery_url) {
        goto end;
    }

    
    if(!cJSON_IsString(discovery_url))
    {
    goto end; //String
    }

    // cluster_config_coordinator_config_auth_providers_inner->client_id
    cJSON *client_id = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_config_auth_providers_innerJSON, "clientId");
    if (cJSON_IsNull(client_id)) {
        client_id = NULL;
    }
    if (!client_id) {
        goto end;
    }

    
    if(!cJSON_IsString(client_id))
    {
    goto end; //String
    }

    // cluster_config_coordinator_config_auth_providers_inner->client_secret
    cJSON *client_secret = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_config_auth_providers_innerJSON, "clientSecret");
    if (cJSON_IsNull(client_secret)) {
        client_secret = NULL;
    }
    if (!client_secret) {
        goto end;
    }

    
    if(!cJSON_IsString(client_secret))
    {
    goto end; //String
    }

    // cluster_config_coordinator_config_auth_providers_inner->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_config_auth_providers_innerJSON, "label");
    if (cJSON_IsNull(label)) {
        label = NULL;
    }
    if (!label) {
        goto end;
    }

    
    if(!cJSON_IsString(label))
    {
    goto end; //String
    }

    // cluster_config_coordinator_config_auth_providers_inner->invited_only
    cJSON *invited_only = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_config_auth_providers_innerJSON, "invitedOnly");
    if (cJSON_IsNull(invited_only)) {
        invited_only = NULL;
    }
    if (!invited_only) {
        goto end;
    }

    
    if(!cJSON_IsBool(invited_only))
    {
    goto end; //Bool
    }


    cluster_config_coordinator_config_auth_providers_inner_local_var = cluster_config_coordinator_config_auth_providers_inner_create_internal (
        strdup(provider->valuestring),
        strdup(discovery_url->valuestring),
        strdup(client_id->valuestring),
        strdup(client_secret->valuestring),
        strdup(label->valuestring),
        invited_only->valueint
        );

    return cluster_config_coordinator_config_auth_providers_inner_local_var;
end:
    return NULL;

}
