#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "vpn_schema.h"



static vpn_schema_t *vpn_schema_create_internal(
    char *type,
    char *project_id,
    char *state,
    object_t *details
    ) {
    vpn_schema_t *vpn_schema_local_var = malloc(sizeof(vpn_schema_t));
    if (!vpn_schema_local_var) {
        return NULL;
    }
    vpn_schema_local_var->type = type;
    vpn_schema_local_var->project_id = project_id;
    vpn_schema_local_var->state = state;
    vpn_schema_local_var->details = details;

    vpn_schema_local_var->_library_owned = 1;
    return vpn_schema_local_var;
}

__attribute__((deprecated)) vpn_schema_t *vpn_schema_create(
    char *type,
    char *project_id,
    char *state,
    object_t *details
    ) {
    return vpn_schema_create_internal (
        type,
        project_id,
        state,
        details
        );
}

void vpn_schema_free(vpn_schema_t *vpn_schema) {
    if(NULL == vpn_schema){
        return ;
    }
    if(vpn_schema->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "vpn_schema_free");
        return ;
    }
    listEntry_t *listEntry;
    if (vpn_schema->type) {
        free(vpn_schema->type);
        vpn_schema->type = NULL;
    }
    if (vpn_schema->project_id) {
        free(vpn_schema->project_id);
        vpn_schema->project_id = NULL;
    }
    if (vpn_schema->state) {
        free(vpn_schema->state);
        vpn_schema->state = NULL;
    }
    if (vpn_schema->details) {
        object_free(vpn_schema->details);
        vpn_schema->details = NULL;
    }
    free(vpn_schema);
}

cJSON *vpn_schema_convertToJSON(vpn_schema_t *vpn_schema) {
    cJSON *item = cJSON_CreateObject();

    // vpn_schema->type
    if (!vpn_schema->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", vpn_schema->type) == NULL) {
    goto fail; //String
    }


    // vpn_schema->project_id
    if (!vpn_schema->project_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "projectId", vpn_schema->project_id) == NULL) {
    goto fail; //String
    }


    // vpn_schema->state
    if (!vpn_schema->state) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "state", vpn_schema->state) == NULL) {
    goto fail; //String
    }


    // vpn_schema->details
    if (!vpn_schema->details) {
        goto fail;
    }
    cJSON *details_object = object_convertToJSON(vpn_schema->details);
    if(details_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "details", details_object);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

vpn_schema_t *vpn_schema_parseFromJSON(cJSON *vpn_schemaJSON){

    vpn_schema_t *vpn_schema_local_var = NULL;

    // vpn_schema->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(vpn_schemaJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }

    // vpn_schema->project_id
    cJSON *project_id = cJSON_GetObjectItemCaseSensitive(vpn_schemaJSON, "projectId");
    if (cJSON_IsNull(project_id)) {
        project_id = NULL;
    }
    if (!project_id) {
        goto end;
    }

    
    if(!cJSON_IsString(project_id))
    {
    goto end; //String
    }

    // vpn_schema->state
    cJSON *state = cJSON_GetObjectItemCaseSensitive(vpn_schemaJSON, "state");
    if (cJSON_IsNull(state)) {
        state = NULL;
    }
    if (!state) {
        goto end;
    }

    
    if(!cJSON_IsString(state))
    {
    goto end; //String
    }

    // vpn_schema->details
    cJSON *details = cJSON_GetObjectItemCaseSensitive(vpn_schemaJSON, "details");
    if (cJSON_IsNull(details)) {
        details = NULL;
    }
    if (!details) {
        goto end;
    }

    object_t *details_local_object = NULL;
    
    details_local_object = object_parseFromJSON(details); //object


    vpn_schema_local_var = vpn_schema_create_internal (
        strdup(type->valuestring),
        strdup(project_id->valuestring),
        strdup(state->valuestring),
        details_local_object
        );

    return vpn_schema_local_var;
end:
    return NULL;

}
