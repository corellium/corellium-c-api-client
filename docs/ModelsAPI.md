# ModelsAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ModelsAPI_v3GetModelSoftware**](ModelsAPI.md#ModelsAPI_v3GetModelSoftware) | **GET** /v3/models/{model}/software | List software for a model
[**ModelsAPI_v3GetModels**](ModelsAPI.md#ModelsAPI_v3GetModels) | **GET** /v3/models | List device models


# **ModelsAPI_v3GetModelSoftware**
```c
// List software for a model
//
// Lists the operating-system builds you can install on a new instance of one model. Identify the model by its flavor ID (for example `iphone17a`) or its product identifier. Each entry's `osVersion` and `osBuild` are the values to pass to `POST /v3/instances`.  **Where the list comes from.** It includes vendor builds the platform supports for this model (for example public iOS releases), firmware installed cluster-wide with `POST /v3/images/install-firmware`, and firmware uploaded at domain level with `POST /v3/images` (no `projectId` or `instanceId`). It does **not** include images that belong to a project or instance; to boot one of those, reference it explicitly when creating the instance.  **Choosing a build.** - `installed: true` builds are already on your deployment and start fastest. Others are downloaded when first used. - On Android there are usually two builds per version; `rooted` tells them apart. MATRIX needs the rooted build. - `springboardSnapshot` present means the build supports rapid start.  Returns 404 if the model is unknown or has no software.
//
list_t* ModelsAPI_v3GetModelSoftware(apiClient_t *apiClient, char *model);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**model** | **char \*** | Which model to list software for: a flavor ID (the &#x60;flavor&#x60; value from &#x60;v3GetModels&#x60;, for example \&quot;iphone17a\&quot;) or a product identifier such as \&quot;iPhone18,4\&quot;. Only a flavor ID returns &#x60;springboardSnapshot&#x60;. | 

### Return type

[list_t](model_firmware.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ModelsAPI_v3GetModels**
```c
// List device models
//
// Lists every device model you can create an instance of. Call it first when creating a device: pick a model, then list its software with `v3GetModelSoftware`, then create the instance with `POST /v3/instances`.  The list only includes models your account can use. iOS models are left out if iOS is disabled for your domain, models from vendors your domain has not enabled are left out, and beta models appear only on deployments that allow them.  Each entry tells you what you need to create a valid instance: - `flavor`: the value to pass as `flavor` when creating the instance. - `cores`, `coresMin`, `coresMax`, `coresStep`, `coresAllowed`: which CPU core counts are allowed. - `ram`, `ramMin`, `ramMax`: allowed memory, in MiB. - `hasSoftware`: false means there is no operating system available for this model yet, so an instance cannot be created from a standard build. - `mast`: whether MATRIX assessments work on it.  **Caching.** The response carries an `ETag` header. Send it back as `If-None-Match` on later calls; if nothing has changed you get 304 with no body and can reuse your copy.
//
list_t* ModelsAPI_v3GetModels(apiClient_t *apiClient, char *if_none_match);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**if_none_match** | **char \*** | An ETag a previous response carried, quotes included. | [optional] 

### Return type

[list_t](model.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

