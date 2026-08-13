#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "agent_app_v1.h"



static agent_app_v1_t *agent_app_v1_create_internal(
    list_t *tags,
    int running,
    double disk_usage,
    double date,
    char *application_type,
    char *name,
    char *bundle_id,
    char *bundle_path,
    char *bundle_data_path
    ) {
    agent_app_v1_t *agent_app_v1_local_var = malloc(sizeof(agent_app_v1_t));
    if (!agent_app_v1_local_var) {
        return NULL;
    }
    agent_app_v1_local_var->tags = tags;
    agent_app_v1_local_var->running = running;
    agent_app_v1_local_var->disk_usage = disk_usage;
    agent_app_v1_local_var->date = date;
    agent_app_v1_local_var->application_type = application_type;
    agent_app_v1_local_var->name = name;
    agent_app_v1_local_var->bundle_id = bundle_id;
    agent_app_v1_local_var->bundle_path = bundle_path;
    agent_app_v1_local_var->bundle_data_path = bundle_data_path;

    agent_app_v1_local_var->_library_owned = 1;
    return agent_app_v1_local_var;
}

__attribute__((deprecated)) agent_app_v1_t *agent_app_v1_create(
    list_t *tags,
    int running,
    double disk_usage,
    double date,
    char *application_type,
    char *name,
    char *bundle_id,
    char *bundle_path,
    char *bundle_data_path
    ) {
    return agent_app_v1_create_internal (
        tags,
        running,
        disk_usage,
        date,
        application_type,
        name,
        bundle_id,
        bundle_path,
        bundle_data_path
        );
}

void agent_app_v1_free(agent_app_v1_t *agent_app_v1) {
    if(NULL == agent_app_v1){
        return ;
    }
    if(agent_app_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "agent_app_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (agent_app_v1->tags) {
        list_ForEach(listEntry, agent_app_v1->tags) {
            free(listEntry->data);
        }
        list_freeList(agent_app_v1->tags);
        agent_app_v1->tags = NULL;
    }
    if (agent_app_v1->application_type) {
        free(agent_app_v1->application_type);
        agent_app_v1->application_type = NULL;
    }
    if (agent_app_v1->name) {
        free(agent_app_v1->name);
        agent_app_v1->name = NULL;
    }
    if (agent_app_v1->bundle_id) {
        free(agent_app_v1->bundle_id);
        agent_app_v1->bundle_id = NULL;
    }
    if (agent_app_v1->bundle_path) {
        free(agent_app_v1->bundle_path);
        agent_app_v1->bundle_path = NULL;
    }
    if (agent_app_v1->bundle_data_path) {
        free(agent_app_v1->bundle_data_path);
        agent_app_v1->bundle_data_path = NULL;
    }
    free(agent_app_v1);
}

