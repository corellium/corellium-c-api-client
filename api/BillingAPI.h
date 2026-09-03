#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"
#include "../model/api_error.h"
#include "../model/billing_summary.h"
#include "../model/cancel_subscription_body.h"
#include "../model/device_usage.h"
#include "../model/metered_subscription_usage.h"
#include "../model/object.h"
#include "../model/subscribe_to_trial_body.h"
#include "../model/subscription.h"
#include "../model/uncancel_subscription_body.h"
#include "../model/user_error_response.h"


// Cancel a subscription
//
// **Required role:** Domain administrator.  Cancel the current subscription for the domain.
//
void
BillingAPI_v3CancelSubscription(apiClient_t *apiClient, cancel_subscription_body_t *cancel_subscription_body);


// Get billing summary
//
// **Required role:** Domain administrator.  Return a billing summary for the current domain, including plan, usage, and payment state.
//
billing_summary_t*
BillingAPI_v3GetBillingSummary(apiClient_t *apiClient);


// Get device usage
//
// Return device usage for the current domain over the active billing period.
//
device_usage_t*
BillingAPI_v3GetDeviceUsage(apiClient_t *apiClient);


// Get metered subscription usage
//
// **Required role:** Domain administrator.  Return current metered usage for the subscription against its billing thresholds.
//
metered_subscription_usage_t*
BillingAPI_v3GetMeteredSubscriptionUsage(apiClient_t *apiClient);


// Get the current subscription
//
// Return the current subscription for the domain, including plan and status.
//
subscription_t*
BillingAPI_v3GetSubscription(apiClient_t *apiClient);


// Subscribe to a trial
//
// Allow someone with an invite to create a domain.
//
object_t*
BillingAPI_v3SubscribeToTrial(apiClient_t *apiClient, subscribe_to_trial_body_t *subscribe_to_trial_body);


// Uncancel a subscription
//
// **Required role:** Domain administrator.  Reactivate a subscription that was previously scheduled for cancellation.
//
void
BillingAPI_v3UncancelSubscription(apiClient_t *apiClient, uncancel_subscription_body_t *uncancel_subscription_body);


