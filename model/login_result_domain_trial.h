/*
 * login_result_domain_trial.h
 *
 * Trial configuration, null once the domain is no longer on a trial.
 */

#ifndef _login_result_domain_trial_H_
#define _login_result_domain_trial_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct login_result_domain_trial_t login_result_domain_trial_t;




typedef struct login_result_domain_trial_t {
    double start; //numeric
    double end; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} login_result_domain_trial_t;

__attribute__((deprecated)) login_result_domain_trial_t *login_result_domain_trial_create(
    double start,
    double end
);

void login_result_domain_trial_free(login_result_domain_trial_t *login_result_domain_trial);

login_result_domain_trial_t *login_result_domain_trial_parseFromJSON(cJSON *login_result_domain_trialJSON);

cJSON *login_result_domain_trial_convertToJSON(login_result_domain_trial_t *login_result_domain_trial);

#endif /* _login_result_domain_trial_H_ */

