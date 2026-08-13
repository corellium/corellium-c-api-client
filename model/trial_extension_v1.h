/*
 * trial_extension_v1.h
 *
 * 
 */

#ifndef _trial_extension_v1_H_
#define _trial_extension_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct trial_extension_v1_t trial_extension_v1_t;




typedef struct trial_extension_v1_t {
    double duration; //numeric
    char *reason; // string
    int denied; //boolean
    char *denied_reason; // string

    int _library_owned; // Is the library responsible for freeing this object?
} trial_extension_v1_t;

__attribute__((deprecated)) trial_extension_v1_t *trial_extension_v1_create(
    double duration,
    char *reason,
    int denied,
    char *denied_reason
);

void trial_extension_v1_free(trial_extension_v1_t *trial_extension_v1);

trial_extension_v1_t *trial_extension_v1_parseFromJSON(cJSON *trial_extension_v1JSON);

cJSON *trial_extension_v1_convertToJSON(trial_extension_v1_t *trial_extension_v1);

#endif /* _trial_extension_v1_H_ */

