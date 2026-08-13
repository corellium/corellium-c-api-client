#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "project_key_v1.h"


char* project_key_v1_kind_ToString(corellium_api_project_key_v1_KIND_e kind) {
    char* kindArray[] =  { "NULL", "ssh", "adb" };
    return kindArray[kind];
}

corellium_api_project_key_v1_KIND_e project_key_v1_kind_FromString(char* kind){
    int stringToReturn = 0;
    char *kindArray[] =  { "NULL", "ssh", "adb" };
    size_t sizeofArray = sizeof(kindArray) / sizeof(kindArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(kind, kindArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static project_key_v1_t *project_key_v1_create_internal(
    char *identifier,
    corellium_api_project_key_v1_KIND_e kind,
    char *project,
    char *key,
    char *fingerprint,
    char *updated_at,
    char *created_at
    ) {
    project_key_v1_t *project_key_v1_local_var = malloc(sizeof(project_key_v1_t));
    if (!project_key_v1_local_var) {
        return NULL;
    }
    project_key_v1_local_var->identifier = identifier;
    project_key_v1_local_var->kind = kind;
    project_key_v1_local_var->project = project;
    project_key_v1_local_var->key = key;
    project_key_v1_local_var->fingerprint = fingerprint;
    project_key_v1_local_var->updated_at = updated_at;
    project_key_v1_local_var->created_at = created_at;

    project_key_v1_local_var->_library_owned = 1;
    return project_key_v1_local_var;
}

__attribute__((deprecated)) project_key_v1_t *project_key_v1_create(
    char *identifier,
    corellium_api_project_key_v1_KIND_e kind,
    char *project,
    char *key,
    char *fingerprint,
    char *updated_at,
    char *created_at
    ) {
    return project_key_v1_create_internal (
        identifier,
        kind,
        project,
        key,
        fingerprint,
        updated_at,
        created_at
        );
}

void project_key_v1_free(project_key_v1_t *project_key_v1) {
    if(NULL == project_key_v1){
        return ;
    }
    if(project_key_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "project_key_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (project_key_v1->identifier) {
        free(project_key_v1->identifier);
        project_key_v1->identifier = NULL;
    }
    if (project_key_v1->project) {
        free(project_key_v1->project);
        project_key_v1->project = NULL;
    }
    if (project_key_v1->key) {
        free(project_key_v1->key);
        project_key_v1->key = NULL;
    }
    if (project_key_v1->fingerprint) {
        free(project_key_v1->fingerprint);
        project_key_v1->fingerprint = NULL;
    }
    if (project_key_v1->updated_at) {
        free(project_key_v1->updated_at);
        project_key_v1->updated_at = NULL;
    }
    if (project_key_v1->created_at) {
        free(project_key_v1->created_at);
        project_key_v1->created_at = NULL;
    }
    free(project_key_v1);
}

cJSON *project_key_v1_convertToJSON(project_key_v1_t *project_key_v1) {
    cJSON *item = cJSON_CreateObject();

    // project_key_v1->identifier
    if(project_key_v1->identifier) {
    if(cJSON_AddStringToObject(item, "identifier", project_key_v1->identifier) == NULL) {
    goto fail; //String
    }
    }


    // project_key_v1->kind
    if (corellium_api_project_key_v1_KIND_NULL == project_key_v1->kind) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kind", project_key_v1_kind_ToString(project_key_v1->kind)) == NULL)
    {
    goto fail; //Enum
    }


    // project_key_v1->project
    if(project_key_v1->project) {
    if(cJSON_AddStringToObject(item, "project", project_key_v1->project) == NULL) {
    goto fail; //String
    }
    }


    // project_key_v1->key
    if (!project_key_v1->key) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "key", project_key_v1->key) == NULL) {
    goto fail; //String
    }


    // project_key_v1->fingerprint
    if(project_key_v1->fingerprint) {
    if(cJSON_AddStringToObject(item, "fingerprint", project_key_v1->fingerprint) == NULL) {
    goto fail; //String
    }
    }


    // project_key_v1->updated_at
    if(project_key_v1->updated_at) {
    if(cJSON_AddStringToObject(item, "updatedAt", project_key_v1->updated_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // project_key_v1->created_at
    if(project_key_v1->created_at) {
    if(cJSON_AddStringToObject(item, "createdAt", project_key_v1->created_at) == NULL) {
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

project_key_v1_t *project_key_v1_parseFromJSON(cJSON *project_key_v1JSON){

    project_key_v1_t *project_key_v1_local_var = NULL;

    // project_key_v1->identifier
    cJSON *identifier = cJSON_GetObjectItemCaseSensitive(project_key_v1JSON, "identifier");
    if (cJSON_IsNull(identifier)) {
        identifier = NULL;
    }
    if (identifier) { 
    if(!cJSON_IsString(identifier) && !cJSON_IsNull(identifier))
    {
    goto end; //String
    }
    }

    // project_key_v1->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(project_key_v1JSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (!kind) {
        goto end;
    }

    corellium_api_project_key_v1_KIND_e kindVariable;
    
    if(!cJSON_IsString(kind))
    {
    goto end; //Enum
    }
    kindVariable = project_key_v1_kind_FromString(kind->valuestring);

    // project_key_v1->project
    cJSON *project = cJSON_GetObjectItemCaseSensitive(project_key_v1JSON, "project");
    if (cJSON_IsNull(project)) {
        project = NULL;
    }
    if (project) { 
    if(!cJSON_IsString(project) && !cJSON_IsNull(project))
    {
    goto end; //String
    }
    }

    // project_key_v1->key
    cJSON *key = cJSON_GetObjectItemCaseSensitive(project_key_v1JSON, "key");
    if (cJSON_IsNull(key)) {
        key = NULL;
    }
    if (!key) {
        goto end;
    }

    
    if(!cJSON_IsString(key))
    {
    goto end; //String
    }

    // project_key_v1->fingerprint
    cJSON *fingerprint = cJSON_GetObjectItemCaseSensitive(project_key_v1JSON, "fingerprint");
    if (cJSON_IsNull(fingerprint)) {
        fingerprint = NULL;
    }
    if (fingerprint) { 
    if(!cJSON_IsString(fingerprint) && !cJSON_IsNull(fingerprint))
    {
    goto end; //String
    }
    }

    // project_key_v1->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(project_key_v1JSON, "updatedAt");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (updated_at) { 
    if(!cJSON_IsString(updated_at) && !cJSON_IsNull(updated_at))
    {
    goto end; //DateTime
    }
    }

    // project_key_v1->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(project_key_v1JSON, "createdAt");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (created_at) { 
    if(!cJSON_IsString(created_at) && !cJSON_IsNull(created_at))
    {
    goto end; //DateTime
    }
    }


    project_key_v1_local_var = project_key_v1_create_internal (
        identifier && !cJSON_IsNull(identifier) ? strdup(identifier->valuestring) : NULL,
        kindVariable,
        project && !cJSON_IsNull(project) ? strdup(project->valuestring) : NULL,
        strdup(key->valuestring),
        fingerprint && !cJSON_IsNull(fingerprint) ? strdup(fingerprint->valuestring) : NULL,
        updated_at && !cJSON_IsNull(updated_at) ? strdup(updated_at->valuestring) : NULL,
        created_at && !cJSON_IsNull(created_at) ? strdup(created_at->valuestring) : NULL
        );

    return project_key_v1_local_var;
end:
    return NULL;

}
