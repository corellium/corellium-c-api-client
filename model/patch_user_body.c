#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "patch_user_body.h"



static patch_user_body_t *patch_user_body_create_internal(
    char *name,
    char *label,
    char *email,
    int cluster_administrator,
    char *password,
    object_t *misc,
    int administrator,
    char *agreed_to_terms,
    int totp_enabled
    ) {
    patch_user_body_t *patch_user_body_local_var = malloc(sizeof(patch_user_body_t));
    if (!patch_user_body_local_var) {
        return NULL;
    }
    patch_user_body_local_var->name = name;
    patch_user_body_local_var->label = label;
    patch_user_body_local_var->email = email;
    patch_user_body_local_var->cluster_administrator = cluster_administrator;
    patch_user_body_local_var->password = password;
    patch_user_body_local_var->misc = misc;
    patch_user_body_local_var->administrator = administrator;
    patch_user_body_local_var->agreed_to_terms = agreed_to_terms;
    patch_user_body_local_var->totp_enabled = totp_enabled;

    patch_user_body_local_var->_library_owned = 1;
    return patch_user_body_local_var;
}

__attribute__((deprecated)) patch_user_body_t *patch_user_body_create(
    char *name,
    char *label,
    char *email,
    int cluster_administrator,
    char *password,
    object_t *misc,
    int administrator,
    char *agreed_to_terms,
    int totp_enabled
    ) {
    return patch_user_body_create_internal (
        name,
        label,
        email,
        cluster_administrator,
        password,
        misc,
        administrator,
        agreed_to_terms,
        totp_enabled
        );
}

void patch_user_body_free(patch_user_body_t *patch_user_body) {
    if(NULL == patch_user_body){
        return ;
    }
    if(patch_user_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "patch_user_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (patch_user_body->name) {
        free(patch_user_body->name);
        patch_user_body->name = NULL;
    }
    if (patch_user_body->label) {
        free(patch_user_body->label);
        patch_user_body->label = NULL;
    }
    if (patch_user_body->email) {
        free(patch_user_body->email);
        patch_user_body->email = NULL;
    }
    if (patch_user_body->password) {
        free(patch_user_body->password);
        patch_user_body->password = NULL;
    }
    if (patch_user_body->misc) {
        object_free(patch_user_body->misc);
        patch_user_body->misc = NULL;
    }
    if (patch_user_body->agreed_to_terms) {
        free(patch_user_body->agreed_to_terms);
        patch_user_body->agreed_to_terms = NULL;
    }
    free(patch_user_body);
}

