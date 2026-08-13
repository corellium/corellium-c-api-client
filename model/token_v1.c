#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "token_v1.h"



static token_v1_t *token_v1_create_internal(
    char *token
    ) {
    token_v1_t *token_v1_local_var = malloc(sizeof(token_v1_t));
    if (!token_v1_local_var) {
        return NULL;
    }
    token_v1_local_var->token = token;

    token_v1_local_var->_library_owned = 1;
    return token_v1_local_var;
}

__attribute__((deprecated)) token_v1_t *token_v1_create(
    char *token
    ) {
    return token_v1_create_internal (
        token
        );
}

void token_v1_free(token_v1_t *token_v1) {
    if(NULL == token_v1){
        return ;
    }
    if(token_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "token_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (token_v1->token) {
        free(token_v1->token);
        token_v1->token = NULL;
    }
    free(token_v1);
}

cJSON *token_v1_convertToJSON(token_v1_t *token_v1) {
    cJSON *item = cJSON_CreateObject();

    // token_v1->token
    if(token_v1->token) {
    if(cJSON_AddStringToObject(item, "token", token_v1->token) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

token_v1_t *token_v1_parseFromJSON(cJSON *token_v1JSON){

    token_v1_t *token_v1_local_var = NULL;

    // token_v1->token
    cJSON *token = cJSON_GetObjectItemCaseSensitive(token_v1JSON, "token");
    if (cJSON_IsNull(token)) {
        token = NULL;
    }
    if (token) { 
    if(!cJSON_IsString(token) && !cJSON_IsNull(token))
    {
    goto end; //String
    }
    }


    token_v1_local_var = token_v1_create_internal (
        token && !cJSON_IsNull(token) ? strdup(token->valuestring) : NULL
        );

    return token_v1_local_var;
end:
    return NULL;

}
