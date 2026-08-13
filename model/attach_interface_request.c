#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "attach_interface_request.h"



static attach_interface_request_t *attach_interface_request_create_internal(
    char *interface_id,
    char *interconnect_id
    ) {
    attach_interface_request_t *attach_interface_request_local_var = malloc(sizeof(attach_interface_request_t));
    if (!attach_interface_request_local_var) {
        return NULL;
    }
    attach_interface_request_local_var->interface_id = interface_id;
    attach_interface_request_local_var->interconnect_id = interconnect_id;

    attach_interface_request_local_var->_library_owned = 1;
    return attach_interface_request_local_var;
}

__attribute__((deprecated)) attach_interface_request_t *attach_interface_request_create(
    char *interface_id,
    char *interconnect_id
    ) {
    return attach_interface_request_create_internal (
        interface_id,
        interconnect_id
        );
}

void attach_interface_request_free(attach_interface_request_t *attach_interface_request) {
    if(NULL == attach_interface_request){
        return ;
    }
    if(attach_interface_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "attach_interface_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (attach_interface_request->interface_id) {
        free(attach_interface_request->interface_id);
        attach_interface_request->interface_id = NULL;
    }
    if (attach_interface_request->interconnect_id) {
        free(attach_interface_request->interconnect_id);
        attach_interface_request->interconnect_id = NULL;
    }
    free(attach_interface_request);
}

cJSON *attach_interface_request_convertToJSON(attach_interface_request_t *attach_interface_request) {
    cJSON *item = cJSON_CreateObject();

    // attach_interface_request->interface_id
    if (!attach_interface_request->interface_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "interfaceId", attach_interface_request->interface_id) == NULL) {
    goto fail; //String
    }


    // attach_interface_request->interconnect_id
    if (!attach_interface_request->interconnect_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "interconnectId", attach_interface_request->interconnect_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

attach_interface_request_t *attach_interface_request_parseFromJSON(cJSON *attach_interface_requestJSON){

    attach_interface_request_t *attach_interface_request_local_var = NULL;

    // attach_interface_request->interface_id
    cJSON *interface_id = cJSON_GetObjectItemCaseSensitive(attach_interface_requestJSON, "interfaceId");
    if (cJSON_IsNull(interface_id)) {
        interface_id = NULL;
    }
    if (!interface_id) {
        goto end;
    }

    
    if(!cJSON_IsString(interface_id))
    {
    goto end; //String
    }

    // attach_interface_request->interconnect_id
    cJSON *interconnect_id = cJSON_GetObjectItemCaseSensitive(attach_interface_requestJSON, "interconnectId");
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


    attach_interface_request_local_var = attach_interface_request_create_internal (
        strdup(interface_id->valuestring),
        strdup(interconnect_id->valuestring)
        );

    return attach_interface_request_local_var;
end:
    return NULL;

}