cJSON *patch_user_body_convertToJSON(patch_user_body_t *patch_user_body) {
    cJSON *item = cJSON_CreateObject();

    // patch_user_body->name
    if(patch_user_body->name) {
    if(cJSON_AddStringToObject(item, "name", patch_user_body->name) == NULL) {
    goto fail; //String
    }
    }


    // patch_user_body->label
    if(patch_user_body->label) {
    if(cJSON_AddStringToObject(item, "label", patch_user_body->label) == NULL) {
    goto fail; //String
    }
    }


    // patch_user_body->email
    if(patch_user_body->email) {
    if(cJSON_AddStringToObject(item, "email", patch_user_body->email) == NULL) {
    goto fail; //String
    }
    }


    // patch_user_body->cluster_administrator
    if(patch_user_body->cluster_administrator) {
    if(cJSON_AddBoolToObject(item, "clusterAdministrator", patch_user_body->cluster_administrator) == NULL) {
    goto fail; //Bool
    }
    }


    // patch_user_body->password
    if(patch_user_body->password) {
    if(cJSON_AddStringToObject(item, "password", patch_user_body->password) == NULL) {
    goto fail; //String
    }
    }


    // patch_user_body->misc
    if(patch_user_body->misc) {
    cJSON *misc_object = object_convertToJSON(patch_user_body->misc);
    if(misc_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "misc", misc_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // patch_user_body->administrator
    if(patch_user_body->administrator) {
    if(cJSON_AddBoolToObject(item, "administrator", patch_user_body->administrator) == NULL) {
    goto fail; //Bool
    }
    }


    // patch_user_body->agreed_to_terms
    if(patch_user_body->agreed_to_terms) {
    if(cJSON_AddStringToObject(item, "agreedToTerms", patch_user_body->agreed_to_terms) == NULL) {
    goto fail; //String
    }
    }


    // patch_user_body->totp_enabled
    if(patch_user_body->totp_enabled) {
    if(cJSON_AddBoolToObject(item, "totpEnabled", patch_user_body->totp_enabled) == NULL) {
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

patch_user_body_t *patch_user_body_parseFromJSON(cJSON *patch_user_bodyJSON){

    patch_user_body_t *patch_user_body_local_var = NULL;

    // patch_user_body->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(patch_user_bodyJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // patch_user_body->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(patch_user_bodyJSON, "label");
    if (cJSON_IsNull(label)) {
        label = NULL;
    }
    if (label) { 
    if(!cJSON_IsString(label) && !cJSON_IsNull(label))
    {
    goto end; //String
    }
    }

    // patch_user_body->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(patch_user_bodyJSON, "email");
    if (cJSON_IsNull(email)) {
        email = NULL;
    }
    if (email) { 
    if(!cJSON_IsString(email) && !cJSON_IsNull(email))
    {
    goto end; //String
    }
    }

    // patch_user_body->cluster_administrator
    cJSON *cluster_administrator = cJSON_GetObjectItemCaseSensitive(patch_user_bodyJSON, "clusterAdministrator");
    if (cJSON_IsNull(cluster_administrator)) {
        cluster_administrator = NULL;
    }
    if (cluster_administrator) { 
    if(!cJSON_IsBool(cluster_administrator))
    {
    goto end; //Bool
    }
    }

    // patch_user_body->password
    cJSON *password = cJSON_GetObjectItemCaseSensitive(patch_user_bodyJSON, "password");
    if (cJSON_IsNull(password)) {
        password = NULL;
    }
    if (password) { 
    if(!cJSON_IsString(password) && !cJSON_IsNull(password))
    {
    goto end; //String
    }
    }

    // patch_user_body->misc
    cJSON *misc = cJSON_GetObjectItemCaseSensitive(patch_user_bodyJSON, "misc");
    if (cJSON_IsNull(misc)) {
        misc = NULL;
    }
    object_t *misc_local_object = NULL;
    if (misc) { 
    misc_local_object = object_parseFromJSON(misc); //object
    }

    // patch_user_body->administrator
    cJSON *administrator = cJSON_GetObjectItemCaseSensitive(patch_user_bodyJSON, "administrator");
    if (cJSON_IsNull(administrator)) {
        administrator = NULL;
    }
    if (administrator) { 
    if(!cJSON_IsBool(administrator))
    {
    goto end; //Bool
    }
    }

    // patch_user_body->agreed_to_terms
    cJSON *agreed_to_terms = cJSON_GetObjectItemCaseSensitive(patch_user_bodyJSON, "agreedToTerms");
    if (cJSON_IsNull(agreed_to_terms)) {
        agreed_to_terms = NULL;
    }
    if (agreed_to_terms) { 
    if(!cJSON_IsString(agreed_to_terms) && !cJSON_IsNull(agreed_to_terms))
    {
    goto end; //String
    }
    }

    // patch_user_body->totp_enabled
    cJSON *totp_enabled = cJSON_GetObjectItemCaseSensitive(patch_user_bodyJSON, "totpEnabled");
    if (cJSON_IsNull(totp_enabled)) {
        totp_enabled = NULL;
    }
    if (totp_enabled) { 
    if(!cJSON_IsBool(totp_enabled))
    {
    goto end; //Bool
    }
    }


    patch_user_body_local_var = patch_user_body_create_internal (
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        label && !cJSON_IsNull(label) ? strdup(label->valuestring) : NULL,
        email && !cJSON_IsNull(email) ? strdup(email->valuestring) : NULL,
        cluster_administrator ? cluster_administrator->valueint : 0,
        password && !cJSON_IsNull(password) ? strdup(password->valuestring) : NULL,
        misc ? misc_local_object : NULL,
        administrator ? administrator->valueint : 0,
        agreed_to_terms && !cJSON_IsNull(agreed_to_terms) ? strdup(agreed_to_terms->valuestring) : NULL,
        totp_enabled ? totp_enabled->valueint : 0
        );

    return patch_user_body_local_var;
end:
    return NULL;

}
