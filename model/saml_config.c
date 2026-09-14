#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "saml_config.h"



static saml_config_t *saml_config_create_internal(
    saml_identity_provider_config_t *identity_provider_config,
    saml_service_provider_config_t *service_provider_config,
    saml_user_attribute_mapping_t *user_attribute_mapping,
    list_t *group_mapping
    ) {
    saml_config_t *saml_config_local_var = malloc(sizeof(saml_config_t));
    if (!saml_config_local_var) {
        return NULL;
    }
    saml_config_local_var->identity_provider_config = identity_provider_config;
    saml_config_local_var->service_provider_config = service_provider_config;
    saml_config_local_var->user_attribute_mapping = user_attribute_mapping;
    saml_config_local_var->group_mapping = group_mapping;

    saml_config_local_var->_library_owned = 1;
    return saml_config_local_var;
}

__attribute__((deprecated)) saml_config_t *saml_config_create(
    saml_identity_provider_config_t *identity_provider_config,
    saml_service_provider_config_t *service_provider_config,
    saml_user_attribute_mapping_t *user_attribute_mapping,
    list_t *group_mapping
    ) {
    return saml_config_create_internal (
        identity_provider_config,
        service_provider_config,
        user_attribute_mapping,
        group_mapping
        );
}

void saml_config_free(saml_config_t *saml_config) {
    if(NULL == saml_config){
        return ;
    }
    if(saml_config->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "saml_config_free");
        return ;
    }
    listEntry_t *listEntry;
    if (saml_config->identity_provider_config) {
        saml_identity_provider_config_free(saml_config->identity_provider_config);
        saml_config->identity_provider_config = NULL;
    }
    if (saml_config->service_provider_config) {
        saml_service_provider_config_free(saml_config->service_provider_config);
        saml_config->service_provider_config = NULL;
    }
    if (saml_config->user_attribute_mapping) {
        saml_user_attribute_mapping_free(saml_config->user_attribute_mapping);
        saml_config->user_attribute_mapping = NULL;
    }
    if (saml_config->group_mapping) {
        list_ForEach(listEntry, saml_config->group_mapping) {
            saml_group_mapping_free(listEntry->data);
        }
        list_freeList(saml_config->group_mapping);
        saml_config->group_mapping = NULL;
    }
    free(saml_config);
}

