#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "activity_export_dto.h"



static activity_export_dto_t *activity_export_dto_create_internal(
    char *resource,
    char *order_by,
    char *instance,
    char *project,
    char *actor,
    char *search,
    char *to,
    char *from
    ) {
    activity_export_dto_t *activity_export_dto_local_var = malloc(sizeof(activity_export_dto_t));
    if (!activity_export_dto_local_var) {
        return NULL;
    }
    activity_export_dto_local_var->resource = resource;
    activity_export_dto_local_var->order_by = order_by;
    activity_export_dto_local_var->instance = instance;
    activity_export_dto_local_var->project = project;
    activity_export_dto_local_var->actor = actor;
    activity_export_dto_local_var->search = search;
    activity_export_dto_local_var->to = to;
    activity_export_dto_local_var->from = from;

    activity_export_dto_local_var->_library_owned = 1;
    return activity_export_dto_local_var;
}

__attribute__((deprecated)) activity_export_dto_t *activity_export_dto_create(
    char *resource,
    char *order_by,
    char *instance,
    char *project,
    char *actor,
    char *search,
    char *to,
    char *from
    ) {
    return activity_export_dto_create_internal (
        resource,
        order_by,
        instance,
        project,
        actor,
        search,
        to,
        from
        );
}

void activity_export_dto_free(activity_export_dto_t *activity_export_dto) {
    if(NULL == activity_export_dto){
        return ;
    }
    if(activity_export_dto->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "activity_export_dto_free");
        return ;
    }
    listEntry_t *listEntry;
    if (activity_export_dto->resource) {
        free(activity_export_dto->resource);
        activity_export_dto->resource = NULL;
    }
    if (activity_export_dto->order_by) {
        free(activity_export_dto->order_by);
        activity_export_dto->order_by = NULL;
    }
    if (activity_export_dto->instance) {
        free(activity_export_dto->instance);
        activity_export_dto->instance = NULL;
    }
    if (activity_export_dto->project) {
        free(activity_export_dto->project);
        activity_export_dto->project = NULL;
    }
    if (activity_export_dto->actor) {
        free(activity_export_dto->actor);
        activity_export_dto->actor = NULL;
    }
    if (activity_export_dto->search) {
        free(activity_export_dto->search);
        activity_export_dto->search = NULL;
    }
    if (activity_export_dto->to) {
        free(activity_export_dto->to);
        activity_export_dto->to = NULL;
    }
    if (activity_export_dto->from) {
        free(activity_export_dto->from);
        activity_export_dto->from = NULL;
    }
    free(activity_export_dto);
}

