#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_invite_by_token_body.h"



static get_invite_by_token_body_t *get_invite_by_token_body_create_internal(
    char *token
    ) {
    get_invite_by_token_body_t *get_invite_by_token_body_local_var = malloc(sizeof(get_invite_by_token_body_t));
    if (!get_invite_by_token_body_local_var) {
        return NULL;
    }
    get_invite_by_token_body_local_var->token = token;

    get_invite_by_token_body_local_var->_library_owned = 1;
    return get_invite_by_token_body_local_var;
}

__attribute__((deprecated)) get_invite_by_token_body_t *get_invite_by_token_body_create(
    char *token
    ) {
    return get_invite_by_token_body_create_internal (
        token
        );
}

void get_invite_by_token_body_free(get_invite_by_token_body_t *get_invite_by_token_body) {
    if(NULL == get_invite_by_token_body){
        return ;
    }
    if(get_invite_by_token_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "get_invite_by_token_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (get_invite_by_token_body->token) {
        free(get_invite_by_token_body->token);
        get_invite_by_token_body->token = NULL;
    }
    free(get_invite_by_token_body);
}

cJSON *get_invite_by_token_body_convertToJSON(get_invite_by_token_body_t *get_invite_by_token_body) {
    cJSON *item = cJSON_CreateObject();

    // get_invite_by_token_body->token
    if (!get_invite_by_token_body->token) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "token", get_invite_by_token_body->token) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

get_invite_by_token_body_t *get_invite_by_token_body_parseFromJSON(cJSON *get_invite_by_token_bodyJSON){

    get_invite_by_token_body_t *get_invite_by_token_body_local_var = NULL;

    // get_invite_by_token_body->token
    cJSON *token = cJSON_GetObjectItemCaseSensitive(get_invite_by_token_bodyJSON, "token");
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


    get_invite_by_token_body_local_var = get_invite_by_token_body_create_internal (
        strdup(token->valuestring)
        );

    return get_invite_by_token_body_local_var;
end:
    return NULL;

}
