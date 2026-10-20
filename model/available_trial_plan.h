/*
 * available_trial_plan.h
 *
 * 
 */

#ifndef _available_trial_plan_H_
#define _available_trial_plan_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct available_trial_plan_t available_trial_plan_t;




typedef struct available_trial_plan_t {
    char *product_id; // string
    char *name; // string
    char *license; // string
    int workspace; //boolean
    double cores; //numeric
    double devices; //numeric
    double trial_duration; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} available_trial_plan_t;

__attribute__((deprecated)) available_trial_plan_t *available_trial_plan_create(
    char *product_id,
    char *name,
    char *license,
    int workspace,
    double cores,
    double devices,
    double trial_duration
);

void available_trial_plan_free(available_trial_plan_t *available_trial_plan);

available_trial_plan_t *available_trial_plan_parseFromJSON(cJSON *available_trial_planJSON);

cJSON *available_trial_plan_convertToJSON(available_trial_plan_t *available_trial_plan);

#endif /* _available_trial_plan_H_ */

