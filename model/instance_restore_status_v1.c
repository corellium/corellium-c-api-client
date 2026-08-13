#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "instance_restore_status_v1.h"



static instance_restore_status_v1_t *instance_restore_status_v1_create_internal(
    char *type,
    char *stage,
    double progress,
    double total_progress,
    char *heading,
    char *description
    ) {
    instance_restore_status_v1_t *instance_restore_status_v1_local_var = malloc(sizeof(instance_restore_status_v1_t));
    if (!instance_restore_status_v1_local_var) {
        return NULL;
    }
    instance_restore_status_v1_local_var->type = type;
    instance_restore_status_v1_local_var->stage = stage;
    instance_restore_status_v1_local_var->progress = progress;
    instance_restore_status_v1_local_var->total_progress = total_progress;
    instance_restore_status_v1_local_var->heading = heading;
    instance_restore_status_v1_local_var->description = description;

    instance_restore_status_v1_local_var->_library_owned = 1;
    return instance_restore_status_v1_local_var;
}

__attribute__((deprecated)) instance_restore_status_v1_t *instance_restore_status_v1_create(
    char *type,
    char *stage,
    double progress,
    double total_progress,
    char *heading,
    char *description
    ) {
    return instance_restore_status_v1_create_internal (
        type,
        stage,
        progress,
        total_progress,
        heading,
        description
        );
}

void instance_restore_status_v1_free(instance_restore_status_v1_t *instance_restore_status_v1) {
    if(NULL == instance_restore_status_v1){
        return ;
    }
    if(instance_restore_status_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "instance_restore_status_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (instance_restore_status_v1->type) {
        free(instance_restore_status_v1->type);
        instance_restore_status_v1->type = NULL;
    }
    if (instance_restore_status_v1->stage) {
        free(instance_restore_status_v1->stage);
        instance_restore_status_v1->stage = NULL;
    }
    if (instance_restore_status_v1->heading) {
        free(instance_restore_status_v1->heading);
        instance_restore_status_v1->heading = NULL;
    }
    if (instance_restore_status_v1->description) {
        free(instance_restore_status_v1->description);
        instance_restore_status_v1->description = NULL;
    }
    free(instance_restore_status_v1);
}

cJSON *instance_restore_status_v1_convertToJSON(instance_restore_status_v1_t *instance_restore_status_v1) {
    cJSON *item = cJSON_CreateObject();

    // instance_restore_status_v1->type
    if(instance_restore_status_v1->type) {
    if(cJSON_AddStringToObject(item, "type", instance_restore_status_v1->type) == NULL) {
    goto fail; //String
    }
    }


    // instance_restore_status_v1->stage
    if(instance_restore_status_v1->stage) {
    if(cJSON_AddStringToObject(item, "stage", instance_restore_status_v1->stage) == NULL) {
    goto fail; //String
    }
    }


    // instance_restore_status_v1->progress
    if(instance_restore_status_v1->progress) {
    if(cJSON_AddNumberToObject(item, "progress", instance_restore_status_v1->progress) == NULL) {
    goto fail; //Numeric
    }
    }


    // instance_restore_status_v1->total_progress
    if(instance_restore_status_v1->total_progress) {
    if(cJSON_AddNumberToObject(item, "totalProgress", instance_restore_status_v1->total_progress) == NULL) {
    goto fail; //Numeric
    }
    }


    // instance_restore_status_v1->heading
    if(instance_restore_status_v1->heading) {
    if(cJSON_AddStringToObject(item, "heading", instance_restore_status_v1->heading) == NULL) {
    goto fail; //String
    }
    }


    // instance_restore_status_v1->description
    if(instance_restore_status_v1->description) {
    if(cJSON_AddStringToObject(item, "description", instance_restore_status_v1->description) == NULL) {
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

instance_restore_status_v1_t *instance_restore_status_v1_parseFromJSON(cJSON *instance_restore_status_v1JSON){

    instance_restore_status_v1_t *instance_restore_status_v1_local_var = NULL;

    // instance_restore_status_v1->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(instance_restore_status_v1JSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (type) { 
    if(!cJSON_IsString(type) && !cJSON_IsNull(type))
    {
    goto end; //String
    }
    }

    // instance_restore_status_v1->stage
    cJSON *stage = cJSON_GetObjectItemCaseSensitive(instance_restore_status_v1JSON, "stage");
    if (cJSON_IsNull(stage)) {
        stage = NULL;
    }
    if (stage) { 
    if(!cJSON_IsString(stage) && !cJSON_IsNull(stage))
    {
    goto end; //String
    }
    }

    // instance_restore_status_v1->progress
    cJSON *progress = cJSON_GetObjectItemCaseSensitive(instance_restore_status_v1JSON, "progress");
    if (cJSON_IsNull(progress)) {
        progress = NULL;
    }
    if (progress) { 
    if(!cJSON_IsNumber(progress))
    {
    goto end; //Numeric
    }
    }

    // instance_restore_status_v1->total_progress
    cJSON *total_progress = cJSON_GetObjectItemCaseSensitive(instance_restore_status_v1JSON, "totalProgress");
    if (cJSON_IsNull(total_progress)) {
        total_progress = NULL;
    }
    if (total_progress) { 
    if(!cJSON_IsNumber(total_progress))
    {
    goto end; //Numeric
    }
    }

    // instance_restore_status_v1->heading
    cJSON *heading = cJSON_GetObjectItemCaseSensitive(instance_restore_status_v1JSON, "heading");
    if (cJSON_IsNull(heading)) {
        heading = NULL;
    }
    if (heading) { 
    if(!cJSON_IsString(heading) && !cJSON_IsNull(heading))
    {
    goto end; //String
    }
    }

    // instance_restore_status_v1->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(instance_restore_status_v1JSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }


    instance_restore_status_v1_local_var = instance_restore_status_v1_create_internal (
        type && !cJSON_IsNull(type) ? strdup(type->valuestring) : NULL,
        stage && !cJSON_IsNull(stage) ? strdup(stage->valuestring) : NULL,
        progress ? progress->valuedouble : 0,
        total_progress ? total_progress->valuedouble : 0,
        heading && !cJSON_IsNull(heading) ? strdup(heading->valuestring) : NULL,
        description && !cJSON_IsNull(description) ? strdup(description->valuestring) : NULL
        );

    return instance_restore_status_v1_local_var;
end:
    return NULL;

}
