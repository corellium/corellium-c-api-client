/*
 * attach_interface_request.h
 *
 * 
 */

#ifndef _attach_interface_request_H_
#define _attach_interface_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct attach_interface_request_t attach_interface_request_t;




typedef struct attach_interface_request_t {
    char *interface_id; // string
    char *interconnect_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} attach_interface_request_t;

__attribute__((deprecated)) attach_interface_request_t *attach_interface_request_create(
    char *interface_id,
    char *interconnect_id
);

void attach_interface_request_free(attach_interface_request_t *attach_interface_request);

attach_interface_request_t *attach_interface_request_parseFromJSON(cJSON *attach_interface_requestJSON);

cJSON *attach_interface_request_convertToJSON(attach_interface_request_t *attach_interface_request);

#endif /* _attach_interface_request_H_ */

