/*
 * trial_v1.h
 *
 * 
 */

#ifndef _trial_v1_H_
#define _trial_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct trial_v1_t trial_v1_t;




typedef struct trial_v1_t {
    double default_duration; //numeric
    double default_hours; //numeric
    double default_devices; //numeric
    double default_cores; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} trial_v1_t;

__attribute__((deprecated)) trial_v1_t *trial_v1_create(
    double default_duration,
    double default_hours,
    double default_devices,
    double default_cores
);

void trial_v1_free(trial_v1_t *trial_v1);

trial_v1_t *trial_v1_parseFromJSON(cJSON *trial_v1JSON);

cJSON *trial_v1_convertToJSON(trial_v1_t *trial_v1);

#endif /* _trial_v1_H_ */

