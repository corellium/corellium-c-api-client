# instance_input_request_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**position** | [**object_t**](.md) \* | Finger Positions | [optional] 
**buttons** | [**list_t**](object.md) \* | Buttons to be held when this position is reached. Accepts case-insensitive VM button names, keyboard key names, or single ASCII characters. No change if not defined; an empty array releases all buttons. | [optional] 
**normalized** | **int** | true if you want to use normalized x,y coordinates from 0-10000 (eg 5000,5000 is always center of screen) | [optional] 
**wait** | **double** | Duration to wait before this input is executed.  Instant if not defined. | [optional] 
**start** | [**object_t**](.md) \* | Finger Positions | 
**end** | [**object_t**](.md) \* | Finger Positions | 
**bezier_points** | [**list_t**](object.md) \* | array of per-finger intermediate touch positions, up to 10 depending on model.  Straight line if not defined. | [optional] 
**start_buttons** | [**list_t**](object.md) \* | Buttons to be held during this curve. | 
**end_buttons** | [**list_t**](object.md) \* | Buttons to be left held after this curve.  Same as startButtons if not defined. | [optional] 
**duration** | **double** | Duration to execute this curve over. | 
**required** | **char \*** | text to type | 
**key_duration** | **double** | How long to take to type each key.  150ms if not defined. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


