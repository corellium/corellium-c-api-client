#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "activity_query_options.h"



static activity_query_options_t *activity_query_options_create_internal(
    object_t *resource,
    double limit,
    double offset,
    char *order_by,
    char *instance_id,
    char *project_id,
    char *actor,
    char *search,
    char *to,
    char *from
    ) {
    activity_query_options_t *activity_query_options_local_var = malloc(sizeof(activity_query_options_t));
    if (!activity_query_options_local_var) {
        return NULL;
    }
    activity_query_options_local_var->resource = resource;
    activity_query_options_local_var->limit = limit;
    activity_query_options_local_var->offset = offset;
    activity_query_options_local_var->order_by = order_by;
    activity_query_options_local_var->instance_id = instance_id;
    activity_query_options_local_var->project_id = project_id;
    activity_query_options_local_var->actor = actor;
    activity_query_options_local_var->search = search;
    activity_query_options_local_var->to = to;
    activity_query_options_local_var->from = from;

    activity_query_options_local_var->_library_owned = 1;
    return activity_query_options_local_var;
}

__attribute__((deprecated)) activity_query_options_t *activity_query_options_create(
    object_t *resource,
    double limit,
    double offset,
    char *order_by,
    char *instance_id,
    char *project_id,
    char *actor,
    char *search,
    char *to,
    char *from
    ) {
    return activity_query_options_create_internal (
        resource,
        limit,
        offset,
        order_by,
        instance_id,
        project_id,
        actor,
        search,
        to,
        from
        );
}

void activity_query_options_free(activity_query_options_t *activity_query_options) {
    if(NULL == activity_query_options){
        return ;
    }
    if(activity_query_options->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "activity_query_options_free");
        return ;
    }
    listEntry_t *listEntry;
    if (activity_query_options->resource) {
        object_free(activity_query_options->resource);
        activity_query_options->resource = NULL;
    }
    if (activity_query_options->order_by) {
        free(activity_query_options->order_by);
        activity_query_options->order_by = NULL;
    }
    if (activity_query_options->instance_id) {
        free(activity_query_options->instance_id);
        activity_query_options->instance_id = NULL;
    }
    if (activity_query_options->project_id) {
        free(activity_query_options->project_id);
        activity_query_options->project_id = NULL;
    }
    if (activity_query_options->actor) {
        free(activity_query_options->actor);
        activity_query_options->actor = NULL;
    }
    if (activity_query_options->search) {
        free(activity_query_options->search);
        activity_query_options->search = NULL;
    }
    if (activity_query_options->to) {
        free(activity_query_options->to);
        activity_query_options->to = NULL;
    }
    if (activity_query_options->from) {
        free(activity_query_options->from);
        activity_query_options->from = NULL;
    }
    free(activity_query_options);
}

