#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "start_instance_body.h"



static start_instance_body_t *start_instance_body_create_internal(
    int paused,
    int sock_cap
    ) {
    start_instance_body_t *start_instance_body_local_var = malloc(sizeof(start_instance_body_t));
    if (!start_instance_body_local_var) {
        return NULL;
    }
    start_instance_body_local_var->paused = paused;
    start_instance_body_local_var->sock_cap = sock_cap;

    start_instance_body_local_var->_library_owned = 1;
    return start_instance_body_local_var;
}

__attribute__((deprecated)) start_instance_body_t *start_instance_body_create(
    int paused,
    int sock_cap
    ) {
    return start_instance_body_create_internal (
        paused,
        sock_cap
        );
}

void start_instance_body_free(start_instance_body_t *start_instance_body) {
    if(NULL == start_instance_body){
        return ;
    }
    if(start_instance_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "start_instance_body_free");
        return ;
    }
    listEntry_t *listEntry;
    free(start_instance_body);
}

cJSON *start_instance_body_convertToJSON(start_instance_body_t *start_instance_body) {
    cJSON *item = cJSON_CreateObject();

    // start_instance_body->paused
    if(start_instance_body->paused) {
    if(cJSON_AddBoolToObject(item, "paused", start_instance_body->paused) == NULL) {
    goto fail; //Bool
    }
    }


    // start_instance_body->sock_cap
    if(start_instance_body->sock_cap) {
    if(cJSON_AddBoolToObject(item, "sockCap", start_instance_body->sock_cap) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

start_instance_body_t *start_instance_body_parseFromJSON(cJSON *start_instance_bodyJSON){

    start_instance_body_t *start_instance_body_local_var = NULL;

    // start_instance_body->paused
    cJSON *paused = cJSON_GetObjectItemCaseSensitive(start_instance_bodyJSON, "paused");
    if (cJSON_IsNull(paused)) {
        paused = NULL;
    }
    if (paused) { 
    if(!cJSON_IsBool(paused))
    {
    goto end; //Bool
    }
    }

    // start_instance_body->sock_cap
    cJSON *sock_cap = cJSON_GetObjectItemCaseSensitive(start_instance_bodyJSON, "sockCap");
    if (cJSON_IsNull(sock_cap)) {
        sock_cap = NULL;
    }
    if (sock_cap) { 
    if(!cJSON_IsBool(sock_cap))
    {
    goto end; //Bool
    }
    }


    start_instance_body_local_var = start_instance_body_create_internal (
        paused ? paused->valueint : 0,
        sock_cap ? sock_cap->valueint : 0
        );

    return start_instance_body_local_var;
end:
    return NULL;

}
