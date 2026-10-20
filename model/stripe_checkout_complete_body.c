#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "stripe_checkout_complete_body.h"



static stripe_checkout_complete_body_t *stripe_checkout_complete_body_create_internal(
    char *session_id
    ) {
    stripe_checkout_complete_body_t *stripe_checkout_complete_body_local_var = malloc(sizeof(stripe_checkout_complete_body_t));
    if (!stripe_checkout_complete_body_local_var) {
        return NULL;
    }
    stripe_checkout_complete_body_local_var->session_id = session_id;

    stripe_checkout_complete_body_local_var->_library_owned = 1;
    return stripe_checkout_complete_body_local_var;
}

__attribute__((deprecated)) stripe_checkout_complete_body_t *stripe_checkout_complete_body_create(
    char *session_id
    ) {
    return stripe_checkout_complete_body_create_internal (
        session_id
        );
}

void stripe_checkout_complete_body_free(stripe_checkout_complete_body_t *stripe_checkout_complete_body) {
    if(NULL == stripe_checkout_complete_body){
        return ;
    }
    if(stripe_checkout_complete_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "stripe_checkout_complete_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (stripe_checkout_complete_body->session_id) {
        free(stripe_checkout_complete_body->session_id);
        stripe_checkout_complete_body->session_id = NULL;
    }
    free(stripe_checkout_complete_body);
}

cJSON *stripe_checkout_complete_body_convertToJSON(stripe_checkout_complete_body_t *stripe_checkout_complete_body) {
    cJSON *item = cJSON_CreateObject();

    // stripe_checkout_complete_body->session_id
    if (!stripe_checkout_complete_body->session_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sessionId", stripe_checkout_complete_body->session_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

stripe_checkout_complete_body_t *stripe_checkout_complete_body_parseFromJSON(cJSON *stripe_checkout_complete_bodyJSON){

    stripe_checkout_complete_body_t *stripe_checkout_complete_body_local_var = NULL;

    // stripe_checkout_complete_body->session_id
    cJSON *session_id = cJSON_GetObjectItemCaseSensitive(stripe_checkout_complete_bodyJSON, "sessionId");
    if (cJSON_IsNull(session_id)) {
        session_id = NULL;
    }
    if (!session_id) {
        goto end;
    }

    
    if(!cJSON_IsString(session_id))
    {
    goto end; //String
    }


    stripe_checkout_complete_body_local_var = stripe_checkout_complete_body_create_internal (
        strdup(session_id->valuestring)
        );

    return stripe_checkout_complete_body_local_var;
end:
    return NULL;

}
