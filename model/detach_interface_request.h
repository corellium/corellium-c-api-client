/*
 * detach_interface_request.h
 *
 * 
 */

#ifndef _detach_interface_request_H_
#define _detach_interface_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct detach_interface_request_t detach_interface_request_t;




typedef struct detach_interface_request_t {
    char *interconnect_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} detach_interface_request_t;

__attribute__((deprecated)) detach_interface_request_t *detach_interface_request_create(
    char *interconnect_id
);

void detach_interface_request_free(detach_interface_request_t *detach_interface_request);

detach_interface_request_t *detach_interface_request_parseFromJSON(cJSON *detach_interface_requestJSON);

cJSON *detach_interface_request_convertToJSON(detach_interface_request_t *detach_interface_request);

#endif /* _detach_interface_request_H_ */

