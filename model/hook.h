/*
 * hook.h
 *
 * 
 */

#ifndef _hook_H_
#define _hook_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct hook_t hook_t;

#include "hook_patch_type.h"



typedef struct hook_t {
    char *identifier; // string
    char *label; // string
    char *address; // string
    char *patch; // string
    corellium_api_hook_patch_type__e patch_type; //referenced enum
    int enabled; //boolean
    char *instance_id; // string
    char *created_at; //date time
    char *updated_at; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} hook_t;

__attribute__((deprecated)) hook_t *hook_create(
    char *identifier,
    char *label,
    char *address,
    char *patch,
    corellium_api_hook_patch_type__e patch_type,
    int enabled,
    char *instance_id,
    char *created_at,
    char *updated_at
);

void hook_free(hook_t *hook);

hook_t *hook_parseFromJSON(cJSON *hookJSON);

cJSON *hook_convertToJSON(hook_t *hook);

#endif /* _hook_H_ */

