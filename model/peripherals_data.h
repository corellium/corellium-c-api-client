/*
 * peripherals_data.h
 *
 * Peripheral readings and settings. Responses include only fields reported by the compute node; no field is guaranteed to be present. An absent field does not imply a zero or false value. All fields are optional to support partial updates.  Writes require the corresponding feature to be enabled; settings for disabled features are ignored: - deviceMotion: acceleration, gyroscope, magnetic, orientation. - deviceEnvironmentControl: temperature, proximity, light, pressure, humidity. - deviceLocation: gpsLat, gpsLon, gpsAlt, gpsToffs. - deviceBattery: acOnline, batteryPresent, batteryStatus, batteryHealth, batteryCapacity. - biometricBypass: biometricPass.  These write restrictions do not determine which fields are returned by GET.
 */

#ifndef _peripherals_data_H_
#define _peripherals_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct peripherals_data_t peripherals_data_t;


// Enum ACONLINE for peripherals_data

typedef enum  { corellium_api_peripherals_data_ACONLINE_NULL = 0, corellium_api_peripherals_data_ACONLINE__0, corellium_api_peripherals_data_ACONLINE__1 } corellium_api_peripherals_data_ACONLINE_e;

char* peripherals_data_ac_online_ToString(corellium_api_peripherals_data_ACONLINE_e ac_online);

corellium_api_peripherals_data_ACONLINE_e peripherals_data_ac_online_FromString(char* ac_online);

// Enum BATTERYPRESENT for peripherals_data

typedef enum  { corellium_api_peripherals_data_BATTERYPRESENT_NULL = 0, corellium_api_peripherals_data_BATTERYPRESENT__0, corellium_api_peripherals_data_BATTERYPRESENT__1 } corellium_api_peripherals_data_BATTERYPRESENT_e;

char* peripherals_data_battery_present_ToString(corellium_api_peripherals_data_BATTERYPRESENT_e battery_present);

corellium_api_peripherals_data_BATTERYPRESENT_e peripherals_data_battery_present_FromString(char* battery_present);

// Enum BATTERYSTATUS for peripherals_data

typedef enum  { corellium_api_peripherals_data_BATTERYSTATUS_NULL = 0, corellium_api_peripherals_data_BATTERYSTATUS_charging, corellium_api_peripherals_data_BATTERYSTATUS_discharging, corellium_api_peripherals_data_BATTERYSTATUS_not_charging } corellium_api_peripherals_data_BATTERYSTATUS_e;

char* peripherals_data_battery_status_ToString(corellium_api_peripherals_data_BATTERYSTATUS_e battery_status);

corellium_api_peripherals_data_BATTERYSTATUS_e peripherals_data_battery_status_FromString(char* battery_status);

// Enum BATTERYHEALTH for peripherals_data

typedef enum  { corellium_api_peripherals_data_BATTERYHEALTH_NULL = 0, corellium_api_peripherals_data_BATTERYHEALTH_good, corellium_api_peripherals_data_BATTERYHEALTH_overheat, corellium_api_peripherals_data_BATTERYHEALTH_dead, corellium_api_peripherals_data_BATTERYHEALTH_overvolt, corellium_api_peripherals_data_BATTERYHEALTH_failure } corellium_api_peripherals_data_BATTERYHEALTH_e;

char* peripherals_data_battery_health_ToString(corellium_api_peripherals_data_BATTERYHEALTH_e battery_health);

corellium_api_peripherals_data_BATTERYHEALTH_e peripherals_data_battery_health_FromString(char* battery_health);

// Enum BIOMETRICPASS for peripherals_data

typedef enum  { corellium_api_peripherals_data_BIOMETRICPASS_NULL = 0, corellium_api_peripherals_data_BIOMETRICPASS__0, corellium_api_peripherals_data_BIOMETRICPASS__1 } corellium_api_peripherals_data_BIOMETRICPASS_e;

char* peripherals_data_biometric_pass_ToString(corellium_api_peripherals_data_BIOMETRICPASS_e biometric_pass);

corellium_api_peripherals_data_BIOMETRICPASS_e peripherals_data_biometric_pass_FromString(char* biometric_pass);



typedef struct peripherals_data_t {
    list_t *acceleration; //primitive container
    list_t *gyroscope; //primitive container
    list_t *magnetic; //primitive container
    list_t *orientation; //primitive container
    double temperature; //numeric
    double proximity; //numeric
    double light; //numeric
    double pressure; //numeric
    double humidity; //numeric
    double gps_lat; //numeric
    double gps_lon; //numeric
    double gps_alt; //numeric
    double gps_toffs; //numeric
    double ac_online; //numeric
    double battery_present; //numeric
    corellium_api_peripherals_data_BATTERYSTATUS_e battery_status; //enum
    corellium_api_peripherals_data_BATTERYHEALTH_e battery_health; //enum
    double battery_capacity; //numeric
    double biometric_pass; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} peripherals_data_t;

__attribute__((deprecated)) peripherals_data_t *peripherals_data_create(
    list_t *acceleration,
    list_t *gyroscope,
    list_t *magnetic,
    list_t *orientation,
    double temperature,
    double proximity,
    double light,
    double pressure,
    double humidity,
    double gps_lat,
    double gps_lon,
    double gps_alt,
    double gps_toffs,
    double ac_online,
    double battery_present,
    corellium_api_peripherals_data_BATTERYSTATUS_e battery_status,
    corellium_api_peripherals_data_BATTERYHEALTH_e battery_health,
    double battery_capacity,
    double biometric_pass
);

void peripherals_data_free(peripherals_data_t *peripherals_data);

peripherals_data_t *peripherals_data_parseFromJSON(cJSON *peripherals_dataJSON);

cJSON *peripherals_data_convertToJSON(peripherals_data_t *peripherals_data);

#endif /* _peripherals_data_H_ */

