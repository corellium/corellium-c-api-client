#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "text_input_request_v1.h"



static text_input_request_v1_t *text_input_request_v1_create_internal(
    char *required,
    double key_duration
    ) {
    text_input_request_v1_t *text_input_request_v1_local_var = malloc(sizeof(text_input_request_v1_t));
    if (!text_input_request_v1_local_var) {
        return NULL;
    }
    text_input_request_v1_local_var->required = required;
    text_input_request_v1_local_var->key_duration = key_duration;

    text_input_request_v1_local_var->_library_owned = 1;
    return text_input_request_v1_local_var;
}

__attribute__((deprecated)) text_input_request_v1_t *text_input_request_v1_create(
    char *required,
    double key_duration
    ) {
    return text_input_request_v1_create_internal (
        required,
        key_duration
        );
}

void text_input_request_v1_free(text_input_request_v1_t *text_input_request_v1) {
    if(NULL == text_input_request_v1){
        return ;
    }
    if(text_input_request_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "text_input_request_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (text_input_request_v1->required) {
        free(text_input_request_v1->required);
        text_input_request_v1->required = NULL;
    }
    free(text_input_request_v1);
}

cJSON *text_input_request_v1_convertToJSON(text_input_request_v1_t *text_input_request_v1) {
    cJSON *item = cJSON_CreateObject();

    // text_input_request_v1->required
    if (!text_input_request_v1->required) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "required", text_input_request_v1->required) == NULL) {
    goto fail; //String
    }


    // text_input_request_v1->key_duration
    if(text_input_request_v1->key_duration) {
    if(cJSON_AddNumberToObject(item, "keyDuration", text_input_request_v1->key_duration) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

text_input_request_v1_t *text_input_request_v1_parseFromJSON(cJSON *text_input_request_v1JSON){

    text_input_request_v1_t *text_input_request_v1_local_var = NULL;

    // text_input_request_v1->required
    cJSON *required = cJSON_GetObjectItemCaseSensitive(text_input_request_v1JSON, "required");
    if (cJSON_IsNull(required)) {
        required = NULL;
    }
    if (!required) {
        goto end;
    }

    
    if(!cJSON_IsString(required))
    {
    goto end; //String
    }

    // text_input_request_v1->key_duration
    cJSON *key_duration = cJSON_GetObjectItemCaseSensitive(text_input_request_v1JSON, "keyDuration");
    if (cJSON_IsNull(key_duration)) {
        key_duration = NULL;
    }
    if (key_duration) { 
    if(!cJSON_IsNumber(key_duration))
    {
    goto end; //Numeric
    }
    }


    text_input_request_v1_local_var = text_input_request_v1_create_internal (
        strdup(required->valuestring),
        key_duration ? key_duration->valuedouble : 0
        );

    return text_input_request_v1_local_var;
end:
    return NULL;

}
