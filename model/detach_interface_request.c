#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "detach_interface_request.h"



static detach_interface_request_t *detach_interface_request_create_internal(
    char *interconnect_id
    ) {
    detach_interface_request_t *detach_interface_request_local_var = malloc(sizeof(detach_interface_request_t));
    if (!detach_interface_request_local_var) {
        return NULL;
    }
    detach_interface_request_local_var->interconnect_id = interconnect_id;

    detach_interface_request_local_var->_library_owned = 1;
    return detach_interface_request_local_var;
}

__attribute__((deprecated)) detach_interface_request_t *detach_interface_request_create(
    char *interconnect_id
    ) {
    return detach_interface_request_create_internal (
        interconnect_id
        );
}

void detach_interface_request_free(detach_interface_request_t *detach_interface_request) {
    if(NULL == detach_interface_request){
        return ;
    }
    if(detach_interface_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "detach_interface_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (detach_interface_request->interconnect_id) {
        free(detach_interface_request->interconnect_id);
        detach_interface_request->interconnect_id = NULL;
    }
    free(detach_interface_request);
}

cJSON *detach_interface_request_convertToJSON(detach_interface_request_t *detach_interface_request) {
    cJSON *item = cJSON_CreateObject();

    // detach_interface_request->interconnect_id
    if (!detach_interface_request->interconnect_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "interconnectId", detach_interface_request->interconnect_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

detach_interface_request_t *detach_interface_request_parseFromJSON(cJSON *detach_interface_requestJSON){

    detach_interface_request_t *detach_interface_request_local_var = NULL;

    // detach_interface_request->interconnect_id
    cJSON *interconnect_id = cJSON_GetObjectItemCaseSensitive(detach_interface_requestJSON, "interconnectId");
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


    detach_interface_request_local_var = detach_interface_request_create_internal (
        strdup(interconnect_id->valuestring)
        );

    return detach_interface_request_local_var;
end:
    return NULL;

}
