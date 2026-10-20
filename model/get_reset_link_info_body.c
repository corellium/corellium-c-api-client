#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_reset_link_info_body.h"



static get_reset_link_info_body_t *get_reset_link_info_body_create_internal(
    char *token
    ) {
    get_reset_link_info_body_t *get_reset_link_info_body_local_var = malloc(sizeof(get_reset_link_info_body_t));
    if (!get_reset_link_info_body_local_var) {
        return NULL;
    }
    get_reset_link_info_body_local_var->token = token;

    get_reset_link_info_body_local_var->_library_owned = 1;
    return get_reset_link_info_body_local_var;
}

__attribute__((deprecated)) get_reset_link_info_body_t *get_reset_link_info_body_create(
    char *token
    ) {
    return get_reset_link_info_body_create_internal (
        token
        );
}

void get_reset_link_info_body_free(get_reset_link_info_body_t *get_reset_link_info_body) {
    if(NULL == get_reset_link_info_body){
        return ;
    }
    if(get_reset_link_info_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "get_reset_link_info_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (get_reset_link_info_body->token) {
        free(get_reset_link_info_body->token);
        get_reset_link_info_body->token = NULL;
    }
    free(get_reset_link_info_body);
}

cJSON *get_reset_link_info_body_convertToJSON(get_reset_link_info_body_t *get_reset_link_info_body) {
    cJSON *item = cJSON_CreateObject();

    // get_reset_link_info_body->token
    if (!get_reset_link_info_body->token) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "token", get_reset_link_info_body->token) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

get_reset_link_info_body_t *get_reset_link_info_body_parseFromJSON(cJSON *get_reset_link_info_bodyJSON){

    get_reset_link_info_body_t *get_reset_link_info_body_local_var = NULL;

    // get_reset_link_info_body->token
    cJSON *token = cJSON_GetObjectItemCaseSensitive(get_reset_link_info_bodyJSON, "token");
    if (cJSON_IsNull(token)) {
        token = NULL;
    }
    if (!token) {
        goto end;
    }

    
    if(!cJSON_IsString(token))
    {
    goto end; //String
    }


    get_reset_link_info_body_local_var = get_reset_link_info_body_create_internal (
        strdup(token->valuestring)
        );

    return get_reset_link_info_body_local_var;
end:
    return NULL;

}
