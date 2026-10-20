#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "subscribe_to_trial_body.h"



static subscribe_to_trial_body_t *subscribe_to_trial_body_create_internal(
    char *trial_request_code,
    char *password,
    int terms_of_service,
    char *enterprise_domain_name,
    int sso,
    char *email,
    char *name,
    char *federated_user_id
    ) {
    subscribe_to_trial_body_t *subscribe_to_trial_body_local_var = malloc(sizeof(subscribe_to_trial_body_t));
    if (!subscribe_to_trial_body_local_var) {
        return NULL;
    }
    subscribe_to_trial_body_local_var->trial_request_code = trial_request_code;
    subscribe_to_trial_body_local_var->password = password;
    subscribe_to_trial_body_local_var->terms_of_service = terms_of_service;
    subscribe_to_trial_body_local_var->enterprise_domain_name = enterprise_domain_name;
    subscribe_to_trial_body_local_var->sso = sso;
    subscribe_to_trial_body_local_var->email = email;
    subscribe_to_trial_body_local_var->name = name;
    subscribe_to_trial_body_local_var->federated_user_id = federated_user_id;

    subscribe_to_trial_body_local_var->_library_owned = 1;
    return subscribe_to_trial_body_local_var;
}

__attribute__((deprecated)) subscribe_to_trial_body_t *subscribe_to_trial_body_create(
    char *trial_request_code,
    char *password,
    int terms_of_service,
    char *enterprise_domain_name,
    int sso,
    char *email,
    char *name,
    char *federated_user_id
    ) {
    return subscribe_to_trial_body_create_internal (
        trial_request_code,
        password,
        terms_of_service,
        enterprise_domain_name,
        sso,
        email,
        name,
        federated_user_id
        );
}

void subscribe_to_trial_body_free(subscribe_to_trial_body_t *subscribe_to_trial_body) {
    if(NULL == subscribe_to_trial_body){
        return ;
    }
    if(subscribe_to_trial_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "subscribe_to_trial_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (subscribe_to_trial_body->trial_request_code) {
        free(subscribe_to_trial_body->trial_request_code);
        subscribe_to_trial_body->trial_request_code = NULL;
    }
    if (subscribe_to_trial_body->password) {
        free(subscribe_to_trial_body->password);
        subscribe_to_trial_body->password = NULL;
    }
    if (subscribe_to_trial_body->enterprise_domain_name) {
        free(subscribe_to_trial_body->enterprise_domain_name);
        subscribe_to_trial_body->enterprise_domain_name = NULL;
    }
    if (subscribe_to_trial_body->email) {
        free(subscribe_to_trial_body->email);
        subscribe_to_trial_body->email = NULL;
    }
    if (subscribe_to_trial_body->name) {
        free(subscribe_to_trial_body->name);
        subscribe_to_trial_body->name = NULL;
    }
    if (subscribe_to_trial_body->federated_user_id) {
        free(subscribe_to_trial_body->federated_user_id);
        subscribe_to_trial_body->federated_user_id = NULL;
    }
    free(subscribe_to_trial_body);
}

