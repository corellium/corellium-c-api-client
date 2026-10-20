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
// **Required role:** Domain administrator.  Cancels your domain's subscription. Requires an administrator. By default it acts on your own domain; only a cloud administrator may pass another `domainId`. Set `deleteDomain: true` to also delete the domain and everything in it, which cannot be undone. A cancellation that has not taken effect yet can be reversed with `v3UncancelSubscription`.
//
void
BillingAPI_v3CancelSubscription(apiClient_t *apiClient, cancel_subscription_body_t *cancel_subscription_body);


// Get billing summary
//
// **Required role:** Domain administrator.  Returns the charges building up for your domain in the current billing period on a usage-based plan: when the period started and ends, the running total, the billing threshold, and a line item per charged activity. Returns `pendingUsageBased: null` if your domain is not on a usage-based plan. Requires a domain administrator.
//
billing_summary_t*
BillingAPI_v3GetBillingSummary(apiClient_t *apiClient);


// Get device usage
//
// Returns how much your domain's devices have been used in the current billing period.
//
device_usage_t*
BillingAPI_v3GetDeviceUsage(apiClient_t *apiClient);


// Get metered subscription usage
//
// **Required role:** Domain administrator.  For domains on a metered plan, returns how much has been used in the current billing period: units (hours) included in the plan, units used beyond it, the rate for extra use, and the amounts billed and still outstanding. Amounts are in cents. Requires a domain administrator.
//
metered_subscription_usage_t*
BillingAPI_v3GetMeteredSubscriptionUsage(apiClient_t *apiClient);


// Get the current subscription
//
// Returns your domain's current subscription: which plan you are on and its status. Use it to check what your account includes or whether a cancellation is scheduled.
//
subscription_t*
BillingAPI_v3GetSubscription(apiClient_t *apiClient);


// Subscribe to a trial
//
// Creates a new trial domain for someone who has a trial invitation. Needs no sign-in: the invitation details in the body identify the person. Used by the trial sign-up page.
//
object_t*
BillingAPI_v3SubscribeToTrial(apiClient_t *apiClient, subscribe_to_trial_body_t *subscribe_to_trial_body);


// Uncancel a subscription
//
// **Required role:** Domain administrator.  Reverses a scheduled cancellation, so the subscription continues as before: the pending cancellation is cleared and the scheduled shut-off is removed. Requires an administrator; acts on your own domain unless a cloud administrator passes another `domainId`.
//
void
BillingAPI_v3UncancelSubscription(apiClient_t *apiClient, uncancel_subscription_body_t *uncancel_subscription_body);


