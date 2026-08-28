#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "agent_app.h"



static agent_app_t *agent_app_create_internal(
    list_t *tags,
    int running,
    double disk_usage,
    double date,
    char *application_type,
    char *name,
    char *bundle_id,
    char *bundle_path,
    char *bundle_data_path,
    int is_launchable,
    char *icon
    ) {
    agent_app_t *agent_app_local_var = malloc(sizeof(agent_app_t));
    if (!agent_app_local_var) {
        return NULL;
    }
    agent_app_local_var->tags = tags;
    agent_app_local_var->running = running;
    agent_app_local_var->disk_usage = disk_usage;
    agent_app_local_var->date = date;
    agent_app_local_var->application_type = application_type;
    agent_app_local_var->name = name;
    agent_app_local_var->bundle_id = bundle_id;
    agent_app_local_var->bundle_path = bundle_path;
    agent_app_local_var->bundle_data_path = bundle_data_path;
    agent_app_local_var->is_launchable = is_launchable;
    agent_app_local_var->icon = icon;

    agent_app_local_var->_library_owned = 1;
    return agent_app_local_var;
}

__attribute__((deprecated)) agent_app_t *agent_app_create(
    list_t *tags,
    int running,
    double disk_usage,
    double date,
    char *application_type,
    char *name,
    char *bundle_id,
    char *bundle_path,
    char *bundle_data_path,
    int is_launchable,
    char *icon
    ) {
    return agent_app_create_internal (
        tags,
        running,
        disk_usage,
        date,
        application_type,
        name,
        bundle_id,
        bundle_path,
        bundle_data_path,
        is_launchable,
        icon
        );
}

void agent_app_free(agent_app_t *agent_app) {
    if(NULL == agent_app){
        return ;
    }
    if(agent_app->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "agent_app_free");
        return ;
    }
    listEntry_t *listEntry;
    if (agent_app->tags) {
        list_ForEach(listEntry, agent_app->tags) {
            free(listEntry->data);
        }
        list_freeList(agent_app->tags);
        agent_app->tags = NULL;
    }
    if (agent_app->application_type) {
        free(agent_app->application_type);
        agent_app->application_type = NULL;
    }
    if (agent_app->name) {
        free(agent_app->name);
        agent_app->name = NULL;
    }
    if (agent_app->bundle_id) {
        free(agent_app->bundle_id);
        agent_app->bundle_id = NULL;
    }
    if (agent_app->bundle_path) {
        free(agent_app->bundle_path);
        agent_app->bundle_path = NULL;
    }
    if (agent_app->bundle_data_path) {
        free(agent_app->bundle_data_path);
        agent_app->bundle_data_path = NULL;
    }
    if (agent_app->icon) {
        free(agent_app->icon);
        agent_app->icon = NULL;
    }
    free(agent_app);
}

