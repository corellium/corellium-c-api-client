# user_errors_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**error** | **char \*** | Summary of the problem. The individual problems are listed in &#x60;errors&#x60;. | 
**error_id** | **corellium_api_user_errors_ERRORID_e** | Always &#x60;UserErrors&#x60;: more than one field in the request was invalid. | 
**errors** | [**list_t**](user_error.md) \* | One entry per rejected field. Fix every one before retrying. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


