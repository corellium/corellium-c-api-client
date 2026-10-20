#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "agent_system_install_open_gapps_body.h"



static agent_system_install_open_gapps_body_t *agent_system_install_open_gapps_body_create_internal(
    char *url,
    char *hash,
    char *fingerprint
    ) {
    agent_system_install_open_gapps_body_t *agent_system_install_open_gapps_body_local_var = malloc(sizeof(agent_system_install_open_gapps_body_t));
    if (!agent_system_install_open_gapps_body_local_var) {
        return NULL;
    }
    agent_system_install_open_gapps_body_local_var->url = url;
    agent_system_install_open_gapps_body_local_var->hash = hash;
    agent_system_install_open_gapps_body_local_var->fingerprint = fingerprint;

    agent_system_install_open_gapps_body_local_var->_library_owned = 1;
    return agent_system_install_open_gapps_body_local_var;
}

__attribute__((deprecated)) agent_system_install_open_gapps_body_t *agent_system_install_open_gapps_body_create(
    char *url,
    char *hash,
    char *fingerprint
    ) {
    return agent_system_install_open_gapps_body_create_internal (
        url,
        hash,
        fingerprint
        );
}

void agent_system_install_open_gapps_body_free(agent_system_install_open_gapps_body_t *agent_system_install_open_gapps_body) {
    if(NULL == agent_system_install_open_gapps_body){
        return ;
    }
    if(agent_system_install_open_gapps_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "agent_system_install_open_gapps_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (agent_system_install_open_gapps_body->url) {
        free(agent_system_install_open_gapps_body->url);
        agent_system_install_open_gapps_body->url = NULL;
    }
    if (agent_system_install_open_gapps_body->hash) {
        free(agent_system_install_open_gapps_body->hash);
        agent_system_install_open_gapps_body->hash = NULL;
    }
    if (agent_system_install_open_gapps_body->fingerprint) {
        free(agent_system_install_open_gapps_body->fingerprint);
        agent_system_install_open_gapps_body->fingerprint = NULL;
    }
    free(agent_system_install_open_gapps_body);
}

cJSON *agent_system_install_open_gapps_body_convertToJSON(agent_system_install_open_gapps_body_t *agent_system_install_open_gapps_body) {
    cJSON *item = cJSON_CreateObject();

    // agent_system_install_open_gapps_body->url
    if (!agent_system_install_open_gapps_body->url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "url", agent_system_install_open_gapps_body->url) == NULL) {
    goto fail; //String
    }


    // agent_system_install_open_gapps_body->hash
    if (!agent_system_install_open_gapps_body->hash) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "hash", agent_system_install_open_gapps_body->hash) == NULL) {
    goto fail; //String
    }


    // agent_system_install_open_gapps_body->fingerprint
    if (!agent_system_install_open_gapps_body->fingerprint) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "fingerprint", agent_system_install_open_gapps_body->fingerprint) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

agent_system_install_open_gapps_body_t *agent_system_install_open_gapps_body_parseFromJSON(cJSON *agent_system_install_open_gapps_bodyJSON){

    agent_system_install_open_gapps_body_t *agent_system_install_open_gapps_body_local_var = NULL;

    // agent_system_install_open_gapps_body->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(agent_system_install_open_gapps_bodyJSON, "url");
    if (cJSON_IsNull(url)) {
        url = NULL;
    }
    if (!url) {
        goto end;
    }

    
    if(!cJSON_IsString(url))
    {
    goto end; //String
    }

    // agent_system_install_open_gapps_body->hash
    cJSON *hash = cJSON_GetObjectItemCaseSensitive(agent_system_install_open_gapps_bodyJSON, "hash");
    if (cJSON_IsNull(hash)) {
        hash = NULL;
    }
    if (!hash) {
        goto end;
    }

    
    if(!cJSON_IsString(hash))
    {
    goto end; //String
    }

    // agent_system_install_open_gapps_body->fingerprint
    cJSON *fingerprint = cJSON_GetObjectItemCaseSensitive(agent_system_install_open_gapps_bodyJSON, "fingerprint");
    if (cJSON_IsNull(fingerprint)) {
        fingerprint = NULL;
    }
    if (!fingerprint) {
        goto end;
    }

    
    if(!cJSON_IsString(fingerprint))
    {
    goto end; //String
    }


    agent_system_install_open_gapps_body_local_var = agent_system_install_open_gapps_body_create_internal (
        strdup(url->valuestring),
        strdup(hash->valuestring),
        strdup(fingerprint->valuestring)
        );

    return agent_system_install_open_gapps_body_local_var;
end:
    return NULL;

}
