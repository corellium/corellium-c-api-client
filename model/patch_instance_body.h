/*
 * patch_instance_body.h
 *
 * 
 */

#ifndef _patch_instance_body_H_
#define _patch_instance_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct patch_instance_body_t patch_instance_body_t;

#include "patch_instance_body_boot_options.h"
#include "patch_instance_body_proxy_inner.h"



typedef struct patch_instance_body_t {
    char *name; // string
    struct patch_instance_body_boot_options_t *boot_options; //model
    list_t *proxy; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} patch_instance_body_t;

__attribute__((deprecated)) patch_instance_body_t *patch_instance_body_create(
    char *name,
    patch_instance_body_boot_options_t *boot_options,
    list_t *proxy
);

void patch_instance_body_free(patch_instance_body_t *patch_instance_body);

patch_instance_body_t *patch_instance_body_parseFromJSON(cJSON *patch_instance_bodyJSON);

cJSON *patch_instance_body_convertToJSON(patch_instance_body_t *patch_instance_body);

#endif /* _patch_instance_body_H_ */

