/*
 * create_hook_body.h
 *
 * 
 */

#ifndef _create_hook_body_H_
#define _create_hook_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_hook_body_t create_hook_body_t;


// Enum PATCHTYPE for create_hook_body

typedef enum  { corellium_api_create_hook_body_PATCHTYPE_NULL = 0, corellium_api_create_hook_body_PATCHTYPE_csmfcc, corellium_api_create_hook_body_PATCHTYPE_csmfvm } corellium_api_create_hook_body_PATCHTYPE_e;

char* create_hook_body_patch_type_ToString(corellium_api_create_hook_body_PATCHTYPE_e patch_type);

corellium_api_create_hook_body_PATCHTYPE_e create_hook_body_patch_type_FromString(char* patch_type);



typedef struct create_hook_body_t {
    char *label; // string
    char *address; // string
    char *patch; // string
    corellium_api_create_hook_body_PATCHTYPE_e patch_type; //enum
    int enabled; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} create_hook_body_t;

__attribute__((deprecated)) create_hook_body_t *create_hook_body_create(
    char *label,
    char *address,
    char *patch,
    corellium_api_create_hook_body_PATCHTYPE_e patch_type,
    int enabled
);

void create_hook_body_free(create_hook_body_t *create_hook_body);

create_hook_body_t *create_hook_body_parseFromJSON(cJSON *create_hook_bodyJSON);

cJSON *create_hook_body_convertToJSON(create_hook_body_t *create_hook_body);

#endif /* _create_hook_body_H_ */

