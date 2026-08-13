/*
 * metered_subscription_usage.h
 *
 * 
 */

#ifndef _metered_subscription_usage_H_
#define _metered_subscription_usage_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct metered_subscription_usage_t metered_subscription_usage_t;




typedef struct metered_subscription_usage_t {
    double burst_rate; //numeric
    double allocated_hours; //numeric
    double plan_billed_amount; //numeric
    double burst_billed_amount; //numeric
    double burst_billed_units; //numeric
    double burst_outstanding_amount; //numeric
    double burst_outstanding_units; //numeric
    double total_usage_amount; //numeric
    double total_used_units; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} metered_subscription_usage_t;

__attribute__((deprecated)) metered_subscription_usage_t *metered_subscription_usage_create(
    double burst_rate,
    double allocated_hours,
    double plan_billed_amount,
    double burst_billed_amount,
    double burst_billed_units,
    double burst_outstanding_amount,
    double burst_outstanding_units,
    double total_usage_amount,
    double total_used_units
);

void metered_subscription_usage_free(metered_subscription_usage_t *metered_subscription_usage);

metered_subscription_usage_t *metered_subscription_usage_parseFromJSON(cJSON *metered_subscription_usageJSON);

cJSON *metered_subscription_usage_convertToJSON(metered_subscription_usage_t *metered_subscription_usage);

#endif /* _metered_subscription_usage_H_ */

