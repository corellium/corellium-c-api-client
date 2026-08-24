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
// **Required role:** Domain administrator.  Cancel the current subscription for the domain.
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
// **Required role:** Domain administrator.  Return a billing summary for the current domain, including plan, usage, and payment state.
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
// Return device usage for the current domain over the active billing period.
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
// **Required role:** Domain administrator.  Return current metered usage for the subscription against its billing thresholds.
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
// Return the current subscription for the domain, including plan and status.
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
// Allow someone with an invite to create a domain.
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
// **Required role:** Domain administrator.  Reactivate a subscription that was previously scheduled for cancellation.
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

