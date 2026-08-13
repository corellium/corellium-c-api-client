/*
 * update_trial_request_body.h
 *
 * 
 */

#ifndef _update_trial_request_body_H_
#define _update_trial_request_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct update_trial_request_body_t update_trial_request_body_t;




typedef struct update_trial_request_body_t {
    double extension_days; //numeric
    double extension_hours; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} update_trial_request_body_t;

__attribute__((deprecated)) update_trial_request_body_t *update_trial_request_body_create(
    double extension_days,
    double extension_hours
);

void update_trial_request_body_free(update_trial_request_body_t *update_trial_request_body);

update_trial_request_body_t *update_trial_request_body_parseFromJSON(cJSON *update_trial_request_bodyJSON);

cJSON *update_trial_request_body_convertToJSON(update_trial_request_body_t *update_trial_request_body);

#endif /* _update_trial_request_body_H_ */

