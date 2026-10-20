/*
 * patch_instance_read_only_body.h
 *
 * 
 */

#ifndef _patch_instance_read_only_body_H_
#define _patch_instance_read_only_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct patch_instance_read_only_body_t patch_instance_read_only_body_t;




typedef struct patch_instance_read_only_body_t {
    int read_only; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} patch_instance_read_only_body_t;

__attribute__((deprecated)) patch_instance_read_only_body_t *patch_instance_read_only_body_create(
    int read_only
);

void patch_instance_read_only_body_free(patch_instance_read_only_body_t *patch_instance_read_only_body);

patch_instance_read_only_body_t *patch_instance_read_only_body_parseFromJSON(cJSON *patch_instance_read_only_bodyJSON);

cJSON *patch_instance_read_only_body_convertToJSON(patch_instance_read_only_body_t *patch_instance_read_only_body);

#endif /* _patch_instance_read_only_body_H_ */

