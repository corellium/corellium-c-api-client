/*
 * extension_v1.h
 *
 * 
 */

#ifndef _extension_v1_H_
#define _extension_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct extension_v1_t extension_v1_t;

#include "any_type.h"
#include "object.h"



typedef struct extension_v1_t {
    char *identifier; // string
    int enabled; //boolean
    char *created_at; // string
    char *updated_at; // string
    char *image_id; // string
    char *state; // string
    list_t *flavors; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} extension_v1_t;

__attribute__((deprecated)) extension_v1_t *extension_v1_create(
    char *identifier,
    int enabled,
    char *created_at,
    char *updated_at,
    char *image_id,
    char *state,
    list_t *flavors
);

void extension_v1_free(extension_v1_t *extension_v1);

extension_v1_t *extension_v1_parseFromJSON(cJSON *extension_v1JSON);

cJSON *extension_v1_convertToJSON(extension_v1_t *extension_v1);

#endif /* _extension_v1_H_ */

