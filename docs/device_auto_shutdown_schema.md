# device_auto_shutdown_schema_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**enabled** | **int** | Whether devices in this domain are turned off automatically after running for &#x60;threshold&#x60; hours. Turning a device back on restarts its timer. | [optional] 
**threshold** | **double** | Hours a device may run, counted from when it was last started, before it is turned off automatically. This is running time, not idle time: a device in active use is still stopped when the time is up. Whole number greater than 0. Defaults to 10 when not set. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


