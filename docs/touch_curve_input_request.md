# touch_curve_input_request_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**start** | **list_t \*** | Array of per-finger [x,y] touch positions, up to 10 depending on model. | 
**end** | **list_t \*** | Array of per-finger [x,y] touch positions, up to 10 depending on model. | 
**bezier_points** | **list_t \*** | Per-finger intermediate touch positions. | [optional] 
**start_buttons** | **list_t \*** | Buttons held during this curve. | 
**end_buttons** | **list_t \*** | Buttons left held after this curve. | [optional] 
**normalized** | **int** | Use normalized 0-10000 coordinates. | [optional] 
**wait** | **double** | Duration to wait before this input is executed, in milliseconds. | [optional] 
**duration** | **double** | Duration to execute this curve over, in milliseconds. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


