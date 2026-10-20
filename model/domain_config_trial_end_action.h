/*
 * domain_config_trial_end_action.h
 *
 * What happens when the trial ends.
 */

#ifndef _domain_config_trial_end_action_H_
#define _domain_config_trial_end_action_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct domain_config_trial_end_action_t domain_config_trial_end_action_t;




typedef struct domain_config_trial_end_action_t {
    char *action; // string

    int _library_owned; // Is the library responsible for freeing this object?
} domain_config_trial_end_action_t;

__attribute__((deprecated)) domain_config_trial_end_action_t *domain_config_trial_end_action_create(
    char *action
);

void domain_config_trial_end_action_free(domain_config_trial_end_action_t *domain_config_trial_end_action);

domain_config_trial_end_action_t *domain_config_trial_end_action_parseFromJSON(cJSON *domain_config_trial_end_actionJSON);

cJSON *domain_config_trial_end_action_convertToJSON(domain_config_trial_end_action_t *domain_config_trial_end_action);

#endif /* _domain_config_trial_end_action_H_ */