cJSON *activity_query_options_convertToJSON(activity_query_options_t *activity_query_options) {
    cJSON *item = cJSON_CreateObject();

    // activity_query_options->resource
    if(activity_query_options->resource) {
    cJSON *resource_object = object_convertToJSON(activity_query_options->resource);
    if(resource_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "resource", resource_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // activity_query_options->limit
    if(activity_query_options->limit) {
    if(cJSON_AddNumberToObject(item, "limit", activity_query_options->limit) == NULL) {
    goto fail; //Numeric
    }
    }


    // activity_query_options->offset
    if(activity_query_options->offset) {
    if(cJSON_AddNumberToObject(item, "offset", activity_query_options->offset) == NULL) {
    goto fail; //Numeric
    }
    }


    // activity_query_options->order_by
    if(activity_query_options->order_by) {
    if(cJSON_AddStringToObject(item, "orderBy", activity_query_options->order_by) == NULL) {
    goto fail; //String
    }
    }


    // activity_query_options->instance_id
    if(activity_query_options->instance_id) {
    if(cJSON_AddStringToObject(item, "instanceId", activity_query_options->instance_id) == NULL) {
    goto fail; //String
    }
    }


    // activity_query_options->project_id
    if(activity_query_options->project_id) {
    if(cJSON_AddStringToObject(item, "projectId", activity_query_options->project_id) == NULL) {
    goto fail; //String
    }
    }


    // activity_query_options->actor
    if(activity_query_options->actor) {
    if(cJSON_AddStringToObject(item, "actor", activity_query_options->actor) == NULL) {
    goto fail; //String
    }
    }


    // activity_query_options->search
    if(activity_query_options->search) {
    if(cJSON_AddStringToObject(item, "search", activity_query_options->search) == NULL) {
    goto fail; //String
    }
    }


    // activity_query_options->to
    if(activity_query_options->to) {
    if(cJSON_AddStringToObject(item, "to", activity_query_options->to) == NULL) {
    goto fail; //Date-Time
    }
    }


    // activity_query_options->from
    if(activity_query_options->from) {
    if(cJSON_AddStringToObject(item, "from", activity_query_options->from) == NULL) {
    goto fail; //Date-Time
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

activity_query_options_t *activity_query_options_parseFromJSON(cJSON *activity_query_optionsJSON){

    activity_query_options_t *activity_query_options_local_var = NULL;

    // activity_query_options->resource
    cJSON *resource = cJSON_GetObjectItemCaseSensitive(activity_query_optionsJSON, "resource");
    if (cJSON_IsNull(resource)) {
        resource = NULL;
    }
    object_t *resource_local_object = NULL;
    if (resource) { 
    resource_local_object = object_parseFromJSON(resource); //object
    }

    // activity_query_options->limit
    cJSON *limit = cJSON_GetObjectItemCaseSensitive(activity_query_optionsJSON, "limit");
    if (cJSON_IsNull(limit)) {
        limit = NULL;
    }
    if (limit) { 
    if(!cJSON_IsNumber(limit))
    {
    goto end; //Numeric
    }
    }

    // activity_query_options->offset
    cJSON *offset = cJSON_GetObjectItemCaseSensitive(activity_query_optionsJSON, "offset");
    if (cJSON_IsNull(offset)) {
        offset = NULL;
    }
    if (offset) { 
    if(!cJSON_IsNumber(offset))
    {
    goto end; //Numeric
    }
    }

    // activity_query_options->order_by
    cJSON *order_by = cJSON_GetObjectItemCaseSensitive(activity_query_optionsJSON, "orderBy");
    if (cJSON_IsNull(order_by)) {
        order_by = NULL;
    }
    if (order_by) { 
    if(!cJSON_IsString(order_by) && !cJSON_IsNull(order_by))
    {
    goto end; //String
    }
    }

    // activity_query_options->instance_id
    cJSON *instance_id = cJSON_GetObjectItemCaseSensitive(activity_query_optionsJSON, "instanceId");
    if (cJSON_IsNull(instance_id)) {
        instance_id = NULL;
    }
    if (instance_id) { 
    if(!cJSON_IsString(instance_id) && !cJSON_IsNull(instance_id))
    {
    goto end; //String
    }
    }

    // activity_query_options->project_id
    cJSON *project_id = cJSON_GetObjectItemCaseSensitive(activity_query_optionsJSON, "projectId");
    if (cJSON_IsNull(project_id)) {
        project_id = NULL;
    }
    if (project_id) { 
    if(!cJSON_IsString(project_id) && !cJSON_IsNull(project_id))
    {
    goto end; //String
    }
    }

    // activity_query_options->actor
    cJSON *actor = cJSON_GetObjectItemCaseSensitive(activity_query_optionsJSON, "actor");
    if (cJSON_IsNull(actor)) {
        actor = NULL;
    }
    if (actor) { 
    if(!cJSON_IsString(actor) && !cJSON_IsNull(actor))
    {
    goto end; //String
    }
    }

    // activity_query_options->search
    cJSON *search = cJSON_GetObjectItemCaseSensitive(activity_query_optionsJSON, "search");
    if (cJSON_IsNull(search)) {
        search = NULL;
    }
    if (search) { 
    if(!cJSON_IsString(search) && !cJSON_IsNull(search))
    {
    goto end; //String
    }
    }

    // activity_query_options->to
    cJSON *to = cJSON_GetObjectItemCaseSensitive(activity_query_optionsJSON, "to");
    if (cJSON_IsNull(to)) {
        to = NULL;
    }
    if (to) { 
    if(!cJSON_IsString(to) && !cJSON_IsNull(to))
    {
    goto end; //DateTime
    }
    }

    // activity_query_options->from
    cJSON *from = cJSON_GetObjectItemCaseSensitive(activity_query_optionsJSON, "from");
    if (cJSON_IsNull(from)) {
        from = NULL;
    }
    if (from) { 
    if(!cJSON_IsString(from) && !cJSON_IsNull(from))
    {
    goto end; //DateTime
    }
    }


    activity_query_options_local_var = activity_query_options_create_internal (
        resource ? resource_local_object : NULL,
        limit ? limit->valuedouble : 0,
        offset ? offset->valuedouble : 0,
        order_by && !cJSON_IsNull(order_by) ? strdup(order_by->valuestring) : NULL,
        instance_id && !cJSON_IsNull(instance_id) ? strdup(instance_id->valuestring) : NULL,
        project_id && !cJSON_IsNull(project_id) ? strdup(project_id->valuestring) : NULL,
        actor && !cJSON_IsNull(actor) ? strdup(actor->valuestring) : NULL,
        search && !cJSON_IsNull(search) ? strdup(search->valuestring) : NULL,
        to && !cJSON_IsNull(to) ? strdup(to->valuestring) : NULL,
        from && !cJSON_IsNull(from) ? strdup(from->valuestring) : NULL
        );

    return activity_query_options_local_var;
end:
    return NULL;

}
