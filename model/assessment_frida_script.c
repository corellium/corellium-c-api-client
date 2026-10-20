#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "assessment_frida_script.h"



static assessment_frida_script_t *assessment_frida_script_create_internal(
    char *id,
    char *name
    ) {
    assessment_frida_script_t *assessment_frida_script_local_var = malloc(sizeof(assessment_frida_script_t));
    if (!assessment_frida_script_local_var) {
        return NULL;
    }
    assessment_frida_script_local_var->id = id;
    assessment_frida_script_local_var->name = name;

    assessment_frida_script_local_var->_library_owned = 1;
    return assessment_frida_script_local_var;
}

__attribute__((deprecated)) assessment_frida_script_t *assessment_frida_script_create(
    char *id,
    char *name
    ) {
    return assessment_frida_script_create_internal (
        id,
        name
        );
}

void assessment_frida_script_free(assessment_frida_script_t *assessment_frida_script) {
    if(NULL == assessment_frida_script){
        return ;
    }
    if(assessment_frida_script->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "assessment_frida_script_free");
        return ;
    }
    listEntry_t *listEntry;
    if (assessment_frida_script->id) {
        free(assessment_frida_script->id);
        assessment_frida_script->id = NULL;
    }
    if (assessment_frida_script->name) {
        free(assessment_frida_script->name);
        assessment_frida_script->name = NULL;
    }
    free(assessment_frida_script);
}

cJSON *assessment_frida_script_convertToJSON(assessment_frida_script_t *assessment_frida_script) {
    cJSON *item = cJSON_CreateObject();

    // assessment_frida_script->id
    if (!assessment_frida_script->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", assessment_frida_script->id) == NULL) {
    goto fail; //String
    }


    // assessment_frida_script->name
    if (!assessment_frida_script->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", assessment_frida_script->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

assessment_frida_script_t *assessment_frida_script_parseFromJSON(cJSON *assessment_frida_scriptJSON){

    assessment_frida_script_t *assessment_frida_script_local_var = NULL;

    // assessment_frida_script->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(assessment_frida_scriptJSON, "id");
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

    // assessment_frida_script->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(assessment_frida_scriptJSON, "name");
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


    assessment_frida_script_local_var = assessment_frida_script_create_internal (
        strdup(id->valuestring),
        strdup(name->valuestring)
        );

    return assessment_frida_script_local_var;
end:
    return NULL;

}