cJSON *agent_app_convertToJSON(agent_app_t *agent_app) {
    cJSON *item = cJSON_CreateObject();

    // agent_app->tags
    if(agent_app->tags) {
    cJSON *tags = cJSON_AddArrayToObject(item, "tags");
    if(tags == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *tagsListEntry;
    list_ForEach(tagsListEntry, agent_app->tags) {
    if(cJSON_AddStringToObject(tags, "", tagsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // agent_app->running
    if (!agent_app->running) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "running", agent_app->running) == NULL) {
    goto fail; //Bool
    }


    // agent_app->disk_usage
    if (!agent_app->disk_usage) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "diskUsage", agent_app->disk_usage) == NULL) {
    goto fail; //Numeric
    }


    // agent_app->date
    if (!agent_app->date) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "date", agent_app->date) == NULL) {
    goto fail; //Numeric
    }


    // agent_app->application_type
    if (!agent_app->application_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "applicationType", agent_app->application_type) == NULL) {
    goto fail; //String
    }


    // agent_app->name
    if(agent_app->name) {
    if(cJSON_AddStringToObject(item, "name", agent_app->name) == NULL) {
    goto fail; //String
    }
    }


    // agent_app->bundle_id
    if (!agent_app->bundle_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "bundleId", agent_app->bundle_id) == NULL) {
    goto fail; //String
    }


    // agent_app->bundle_path
    if (!agent_app->bundle_path) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "bundlePath", agent_app->bundle_path) == NULL) {
    goto fail; //String
    }


    // agent_app->bundle_data_path
    if (!agent_app->bundle_data_path) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "bundleDataPath", agent_app->bundle_data_path) == NULL) {
    goto fail; //String
    }


    // agent_app->is_launchable
    if(agent_app->is_launchable) {
    if(cJSON_AddBoolToObject(item, "isLaunchable", agent_app->is_launchable) == NULL) {
    goto fail; //Bool
    }
    }


    // agent_app->icon
    if(agent_app->icon) {
    if(cJSON_AddStringToObject(item, "icon", agent_app->icon) == NULL) {
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

agent_app_t *agent_app_parseFromJSON(cJSON *agent_appJSON){

    agent_app_t *agent_app_local_var = NULL;

    // define the local list for agent_app->tags
    list_t *tagsList = NULL;

    // agent_app->tags
    cJSON *tags = cJSON_GetObjectItemCaseSensitive(agent_appJSON, "tags");
    if (cJSON_IsNull(tags)) {
        tags = NULL;
    }
    if (tags) { 
    cJSON *tags_local = NULL;
    if(!cJSON_IsArray(tags)) {
        goto end;//primitive container
    }
    tagsList = list_createList();

    cJSON_ArrayForEach(tags_local, tags)
    {
        if(!cJSON_IsString(tags_local))
        {
            goto end;
        }
        list_addElement(tagsList , strdup(tags_local->valuestring));
    }
    }

    // agent_app->running
    cJSON *running = cJSON_GetObjectItemCaseSensitive(agent_appJSON, "running");
    if (cJSON_IsNull(running)) {
        running = NULL;
    }
    if (!running) {
        goto end;
    }

    
    if(!cJSON_IsBool(running))
    {
    goto end; //Bool
    }

    // agent_app->disk_usage
    cJSON *disk_usage = cJSON_GetObjectItemCaseSensitive(agent_appJSON, "diskUsage");
    if (cJSON_IsNull(disk_usage)) {
        disk_usage = NULL;
    }
    if (!disk_usage) {
        goto end;
    }

    
    if(!cJSON_IsNumber(disk_usage))
    {
    goto end; //Numeric
    }

    // agent_app->date
    cJSON *date = cJSON_GetObjectItemCaseSensitive(agent_appJSON, "date");
    if (cJSON_IsNull(date)) {
        date = NULL;
    }
    if (!date) {
        goto end;
    }

    
    if(!cJSON_IsNumber(date))
    {
    goto end; //Numeric
    }

    // agent_app->application_type
    cJSON *application_type = cJSON_GetObjectItemCaseSensitive(agent_appJSON, "applicationType");
    if (cJSON_IsNull(application_type)) {
        application_type = NULL;
    }
    if (!application_type) {
        goto end;
    }

    
    if(!cJSON_IsString(application_type))
    {
    goto end; //String
    }

    // agent_app->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(agent_appJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // agent_app->bundle_id
    cJSON *bundle_id = cJSON_GetObjectItemCaseSensitive(agent_appJSON, "bundleId");
    if (cJSON_IsNull(bundle_id)) {
        bundle_id = NULL;
    }
    if (!bundle_id) {
        goto end;
    }

    
    if(!cJSON_IsString(bundle_id))
    {
    goto end; //String
    }

    // agent_app->bundle_path
    cJSON *bundle_path = cJSON_GetObjectItemCaseSensitive(agent_appJSON, "bundlePath");
    if (cJSON_IsNull(bundle_path)) {
        bundle_path = NULL;
    }
    if (!bundle_path) {
        goto end;
    }

    
    if(!cJSON_IsString(bundle_path))
    {
    goto end; //String
    }

    // agent_app->bundle_data_path
    cJSON *bundle_data_path = cJSON_GetObjectItemCaseSensitive(agent_appJSON, "bundleDataPath");
    if (cJSON_IsNull(bundle_data_path)) {
        bundle_data_path = NULL;
    }
    if (!bundle_data_path) {
        goto end;
    }

    
    if(!cJSON_IsString(bundle_data_path))
    {
    goto end; //String
    }

    // agent_app->is_launchable
    cJSON *is_launchable = cJSON_GetObjectItemCaseSensitive(agent_appJSON, "isLaunchable");
    if (cJSON_IsNull(is_launchable)) {
        is_launchable = NULL;
    }
    if (is_launchable) { 
    if(!cJSON_IsBool(is_launchable))
    {
    goto end; //Bool
    }
    }

    // agent_app->icon
    cJSON *icon = cJSON_GetObjectItemCaseSensitive(agent_appJSON, "icon");
    if (cJSON_IsNull(icon)) {
        icon = NULL;
    }
    if (icon) { 
    if(!cJSON_IsString(icon) && !cJSON_IsNull(icon))
    {
    goto end; //String
    }
    }


    agent_app_local_var = agent_app_create_internal (
        tags ? tagsList : NULL,
        running->valueint,
        disk_usage->valuedouble,
        date->valuedouble,
        strdup(application_type->valuestring),
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        strdup(bundle_id->valuestring),
        strdup(bundle_path->valuestring),
        strdup(bundle_data_path->valuestring),
        is_launchable ? is_launchable->valueint : 0,
        icon && !cJSON_IsNull(icon) ? strdup(icon->valuestring) : NULL
        );

    return agent_app_local_var;
end:
    if (tagsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, tagsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(tagsList);
        tagsList = NULL;
    }
    return NULL;

}
