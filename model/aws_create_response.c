#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "aws_create_response.h"



static aws_create_response_t *aws_create_response_create_internal(
    int ready,
    int is_authed
    ) {
    aws_create_response_t *aws_create_response_local_var = malloc(sizeof(aws_create_response_t));
    if (!aws_create_response_local_var) {
        return NULL;
    }
    aws_create_response_local_var->ready = ready;
    aws_create_response_local_var->is_authed = is_authed;

    aws_create_response_local_var->_library_owned = 1;
    return aws_create_response_local_var;
}

__attribute__((deprecated)) aws_create_response_t *aws_create_response_create(
    int ready,
    int is_authed
    ) {
    return aws_create_response_create_internal (
        ready,
        is_authed
        );
}

void aws_create_response_free(aws_create_response_t *aws_create_response) {
    if(NULL == aws_create_response){
        return ;
    }
    if(aws_create_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "aws_create_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(aws_create_response);
}

cJSON *aws_create_response_convertToJSON(aws_create_response_t *aws_create_response) {
    cJSON *item = cJSON_CreateObject();

    // aws_create_response->ready
    if (!aws_create_response->ready) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ready", aws_create_response->ready) == NULL) {
    goto fail; //Bool
    }


    // aws_create_response->is_authed
    if (!aws_create_response->is_authed) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "isAuthed", aws_create_response->is_authed) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

aws_create_response_t *aws_create_response_parseFromJSON(cJSON *aws_create_responseJSON){

    aws_create_response_t *aws_create_response_local_var = NULL;

    // aws_create_response->ready
    cJSON *ready = cJSON_GetObjectItemCaseSensitive(aws_create_responseJSON, "ready");
    if (cJSON_IsNull(ready)) {
        ready = NULL;
    }
    if (!ready) {
        goto end;
    }

    
    if(!cJSON_IsBool(ready))
    {
    goto end; //Bool
    }

    // aws_create_response->is_authed
    cJSON *is_authed = cJSON_GetObjectItemCaseSensitive(aws_create_responseJSON, "isAuthed");
    if (cJSON_IsNull(is_authed)) {
        is_authed = NULL;
    }
    if (!is_authed) {
        goto end;
    }

    
    if(!cJSON_IsBool(is_authed))
    {
    goto end; //Bool
    }


    aws_create_response_local_var = aws_create_response_create_internal (
        ready->valueint,
        is_authed->valueint
        );

    return aws_create_response_local_var;
end:
    return NULL;

}
