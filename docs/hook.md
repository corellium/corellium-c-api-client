# hook_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**identifier** | **char \*** | Hook identifier. | 
**label** | **char \*** | Hook label. | 
**address** | **char \*** | Memory address, in hexadecimal, where the hook fires: the patch runs each time the device executes the instruction at this address. | 
**patch** | **char \*** | The code to run when the hook fires, in the language given by &#x60;patchType&#x60;. | 
**patch_type** | **hook_patch_type_t \*** |  | 
**enabled** | **int** | Whether the hook runs. Disabled hooks are kept but skipped. | 
**instance_id** | **char \*** | Owning instance identifier. | 
**created_at** | **char \*** | Creation timestamp. | 
**updated_at** | **char \*** | Last update timestamp. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


