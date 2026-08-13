#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "invite_result_error.h"



static invite_result_error_t *invite_result_error_create_internal(
    char *error
    ) {
    invite_result_error_t *invite_result_error_local_var = malloc(sizeof(invite_result_error_t));
    if (!invite_result_error_local_var) {
        return NULL;
    }
    invite_result_error_local_var->error = error;

    invite_result_error_local_var->_library_owned = 1;
    return invite_result_error_local_var;
}

__attribute__((deprecated)) invite_result_error_t *invite_result_error_create(
    char *error
    ) {
    return invite_result_error_create_internal (
        error
        );
}

void invite_result_error_free(invite_result_error_t *invite_result_error) {
    if(NULL == invite_result_error){
        return ;
    }
    if(invite_result_error->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "invite_result_error_free");
        return ;
    }
    listEntry_t *listEntry;
    if (invite_result_error->error) {
        free(invite_result_error->error);
        invite_result_error->error = NULL;
    }
    free(invite_result_error);
}

cJSON *invite_result_error_convertToJSON(invite_result_error_t *invite_result_error) {
    cJSON *item = cJSON_CreateObject();

    // invite_result_error->error
    if (!invite_result_error->error) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "error", invite_result_error->error) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

invite_result_error_t *invite_result_error_parseFromJSON(cJSON *invite_result_errorJSON){

    invite_result_error_t *invite_result_error_local_var = NULL;

    // invite_result_error->error
    cJSON *error = cJSON_GetObjectItemCaseSensitive(invite_result_errorJSON, "error");
    if (cJSON_IsNull(error)) {
        error = NULL;
    }
    if (!error) {
        goto end;
    }

    
    if(!cJSON_IsString(error))
    {
    goto end; //String
    }


    invite_result_error_local_var = invite_result_error_create_internal (
        strdup(error->valuestring)
        );

    return invite_result_error_local_var;
end:
    return NULL;

}
