/*
 * update_trial_request_params.h
 *
 * 
 */

#ifndef _update_trial_request_params_H_
#define _update_trial_request_params_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct update_trial_request_params_t update_trial_request_params_t;




typedef struct update_trial_request_params_t {
    double extension_days; //numeric
    double extension_hours; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} update_trial_request_params_t;

__attribute__((deprecated)) update_trial_request_params_t *update_trial_request_params_create(
    double extension_days,
    double extension_hours
);

void update_trial_request_params_free(update_trial_request_params_t *update_trial_request_params);

update_trial_request_params_t *update_trial_request_params_parseFromJSON(cJSON *update_trial_request_paramsJSON);

cJSON *update_trial_request_params_convertToJSON(update_trial_request_params_t *update_trial_request_params);

#endif /* _update_trial_request_params_H_ */

