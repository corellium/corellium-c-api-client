# peripherals_data_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**acceleration** | **list_t \*** | Accelerometer reading as [x, y, z]. | [optional] 
**gyroscope** | **list_t \*** | Gyroscope reading as [x, y, z]. | [optional] 
**magnetic** | **list_t \*** | Magnetometer reading as [x, y, z]. | [optional] 
**orientation** | **list_t \*** | Device orientation vector. | [optional] 
**temperature** | **double** | Ambient temperature reading. | [optional] 
**proximity** | **double** | Proximity sensor reading. | [optional] 
**light** | **double** | Ambient light sensor reading. | [optional] 
**pressure** | **double** | Barometric pressure reading. | [optional] 
**humidity** | **double** | Relative humidity reading. | [optional] 
**gps_lat** | **double** | GPS latitude in decimal degrees. | [optional] 
**gps_lon** | **double** | GPS longitude in decimal degrees. | [optional] 
**gps_alt** | **double** | GPS altitude in meters. | [optional] 
**gps_toffs** | **double** | GPS time offset in seconds. | [optional] 
**ac_online** | **double** | Whether the device is on AC power (0 or 1). | [optional] 
**battery_present** | **double** | Whether a battery is present (0 or 1). | [optional] 
**battery_status** | **char \*** | Battery charging status, e.g. \&quot;charging\&quot;, \&quot;not-charging\&quot;. | [optional] 
**battery_health** | **char \*** | Battery health, e.g. \&quot;good\&quot;. | [optional] 
**battery_capacity** | **double** | Battery charge level as a percentage. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


