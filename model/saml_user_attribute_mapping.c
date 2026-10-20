#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "saml_user_attribute_mapping.h"



static saml_user_attribute_mapping_t *saml_user_attribute_mapping_create_internal(
    char *username,
    char *email,
    char *first_name,
    char *last_name,
    char *group
    ) {
    saml_user_attribute_mapping_t *saml_user_attribute_mapping_local_var = malloc(sizeof(saml_user_attribute_mapping_t));
    if (!saml_user_attribute_mapping_local_var) {
        return NULL;
    }
    saml_user_attribute_mapping_local_var->username = username;
    saml_user_attribute_mapping_local_var->email = email;
    saml_user_attribute_mapping_local_var->first_name = first_name;
    saml_user_attribute_mapping_local_var->last_name = last_name;
    saml_user_attribute_mapping_local_var->group = group;

    saml_user_attribute_mapping_local_var->_library_owned = 1;
    return saml_user_attribute_mapping_local_var;
}

__attribute__((deprecated)) saml_user_attribute_mapping_t *saml_user_attribute_mapping_create(
    char *username,
    char *email,
    char *first_name,
    char *last_name,
    char *group
    ) {
    return saml_user_attribute_mapping_create_internal (
        username,
        email,
        first_name,
        last_name,
        group
        );
}

void saml_user_attribute_mapping_free(saml_user_attribute_mapping_t *saml_user_attribute_mapping) {
    if(NULL == saml_user_attribute_mapping){
        return ;
    }
    if(saml_user_attribute_mapping->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "saml_user_attribute_mapping_free");
        return ;
    }
    listEntry_t *listEntry;
    if (saml_user_attribute_mapping->username) {
        free(saml_user_attribute_mapping->username);
        saml_user_attribute_mapping->username = NULL;
    }
    if (saml_user_attribute_mapping->email) {
        free(saml_user_attribute_mapping->email);
        saml_user_attribute_mapping->email = NULL;
    }
    if (saml_user_attribute_mapping->first_name) {
        free(saml_user_attribute_mapping->first_name);
        saml_user_attribute_mapping->first_name = NULL;
    }
    if (saml_user_attribute_mapping->last_name) {
        free(saml_user_attribute_mapping->last_name);
        saml_user_attribute_mapping->last_name = NULL;
    }
    if (saml_user_attribute_mapping->group) {
        free(saml_user_attribute_mapping->group);
        saml_user_attribute_mapping->group = NULL;
    }
    free(saml_user_attribute_mapping);
}

cJSON *saml_user_attribute_mapping_convertToJSON(saml_user_attribute_mapping_t *saml_user_attribute_mapping) {
    cJSON *item = cJSON_CreateObject();

    // saml_user_attribute_mapping->username
    if(saml_user_attribute_mapping->username) {
    if(cJSON_AddStringToObject(item, "username", saml_user_attribute_mapping->username) == NULL) {
    goto fail; //String
    }
    }


    // saml_user_attribute_mapping->email
    if (!saml_user_attribute_mapping->email) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "email", saml_user_attribute_mapping->email) == NULL) {
    goto fail; //String
    }


    // saml_user_attribute_mapping->first_name
    if (!saml_user_attribute_mapping->first_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "firstName", saml_user_attribute_mapping->first_name) == NULL) {
    goto fail; //String
    }


    // saml_user_attribute_mapping->last_name
    if (!saml_user_attribute_mapping->last_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "lastName", saml_user_attribute_mapping->last_name) == NULL) {
    goto fail; //String
    }


    // saml_user_attribute_mapping->group
    if (!saml_user_attribute_mapping->group) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "group", saml_user_attribute_mapping->group) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

saml_user_attribute_mapping_t *saml_user_attribute_mapping_parseFromJSON(cJSON *saml_user_attribute_mappingJSON){

    saml_user_attribute_mapping_t *saml_user_attribute_mapping_local_var = NULL;

    // saml_user_attribute_mapping->username
    cJSON *username = cJSON_GetObjectItemCaseSensitive(saml_user_attribute_mappingJSON, "username");
    if (cJSON_IsNull(username)) {
        username = NULL;
    }
    if (username) { 
    if(!cJSON_IsString(username) && !cJSON_IsNull(username))
    {
    goto end; //String
    }
    }

    // saml_user_attribute_mapping->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(saml_user_attribute_mappingJSON, "email");
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

    // saml_user_attribute_mapping->first_name
    cJSON *first_name = cJSON_GetObjectItemCaseSensitive(saml_user_attribute_mappingJSON, "firstName");
    if (cJSON_IsNull(first_name)) {
        first_name = NULL;
    }
    if (!first_name) {
        goto end;
    }

    
    if(!cJSON_IsString(first_name))
    {
    goto end; //String
    }

    // saml_user_attribute_mapping->last_name
    cJSON *last_name = cJSON_GetObjectItemCaseSensitive(saml_user_attribute_mappingJSON, "lastName");
    if (cJSON_IsNull(last_name)) {
        last_name = NULL;
    }
    if (!last_name) {
        goto end;
    }

    
    if(!cJSON_IsString(last_name))
    {
    goto end; //String
    }

    // saml_user_attribute_mapping->group
    cJSON *group = cJSON_GetObjectItemCaseSensitive(saml_user_attribute_mappingJSON, "group");
    if (cJSON_IsNull(group)) {
        group = NULL;
    }
    if (!group) {
        goto end;
    }

    
    if(!cJSON_IsString(group))
    {
    goto end; //String
    }


    saml_user_attribute_mapping_local_var = saml_user_attribute_mapping_create_internal (
        username && !cJSON_IsNull(username) ? strdup(username->valuestring) : NULL,
        strdup(email->valuestring),
        strdup(first_name->valuestring),
        strdup(last_name->valuestring),
        strdup(group->valuestring)
        );

    return saml_user_attribute_mapping_local_var;
end:
    return NULL;

}
