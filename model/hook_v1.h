/*
 * hook_v1.h
 *
 * 
 */

#ifndef _hook_v1_H_
#define _hook_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct hook_v1_t hook_v1_t;


// Enum PATCHTYPE for hook_v1

typedef enum  { corellium_api_hook_v1_PATCHTYPE_NULL = 0, corellium_api_hook_v1_PATCHTYPE_csmfcc, corellium_api_hook_v1_PATCHTYPE_csmfvm } corellium_api_hook_v1_PATCHTYPE_e;

char* hook_v1_patch_type_ToString(corellium_api_hook_v1_PATCHTYPE_e patch_type);

corellium_api_hook_v1_PATCHTYPE_e hook_v1_patch_type_FromString(char* patch_type);



typedef struct hook_v1_t {
    char *identifier; // string
    char *label; // string
    char *address; // string
    char *patch; // string
    corellium_api_hook_v1_PATCHTYPE_e patch_type; //enum
    int enabled; //boolean
    char *created_at; // string
    char *updated_at; // string
    char *instance_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} hook_v1_t;

__attribute__((deprecated)) hook_v1_t *hook_v1_create(
    char *identifier,
    char *label,
    char *address,
    char *patch,
    corellium_api_hook_v1_PATCHTYPE_e patch_type,
    int enabled,
    char *created_at,
    char *updated_at,
    char *instance_id
);

void hook_v1_free(hook_v1_t *hook_v1);

hook_v1_t *hook_v1_parseFromJSON(cJSON *hook_v1JSON);

cJSON *hook_v1_convertToJSON(hook_v1_t *hook_v1);

#endif /* _hook_v1_H_ */

