/*
 * volume_options_v1.h
 *
 * 
 */

#ifndef _volume_options_v1_H_
#define _volume_options_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct volume_options_v1_t volume_options_v1_t;




typedef struct volume_options_v1_t {
    double blocks; //numeric
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} volume_options_v1_t;

__attribute__((deprecated)) volume_options_v1_t *volume_options_v1_create(
    double blocks,
    char *name
);

void volume_options_v1_free(volume_options_v1_t *volume_options_v1);

volume_options_v1_t *volume_options_v1_parseFromJSON(cJSON *volume_options_v1JSON);

cJSON *volume_options_v1_convertToJSON(volume_options_v1_t *volume_options_v1);

#endif /* _volume_options_v1_H_ */

