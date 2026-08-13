#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "message_body_any_of_1.h"



static message_body_any_of_1_t *message_body_any_of_1_create_internal(
    char *raw
    ) {
    message_body_any_of_1_t *message_body_any_of_1_local_var = malloc(sizeof(message_body_any_of_1_t));
    if (!message_body_any_of_1_local_var) {
        return NULL;
    }
    message_body_any_of_1_local_var->raw = raw;

    message_body_any_of_1_local_var->_library_owned = 1;
    return message_body_any_of_1_local_var;
}

__attribute__((deprecated)) message_body_any_of_1_t *message_body_any_of_1_create(
    char *raw
    ) {
    return message_body_any_of_1_create_internal (
        raw
        );
}

void message_body_any_of_1_free(message_body_any_of_1_t *message_body_any_of_1) {
    if(NULL == message_body_any_of_1){
        return ;
    }
    if(message_body_any_of_1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "message_body_any_of_1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (message_body_any_of_1->raw) {
        free(message_body_any_of_1->raw);
        message_body_any_of_1->raw = NULL;
    }
    free(message_body_any_of_1);
}

cJSON *message_body_any_of_1_convertToJSON(message_body_any_of_1_t *message_body_any_of_1) {
    cJSON *item = cJSON_CreateObject();

    // message_body_any_of_1->raw
    if (!message_body_any_of_1->raw) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "raw", message_body_any_of_1->raw) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

message_body_any_of_1_t *message_body_any_of_1_parseFromJSON(cJSON *message_body_any_of_1JSON){

    message_body_any_of_1_t *message_body_any_of_1_local_var = NULL;

    // message_body_any_of_1->raw
    cJSON *raw = cJSON_GetObjectItemCaseSensitive(message_body_any_of_1JSON, "raw");
    if (cJSON_IsNull(raw)) {
        raw = NULL;
    }
    if (!raw) {
        goto end;
    }

    
    if(!cJSON_IsString(raw))
    {
    goto end; //String
    }


    message_body_any_of_1_local_var = message_body_any_of_1_create_internal (
        strdup(raw->valuestring)
        );

    return message_body_any_of_1_local_var;
end:
    return NULL;

}
