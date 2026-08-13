#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "stop_instance_body.h"



static stop_instance_body_t *stop_instance_body_create_internal(
    int soft
    ) {
    stop_instance_body_t *stop_instance_body_local_var = malloc(sizeof(stop_instance_body_t));
    if (!stop_instance_body_local_var) {
        return NULL;
    }
    stop_instance_body_local_var->soft = soft;

    stop_instance_body_local_var->_library_owned = 1;
    return stop_instance_body_local_var;
}

__attribute__((deprecated)) stop_instance_body_t *stop_instance_body_create(
    int soft
    ) {
    return stop_instance_body_create_internal (
        soft
        );
}

void stop_instance_body_free(stop_instance_body_t *stop_instance_body) {
    if(NULL == stop_instance_body){
        return ;
    }
    if(stop_instance_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "stop_instance_body_free");
        return ;
    }
    listEntry_t *listEntry;
    free(stop_instance_body);
}

cJSON *stop_instance_body_convertToJSON(stop_instance_body_t *stop_instance_body) {
    cJSON *item = cJSON_CreateObject();

    // stop_instance_body->soft
    if(stop_instance_body->soft) {
    if(cJSON_AddBoolToObject(item, "soft", stop_instance_body->soft) == NULL) {
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

stop_instance_body_t *stop_instance_body_parseFromJSON(cJSON *stop_instance_bodyJSON){

    stop_instance_body_t *stop_instance_body_local_var = NULL;

    // stop_instance_body->soft
    cJSON *soft = cJSON_GetObjectItemCaseSensitive(stop_instance_bodyJSON, "soft");
    if (cJSON_IsNull(soft)) {
        soft = NULL;
    }
    if (soft) { 
    if(!cJSON_IsBool(soft))
    {
    goto end; //Bool
    }
    }


    stop_instance_body_local_var = stop_instance_body_create_internal (
        soft ? soft->valueint : 0
        );

    return stop_instance_body_local_var;
end:
    return NULL;

}
