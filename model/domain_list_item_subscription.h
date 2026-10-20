/*
 * domain_list_item_subscription.h
 *
 * Subscription info.
 */

#ifndef _domain_list_item_subscription_H_
#define _domain_list_item_subscription_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct domain_list_item_subscription_t domain_list_item_subscription_t;

#include "any_type.h"
#include "object.h"

// Enum BILLINGTYPE for domain_list_item_subscription

typedef enum  { corellium_api_domain_list_item_subscription_BILLINGTYPE_NULL = 0, corellium_api_domain_list_item_subscription_BILLINGTYPE_prepaid, corellium_api_domain_list_item_subscription_BILLINGTYPE_usage, corellium_api_domain_list_item_subscription_BILLINGTYPE_metered, corellium_api_domain_list_item_subscription_BILLINGTYPE_credit, corellium_api_domain_list_item_subscription_BILLINGTYPE_cores_metered } corellium_api_domain_list_item_subscription_BILLINGTYPE_e;

char* domain_list_item_subscription_billing_type_ToString(corellium_api_domain_list_item_subscription_BILLINGTYPE_e billing_type);

corellium_api_domain_list_item_subscription_BILLINGTYPE_e domain_list_item_subscription_billing_type_FromString(char* billing_type);



typedef struct domain_list_item_subscription_t {
    object_t *renew_action; //object
    char *domain; // string
    corellium_api_domain_list_item_subscription_BILLINGTYPE_e billing_type; //enum
    char *billing_backend; // string
    char *billing_id; // string
    char *next_bill; //date time
    int usage_based; //boolean
    char *last_usage_bill; //date time
    double last_payment_amount; //numeric
    double usage_bill_interval_days; //numeric
    double usage_billing_threshold_dollars; //numeric
    int past_due; //boolean
    double payment_attempts; //numeric
    char *last_payment_attempt; //date time
    char *created_at; //date time
    char *updated_at; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} domain_list_item_subscription_t;

__attribute__((deprecated)) domain_list_item_subscription_t *domain_list_item_subscription_create(
    object_t *renew_action,
    char *domain,
    corellium_api_domain_list_item_subscription_BILLINGTYPE_e billing_type,
    char *billing_backend,
    char *billing_id,
    char *next_bill,
    int usage_based,
    char *last_usage_bill,
    double last_payment_amount,
    double usage_bill_interval_days,
    double usage_billing_threshold_dollars,
    int past_due,
    double payment_attempts,
    char *last_payment_attempt,
    char *created_at,
    char *updated_at
);

void domain_list_item_subscription_free(domain_list_item_subscription_t *domain_list_item_subscription);

domain_list_item_subscription_t *domain_list_item_subscription_parseFromJSON(cJSON *domain_list_item_subscriptionJSON);

cJSON *domain_list_item_subscription_convertToJSON(domain_list_item_subscription_t *domain_list_item_subscription);

#endif /* _domain_list_item_subscription_H_ */

