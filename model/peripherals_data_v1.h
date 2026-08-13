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
    char *battery_status; // string
    char *battery_health; // string
    double battery_capacity; //numeric

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
    char *battery_status,
    char *battery_health,
    double battery_capacity
);

void peripherals_data_v1_free(peripherals_data_v1_t *peripherals_data_v1);

peripherals_data_v1_t *peripherals_data_v1_parseFromJSON(cJSON *peripherals_data_v1JSON);

cJSON *peripherals_data_v1_convertToJSON(peripherals_data_v1_t *peripherals_data_v1);

#endif /* _peripherals_data_v1_H_ */

