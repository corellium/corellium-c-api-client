/*
 * metered_subscription_usage_v1.h
 *
 * 
 */

#ifndef _metered_subscription_usage_v1_H_
#define _metered_subscription_usage_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct metered_subscription_usage_v1_t metered_subscription_usage_v1_t;




typedef struct metered_subscription_usage_v1_t {
    double burst_rate; //numeric
    double allocated_hours; //numeric
    double plan_billed_amount; //numeric
    double plan_billed_units; //numeric
    double burst_billed_amount; //numeric
    double burst_billed_units; //numeric
    double burst_outstanding_amount; //numeric
    double burst_outstanding_units; //numeric
    double total_usage_amount; //numeric
    double total_used_units; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} metered_subscription_usage_v1_t;

__attribute__((deprecated)) metered_subscription_usage_v1_t *metered_subscription_usage_v1_create(
    double burst_rate,
    double allocated_hours,
    double plan_billed_amount,
    double plan_billed_units,
    double burst_billed_amount,
    double burst_billed_units,
    double burst_outstanding_amount,
    double burst_outstanding_units,
    double total_usage_amount,
    double total_used_units
);

void metered_subscription_usage_v1_free(metered_subscription_usage_v1_t *metered_subscription_usage_v1);

metered_subscription_usage_v1_t *metered_subscription_usage_v1_parseFromJSON(cJSON *metered_subscription_usage_v1JSON);

cJSON *metered_subscription_usage_v1_convertToJSON(metered_subscription_usage_v1_t *metered_subscription_usage_v1);

#endif /* _metered_subscription_usage_v1_H_ */

