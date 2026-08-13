#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "project_with_keys_v1.h"



static project_with_keys_v1_t *project_with_keys_v1_create_internal(
    char *id,
    char *name,
    project_settings_v1_t *settings,
    project_quota_v1_t *quotas,
    project_usage_v1_t *quotas_used,
    network_status_v1_t *network_status,
    list_t *keys
    ) {
    project_with_keys_v1_t *project_with_keys_v1_local_var = malloc(sizeof(project_with_keys_v1_t));
    if (!project_with_keys_v1_local_var) {
        return NULL;
    }
    project_with_keys_v1_local_var->id = id;
    project_with_keys_v1_local_var->name = name;
    project_with_keys_v1_local_var->settings = settings;
    project_with_keys_v1_local_var->quotas = quotas;
    project_with_keys_v1_local_var->quotas_used = quotas_used;
    project_with_keys_v1_local_var->network_status = network_status;
    project_with_keys_v1_local_var->keys = keys;

    project_with_keys_v1_local_var->_library_owned = 1;
    return project_with_keys_v1_local_var;
}

__attribute__((deprecated)) project_with_keys_v1_t *project_with_keys_v1_create(
    char *id,
    char *name,
    project_settings_v1_t *settings,
    project_quota_v1_t *quotas,
    project_usage_v1_t *quotas_used,
    network_status_v1_t *network_status,
    list_t *keys
    ) {
    return project_with_keys_v1_create_internal (
        id,
        name,
        settings,
        quotas,
        quotas_used,
        network_status,
        keys
        );
}

void project_with_keys_v1_free(project_with_keys_v1_t *project_with_keys_v1) {
    if(NULL == project_with_keys_v1){
        return ;
    }
    if(project_with_keys_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "project_with_keys_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (project_with_keys_v1->id) {
        free(project_with_keys_v1->id);
        project_with_keys_v1->id = NULL;
    }
    if (project_with_keys_v1->name) {
        free(project_with_keys_v1->name);
        project_with_keys_v1->name = NULL;
    }
    if (project_with_keys_v1->settings) {
        project_settings_v1_free(project_with_keys_v1->settings);
        project_with_keys_v1->settings = NULL;
    }
    if (project_with_keys_v1->quotas) {
        project_quota_v1_free(project_with_keys_v1->quotas);
        project_with_keys_v1->quotas = NULL;
    }
    if (project_with_keys_v1->quotas_used) {
        project_usage_v1_free(project_with_keys_v1->quotas_used);
        project_with_keys_v1->quotas_used = NULL;
    }
    if (project_with_keys_v1->network_status) {
        network_status_v1_free(project_with_keys_v1->network_status);
        project_with_keys_v1->network_status = NULL;
    }
    if (project_with_keys_v1->keys) {
        list_ForEach(listEntry, project_with_keys_v1->keys) {
            project_key_v1_free(listEntry->data);
        }
        list_freeList(project_with_keys_v1->keys);
        project_with_keys_v1->keys = NULL;
    }
    free(project_with_keys_v1);
}

