# instance_input_body_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**position** | **list_t \*** | Array of per-finger [x,y] touch positions, up to 10 depending on model. | [optional] 
**buttons** | **list_t \*** | Buttons held when this position is reached. Omit to leave unchanged; use an empty array to release. VM button names: finger, homeButton, holdButton (Power/Hold), volumeUp, volumeDown, backButton, overviewButton. Also accepts single characters and keyboard key names (e.g. enter, home, power), each optionally suffixed with a value (e.g. finger:1 for the fingerprint sensor, leftctrl:down). | [optional] 
**normalized** | **int** | Use normalized 0-10000 coordinates. | [optional] 
**wait** | **double** | Duration to wait before this input is executed, in milliseconds. | [optional] 
**start** | **list_t \*** | Array of per-finger [x,y] touch positions, up to 10 depending on model. | 
**end** | **list_t \*** | Array of per-finger [x,y] touch positions, up to 10 depending on model. | 
**bezier_points** | **list_t \*** | Per-finger intermediate touch positions. | [optional] 
**start_buttons** | **list_t \*** | Buttons held during this curve. VM button names: finger, homeButton, holdButton (Power/Hold), volumeUp, volumeDown, backButton, overviewButton. Also accepts single characters and keyboard key names (e.g. enter, home, power), each optionally suffixed with a value (e.g. finger:1 for the fingerprint sensor, leftctrl:down). | 
**end_buttons** | **list_t \*** | Buttons left held after this curve. Omit to leave unchanged; use an empty array to release. VM button names: finger, homeButton, holdButton (Power/Hold), volumeUp, volumeDown, backButton, overviewButton. Also accepts single characters and keyboard key names (e.g. enter, home, power), each optionally suffixed with a value (e.g. finger:1 for the fingerprint sensor, leftctrl:down). | [optional] 
**duration** | **double** | Duration to execute this curve over, in milliseconds. | 
**text** | **char \*** | Text to type. | 
**key_duration** | **double** | How long to take to type each key, in milliseconds. Defaults to ~150ms per key downstream when omitted. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


