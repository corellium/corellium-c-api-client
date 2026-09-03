# user_error_response_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**error** | **char \*** | Error text. | 
**error_id** | **corellium_api_user_error_response_ERRORID_e** | Error ID. | 
**field** | **char \*** | Field associated with error | [optional] 
**validator** | **char \*** | Validator that rejected the field. | [optional] 
**project_ids** | **list_t \*** | Projects still using this resource, when the error is a usage conflict. | [optional] 
**missing_fw_assets** | **list_t \*** | Firmware asset URLs required by the target firmware but absent from the domain, when field is &#39;firmware_asset&#39;. | [optional] 
**errors** | [**list_t**](user_error.md) \* | Individual field errors. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