cJSON *project_with_keys_v1_convertToJSON(project_with_keys_v1_t *project_with_keys_v1) {
    cJSON *item = cJSON_CreateObject();

    // project_with_keys_v1->id
    if (!project_with_keys_v1->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", project_with_keys_v1->id) == NULL) {
    goto fail; //String
    }


    // project_with_keys_v1->name
    if(project_with_keys_v1->name) {
    if(cJSON_AddStringToObject(item, "name", project_with_keys_v1->name) == NULL) {
    goto fail; //String
    }
    }


    // project_with_keys_v1->settings
    if(project_with_keys_v1->settings) {
    cJSON *settings_local_JSON = project_settings_v1_convertToJSON(project_with_keys_v1->settings);
    if(settings_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "settings", settings_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // project_with_keys_v1->quotas
    if(project_with_keys_v1->quotas) {
    cJSON *quotas_local_JSON = project_quota_v1_convertToJSON(project_with_keys_v1->quotas);
    if(quotas_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "quotas", quotas_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // project_with_keys_v1->quotas_used
    if(project_with_keys_v1->quotas_used) {
    cJSON *quotas_used_local_JSON = project_usage_v1_convertToJSON(project_with_keys_v1->quotas_used);
    if(quotas_used_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "quotasUsed", quotas_used_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // project_with_keys_v1->network_status
    if(project_with_keys_v1->network_status) {
    cJSON *network_status_local_JSON = network_status_v1_convertToJSON(project_with_keys_v1->network_status);
    if(network_status_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "networkStatus", network_status_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // project_with_keys_v1->keys
    if(project_with_keys_v1->keys) {
    cJSON *keys = cJSON_AddArrayToObject(item, "keys");
    if(keys == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *keysListEntry;
    if (project_with_keys_v1->keys) {
    list_ForEach(keysListEntry, project_with_keys_v1->keys) {
    cJSON *itemLocal = project_key_v1_convertToJSON(keysListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(keys, itemLocal);
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

project_with_keys_v1_t *project_with_keys_v1_parseFromJSON(cJSON *project_with_keys_v1JSON){

    project_with_keys_v1_t *project_with_keys_v1_local_var = NULL;

    // define the local variable for project_with_keys_v1->settings
    project_settings_v1_t *settings_local_nonprim = NULL;

    // define the local variable for project_with_keys_v1->quotas
    project_quota_v1_t *quotas_local_nonprim = NULL;

    // define the local variable for project_with_keys_v1->quotas_used
    project_usage_v1_t *quotas_used_local_nonprim = NULL;

    // define the local variable for project_with_keys_v1->network_status
    network_status_v1_t *network_status_local_nonprim = NULL;

    // define the local list for project_with_keys_v1->keys
    list_t *keysList = NULL;

    // project_with_keys_v1->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(project_with_keys_v1JSON, "id");
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

    // project_with_keys_v1->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(project_with_keys_v1JSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // project_with_keys_v1->settings
    cJSON *settings = cJSON_GetObjectItemCaseSensitive(project_with_keys_v1JSON, "settings");
    if (cJSON_IsNull(settings)) {
        settings = NULL;
    }
    if (settings) { 
    settings_local_nonprim = project_settings_v1_parseFromJSON(settings); //nonprimitive
    }

    // project_with_keys_v1->quotas
    cJSON *quotas = cJSON_GetObjectItemCaseSensitive(project_with_keys_v1JSON, "quotas");
    if (cJSON_IsNull(quotas)) {
        quotas = NULL;
    }
    if (quotas) { 
    quotas_local_nonprim = project_quota_v1_parseFromJSON(quotas); //nonprimitive
    }

    // project_with_keys_v1->quotas_used
    cJSON *quotas_used = cJSON_GetObjectItemCaseSensitive(project_with_keys_v1JSON, "quotasUsed");
    if (cJSON_IsNull(quotas_used)) {
        quotas_used = NULL;
    }
    if (quotas_used) { 
    quotas_used_local_nonprim = project_usage_v1_parseFromJSON(quotas_used); //nonprimitive
    }

    // project_with_keys_v1->network_status
    cJSON *network_status = cJSON_GetObjectItemCaseSensitive(project_with_keys_v1JSON, "networkStatus");
    if (cJSON_IsNull(network_status)) {
        network_status = NULL;
    }
    if (network_status) { 
    network_status_local_nonprim = network_status_v1_parseFromJSON(network_status); //nonprimitive
    }

    // project_with_keys_v1->keys
    cJSON *keys = cJSON_GetObjectItemCaseSensitive(project_with_keys_v1JSON, "keys");
    if (cJSON_IsNull(keys)) {
        keys = NULL;
    }
    if (keys) { 
    cJSON *keys_local_nonprimitive = NULL;
    if(!cJSON_IsArray(keys)){
        goto end; //nonprimitive container
    }

    keysList = list_createList();

    cJSON_ArrayForEach(keys_local_nonprimitive,keys )
    {
        if(!cJSON_IsObject(keys_local_nonprimitive)){
            goto end;
        }
        project_key_v1_t *keysItem = project_key_v1_parseFromJSON(keys_local_nonprimitive);

        list_addElement(keysList, keysItem);
    }
    }


    project_with_keys_v1_local_var = project_with_keys_v1_create_internal (
        strdup(id->valuestring),
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        settings ? settings_local_nonprim : NULL,
        quotas ? quotas_local_nonprim : NULL,
        quotas_used ? quotas_used_local_nonprim : NULL,
        network_status ? network_status_local_nonprim : NULL,
        keys ? keysList : NULL
        );

    return project_with_keys_v1_local_var;
end:
    if (settings_local_nonprim) {
        project_settings_v1_free(settings_local_nonprim);
        settings_local_nonprim = NULL;
    }
    if (quotas_local_nonprim) {
        project_quota_v1_free(quotas_local_nonprim);
        quotas_local_nonprim = NULL;
    }
    if (quotas_used_local_nonprim) {
        project_usage_v1_free(quotas_used_local_nonprim);
        quotas_used_local_nonprim = NULL;
    }
    if (network_status_local_nonprim) {
        network_status_v1_free(network_status_local_nonprim);
        network_status_local_nonprim = NULL;
    }
    if (keysList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, keysList) {
            project_key_v1_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(keysList);
        keysList = NULL;
    }
    return NULL;

}
