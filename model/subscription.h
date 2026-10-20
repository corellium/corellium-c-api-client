/*
 * subscription.h
 *
 * 
 */

#ifndef _subscription_H_
#define _subscription_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct subscription_t subscription_t;

#include "subscription_trial.h"



typedef struct subscription_t {
    struct subscription_trial_t *trial; //model
    char *status; // string
    char *billing_type; // string
    char *plan_name; // string
    char *next_bill; // string
    int use_device_accounting; //boolean
    int is_enterprise; //boolean
    int is_usage_based; //boolean
    char *cancel_policy; // string

    int _library_owned; // Is the library responsible for freeing this object?
} subscription_t;

__attribute__((deprecated)) subscription_t *subscription_create(
    subscription_trial_t *trial,
    char *status,
    char *billing_type,
    char *plan_name,
    char *next_bill,
    int use_device_accounting,
    int is_enterprise,
    int is_usage_based,
    char *cancel_policy
);

void subscription_free(subscription_t *subscription);

subscription_t *subscription_parseFromJSON(cJSON *subscriptionJSON);

cJSON *subscription_convertToJSON(subscription_t *subscription);

#endif /* _subscription_H_ */

