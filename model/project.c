#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "project.h"



static project_t *project_create_internal(
    char *id,
    char *name,
    project_settings_t *settings,
    project_quota_t *quotas,
    project_usage_t *quotas_used,
    network_status_t *network_status,
    project_config_t *config
    ) {
    project_t *project_local_var = malloc(sizeof(project_t));
    if (!project_local_var) {
        return NULL;
    }
    project_local_var->id = id;
    project_local_var->name = name;
    project_local_var->settings = settings;
    project_local_var->quotas = quotas;
    project_local_var->quotas_used = quotas_used;
    project_local_var->network_status = network_status;
    project_local_var->config = config;

    project_local_var->_library_owned = 1;
    return project_local_var;
}

__attribute__((deprecated)) project_t *project_create(
    char *id,
    char *name,
    project_settings_t *settings,
    project_quota_t *quotas,
    project_usage_t *quotas_used,
    network_status_t *network_status,
    project_config_t *config
    ) {
    return project_create_internal (
        id,
        name,
        settings,
        quotas,
        quotas_used,
        network_status,
        config
        );
}

void project_free(project_t *project) {
    if(NULL == project){
        return ;
    }
    if(project->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "project_free");
        return ;
    }
    listEntry_t *listEntry;
    if (project->id) {
        free(project->id);
        project->id = NULL;
    }
    if (project->name) {
        free(project->name);
        project->name = NULL;
    }
    if (project->settings) {
        project_settings_free(project->settings);
        project->settings = NULL;
    }
    if (project->quotas) {
        project_quota_free(project->quotas);
        project->quotas = NULL;
    }
    if (project->quotas_used) {
        project_usage_free(project->quotas_used);
        project->quotas_used = NULL;
    }
    if (project->network_status) {
        network_status_free(project->network_status);
        project->network_status = NULL;
    }
    if (project->config) {
        project_config_free(project->config);
        project->config = NULL;
    }
    free(project);
}

cJSON *project_convertToJSON(project_t *project) {
    cJSON *item = cJSON_CreateObject();

    // project->id
    if (!project->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", project->id) == NULL) {
    goto fail; //String
    }


    // project->name
    if (!project->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", project->name) == NULL) {
    goto fail; //String
    }


    // project->settings
    if (!project->settings) {
        goto fail;
    }
    cJSON *settings_local_JSON = project_settings_convertToJSON(project->settings);
    if(settings_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "settings", settings_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // project->quotas
    if (!project->quotas) {
        goto fail;
    }
    cJSON *quotas_local_JSON = project_quota_convertToJSON(project->quotas);
    if(quotas_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "quotas", quotas_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // project->quotas_used
    if (!project->quotas_used) {
        goto fail;
    }
    cJSON *quotas_used_local_JSON = project_usage_convertToJSON(project->quotas_used);
    if(quotas_used_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "quotasUsed", quotas_used_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // project->network_status
    if(project->network_status) {
    cJSON *network_status_local_JSON = network_status_convertToJSON(project->network_status);
    if(network_status_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "networkStatus", network_status_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // project->config
    if(project->config) {
    cJSON *config_local_JSON = project_config_convertToJSON(project->config);
    if(config_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "config", config_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

project_t *project_parseFromJSON(cJSON *projectJSON){

    project_t *project_local_var = NULL;

    // define the local variable for project->settings
    project_settings_t *settings_local_nonprim = NULL;

    // define the local variable for project->quotas
    project_quota_t *quotas_local_nonprim = NULL;

    // define the local variable for project->quotas_used
    project_usage_t *quotas_used_local_nonprim = NULL;

    // define the local variable for project->network_status
    network_status_t *network_status_local_nonprim = NULL;

    // define the local variable for project->config
    project_config_t *config_local_nonprim = NULL;

    // project->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(projectJSON, "id");
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

    // project->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(projectJSON, "name");
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

    // project->settings
    cJSON *settings = cJSON_GetObjectItemCaseSensitive(projectJSON, "settings");
    if (cJSON_IsNull(settings)) {
        settings = NULL;
    }
    if (!settings) {
        goto end;
    }

    
    settings_local_nonprim = project_settings_parseFromJSON(settings); //nonprimitive

    // project->quotas
    cJSON *quotas = cJSON_GetObjectItemCaseSensitive(projectJSON, "quotas");
    if (cJSON_IsNull(quotas)) {
        quotas = NULL;
    }
    if (!quotas) {
        goto end;
    }

    
    quotas_local_nonprim = project_quota_parseFromJSON(quotas); //nonprimitive

    // project->quotas_used
    cJSON *quotas_used = cJSON_GetObjectItemCaseSensitive(projectJSON, "quotasUsed");
    if (cJSON_IsNull(quotas_used)) {
        quotas_used = NULL;
    }
    if (!quotas_used) {
        goto end;
    }

    
    quotas_used_local_nonprim = project_usage_parseFromJSON(quotas_used); //nonprimitive

    // project->network_status
    cJSON *network_status = cJSON_GetObjectItemCaseSensitive(projectJSON, "networkStatus");
    if (cJSON_IsNull(network_status)) {
        network_status = NULL;
    }
    if (network_status) { 
    network_status_local_nonprim = network_status_parseFromJSON(network_status); //nonprimitive
    }

    // project->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(projectJSON, "config");
    if (cJSON_IsNull(config)) {
        config = NULL;
    }
    if (config) { 
    config_local_nonprim = project_config_parseFromJSON(config); //nonprimitive
    }


    project_local_var = project_create_internal (
        strdup(id->valuestring),
        strdup(name->valuestring),
        settings_local_nonprim,
        quotas_local_nonprim,
        quotas_used_local_nonprim,
        network_status ? network_status_local_nonprim : NULL,
        config ? config_local_nonprim : NULL
        );

    return project_local_var;
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
