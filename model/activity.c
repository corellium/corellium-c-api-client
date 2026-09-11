#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "activity.h"


char* activity_outcome_ToString(corellium_api_activity_OUTCOME_e outcome) {
    char* outcomeArray[] =  { "NULL", "success", "fail" };
    return outcomeArray[outcome];
}

corellium_api_activity_OUTCOME_e activity_outcome_FromString(char* outcome){
    int stringToReturn = 0;
    char *outcomeArray[] =  { "NULL", "success", "fail" };
    size_t sizeofArray = sizeof(outcomeArray) / sizeof(outcomeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(outcome, outcomeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static activity_t *activity_create_internal(
    char *identifier,
    char *domain,
    char *actor,
    char *event,
    corellium_api_activity_OUTCOME_e outcome,
    object_t *metadata,
    char *corellium_version,
    char *project_id,
    char *instance_id,
    char *created_at,
    char *updated_at
    ) {
    activity_t *activity_local_var = malloc(sizeof(activity_t));
    if (!activity_local_var) {
        return NULL;
    }
    activity_local_var->identifier = identifier;
    activity_local_var->domain = domain;
    activity_local_var->actor = actor;
    activity_local_var->event = event;
    activity_local_var->outcome = outcome;
    activity_local_var->metadata = metadata;
    activity_local_var->corellium_version = corellium_version;
    activity_local_var->project_id = project_id;
    activity_local_var->instance_id = instance_id;
    activity_local_var->created_at = created_at;
    activity_local_var->updated_at = updated_at;

    activity_local_var->_library_owned = 1;
    return activity_local_var;
}

__attribute__((deprecated)) activity_t *activity_create(
    char *identifier,
    char *domain,
    char *actor,
    char *event,
    corellium_api_activity_OUTCOME_e outcome,
    object_t *metadata,
    char *corellium_version,
    char *project_id,
    char *instance_id,
    char *created_at,
    char *updated_at
    ) {
    return activity_create_internal (
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

void activity_free(activity_t *activity) {
    if(NULL == activity){
        return ;
    }
    if(activity->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "activity_free");
        return ;
    }
    listEntry_t *listEntry;
    if (activity->identifier) {
        free(activity->identifier);
        activity->identifier = NULL;
    }
    if (activity->domain) {
        free(activity->domain);
        activity->domain = NULL;
    }
    if (activity->actor) {
        free(activity->actor);
        activity->actor = NULL;
    }
    if (activity->event) {
        free(activity->event);
        activity->event = NULL;
    }
    if (activity->metadata) {
        object_free(activity->metadata);
        activity->metadata = NULL;
    }
    if (activity->corellium_version) {
        free(activity->corellium_version);
        activity->corellium_version = NULL;
    }
    if (activity->project_id) {
        free(activity->project_id);
        activity->project_id = NULL;
    }
    if (activity->instance_id) {
        free(activity->instance_id);
        activity->instance_id = NULL;
    }
    if (activity->created_at) {
        free(activity->created_at);
        activity->created_at = NULL;
    }
    if (activity->updated_at) {
        free(activity->updated_at);
        activity->updated_at = NULL;
    }
    free(activity);
}

cJSON *activity_convertToJSON(activity_t *activity) {
    cJSON *item = cJSON_CreateObject();

    // activity->identifier
    if (!activity->identifier) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "identifier", activity->identifier) == NULL) {
    goto fail; //String
    }


    // activity->domain
    if (!activity->domain) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "domain", activity->domain) == NULL) {
    goto fail; //String
    }


    // activity->actor
    if (!activity->actor) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "actor", activity->actor) == NULL) {
    goto fail; //String
    }


    // activity->event
    if (!activity->event) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "event", activity->event) == NULL) {
    goto fail; //String
    }


    // activity->outcome
    if (corellium_api_activity_OUTCOME_NULL == activity->outcome) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "outcome", activity_outcome_ToString(activity->outcome)) == NULL)
    {
    goto fail; //Enum
    }


    // activity->metadata
    if(activity->metadata) {
    cJSON *metadata_object = object_convertToJSON(activity->metadata);
    if(metadata_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // activity->corellium_version
    if(activity->corellium_version) {
    if(cJSON_AddStringToObject(item, "corelliumVersion", activity->corellium_version) == NULL) {
    goto fail; //String
    }
    }


    // activity->project_id
    if(activity->project_id) {
    if(cJSON_AddStringToObject(item, "projectId", activity->project_id) == NULL) {
    goto fail; //String
    }
    }


    // activity->instance_id
    if(activity->instance_id) {
    if(cJSON_AddStringToObject(item, "instanceId", activity->instance_id) == NULL) {
    goto fail; //String
    }
    }


    // activity->created_at
    if (!activity->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "createdAt", activity->created_at) == NULL) {
    goto fail; //Date-Time
    }


    // activity->updated_at
    if (!activity->updated_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "updatedAt", activity->updated_at) == NULL) {
    goto fail; //Date-Time
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

activity_t *activity_parseFromJSON(cJSON *activityJSON){

    activity_t *activity_local_var = NULL;

    // activity->identifier
    cJSON *identifier = cJSON_GetObjectItemCaseSensitive(activityJSON, "identifier");
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

    // activity->domain
    cJSON *domain = cJSON_GetObjectItemCaseSensitive(activityJSON, "domain");
    if (cJSON_IsNull(domain)) {
        domain = NULL;
    }
    if (!domain) {
        goto end;
    }

    
    if(!cJSON_IsString(domain))
    {
    goto end; //String
    }

    // activity->actor
    cJSON *actor = cJSON_GetObjectItemCaseSensitive(activityJSON, "actor");
    if (cJSON_IsNull(actor)) {
        actor = NULL;
    }
    if (!actor) {
        goto end;
    }

    
    if(!cJSON_IsString(actor))
    {
    goto end; //String
    }

    // activity->event
    cJSON *event = cJSON_GetObjectItemCaseSensitive(activityJSON, "event");
    if (cJSON_IsNull(event)) {
        event = NULL;
    }
    if (!event) {
        goto end;
    }

    
    if(!cJSON_IsString(event))
    {
    goto end; //String
    }

    // activity->outcome
    cJSON *outcome = cJSON_GetObjectItemCaseSensitive(activityJSON, "outcome");
    if (cJSON_IsNull(outcome)) {
        outcome = NULL;
    }
    if (!outcome) {
        goto end;
    }

    corellium_api_activity_OUTCOME_e outcomeVariable;
    
    if(!cJSON_IsString(outcome))
    {
    goto end; //Enum
    }
    outcomeVariable = activity_outcome_FromString(outcome->valuestring);

    // activity->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(activityJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    object_t *metadata_local_object = NULL;
    if (metadata) { 
    metadata_local_object = object_parseFromJSON(metadata); //object
    }

    // activity->corellium_version
    cJSON *corellium_version = cJSON_GetObjectItemCaseSensitive(activityJSON, "corelliumVersion");
    if (cJSON_IsNull(corellium_version)) {
        corellium_version = NULL;
    }
    if (corellium_version) { 
    if(!cJSON_IsString(corellium_version) && !cJSON_IsNull(corellium_version))
    {
    goto end; //String
    }
    }

    // activity->project_id
    cJSON *project_id = cJSON_GetObjectItemCaseSensitive(activityJSON, "projectId");
    if (cJSON_IsNull(project_id)) {
        project_id = NULL;
    }
    if (project_id) { 
    if(!cJSON_IsString(project_id) && !cJSON_IsNull(project_id))
    {
    goto end; //String
    }
    }

    // activity->instance_id
    cJSON *instance_id = cJSON_GetObjectItemCaseSensitive(activityJSON, "instanceId");
    if (cJSON_IsNull(instance_id)) {
        instance_id = NULL;
    }
    if (instance_id) { 
    if(!cJSON_IsString(instance_id) && !cJSON_IsNull(instance_id))
    {
    goto end; //String
    }
    }

    // activity->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(activityJSON, "createdAt");
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

    // activity->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(activityJSON, "updatedAt");
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


    activity_local_var = activity_create_internal (
        strdup(identifier->valuestring),
        strdup(domain->valuestring),
        strdup(actor->valuestring),
        strdup(event->valuestring),
        outcomeVariable,
        metadata ? metadata_local_object : NULL,
        corellium_version && !cJSON_IsNull(corellium_version) ? strdup(corellium_version->valuestring) : NULL,
        project_id && !cJSON_IsNull(project_id) ? strdup(project_id->valuestring) : NULL,
        instance_id && !cJSON_IsNull(instance_id) ? strdup(instance_id->valuestring) : NULL,
        strdup(created_at->valuestring),
        strdup(updated_at->valuestring)
        );

    return activity_local_var;
end:
    return NULL;

}
