#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_activity_export_body.h"



static create_activity_export_body_t *create_activity_export_body_create_internal(
    object_t *resource,
    double offset,
    char *order_by,
    char *instance_id,
    char *project_id,
    char *actor,
    char *search,
    char *to,
    char *from
    ) {
    create_activity_export_body_t *create_activity_export_body_local_var = malloc(sizeof(create_activity_export_body_t));
    if (!create_activity_export_body_local_var) {
        return NULL;
    }
    create_activity_export_body_local_var->resource = resource;
    create_activity_export_body_local_var->offset = offset;
    create_activity_export_body_local_var->order_by = order_by;
    create_activity_export_body_local_var->instance_id = instance_id;
    create_activity_export_body_local_var->project_id = project_id;
    create_activity_export_body_local_var->actor = actor;
    create_activity_export_body_local_var->search = search;
    create_activity_export_body_local_var->to = to;
    create_activity_export_body_local_var->from = from;

    create_activity_export_body_local_var->_library_owned = 1;
    return create_activity_export_body_local_var;
}

__attribute__((deprecated)) create_activity_export_body_t *create_activity_export_body_create(
    object_t *resource,
    double offset,
    char *order_by,
    char *instance_id,
    char *project_id,
    char *actor,
    char *search,
    char *to,
    char *from
    ) {
    return create_activity_export_body_create_internal (
        resource,
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

void create_activity_export_body_free(create_activity_export_body_t *create_activity_export_body) {
    if(NULL == create_activity_export_body){
        return ;
    }
    if(create_activity_export_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "create_activity_export_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (create_activity_export_body->resource) {
        object_free(create_activity_export_body->resource);
        create_activity_export_body->resource = NULL;
    }
    if (create_activity_export_body->order_by) {
        free(create_activity_export_body->order_by);
        create_activity_export_body->order_by = NULL;
    }
    if (create_activity_export_body->instance_id) {
        free(create_activity_export_body->instance_id);
        create_activity_export_body->instance_id = NULL;
    }
    if (create_activity_export_body->project_id) {
        free(create_activity_export_body->project_id);
        create_activity_export_body->project_id = NULL;
    }
    if (create_activity_export_body->actor) {
        free(create_activity_export_body->actor);
        create_activity_export_body->actor = NULL;
    }
    if (create_activity_export_body->search) {
        free(create_activity_export_body->search);
        create_activity_export_body->search = NULL;
    }
    if (create_activity_export_body->to) {
        free(create_activity_export_body->to);
        create_activity_export_body->to = NULL;
    }
    if (create_activity_export_body->from) {
        free(create_activity_export_body->from);
        create_activity_export_body->from = NULL;
    }
    free(create_activity_export_body);
}

cJSON *create_activity_export_body_convertToJSON(create_activity_export_body_t *create_activity_export_body) {
    cJSON *item = cJSON_CreateObject();

    // create_activity_export_body->resource
    if(create_activity_export_body->resource) {
    cJSON *resource_object = object_convertToJSON(create_activity_export_body->resource);
    if(resource_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "resource", resource_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // create_activity_export_body->offset
    if(create_activity_export_body->offset) {
    if(cJSON_AddNumberToObject(item, "offset", create_activity_export_body->offset) == NULL) {
    goto fail; //Numeric
    }
    }


    // create_activity_export_body->order_by
    if(create_activity_export_body->order_by) {
    if(cJSON_AddStringToObject(item, "orderBy", create_activity_export_body->order_by) == NULL) {
    goto fail; //String
    }
    }


    // create_activity_export_body->instance_id
    if(create_activity_export_body->instance_id) {
    if(cJSON_AddStringToObject(item, "instanceId", create_activity_export_body->instance_id) == NULL) {
    goto fail; //String
    }
    }


    // create_activity_export_body->project_id
    if(create_activity_export_body->project_id) {
    if(cJSON_AddStringToObject(item, "projectId", create_activity_export_body->project_id) == NULL) {
    goto fail; //String
    }
    }


    // create_activity_export_body->actor
    if(create_activity_export_body->actor) {
    if(cJSON_AddStringToObject(item, "actor", create_activity_export_body->actor) == NULL) {
    goto fail; //String
    }
    }


    // create_activity_export_body->search
    if(create_activity_export_body->search) {
    if(cJSON_AddStringToObject(item, "search", create_activity_export_body->search) == NULL) {
    goto fail; //String
    }
    }


    // create_activity_export_body->to
    if(create_activity_export_body->to) {
    if(cJSON_AddStringToObject(item, "to", create_activity_export_body->to) == NULL) {
    goto fail; //Date-Time
    }
    }


    // create_activity_export_body->from
    if(create_activity_export_body->from) {
    if(cJSON_AddStringToObject(item, "from", create_activity_export_body->from) == NULL) {
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

create_activity_export_body_t *create_activity_export_body_parseFromJSON(cJSON *create_activity_export_bodyJSON){

    create_activity_export_body_t *create_activity_export_body_local_var = NULL;

    // create_activity_export_body->resource
    cJSON *resource = cJSON_GetObjectItemCaseSensitive(create_activity_export_bodyJSON, "resource");
    if (cJSON_IsNull(resource)) {
        resource = NULL;
    }
    object_t *resource_local_object = NULL;
    if (resource) { 
    resource_local_object = object_parseFromJSON(resource); //object
    }

    // create_activity_export_body->offset
    cJSON *offset = cJSON_GetObjectItemCaseSensitive(create_activity_export_bodyJSON, "offset");
    if (cJSON_IsNull(offset)) {
        offset = NULL;
    }
    if (offset) { 
    if(!cJSON_IsNumber(offset))
    {
    goto end; //Numeric
    }
    }

    // create_activity_export_body->order_by
    cJSON *order_by = cJSON_GetObjectItemCaseSensitive(create_activity_export_bodyJSON, "orderBy");
    if (cJSON_IsNull(order_by)) {
        order_by = NULL;
    }
    if (order_by) { 
    if(!cJSON_IsString(order_by) && !cJSON_IsNull(order_by))
    {
    goto end; //String
    }
    }

    // create_activity_export_body->instance_id
    cJSON *instance_id = cJSON_GetObjectItemCaseSensitive(create_activity_export_bodyJSON, "instanceId");
    if (cJSON_IsNull(instance_id)) {
        instance_id = NULL;
    }
    if (instance_id) { 
    if(!cJSON_IsString(instance_id) && !cJSON_IsNull(instance_id))
    {
    goto end; //String
    }
    }

    // create_activity_export_body->project_id
    cJSON *project_id = cJSON_GetObjectItemCaseSensitive(create_activity_export_bodyJSON, "projectId");
    if (cJSON_IsNull(project_id)) {
        project_id = NULL;
    }
    if (project_id) { 
    if(!cJSON_IsString(project_id) && !cJSON_IsNull(project_id))
    {
    goto end; //String
    }
    }

    // create_activity_export_body->actor
    cJSON *actor = cJSON_GetObjectItemCaseSensitive(create_activity_export_bodyJSON, "actor");
    if (cJSON_IsNull(actor)) {
        actor = NULL;
    }
    if (actor) { 
    if(!cJSON_IsString(actor) && !cJSON_IsNull(actor))
    {
    goto end; //String
    }
    }

    // create_activity_export_body->search
    cJSON *search = cJSON_GetObjectItemCaseSensitive(create_activity_export_bodyJSON, "search");
    if (cJSON_IsNull(search)) {
        search = NULL;
    }
    if (search) { 
    if(!cJSON_IsString(search) && !cJSON_IsNull(search))
    {
    goto end; //String
    }
    }

    // create_activity_export_body->to
    cJSON *to = cJSON_GetObjectItemCaseSensitive(create_activity_export_bodyJSON, "to");
    if (cJSON_IsNull(to)) {
        to = NULL;
    }
    if (to) { 
    if(!cJSON_IsString(to) && !cJSON_IsNull(to))
    {
    goto end; //DateTime
    }
    }

    // create_activity_export_body->from
    cJSON *from = cJSON_GetObjectItemCaseSensitive(create_activity_export_bodyJSON, "from");
    if (cJSON_IsNull(from)) {
        from = NULL;
    }
    if (from) { 
    if(!cJSON_IsString(from) && !cJSON_IsNull(from))
    {
    goto end; //DateTime
    }
    }


    create_activity_export_body_local_var = create_activity_export_body_create_internal (
        resource ? resource_local_object : NULL,
        offset ? offset->valuedouble : 0,
        order_by && !cJSON_IsNull(order_by) ? strdup(order_by->valuestring) : NULL,
        instance_id && !cJSON_IsNull(instance_id) ? strdup(instance_id->valuestring) : NULL,
        project_id && !cJSON_IsNull(project_id) ? strdup(project_id->valuestring) : NULL,
        actor && !cJSON_IsNull(actor) ? strdup(actor->valuestring) : NULL,
        search && !cJSON_IsNull(search) ? strdup(search->valuestring) : NULL,
        to && !cJSON_IsNull(to) ? strdup(to->valuestring) : NULL,
        from && !cJSON_IsNull(from) ? strdup(from->valuestring) : NULL
        );

    return create_activity_export_body_local_var;
end:
    return NULL;

}
