/*
 * domain_config_input_trial.h
 *
 * Trial configuration.
 */

#ifndef _domain_config_input_trial_H_
#define _domain_config_input_trial_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct domain_config_input_trial_t domain_config_input_trial_t;




typedef struct domain_config_input_trial_t {
    double start; //numeric
    double end; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} domain_config_input_trial_t;

__attribute__((deprecated)) domain_config_input_trial_t *domain_config_input_trial_create(
    double start,
    double end
);

void domain_config_input_trial_free(domain_config_input_trial_t *domain_config_input_trial);

domain_config_input_trial_t *domain_config_input_trial_parseFromJSON(cJSON *domain_config_input_trialJSON);

cJSON *domain_config_input_trial_convertToJSON(domain_config_input_trial_t *domain_config_input_trial);

#endif /* _domain_config_input_trial_H_ */

