/*
 * hook_patch_type.h
 *
 * Language the &#x60;patch&#x60; is written in: &#x60;csmfcc&#x60; for a C-like language, or &#x60;csmfvm&#x60; for an assembly-like language.
 */

#ifndef _hook_patch_type_H_
#define _hook_patch_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct hook_patch_type_t hook_patch_type_t;


// Enum  for hook_patch_type

typedef enum { corellium_api_hook_patch_type__NULL = 0, corellium_api_hook_patch_type__csmfcc, corellium_api_hook_patch_type__csmfvm } corellium_api_hook_patch_type__e;

char* hook_patch_type_hook_patch_type_ToString(corellium_api_hook_patch_type__e hook_patch_type);

corellium_api_hook_patch_type__e hook_patch_type_hook_patch_type_FromString(char* hook_patch_type);

cJSON *hook_patch_type_convertToJSON(corellium_api_hook_patch_type__e hook_patch_type);

corellium_api_hook_patch_type__e hook_patch_type_parseFromJSON(cJSON *hook_patch_typeJSON);

#endif /* _hook_patch_type_H_ */

