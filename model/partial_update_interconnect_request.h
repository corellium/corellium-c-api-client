/*
 * partial_update_interconnect_request.h
 *
 * 
 */

#ifndef _partial_update_interconnect_request_H_
#define _partial_update_interconnect_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct partial_update_interconnect_request_t partial_update_interconnect_request_t;

#include "any_type.h"
#include "object.h"



typedef struct partial_update_interconnect_request_t {
    char *name; // string
    list_t *interfaces; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} partial_update_interconnect_request_t;

__attribute__((deprecated)) partial_update_interconnect_request_t *partial_update_interconnect_request_create(
    char *name,
    list_t *interfaces
);

void partial_update_interconnect_request_free(partial_update_interconnect_request_t *partial_update_interconnect_request);

partial_update_interconnect_request_t *partial_update_interconnect_request_parseFromJSON(cJSON *partial_update_interconnect_requestJSON);

cJSON *partial_update_interconnect_request_convertToJSON(partial_update_interconnect_request_t *partial_update_interconnect_request);

#endif /* _partial_update_interconnect_request_H_ */

