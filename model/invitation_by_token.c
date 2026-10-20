#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "invitation_by_token.h"



static invitation_by_token_t *invitation_by_token_create_internal(
    char *id,
    char *email,
    char *domain,
    char *display_name,
    int terms_agreement_required,
    invite_settings_t *settings
    ) {
    invitation_by_token_t *invitation_by_token_local_var = malloc(sizeof(invitation_by_token_t));
    if (!invitation_by_token_local_var) {
        return NULL;
    }
    invitation_by_token_local_var->id = id;
    invitation_by_token_local_var->email = email;
    invitation_by_token_local_var->domain = domain;
    invitation_by_token_local_var->display_name = display_name;
    invitation_by_token_local_var->terms_agreement_required = terms_agreement_required;
    invitation_by_token_local_var->settings = settings;

    invitation_by_token_local_var->_library_owned = 1;
    return invitation_by_token_local_var;
}

__attribute__((deprecated)) invitation_by_token_t *invitation_by_token_create(
    char *id,
    char *email,
    char *domain,
    char *display_name,
    int terms_agreement_required,
    invite_settings_t *settings
    ) {
    return invitation_by_token_create_internal (
        id,
        email,
        domain,
        display_name,
        terms_agreement_required,
        settings
        );
}

void invitation_by_token_free(invitation_by_token_t *invitation_by_token) {
    if(NULL == invitation_by_token){
        return ;
    }
    if(invitation_by_token->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "invitation_by_token_free");
        return ;
    }
    listEntry_t *listEntry;
    if (invitation_by_token->id) {
        free(invitation_by_token->id);
        invitation_by_token->id = NULL;
    }
    if (invitation_by_token->email) {
        free(invitation_by_token->email);
        invitation_by_token->email = NULL;
    }
    if (invitation_by_token->domain) {
        free(invitation_by_token->domain);
        invitation_by_token->domain = NULL;
    }
    if (invitation_by_token->display_name) {
        free(invitation_by_token->display_name);
        invitation_by_token->display_name = NULL;
    }
    if (invitation_by_token->settings) {
        invite_settings_free(invitation_by_token->settings);
        invitation_by_token->settings = NULL;
    }
    free(invitation_by_token);
}

cJSON *invitation_by_token_convertToJSON(invitation_by_token_t *invitation_by_token) {
    cJSON *item = cJSON_CreateObject();

    // invitation_by_token->id
    if (!invitation_by_token->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", invitation_by_token->id) == NULL) {
    goto fail; //String
    }


    // invitation_by_token->email
    if (!invitation_by_token->email) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "email", invitation_by_token->email) == NULL) {
    goto fail; //String
    }


    // invitation_by_token->domain
    if (!invitation_by_token->domain) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "domain", invitation_by_token->domain) == NULL) {
    goto fail; //String
    }


    // invitation_by_token->display_name
    if (!invitation_by_token->display_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "displayName", invitation_by_token->display_name) == NULL) {
    goto fail; //String
    }


    // invitation_by_token->terms_agreement_required
    if (!invitation_by_token->terms_agreement_required) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "termsAgreementRequired", invitation_by_token->terms_agreement_required) == NULL) {
    goto fail; //Bool
    }


    // invitation_by_token->settings
    if (!invitation_by_token->settings) {
        goto fail;
    }
    cJSON *settings_local_JSON = invite_settings_convertToJSON(invitation_by_token->settings);
    if(settings_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "settings", settings_local_JSON);
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

invitation_by_token_t *invitation_by_token_parseFromJSON(cJSON *invitation_by_tokenJSON){

    invitation_by_token_t *invitation_by_token_local_var = NULL;

    // define the local variable for invitation_by_token->settings
    invite_settings_t *settings_local_nonprim = NULL;

    // invitation_by_token->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(invitation_by_tokenJSON, "id");
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

    // invitation_by_token->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(invitation_by_tokenJSON, "email");
    if (cJSON_IsNull(email)) {
        email = NULL;
    }
    if (!email) {
        goto end;
    }

    
    if(!cJSON_IsString(email))
    {
    goto end; //String
    }

    // invitation_by_token->domain
    cJSON *domain = cJSON_GetObjectItemCaseSensitive(invitation_by_tokenJSON, "domain");
    if (cJSON_IsNull(domain)) {
        domain = NULL;
    }
    if (!domain) {
        goto end;
    }

    
    if(!cJSON_IsString(domain))
    {
    goto end; //String
    }

    // invitation_by_token->display_name
    cJSON *display_name = cJSON_GetObjectItemCaseSensitive(invitation_by_tokenJSON, "displayName");
    if (cJSON_IsNull(display_name)) {
        display_name = NULL;
    }
    if (!display_name) {
        goto end;
    }

    
    if(!cJSON_IsString(display_name))
    {
    goto end; //String
    }

    // invitation_by_token->terms_agreement_required
    cJSON *terms_agreement_required = cJSON_GetObjectItemCaseSensitive(invitation_by_tokenJSON, "termsAgreementRequired");
    if (cJSON_IsNull(terms_agreement_required)) {
        terms_agreement_required = NULL;
    }
    if (!terms_agreement_required) {
        goto end;
    }

    
    if(!cJSON_IsBool(terms_agreement_required))
    {
    goto end; //Bool
    }

    // invitation_by_token->settings
    cJSON *settings = cJSON_GetObjectItemCaseSensitive(invitation_by_tokenJSON, "settings");
    if (cJSON_IsNull(settings)) {
        settings = NULL;
    }
    if (!settings) {
        goto end;
    }

    
    settings_local_nonprim = invite_settings_parseFromJSON(settings); //nonprimitive


    invitation_by_token_local_var = invitation_by_token_create_internal (
        strdup(id->valuestring),
        strdup(email->valuestring),
        strdup(domain->valuestring),
        strdup(display_name->valuestring),
        terms_agreement_required->valueint,
        settings_local_nonprim
        );

    return invitation_by_token_local_var;
end:
    if (settings_local_nonprim) {
        invite_settings_free(settings_local_nonprim);
        settings_local_nonprim = NULL;
    }
    return NULL;

}