cJSON *activity_export_dto_convertToJSON(activity_export_dto_t *activity_export_dto) {
    cJSON *item = cJSON_CreateObject();

    // activity_export_dto->resource
    if(activity_export_dto->resource) {
    if(cJSON_AddStringToObject(item, "resource", activity_export_dto->resource) == NULL) {
    goto fail; //String
    }
    }


    // activity_export_dto->order_by
    if(activity_export_dto->order_by) {
    if(cJSON_AddStringToObject(item, "orderBy", activity_export_dto->order_by) == NULL) {
    goto fail; //String
    }
    }


    // activity_export_dto->instance
    if(activity_export_dto->instance) {
    if(cJSON_AddStringToObject(item, "instance", activity_export_dto->instance) == NULL) {
    goto fail; //String
    }
    }


    // activity_export_dto->project
    if(activity_export_dto->project) {
    if(cJSON_AddStringToObject(item, "project", activity_export_dto->project) == NULL) {
    goto fail; //String
    }
    }


    // activity_export_dto->actor
    if(activity_export_dto->actor) {
    if(cJSON_AddStringToObject(item, "actor", activity_export_dto->actor) == NULL) {
    goto fail; //String
    }
    }


    // activity_export_dto->search
    if(activity_export_dto->search) {
    if(cJSON_AddStringToObject(item, "search", activity_export_dto->search) == NULL) {
    goto fail; //String
    }
    }


    // activity_export_dto->to
    if(activity_export_dto->to) {
    if(cJSON_AddStringToObject(item, "to", activity_export_dto->to) == NULL) {
    goto fail; //String
    }
    }


    // activity_export_dto->from
    if(activity_export_dto->from) {
    if(cJSON_AddStringToObject(item, "from", activity_export_dto->from) == NULL) {
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

activity_export_dto_t *activity_export_dto_parseFromJSON(cJSON *activity_export_dtoJSON){

    activity_export_dto_t *activity_export_dto_local_var = NULL;

    // activity_export_dto->resource
    cJSON *resource = cJSON_GetObjectItemCaseSensitive(activity_export_dtoJSON, "resource");
    if (cJSON_IsNull(resource)) {
        resource = NULL;
    }
    if (resource) { 
    if(!cJSON_IsString(resource) && !cJSON_IsNull(resource))
    {
    goto end; //String
    }
    }

    // activity_export_dto->order_by
    cJSON *order_by = cJSON_GetObjectItemCaseSensitive(activity_export_dtoJSON, "orderBy");
    if (cJSON_IsNull(order_by)) {
        order_by = NULL;
    }
    if (order_by) { 
    if(!cJSON_IsString(order_by) && !cJSON_IsNull(order_by))
    {
    goto end; //String
    }
    }

    // activity_export_dto->instance
    cJSON *instance = cJSON_GetObjectItemCaseSensitive(activity_export_dtoJSON, "instance");
    if (cJSON_IsNull(instance)) {
        instance = NULL;
    }
    if (instance) { 
    if(!cJSON_IsString(instance) && !cJSON_IsNull(instance))
    {
    goto end; //String
    }
    }

    // activity_export_dto->project
    cJSON *project = cJSON_GetObjectItemCaseSensitive(activity_export_dtoJSON, "project");
    if (cJSON_IsNull(project)) {
        project = NULL;
    }
    if (project) { 
    if(!cJSON_IsString(project) && !cJSON_IsNull(project))
    {
    goto end; //String
    }
    }

    // activity_export_dto->actor
    cJSON *actor = cJSON_GetObjectItemCaseSensitive(activity_export_dtoJSON, "actor");
    if (cJSON_IsNull(actor)) {
        actor = NULL;
    }
    if (actor) { 
    if(!cJSON_IsString(actor) && !cJSON_IsNull(actor))
    {
    goto end; //String
    }
    }

    // activity_export_dto->search
    cJSON *search = cJSON_GetObjectItemCaseSensitive(activity_export_dtoJSON, "search");
    if (cJSON_IsNull(search)) {
        search = NULL;
    }
    if (search) { 
    if(!cJSON_IsString(search) && !cJSON_IsNull(search))
    {
    goto end; //String
    }
    }

    // activity_export_dto->to
    cJSON *to = cJSON_GetObjectItemCaseSensitive(activity_export_dtoJSON, "to");
    if (cJSON_IsNull(to)) {
        to = NULL;
    }
    if (to) { 
    if(!cJSON_IsString(to) && !cJSON_IsNull(to))
    {
    goto end; //String
    }
    }

    // activity_export_dto->from
    cJSON *from = cJSON_GetObjectItemCaseSensitive(activity_export_dtoJSON, "from");
    if (cJSON_IsNull(from)) {
        from = NULL;
    }
    if (from) { 
    if(!cJSON_IsString(from) && !cJSON_IsNull(from))
    {
    goto end; //String
    }
    }


    activity_export_dto_local_var = activity_export_dto_create_internal (
        resource && !cJSON_IsNull(resource) ? strdup(resource->valuestring) : NULL,
        order_by && !cJSON_IsNull(order_by) ? strdup(order_by->valuestring) : NULL,
        instance && !cJSON_IsNull(instance) ? strdup(instance->valuestring) : NULL,
        project && !cJSON_IsNull(project) ? strdup(project->valuestring) : NULL,
        actor && !cJSON_IsNull(actor) ? strdup(actor->valuestring) : NULL,
        search && !cJSON_IsNull(search) ? strdup(search->valuestring) : NULL,
        to && !cJSON_IsNull(to) ? strdup(to->valuestring) : NULL,
        from && !cJSON_IsNull(from) ? strdup(from->valuestring) : NULL
        );

    return activity_export_dto_local_var;
end:
    return NULL;

}
