/*
 * patch_instance_body_strace_filter_inner.h
 *
 * 
 */

#ifndef _patch_instance_body_strace_filter_inner_H_
#define _patch_instance_body_strace_filter_inner_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct patch_instance_body_strace_filter_inner_t patch_instance_body_strace_filter_inner_t;


// Enum TRAIT for patch_instance_body_strace_filter_inner

typedef enum  { corellium_api_patch_instance_body_strace_filter_inner_TRAIT_NULL = 0, corellium_api_patch_instance_body_strace_filter_inner_TRAIT_name, corellium_api_patch_instance_body_strace_filter_inner_TRAIT_pid, corellium_api_patch_instance_body_strace_filter_inner_TRAIT_tid } corellium_api_patch_instance_body_strace_filter_inner_TRAIT_e;

char* patch_instance_body_strace_filter_inner_trait_ToString(corellium_api_patch_instance_body_strace_filter_inner_TRAIT_e trait);

corellium_api_patch_instance_body_strace_filter_inner_TRAIT_e patch_instance_body_strace_filter_inner_trait_FromString(char* trait);



typedef struct patch_instance_body_strace_filter_inner_t {
    corellium_api_patch_instance_body_strace_filter_inner_TRAIT_e trait; //enum
    char *value; // string

    int _library_owned; // Is the library responsible for freeing this object?
} patch_instance_body_strace_filter_inner_t;

__attribute__((deprecated)) patch_instance_body_strace_filter_inner_t *patch_instance_body_strace_filter_inner_create(
    corellium_api_patch_instance_body_strace_filter_inner_TRAIT_e trait,
    char *value
);

void patch_instance_body_strace_filter_inner_free(patch_instance_body_strace_filter_inner_t *patch_instance_body_strace_filter_inner);

patch_instance_body_strace_filter_inner_t *patch_instance_body_strace_filter_inner_parseFromJSON(cJSON *patch_instance_body_strace_filter_innerJSON);

cJSON *patch_instance_body_strace_filter_inner_convertToJSON(patch_instance_body_strace_filter_inner_t *patch_instance_body_strace_filter_inner);

#endif /* _patch_instance_body_strace_filter_inner_H_ */

