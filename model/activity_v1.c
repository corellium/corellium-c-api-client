#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "activity_v1.h"



static activity_v1_t *activity_v1_create_internal(
    char *identifier,
    char *domain,
    char *actor,
    char *event,
    char *outcome,
    object_t *metadata,
    char *corellium_version,
    char *project_id,
    char *instance_id,
    char *created_at,
    char *updated_at
    ) {
    activity_v1_t *activity_v1_local_var = malloc(sizeof(activity_v1_t));
    if (!activity_v1_local_var) {
        return NULL;
    }
    activity_v1_local_var->identifier = identifier;
    activity_v1_local_var->domain = domain;
    activity_v1_local_var->actor = actor;
    activity_v1_local_var->event = event;
    activity_v1_local_var->outcome = outcome;
    activity_v1_local_var->metadata = metadata;
    activity_v1_local_var->corellium_version = corellium_version;
    activity_v1_local_var->project_id = project_id;
    activity_v1_local_var->instance_id = instance_id;
    activity_v1_local_var->created_at = created_at;
    activity_v1_local_var->updated_at = updated_at;

    activity_v1_local_var->_library_owned = 1;
    return activity_v1_local_var;
}

__attribute__((deprecated)) activity_v1_t *activity_v1_create(
    char *identifier,
    char *domain,
    char *actor,
    char *event,
    char *outcome,
    object_t *metadata,
    char *corellium_version,
    char *project_id,
    char *instance_id,
    char *created_at,
    char *updated_at
    ) {
    return activity_v1_create_internal (
        identifier,
        domain,
        actor,
        event,
        outcome,
        metadata,
        corellium_version,
        project_id,
        instance_id,
        created_at,
        updated_at
        );
}

void activity_v1_free(activity_v1_t *activity_v1) {
    if(NULL == activity_v1){
        return ;
    }
    if(activity_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "activity_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (activity_v1->identifier) {
        free(activity_v1->identifier);
        activity_v1->identifier = NULL;
    }
    if (activity_v1->domain) {
        free(activity_v1->domain);
        activity_v1->domain = NULL;
    }
    if (activity_v1->actor) {
        free(activity_v1->actor);
        activity_v1->actor = NULL;
    }
    if (activity_v1->event) {
        free(activity_v1->event);
        activity_v1->event = NULL;
    }
    if (activity_v1->outcome) {
        free(activity_v1->outcome);
        activity_v1->outcome = NULL;
    }
    if (activity_v1->metadata) {
        object_free(activity_v1->metadata);
        activity_v1->metadata = NULL;
    }
    if (activity_v1->corellium_version) {
        free(activity_v1->corellium_version);
        activity_v1->corellium_version = NULL;
    }
    if (activity_v1->project_id) {
        free(activity_v1->project_id);
        activity_v1->project_id = NULL;
    }
    if (activity_v1->instance_id) {
        free(activity_v1->instance_id);
        activity_v1->instance_id = NULL;
    }
    if (activity_v1->created_at) {
        free(activity_v1->created_at);
        activity_v1->created_at = NULL;
    }
    if (activity_v1->updated_at) {
        free(activity_v1->updated_at);
        activity_v1->updated_at = NULL;
    }
    free(activity_v1);
}

