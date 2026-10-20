#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "service_status_request_body_vms_inner.h"



static service_status_request_body_vms_inner_t *service_status_request_body_vms_inner_create_internal(
    char *identifier
    ) {
    service_status_request_body_vms_inner_t *service_status_request_body_vms_inner_local_var = malloc(sizeof(service_status_request_body_vms_inner_t));
    if (!service_status_request_body_vms_inner_local_var) {
        return NULL;
    }
    service_status_request_body_vms_inner_local_var->identifier = identifier;

    service_status_request_body_vms_inner_local_var->_library_owned = 1;
    return service_status_request_body_vms_inner_local_var;
}

__attribute__((deprecated)) service_status_request_body_vms_inner_t *service_status_request_body_vms_inner_create(
    char *identifier
    ) {
    return service_status_request_body_vms_inner_create_internal (
        identifier
        );
}

void service_status_request_body_vms_inner_free(service_status_request_body_vms_inner_t *service_status_request_body_vms_inner) {
    if(NULL == service_status_request_body_vms_inner){
        return ;
    }
    if(service_status_request_body_vms_inner->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "service_status_request_body_vms_inner_free");
        return ;
    }
    listEntry_t *listEntry;
    if (service_status_request_body_vms_inner->identifier) {
        free(service_status_request_body_vms_inner->identifier);
        service_status_request_body_vms_inner->identifier = NULL;
    }
    free(service_status_request_body_vms_inner);
}

cJSON *service_status_request_body_vms_inner_convertToJSON(service_status_request_body_vms_inner_t *service_status_request_body_vms_inner) {
    cJSON *item = cJSON_CreateObject();

    // service_status_request_body_vms_inner->identifier
    if (!service_status_request_body_vms_inner->identifier) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "identifier", service_status_request_body_vms_inner->identifier) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

service_status_request_body_vms_inner_t *service_status_request_body_vms_inner_parseFromJSON(cJSON *service_status_request_body_vms_innerJSON){

    service_status_request_body_vms_inner_t *service_status_request_body_vms_inner_local_var = NULL;

    // service_status_request_body_vms_inner->identifier
    cJSON *identifier = cJSON_GetObjectItemCaseSensitive(service_status_request_body_vms_innerJSON, "identifier");
    if (cJSON_IsNull(identifier)) {
        identifier = NULL;
    }
    if (!identifier) {
        goto end;
    }

    
    if(!cJSON_IsString(identifier))
    {
    goto end; //String
    }


    service_status_request_body_vms_inner_local_var = service_status_request_body_vms_inner_create_internal (
        strdup(identifier->valuestring)
        );

    return service_status_request_body_vms_inner_local_var;
end:
    return NULL;

}
