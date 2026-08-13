#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "instance_restore_status.h"



static instance_restore_status_t *instance_restore_status_create_internal(
    char *type,
    char *stage,
    object_t *progress,
    object_t *total_progress,
    char *heading,
    char *description
    ) {
    instance_restore_status_t *instance_restore_status_local_var = malloc(sizeof(instance_restore_status_t));
    if (!instance_restore_status_local_var) {
        return NULL;
    }
    instance_restore_status_local_var->type = type;
    instance_restore_status_local_var->stage = stage;
    instance_restore_status_local_var->progress = progress;
    instance_restore_status_local_var->total_progress = total_progress;
    instance_restore_status_local_var->heading = heading;
    instance_restore_status_local_var->description = description;

    instance_restore_status_local_var->_library_owned = 1;
    return instance_restore_status_local_var;
}

__attribute__((deprecated)) instance_restore_status_t *instance_restore_status_create(
    char *type,
    char *stage,
    object_t *progress,
    object_t *total_progress,
    char *heading,
    char *description
    ) {
    return instance_restore_status_create_internal (
        type,
        stage,
        progress,
        total_progress,
        heading,
        description
        );
}

void instance_restore_status_free(instance_restore_status_t *instance_restore_status) {
    if(NULL == instance_restore_status){
        return ;
    }
    if(instance_restore_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "instance_restore_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (instance_restore_status->type) {
        free(instance_restore_status->type);
        instance_restore_status->type = NULL;
    }
    if (instance_restore_status->stage) {
        free(instance_restore_status->stage);
        instance_restore_status->stage = NULL;
    }
    if (instance_restore_status->progress) {
        object_free(instance_restore_status->progress);
        instance_restore_status->progress = NULL;
    }
    if (instance_restore_status->total_progress) {
        object_free(instance_restore_status->total_progress);
        instance_restore_status->total_progress = NULL;
    }
    if (instance_restore_status->heading) {
        free(instance_restore_status->heading);
        instance_restore_status->heading = NULL;
    }
    if (instance_restore_status->description) {
        free(instance_restore_status->description);
        instance_restore_status->description = NULL;
    }
    free(instance_restore_status);
}

cJSON *instance_restore_status_convertToJSON(instance_restore_status_t *instance_restore_status) {
    cJSON *item = cJSON_CreateObject();

    // instance_restore_status->type
    if(instance_restore_status->type) {
    if(cJSON_AddStringToObject(item, "type", instance_restore_status->type) == NULL) {
    goto fail; //String
    }
    }


    // instance_restore_status->stage
    if(instance_restore_status->stage) {
    if(cJSON_AddStringToObject(item, "stage", instance_restore_status->stage) == NULL) {
    goto fail; //String
    }
    }


    // instance_restore_status->progress
    if(instance_restore_status->progress) {
    cJSON *progress_object = object_convertToJSON(instance_restore_status->progress);
    if(progress_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "progress", progress_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // instance_restore_status->total_progress
    if(instance_restore_status->total_progress) {
    cJSON *total_progress_object = object_convertToJSON(instance_restore_status->total_progress);
    if(total_progress_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "totalProgress", total_progress_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // instance_restore_status->heading
    if(instance_restore_status->heading) {
    if(cJSON_AddStringToObject(item, "heading", instance_restore_status->heading) == NULL) {
    goto fail; //String
    }
    }


    // instance_restore_status->description
    if(instance_restore_status->description) {
    if(cJSON_AddStringToObject(item, "description", instance_restore_status->description) == NULL) {
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

instance_restore_status_t *instance_restore_status_parseFromJSON(cJSON *instance_restore_statusJSON){

    instance_restore_status_t *instance_restore_status_local_var = NULL;

    // instance_restore_status->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(instance_restore_statusJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (type) { 
    if(!cJSON_IsString(type) && !cJSON_IsNull(type))
    {
    goto end; //String
    }
    }

    // instance_restore_status->stage
    cJSON *stage = cJSON_GetObjectItemCaseSensitive(instance_restore_statusJSON, "stage");
    if (cJSON_IsNull(stage)) {
        stage = NULL;
    }
    if (stage) { 
    if(!cJSON_IsString(stage) && !cJSON_IsNull(stage))
    {
    goto end; //String
    }
    }

    // instance_restore_status->progress
    cJSON *progress = cJSON_GetObjectItemCaseSensitive(instance_restore_statusJSON, "progress");
    if (cJSON_IsNull(progress)) {
        progress = NULL;
    }
    object_t *progress_local_object = NULL;
    if (progress) { 
    progress_local_object = object_parseFromJSON(progress); //object
    }

    // instance_restore_status->total_progress
    cJSON *total_progress = cJSON_GetObjectItemCaseSensitive(instance_restore_statusJSON, "totalProgress");
    if (cJSON_IsNull(total_progress)) {
        total_progress = NULL;
    }
    object_t *total_progress_local_object = NULL;
    if (total_progress) { 
    total_progress_local_object = object_parseFromJSON(total_progress); //object
    }

    // instance_restore_status->heading
    cJSON *heading = cJSON_GetObjectItemCaseSensitive(instance_restore_statusJSON, "heading");
    if (cJSON_IsNull(heading)) {
        heading = NULL;
    }
    if (heading) { 
    if(!cJSON_IsString(heading) && !cJSON_IsNull(heading))
    {
    goto end; //String
    }
    }

    // instance_restore_status->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(instance_restore_statusJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }


    instance_restore_status_local_var = instance_restore_status_create_internal (
        type && !cJSON_IsNull(type) ? strdup(type->valuestring) : NULL,
        stage && !cJSON_IsNull(stage) ? strdup(stage->valuestring) : NULL,
        progress ? progress_local_object : NULL,
        total_progress ? total_progress_local_object : NULL,
        heading && !cJSON_IsNull(heading) ? strdup(heading->valuestring) : NULL,
        description && !cJSON_IsNull(description) ? strdup(description->valuestring) : NULL
        );

    return instance_restore_status_local_var;
end:
    return NULL;

}
