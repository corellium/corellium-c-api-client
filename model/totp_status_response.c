#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "totp_status_response.h"



static totp_status_response_t *totp_status_response_create_internal(
    char *token,
    double time,
    totp_status_response_user_t *user,
    totp_status_response_domain_t *domain
    ) {
    totp_status_response_t *totp_status_response_local_var = malloc(sizeof(totp_status_response_t));
    if (!totp_status_response_local_var) {
        return NULL;
    }
    totp_status_response_local_var->token = token;
    totp_status_response_local_var->time = time;
    totp_status_response_local_var->user = user;
    totp_status_response_local_var->domain = domain;

    totp_status_response_local_var->_library_owned = 1;
    return totp_status_response_local_var;
}

__attribute__((deprecated)) totp_status_response_t *totp_status_response_create(
    char *token,
    double time,
    totp_status_response_user_t *user,
    totp_status_response_domain_t *domain
    ) {
    return totp_status_response_create_internal (
        token,
        time,
        user,
        domain
        );
}

void totp_status_response_free(totp_status_response_t *totp_status_response) {
    if(NULL == totp_status_response){
        return ;
    }
    if(totp_status_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "totp_status_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (totp_status_response->token) {
        free(totp_status_response->token);
        totp_status_response->token = NULL;
    }
    if (totp_status_response->user) {
        totp_status_response_user_free(totp_status_response->user);
        totp_status_response->user = NULL;
    }
    if (totp_status_response->domain) {
        totp_status_response_domain_free(totp_status_response->domain);
        totp_status_response->domain = NULL;
    }
    free(totp_status_response);
}

cJSON *totp_status_response_convertToJSON(totp_status_response_t *totp_status_response) {
    cJSON *item = cJSON_CreateObject();

    // totp_status_response->token
    if (!totp_status_response->token) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "token", totp_status_response->token) == NULL) {
    goto fail; //String
    }


    // totp_status_response->time
    if (!totp_status_response->time) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "time", totp_status_response->time) == NULL) {
    goto fail; //Numeric
    }


    // totp_status_response->user
    if (!totp_status_response->user) {
        goto fail;
    }
    cJSON *user_local_JSON = totp_status_response_user_convertToJSON(totp_status_response->user);
    if(user_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "user", user_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // totp_status_response->domain
    if (!totp_status_response->domain) {
        goto fail;
    }
    cJSON *domain_local_JSON = totp_status_response_domain_convertToJSON(totp_status_response->domain);
    if(domain_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "domain", domain_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

totp_status_response_t *totp_status_response_parseFromJSON(cJSON *totp_status_responseJSON){

    totp_status_response_t *totp_status_response_local_var = NULL;

    // define the local variable for totp_status_response->user
    totp_status_response_user_t *user_local_nonprim = NULL;

    // define the local variable for totp_status_response->domain
    totp_status_response_domain_t *domain_local_nonprim = NULL;

    // totp_status_response->token
    cJSON *token = cJSON_GetObjectItemCaseSensitive(totp_status_responseJSON, "token");
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

    // totp_status_response->time
    cJSON *time = cJSON_GetObjectItemCaseSensitive(totp_status_responseJSON, "time");
    if (cJSON_IsNull(time)) {
        time = NULL;
    }
    if (!time) {
        goto end;
    }

    
    if(!cJSON_IsNumber(time))
    {
    goto end; //Numeric
    }

    // totp_status_response->user
    cJSON *user = cJSON_GetObjectItemCaseSensitive(totp_status_responseJSON, "user");
    if (cJSON_IsNull(user)) {
        user = NULL;
    }
    if (!user) {
        goto end;
    }

    
    user_local_nonprim = totp_status_response_user_parseFromJSON(user); //nonprimitive

    // totp_status_response->domain
    cJSON *domain = cJSON_GetObjectItemCaseSensitive(totp_status_responseJSON, "domain");
    if (cJSON_IsNull(domain)) {
        domain = NULL;
    }
    if (!domain) {
        goto end;
    }

    
    domain_local_nonprim = totp_status_response_domain_parseFromJSON(domain); //nonprimitive


    totp_status_response_local_var = totp_status_response_create_internal (
        strdup(token->valuestring),
        time->valuedouble,
        user_local_nonprim,
        domain_local_nonprim
        );

    return totp_status_response_local_var;
end:
    if (user_local_nonprim) {
        totp_status_response_user_free(user_local_nonprim);
        user_local_nonprim = NULL;
    }
    if (domain_local_nonprim) {
        totp_status_response_domain_free(domain_local_nonprim);
        domain_local_nonprim = NULL;
    }
    return NULL;

}
