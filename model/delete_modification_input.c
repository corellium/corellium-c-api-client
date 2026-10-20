#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "delete_modification_input.h"



static delete_modification_input_t *delete_modification_input_create_internal(
    char *check_id,
    char *property
    ) {
    delete_modification_input_t *delete_modification_input_local_var = malloc(sizeof(delete_modification_input_t));
    if (!delete_modification_input_local_var) {
        return NULL;
    }
    delete_modification_input_local_var->check_id = check_id;
    delete_modification_input_local_var->property = property;

    delete_modification_input_local_var->_library_owned = 1;
    return delete_modification_input_local_var;
}

__attribute__((deprecated)) delete_modification_input_t *delete_modification_input_create(
    char *check_id,
    char *property
    ) {
    return delete_modification_input_create_internal (
        check_id,
        property
        );
}

void delete_modification_input_free(delete_modification_input_t *delete_modification_input) {
    if(NULL == delete_modification_input){
        return ;
    }
    if(delete_modification_input->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "delete_modification_input_free");
        return ;
    }
    listEntry_t *listEntry;
    if (delete_modification_input->check_id) {
        free(delete_modification_input->check_id);
        delete_modification_input->check_id = NULL;
    }
    if (delete_modification_input->property) {
        free(delete_modification_input->property);
        delete_modification_input->property = NULL;
    }
    free(delete_modification_input);
}

cJSON *delete_modification_input_convertToJSON(delete_modification_input_t *delete_modification_input) {
    cJSON *item = cJSON_CreateObject();

    // delete_modification_input->check_id
    if (!delete_modification_input->check_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "checkId", delete_modification_input->check_id) == NULL) {
    goto fail; //String
    }


    // delete_modification_input->property
    if (!delete_modification_input->property) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "property", delete_modification_input->property) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

delete_modification_input_t *delete_modification_input_parseFromJSON(cJSON *delete_modification_inputJSON){

    delete_modification_input_t *delete_modification_input_local_var = NULL;

    // delete_modification_input->check_id
    cJSON *check_id = cJSON_GetObjectItemCaseSensitive(delete_modification_inputJSON, "checkId");
    if (cJSON_IsNull(check_id)) {
        check_id = NULL;
    }
    if (!check_id) {
        goto end;
    }

    
    if(!cJSON_IsString(check_id))
    {
    goto end; //String
    }

    // delete_modification_input->property
    cJSON *property = cJSON_GetObjectItemCaseSensitive(delete_modification_inputJSON, "property");
    if (cJSON_IsNull(property)) {
        property = NULL;
    }
    if (!property) {
        goto end;
    }

    
    if(!cJSON_IsString(property))
    {
    goto end; //String
    }


    delete_modification_input_local_var = delete_modification_input_create_internal (
        strdup(check_id->valuestring),
        strdup(property->valuestring)
        );

    return delete_modification_input_local_var;
end:
    return NULL;

}
