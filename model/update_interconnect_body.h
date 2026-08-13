/*
 * update_interconnect_body.h
 *
 * 
 */

#ifndef _update_interconnect_body_H_
#define _update_interconnect_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct update_interconnect_body_t update_interconnect_body_t;

#include "any_type.h"
#include "object.h"



typedef struct update_interconnect_body_t {
    char *name; // string
    list_t *interfaces; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} update_interconnect_body_t;

__attribute__((deprecated)) update_interconnect_body_t *update_interconnect_body_create(
    char *name,
    list_t *interfaces
);

void update_interconnect_body_free(update_interconnect_body_t *update_interconnect_body);

update_interconnect_body_t *update_interconnect_body_parseFromJSON(cJSON *update_interconnect_bodyJSON);

cJSON *update_interconnect_body_convertToJSON(update_interconnect_body_t *update_interconnect_body);

#endif /* _update_interconnect_body_H_ */

