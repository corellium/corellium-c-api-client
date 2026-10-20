#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "saml_service_provider_config.h"



static saml_service_provider_config_t *saml_service_provider_config_create_internal(
    char *sso_url,
    char *public_certificate,
    char *audience_url
    ) {
    saml_service_provider_config_t *saml_service_provider_config_local_var = malloc(sizeof(saml_service_provider_config_t));
    if (!saml_service_provider_config_local_var) {
        return NULL;
    }
    saml_service_provider_config_local_var->sso_url = sso_url;
    saml_service_provider_config_local_var->public_certificate = public_certificate;
    saml_service_provider_config_local_var->audience_url = audience_url;

    saml_service_provider_config_local_var->_library_owned = 1;
    return saml_service_provider_config_local_var;
}

__attribute__((deprecated)) saml_service_provider_config_t *saml_service_provider_config_create(
    char *sso_url,
    char *public_certificate,
    char *audience_url
    ) {
    return saml_service_provider_config_create_internal (
        sso_url,
        public_certificate,
        audience_url
        );
}

void saml_service_provider_config_free(saml_service_provider_config_t *saml_service_provider_config) {
    if(NULL == saml_service_provider_config){
        return ;
    }
    if(saml_service_provider_config->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "saml_service_provider_config_free");
        return ;
    }
    listEntry_t *listEntry;
    if (saml_service_provider_config->sso_url) {
        free(saml_service_provider_config->sso_url);
        saml_service_provider_config->sso_url = NULL;
    }
    if (saml_service_provider_config->public_certificate) {
        free(saml_service_provider_config->public_certificate);
        saml_service_provider_config->public_certificate = NULL;
    }
    if (saml_service_provider_config->audience_url) {
        free(saml_service_provider_config->audience_url);
        saml_service_provider_config->audience_url = NULL;
    }
    free(saml_service_provider_config);
}

cJSON *saml_service_provider_config_convertToJSON(saml_service_provider_config_t *saml_service_provider_config) {
    cJSON *item = cJSON_CreateObject();

    // saml_service_provider_config->sso_url
    if (!saml_service_provider_config->sso_url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "ssoUrl", saml_service_provider_config->sso_url) == NULL) {
    goto fail; //String
    }


    // saml_service_provider_config->public_certificate
    if (!saml_service_provider_config->public_certificate) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "publicCertificate", saml_service_provider_config->public_certificate) == NULL) {
    goto fail; //String
    }


    // saml_service_provider_config->audience_url
    if (!saml_service_provider_config->audience_url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "audienceUrl", saml_service_provider_config->audience_url) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

saml_service_provider_config_t *saml_service_provider_config_parseFromJSON(cJSON *saml_service_provider_configJSON){

    saml_service_provider_config_t *saml_service_provider_config_local_var = NULL;

    // saml_service_provider_config->sso_url
    cJSON *sso_url = cJSON_GetObjectItemCaseSensitive(saml_service_provider_configJSON, "ssoUrl");
    if (cJSON_IsNull(sso_url)) {
        sso_url = NULL;
    }
    if (!sso_url) {
        goto end;
    }

    
    if(!cJSON_IsString(sso_url))
    {
    goto end; //String
    }

    // saml_service_provider_config->public_certificate
    cJSON *public_certificate = cJSON_GetObjectItemCaseSensitive(saml_service_provider_configJSON, "publicCertificate");
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

    // saml_service_provider_config->audience_url
    cJSON *audience_url = cJSON_GetObjectItemCaseSensitive(saml_service_provider_configJSON, "audienceUrl");
    if (cJSON_IsNull(audience_url)) {
        audience_url = NULL;
    }
    if (!audience_url) {
        goto end;
    }

    
    if(!cJSON_IsString(audience_url))
    {
    goto end; //String
    }


    saml_service_provider_config_local_var = saml_service_provider_config_create_internal (
        strdup(sso_url->valuestring),
        strdup(public_certificate->valuestring),
        strdup(audience_url->valuestring)
        );

    return saml_service_provider_config_local_var;
end:
    return NULL;

}
