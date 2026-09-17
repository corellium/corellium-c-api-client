# touch_input_request_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**position** | **list_t \*** | Array of per-finger [x,y] touch positions, up to 10 depending on model. | [optional] 
**buttons** | **list_t \*** | Buttons held when this position is reached. Omit to leave unchanged; use an empty array to release. VM button names: finger, homeButton, holdButton (Power/Hold), volumeUp, volumeDown, backButton, overviewButton. Also accepts single characters and keyboard key names (e.g. enter, home, power), each optionally suffixed with a value (e.g. finger:1 for the fingerprint sensor, leftctrl:down). | [optional] 
**normalized** | **int** | Use normalized 0-10000 coordinates. | [optional] 
**wait** | **double** | Duration to wait before this input is executed, in milliseconds. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


