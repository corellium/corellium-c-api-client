/*
 * available_trial_plan_list.h
 *
 * 
 */

#ifndef _available_trial_plan_list_H_
#define _available_trial_plan_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct available_trial_plan_list_t available_trial_plan_list_t;

#include "available_trial_plan.h"



typedef struct available_trial_plan_list_t {
    list_t *results; //nonprimitive container
    double count; //numeric
    double total; //numeric
    double limit; //numeric
    double offset; //numeric
    int has_more; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} available_trial_plan_list_t;

__attribute__((deprecated)) available_trial_plan_list_t *available_trial_plan_list_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
);

void available_trial_plan_list_free(available_trial_plan_list_t *available_trial_plan_list);

available_trial_plan_list_t *available_trial_plan_list_parseFromJSON(cJSON *available_trial_plan_listJSON);

cJSON *available_trial_plan_list_convertToJSON(available_trial_plan_list_t *available_trial_plan_list);

#endif /* _available_trial_plan_list_H_ */

