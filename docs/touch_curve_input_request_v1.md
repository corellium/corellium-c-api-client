# touch_curve_input_request_v1_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**start** | [**object_t**](.md) \* | Finger Positions | 
**end** | [**object_t**](.md) \* | Finger Positions | 
**bezier_points** | [**list_t**](object.md) \* | array of per-finger intermediate touch positions, up to 10 depending on model.  Straight line if not defined. | [optional] 
**start_buttons** | [**list_t**](object.md) \* | Buttons to be held during this curve. | 
**end_buttons** | [**list_t**](object.md) \* | Buttons to be left held after this curve.  Same as startButtons if not defined. | [optional] 
**normalized** | **int** | true if you want to use normalized x,y coordinates from 0-10000 (eg 5000,5000 is always center of screen) | [optional] 
**wait** | **double** | Duration to wait before this input is executed.  Instant if not defined. | [optional] 
**duration** | **double** | Duration to execute this curve over. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


