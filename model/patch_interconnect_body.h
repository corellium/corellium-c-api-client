/*
 * patch_interconnect_body.h
 *
 * 
 */

#ifndef _patch_interconnect_body_H_
#define _patch_interconnect_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct patch_interconnect_body_t patch_interconnect_body_t;

#include "interfaces_schema_inner.h"



typedef struct patch_interconnect_body_t {
    char *name; // string
    list_t *interfaces; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} patch_interconnect_body_t;

__attribute__((deprecated)) patch_interconnect_body_t *patch_interconnect_body_create(
    char *name,
    list_t *interfaces
);

void patch_interconnect_body_free(patch_interconnect_body_t *patch_interconnect_body);

patch_interconnect_body_t *patch_interconnect_body_parseFromJSON(cJSON *patch_interconnect_bodyJSON);

cJSON *patch_interconnect_body_convertToJSON(patch_interconnect_body_t *patch_interconnect_body);

#endif /* _patch_interconnect_body_H_ */