cJSON *activity_v1_convertToJSON(activity_v1_t *activity_v1) {
    cJSON *item = cJSON_CreateObject();

    // activity_v1->identifier
    if(activity_v1->identifier) {
    if(cJSON_AddStringToObject(item, "identifier", activity_v1->identifier) == NULL) {
    goto fail; //String
    }
    }


    // activity_v1->domain
    if(activity_v1->domain) {
    if(cJSON_AddStringToObject(item, "domain", activity_v1->domain) == NULL) {
    goto fail; //String
    }
    }


    // activity_v1->actor
    if(activity_v1->actor) {
    if(cJSON_AddStringToObject(item, "actor", activity_v1->actor) == NULL) {
    goto fail; //String
    }
    }


    // activity_v1->event
    if(activity_v1->event) {
    if(cJSON_AddStringToObject(item, "event", activity_v1->event) == NULL) {
    goto fail; //String
    }
    }


    // activity_v1->outcome
    if(activity_v1->outcome) {
    if(cJSON_AddStringToObject(item, "outcome", activity_v1->outcome) == NULL) {
    goto fail; //String
    }
    }


    // activity_v1->metadata
    if(activity_v1->metadata) {
    cJSON *metadata_object = object_convertToJSON(activity_v1->metadata);
    if(metadata_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // activity_v1->corellium_version
    if(activity_v1->corellium_version) {
    if(cJSON_AddStringToObject(item, "corelliumVersion", activity_v1->corellium_version) == NULL) {
    goto fail; //String
    }
    }


    // activity_v1->project_id
    if(activity_v1->project_id) {
    if(cJSON_AddStringToObject(item, "projectId", activity_v1->project_id) == NULL) {
    goto fail; //String
    }
    }


    // activity_v1->instance_id
    if(activity_v1->instance_id) {
    if(cJSON_AddStringToObject(item, "instanceId", activity_v1->instance_id) == NULL) {
    goto fail; //String
    }
    }


    // activity_v1->created_at
    if(activity_v1->created_at) {
    if(cJSON_AddStringToObject(item, "createdAt", activity_v1->created_at) == NULL) {
    goto fail; //String
    }
    }


    // activity_v1->updated_at
    if(activity_v1->updated_at) {
    if(cJSON_AddStringToObject(item, "updatedAt", activity_v1->updated_at) == NULL) {
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

activity_v1_t *activity_v1_parseFromJSON(cJSON *activity_v1JSON){

    activity_v1_t *activity_v1_local_var = NULL;

    // activity_v1->identifier
    cJSON *identifier = cJSON_GetObjectItemCaseSensitive(activity_v1JSON, "identifier");
    if (cJSON_IsNull(identifier)) {
        identifier = NULL;
    }
    if (identifier) { 
    if(!cJSON_IsString(identifier) && !cJSON_IsNull(identifier))
    {
    goto end; //String
    }
    }

    // activity_v1->domain
    cJSON *domain = cJSON_GetObjectItemCaseSensitive(activity_v1JSON, "domain");
    if (cJSON_IsNull(domain)) {
        domain = NULL;
    }
    if (domain) { 
    if(!cJSON_IsString(domain) && !cJSON_IsNull(domain))
    {
    goto end; //String
    }
    }

    // activity_v1->actor
    cJSON *actor = cJSON_GetObjectItemCaseSensitive(activity_v1JSON, "actor");
    if (cJSON_IsNull(actor)) {
        actor = NULL;
    }
    if (actor) { 
    if(!cJSON_IsString(actor) && !cJSON_IsNull(actor))
    {
    goto end; //String
    }
    }

    // activity_v1->event
    cJSON *event = cJSON_GetObjectItemCaseSensitive(activity_v1JSON, "event");
    if (cJSON_IsNull(event)) {
        event = NULL;
    }
    if (event) { 
    if(!cJSON_IsString(event) && !cJSON_IsNull(event))
    {
    goto end; //String
    }
    }

    // activity_v1->outcome
    cJSON *outcome = cJSON_GetObjectItemCaseSensitive(activity_v1JSON, "outcome");
    if (cJSON_IsNull(outcome)) {
        outcome = NULL;
    }
    if (outcome) { 
    if(!cJSON_IsString(outcome) && !cJSON_IsNull(outcome))
    {
    goto end; //String
    }
    }

    // activity_v1->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(activity_v1JSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    object_t *metadata_local_object = NULL;
    if (metadata) { 
    metadata_local_object = object_parseFromJSON(metadata); //object
    }

    // activity_v1->corellium_version
    cJSON *corellium_version = cJSON_GetObjectItemCaseSensitive(activity_v1JSON, "corelliumVersion");
    if (cJSON_IsNull(corellium_version)) {
        corellium_version = NULL;
    }
    if (corellium_version) { 
    if(!cJSON_IsString(corellium_version) && !cJSON_IsNull(corellium_version))
    {
    goto end; //String
    }
    }

    // activity_v1->project_id
    cJSON *project_id = cJSON_GetObjectItemCaseSensitive(activity_v1JSON, "projectId");
    if (cJSON_IsNull(project_id)) {
        project_id = NULL;
    }
    if (project_id) { 
    if(!cJSON_IsString(project_id) && !cJSON_IsNull(project_id))
    {
    goto end; //String
    }
    }

    // activity_v1->instance_id
    cJSON *instance_id = cJSON_GetObjectItemCaseSensitive(activity_v1JSON, "instanceId");
    if (cJSON_IsNull(instance_id)) {
        instance_id = NULL;
    }
    if (instance_id) { 
    if(!cJSON_IsString(instance_id) && !cJSON_IsNull(instance_id))
    {
    goto end; //String
    }
    }

    // activity_v1->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(activity_v1JSON, "createdAt");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (created_at) { 
    if(!cJSON_IsString(created_at) && !cJSON_IsNull(created_at))
    {
    goto end; //String
    }
    }

    // activity_v1->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(activity_v1JSON, "updatedAt");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (updated_at) { 
    if(!cJSON_IsString(updated_at) && !cJSON_IsNull(updated_at))
    {
    goto end; //String
    }
    }


    activity_v1_local_var = activity_v1_create_internal (
        identifier && !cJSON_IsNull(identifier) ? strdup(identifier->valuestring) : NULL,
        domain && !cJSON_IsNull(domain) ? strdup(domain->valuestring) : NULL,
        actor && !cJSON_IsNull(actor) ? strdup(actor->valuestring) : NULL,
        event && !cJSON_IsNull(event) ? strdup(event->valuestring) : NULL,
        outcome && !cJSON_IsNull(outcome) ? strdup(outcome->valuestring) : NULL,
        metadata ? metadata_local_object : NULL,
        corellium_version && !cJSON_IsNull(corellium_version) ? strdup(corellium_version->valuestring) : NULL,
        project_id && !cJSON_IsNull(project_id) ? strdup(project_id->valuestring) : NULL,
        instance_id && !cJSON_IsNull(instance_id) ? strdup(instance_id->valuestring) : NULL,
        created_at && !cJSON_IsNull(created_at) ? strdup(created_at->valuestring) : NULL,
        updated_at && !cJSON_IsNull(updated_at) ? strdup(updated_at->valuestring) : NULL
        );

    return activity_v1_local_var;
end:
    return NULL;

}
