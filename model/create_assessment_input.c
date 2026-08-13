#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_assessment_input.h"



static create_assessment_input_t *create_assessment_input_create_internal(
    char *instance_id,
    char *bundle_id,
    char *wordlist_id,
    char *frida_script_id,
    char *created_by
    ) {
    create_assessment_input_t *create_assessment_input_local_var = malloc(sizeof(create_assessment_input_t));
    if (!create_assessment_input_local_var) {
        return NULL;
    }
    create_assessment_input_local_var->instance_id = instance_id;
    create_assessment_input_local_var->bundle_id = bundle_id;
    create_assessment_input_local_var->wordlist_id = wordlist_id;
    create_assessment_input_local_var->frida_script_id = frida_script_id;
    create_assessment_input_local_var->created_by = created_by;

    create_assessment_input_local_var->_library_owned = 1;
    return create_assessment_input_local_var;
}

__attribute__((deprecated)) create_assessment_input_t *create_assessment_input_create(
    char *instance_id,
    char *bundle_id,
    char *wordlist_id,
    char *frida_script_id,
    char *created_by
    ) {
    return create_assessment_input_create_internal (
        instance_id,
        bundle_id,
        wordlist_id,
        frida_script_id,
        created_by
        );
}

void create_assessment_input_free(create_assessment_input_t *create_assessment_input) {
    if(NULL == create_assessment_input){
        return ;
    }
    if(create_assessment_input->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "create_assessment_input_free");
        return ;
    }
    listEntry_t *listEntry;
    if (create_assessment_input->instance_id) {
        free(create_assessment_input->instance_id);
        create_assessment_input->instance_id = NULL;
    }
    if (create_assessment_input->bundle_id) {
        free(create_assessment_input->bundle_id);
        create_assessment_input->bundle_id = NULL;
    }
    if (create_assessment_input->wordlist_id) {
        free(create_assessment_input->wordlist_id);
        create_assessment_input->wordlist_id = NULL;
    }
    if (create_assessment_input->frida_script_id) {
        free(create_assessment_input->frida_script_id);
        create_assessment_input->frida_script_id = NULL;
    }
    if (create_assessment_input->created_by) {
        free(create_assessment_input->created_by);
        create_assessment_input->created_by = NULL;
    }
    free(create_assessment_input);
}

cJSON *create_assessment_input_convertToJSON(create_assessment_input_t *create_assessment_input) {
    cJSON *item = cJSON_CreateObject();

    // create_assessment_input->instance_id
    if (!create_assessment_input->instance_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "instanceId", create_assessment_input->instance_id) == NULL) {
    goto fail; //String
    }


    // create_assessment_input->bundle_id
    if (!create_assessment_input->bundle_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "bundleId", create_assessment_input->bundle_id) == NULL) {
    goto fail; //String
    }


    // create_assessment_input->wordlist_id
    if(create_assessment_input->wordlist_id) {
    if(cJSON_AddStringToObject(item, "wordlistId", create_assessment_input->wordlist_id) == NULL) {
    goto fail; //String
    }
    }


    // create_assessment_input->frida_script_id
    if(create_assessment_input->frida_script_id) {
    if(cJSON_AddStringToObject(item, "fridaScriptId", create_assessment_input->frida_script_id) == NULL) {
    goto fail; //String
    }
    }


    // create_assessment_input->created_by
    if(create_assessment_input->created_by) {
    if(cJSON_AddStringToObject(item, "createdBy", create_assessment_input->created_by) == NULL) {
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

create_assessment_input_t *create_assessment_input_parseFromJSON(cJSON *create_assessment_inputJSON){

    create_assessment_input_t *create_assessment_input_local_var = NULL;

    // create_assessment_input->instance_id
    cJSON *instance_id = cJSON_GetObjectItemCaseSensitive(create_assessment_inputJSON, "instanceId");
    if (cJSON_IsNull(instance_id)) {
        instance_id = NULL;
    }
    if (!instance_id) {
        goto end;
    }

    
    if(!cJSON_IsString(instance_id))
    {
    goto end; //String
    }

    // create_assessment_input->bundle_id
    cJSON *bundle_id = cJSON_GetObjectItemCaseSensitive(create_assessment_inputJSON, "bundleId");
    if (cJSON_IsNull(bundle_id)) {
        bundle_id = NULL;
    }
    if (!bundle_id) {
        goto end;
    }

    
    if(!cJSON_IsString(bundle_id))
    {
    goto end; //String
    }

    // create_assessment_input->wordlist_id
    cJSON *wordlist_id = cJSON_GetObjectItemCaseSensitive(create_assessment_inputJSON, "wordlistId");
    if (cJSON_IsNull(wordlist_id)) {
        wordlist_id = NULL;
    }
    if (wordlist_id) { 
    if(!cJSON_IsString(wordlist_id) && !cJSON_IsNull(wordlist_id))
    {
    goto end; //String
    }
    }

    // create_assessment_input->frida_script_id
    cJSON *frida_script_id = cJSON_GetObjectItemCaseSensitive(create_assessment_inputJSON, "fridaScriptId");
    if (cJSON_IsNull(frida_script_id)) {
        frida_script_id = NULL;
    }
    if (frida_script_id) { 
    if(!cJSON_IsString(frida_script_id) && !cJSON_IsNull(frida_script_id))
    {
    goto end; //String
    }
    }

    // create_assessment_input->created_by
    cJSON *created_by = cJSON_GetObjectItemCaseSensitive(create_assessment_inputJSON, "createdBy");
    if (cJSON_IsNull(created_by)) {
        created_by = NULL;
    }
    if (created_by) { 
    if(!cJSON_IsString(created_by) && !cJSON_IsNull(created_by))
    {
    goto end; //String
    }
    }


    create_assessment_input_local_var = create_assessment_input_create_internal (
        strdup(instance_id->valuestring),
        strdup(bundle_id->valuestring),
        wordlist_id && !cJSON_IsNull(wordlist_id) ? strdup(wordlist_id->valuestring) : NULL,
        frida_script_id && !cJSON_IsNull(frida_script_id) ? strdup(frida_script_id->valuestring) : NULL,
        created_by && !cJSON_IsNull(created_by) ? strdup(created_by->valuestring) : NULL
        );

    return create_assessment_input_local_var;
end:
    return NULL;

}