cJSON *agent_app_v1_convertToJSON(agent_app_v1_t *agent_app_v1) {
    cJSON *item = cJSON_CreateObject();

    // agent_app_v1->tags
    if(agent_app_v1->tags) {
    cJSON *tags = cJSON_AddArrayToObject(item, "tags");
    if(tags == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *tagsListEntry;
    list_ForEach(tagsListEntry, agent_app_v1->tags) {
    if(cJSON_AddStringToObject(tags, "", tagsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // agent_app_v1->running
    if(agent_app_v1->running) {
    if(cJSON_AddBoolToObject(item, "running", agent_app_v1->running) == NULL) {
    goto fail; //Bool
    }
    }


    // agent_app_v1->disk_usage
    if(agent_app_v1->disk_usage) {
    if(cJSON_AddNumberToObject(item, "diskUsage", agent_app_v1->disk_usage) == NULL) {
    goto fail; //Numeric
    }
    }


    // agent_app_v1->date
    if(agent_app_v1->date) {
    if(cJSON_AddNumberToObject(item, "Date", agent_app_v1->date) == NULL) {
    goto fail; //Numeric
    }
    }


    // agent_app_v1->application_type
    if(agent_app_v1->application_type) {
    if(cJSON_AddStringToObject(item, "applicationType", agent_app_v1->application_type) == NULL) {
    goto fail; //String
    }
    }


    // agent_app_v1->name
    if(agent_app_v1->name) {
    if(cJSON_AddStringToObject(item, "name", agent_app_v1->name) == NULL) {
    goto fail; //String
    }
    }


    // agent_app_v1->bundle_id
    if(agent_app_v1->bundle_id) {
    if(cJSON_AddStringToObject(item, "bundleID", agent_app_v1->bundle_id) == NULL) {
    goto fail; //String
    }
    }


    // agent_app_v1->bundle_path
    if(agent_app_v1->bundle_path) {
    if(cJSON_AddStringToObject(item, "bundlePath", agent_app_v1->bundle_path) == NULL) {
    goto fail; //String
    }
    }


    // agent_app_v1->bundle_data_path
    if(agent_app_v1->bundle_data_path) {
    if(cJSON_AddStringToObject(item, "bundleDataPath", agent_app_v1->bundle_data_path) == NULL) {
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

agent_app_v1_t *agent_app_v1_parseFromJSON(cJSON *agent_app_v1JSON){

    agent_app_v1_t *agent_app_v1_local_var = NULL;

    // define the local list for agent_app_v1->tags
    list_t *tagsList = NULL;

    // agent_app_v1->tags
    cJSON *tags = cJSON_GetObjectItemCaseSensitive(agent_app_v1JSON, "tags");
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

    // agent_app_v1->running
    cJSON *running = cJSON_GetObjectItemCaseSensitive(agent_app_v1JSON, "running");
    if (cJSON_IsNull(running)) {
        running = NULL;
    }
    if (running) { 
    if(!cJSON_IsBool(running))
    {
    goto end; //Bool
    }
    }

    // agent_app_v1->disk_usage
    cJSON *disk_usage = cJSON_GetObjectItemCaseSensitive(agent_app_v1JSON, "diskUsage");
    if (cJSON_IsNull(disk_usage)) {
        disk_usage = NULL;
    }
    if (disk_usage) { 
    if(!cJSON_IsNumber(disk_usage))
    {
    goto end; //Numeric
    }
    }

    // agent_app_v1->date
    cJSON *date = cJSON_GetObjectItemCaseSensitive(agent_app_v1JSON, "Date");
    if (cJSON_IsNull(date)) {
        date = NULL;
    }
    if (date) { 
    if(!cJSON_IsNumber(date))
    {
    goto end; //Numeric
    }
    }

    // agent_app_v1->application_type
    cJSON *application_type = cJSON_GetObjectItemCaseSensitive(agent_app_v1JSON, "applicationType");
    if (cJSON_IsNull(application_type)) {
        application_type = NULL;
    }
    if (application_type) { 
    if(!cJSON_IsString(application_type) && !cJSON_IsNull(application_type))
    {
    goto end; //String
    }
    }

    // agent_app_v1->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(agent_app_v1JSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // agent_app_v1->bundle_id
    cJSON *bundle_id = cJSON_GetObjectItemCaseSensitive(agent_app_v1JSON, "bundleID");
    if (cJSON_IsNull(bundle_id)) {
        bundle_id = NULL;
    }
    if (bundle_id) { 
    if(!cJSON_IsString(bundle_id) && !cJSON_IsNull(bundle_id))
    {
    goto end; //String
    }
    }

    // agent_app_v1->bundle_path
    cJSON *bundle_path = cJSON_GetObjectItemCaseSensitive(agent_app_v1JSON, "bundlePath");
    if (cJSON_IsNull(bundle_path)) {
        bundle_path = NULL;
    }
    if (bundle_path) { 
    if(!cJSON_IsString(bundle_path) && !cJSON_IsNull(bundle_path))
    {
    goto end; //String
    }
    }

    // agent_app_v1->bundle_data_path
    cJSON *bundle_data_path = cJSON_GetObjectItemCaseSensitive(agent_app_v1JSON, "bundleDataPath");
    if (cJSON_IsNull(bundle_data_path)) {
        bundle_data_path = NULL;
    }
    if (bundle_data_path) { 
    if(!cJSON_IsString(bundle_data_path) && !cJSON_IsNull(bundle_data_path))
    {
    goto end; //String
    }
    }


    agent_app_v1_local_var = agent_app_v1_create_internal (
        tags ? tagsList : NULL,
        running ? running->valueint : 0,
        disk_usage ? disk_usage->valuedouble : 0,
        date ? date->valuedouble : 0,
        application_type && !cJSON_IsNull(application_type) ? strdup(application_type->valuestring) : NULL,
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        bundle_id && !cJSON_IsNull(bundle_id) ? strdup(bundle_id->valuestring) : NULL,
        bundle_path && !cJSON_IsNull(bundle_path) ? strdup(bundle_path->valuestring) : NULL,
        bundle_data_path && !cJSON_IsNull(bundle_data_path) ? strdup(bundle_data_path->valuestring) : NULL
        );

    return agent_app_v1_local_var;
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
