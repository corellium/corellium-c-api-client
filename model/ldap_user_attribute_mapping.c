#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ldap_user_attribute_mapping.h"



static ldap_user_attribute_mapping_t *ldap_user_attribute_mapping_create_internal(
    char *username_attribute,
    char *email_attribute,
    char *first_name_attribute,
    char *last_name_attribute
    ) {
    ldap_user_attribute_mapping_t *ldap_user_attribute_mapping_local_var = malloc(sizeof(ldap_user_attribute_mapping_t));
    if (!ldap_user_attribute_mapping_local_var) {
        return NULL;
    }
    ldap_user_attribute_mapping_local_var->username_attribute = username_attribute;
    ldap_user_attribute_mapping_local_var->email_attribute = email_attribute;
    ldap_user_attribute_mapping_local_var->first_name_attribute = first_name_attribute;
    ldap_user_attribute_mapping_local_var->last_name_attribute = last_name_attribute;

    ldap_user_attribute_mapping_local_var->_library_owned = 1;
    return ldap_user_attribute_mapping_local_var;
}

__attribute__((deprecated)) ldap_user_attribute_mapping_t *ldap_user_attribute_mapping_create(
    char *username_attribute,
    char *email_attribute,
    char *first_name_attribute,
    char *last_name_attribute
    ) {
    return ldap_user_attribute_mapping_create_internal (
        username_attribute,
        email_attribute,
        first_name_attribute,
        last_name_attribute
        );
}

void ldap_user_attribute_mapping_free(ldap_user_attribute_mapping_t *ldap_user_attribute_mapping) {
    if(NULL == ldap_user_attribute_mapping){
        return ;
    }
    if(ldap_user_attribute_mapping->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ldap_user_attribute_mapping_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ldap_user_attribute_mapping->username_attribute) {
        free(ldap_user_attribute_mapping->username_attribute);
        ldap_user_attribute_mapping->username_attribute = NULL;
    }
    if (ldap_user_attribute_mapping->email_attribute) {
        free(ldap_user_attribute_mapping->email_attribute);
        ldap_user_attribute_mapping->email_attribute = NULL;
    }
    if (ldap_user_attribute_mapping->first_name_attribute) {
        free(ldap_user_attribute_mapping->first_name_attribute);
        ldap_user_attribute_mapping->first_name_attribute = NULL;
    }
    if (ldap_user_attribute_mapping->last_name_attribute) {
        free(ldap_user_attribute_mapping->last_name_attribute);
        ldap_user_attribute_mapping->last_name_attribute = NULL;
    }
    free(ldap_user_attribute_mapping);
}

cJSON *ldap_user_attribute_mapping_convertToJSON(ldap_user_attribute_mapping_t *ldap_user_attribute_mapping) {
    cJSON *item = cJSON_CreateObject();

    // ldap_user_attribute_mapping->username_attribute
    if(ldap_user_attribute_mapping->username_attribute) {
    if(cJSON_AddStringToObject(item, "usernameAttribute", ldap_user_attribute_mapping->username_attribute) == NULL) {
    goto fail; //String
    }
    }


    // ldap_user_attribute_mapping->email_attribute
    if(ldap_user_attribute_mapping->email_attribute) {
    if(cJSON_AddStringToObject(item, "emailAttribute", ldap_user_attribute_mapping->email_attribute) == NULL) {
    goto fail; //String
    }
    }


    // ldap_user_attribute_mapping->first_name_attribute
    if(ldap_user_attribute_mapping->first_name_attribute) {
    if(cJSON_AddStringToObject(item, "firstNameAttribute", ldap_user_attribute_mapping->first_name_attribute) == NULL) {
    goto fail; //String
    }
    }


    // ldap_user_attribute_mapping->last_name_attribute
    if(ldap_user_attribute_mapping->last_name_attribute) {
    if(cJSON_AddStringToObject(item, "lastNameAttribute", ldap_user_attribute_mapping->last_name_attribute) == NULL) {
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

ldap_user_attribute_mapping_t *ldap_user_attribute_mapping_parseFromJSON(cJSON *ldap_user_attribute_mappingJSON){

    ldap_user_attribute_mapping_t *ldap_user_attribute_mapping_local_var = NULL;

    // ldap_user_attribute_mapping->username_attribute
    cJSON *username_attribute = cJSON_GetObjectItemCaseSensitive(ldap_user_attribute_mappingJSON, "usernameAttribute");
    if (cJSON_IsNull(username_attribute)) {
        username_attribute = NULL;
    }
    if (username_attribute) { 
    if(!cJSON_IsString(username_attribute) && !cJSON_IsNull(username_attribute))
    {
    goto end; //String
    }
    }

    // ldap_user_attribute_mapping->email_attribute
    cJSON *email_attribute = cJSON_GetObjectItemCaseSensitive(ldap_user_attribute_mappingJSON, "emailAttribute");
    if (cJSON_IsNull(email_attribute)) {
        email_attribute = NULL;
    }
    if (email_attribute) { 
    if(!cJSON_IsString(email_attribute) && !cJSON_IsNull(email_attribute))
    {
    goto end; //String
    }
    }

    // ldap_user_attribute_mapping->first_name_attribute
    cJSON *first_name_attribute = cJSON_GetObjectItemCaseSensitive(ldap_user_attribute_mappingJSON, "firstNameAttribute");
    if (cJSON_IsNull(first_name_attribute)) {
        first_name_attribute = NULL;
    }
    if (first_name_attribute) { 
    if(!cJSON_IsString(first_name_attribute) && !cJSON_IsNull(first_name_attribute))
    {
    goto end; //String
    }
    }

    // ldap_user_attribute_mapping->last_name_attribute
    cJSON *last_name_attribute = cJSON_GetObjectItemCaseSensitive(ldap_user_attribute_mappingJSON, "lastNameAttribute");
    if (cJSON_IsNull(last_name_attribute)) {
        last_name_attribute = NULL;
    }
    if (last_name_attribute) { 
    if(!cJSON_IsString(last_name_attribute) && !cJSON_IsNull(last_name_attribute))
    {
    goto end; //String
    }
    }


    ldap_user_attribute_mapping_local_var = ldap_user_attribute_mapping_create_internal (
        username_attribute && !cJSON_IsNull(username_attribute) ? strdup(username_attribute->valuestring) : NULL,
        email_attribute && !cJSON_IsNull(email_attribute) ? strdup(email_attribute->valuestring) : NULL,
        first_name_attribute && !cJSON_IsNull(first_name_attribute) ? strdup(first_name_attribute->valuestring) : NULL,
        last_name_attribute && !cJSON_IsNull(last_name_attribute) ? strdup(last_name_attribute->valuestring) : NULL
        );

    return ldap_user_attribute_mapping_local_var;
end:
    return NULL;

}
