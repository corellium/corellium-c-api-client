# api_error_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**error** | **char \*** | Human-readable explanation of the error. | 
**error_id** | **char \*** | Short machine-readable error name, for example &#x60;PermissionDenied&#x60; or &#x60;NotFound&#x60;. Use this, not &#x60;error&#x60;, to decide what to do in code. | 
**original_error** | **char \*** | When the platform failed while talking to another service, the error that service reported. Useful when reporting a problem to support. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


