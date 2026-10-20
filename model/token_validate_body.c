#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "token_validate_body.h"



static token_validate_body_t *token_validate_body_create_internal(
    char *token
    ) {
    token_validate_body_t *token_validate_body_local_var = malloc(sizeof(token_validate_body_t));
    if (!token_validate_body_local_var) {
        return NULL;
    }
    token_validate_body_local_var->token = token;

    token_validate_body_local_var->_library_owned = 1;
    return token_validate_body_local_var;
}

__attribute__((deprecated)) token_validate_body_t *token_validate_body_create(
    char *token
    ) {
    return token_validate_body_create_internal (
        token
        );
}

void token_validate_body_free(token_validate_body_t *token_validate_body) {
    if(NULL == token_validate_body){
        return ;
    }
    if(token_validate_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "token_validate_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (token_validate_body->token) {
        free(token_validate_body->token);
        token_validate_body->token = NULL;
    }
    free(token_validate_body);
}

cJSON *token_validate_body_convertToJSON(token_validate_body_t *token_validate_body) {
    cJSON *item = cJSON_CreateObject();

    // token_validate_body->token
    if (!token_validate_body->token) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "token", token_validate_body->token) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

token_validate_body_t *token_validate_body_parseFromJSON(cJSON *token_validate_bodyJSON){

    token_validate_body_t *token_validate_body_local_var = NULL;

    // token_validate_body->token
    cJSON *token = cJSON_GetObjectItemCaseSensitive(token_validate_bodyJSON, "token");
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


    token_validate_body_local_var = token_validate_body_create_internal (
        strdup(token->valuestring)
        );

    return token_validate_body_local_var;
end:
    return NULL;

}
