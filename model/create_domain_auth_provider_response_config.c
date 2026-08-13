#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_domain_auth_provider_response_config.h"



static create_domain_auth_provider_response_config_t *create_domain_auth_provider_response_config_create_internal(
    char *discovery_url,
    char *client_id,
    char *client_secret,
    int invited_only
    ) {
    create_domain_auth_provider_response_config_t *create_domain_auth_provider_response_config_local_var = malloc(sizeof(create_domain_auth_provider_response_config_t));
    if (!create_domain_auth_provider_response_config_local_var) {
        return NULL;
    }
    create_domain_auth_provider_response_config_local_var->discovery_url = discovery_url;
    create_domain_auth_provider_response_config_local_var->client_id = client_id;
    create_domain_auth_provider_response_config_local_var->client_secret = client_secret;
    create_domain_auth_provider_response_config_local_var->invited_only = invited_only;

    create_domain_auth_provider_response_config_local_var->_library_owned = 1;
    return create_domain_auth_provider_response_config_local_var;
}

__attribute__((deprecated)) create_domain_auth_provider_response_config_t *create_domain_auth_provider_response_config_create(
    char *discovery_url,
    char *client_id,
    char *client_secret,
    int invited_only
    ) {
    return create_domain_auth_provider_response_config_create_internal (
        discovery_url,
        client_id,
        client_secret,
        invited_only
        );
}

void create_domain_auth_provider_response_config_free(create_domain_auth_provider_response_config_t *create_domain_auth_provider_response_config) {
    if(NULL == create_domain_auth_provider_response_config){
        return ;
    }
    if(create_domain_auth_provider_response_config->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "create_domain_auth_provider_response_config_free");
        return ;
    }
    listEntry_t *listEntry;
    if (create_domain_auth_provider_response_config->discovery_url) {
        free(create_domain_auth_provider_response_config->discovery_url);
        create_domain_auth_provider_response_config->discovery_url = NULL;
    }
    if (create_domain_auth_provider_response_config->client_id) {
        free(create_domain_auth_provider_response_config->client_id);
        create_domain_auth_provider_response_config->client_id = NULL;
    }
    if (create_domain_auth_provider_response_config->client_secret) {
        free(create_domain_auth_provider_response_config->client_secret);
        create_domain_auth_provider_response_config->client_secret = NULL;
    }
    free(create_domain_auth_provider_response_config);
}

cJSON *create_domain_auth_provider_response_config_convertToJSON(create_domain_auth_provider_response_config_t *create_domain_auth_provider_response_config) {
    cJSON *item = cJSON_CreateObject();

    // create_domain_auth_provider_response_config->discovery_url
    if (!create_domain_auth_provider_response_config->discovery_url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "discoveryUrl", create_domain_auth_provider_response_config->discovery_url) == NULL) {
    goto fail; //String
    }


    // create_domain_auth_provider_response_config->client_id
    if (!create_domain_auth_provider_response_config->client_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "clientId", create_domain_auth_provider_response_config->client_id) == NULL) {
    goto fail; //String
    }


    // create_domain_auth_provider_response_config->client_secret
    if (!create_domain_auth_provider_response_config->client_secret) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "clientSecret", create_domain_auth_provider_response_config->client_secret) == NULL) {
    goto fail; //String
    }


    // create_domain_auth_provider_response_config->invited_only
    if(create_domain_auth_provider_response_config->invited_only) {
    if(cJSON_AddBoolToObject(item, "invitedOnly", create_domain_auth_provider_response_config->invited_only) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

create_domain_auth_provider_response_config_t *create_domain_auth_provider_response_config_parseFromJSON(cJSON *create_domain_auth_provider_response_configJSON){

    create_domain_auth_provider_response_config_t *create_domain_auth_provider_response_config_local_var = NULL;

    // create_domain_auth_provider_response_config->discovery_url
    cJSON *discovery_url = cJSON_GetObjectItemCaseSensitive(create_domain_auth_provider_response_configJSON, "discoveryUrl");
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

    // create_domain_auth_provider_response_config->client_id
    cJSON *client_id = cJSON_GetObjectItemCaseSensitive(create_domain_auth_provider_response_configJSON, "clientId");
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

    // create_domain_auth_provider_response_config->client_secret
    cJSON *client_secret = cJSON_GetObjectItemCaseSensitive(create_domain_auth_provider_response_configJSON, "clientSecret");
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

    // create_domain_auth_provider_response_config->invited_only
    cJSON *invited_only = cJSON_GetObjectItemCaseSensitive(create_domain_auth_provider_response_configJSON, "invitedOnly");
    if (cJSON_IsNull(invited_only)) {
        invited_only = NULL;
    }
    if (invited_only) { 
    if(!cJSON_IsBool(invited_only))
    {
    goto end; //Bool
    }
    }


    create_domain_auth_provider_response_config_local_var = create_domain_auth_provider_response_config_create_internal (
        strdup(discovery_url->valuestring),
        strdup(client_id->valuestring),
        strdup(client_secret->valuestring),
        invited_only ? invited_only->valueint : 0
        );

    return create_domain_auth_provider_response_config_local_var;
end:
    return NULL;

}
