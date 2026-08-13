#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "activity_export_tasks.h"


char* activity_export_tasks_status_ToString(corellium_api_activity_export_tasks_STATUS_e status) {
    char* statusArray[] =  { "NULL", "in-progress", "complete", "error", "" };
    return statusArray[status];
}

corellium_api_activity_export_tasks_STATUS_e activity_export_tasks_status_FromString(char* status){
    int stringToReturn = 0;
    char *statusArray[] =  { "NULL", "in-progress", "complete", "error", "" };
    size_t sizeofArray = sizeof(statusArray) / sizeof(statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(status, statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static activity_export_tasks_t *activity_export_tasks_create_internal(
    char *identifier,
    char *scheduled_at,
    corellium_api_activity_export_tasks_STATUS_e status,
    object_t *args,
    char *created_at,
    char *updated_at
    ) {
    activity_export_tasks_t *activity_export_tasks_local_var = malloc(sizeof(activity_export_tasks_t));
    if (!activity_export_tasks_local_var) {
        return NULL;
    }
    activity_export_tasks_local_var->identifier = identifier;
    activity_export_tasks_local_var->scheduled_at = scheduled_at;
    activity_export_tasks_local_var->status = status;
    activity_export_tasks_local_var->args = args;
    activity_export_tasks_local_var->created_at = created_at;
    activity_export_tasks_local_var->updated_at = updated_at;

    activity_export_tasks_local_var->_library_owned = 1;
    return activity_export_tasks_local_var;
}

__attribute__((deprecated)) activity_export_tasks_t *activity_export_tasks_create(
    char *identifier,
    char *scheduled_at,
    corellium_api_activity_export_tasks_STATUS_e status,
    object_t *args,
    char *created_at,
    char *updated_at
    ) {
    return activity_export_tasks_create_internal (
        identifier,
        scheduled_at,
        status,
        args,
        created_at,
        updated_at
        );
}

void activity_export_tasks_free(activity_export_tasks_t *activity_export_tasks) {
    if(NULL == activity_export_tasks){
        return ;
    }
    if(activity_export_tasks->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "activity_export_tasks_free");
        return ;
    }
    listEntry_t *listEntry;
    if (activity_export_tasks->identifier) {
        free(activity_export_tasks->identifier);
        activity_export_tasks->identifier = NULL;
    }
    if (activity_export_tasks->scheduled_at) {
        free(activity_export_tasks->scheduled_at);
        activity_export_tasks->scheduled_at = NULL;
    }
    if (activity_export_tasks->args) {
        object_free(activity_export_tasks->args);
        activity_export_tasks->args = NULL;
    }
    if (activity_export_tasks->created_at) {
        free(activity_export_tasks->created_at);
        activity_export_tasks->created_at = NULL;
    }
    if (activity_export_tasks->updated_at) {
        free(activity_export_tasks->updated_at);
        activity_export_tasks->updated_at = NULL;
    }
    free(activity_export_tasks);
}

cJSON *activity_export_tasks_convertToJSON(activity_export_tasks_t *activity_export_tasks) {
    cJSON *item = cJSON_CreateObject();

    // activity_export_tasks->identifier
    if (!activity_export_tasks->identifier) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "identifier", activity_export_tasks->identifier) == NULL) {
    goto fail; //String
    }


    // activity_export_tasks->scheduled_at
    if (!activity_export_tasks->scheduled_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "scheduledAt", activity_export_tasks->scheduled_at) == NULL) {
    goto fail; //Date-Time
    }


    // activity_export_tasks->status
    if(activity_export_tasks->status != corellium_api_activity_export_tasks_STATUS_NULL) {
    if(cJSON_AddStringToObject(item, "status", activity_export_tasks_status_ToString(activity_export_tasks->status)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // activity_export_tasks->args
    if (!activity_export_tasks->args) {
        goto fail;
    }
    cJSON *args_object = object_convertToJSON(activity_export_tasks->args);
    if(args_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "args", args_object);
    if(item->child == NULL) {
    goto fail;
    }


    // activity_export_tasks->created_at
    if (!activity_export_tasks->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "createdAt", activity_export_tasks->created_at) == NULL) {
    goto fail; //Date-Time
    }


    // activity_export_tasks->updated_at
    if (!activity_export_tasks->updated_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "updatedAt", activity_export_tasks->updated_at) == NULL) {
    goto fail; //Date-Time
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

activity_export_tasks_t *activity_export_tasks_parseFromJSON(cJSON *activity_export_tasksJSON){

    activity_export_tasks_t *activity_export_tasks_local_var = NULL;

    // activity_export_tasks->identifier
    cJSON *identifier = cJSON_GetObjectItemCaseSensitive(activity_export_tasksJSON, "identifier");
    if (cJSON_IsNull(identifier)) {
        identifier = NULL;
    }
    if (!identifier) {
        goto end;
    }

    
    if(!cJSON_IsString(identifier))
    {
    goto end; //String
    }

    // activity_export_tasks->scheduled_at
    cJSON *scheduled_at = cJSON_GetObjectItemCaseSensitive(activity_export_tasksJSON, "scheduledAt");
    if (cJSON_IsNull(scheduled_at)) {
        scheduled_at = NULL;
    }
    if (!scheduled_at) {
        goto end;
    }

    
    if(!cJSON_IsString(scheduled_at) && !cJSON_IsNull(scheduled_at))
    {
    goto end; //DateTime
    }

    // activity_export_tasks->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(activity_export_tasksJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    corellium_api_activity_export_tasks_STATUS_e statusVariable;
    if (status) { 
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = activity_export_tasks_status_FromString(status->valuestring);
    }

    // activity_export_tasks->args
    cJSON *args = cJSON_GetObjectItemCaseSensitive(activity_export_tasksJSON, "args");
    if (cJSON_IsNull(args)) {
        args = NULL;
    }
    if (!args) {
        goto end;
    }

    object_t *args_local_object = NULL;
    
    args_local_object = object_parseFromJSON(args); //object

    // activity_export_tasks->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(activity_export_tasksJSON, "createdAt");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (!created_at) {
        goto end;
    }

    
    if(!cJSON_IsString(created_at) && !cJSON_IsNull(created_at))
    {
    goto end; //DateTime
    }

    // activity_export_tasks->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(activity_export_tasksJSON, "updatedAt");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (!updated_at) {
        goto end;
    }

    
    if(!cJSON_IsString(updated_at) && !cJSON_IsNull(updated_at))
    {
    goto end; //DateTime
    }


    activity_export_tasks_local_var = activity_export_tasks_create_internal (
        strdup(identifier->valuestring),
        strdup(scheduled_at->valuestring),
        status ? statusVariable : corellium_api_activity_export_tasks_STATUS_NULL,
        args_local_object,
        strdup(created_at->valuestring),
        strdup(updated_at->valuestring)
        );

    return activity_export_tasks_local_var;
end:
    return NULL;

}
