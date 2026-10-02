# user_error_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**error** | **char \*** | Human-readable explanation of what was wrong with the request. Show it to the user or log it; do not parse it, because the wording can change. | 
**error_id** | **corellium_api_user_error_ERRORID_e** | Always &#x60;UserError&#x60;: the request itself was invalid. Fix the request before retrying; sending it again unchanged fails the same way. | 
**field** | **char \*** | Name of the request field that was rejected, when the error is about one field. | [optional] 
**validator** | **char \*** | Validator that rejected the field. | [optional] 
**project_ids** | **list_t \*** | Projects still using this resource, when the error is a usage conflict. | [optional] 
**missing_fw_assets** | **list_t \*** | Firmware asset URLs required by the target firmware but absent from the domain, when field is &#39;firmware_asset&#39;. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


