/*
 * service_status_request_body_vms_inner.h
 *
 * 
 */

#ifndef _service_status_request_body_vms_inner_H_
#define _service_status_request_body_vms_inner_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct service_status_request_body_vms_inner_t service_status_request_body_vms_inner_t;




typedef struct service_status_request_body_vms_inner_t {
    char *identifier; // string

    int _library_owned; // Is the library responsible for freeing this object?
} service_status_request_body_vms_inner_t;

__attribute__((deprecated)) service_status_request_body_vms_inner_t *service_status_request_body_vms_inner_create(
    char *identifier
);

void service_status_request_body_vms_inner_free(service_status_request_body_vms_inner_t *service_status_request_body_vms_inner);

service_status_request_body_vms_inner_t *service_status_request_body_vms_inner_parseFromJSON(cJSON *service_status_request_body_vms_innerJSON);

cJSON *service_status_request_body_vms_inner_convertToJSON(service_status_request_body_vms_inner_t *service_status_request_body_vms_inner);

#endif /* _service_status_request_body_vms_inner_H_ */

