#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "text_input_request.h"



static text_input_request_t *text_input_request_create_internal(
    char *text,
    double key_duration
    ) {
    text_input_request_t *text_input_request_local_var = malloc(sizeof(text_input_request_t));
    if (!text_input_request_local_var) {
        return NULL;
    }
    text_input_request_local_var->text = text;
    text_input_request_local_var->key_duration = key_duration;

    text_input_request_local_var->_library_owned = 1;
    return text_input_request_local_var;
}

__attribute__((deprecated)) text_input_request_t *text_input_request_create(
    char *text,
    double key_duration
    ) {
    return text_input_request_create_internal (
        text,
        key_duration
        );
}

void text_input_request_free(text_input_request_t *text_input_request) {
    if(NULL == text_input_request){
        return ;
    }
    if(text_input_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "text_input_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (text_input_request->text) {
        free(text_input_request->text);
        text_input_request->text = NULL;
    }
    free(text_input_request);
}

cJSON *text_input_request_convertToJSON(text_input_request_t *text_input_request) {
    cJSON *item = cJSON_CreateObject();

    // text_input_request->text
    if (!text_input_request->text) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "text", text_input_request->text) == NULL) {
    goto fail; //String
    }


    // text_input_request->key_duration
    if(text_input_request->key_duration) {
    if(cJSON_AddNumberToObject(item, "keyDuration", text_input_request->key_duration) == NULL) {
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

text_input_request_t *text_input_request_parseFromJSON(cJSON *text_input_requestJSON){

    text_input_request_t *text_input_request_local_var = NULL;

    // text_input_request->text
    cJSON *text = cJSON_GetObjectItemCaseSensitive(text_input_requestJSON, "text");
    if (cJSON_IsNull(text)) {
        text = NULL;
    }
    if (!text) {
        goto end;
    }

    
    if(!cJSON_IsString(text))
    {
    goto end; //String
    }

    // text_input_request->key_duration
    cJSON *key_duration = cJSON_GetObjectItemCaseSensitive(text_input_requestJSON, "keyDuration");
    if (cJSON_IsNull(key_duration)) {
        key_duration = NULL;
    }
    if (key_duration) { 
    if(!cJSON_IsNumber(key_duration))
    {
    goto end; //Numeric
    }
    }


    text_input_request_local_var = text_input_request_create_internal (
        strdup(text->valuestring),
        key_duration ? key_duration->valuedouble : 0
        );

    return text_input_request_local_var;
end:
    return NULL;

}
