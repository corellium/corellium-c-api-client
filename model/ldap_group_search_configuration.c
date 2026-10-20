#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ldap_group_search_configuration.h"



static ldap_group_search_configuration_t *ldap_group_search_configuration_create_internal(
    char *group_base_dn,
    char *group_search_filter,
    char *team_id,
    char *role
    ) {
    ldap_group_search_configuration_t *ldap_group_search_configuration_local_var = malloc(sizeof(ldap_group_search_configuration_t));
    if (!ldap_group_search_configuration_local_var) {
        return NULL;
    }
    ldap_group_search_configuration_local_var->group_base_dn = group_base_dn;
    ldap_group_search_configuration_local_var->group_search_filter = group_search_filter;
    ldap_group_search_configuration_local_var->team_id = team_id;
    ldap_group_search_configuration_local_var->role = role;

    ldap_group_search_configuration_local_var->_library_owned = 1;
    return ldap_group_search_configuration_local_var;
}

__attribute__((deprecated)) ldap_group_search_configuration_t *ldap_group_search_configuration_create(
    char *group_base_dn,
    char *group_search_filter,
    char *team_id,
    char *role
    ) {
    return ldap_group_search_configuration_create_internal (
        group_base_dn,
        group_search_filter,
        team_id,
        role
        );
}

void ldap_group_search_configuration_free(ldap_group_search_configuration_t *ldap_group_search_configuration) {
    if(NULL == ldap_group_search_configuration){
        return ;
    }
    if(ldap_group_search_configuration->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ldap_group_search_configuration_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ldap_group_search_configuration->group_base_dn) {
        free(ldap_group_search_configuration->group_base_dn);
        ldap_group_search_configuration->group_base_dn = NULL;
    }
    if (ldap_group_search_configuration->group_search_filter) {
        free(ldap_group_search_configuration->group_search_filter);
        ldap_group_search_configuration->group_search_filter = NULL;
    }
    if (ldap_group_search_configuration->team_id) {
        free(ldap_group_search_configuration->team_id);
        ldap_group_search_configuration->team_id = NULL;
    }
    if (ldap_group_search_configuration->role) {
        free(ldap_group_search_configuration->role);
        ldap_group_search_configuration->role = NULL;
    }
    free(ldap_group_search_configuration);
}

cJSON *ldap_group_search_configuration_convertToJSON(ldap_group_search_configuration_t *ldap_group_search_configuration) {
    cJSON *item = cJSON_CreateObject();

    // ldap_group_search_configuration->group_base_dn
    if (!ldap_group_search_configuration->group_base_dn) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "groupBaseDn", ldap_group_search_configuration->group_base_dn) == NULL) {
    goto fail; //String
    }


    // ldap_group_search_configuration->group_search_filter
    if(ldap_group_search_configuration->group_search_filter) {
    if(cJSON_AddStringToObject(item, "groupSearchFilter", ldap_group_search_configuration->group_search_filter) == NULL) {
    goto fail; //String
    }
    }


    // ldap_group_search_configuration->team_id
    if (!ldap_group_search_configuration->team_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "teamId", ldap_group_search_configuration->team_id) == NULL) {
    goto fail; //String
    }


    // ldap_group_search_configuration->role
    if(ldap_group_search_configuration->role) {
    if(cJSON_AddStringToObject(item, "role", ldap_group_search_configuration->role) == NULL) {
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

ldap_group_search_configuration_t *ldap_group_search_configuration_parseFromJSON(cJSON *ldap_group_search_configurationJSON){

    ldap_group_search_configuration_t *ldap_group_search_configuration_local_var = NULL;

    // ldap_group_search_configuration->group_base_dn
    cJSON *group_base_dn = cJSON_GetObjectItemCaseSensitive(ldap_group_search_configurationJSON, "groupBaseDn");
    if (cJSON_IsNull(group_base_dn)) {
        group_base_dn = NULL;
    }
    if (!group_base_dn) {
        goto end;
    }

    
    if(!cJSON_IsString(group_base_dn))
    {
    goto end; //String
    }

    // ldap_group_search_configuration->group_search_filter
    cJSON *group_search_filter = cJSON_GetObjectItemCaseSensitive(ldap_group_search_configurationJSON, "groupSearchFilter");
    if (cJSON_IsNull(group_search_filter)) {
        group_search_filter = NULL;
    }
    if (group_search_filter) { 
    if(!cJSON_IsString(group_search_filter) && !cJSON_IsNull(group_search_filter))
    {
    goto end; //String
    }
    }

    // ldap_group_search_configuration->team_id
    cJSON *team_id = cJSON_GetObjectItemCaseSensitive(ldap_group_search_configurationJSON, "teamId");
    if (cJSON_IsNull(team_id)) {
        team_id = NULL;
    }
    if (!team_id) {
        goto end;
    }

    
    if(!cJSON_IsString(team_id))
    {
    goto end; //String
    }

    // ldap_group_search_configuration->role
    cJSON *role = cJSON_GetObjectItemCaseSensitive(ldap_group_search_configurationJSON, "role");
    if (cJSON_IsNull(role)) {
        role = NULL;
    }
    if (role) { 
    if(!cJSON_IsString(role) && !cJSON_IsNull(role))
    {
    goto end; //String
    }
    }


    ldap_group_search_configuration_local_var = ldap_group_search_configuration_create_internal (
        strdup(group_base_dn->valuestring),
        group_search_filter && !cJSON_IsNull(group_search_filter) ? strdup(group_search_filter->valuestring) : NULL,
        strdup(team_id->valuestring),
        role && !cJSON_IsNull(role) ? strdup(role->valuestring) : NULL
        );

    return ldap_group_search_configuration_local_var;
end:
    return NULL;

}
