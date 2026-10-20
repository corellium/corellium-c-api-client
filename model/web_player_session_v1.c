#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "web_player_session_v1.h"



static web_player_session_v1_t *web_player_session_v1_create_internal(
    char *identifier,
    char *token,
    double expiration
    ) {
    web_player_session_v1_t *web_player_session_v1_local_var = malloc(sizeof(web_player_session_v1_t));
    if (!web_player_session_v1_local_var) {
        return NULL;
    }
    web_player_session_v1_local_var->identifier = identifier;
    web_player_session_v1_local_var->token = token;
    web_player_session_v1_local_var->expiration = expiration;

    web_player_session_v1_local_var->_library_owned = 1;
    return web_player_session_v1_local_var;
}

__attribute__((deprecated)) web_player_session_v1_t *web_player_session_v1_create(
    char *identifier,
    char *token,
    double expiration
    ) {
    return web_player_session_v1_create_internal (
        identifier,
        token,
        expiration
        );
}

void web_player_session_v1_free(web_player_session_v1_t *web_player_session_v1) {
    if(NULL == web_player_session_v1){
        return ;
    }
    if(web_player_session_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "web_player_session_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (web_player_session_v1->identifier) {
        free(web_player_session_v1->identifier);
        web_player_session_v1->identifier = NULL;
    }
    if (web_player_session_v1->token) {
        free(web_player_session_v1->token);
        web_player_session_v1->token = NULL;
    }
    free(web_player_session_v1);
}

cJSON *web_player_session_v1_convertToJSON(web_player_session_v1_t *web_player_session_v1) {
    cJSON *item = cJSON_CreateObject();

    // web_player_session_v1->identifier
    if (!web_player_session_v1->identifier) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "identifier", web_player_session_v1->identifier) == NULL) {
    goto fail; //String
    }


    // web_player_session_v1->token
    if (!web_player_session_v1->token) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "token", web_player_session_v1->token) == NULL) {
    goto fail; //String
    }


    // web_player_session_v1->expiration
    if (!web_player_session_v1->expiration) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "expiration", web_player_session_v1->expiration) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

web_player_session_v1_t *web_player_session_v1_parseFromJSON(cJSON *web_player_session_v1JSON){

    web_player_session_v1_t *web_player_session_v1_local_var = NULL;

    // web_player_session_v1->identifier
    cJSON *identifier = cJSON_GetObjectItemCaseSensitive(web_player_session_v1JSON, "identifier");
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

    // web_player_session_v1->token
    cJSON *token = cJSON_GetObjectItemCaseSensitive(web_player_session_v1JSON, "token");
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

    // web_player_session_v1->expiration
    cJSON *expiration = cJSON_GetObjectItemCaseSensitive(web_player_session_v1JSON, "expiration");
    if (cJSON_IsNull(expiration)) {
        expiration = NULL;
    }
    if (!expiration) {
        goto end;
    }

    
    if(!cJSON_IsNumber(expiration))
    {
    goto end; //Numeric
    }


    web_player_session_v1_local_var = web_player_session_v1_create_internal (
        strdup(identifier->valuestring),
        strdup(token->valuestring),
        expiration->valuedouble
        );

    return web_player_session_v1_local_var;
end:
    return NULL;

}
