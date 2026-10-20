#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "revoke_invites_response.h"



static revoke_invites_response_t *revoke_invites_response_create_internal(
    double deleted_count
    ) {
    revoke_invites_response_t *revoke_invites_response_local_var = malloc(sizeof(revoke_invites_response_t));
    if (!revoke_invites_response_local_var) {
        return NULL;
    }
    revoke_invites_response_local_var->deleted_count = deleted_count;

    revoke_invites_response_local_var->_library_owned = 1;
    return revoke_invites_response_local_var;
}

__attribute__((deprecated)) revoke_invites_response_t *revoke_invites_response_create(
    double deleted_count
    ) {
    return revoke_invites_response_create_internal (
        deleted_count
        );
}

void revoke_invites_response_free(revoke_invites_response_t *revoke_invites_response) {
    if(NULL == revoke_invites_response){
        return ;
    }
    if(revoke_invites_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "revoke_invites_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(revoke_invites_response);
}

cJSON *revoke_invites_response_convertToJSON(revoke_invites_response_t *revoke_invites_response) {
    cJSON *item = cJSON_CreateObject();

    // revoke_invites_response->deleted_count
    if (!revoke_invites_response->deleted_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "deletedCount", revoke_invites_response->deleted_count) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

revoke_invites_response_t *revoke_invites_response_parseFromJSON(cJSON *revoke_invites_responseJSON){

    revoke_invites_response_t *revoke_invites_response_local_var = NULL;

    // revoke_invites_response->deleted_count
    cJSON *deleted_count = cJSON_GetObjectItemCaseSensitive(revoke_invites_responseJSON, "deletedCount");
    if (cJSON_IsNull(deleted_count)) {
        deleted_count = NULL;
    }
    if (!deleted_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(deleted_count))
    {
    goto end; //Numeric
    }


    revoke_invites_response_local_var = revoke_invites_response_create_internal (
        deleted_count->valuedouble
        );

    return revoke_invites_response_local_var;
end:
    return NULL;

}