cJSON *saml_config_convertToJSON(saml_config_t *saml_config) {
    cJSON *item = cJSON_CreateObject();

    // saml_config->identity_provider_config
    if (!saml_config->identity_provider_config) {
        goto fail;
    }
    cJSON *identity_provider_config_local_JSON = saml_identity_provider_config_convertToJSON(saml_config->identity_provider_config);
    if(identity_provider_config_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "identityProviderConfig", identity_provider_config_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // saml_config->service_provider_config
    if(saml_config->service_provider_config) {
    cJSON *service_provider_config_local_JSON = saml_service_provider_config_convertToJSON(saml_config->service_provider_config);
    if(service_provider_config_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "serviceProviderConfig", service_provider_config_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // saml_config->user_attribute_mapping
    if(saml_config->user_attribute_mapping) {
    cJSON *user_attribute_mapping_local_JSON = saml_user_attribute_mapping_convertToJSON(saml_config->user_attribute_mapping);
    if(user_attribute_mapping_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "userAttributeMapping", user_attribute_mapping_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // saml_config->group_mapping
    if(saml_config->group_mapping) {
    cJSON *group_mapping = cJSON_AddArrayToObject(item, "groupMapping");
    if(group_mapping == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *group_mappingListEntry;
    if (saml_config->group_mapping) {
    list_ForEach(group_mappingListEntry, saml_config->group_mapping) {
    cJSON *itemLocal = saml_group_mapping_convertToJSON(group_mappingListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(group_mapping, itemLocal);
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

saml_config_t *saml_config_parseFromJSON(cJSON *saml_configJSON){

    saml_config_t *saml_config_local_var = NULL;

    // define the local variable for saml_config->identity_provider_config
    saml_identity_provider_config_t *identity_provider_config_local_nonprim = NULL;

    // define the local variable for saml_config->service_provider_config
    saml_service_provider_config_t *service_provider_config_local_nonprim = NULL;

    // define the local variable for saml_config->user_attribute_mapping
    saml_user_attribute_mapping_t *user_attribute_mapping_local_nonprim = NULL;

    // define the local list for saml_config->group_mapping
    list_t *group_mappingList = NULL;

    // saml_config->identity_provider_config
    cJSON *identity_provider_config = cJSON_GetObjectItemCaseSensitive(saml_configJSON, "identityProviderConfig");
    if (cJSON_IsNull(identity_provider_config)) {
        identity_provider_config = NULL;
    }
    if (!identity_provider_config) {
        goto end;
    }

    
    identity_provider_config_local_nonprim = saml_identity_provider_config_parseFromJSON(identity_provider_config); //nonprimitive

    // saml_config->service_provider_config
    cJSON *service_provider_config = cJSON_GetObjectItemCaseSensitive(saml_configJSON, "serviceProviderConfig");
    if (cJSON_IsNull(service_provider_config)) {
        service_provider_config = NULL;
    }
    if (service_provider_config) { 
    service_provider_config_local_nonprim = saml_service_provider_config_parseFromJSON(service_provider_config); //nonprimitive
    }

    // saml_config->user_attribute_mapping
    cJSON *user_attribute_mapping = cJSON_GetObjectItemCaseSensitive(saml_configJSON, "userAttributeMapping");
    if (cJSON_IsNull(user_attribute_mapping)) {
        user_attribute_mapping = NULL;
    }
    if (user_attribute_mapping) { 
    user_attribute_mapping_local_nonprim = saml_user_attribute_mapping_parseFromJSON(user_attribute_mapping); //nonprimitive
    }

    // saml_config->group_mapping
    cJSON *group_mapping = cJSON_GetObjectItemCaseSensitive(saml_configJSON, "groupMapping");
    if (cJSON_IsNull(group_mapping)) {
        group_mapping = NULL;
    }
    if (group_mapping) { 
    cJSON *group_mapping_local_nonprimitive = NULL;
    if(!cJSON_IsArray(group_mapping)){
        goto end; //nonprimitive container
    }

    group_mappingList = list_createList();

    cJSON_ArrayForEach(group_mapping_local_nonprimitive,group_mapping )
    {
        if(!cJSON_IsObject(group_mapping_local_nonprimitive)){
            goto end;
        }
        saml_group_mapping_t *group_mappingItem = saml_group_mapping_parseFromJSON(group_mapping_local_nonprimitive);

        list_addElement(group_mappingList, group_mappingItem);
    }
    }


    saml_config_local_var = saml_config_create_internal (
        identity_provider_config_local_nonprim,
        service_provider_config ? service_provider_config_local_nonprim : NULL,
        user_attribute_mapping ? user_attribute_mapping_local_nonprim : NULL,
        group_mapping ? group_mappingList : NULL
        );

    return saml_config_local_var;
end:
    if (identity_provider_config_local_nonprim) {
        saml_identity_provider_config_free(identity_provider_config_local_nonprim);
        identity_provider_config_local_nonprim = NULL;
    }
    if (service_provider_config_local_nonprim) {
        saml_service_provider_config_free(service_provider_config_local_nonprim);
        service_provider_config_local_nonprim = NULL;
    }
    if (user_attribute_mapping_local_nonprim) {
        saml_user_attribute_mapping_free(user_attribute_mapping_local_nonprim);
        user_attribute_mapping_local_nonprim = NULL;
    }
    if (group_mappingList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, group_mappingList) {
            saml_group_mapping_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(group_mappingList);
        group_mappingList = NULL;
    }
    return NULL;

}
