/*
 * domain_config_trial.h
 *
 * Trial configuration.
 */

#ifndef _domain_config_trial_H_
#define _domain_config_trial_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct domain_config_trial_t domain_config_trial_t;

#include "domain_config_trial_end_action.h"
#include "domain_config_trial_extension.h"
#include "domain_config_trial_subscribe_action.h"



typedef struct domain_config_trial_t {
    double start; //numeric
    double end; //numeric
    struct domain_config_trial_end_action_t *end_action; //model
    struct domain_config_trial_subscribe_action_t *subscribe_action; //model
    struct domain_config_trial_extension_t *extension; //model

    int _library_owned; // Is the library responsible for freeing this object?
} domain_config_trial_t;

__attribute__((deprecated)) domain_config_trial_t *domain_config_trial_create(
    double start,
    double end,
    domain_config_trial_end_action_t *end_action,
    domain_config_trial_subscribe_action_t *subscribe_action,
    domain_config_trial_extension_t *extension
);

void domain_config_trial_free(domain_config_trial_t *domain_config_trial);

domain_config_trial_t *domain_config_trial_parseFromJSON(cJSON *domain_config_trialJSON);

cJSON *domain_config_trial_convertToJSON(domain_config_trial_t *domain_config_trial);

#endif /* _domain_config_trial_H_ */

