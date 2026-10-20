#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "activity_request.h"



static activity_request_t *activity_request_create_internal(
    char *resource,
    double limit,
    char *order_by,
    double page,
    char *instance,
    char *project,
    char *actor,
    char *search,
    char *to,
    char *from
    ) {
    activity_request_t *activity_request_local_var = malloc(sizeof(activity_request_t));
    if (!activity_request_local_var) {
        return NULL;
    }
    activity_request_local_var->resource = resource;
    activity_request_local_var->limit = limit;
    activity_request_local_var->order_by = order_by;
    activity_request_local_var->page = page;
    activity_request_local_var->instance = instance;
    activity_request_local_var->project = project;
    activity_request_local_var->actor = actor;
    activity_request_local_var->search = search;
    activity_request_local_var->to = to;
    activity_request_local_var->from = from;

    activity_request_local_var->_library_owned = 1;
    return activity_request_local_var;
}

__attribute__((deprecated)) activity_request_t *activity_request_create(
    char *resource,
    double limit,
    char *order_by,
    double page,
    char *instance,
    char *project,
    char *actor,
    char *search,
    char *to,
    char *from
    ) {
    return activity_request_create_internal (
        resource,
        limit,
        order_by,
        page,
        instance,
        project,
        actor,
        search,
        to,
        from
        );
}

void activity_request_free(activity_request_t *activity_request) {
    if(NULL == activity_request){
        return ;
    }
    if(activity_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "activity_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (activity_request->resource) {
        free(activity_request->resource);
        activity_request->resource = NULL;
    }
    if (activity_request->order_by) {
        free(activity_request->order_by);
        activity_request->order_by = NULL;
    }
    if (activity_request->instance) {
        free(activity_request->instance);
        activity_request->instance = NULL;
    }
    if (activity_request->project) {
        free(activity_request->project);
        activity_request->project = NULL;
    }
    if (activity_request->actor) {
        free(activity_request->actor);
        activity_request->actor = NULL;
    }
    if (activity_request->search) {
        free(activity_request->search);
        activity_request->search = NULL;
    }
    if (activity_request->to) {
        free(activity_request->to);
        activity_request->to = NULL;
    }
    if (activity_request->from) {
        free(activity_request->from);
        activity_request->from = NULL;
    }
    free(activity_request);
}

