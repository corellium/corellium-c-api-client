#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "web_player_created_session.h"



static web_player_created_session_t *web_player_created_session_create_internal(
    char *identifier,
    char *token,
    char *expiration,
    web_player_session_domain_t *domain,
    double time,
    int disabled
    ) {
    web_player_created_session_t *web_player_created_session_local_var = malloc(sizeof(web_player_created_session_t));
    if (!web_player_created_session_local_var) {
        return NULL;
    }
    web_player_created_session_local_var->identifier = identifier;
    web_player_created_session_local_var->token = token;
    web_player_created_session_local_var->expiration = expiration;
    web_player_created_session_local_var->domain = domain;
    web_player_created_session_local_var->time = time;
    web_player_created_session_local_var->disabled = disabled;

    web_player_created_session_local_var->_library_owned = 1;
    return web_player_created_session_local_var;
}

__attribute__((deprecated)) web_player_created_session_t *web_player_created_session_create(
    char *identifier,
    char *token,
    char *expiration,
    web_player_session_domain_t *domain,
    double time,
    int disabled
    ) {
    return web_player_created_session_create_internal (
        identifier,
        token,
        expiration,
        domain,
        time,
        disabled
        );
}

void web_player_created_session_free(web_player_created_session_t *web_player_created_session) {
    if(NULL == web_player_created_session){
        return ;
    }
    if(web_player_created_session->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "web_player_created_session_free");
        return ;
    }
    listEntry_t *listEntry;
    if (web_player_created_session->identifier) {
        free(web_player_created_session->identifier);
        web_player_created_session->identifier = NULL;
    }
    if (web_player_created_session->token) {
        free(web_player_created_session->token);
        web_player_created_session->token = NULL;
    }
    if (web_player_created_session->expiration) {
        free(web_player_created_session->expiration);
        web_player_created_session->expiration = NULL;
    }
    if (web_player_created_session->domain) {
        web_player_session_domain_free(web_player_created_session->domain);
        web_player_created_session->domain = NULL;
    }
    free(web_player_created_session);
}

cJSON *web_player_created_session_convertToJSON(web_player_created_session_t *web_player_created_session) {
    cJSON *item = cJSON_CreateObject();

    // web_player_created_session->identifier
    if (!web_player_created_session->identifier) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "identifier", web_player_created_session->identifier) == NULL) {
    goto fail; //String
    }


    // web_player_created_session->token
    if (!web_player_created_session->token) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "token", web_player_created_session->token) == NULL) {
    goto fail; //String
    }


    // web_player_created_session->expiration
    if (!web_player_created_session->expiration) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "expiration", web_player_created_session->expiration) == NULL) {
    goto fail; //Date-Time
    }


    // web_player_created_session->domain
    if(web_player_created_session->domain) {
    cJSON *domain_local_JSON = web_player_session_domain_convertToJSON(web_player_created_session->domain);
    if(domain_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "domain", domain_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // web_player_created_session->time
    if(web_player_created_session->time) {
    if(cJSON_AddNumberToObject(item, "time", web_player_created_session->time) == NULL) {
    goto fail; //Numeric
    }
    }


    // web_player_created_session->disabled
    if(web_player_created_session->disabled) {
    if(cJSON_AddBoolToObject(item, "disabled", web_player_created_session->disabled) == NULL) {
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

web_player_created_session_t *web_player_created_session_parseFromJSON(cJSON *web_player_created_sessionJSON){

    web_player_created_session_t *web_player_created_session_local_var = NULL;

    // define the local variable for web_player_created_session->domain
    web_player_session_domain_t *domain_local_nonprim = NULL;

    // web_player_created_session->identifier
    cJSON *identifier = cJSON_GetObjectItemCaseSensitive(web_player_created_sessionJSON, "identifier");
    if (cJSON_IsNull(identifier)) {
        identifier = NULL;
    }
    if (!identifier) {
        goto end;
    }

    
    if(!cJSON_IsString(identifier))
    {
    goto end; //String
    }

    // web_player_created_session->token
    cJSON *token = cJSON_GetObjectItemCaseSensitive(web_player_created_sessionJSON, "token");
    if (cJSON_IsNull(token)) {
        token = NULL;
    }
    if (!token) {
        goto end;
    }

    
    if(!cJSON_IsString(token))
    {
    goto end; //String
    }

    // web_player_created_session->expiration
    cJSON *expiration = cJSON_GetObjectItemCaseSensitive(web_player_created_sessionJSON, "expiration");
    if (cJSON_IsNull(expiration)) {
        expiration = NULL;
    }
    if (!expiration) {
        goto end;
    }

    
    if(!cJSON_IsString(expiration) && !cJSON_IsNull(expiration))
    {
    goto end; //DateTime
    }

    // web_player_created_session->domain
    cJSON *domain = cJSON_GetObjectItemCaseSensitive(web_player_created_sessionJSON, "domain");
    if (cJSON_IsNull(domain)) {
        domain = NULL;
    }
    if (domain) { 
    domain_local_nonprim = web_player_session_domain_parseFromJSON(domain); //nonprimitive
    }

    // web_player_created_session->time
    cJSON *time = cJSON_GetObjectItemCaseSensitive(web_player_created_sessionJSON, "time");
    if (cJSON_IsNull(time)) {
        time = NULL;
    }
    if (time) { 
    if(!cJSON_IsNumber(time))
    {
    goto end; //Numeric
    }
    }

    // web_player_created_session->disabled
    cJSON *disabled = cJSON_GetObjectItemCaseSensitive(web_player_created_sessionJSON, "disabled");
    if (cJSON_IsNull(disabled)) {
        disabled = NULL;
    }
    if (disabled) { 
    if(!cJSON_IsBool(disabled))
    {
    goto end; //Bool
    }
    }


    web_player_created_session_local_var = web_player_created_session_create_internal (
        strdup(identifier->valuestring),
        strdup(token->valuestring),
        strdup(expiration->valuestring),
        domain ? domain_local_nonprim : NULL,
        time ? time->valuedouble : 0,
        disabled ? disabled->valueint : 0
        );

    return web_player_created_session_local_var;
end:
    if (domain_local_nonprim) {
        web_player_session_domain_free(domain_local_nonprim);
        domain_local_nonprim = NULL;
    }
    return NULL;

}
