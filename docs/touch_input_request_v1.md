# touch_input_request_v1_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**position** | [**object_t**](.md) \* | Finger Positions | [optional] 
**buttons** | [**list_t**](object.md) \* | Buttons to be held when this position is reached. Accepts case-insensitive VM button names, keyboard key names, or single ASCII characters. No change if not defined; an empty array releases all buttons. | [optional] 
**normalized** | **int** | true if you want to use normalized x,y coordinates from 0-10000 (eg 5000,5000 is always center of screen) | [optional] 
**wait** | **double** | Duration to wait before this input is executed.  Instant if not defined. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


