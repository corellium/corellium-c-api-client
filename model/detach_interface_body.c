#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "detach_interface_body.h"



static detach_interface_body_t *detach_interface_body_create_internal(
    char *interconnect_id
    ) {
    detach_interface_body_t *detach_interface_body_local_var = malloc(sizeof(detach_interface_body_t));
    if (!detach_interface_body_local_var) {
        return NULL;
    }
    detach_interface_body_local_var->interconnect_id = interconnect_id;

    detach_interface_body_local_var->_library_owned = 1;
    return detach_interface_body_local_var;
}

__attribute__((deprecated)) detach_interface_body_t *detach_interface_body_create(
    char *interconnect_id
    ) {
    return detach_interface_body_create_internal (
        interconnect_id
        );
}

void detach_interface_body_free(detach_interface_body_t *detach_interface_body) {
    if(NULL == detach_interface_body){
        return ;
    }
    if(detach_interface_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "detach_interface_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (detach_interface_body->interconnect_id) {
        free(detach_interface_body->interconnect_id);
        detach_interface_body->interconnect_id = NULL;
    }
    free(detach_interface_body);
}

cJSON *detach_interface_body_convertToJSON(detach_interface_body_t *detach_interface_body) {
    cJSON *item = cJSON_CreateObject();

    // detach_interface_body->interconnect_id
    if (!detach_interface_body->interconnect_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "interconnectId", detach_interface_body->interconnect_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

detach_interface_body_t *detach_interface_body_parseFromJSON(cJSON *detach_interface_bodyJSON){

    detach_interface_body_t *detach_interface_body_local_var = NULL;

    // detach_interface_body->interconnect_id
    cJSON *interconnect_id = cJSON_GetObjectItemCaseSensitive(detach_interface_bodyJSON, "interconnectId");
    if (cJSON_IsNull(interconnect_id)) {
        interconnect_id = NULL;
    }
    if (!interconnect_id) {
        goto end;
    }

    
    if(!cJSON_IsString(interconnect_id))
    {
    goto end; //String
    }


    detach_interface_body_local_var = detach_interface_body_create_internal (
        strdup(interconnect_id->valuestring)
        );

    return detach_interface_body_local_var;
end:
    return NULL;

}
