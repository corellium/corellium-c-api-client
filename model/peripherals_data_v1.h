/*
 * peripherals_data_v1.h
 *
 * 
 */

#ifndef _peripherals_data_v1_H_
#define _peripherals_data_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct peripherals_data_v1_t peripherals_data_v1_t;


// Enum BATTERYSTATUS for peripherals_data_v1

typedef enum  { corellium_api_peripherals_data_v1_BATTERYSTATUS_NULL = 0, corellium_api_peripherals_data_v1_BATTERYSTATUS_charging, corellium_api_peripherals_data_v1_BATTERYSTATUS_discharging, corellium_api_peripherals_data_v1_BATTERYSTATUS_not_charging } corellium_api_peripherals_data_v1_BATTERYSTATUS_e;

char* peripherals_data_v1_battery_status_ToString(corellium_api_peripherals_data_v1_BATTERYSTATUS_e battery_status);

corellium_api_peripherals_data_v1_BATTERYSTATUS_e peripherals_data_v1_battery_status_FromString(char* battery_status);

// Enum BATTERYHEALTH for peripherals_data_v1

typedef enum  { corellium_api_peripherals_data_v1_BATTERYHEALTH_NULL = 0, corellium_api_peripherals_data_v1_BATTERYHEALTH_good, corellium_api_peripherals_data_v1_BATTERYHEALTH_overheat, corellium_api_peripherals_data_v1_BATTERYHEALTH_dead, corellium_api_peripherals_data_v1_BATTERYHEALTH_overvolt, corellium_api_peripherals_data_v1_BATTERYHEALTH_failure } corellium_api_peripherals_data_v1_BATTERYHEALTH_e;

char* peripherals_data_v1_battery_health_ToString(corellium_api_peripherals_data_v1_BATTERYHEALTH_e battery_health);

corellium_api_peripherals_data_v1_BATTERYHEALTH_e peripherals_data_v1_battery_health_FromString(char* battery_health);



typedef struct peripherals_data_v1_t {
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
    corellium_api_peripherals_data_v1_BATTERYSTATUS_e battery_status; //enum
    corellium_api_peripherals_data_v1_BATTERYHEALTH_e battery_health; //enum
    double battery_capacity; //numeric
    double biometric_pass; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} peripherals_data_v1_t;

__attribute__((deprecated)) peripherals_data_v1_t *peripherals_data_v1_create(
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
    corellium_api_peripherals_data_v1_BATTERYSTATUS_e battery_status,
    corellium_api_peripherals_data_v1_BATTERYHEALTH_e battery_health,
    double battery_capacity,
    double biometric_pass
);

void peripherals_data_v1_free(peripherals_data_v1_t *peripherals_data_v1);

peripherals_data_v1_t *peripherals_data_v1_parseFromJSON(cJSON *peripherals_data_v1JSON);

cJSON *peripherals_data_v1_convertToJSON(peripherals_data_v1_t *peripherals_data_v1);

#endif /* _peripherals_data_v1_H_ */

