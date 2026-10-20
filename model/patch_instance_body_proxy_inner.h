/*
 * patch_instance_body_proxy_inner.h
 *
 * 
 */

#ifndef _patch_instance_body_proxy_inner_H_
#define _patch_instance_body_proxy_inner_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct patch_instance_body_proxy_inner_t patch_instance_body_proxy_inner_t;




typedef struct patch_instance_body_proxy_inner_t {
    double device_port; //numeric
    int first_available; //boolean
    int expose; //boolean
    double router_port; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} patch_instance_body_proxy_inner_t;

__attribute__((deprecated)) patch_instance_body_proxy_inner_t *patch_instance_body_proxy_inner_create(
    double device_port,
    int first_available,
    int expose,
    double router_port
);

void patch_instance_body_proxy_inner_free(patch_instance_body_proxy_inner_t *patch_instance_body_proxy_inner);

patch_instance_body_proxy_inner_t *patch_instance_body_proxy_inner_parseFromJSON(cJSON *patch_instance_body_proxy_innerJSON);

cJSON *patch_instance_body_proxy_inner_convertToJSON(patch_instance_body_proxy_inner_t *patch_instance_body_proxy_inner);

#endif /* _patch_instance_body_proxy_inner_H_ */

