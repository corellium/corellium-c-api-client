#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "send_reset_link_body.h"



static send_reset_link_body_t *send_reset_link_body_create_internal(
    char *email
    ) {
    send_reset_link_body_t *send_reset_link_body_local_var = malloc(sizeof(send_reset_link_body_t));
    if (!send_reset_link_body_local_var) {
        return NULL;
    }
    send_reset_link_body_local_var->email = email;

    send_reset_link_body_local_var->_library_owned = 1;
    return send_reset_link_body_local_var;
}

__attribute__((deprecated)) send_reset_link_body_t *send_reset_link_body_create(
    char *email
    ) {
    return send_reset_link_body_create_internal (
        email
        );
}

void send_reset_link_body_free(send_reset_link_body_t *send_reset_link_body) {
    if(NULL == send_reset_link_body){
        return ;
    }
    if(send_reset_link_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "send_reset_link_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (send_reset_link_body->email) {
        free(send_reset_link_body->email);
        send_reset_link_body->email = NULL;
    }
    free(send_reset_link_body);
}

cJSON *send_reset_link_body_convertToJSON(send_reset_link_body_t *send_reset_link_body) {
    cJSON *item = cJSON_CreateObject();

    // send_reset_link_body->email
    if(send_reset_link_body->email) {
    if(cJSON_AddStringToObject(item, "email", send_reset_link_body->email) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

send_reset_link_body_t *send_reset_link_body_parseFromJSON(cJSON *send_reset_link_bodyJSON){

    send_reset_link_body_t *send_reset_link_body_local_var = NULL;

    // send_reset_link_body->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(send_reset_link_bodyJSON, "email");
    if (cJSON_IsNull(email)) {
        email = NULL;
    }
    if (email) { 
    if(!cJSON_IsString(email) && !cJSON_IsNull(email))
    {
    goto end; //String
    }
    }


    send_reset_link_body_local_var = send_reset_link_body_create_internal (
        email && !cJSON_IsNull(email) ? strdup(email->valuestring) : NULL
        );

    return send_reset_link_body_local_var;
end:
    return NULL;

}
