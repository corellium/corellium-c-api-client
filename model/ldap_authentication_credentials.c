#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ldap_authentication_credentials.h"



static ldap_authentication_credentials_t *ldap_authentication_credentials_create_internal(
    char *bind_dn,
    char *bind_password
    ) {
    ldap_authentication_credentials_t *ldap_authentication_credentials_local_var = malloc(sizeof(ldap_authentication_credentials_t));
    if (!ldap_authentication_credentials_local_var) {
        return NULL;
    }
    ldap_authentication_credentials_local_var->bind_dn = bind_dn;
    ldap_authentication_credentials_local_var->bind_password = bind_password;

    ldap_authentication_credentials_local_var->_library_owned = 1;
    return ldap_authentication_credentials_local_var;
}

__attribute__((deprecated)) ldap_authentication_credentials_t *ldap_authentication_credentials_create(
    char *bind_dn,
    char *bind_password
    ) {
    return ldap_authentication_credentials_create_internal (
        bind_dn,
        bind_password
        );
}

void ldap_authentication_credentials_free(ldap_authentication_credentials_t *ldap_authentication_credentials) {
    if(NULL == ldap_authentication_credentials){
        return ;
    }
    if(ldap_authentication_credentials->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ldap_authentication_credentials_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ldap_authentication_credentials->bind_dn) {
        free(ldap_authentication_credentials->bind_dn);
        ldap_authentication_credentials->bind_dn = NULL;
    }
    if (ldap_authentication_credentials->bind_password) {
        free(ldap_authentication_credentials->bind_password);
        ldap_authentication_credentials->bind_password = NULL;
    }
    free(ldap_authentication_credentials);
}

cJSON *ldap_authentication_credentials_convertToJSON(ldap_authentication_credentials_t *ldap_authentication_credentials) {
    cJSON *item = cJSON_CreateObject();

    // ldap_authentication_credentials->bind_dn
    if (!ldap_authentication_credentials->bind_dn) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "bindDn", ldap_authentication_credentials->bind_dn) == NULL) {
    goto fail; //String
    }


    // ldap_authentication_credentials->bind_password
    if (!ldap_authentication_credentials->bind_password) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "bindPassword", ldap_authentication_credentials->bind_password) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ldap_authentication_credentials_t *ldap_authentication_credentials_parseFromJSON(cJSON *ldap_authentication_credentialsJSON){

    ldap_authentication_credentials_t *ldap_authentication_credentials_local_var = NULL;

    // ldap_authentication_credentials->bind_dn
    cJSON *bind_dn = cJSON_GetObjectItemCaseSensitive(ldap_authentication_credentialsJSON, "bindDn");
    if (cJSON_IsNull(bind_dn)) {
        bind_dn = NULL;
    }
    if (!bind_dn) {
        goto end;
    }

    
    if(!cJSON_IsString(bind_dn))
    {
    goto end; //String
    }

    // ldap_authentication_credentials->bind_password
    cJSON *bind_password = cJSON_GetObjectItemCaseSensitive(ldap_authentication_credentialsJSON, "bindPassword");
    if (cJSON_IsNull(bind_password)) {
        bind_password = NULL;
    }
    if (!bind_password) {
        goto end;
    }

    
    if(!cJSON_IsString(bind_password))
    {
    goto end; //String
    }


    ldap_authentication_credentials_local_var = ldap_authentication_credentials_create_internal (
        strdup(bind_dn->valuestring),
        strdup(bind_password->valuestring)
        );

    return ldap_authentication_credentials_local_var;
end:
    return NULL;

}
