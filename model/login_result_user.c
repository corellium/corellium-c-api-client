#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "login_result_user.h"



static login_result_user_t *login_result_user_create_internal(
    char *id,
    char *name,
    char *label,
    char *email,
    int cluster_administrator,
    char *agreed_to_terms,
    char *federated_user_id,
    char *intercom_hmac,
    object_t *misc
    ) {
    login_result_user_t *login_result_user_local_var = malloc(sizeof(login_result_user_t));
    if (!login_result_user_local_var) {
        return NULL;
    }
    login_result_user_local_var->id = id;
    login_result_user_local_var->name = name;
    login_result_user_local_var->label = label;
    login_result_user_local_var->email = email;
    login_result_user_local_var->cluster_administrator = cluster_administrator;
    login_result_user_local_var->agreed_to_terms = agreed_to_terms;
    login_result_user_local_var->federated_user_id = federated_user_id;
    login_result_user_local_var->intercom_hmac = intercom_hmac;
    login_result_user_local_var->misc = misc;

    login_result_user_local_var->_library_owned = 1;
    return login_result_user_local_var;
}

__attribute__((deprecated)) login_result_user_t *login_result_user_create(
    char *id,
    char *name,
    char *label,
    char *email,
    int cluster_administrator,
    char *agreed_to_terms,
    char *federated_user_id,
    char *intercom_hmac,
    object_t *misc
    ) {
    return login_result_user_create_internal (
        id,
        name,
        label,
        email,
        cluster_administrator,
        agreed_to_terms,
        federated_user_id,
        intercom_hmac,
        misc
        );
}

void login_result_user_free(login_result_user_t *login_result_user) {
    if(NULL == login_result_user){
        return ;
    }
    if(login_result_user->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "login_result_user_free");
        return ;
    }
    listEntry_t *listEntry;
    if (login_result_user->id) {
        free(login_result_user->id);
        login_result_user->id = NULL;
    }
    if (login_result_user->name) {
        free(login_result_user->name);
        login_result_user->name = NULL;
    }
    if (login_result_user->label) {
        free(login_result_user->label);
        login_result_user->label = NULL;
    }
    if (login_result_user->email) {
        free(login_result_user->email);
        login_result_user->email = NULL;
    }
    if (login_result_user->agreed_to_terms) {
        free(login_result_user->agreed_to_terms);
        login_result_user->agreed_to_terms = NULL;
    }
    if (login_result_user->federated_user_id) {
        free(login_result_user->federated_user_id);
        login_result_user->federated_user_id = NULL;
    }
    if (login_result_user->intercom_hmac) {
        free(login_result_user->intercom_hmac);
        login_result_user->intercom_hmac = NULL;
    }
    if (login_result_user->misc) {
        object_free(login_result_user->misc);
        login_result_user->misc = NULL;
    }
    free(login_result_user);
}

cJSON *login_result_user_convertToJSON(login_result_user_t *login_result_user) {
    cJSON *item = cJSON_CreateObject();

    // login_result_user->id
    if (!login_result_user->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", login_result_user->id) == NULL) {
    goto fail; //String
    }


    // login_result_user->name
    if(login_result_user->name) {
    if(cJSON_AddStringToObject(item, "name", login_result_user->name) == NULL) {
    goto fail; //String
    }
    }


    // login_result_user->label
    if(login_result_user->label) {
    if(cJSON_AddStringToObject(item, "label", login_result_user->label) == NULL) {
    goto fail; //String
    }
    }


    // login_result_user->email
    if(login_result_user->email) {
    if(cJSON_AddStringToObject(item, "email", login_result_user->email) == NULL) {
    goto fail; //String
    }
    }


    // login_result_user->cluster_administrator
    if (!login_result_user->cluster_administrator) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "clusterAdministrator", login_result_user->cluster_administrator) == NULL) {
    goto fail; //Bool
    }


    // login_result_user->agreed_to_terms
    if(login_result_user->agreed_to_terms) {
    if(cJSON_AddStringToObject(item, "agreedToTerms", login_result_user->agreed_to_terms) == NULL) {
    goto fail; //String
    }
    }


    // login_result_user->federated_user_id
    if(login_result_user->federated_user_id) {
    if(cJSON_AddStringToObject(item, "federatedUserId", login_result_user->federated_user_id) == NULL) {
    goto fail; //String
    }
    }


    // login_result_user->intercom_hmac
    if (!login_result_user->intercom_hmac) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "intercomHMAC", login_result_user->intercom_hmac) == NULL) {
    goto fail; //String
    }


    // login_result_user->misc
    if (!login_result_user->misc) {
        goto fail;
    }
    cJSON *misc_object = object_convertToJSON(login_result_user->misc);
    if(misc_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "misc", misc_object);
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

