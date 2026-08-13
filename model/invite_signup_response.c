#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "invite_signup_response.h"



static invite_signup_response_t *invite_signup_response_create_internal(
    char *id
    ) {
    invite_signup_response_t *invite_signup_response_local_var = malloc(sizeof(invite_signup_response_t));
    if (!invite_signup_response_local_var) {
        return NULL;
    }
    invite_signup_response_local_var->id = id;

    invite_signup_response_local_var->_library_owned = 1;
    return invite_signup_response_local_var;
}

__attribute__((deprecated)) invite_signup_response_t *invite_signup_response_create(
    char *id
    ) {
    return invite_signup_response_create_internal (
        id
        );
}

void invite_signup_response_free(invite_signup_response_t *invite_signup_response) {
    if(NULL == invite_signup_response){
        return ;
    }
    if(invite_signup_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "invite_signup_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (invite_signup_response->id) {
        free(invite_signup_response->id);
        invite_signup_response->id = NULL;
    }
    free(invite_signup_response);
}

cJSON *invite_signup_response_convertToJSON(invite_signup_response_t *invite_signup_response) {
    cJSON *item = cJSON_CreateObject();

    // invite_signup_response->id
    if (!invite_signup_response->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", invite_signup_response->id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

invite_signup_response_t *invite_signup_response_parseFromJSON(cJSON *invite_signup_responseJSON){

    invite_signup_response_t *invite_signup_response_local_var = NULL;

    // invite_signup_response->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(invite_signup_responseJSON, "id");
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


    invite_signup_response_local_var = invite_signup_response_create_internal (
        strdup(id->valuestring)
        );

    return invite_signup_response_local_var;
end:
    return NULL;

}