cJSON *activity_request_convertToJSON(activity_request_t *activity_request) {
    cJSON *item = cJSON_CreateObject();

    // activity_request->resource
    if(activity_request->resource) {
    if(cJSON_AddStringToObject(item, "resource", activity_request->resource) == NULL) {
    goto fail; //String
    }
    }


    // activity_request->limit
    if(activity_request->limit) {
    if(cJSON_AddNumberToObject(item, "limit", activity_request->limit) == NULL) {
    goto fail; //Numeric
    }
    }


    // activity_request->order_by
    if(activity_request->order_by) {
    if(cJSON_AddStringToObject(item, "orderBy", activity_request->order_by) == NULL) {
    goto fail; //String
    }
    }


    // activity_request->page
    if(activity_request->page) {
    if(cJSON_AddNumberToObject(item, "page", activity_request->page) == NULL) {
    goto fail; //Numeric
    }
    }


    // activity_request->instance
    if(activity_request->instance) {
    if(cJSON_AddStringToObject(item, "instance", activity_request->instance) == NULL) {
    goto fail; //String
    }
    }


    // activity_request->project
    if(activity_request->project) {
    if(cJSON_AddStringToObject(item, "project", activity_request->project) == NULL) {
    goto fail; //String
    }
    }


    // activity_request->actor
    if(activity_request->actor) {
    if(cJSON_AddStringToObject(item, "actor", activity_request->actor) == NULL) {
    goto fail; //String
    }
    }


    // activity_request->search
    if(activity_request->search) {
    if(cJSON_AddStringToObject(item, "search", activity_request->search) == NULL) {
    goto fail; //String
    }
    }


    // activity_request->to
    if(activity_request->to) {
    if(cJSON_AddStringToObject(item, "to", activity_request->to) == NULL) {
    goto fail; //String
    }
    }


    // activity_request->from
    if(activity_request->from) {
    if(cJSON_AddStringToObject(item, "from", activity_request->from) == NULL) {
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

activity_request_t *activity_request_parseFromJSON(cJSON *activity_requestJSON){

    activity_request_t *activity_request_local_var = NULL;

    // activity_request->resource
    cJSON *resource = cJSON_GetObjectItemCaseSensitive(activity_requestJSON, "resource");
    if (cJSON_IsNull(resource)) {
        resource = NULL;
    }
    if (resource) { 
    if(!cJSON_IsString(resource) && !cJSON_IsNull(resource))
    {
    goto end; //String
    }
    }

    // activity_request->limit
    cJSON *limit = cJSON_GetObjectItemCaseSensitive(activity_requestJSON, "limit");
    if (cJSON_IsNull(limit)) {
        limit = NULL;
    }
    if (limit) { 
    if(!cJSON_IsNumber(limit))
    {
    goto end; //Numeric
    }
    }

    // activity_request->order_by
    cJSON *order_by = cJSON_GetObjectItemCaseSensitive(activity_requestJSON, "orderBy");
    if (cJSON_IsNull(order_by)) {
        order_by = NULL;
    }
    if (order_by) { 
    if(!cJSON_IsString(order_by) && !cJSON_IsNull(order_by))
    {
    goto end; //String
    }
    }

    // activity_request->page
    cJSON *page = cJSON_GetObjectItemCaseSensitive(activity_requestJSON, "page");
    if (cJSON_IsNull(page)) {
        page = NULL;
    }
    if (page) { 
    if(!cJSON_IsNumber(page))
    {
    goto end; //Numeric
    }
    }

    // activity_request->instance
    cJSON *instance = cJSON_GetObjectItemCaseSensitive(activity_requestJSON, "instance");
    if (cJSON_IsNull(instance)) {
        instance = NULL;
    }
    if (instance) { 
    if(!cJSON_IsString(instance) && !cJSON_IsNull(instance))
    {
    goto end; //String
    }
    }

    // activity_request->project
    cJSON *project = cJSON_GetObjectItemCaseSensitive(activity_requestJSON, "project");
    if (cJSON_IsNull(project)) {
        project = NULL;
    }
    if (project) { 
    if(!cJSON_IsString(project) && !cJSON_IsNull(project))
    {
    goto end; //String
    }
    }

    // activity_request->actor
    cJSON *actor = cJSON_GetObjectItemCaseSensitive(activity_requestJSON, "actor");
    if (cJSON_IsNull(actor)) {
        actor = NULL;
    }
    if (actor) { 
    if(!cJSON_IsString(actor) && !cJSON_IsNull(actor))
    {
    goto end; //String
    }
    }

    // activity_request->search
    cJSON *search = cJSON_GetObjectItemCaseSensitive(activity_requestJSON, "search");
    if (cJSON_IsNull(search)) {
        search = NULL;
    }
    if (search) { 
    if(!cJSON_IsString(search) && !cJSON_IsNull(search))
    {
    goto end; //String
    }
    }

    // activity_request->to
    cJSON *to = cJSON_GetObjectItemCaseSensitive(activity_requestJSON, "to");
    if (cJSON_IsNull(to)) {
        to = NULL;
    }
    if (to) { 
    if(!cJSON_IsString(to) && !cJSON_IsNull(to))
    {
    goto end; //String
    }
    }

    // activity_request->from
    cJSON *from = cJSON_GetObjectItemCaseSensitive(activity_requestJSON, "from");
    if (cJSON_IsNull(from)) {
        from = NULL;
    }
    if (from) { 
    if(!cJSON_IsString(from) && !cJSON_IsNull(from))
    {
    goto end; //String
    }
    }


    activity_request_local_var = activity_request_create_internal (
        resource && !cJSON_IsNull(resource) ? strdup(resource->valuestring) : NULL,
        limit ? limit->valuedouble : 0,
        order_by && !cJSON_IsNull(order_by) ? strdup(order_by->valuestring) : NULL,
        page ? page->valuedouble : 0,
        instance && !cJSON_IsNull(instance) ? strdup(instance->valuestring) : NULL,
        project && !cJSON_IsNull(project) ? strdup(project->valuestring) : NULL,
        actor && !cJSON_IsNull(actor) ? strdup(actor->valuestring) : NULL,
        search && !cJSON_IsNull(search) ? strdup(search->valuestring) : NULL,
        to && !cJSON_IsNull(to) ? strdup(to->valuestring) : NULL,
        from && !cJSON_IsNull(from) ? strdup(from->valuestring) : NULL
        );

    return activity_request_local_var;
end:
    return NULL;

}
