#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ensure_domain_settings_body_admin_user.h"



static ensure_domain_settings_body_admin_user_t *ensure_domain_settings_body_admin_user_create_internal(
    char *username,
    char *email,
    char *label,
    char *billing_url
    ) {
    ensure_domain_settings_body_admin_user_t *ensure_domain_settings_body_admin_user_local_var = malloc(sizeof(ensure_domain_settings_body_admin_user_t));
    if (!ensure_domain_settings_body_admin_user_local_var) {
        return NULL;
    }
    ensure_domain_settings_body_admin_user_local_var->username = username;
    ensure_domain_settings_body_admin_user_local_var->email = email;
    ensure_domain_settings_body_admin_user_local_var->label = label;
    ensure_domain_settings_body_admin_user_local_var->billing_url = billing_url;

    ensure_domain_settings_body_admin_user_local_var->_library_owned = 1;
    return ensure_domain_settings_body_admin_user_local_var;
}

__attribute__((deprecated)) ensure_domain_settings_body_admin_user_t *ensure_domain_settings_body_admin_user_create(
    char *username,
    char *email,
    char *label,
    char *billing_url
    ) {
    return ensure_domain_settings_body_admin_user_create_internal (
        username,
        email,
        label,
        billing_url
        );
}

void ensure_domain_settings_body_admin_user_free(ensure_domain_settings_body_admin_user_t *ensure_domain_settings_body_admin_user) {
    if(NULL == ensure_domain_settings_body_admin_user){
        return ;
    }
    if(ensure_domain_settings_body_admin_user->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ensure_domain_settings_body_admin_user_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ensure_domain_settings_body_admin_user->username) {
        free(ensure_domain_settings_body_admin_user->username);
        ensure_domain_settings_body_admin_user->username = NULL;
    }
    if (ensure_domain_settings_body_admin_user->email) {
        free(ensure_domain_settings_body_admin_user->email);
        ensure_domain_settings_body_admin_user->email = NULL;
    }
    if (ensure_domain_settings_body_admin_user->label) {
        free(ensure_domain_settings_body_admin_user->label);
        ensure_domain_settings_body_admin_user->label = NULL;
    }
    if (ensure_domain_settings_body_admin_user->billing_url) {
        free(ensure_domain_settings_body_admin_user->billing_url);
        ensure_domain_settings_body_admin_user->billing_url = NULL;
    }
    free(ensure_domain_settings_body_admin_user);
}

cJSON *ensure_domain_settings_body_admin_user_convertToJSON(ensure_domain_settings_body_admin_user_t *ensure_domain_settings_body_admin_user) {
    cJSON *item = cJSON_CreateObject();

    // ensure_domain_settings_body_admin_user->username
    if(ensure_domain_settings_body_admin_user->username) {
    if(cJSON_AddStringToObject(item, "username", ensure_domain_settings_body_admin_user->username) == NULL) {
    goto fail; //String
    }
    }


    // ensure_domain_settings_body_admin_user->email
    if(ensure_domain_settings_body_admin_user->email) {
    if(cJSON_AddStringToObject(item, "email", ensure_domain_settings_body_admin_user->email) == NULL) {
    goto fail; //String
    }
    }


    // ensure_domain_settings_body_admin_user->label
    if(ensure_domain_settings_body_admin_user->label) {
    if(cJSON_AddStringToObject(item, "label", ensure_domain_settings_body_admin_user->label) == NULL) {
    goto fail; //String
    }
    }


    // ensure_domain_settings_body_admin_user->billing_url
    if(ensure_domain_settings_body_admin_user->billing_url) {
    if(cJSON_AddStringToObject(item, "billingUrl", ensure_domain_settings_body_admin_user->billing_url) == NULL) {
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

ensure_domain_settings_body_admin_user_t *ensure_domain_settings_body_admin_user_parseFromJSON(cJSON *ensure_domain_settings_body_admin_userJSON){

    ensure_domain_settings_body_admin_user_t *ensure_domain_settings_body_admin_user_local_var = NULL;

    // ensure_domain_settings_body_admin_user->username
    cJSON *username = cJSON_GetObjectItemCaseSensitive(ensure_domain_settings_body_admin_userJSON, "username");
    if (cJSON_IsNull(username)) {
        username = NULL;
    }
    if (username) { 
    if(!cJSON_IsString(username) && !cJSON_IsNull(username))
    {
    goto end; //String
    }
    }

    // ensure_domain_settings_body_admin_user->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(ensure_domain_settings_body_admin_userJSON, "email");
    if (cJSON_IsNull(email)) {
        email = NULL;
    }
    if (email) { 
    if(!cJSON_IsString(email) && !cJSON_IsNull(email))
    {
    goto end; //String
    }
    }

    // ensure_domain_settings_body_admin_user->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(ensure_domain_settings_body_admin_userJSON, "label");
    if (cJSON_IsNull(label)) {
        label = NULL;
    }
    if (label) { 
    if(!cJSON_IsString(label) && !cJSON_IsNull(label))
    {
    goto end; //String
    }
    }

    // ensure_domain_settings_body_admin_user->billing_url
    cJSON *billing_url = cJSON_GetObjectItemCaseSensitive(ensure_domain_settings_body_admin_userJSON, "billingUrl");
    if (cJSON_IsNull(billing_url)) {
        billing_url = NULL;
    }
    if (billing_url) { 
    if(!cJSON_IsString(billing_url) && !cJSON_IsNull(billing_url))
    {
    goto end; //String
    }
    }


    ensure_domain_settings_body_admin_user_local_var = ensure_domain_settings_body_admin_user_create_internal (
        username && !cJSON_IsNull(username) ? strdup(username->valuestring) : NULL,
        email && !cJSON_IsNull(email) ? strdup(email->valuestring) : NULL,
        label && !cJSON_IsNull(label) ? strdup(label->valuestring) : NULL,
        billing_url && !cJSON_IsNull(billing_url) ? strdup(billing_url->valuestring) : NULL
        );

    return ensure_domain_settings_body_admin_user_local_var;
end:
    return NULL;

}
