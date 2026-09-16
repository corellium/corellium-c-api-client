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
**ac_online** | **double** | AC power connection: 0 &#x3D; disconnected, 1 &#x3D; connected. | [optional] 
**battery_present** | **double** | Battery presence: 0 &#x3D; absent, 1 &#x3D; present. | [optional] 
**battery_status** | **corellium_api_peripherals_data_BATTERYSTATUS_e** | Battery charging status. | [optional] 
**battery_health** | **corellium_api_peripherals_data_BATTERYHEALTH_e** | Battery health. | [optional] 
**battery_capacity** | **double** | Battery charge level as a percentage. | [optional] 
**biometric_pass** | **double** | Biometric bypass: 0 &#x3D; disabled, 1 &#x3D; enabled. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


