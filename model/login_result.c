#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "login_result.h"



static login_result_t *login_result_create_internal(
    char *token,
    char *expiration
    ) {
    login_result_t *login_result_local_var = malloc(sizeof(login_result_t));
    if (!login_result_local_var) {
        return NULL;
    }
    login_result_local_var->token = token;
    login_result_local_var->expiration = expiration;

    login_result_local_var->_library_owned = 1;
    return login_result_local_var;
}

__attribute__((deprecated)) login_result_t *login_result_create(
    char *token,
    char *expiration
    ) {
    return login_result_create_internal (
        token,
        expiration
        );
}

void login_result_free(login_result_t *login_result) {
    if(NULL == login_result){
        return ;
    }
    if(login_result->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "login_result_free");
        return ;
    }
    listEntry_t *listEntry;
    if (login_result->token) {
        free(login_result->token);
        login_result->token = NULL;
    }
    if (login_result->expiration) {
        free(login_result->expiration);
        login_result->expiration = NULL;
    }
    free(login_result);
}

cJSON *login_result_convertToJSON(login_result_t *login_result) {
    cJSON *item = cJSON_CreateObject();

    // login_result->token
    if (!login_result->token) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "token", login_result->token) == NULL) {
    goto fail; //String
    }


    // login_result->expiration
    if (!login_result->expiration) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "expiration", login_result->expiration) == NULL) {
    goto fail; //Date-Time
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

login_result_t *login_result_parseFromJSON(cJSON *login_resultJSON){

    login_result_t *login_result_local_var = NULL;

    // login_result->token
    cJSON *token = cJSON_GetObjectItemCaseSensitive(login_resultJSON, "token");
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

    // login_result->expiration
    cJSON *expiration = cJSON_GetObjectItemCaseSensitive(login_resultJSON, "expiration");
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


    login_result_local_var = login_result_create_internal (
        strdup(token->valuestring),
        strdup(expiration->valuestring)
        );

    return login_result_local_var;
end:
    return NULL;

}
