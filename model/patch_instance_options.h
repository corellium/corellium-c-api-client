/*
 * patch_instance_options.h
 *
 * 
 */

#ifndef _patch_instance_options_H_
#define _patch_instance_options_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct patch_instance_options_t patch_instance_options_t;

#include "instance_boot_options_v1.h"
#include "proxy_config.h"

// Enum STATE for patch_instance_options

typedef enum  { corellium_api_patch_instance_options_STATE_NULL = 0, corellium_api_patch_instance_options_STATE_on, corellium_api_patch_instance_options_STATE_off, corellium_api_patch_instance_options_STATE_paused, corellium_api_patch_instance_options_STATE_deleting } corellium_api_patch_instance_options_STATE_e;

char* patch_instance_options_state_ToString(corellium_api_patch_instance_options_STATE_e state);

corellium_api_patch_instance_options_STATE_e patch_instance_options_state_FromString(char* state);



typedef struct patch_instance_options_t {
    char *name; // string
    corellium_api_patch_instance_options_STATE_e state; //enum
    struct instance_boot_options_v1_t *boot_options; //model
    list_t *proxy; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} patch_instance_options_t;

__attribute__((deprecated)) patch_instance_options_t *patch_instance_options_create(
    char *name,
    corellium_api_patch_instance_options_STATE_e state,
    instance_boot_options_v1_t *boot_options,
    list_t *proxy
);

void patch_instance_options_free(patch_instance_options_t *patch_instance_options);

patch_instance_options_t *patch_instance_options_parseFromJSON(cJSON *patch_instance_optionsJSON);

cJSON *patch_instance_options_convertToJSON(patch_instance_options_t *patch_instance_options);

#endif /* _patch_instance_options_H_ */

