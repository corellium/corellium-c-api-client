# BillingAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**BillingAPI_v3CancelSubscription**](BillingAPI.md#BillingAPI_v3CancelSubscription) | **POST** /v3/billing/cancel | Cancel a subscription
[**BillingAPI_v3GetBillingSummary**](BillingAPI.md#BillingAPI_v3GetBillingSummary) | **GET** /v3/billing/summary | Get billing summary
[**BillingAPI_v3GetDeviceUsage**](BillingAPI.md#BillingAPI_v3GetDeviceUsage) | **GET** /v3/billing/usage | Get device usage
[**BillingAPI_v3GetMeteredSubscriptionUsage**](BillingAPI.md#BillingAPI_v3GetMeteredSubscriptionUsage) | **GET** /v3/billing/subscription/metered/usage | Get metered subscription usage
[**BillingAPI_v3GetSubscription**](BillingAPI.md#BillingAPI_v3GetSubscription) | **GET** /v3/billing/subscription | Get the current subscription
[**BillingAPI_v3SubscribeToTrial**](BillingAPI.md#BillingAPI_v3SubscribeToTrial) | **POST** /v3/billing/trials/subscribe | Subscribe to a trial
[**BillingAPI_v3UncancelSubscription**](BillingAPI.md#BillingAPI_v3UncancelSubscription) | **POST** /v3/billing/uncancel | Uncancel a subscription


# **BillingAPI_v3CancelSubscription**
```c
// Cancel a subscription
//
// **Required role:** Domain administrator.  Cancels your domain's subscription. Requires an administrator. By default it acts on your own domain; only a cloud administrator may pass another `domainId`. Set `deleteDomain: true` to also delete the domain and everything in it, which cannot be undone. A cancellation that has not taken effect yet can be reversed with `v3UncancelSubscription`.
//
void BillingAPI_v3CancelSubscription(apiClient_t *apiClient, cancel_subscription_body_t *cancel_subscription_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**cancel_subscription_body** | **[cancel_subscription_body_t](cancel_subscription_body.md) \*** |  | [optional] 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **BillingAPI_v3GetBillingSummary**
```c
// Get billing summary
//
// **Required role:** Domain administrator.  Returns the charges building up for your domain in the current billing period on a usage-based plan: when the period started and ends, the running total, the billing threshold, and a line item per charged activity. Returns `pendingUsageBased: null` if your domain is not on a usage-based plan. Requires a domain administrator.
//
billing_summary_t* BillingAPI_v3GetBillingSummary(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[billing_summary_t](billing_summary.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **BillingAPI_v3GetDeviceUsage**
```c
// Get device usage
//
// Returns how much your domain's devices have been used in the current billing period.
//
device_usage_t* BillingAPI_v3GetDeviceUsage(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[device_usage_t](device_usage.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **BillingAPI_v3GetMeteredSubscriptionUsage**
```c
// Get metered subscription usage
//
// **Required role:** Domain administrator.  For domains on a metered plan, returns how much has been used in the current billing period: units (hours) included in the plan, units used beyond it, the rate for extra use, and the amounts billed and still outstanding. Amounts are in cents. Requires a domain administrator.
//
metered_subscription_usage_t* BillingAPI_v3GetMeteredSubscriptionUsage(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[metered_subscription_usage_t](metered_subscription_usage.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **BillingAPI_v3GetSubscription**
```c
// Get the current subscription
//
// Returns your domain's current subscription: which plan you are on and its status. Use it to check what your account includes or whether a cancellation is scheduled.
//
subscription_t* BillingAPI_v3GetSubscription(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[subscription_t](subscription.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **BillingAPI_v3SubscribeToTrial**
```c
// Subscribe to a trial
//
// Creates a new trial domain for someone who has a trial invitation. Needs no sign-in: the invitation details in the body identify the person. Used by the trial sign-up page.
//
object_t* BillingAPI_v3SubscribeToTrial(apiClient_t *apiClient, subscribe_to_trial_body_t *subscribe_to_trial_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**subscribe_to_trial_body** | **[subscribe_to_trial_body_t](subscribe_to_trial_body.md) \*** |  | [optional] 

### Return type

[object_t](object.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **BillingAPI_v3UncancelSubscription**
```c
// Uncancel a subscription
//
// **Required role:** Domain administrator.  Reverses a scheduled cancellation, so the subscription continues as before: the pending cancellation is cleared and the scheduled shut-off is removed. Requires an administrator; acts on your own domain unless a cloud administrator passes another `domainId`.
//
void BillingAPI_v3UncancelSubscription(apiClient_t *apiClient, uncancel_subscription_body_t *uncancel_subscription_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**uncancel_subscription_body** | **[uncancel_subscription_body_t](uncancel_subscription_body.md) \*** |  | [optional] 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

