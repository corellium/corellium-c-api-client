# user_error_response_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**error** | **char \*** | Summary of the problem. The individual problems are listed in &#x60;errors&#x60;. | 
**error_id** | **corellium_api_user_error_response_ERRORID_e** | Always &#x60;UserErrors&#x60;: more than one field in the request was invalid. | 
**field** | **char \*** | Name of the request field that was rejected, when the error is about one field. | [optional] 
**validator** | **char \*** | Validator that rejected the field. | [optional] 
**project_ids** | **list_t \*** | Projects still using this resource, when the error is a usage conflict. | [optional] 
**missing_fw_assets** | **list_t \*** | Firmware asset URLs required by the target firmware but absent from the domain, when field is &#39;firmware_asset&#39;. | [optional] 
**errors** | [**list_t**](user_error.md) \* | One entry per rejected field. Fix every one before retrying. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


