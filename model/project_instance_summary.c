#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "project_instance_summary.h"



static project_instance_summary_t *project_instance_summary_create_internal(
    char *id,
    char *name,
    char *project,
    char *state
    ) {
    project_instance_summary_t *project_instance_summary_local_var = malloc(sizeof(project_instance_summary_t));
    if (!project_instance_summary_local_var) {
        return NULL;
    }
    project_instance_summary_local_var->id = id;
    project_instance_summary_local_var->name = name;
    project_instance_summary_local_var->project = project;
    project_instance_summary_local_var->state = state;

    project_instance_summary_local_var->_library_owned = 1;
    return project_instance_summary_local_var;
}

__attribute__((deprecated)) project_instance_summary_t *project_instance_summary_create(
    char *id,
    char *name,
    char *project,
    char *state
    ) {
    return project_instance_summary_create_internal (
        id,
        name,
        project,
        state
        );
}

void project_instance_summary_free(project_instance_summary_t *project_instance_summary) {
    if(NULL == project_instance_summary){
        return ;
    }
    if(project_instance_summary->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "project_instance_summary_free");
        return ;
    }
    listEntry_t *listEntry;
    if (project_instance_summary->id) {
        free(project_instance_summary->id);
        project_instance_summary->id = NULL;
    }
    if (project_instance_summary->name) {
        free(project_instance_summary->name);
        project_instance_summary->name = NULL;
    }
    if (project_instance_summary->project) {
        free(project_instance_summary->project);
        project_instance_summary->project = NULL;
    }
    if (project_instance_summary->state) {
        free(project_instance_summary->state);
        project_instance_summary->state = NULL;
    }
    free(project_instance_summary);
}

cJSON *project_instance_summary_convertToJSON(project_instance_summary_t *project_instance_summary) {
    cJSON *item = cJSON_CreateObject();

    // project_instance_summary->id
    if (!project_instance_summary->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", project_instance_summary->id) == NULL) {
    goto fail; //String
    }


    // project_instance_summary->name
    if (!project_instance_summary->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", project_instance_summary->name) == NULL) {
    goto fail; //String
    }


    // project_instance_summary->project
    if (!project_instance_summary->project) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "project", project_instance_summary->project) == NULL) {
    goto fail; //String
    }


    // project_instance_summary->state
    if (!project_instance_summary->state) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "state", project_instance_summary->state) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

project_instance_summary_t *project_instance_summary_parseFromJSON(cJSON *project_instance_summaryJSON){

    project_instance_summary_t *project_instance_summary_local_var = NULL;

    // project_instance_summary->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(project_instance_summaryJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }

    // project_instance_summary->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(project_instance_summaryJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // project_instance_summary->project
    cJSON *project = cJSON_GetObjectItemCaseSensitive(project_instance_summaryJSON, "project");
    if (cJSON_IsNull(project)) {
        project = NULL;
    }
    if (!project) {
        goto end;
    }

    
    if(!cJSON_IsString(project))
    {
    goto end; //String
    }

    // project_instance_summary->state
    cJSON *state = cJSON_GetObjectItemCaseSensitive(project_instance_summaryJSON, "state");
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


    project_instance_summary_local_var = project_instance_summary_create_internal (
        strdup(id->valuestring),
        strdup(name->valuestring),
        strdup(project->valuestring),
        strdup(state->valuestring)
        );

    return project_instance_summary_local_var;
end:
    return NULL;

}
