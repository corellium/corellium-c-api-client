#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "open_id_config_v1.h"



static open_id_config_v1_t *open_id_config_v1_create_internal(
    char *discovery_url,
    char *client_id,
    char *client_secret,
    int invited_only
    ) {
    open_id_config_v1_t *open_id_config_v1_local_var = malloc(sizeof(open_id_config_v1_t));
    if (!open_id_config_v1_local_var) {
        return NULL;
    }
    open_id_config_v1_local_var->discovery_url = discovery_url;
    open_id_config_v1_local_var->client_id = client_id;
    open_id_config_v1_local_var->client_secret = client_secret;
    open_id_config_v1_local_var->invited_only = invited_only;

    open_id_config_v1_local_var->_library_owned = 1;
    return open_id_config_v1_local_var;
}

__attribute__((deprecated)) open_id_config_v1_t *open_id_config_v1_create(
    char *discovery_url,
    char *client_id,
    char *client_secret,
    int invited_only
    ) {
    return open_id_config_v1_create_internal (
        discovery_url,
        client_id,
        client_secret,
        invited_only
        );
}

void open_id_config_v1_free(open_id_config_v1_t *open_id_config_v1) {
    if(NULL == open_id_config_v1){
        return ;
    }
    if(open_id_config_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "open_id_config_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (open_id_config_v1->discovery_url) {
        free(open_id_config_v1->discovery_url);
        open_id_config_v1->discovery_url = NULL;
    }
    if (open_id_config_v1->client_id) {
        free(open_id_config_v1->client_id);
        open_id_config_v1->client_id = NULL;
    }
    if (open_id_config_v1->client_secret) {
        free(open_id_config_v1->client_secret);
        open_id_config_v1->client_secret = NULL;
    }
    free(open_id_config_v1);
}

cJSON *open_id_config_v1_convertToJSON(open_id_config_v1_t *open_id_config_v1) {
    cJSON *item = cJSON_CreateObject();

    // open_id_config_v1->discovery_url
    if(open_id_config_v1->discovery_url) {
    if(cJSON_AddStringToObject(item, "discoveryUrl", open_id_config_v1->discovery_url) == NULL) {
    goto fail; //String
    }
    }


    // open_id_config_v1->client_id
    if(open_id_config_v1->client_id) {
    if(cJSON_AddStringToObject(item, "clientId", open_id_config_v1->client_id) == NULL) {
    goto fail; //String
    }
    }


    // open_id_config_v1->client_secret
    if(open_id_config_v1->client_secret) {
    if(cJSON_AddStringToObject(item, "clientSecret", open_id_config_v1->client_secret) == NULL) {
    goto fail; //String
    }
    }


    // open_id_config_v1->invited_only
    if(open_id_config_v1->invited_only) {
    if(cJSON_AddBoolToObject(item, "invitedOnly", open_id_config_v1->invited_only) == NULL) {
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

open_id_config_v1_t *open_id_config_v1_parseFromJSON(cJSON *open_id_config_v1JSON){

    open_id_config_v1_t *open_id_config_v1_local_var = NULL;

    // open_id_config_v1->discovery_url
    cJSON *discovery_url = cJSON_GetObjectItemCaseSensitive(open_id_config_v1JSON, "discoveryUrl");
    if (cJSON_IsNull(discovery_url)) {
        discovery_url = NULL;
    }
    if (discovery_url) { 
    if(!cJSON_IsString(discovery_url) && !cJSON_IsNull(discovery_url))
    {
    goto end; //String
    }
    }

    // open_id_config_v1->client_id
    cJSON *client_id = cJSON_GetObjectItemCaseSensitive(open_id_config_v1JSON, "clientId");
    if (cJSON_IsNull(client_id)) {
        client_id = NULL;
    }
    if (client_id) { 
    if(!cJSON_IsString(client_id) && !cJSON_IsNull(client_id))
    {
    goto end; //String
    }
    }

    // open_id_config_v1->client_secret
    cJSON *client_secret = cJSON_GetObjectItemCaseSensitive(open_id_config_v1JSON, "clientSecret");
    if (cJSON_IsNull(client_secret)) {
        client_secret = NULL;
    }
    if (client_secret) { 
    if(!cJSON_IsString(client_secret) && !cJSON_IsNull(client_secret))
    {
    goto end; //String
    }
    }

    // open_id_config_v1->invited_only
    cJSON *invited_only = cJSON_GetObjectItemCaseSensitive(open_id_config_v1JSON, "invitedOnly");
    if (cJSON_IsNull(invited_only)) {
        invited_only = NULL;
    }
    if (invited_only) { 
    if(!cJSON_IsBool(invited_only))
    {
    goto end; //Bool
    }
    }


    open_id_config_v1_local_var = open_id_config_v1_create_internal (
        discovery_url && !cJSON_IsNull(discovery_url) ? strdup(discovery_url->valuestring) : NULL,
        client_id && !cJSON_IsNull(client_id) ? strdup(client_id->valuestring) : NULL,
        client_secret && !cJSON_IsNull(client_secret) ? strdup(client_secret->valuestring) : NULL,
        invited_only ? invited_only->valueint : 0
        );

    return open_id_config_v1_local_var;
end:
    return NULL;

}
