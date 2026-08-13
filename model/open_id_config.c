#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "open_id_config.h"



static open_id_config_t *open_id_config_create_internal(
    char *discovery_url,
    char *client_id,
    char *client_secret,
    int invited_only
    ) {
    open_id_config_t *open_id_config_local_var = malloc(sizeof(open_id_config_t));
    if (!open_id_config_local_var) {
        return NULL;
    }
    open_id_config_local_var->discovery_url = discovery_url;
    open_id_config_local_var->client_id = client_id;
    open_id_config_local_var->client_secret = client_secret;
    open_id_config_local_var->invited_only = invited_only;

    open_id_config_local_var->_library_owned = 1;
    return open_id_config_local_var;
}

__attribute__((deprecated)) open_id_config_t *open_id_config_create(
    char *discovery_url,
    char *client_id,
    char *client_secret,
    int invited_only
    ) {
    return open_id_config_create_internal (
        discovery_url,
        client_id,
        client_secret,
        invited_only
        );
}

void open_id_config_free(open_id_config_t *open_id_config) {
    if(NULL == open_id_config){
        return ;
    }
    if(open_id_config->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "open_id_config_free");
        return ;
    }
    listEntry_t *listEntry;
    if (open_id_config->discovery_url) {
        free(open_id_config->discovery_url);
        open_id_config->discovery_url = NULL;
    }
    if (open_id_config->client_id) {
        free(open_id_config->client_id);
        open_id_config->client_id = NULL;
    }
    if (open_id_config->client_secret) {
        free(open_id_config->client_secret);
        open_id_config->client_secret = NULL;
    }
    free(open_id_config);
}

cJSON *open_id_config_convertToJSON(open_id_config_t *open_id_config) {
    cJSON *item = cJSON_CreateObject();

    // open_id_config->discovery_url
    if (!open_id_config->discovery_url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "discoveryUrl", open_id_config->discovery_url) == NULL) {
    goto fail; //String
    }


    // open_id_config->client_id
    if (!open_id_config->client_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "clientId", open_id_config->client_id) == NULL) {
    goto fail; //String
    }


    // open_id_config->client_secret
    if (!open_id_config->client_secret) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "clientSecret", open_id_config->client_secret) == NULL) {
    goto fail; //String
    }


    // open_id_config->invited_only
    if(open_id_config->invited_only) {
    if(cJSON_AddBoolToObject(item, "invitedOnly", open_id_config->invited_only) == NULL) {
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

open_id_config_t *open_id_config_parseFromJSON(cJSON *open_id_configJSON){

    open_id_config_t *open_id_config_local_var = NULL;

    // open_id_config->discovery_url
    cJSON *discovery_url = cJSON_GetObjectItemCaseSensitive(open_id_configJSON, "discoveryUrl");
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

    // open_id_config->client_id
    cJSON *client_id = cJSON_GetObjectItemCaseSensitive(open_id_configJSON, "clientId");
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

    // open_id_config->client_secret
    cJSON *client_secret = cJSON_GetObjectItemCaseSensitive(open_id_configJSON, "clientSecret");
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

    // open_id_config->invited_only
    cJSON *invited_only = cJSON_GetObjectItemCaseSensitive(open_id_configJSON, "invitedOnly");
    if (cJSON_IsNull(invited_only)) {
        invited_only = NULL;
    }
    if (invited_only) { 
    if(!cJSON_IsBool(invited_only))
    {
    goto end; //Bool
    }
    }


    open_id_config_local_var = open_id_config_create_internal (
        strdup(discovery_url->valuestring),
        strdup(client_id->valuestring),
        strdup(client_secret->valuestring),
        invited_only ? invited_only->valueint : 0
        );

    return open_id_config_local_var;
end:
    return NULL;

}