cJSON *subscribe_to_trial_body_convertToJSON(subscribe_to_trial_body_t *subscribe_to_trial_body) {
    cJSON *item = cJSON_CreateObject();

    // subscribe_to_trial_body->trial_request_code
    if(subscribe_to_trial_body->trial_request_code) {
    if(cJSON_AddStringToObject(item, "trialRequestCode", subscribe_to_trial_body->trial_request_code) == NULL) {
    goto fail; //String
    }
    }


    // subscribe_to_trial_body->password
    if(subscribe_to_trial_body->password) {
    if(cJSON_AddStringToObject(item, "password", subscribe_to_trial_body->password) == NULL) {
    goto fail; //String
    }
    }


    // subscribe_to_trial_body->terms_of_service
    if(subscribe_to_trial_body->terms_of_service) {
    if(cJSON_AddBoolToObject(item, "termsOfService", subscribe_to_trial_body->terms_of_service) == NULL) {
    goto fail; //Bool
    }
    }


    // subscribe_to_trial_body->enterprise_domain_name
    if(subscribe_to_trial_body->enterprise_domain_name) {
    if(cJSON_AddStringToObject(item, "enterpriseDomainName", subscribe_to_trial_body->enterprise_domain_name) == NULL) {
    goto fail; //String
    }
    }


    // subscribe_to_trial_body->sso
    if(subscribe_to_trial_body->sso) {
    if(cJSON_AddBoolToObject(item, "sso", subscribe_to_trial_body->sso) == NULL) {
    goto fail; //Bool
    }
    }


    // subscribe_to_trial_body->email
    if(subscribe_to_trial_body->email) {
    if(cJSON_AddStringToObject(item, "email", subscribe_to_trial_body->email) == NULL) {
    goto fail; //String
    }
    }


    // subscribe_to_trial_body->name
    if(subscribe_to_trial_body->name) {
    if(cJSON_AddStringToObject(item, "name", subscribe_to_trial_body->name) == NULL) {
    goto fail; //String
    }
    }


    // subscribe_to_trial_body->federated_user_id
    if(subscribe_to_trial_body->federated_user_id) {
    if(cJSON_AddStringToObject(item, "federatedUserId", subscribe_to_trial_body->federated_user_id) == NULL) {
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

subscribe_to_trial_body_t *subscribe_to_trial_body_parseFromJSON(cJSON *subscribe_to_trial_bodyJSON){

    subscribe_to_trial_body_t *subscribe_to_trial_body_local_var = NULL;

    // subscribe_to_trial_body->trial_request_code
    cJSON *trial_request_code = cJSON_GetObjectItemCaseSensitive(subscribe_to_trial_bodyJSON, "trialRequestCode");
    if (cJSON_IsNull(trial_request_code)) {
        trial_request_code = NULL;
    }
    if (trial_request_code) { 
    if(!cJSON_IsString(trial_request_code) && !cJSON_IsNull(trial_request_code))
    {
    goto end; //String
    }
    }

    // subscribe_to_trial_body->password
    cJSON *password = cJSON_GetObjectItemCaseSensitive(subscribe_to_trial_bodyJSON, "password");
    if (cJSON_IsNull(password)) {
        password = NULL;
    }
    if (password) { 
    if(!cJSON_IsString(password) && !cJSON_IsNull(password))
    {
    goto end; //String
    }
    }

    // subscribe_to_trial_body->terms_of_service
    cJSON *terms_of_service = cJSON_GetObjectItemCaseSensitive(subscribe_to_trial_bodyJSON, "termsOfService");
    if (cJSON_IsNull(terms_of_service)) {
        terms_of_service = NULL;
    }
    if (terms_of_service) { 
    if(!cJSON_IsBool(terms_of_service))
    {
    goto end; //Bool
    }
    }

    // subscribe_to_trial_body->enterprise_domain_name
    cJSON *enterprise_domain_name = cJSON_GetObjectItemCaseSensitive(subscribe_to_trial_bodyJSON, "enterpriseDomainName");
    if (cJSON_IsNull(enterprise_domain_name)) {
        enterprise_domain_name = NULL;
    }
    if (enterprise_domain_name) { 
    if(!cJSON_IsString(enterprise_domain_name) && !cJSON_IsNull(enterprise_domain_name))
    {
    goto end; //String
    }
    }

    // subscribe_to_trial_body->sso
    cJSON *sso = cJSON_GetObjectItemCaseSensitive(subscribe_to_trial_bodyJSON, "sso");
    if (cJSON_IsNull(sso)) {
        sso = NULL;
    }
    if (sso) { 
    if(!cJSON_IsBool(sso))
    {
    goto end; //Bool
    }
    }

    // subscribe_to_trial_body->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(subscribe_to_trial_bodyJSON, "email");
    if (cJSON_IsNull(email)) {
        email = NULL;
    }
    if (email) { 
    if(!cJSON_IsString(email) && !cJSON_IsNull(email))
    {
    goto end; //String
    }
    }

    // subscribe_to_trial_body->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(subscribe_to_trial_bodyJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // subscribe_to_trial_body->federated_user_id
    cJSON *federated_user_id = cJSON_GetObjectItemCaseSensitive(subscribe_to_trial_bodyJSON, "federatedUserId");
    if (cJSON_IsNull(federated_user_id)) {
        federated_user_id = NULL;
    }
    if (federated_user_id) { 
    if(!cJSON_IsString(federated_user_id) && !cJSON_IsNull(federated_user_id))
    {
    goto end; //String
    }
    }


    subscribe_to_trial_body_local_var = subscribe_to_trial_body_create_internal (
        trial_request_code && !cJSON_IsNull(trial_request_code) ? strdup(trial_request_code->valuestring) : NULL,
        password && !cJSON_IsNull(password) ? strdup(password->valuestring) : NULL,
        terms_of_service ? terms_of_service->valueint : 0,
        enterprise_domain_name && !cJSON_IsNull(enterprise_domain_name) ? strdup(enterprise_domain_name->valuestring) : NULL,
        sso ? sso->valueint : 0,
        email && !cJSON_IsNull(email) ? strdup(email->valuestring) : NULL,
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        federated_user_id && !cJSON_IsNull(federated_user_id) ? strdup(federated_user_id->valuestring) : NULL
        );

    return subscribe_to_trial_body_local_var;
end:
    return NULL;

}
