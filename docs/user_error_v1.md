# user_error_v1_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**error** | **char \*** | Error text | 
**error_id** | **corellium_api_user_error_v1_ERRORID_e** | Error ID | 
**field** | **char \*** | Field associated with error | [optional] 
**validator** | **char \*** | Validator that rejected the field | [optional] 
**project_ids** | **list_t \*** | Projects still using this resource, when the error is a usage conflict. | [optional] 
**errors** | [**list_t**](user_error_item.md) \* | Individual field errors | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


