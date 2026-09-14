#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "saml_group_mapping.h"



static saml_group_mapping_t *saml_group_mapping_create_internal(
    char *group_name,
    char *role,
    char *team
    ) {
    saml_group_mapping_t *saml_group_mapping_local_var = malloc(sizeof(saml_group_mapping_t));
    if (!saml_group_mapping_local_var) {
        return NULL;
    }
    saml_group_mapping_local_var->group_name = group_name;
    saml_group_mapping_local_var->role = role;
    saml_group_mapping_local_var->team = team;

    saml_group_mapping_local_var->_library_owned = 1;
    return saml_group_mapping_local_var;
}

__attribute__((deprecated)) saml_group_mapping_t *saml_group_mapping_create(
    char *group_name,
    char *role,
    char *team
    ) {
    return saml_group_mapping_create_internal (
        group_name,
        role,
        team
        );
}

void saml_group_mapping_free(saml_group_mapping_t *saml_group_mapping) {
    if(NULL == saml_group_mapping){
        return ;
    }
    if(saml_group_mapping->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "saml_group_mapping_free");
        return ;
    }
    listEntry_t *listEntry;
    if (saml_group_mapping->group_name) {
        free(saml_group_mapping->group_name);
        saml_group_mapping->group_name = NULL;
    }
    if (saml_group_mapping->role) {
        free(saml_group_mapping->role);
        saml_group_mapping->role = NULL;
    }
    if (saml_group_mapping->team) {
        free(saml_group_mapping->team);
        saml_group_mapping->team = NULL;
    }
    free(saml_group_mapping);
}

cJSON *saml_group_mapping_convertToJSON(saml_group_mapping_t *saml_group_mapping) {
    cJSON *item = cJSON_CreateObject();

    // saml_group_mapping->group_name
    if (!saml_group_mapping->group_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "groupName", saml_group_mapping->group_name) == NULL) {
    goto fail; //String
    }


    // saml_group_mapping->role
    if (!saml_group_mapping->role) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "role", saml_group_mapping->role) == NULL) {
    goto fail; //String
    }


    // saml_group_mapping->team
    if (!saml_group_mapping->team) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "team", saml_group_mapping->team) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

saml_group_mapping_t *saml_group_mapping_parseFromJSON(cJSON *saml_group_mappingJSON){

    saml_group_mapping_t *saml_group_mapping_local_var = NULL;

    // saml_group_mapping->group_name
    cJSON *group_name = cJSON_GetObjectItemCaseSensitive(saml_group_mappingJSON, "groupName");
    if (cJSON_IsNull(group_name)) {
        group_name = NULL;
    }
    if (!group_name) {
        goto end;
    }

    
    if(!cJSON_IsString(group_name))
    {
    goto end; //String
    }

    // saml_group_mapping->role
    cJSON *role = cJSON_GetObjectItemCaseSensitive(saml_group_mappingJSON, "role");
    if (cJSON_IsNull(role)) {
        role = NULL;
    }
    if (!role) {
        goto end;
    }

    
    if(!cJSON_IsString(role))
    {
    goto end; //String
    }

    // saml_group_mapping->team
    cJSON *team = cJSON_GetObjectItemCaseSensitive(saml_group_mappingJSON, "team");
    if (cJSON_IsNull(team)) {
        team = NULL;
    }
    if (!team) {
        goto end;
    }

    
    if(!cJSON_IsString(team))
    {
    goto end; //String
    }


    saml_group_mapping_local_var = saml_group_mapping_create_internal (
        strdup(group_name->valuestring),
        strdup(role->valuestring),
        strdup(team->valuestring)
        );

    return saml_group_mapping_local_var;
end:
    return NULL;

}
