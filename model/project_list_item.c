#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "project_list_item.h"



static project_list_item_t *project_list_item_create_internal(
    char *id,
    char *name,
    project_settings_t *settings,
    project_quota_t *quotas,
    project_usage_t *quotas_used,
    network_status_t *network_status,
    project_config_t *config,
    double key_count
    ) {
    project_list_item_t *project_list_item_local_var = malloc(sizeof(project_list_item_t));
    if (!project_list_item_local_var) {
        return NULL;
    }
    project_list_item_local_var->id = id;
    project_list_item_local_var->name = name;
    project_list_item_local_var->settings = settings;
    project_list_item_local_var->quotas = quotas;
    project_list_item_local_var->quotas_used = quotas_used;
    project_list_item_local_var->network_status = network_status;
    project_list_item_local_var->config = config;
    project_list_item_local_var->key_count = key_count;

    project_list_item_local_var->_library_owned = 1;
    return project_list_item_local_var;
}

__attribute__((deprecated)) project_list_item_t *project_list_item_create(
    char *id,
    char *name,
    project_settings_t *settings,
    project_quota_t *quotas,
    project_usage_t *quotas_used,
    network_status_t *network_status,
    project_config_t *config,
    double key_count
    ) {
    return project_list_item_create_internal (
        id,
        name,
        settings,
        quotas,
        quotas_used,
        network_status,
        config,
        key_count
        );
}

void project_list_item_free(project_list_item_t *project_list_item) {
    if(NULL == project_list_item){
        return ;
    }
    if(project_list_item->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "project_list_item_free");
        return ;
    }
    listEntry_t *listEntry;
    if (project_list_item->id) {
        free(project_list_item->id);
        project_list_item->id = NULL;
    }
    if (project_list_item->name) {
        free(project_list_item->name);
        project_list_item->name = NULL;
    }
    if (project_list_item->settings) {
        project_settings_free(project_list_item->settings);
        project_list_item->settings = NULL;
    }
    if (project_list_item->quotas) {
        project_quota_free(project_list_item->quotas);
        project_list_item->quotas = NULL;
    }
    if (project_list_item->quotas_used) {
        project_usage_free(project_list_item->quotas_used);
        project_list_item->quotas_used = NULL;
    }
    if (project_list_item->network_status) {
        network_status_free(project_list_item->network_status);
        project_list_item->network_status = NULL;
    }
    if (project_list_item->config) {
        project_config_free(project_list_item->config);
        project_list_item->config = NULL;
    }
    free(project_list_item);
}

