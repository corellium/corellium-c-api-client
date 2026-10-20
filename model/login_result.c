#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "login_result.h"



static login_result_t *login_result_create_internal(
    char *token,
    char *expiration,
    login_result_user_t *user,
    login_result_domain_t *domain,
    double time,
    char *identifier,
    login_result_disabled_t *disabled,
    int missing_totp
    ) {
    login_result_t *login_result_local_var = malloc(sizeof(login_result_t));
    if (!login_result_local_var) {
        return NULL;
    }
    login_result_local_var->token = token;
    login_result_local_var->expiration = expiration;
    login_result_local_var->user = user;
    login_result_local_var->domain = domain;
    login_result_local_var->time = time;
    login_result_local_var->identifier = identifier;
    login_result_local_var->disabled = disabled;
    login_result_local_var->missing_totp = missing_totp;

    login_result_local_var->_library_owned = 1;
    return login_result_local_var;
}

__attribute__((deprecated)) login_result_t *login_result_create(
    char *token,
    char *expiration,
    login_result_user_t *user,
    login_result_domain_t *domain,
    double time,
    char *identifier,
    login_result_disabled_t *disabled,
    int missing_totp
    ) {
    return login_result_create_internal (
        token,
        expiration,
        user,
        domain,
        time,
        identifier,
        disabled,
        missing_totp
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
    if (login_result->user) {
        login_result_user_free(login_result->user);
        login_result->user = NULL;
    }
    if (login_result->domain) {
        login_result_domain_free(login_result->domain);
        login_result->domain = NULL;
    }
    if (login_result->identifier) {
        free(login_result->identifier);
        login_result->identifier = NULL;
    }
    if (login_result->disabled) {
        login_result_disabled_free(login_result->disabled);
        login_result->disabled = NULL;
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


    // login_result->user
    if(login_result->user) {
    cJSON *user_local_JSON = login_result_user_convertToJSON(login_result->user);
    if(user_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "user", user_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // login_result->domain
    if(login_result->domain) {
    cJSON *domain_local_JSON = login_result_domain_convertToJSON(login_result->domain);
    if(domain_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "domain", domain_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // login_result->time
    if(login_result->time) {
    if(cJSON_AddNumberToObject(item, "time", login_result->time) == NULL) {
    goto fail; //Numeric
    }
    }


    // login_result->identifier
    if(login_result->identifier) {
    if(cJSON_AddStringToObject(item, "identifier", login_result->identifier) == NULL) {
    goto fail; //String
    }
    }


    // login_result->disabled
    if(login_result->disabled) {
    cJSON *disabled_local_JSON = login_result_disabled_convertToJSON(login_result->disabled);
    if(disabled_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "disabled", disabled_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // login_result->missing_totp
    if(login_result->missing_totp) {
    if(cJSON_AddBoolToObject(item, "missingTOTP", login_result->missing_totp) == NULL) {
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

login_result_t *login_result_parseFromJSON(cJSON *login_resultJSON){

    login_result_t *login_result_local_var = NULL;

    // define the local variable for login_result->user
    login_result_user_t *user_local_nonprim = NULL;

    // define the local variable for login_result->domain
    login_result_domain_t *domain_local_nonprim = NULL;

    // define the local variable for login_result->disabled
    login_result_disabled_t *disabled_local_nonprim = NULL;

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

    // login_result->user
    cJSON *user = cJSON_GetObjectItemCaseSensitive(login_resultJSON, "user");
    if (cJSON_IsNull(user)) {
        user = NULL;
    }
    if (user) { 
    user_local_nonprim = login_result_user_parseFromJSON(user); //nonprimitive
    }

    // login_result->domain
    cJSON *domain = cJSON_GetObjectItemCaseSensitive(login_resultJSON, "domain");
    if (cJSON_IsNull(domain)) {
        domain = NULL;
    }
    if (domain) { 
    domain_local_nonprim = login_result_domain_parseFromJSON(domain); //nonprimitive
    }

    // login_result->time
    cJSON *time = cJSON_GetObjectItemCaseSensitive(login_resultJSON, "time");
    if (cJSON_IsNull(time)) {
        time = NULL;
    }
    if (time) { 
    if(!cJSON_IsNumber(time))
    {
    goto end; //Numeric
    }
    }

    // login_result->identifier
    cJSON *identifier = cJSON_GetObjectItemCaseSensitive(login_resultJSON, "identifier");
    if (cJSON_IsNull(identifier)) {
        identifier = NULL;
    }
    if (identifier) { 
    if(!cJSON_IsString(identifier) && !cJSON_IsNull(identifier))
    {
    goto end; //String
    }
    }

    // login_result->disabled
    cJSON *disabled = cJSON_GetObjectItemCaseSensitive(login_resultJSON, "disabled");
    if (cJSON_IsNull(disabled)) {
        disabled = NULL;
    }
    if (disabled) { 
    disabled_local_nonprim = login_result_disabled_parseFromJSON(disabled); //nonprimitive
    }

    // login_result->missing_totp
    cJSON *missing_totp = cJSON_GetObjectItemCaseSensitive(login_resultJSON, "missingTOTP");
    if (cJSON_IsNull(missing_totp)) {
        missing_totp = NULL;
    }
    if (missing_totp) { 
    if(!cJSON_IsBool(missing_totp))
    {
    goto end; //Bool
    }
    }


    login_result_local_var = login_result_create_internal (
        strdup(token->valuestring),
        strdup(expiration->valuestring),
        user ? user_local_nonprim : NULL,
        domain ? domain_local_nonprim : NULL,
        time ? time->valuedouble : 0,
        identifier && !cJSON_IsNull(identifier) ? strdup(identifier->valuestring) : NULL,
        disabled ? disabled_local_nonprim : NULL,
        missing_totp ? missing_totp->valueint : 0
        );

    return login_result_local_var;
end:
    if (user_local_nonprim) {
        login_result_user_free(user_local_nonprim);
        user_local_nonprim = NULL;
    }
    if (domain_local_nonprim) {
        login_result_domain_free(domain_local_nonprim);
        domain_local_nonprim = NULL;
    }
    if (disabled_local_nonprim) {
        login_result_disabled_free(disabled_local_nonprim);
        disabled_local_nonprim = NULL;
    }
    return NULL;

}
