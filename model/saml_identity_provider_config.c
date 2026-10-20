#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "saml_identity_provider_config.h"



static saml_identity_provider_config_t *saml_identity_provider_config_create_internal(
    char *login_url,
    char *public_certificate,
    char *issuer_url,
    char *logout_url
    ) {
    saml_identity_provider_config_t *saml_identity_provider_config_local_var = malloc(sizeof(saml_identity_provider_config_t));
    if (!saml_identity_provider_config_local_var) {
        return NULL;
    }
    saml_identity_provider_config_local_var->login_url = login_url;
    saml_identity_provider_config_local_var->public_certificate = public_certificate;
    saml_identity_provider_config_local_var->issuer_url = issuer_url;
    saml_identity_provider_config_local_var->logout_url = logout_url;

    saml_identity_provider_config_local_var->_library_owned = 1;
    return saml_identity_provider_config_local_var;
}

__attribute__((deprecated)) saml_identity_provider_config_t *saml_identity_provider_config_create(
    char *login_url,
    char *public_certificate,
    char *issuer_url,
    char *logout_url
    ) {
    return saml_identity_provider_config_create_internal (
        login_url,
        public_certificate,
        issuer_url,
        logout_url
        );
}

void saml_identity_provider_config_free(saml_identity_provider_config_t *saml_identity_provider_config) {
    if(NULL == saml_identity_provider_config){
        return ;
    }
    if(saml_identity_provider_config->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "saml_identity_provider_config_free");
        return ;
    }
    listEntry_t *listEntry;
    if (saml_identity_provider_config->login_url) {
        free(saml_identity_provider_config->login_url);
        saml_identity_provider_config->login_url = NULL;
    }
    if (saml_identity_provider_config->public_certificate) {
        free(saml_identity_provider_config->public_certificate);
        saml_identity_provider_config->public_certificate = NULL;
    }
    if (saml_identity_provider_config->issuer_url) {
        free(saml_identity_provider_config->issuer_url);
        saml_identity_provider_config->issuer_url = NULL;
    }
    if (saml_identity_provider_config->logout_url) {
        free(saml_identity_provider_config->logout_url);
        saml_identity_provider_config->logout_url = NULL;
    }
    free(saml_identity_provider_config);
}

cJSON *saml_identity_provider_config_convertToJSON(saml_identity_provider_config_t *saml_identity_provider_config) {
    cJSON *item = cJSON_CreateObject();

    // saml_identity_provider_config->login_url
    if (!saml_identity_provider_config->login_url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "loginUrl", saml_identity_provider_config->login_url) == NULL) {
    goto fail; //String
    }


    // saml_identity_provider_config->public_certificate
    if (!saml_identity_provider_config->public_certificate) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "publicCertificate", saml_identity_provider_config->public_certificate) == NULL) {
    goto fail; //String
    }


    // saml_identity_provider_config->issuer_url
    if (!saml_identity_provider_config->issuer_url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "issuerUrl", saml_identity_provider_config->issuer_url) == NULL) {
    goto fail; //String
    }


    // saml_identity_provider_config->logout_url
    if(saml_identity_provider_config->logout_url) {
    if(cJSON_AddStringToObject(item, "logoutUrl", saml_identity_provider_config->logout_url) == NULL) {
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

saml_identity_provider_config_t *saml_identity_provider_config_parseFromJSON(cJSON *saml_identity_provider_configJSON){

    saml_identity_provider_config_t *saml_identity_provider_config_local_var = NULL;

    // saml_identity_provider_config->login_url
    cJSON *login_url = cJSON_GetObjectItemCaseSensitive(saml_identity_provider_configJSON, "loginUrl");
    if (cJSON_IsNull(login_url)) {
        login_url = NULL;
    }
    if (!login_url) {
        goto end;
    }

    
    if(!cJSON_IsString(login_url))
    {
    goto end; //String
    }

    // saml_identity_provider_config->public_certificate
    cJSON *public_certificate = cJSON_GetObjectItemCaseSensitive(saml_identity_provider_configJSON, "publicCertificate");
    if (cJSON_IsNull(public_certificate)) {
        public_certificate = NULL;
    }
    if (!public_certificate) {
        goto end;
    }

    
    if(!cJSON_IsString(public_certificate))
    {
    goto end; //String
    }

    // saml_identity_provider_config->issuer_url
    cJSON *issuer_url = cJSON_GetObjectItemCaseSensitive(saml_identity_provider_configJSON, "issuerUrl");
    if (cJSON_IsNull(issuer_url)) {
        issuer_url = NULL;
    }
    if (!issuer_url) {
        goto end;
    }

    
    if(!cJSON_IsString(issuer_url))
    {
    goto end; //String
    }

    // saml_identity_provider_config->logout_url
    cJSON *logout_url = cJSON_GetObjectItemCaseSensitive(saml_identity_provider_configJSON, "logoutUrl");
    if (cJSON_IsNull(logout_url)) {
        logout_url = NULL;
    }
    if (logout_url) { 
    if(!cJSON_IsString(logout_url) && !cJSON_IsNull(logout_url))
    {
    goto end; //String
    }
    }


    saml_identity_provider_config_local_var = saml_identity_provider_config_create_internal (
        strdup(login_url->valuestring),
        strdup(public_certificate->valuestring),
        strdup(issuer_url->valuestring),
        logout_url && !cJSON_IsNull(logout_url) ? strdup(logout_url->valuestring) : NULL
        );

    return saml_identity_provider_config_local_var;
end:
    return NULL;

}