cJSON *project_list_item_convertToJSON(project_list_item_t *project_list_item) {
    cJSON *item = cJSON_CreateObject();

    // project_list_item->id
    if (!project_list_item->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", project_list_item->id) == NULL) {
    goto fail; //String
    }


    // project_list_item->name
    if (!project_list_item->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", project_list_item->name) == NULL) {
    goto fail; //String
    }


    // project_list_item->settings
    if (!project_list_item->settings) {
        goto fail;
    }
    cJSON *settings_local_JSON = project_settings_convertToJSON(project_list_item->settings);
    if(settings_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "settings", settings_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // project_list_item->quotas
    if (!project_list_item->quotas) {
        goto fail;
    }
    cJSON *quotas_local_JSON = project_quota_convertToJSON(project_list_item->quotas);
    if(quotas_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "quotas", quotas_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // project_list_item->quotas_used
    if (!project_list_item->quotas_used) {
        goto fail;
    }
    cJSON *quotas_used_local_JSON = project_usage_convertToJSON(project_list_item->quotas_used);
    if(quotas_used_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "quotasUsed", quotas_used_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // project_list_item->network_status
    if(project_list_item->network_status) {
    cJSON *network_status_local_JSON = network_status_convertToJSON(project_list_item->network_status);
    if(network_status_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "networkStatus", network_status_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // project_list_item->config
    if(project_list_item->config) {
    cJSON *config_local_JSON = project_config_convertToJSON(project_list_item->config);
    if(config_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "config", config_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // project_list_item->key_count
    if (!project_list_item->key_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "keyCount", project_list_item->key_count) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

project_list_item_t *project_list_item_parseFromJSON(cJSON *project_list_itemJSON){

    project_list_item_t *project_list_item_local_var = NULL;

    // define the local variable for project_list_item->settings
    project_settings_t *settings_local_nonprim = NULL;

    // define the local variable for project_list_item->quotas
    project_quota_t *quotas_local_nonprim = NULL;

    // define the local variable for project_list_item->quotas_used
    project_usage_t *quotas_used_local_nonprim = NULL;

    // define the local variable for project_list_item->network_status
    network_status_t *network_status_local_nonprim = NULL;

    // define the local variable for project_list_item->config
    project_config_t *config_local_nonprim = NULL;

    // project_list_item->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(project_list_itemJSON, "id");
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

    // project_list_item->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(project_list_itemJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // project_list_item->settings
    cJSON *settings = cJSON_GetObjectItemCaseSensitive(project_list_itemJSON, "settings");
    if (cJSON_IsNull(settings)) {
        settings = NULL;
    }
    if (!settings) {
        goto end;
    }

    
    settings_local_nonprim = project_settings_parseFromJSON(settings); //nonprimitive

    // project_list_item->quotas
    cJSON *quotas = cJSON_GetObjectItemCaseSensitive(project_list_itemJSON, "quotas");
    if (cJSON_IsNull(quotas)) {
        quotas = NULL;
    }
    if (!quotas) {
        goto end;
    }

    
    quotas_local_nonprim = project_quota_parseFromJSON(quotas); //nonprimitive

    // project_list_item->quotas_used
    cJSON *quotas_used = cJSON_GetObjectItemCaseSensitive(project_list_itemJSON, "quotasUsed");
    if (cJSON_IsNull(quotas_used)) {
        quotas_used = NULL;
    }
    if (!quotas_used) {
        goto end;
    }

    
    quotas_used_local_nonprim = project_usage_parseFromJSON(quotas_used); //nonprimitive

    // project_list_item->network_status
    cJSON *network_status = cJSON_GetObjectItemCaseSensitive(project_list_itemJSON, "networkStatus");
    if (cJSON_IsNull(network_status)) {
        network_status = NULL;
    }
    if (network_status) { 
    network_status_local_nonprim = network_status_parseFromJSON(network_status); //nonprimitive
    }

    // project_list_item->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(project_list_itemJSON, "config");
    if (cJSON_IsNull(config)) {
        config = NULL;
    }
    if (config) { 
    config_local_nonprim = project_config_parseFromJSON(config); //nonprimitive
    }

    // project_list_item->key_count
    cJSON *key_count = cJSON_GetObjectItemCaseSensitive(project_list_itemJSON, "keyCount");
    if (cJSON_IsNull(key_count)) {
        key_count = NULL;
    }
    if (!key_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(key_count))
    {
    goto end; //Numeric
    }


    project_list_item_local_var = project_list_item_create_internal (
        strdup(id->valuestring),
        strdup(name->valuestring),
        settings_local_nonprim,
        quotas_local_nonprim,
        quotas_used_local_nonprim,
        network_status ? network_status_local_nonprim : NULL,
        config ? config_local_nonprim : NULL,
        key_count->valuedouble
        );

    return project_list_item_local_var;
end:
    if (settings_local_nonprim) {
        project_settings_free(settings_local_nonprim);
        settings_local_nonprim = NULL;
    }
    if (quotas_local_nonprim) {
        project_quota_free(quotas_local_nonprim);
        quotas_local_nonprim = NULL;
    }
    if (quotas_used_local_nonprim) {
        project_usage_free(quotas_used_local_nonprim);
        quotas_used_local_nonprim = NULL;
    }
    if (network_status_local_nonprim) {
        network_status_free(network_status_local_nonprim);
        network_status_local_nonprim = NULL;
    }
    if (config_local_nonprim) {
        project_config_free(config_local_nonprim);
        config_local_nonprim = NULL;
    }
    return NULL;

}
