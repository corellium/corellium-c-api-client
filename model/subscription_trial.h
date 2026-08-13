/*
 * subscription_trial.h
 *
 * Trial usage details, or null when the domain has no trial.
 */

#ifndef _subscription_trial_H_
#define _subscription_trial_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct subscription_trial_t subscription_trial_t;


// Enum STATUS for subscription_trial

typedef enum  { corellium_api_subscription_trial_STATUS_NULL = 0, corellium_api_subscription_trial_STATUS_not_started, corellium_api_subscription_trial_STATUS_active, corellium_api_subscription_trial_STATUS_completed } corellium_api_subscription_trial_STATUS_e;

char* subscription_trial_status_ToString(corellium_api_subscription_trial_STATUS_e status);

corellium_api_subscription_trial_STATUS_e subscription_trial_status_FromString(char* status);



typedef struct subscription_trial_t {
    corellium_api_subscription_trial_STATUS_e status; //enum
    char *start; //date time
    char *end; //date time
    double used_hours; //numeric
    double max_hours; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} subscription_trial_t;

__attribute__((deprecated)) subscription_trial_t *subscription_trial_create(
    corellium_api_subscription_trial_STATUS_e status,
    char *start,
    char *end,
    double used_hours,
    double max_hours
);

void subscription_trial_free(subscription_trial_t *subscription_trial);

subscription_trial_t *subscription_trial_parseFromJSON(cJSON *subscription_trialJSON);

cJSON *subscription_trial_convertToJSON(subscription_trial_t *subscription_trial);

#endif /* _subscription_trial_H_ */