login_result_user_t *login_result_user_parseFromJSON(cJSON *login_result_userJSON){

    login_result_user_t *login_result_user_local_var = NULL;

    // login_result_user->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(login_result_userJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }

    // login_result_user->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(login_result_userJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // login_result_user->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(login_result_userJSON, "label");
    if (cJSON_IsNull(label)) {
        label = NULL;
    }
    if (label) { 
    if(!cJSON_IsString(label) && !cJSON_IsNull(label))
    {
    goto end; //String
    }
    }

    // login_result_user->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(login_result_userJSON, "email");
    if (cJSON_IsNull(email)) {
        email = NULL;
    }
    if (email) { 
    if(!cJSON_IsString(email) && !cJSON_IsNull(email))
    {
    goto end; //String
    }
    }

    // login_result_user->cluster_administrator
    cJSON *cluster_administrator = cJSON_GetObjectItemCaseSensitive(login_result_userJSON, "clusterAdministrator");
    if (cJSON_IsNull(cluster_administrator)) {
        cluster_administrator = NULL;
    }
    if (!cluster_administrator) {
        goto end;
    }

    
    if(!cJSON_IsBool(cluster_administrator))
    {
    goto end; //Bool
    }

    // login_result_user->agreed_to_terms
    cJSON *agreed_to_terms = cJSON_GetObjectItemCaseSensitive(login_result_userJSON, "agreedToTerms");
    if (cJSON_IsNull(agreed_to_terms)) {
        agreed_to_terms = NULL;
    }
    if (agreed_to_terms) { 
    if(!cJSON_IsString(agreed_to_terms) && !cJSON_IsNull(agreed_to_terms))
    {
    goto end; //String
    }
    }

    // login_result_user->federated_user_id
    cJSON *federated_user_id = cJSON_GetObjectItemCaseSensitive(login_result_userJSON, "federatedUserId");
    if (cJSON_IsNull(federated_user_id)) {
        federated_user_id = NULL;
    }
    if (federated_user_id) { 
    if(!cJSON_IsString(federated_user_id) && !cJSON_IsNull(federated_user_id))
    {
    goto end; //String
    }
    }

    // login_result_user->intercom_hmac
    cJSON *intercom_hmac = cJSON_GetObjectItemCaseSensitive(login_result_userJSON, "intercomHMAC");
    if (cJSON_IsNull(intercom_hmac)) {
        intercom_hmac = NULL;
    }
    if (!intercom_hmac) {
        goto end;
    }

    
    if(!cJSON_IsString(intercom_hmac))
    {
    goto end; //String
    }

    // login_result_user->misc
    cJSON *misc = cJSON_GetObjectItemCaseSensitive(login_result_userJSON, "misc");
    if (cJSON_IsNull(misc)) {
        misc = NULL;
    }
    if (!misc) {
        goto end;
    }

    object_t *misc_local_object = NULL;
    
    misc_local_object = object_parseFromJSON(misc); //object


    login_result_user_local_var = login_result_user_create_internal (
        strdup(id->valuestring),
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        label && !cJSON_IsNull(label) ? strdup(label->valuestring) : NULL,
        email && !cJSON_IsNull(email) ? strdup(email->valuestring) : NULL,
        cluster_administrator->valueint,
        agreed_to_terms && !cJSON_IsNull(agreed_to_terms) ? strdup(agreed_to_terms->valuestring) : NULL,
        federated_user_id && !cJSON_IsNull(federated_user_id) ? strdup(federated_user_id->valuestring) : NULL,
        strdup(intercom_hmac->valuestring),
        misc_local_object
        );

    return login_result_user_local_var;
end:
    return NULL;

}
