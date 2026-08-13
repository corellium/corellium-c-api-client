#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "invite_result.h"



static invite_result_t *invite_result_create_internal(
    invite_result_invite_t *invite,
    invite_result_error_t *error
    ) {
    invite_result_t *invite_result_local_var = malloc(sizeof(invite_result_t));
    if (!invite_result_local_var) {
        return NULL;
    }
    invite_result_local_var->invite = invite;
    invite_result_local_var->error = error;

    invite_result_local_var->_library_owned = 1;
    return invite_result_local_var;
}

__attribute__((deprecated)) invite_result_t *invite_result_create(
    invite_result_invite_t *invite,
    invite_result_error_t *error
    ) {
    return invite_result_create_internal (
        invite,
        error
        );
}

void invite_result_free(invite_result_t *invite_result) {
    if(NULL == invite_result){
        return ;
    }
    if(invite_result->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "invite_result_free");
        return ;
    }
    listEntry_t *listEntry;
    if (invite_result->invite) {
        invite_result_invite_free(invite_result->invite);
        invite_result->invite = NULL;
    }
    if (invite_result->error) {
        invite_result_error_free(invite_result->error);
        invite_result->error = NULL;
    }
    free(invite_result);
}

cJSON *invite_result_convertToJSON(invite_result_t *invite_result) {
    cJSON *item = cJSON_CreateObject();

    // invite_result->invite
    if(invite_result->invite) {
    cJSON *invite_local_JSON = invite_result_invite_convertToJSON(invite_result->invite);
    if(invite_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "invite", invite_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // invite_result->error
    if(invite_result->error) {
    cJSON *error_local_JSON = invite_result_error_convertToJSON(invite_result->error);
    if(error_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "error", error_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

invite_result_t *invite_result_parseFromJSON(cJSON *invite_resultJSON){

    invite_result_t *invite_result_local_var = NULL;

    // define the local variable for invite_result->invite
    invite_result_invite_t *invite_local_nonprim = NULL;

    // define the local variable for invite_result->error
    invite_result_error_t *error_local_nonprim = NULL;

    // invite_result->invite
    cJSON *invite = cJSON_GetObjectItemCaseSensitive(invite_resultJSON, "invite");
    if (cJSON_IsNull(invite)) {
        invite = NULL;
    }
    if (invite) { 
    invite_local_nonprim = invite_result_invite_parseFromJSON(invite); //nonprimitive
    }

    // invite_result->error
    cJSON *error = cJSON_GetObjectItemCaseSensitive(invite_resultJSON, "error");
    if (cJSON_IsNull(error)) {
        error = NULL;
    }
    if (error) { 
    error_local_nonprim = invite_result_error_parseFromJSON(error); //nonprimitive
    }


    invite_result_local_var = invite_result_create_internal (
        invite ? invite_local_nonprim : NULL,
        error ? error_local_nonprim : NULL
        );

    return invite_result_local_var;
end:
    if (invite_local_nonprim) {
        invite_result_invite_free(invite_local_nonprim);
        invite_local_nonprim = NULL;
    }
    if (error_local_nonprim) {
        invite_result_error_free(error_local_nonprim);
        error_local_nonprim = NULL;
    }
    return NULL;

}
