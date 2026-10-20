#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "project_network_state.h"



static project_network_state_t *project_network_state_create_internal(
    char *state,
    object_t *details
    ) {
    project_network_state_t *project_network_state_local_var = malloc(sizeof(project_network_state_t));
    if (!project_network_state_local_var) {
        return NULL;
    }
    project_network_state_local_var->state = state;
    project_network_state_local_var->details = details;

    project_network_state_local_var->_library_owned = 1;
    return project_network_state_local_var;
}

__attribute__((deprecated)) project_network_state_t *project_network_state_create(
    char *state,
    object_t *details
    ) {
    return project_network_state_create_internal (
        state,
        details
        );
}

void project_network_state_free(project_network_state_t *project_network_state) {
    if(NULL == project_network_state){
        return ;
    }
    if(project_network_state->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "project_network_state_free");
        return ;
    }
    listEntry_t *listEntry;
    if (project_network_state->state) {
        free(project_network_state->state);
        project_network_state->state = NULL;
    }
    if (project_network_state->details) {
        object_free(project_network_state->details);
        project_network_state->details = NULL;
    }
    free(project_network_state);
}

cJSON *project_network_state_convertToJSON(project_network_state_t *project_network_state) {
    cJSON *item = cJSON_CreateObject();

    // project_network_state->state
    if (!project_network_state->state) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "state", project_network_state->state) == NULL) {
    goto fail; //String
    }


    // project_network_state->details
    if(project_network_state->details) {
    cJSON *details_object = object_convertToJSON(project_network_state->details);
    if(details_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "details", details_object);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

project_network_state_t *project_network_state_parseFromJSON(cJSON *project_network_stateJSON){

    project_network_state_t *project_network_state_local_var = NULL;

    // project_network_state->state
    cJSON *state = cJSON_GetObjectItemCaseSensitive(project_network_stateJSON, "state");
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

    // project_network_state->details
    cJSON *details = cJSON_GetObjectItemCaseSensitive(project_network_stateJSON, "details");
    if (cJSON_IsNull(details)) {
        details = NULL;
    }
    object_t *details_local_object = NULL;
    if (details) { 
    details_local_object = object_parseFromJSON(details); //object
    }


    project_network_state_local_var = project_network_state_create_internal (
        strdup(state->valuestring),
        details ? details_local_object : NULL
        );

    return project_network_state_local_var;
end:
    return NULL;

}
