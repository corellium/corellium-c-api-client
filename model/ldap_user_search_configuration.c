#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ldap_user_search_configuration.h"



static ldap_user_search_configuration_t *ldap_user_search_configuration_create_internal(
    char *base_dn,
    char *user_search_base,
    char *user_search_filter
    ) {
    ldap_user_search_configuration_t *ldap_user_search_configuration_local_var = malloc(sizeof(ldap_user_search_configuration_t));
    if (!ldap_user_search_configuration_local_var) {
        return NULL;
    }
    ldap_user_search_configuration_local_var->base_dn = base_dn;
    ldap_user_search_configuration_local_var->user_search_base = user_search_base;
    ldap_user_search_configuration_local_var->user_search_filter = user_search_filter;

    ldap_user_search_configuration_local_var->_library_owned = 1;
    return ldap_user_search_configuration_local_var;
}

__attribute__((deprecated)) ldap_user_search_configuration_t *ldap_user_search_configuration_create(
    char *base_dn,
    char *user_search_base,
    char *user_search_filter
    ) {
    return ldap_user_search_configuration_create_internal (
        base_dn,
        user_search_base,
        user_search_filter
        );
}

void ldap_user_search_configuration_free(ldap_user_search_configuration_t *ldap_user_search_configuration) {
    if(NULL == ldap_user_search_configuration){
        return ;
    }
    if(ldap_user_search_configuration->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ldap_user_search_configuration_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ldap_user_search_configuration->base_dn) {
        free(ldap_user_search_configuration->base_dn);
        ldap_user_search_configuration->base_dn = NULL;
    }
    if (ldap_user_search_configuration->user_search_base) {
        free(ldap_user_search_configuration->user_search_base);
        ldap_user_search_configuration->user_search_base = NULL;
    }
    if (ldap_user_search_configuration->user_search_filter) {
        free(ldap_user_search_configuration->user_search_filter);
        ldap_user_search_configuration->user_search_filter = NULL;
    }
    free(ldap_user_search_configuration);
}

cJSON *ldap_user_search_configuration_convertToJSON(ldap_user_search_configuration_t *ldap_user_search_configuration) {
    cJSON *item = cJSON_CreateObject();

    // ldap_user_search_configuration->base_dn
    if (!ldap_user_search_configuration->base_dn) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "baseDn", ldap_user_search_configuration->base_dn) == NULL) {
    goto fail; //String
    }


    // ldap_user_search_configuration->user_search_base
    if(ldap_user_search_configuration->user_search_base) {
    if(cJSON_AddStringToObject(item, "userSearchBase", ldap_user_search_configuration->user_search_base) == NULL) {
    goto fail; //String
    }
    }


    // ldap_user_search_configuration->user_search_filter
    if(ldap_user_search_configuration->user_search_filter) {
    if(cJSON_AddStringToObject(item, "userSearchFilter", ldap_user_search_configuration->user_search_filter) == NULL) {
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

ldap_user_search_configuration_t *ldap_user_search_configuration_parseFromJSON(cJSON *ldap_user_search_configurationJSON){

    ldap_user_search_configuration_t *ldap_user_search_configuration_local_var = NULL;

    // ldap_user_search_configuration->base_dn
    cJSON *base_dn = cJSON_GetObjectItemCaseSensitive(ldap_user_search_configurationJSON, "baseDn");
    if (cJSON_IsNull(base_dn)) {
        base_dn = NULL;
    }
    if (!base_dn) {
        goto end;
    }

    
    if(!cJSON_IsString(base_dn))
    {
    goto end; //String
    }

    // ldap_user_search_configuration->user_search_base
    cJSON *user_search_base = cJSON_GetObjectItemCaseSensitive(ldap_user_search_configurationJSON, "userSearchBase");
    if (cJSON_IsNull(user_search_base)) {
        user_search_base = NULL;
    }
    if (user_search_base) { 
    if(!cJSON_IsString(user_search_base) && !cJSON_IsNull(user_search_base))
    {
    goto end; //String
    }
    }

    // ldap_user_search_configuration->user_search_filter
    cJSON *user_search_filter = cJSON_GetObjectItemCaseSensitive(ldap_user_search_configurationJSON, "userSearchFilter");
    if (cJSON_IsNull(user_search_filter)) {
        user_search_filter = NULL;
    }
    if (user_search_filter) { 
    if(!cJSON_IsString(user_search_filter) && !cJSON_IsNull(user_search_filter))
    {
    goto end; //String
    }
    }


    ldap_user_search_configuration_local_var = ldap_user_search_configuration_create_internal (
        strdup(base_dn->valuestring),
        user_search_base && !cJSON_IsNull(user_search_base) ? strdup(user_search_base->valuestring) : NULL,
        user_search_filter && !cJSON_IsNull(user_search_filter) ? strdup(user_search_filter->valuestring) : NULL
        );

    return ldap_user_search_configuration_local_var;
end:
    return NULL;

}
