/*
 * trial.h
 *
 * Info about trial.
 */

#ifndef _trial_H_
#define _trial_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct trial_t trial_t;




typedef struct trial_t {
    double default_duration; //numeric
    double default_hours; //numeric
    double default_devices; //numeric
    double default_cores; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} trial_t;

__attribute__((deprecated)) trial_t *trial_create(
    double default_duration,
    double default_hours,
    double default_devices,
    double default_cores
);

void trial_free(trial_t *trial);

trial_t *trial_parseFromJSON(cJSON *trialJSON);

cJSON *trial_convertToJSON(trial_t *trial);

#endif /* _trial_H_ */

