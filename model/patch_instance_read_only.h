/*
 * patch_instance_read_only.h
 *
 * 
 */

#ifndef _patch_instance_read_only_H_
#define _patch_instance_read_only_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct patch_instance_read_only_t patch_instance_read_only_t;




typedef struct patch_instance_read_only_t {
    char *read_only; // string

    int _library_owned; // Is the library responsible for freeing this object?
} patch_instance_read_only_t;

__attribute__((deprecated)) patch_instance_read_only_t *patch_instance_read_only_create(
    char *read_only
);

void patch_instance_read_only_free(patch_instance_read_only_t *patch_instance_read_only);

patch_instance_read_only_t *patch_instance_read_only_parseFromJSON(cJSON *patch_instance_read_onlyJSON);

cJSON *patch_instance_read_only_convertToJSON(patch_instance_read_only_t *patch_instance_read_only);

#endif /* _patch_instance_read_only_H_ */

