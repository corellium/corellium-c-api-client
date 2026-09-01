/*
 * update_hook_body.h
 *
 * 
 */

#ifndef _update_hook_body_H_
#define _update_hook_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct update_hook_body_t update_hook_body_t;

#include "hook_patch_type.h"



typedef struct update_hook_body_t {
    char *label; // string
    char *address; // string
    char *patch; // string
    corellium_api_hook_patch_type__e patch_type; //referenced enum
    int enabled; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} update_hook_body_t;

__attribute__((deprecated)) update_hook_body_t *update_hook_body_create(
    char *label,
    char *address,
    char *patch,
    corellium_api_hook_patch_type__e patch_type,
    int enabled
);

void update_hook_body_free(update_hook_body_t *update_hook_body);

update_hook_body_t *update_hook_body_parseFromJSON(cJSON *update_hook_bodyJSON);

cJSON *update_hook_body_convertToJSON(update_hook_body_t *update_hook_body);

#endif /* _update_hook_body_H_ */

