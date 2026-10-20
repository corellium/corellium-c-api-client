#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "peripherals_data.h"


char* peripherals_data_ac_online_ToString(corellium_api_peripherals_data_ACONLINE_e ac_online) {
    char* ac_onlineArray[] =  { "NULL", "0", "1" };
    return ac_onlineArray[ac_online];
}

corellium_api_peripherals_data_ACONLINE_e peripherals_data_ac_online_FromString(char* ac_online){
    int stringToReturn = 0;
    char *ac_onlineArray[] =  { "NULL", "0", "1" };
    size_t sizeofArray = sizeof(ac_onlineArray) / sizeof(ac_onlineArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(ac_online, ac_onlineArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}
char* peripherals_data_battery_present_ToString(corellium_api_peripherals_data_BATTERYPRESENT_e battery_present) {
    char* battery_presentArray[] =  { "NULL", "0", "1" };
    return battery_presentArray[battery_present];
}

corellium_api_peripherals_data_BATTERYPRESENT_e peripherals_data_battery_present_FromString(char* battery_present){
    int stringToReturn = 0;
    char *battery_presentArray[] =  { "NULL", "0", "1" };
    size_t sizeofArray = sizeof(battery_presentArray) / sizeof(battery_presentArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(battery_present, battery_presentArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}
char* peripherals_data_battery_status_ToString(corellium_api_peripherals_data_BATTERYSTATUS_e battery_status) {
    char* battery_statusArray[] =  { "NULL", "charging", "discharging", "not-charging" };
    return battery_statusArray[battery_status];
}

corellium_api_peripherals_data_BATTERYSTATUS_e peripherals_data_battery_status_FromString(char* battery_status){
    int stringToReturn = 0;
    char *battery_statusArray[] =  { "NULL", "charging", "discharging", "not-charging" };
    size_t sizeofArray = sizeof(battery_statusArray) / sizeof(battery_statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(battery_status, battery_statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}
char* peripherals_data_battery_health_ToString(corellium_api_peripherals_data_BATTERYHEALTH_e battery_health) {
    char* battery_healthArray[] =  { "NULL", "good", "overheat", "dead", "overvolt", "failure" };
    return battery_healthArray[battery_health];
}

corellium_api_peripherals_data_BATTERYHEALTH_e peripherals_data_battery_health_FromString(char* battery_health){
    int stringToReturn = 0;
    char *battery_healthArray[] =  { "NULL", "good", "overheat", "dead", "overvolt", "failure" };
    size_t sizeofArray = sizeof(battery_healthArray) / sizeof(battery_healthArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(battery_health, battery_healthArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}
char* peripherals_data_biometric_pass_ToString(corellium_api_peripherals_data_BIOMETRICPASS_e biometric_pass) {
    char* biometric_passArray[] =  { "NULL", "0", "1" };
    return biometric_passArray[biometric_pass];
}

corellium_api_peripherals_data_BIOMETRICPASS_e peripherals_data_biometric_pass_FromString(char* biometric_pass){
    int stringToReturn = 0;
    char *biometric_passArray[] =  { "NULL", "0", "1" };
    size_t sizeofArray = sizeof(biometric_passArray) / sizeof(biometric_passArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(biometric_pass, biometric_passArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static peripherals_data_t *peripherals_data_create_internal(
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
    ) {
    peripherals_data_t *peripherals_data_local_var = malloc(sizeof(peripherals_data_t));
    if (!peripherals_data_local_var) {
        return NULL;
    }
    peripherals_data_local_var->acceleration = acceleration;
    peripherals_data_local_var->gyroscope = gyroscope;
    peripherals_data_local_var->magnetic = magnetic;
    peripherals_data_local_var->orientation = orientation;
    peripherals_data_local_var->temperature = temperature;
    peripherals_data_local_var->proximity = proximity;
    peripherals_data_local_var->light = light;
    peripherals_data_local_var->pressure = pressure;
    peripherals_data_local_var->humidity = humidity;
    peripherals_data_local_var->gps_lat = gps_lat;
    peripherals_data_local_var->gps_lon = gps_lon;
    peripherals_data_local_var->gps_alt = gps_alt;
    peripherals_data_local_var->gps_toffs = gps_toffs;
    peripherals_data_local_var->ac_online = ac_online;
    peripherals_data_local_var->battery_present = battery_present;
    peripherals_data_local_var->battery_status = battery_status;
    peripherals_data_local_var->battery_health = battery_health;
    peripherals_data_local_var->battery_capacity = battery_capacity;
    peripherals_data_local_var->biometric_pass = biometric_pass;

    peripherals_data_local_var->_library_owned = 1;
    return peripherals_data_local_var;
}

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
    ) {
    return peripherals_data_create_internal (
        acceleration,
        gyroscope,
        magnetic,
        orientation,
        temperature,
        proximity,
        light,
        pressure,
        humidity,
        gps_lat,
        gps_lon,
        gps_alt,
        gps_toffs,
        ac_online,
        battery_present,
        battery_status,
        battery_health,
        battery_capacity,
        biometric_pass
        );
}

void peripherals_data_free(peripherals_data_t *peripherals_data) {
    if(NULL == peripherals_data){
        return ;
    }
    if(peripherals_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "peripherals_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (peripherals_data->acceleration) {
        list_ForEach(listEntry, peripherals_data->acceleration) {
            free(listEntry->data);
        }
        list_freeList(peripherals_data->acceleration);
        peripherals_data->acceleration = NULL;
    }
    if (peripherals_data->gyroscope) {
        list_ForEach(listEntry, peripherals_data->gyroscope) {
            free(listEntry->data);
        }
        list_freeList(peripherals_data->gyroscope);
        peripherals_data->gyroscope = NULL;
    }
    if (peripherals_data->magnetic) {
        list_ForEach(listEntry, peripherals_data->magnetic) {
            free(listEntry->data);
        }
        list_freeList(peripherals_data->magnetic);
        peripherals_data->magnetic = NULL;
    }
    if (peripherals_data->orientation) {
        list_ForEach(listEntry, peripherals_data->orientation) {
            free(listEntry->data);
        }
        list_freeList(peripherals_data->orientation);
        peripherals_data->orientation = NULL;
    }
    free(peripherals_data);
}

cJSON *peripherals_data_convertToJSON(peripherals_data_t *peripherals_data) {
    cJSON *item = cJSON_CreateObject();

    // peripherals_data->acceleration
    if(peripherals_data->acceleration) {
    cJSON *acceleration = cJSON_AddArrayToObject(item, "acceleration");
    if(acceleration == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *accelerationListEntry;
    list_ForEach(accelerationListEntry, peripherals_data->acceleration) {
    if(cJSON_AddNumberToObject(acceleration, "", *(double *)accelerationListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // peripherals_data->gyroscope
    if(peripherals_data->gyroscope) {
    cJSON *gyroscope = cJSON_AddArrayToObject(item, "gyroscope");
    if(gyroscope == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *gyroscopeListEntry;
    list_ForEach(gyroscopeListEntry, peripherals_data->gyroscope) {
    if(cJSON_AddNumberToObject(gyroscope, "", *(double *)gyroscopeListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // peripherals_data->magnetic
    if(peripherals_data->magnetic) {
    cJSON *magnetic = cJSON_AddArrayToObject(item, "magnetic");
    if(magnetic == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *magneticListEntry;
    list_ForEach(magneticListEntry, peripherals_data->magnetic) {
    if(cJSON_AddNumberToObject(magnetic, "", *(double *)magneticListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // peripherals_data->orientation
    if(peripherals_data->orientation) {
    cJSON *orientation = cJSON_AddArrayToObject(item, "orientation");
    if(orientation == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *orientationListEntry;
    list_ForEach(orientationListEntry, peripherals_data->orientation) {
    if(cJSON_AddNumberToObject(orientation, "", *(double *)orientationListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // peripherals_data->temperature
    if(peripherals_data->temperature) {
    if(cJSON_AddNumberToObject(item, "temperature", peripherals_data->temperature) == NULL) {
    goto fail; //Numeric
    }
    }


    // peripherals_data->proximity
    if(peripherals_data->proximity) {
    if(cJSON_AddNumberToObject(item, "proximity", peripherals_data->proximity) == NULL) {
    goto fail; //Numeric
    }
    }


    // peripherals_data->light
    if(peripherals_data->light) {
    if(cJSON_AddNumberToObject(item, "light", peripherals_data->light) == NULL) {
    goto fail; //Numeric
    }
    }


    // peripherals_data->pressure
    if(peripherals_data->pressure) {
    if(cJSON_AddNumberToObject(item, "pressure", peripherals_data->pressure) == NULL) {
    goto fail; //Numeric
    }
    }


    // peripherals_data->humidity
    if(peripherals_data->humidity) {
    if(cJSON_AddNumberToObject(item, "humidity", peripherals_data->humidity) == NULL) {
    goto fail; //Numeric
    }
    }


    // peripherals_data->gps_lat
    if(peripherals_data->gps_lat) {
    if(cJSON_AddNumberToObject(item, "gpsLat", peripherals_data->gps_lat) == NULL) {
    goto fail; //Numeric
    }
    }


    // peripherals_data->gps_lon
    if(peripherals_data->gps_lon) {
    if(cJSON_AddNumberToObject(item, "gpsLon", peripherals_data->gps_lon) == NULL) {
    goto fail; //Numeric
    }
    }


    // peripherals_data->gps_alt
    if(peripherals_data->gps_alt) {
    if(cJSON_AddNumberToObject(item, "gpsAlt", peripherals_data->gps_alt) == NULL) {
    goto fail; //Numeric
    }
    }


    // peripherals_data->gps_toffs
    if(peripherals_data->gps_toffs) {
    if(cJSON_AddNumberToObject(item, "gpsToffs", peripherals_data->gps_toffs) == NULL) {
    goto fail; //Numeric
    }
    }


    // peripherals_data->ac_online
    if(peripherals_data->ac_online != corellium_api_peripherals_data_ACONLINE_NULL) {
    if(cJSON_AddNumberToObject(item, "acOnline", peripherals_data->ac_online) == NULL) {
    goto fail; //Numeric
    }
    }


    // peripherals_data->battery_present
    if(peripherals_data->battery_present != corellium_api_peripherals_data_BATTERYPRESENT_NULL) {
    if(cJSON_AddNumberToObject(item, "batteryPresent", peripherals_data->battery_present) == NULL) {
    goto fail; //Numeric
    }
    }


    // peripherals_data->battery_status
    if(peripherals_data->battery_status != corellium_api_peripherals_data_BATTERYSTATUS_NULL) {
    if(cJSON_AddStringToObject(item, "batteryStatus", peripherals_data_battery_status_ToString(peripherals_data->battery_status)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // peripherals_data->battery_health
    if(peripherals_data->battery_health != corellium_api_peripherals_data_BATTERYHEALTH_NULL) {
    if(cJSON_AddStringToObject(item, "batteryHealth", peripherals_data_battery_health_ToString(peripherals_data->battery_health)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // peripherals_data->battery_capacity
    if(peripherals_data->battery_capacity) {
    if(cJSON_AddNumberToObject(item, "batteryCapacity", peripherals_data->battery_capacity) == NULL) {
    goto fail; //Numeric
    }
    }


    // peripherals_data->biometric_pass
    if(peripherals_data->biometric_pass != corellium_api_peripherals_data_BIOMETRICPASS_NULL) {
    if(cJSON_AddNumberToObject(item, "biometricPass", peripherals_data->biometric_pass) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

peripherals_data_t *peripherals_data_parseFromJSON(cJSON *peripherals_dataJSON){

    peripherals_data_t *peripherals_data_local_var = NULL;

    // define the local list for peripherals_data->acceleration
    list_t *accelerationList = NULL;

    // define the local list for peripherals_data->gyroscope
    list_t *gyroscopeList = NULL;

    // define the local list for peripherals_data->magnetic
    list_t *magneticList = NULL;

    // define the local list for peripherals_data->orientation
    list_t *orientationList = NULL;

    // peripherals_data->acceleration
    cJSON *acceleration = cJSON_GetObjectItemCaseSensitive(peripherals_dataJSON, "acceleration");
    if (cJSON_IsNull(acceleration)) {
        acceleration = NULL;
    }
    if (acceleration) { 
    cJSON *acceleration_local = NULL;
    if(!cJSON_IsArray(acceleration)) {
        goto end;//primitive container
    }
    accelerationList = list_createList();

    cJSON_ArrayForEach(acceleration_local, acceleration)
    {
        if(!cJSON_IsNumber(acceleration_local))
        {
            goto end;
        }
        double *acceleration_local_value = calloc(1, sizeof(double));
        if(!acceleration_local_value)
        {
            goto end;
        }
        *acceleration_local_value = acceleration_local->valuedouble;
        list_addElement(accelerationList , acceleration_local_value);
    }
    }

    // peripherals_data->gyroscope
    cJSON *gyroscope = cJSON_GetObjectItemCaseSensitive(peripherals_dataJSON, "gyroscope");
    if (cJSON_IsNull(gyroscope)) {
        gyroscope = NULL;
    }
    if (gyroscope) { 
    cJSON *gyroscope_local = NULL;
    if(!cJSON_IsArray(gyroscope)) {
        goto end;//primitive container
    }
    gyroscopeList = list_createList();

    cJSON_ArrayForEach(gyroscope_local, gyroscope)
    {
        if(!cJSON_IsNumber(gyroscope_local))
        {
            goto end;
        }
        double *gyroscope_local_value = calloc(1, sizeof(double));
        if(!gyroscope_local_value)
        {
            goto end;
        }
        *gyroscope_local_value = gyroscope_local->valuedouble;
        list_addElement(gyroscopeList , gyroscope_local_value);
    }
    }

    // peripherals_data->magnetic
    cJSON *magnetic = cJSON_GetObjectItemCaseSensitive(peripherals_dataJSON, "magnetic");
    if (cJSON_IsNull(magnetic)) {
        magnetic = NULL;
    }
    if (magnetic) { 
    cJSON *magnetic_local = NULL;
    if(!cJSON_IsArray(magnetic)) {
        goto end;//primitive container
    }
    magneticList = list_createList();

    cJSON_ArrayForEach(magnetic_local, magnetic)
    {
        if(!cJSON_IsNumber(magnetic_local))
        {
            goto end;
        }
        double *magnetic_local_value = calloc(1, sizeof(double));
        if(!magnetic_local_value)
        {
            goto end;
        }
        *magnetic_local_value = magnetic_local->valuedouble;
        list_addElement(magneticList , magnetic_local_value);
    }
    }

    // peripherals_data->orientation
    cJSON *orientation = cJSON_GetObjectItemCaseSensitive(peripherals_dataJSON, "orientation");
    if (cJSON_IsNull(orientation)) {
        orientation = NULL;
    }
    if (orientation) { 
    cJSON *orientation_local = NULL;
    if(!cJSON_IsArray(orientation)) {
        goto end;//primitive container
    }
    orientationList = list_createList();

    cJSON_ArrayForEach(orientation_local, orientation)
    {
        if(!cJSON_IsNumber(orientation_local))
        {
            goto end;
        }
        double *orientation_local_value = calloc(1, sizeof(double));
        if(!orientation_local_value)
        {
            goto end;
        }
        *orientation_local_value = orientation_local->valuedouble;
        list_addElement(orientationList , orientation_local_value);
    }
    }

    // peripherals_data->temperature
    cJSON *temperature = cJSON_GetObjectItemCaseSensitive(peripherals_dataJSON, "temperature");
    if (cJSON_IsNull(temperature)) {
        temperature = NULL;
    }
    if (temperature) { 
    if(!cJSON_IsNumber(temperature))
    {
    goto end; //Numeric
    }
    }

    // peripherals_data->proximity
    cJSON *proximity = cJSON_GetObjectItemCaseSensitive(peripherals_dataJSON, "proximity");
    if (cJSON_IsNull(proximity)) {
        proximity = NULL;
    }
    if (proximity) { 
    if(!cJSON_IsNumber(proximity))
    {
    goto end; //Numeric
    }
    }

    // peripherals_data->light
    cJSON *light = cJSON_GetObjectItemCaseSensitive(peripherals_dataJSON, "light");
    if (cJSON_IsNull(light)) {
        light = NULL;
    }
    if (light) { 
    if(!cJSON_IsNumber(light))
    {
    goto end; //Numeric
    }
    }

    // peripherals_data->pressure
    cJSON *pressure = cJSON_GetObjectItemCaseSensitive(peripherals_dataJSON, "pressure");
    if (cJSON_IsNull(pressure)) {
        pressure = NULL;
    }
    if (pressure) { 
    if(!cJSON_IsNumber(pressure))
    {
    goto end; //Numeric
    }
    }

    // peripherals_data->humidity
    cJSON *humidity = cJSON_GetObjectItemCaseSensitive(peripherals_dataJSON, "humidity");
    if (cJSON_IsNull(humidity)) {
        humidity = NULL;
    }
    if (humidity) { 
    if(!cJSON_IsNumber(humidity))
    {
    goto end; //Numeric
    }
    }

    // peripherals_data->gps_lat
    cJSON *gps_lat = cJSON_GetObjectItemCaseSensitive(peripherals_dataJSON, "gpsLat");
    if (cJSON_IsNull(gps_lat)) {
        gps_lat = NULL;
    }
    if (gps_lat) { 
    if(!cJSON_IsNumber(gps_lat))
    {
    goto end; //Numeric
    }
    }

    // peripherals_data->gps_lon
    cJSON *gps_lon = cJSON_GetObjectItemCaseSensitive(peripherals_dataJSON, "gpsLon");
    if (cJSON_IsNull(gps_lon)) {
        gps_lon = NULL;
    }
    if (gps_lon) { 
    if(!cJSON_IsNumber(gps_lon))
    {
    goto end; //Numeric
    }
    }

    // peripherals_data->gps_alt
    cJSON *gps_alt = cJSON_GetObjectItemCaseSensitive(peripherals_dataJSON, "gpsAlt");
    if (cJSON_IsNull(gps_alt)) {
        gps_alt = NULL;
    }
    if (gps_alt) { 
    if(!cJSON_IsNumber(gps_alt))
    {
    goto end; //Numeric
    }
    }

    // peripherals_data->gps_toffs
    cJSON *gps_toffs = cJSON_GetObjectItemCaseSensitive(peripherals_dataJSON, "gpsToffs");
    if (cJSON_IsNull(gps_toffs)) {
        gps_toffs = NULL;
    }
    if (gps_toffs) { 
    if(!cJSON_IsNumber(gps_toffs))
    {
    goto end; //Numeric
    }
    }

    // peripherals_data->ac_online
    cJSON *ac_online = cJSON_GetObjectItemCaseSensitive(peripherals_dataJSON, "acOnline");
    if (cJSON_IsNull(ac_online)) {
        ac_online = NULL;
    }
    if (ac_online) { 
    if(!cJSON_IsNumber(ac_online))
    {
    goto end; //Numeric
    }
    }

    // peripherals_data->battery_present
    cJSON *battery_present = cJSON_GetObjectItemCaseSensitive(peripherals_dataJSON, "batteryPresent");
    if (cJSON_IsNull(battery_present)) {
        battery_present = NULL;
    }
    if (battery_present) { 
    if(!cJSON_IsNumber(battery_present))
    {
    goto end; //Numeric
    }
    }

    // peripherals_data->battery_status
    cJSON *battery_status = cJSON_GetObjectItemCaseSensitive(peripherals_dataJSON, "batteryStatus");
    if (cJSON_IsNull(battery_status)) {
        battery_status = NULL;
    }
    corellium_api_peripherals_data_BATTERYSTATUS_e battery_statusVariable;
    if (battery_status) { 
    if(!cJSON_IsString(battery_status))
    {
    goto end; //Enum
    }
    battery_statusVariable = peripherals_data_battery_status_FromString(battery_status->valuestring);
    }

    // peripherals_data->battery_health
    cJSON *battery_health = cJSON_GetObjectItemCaseSensitive(peripherals_dataJSON, "batteryHealth");
    if (cJSON_IsNull(battery_health)) {
        battery_health = NULL;
    }
    corellium_api_peripherals_data_BATTERYHEALTH_e battery_healthVariable;
    if (battery_health) { 
    if(!cJSON_IsString(battery_health))
    {
    goto end; //Enum
    }
    battery_healthVariable = peripherals_data_battery_health_FromString(battery_health->valuestring);
    }

    // peripherals_data->battery_capacity
    cJSON *battery_capacity = cJSON_GetObjectItemCaseSensitive(peripherals_dataJSON, "batteryCapacity");
    if (cJSON_IsNull(battery_capacity)) {
        battery_capacity = NULL;
    }
    if (battery_capacity) { 
    if(!cJSON_IsNumber(battery_capacity))
    {
    goto end; //Numeric
    }
    }

    // peripherals_data->biometric_pass
    cJSON *biometric_pass = cJSON_GetObjectItemCaseSensitive(peripherals_dataJSON, "biometricPass");
    if (cJSON_IsNull(biometric_pass)) {
        biometric_pass = NULL;
    }
    if (biometric_pass) { 
    if(!cJSON_IsNumber(biometric_pass))
    {
    goto end; //Numeric
    }
    }


    peripherals_data_local_var = peripherals_data_create_internal (
        acceleration ? accelerationList : NULL,
        gyroscope ? gyroscopeList : NULL,
        magnetic ? magneticList : NULL,
        orientation ? orientationList : NULL,
        temperature ? temperature->valuedouble : 0,
        proximity ? proximity->valuedouble : 0,
        light ? light->valuedouble : 0,
        pressure ? pressure->valuedouble : 0,
        humidity ? humidity->valuedouble : 0,
        gps_lat ? gps_lat->valuedouble : 0,
        gps_lon ? gps_lon->valuedouble : 0,
        gps_alt ? gps_alt->valuedouble : 0,
        gps_toffs ? gps_toffs->valuedouble : 0,
        ac_online ? ac_online->valuedouble : 0,
        battery_present ? battery_present->valuedouble : 0,
        battery_status ? battery_statusVariable : corellium_api_peripherals_data_BATTERYSTATUS_NULL,
        battery_health ? battery_healthVariable : corellium_api_peripherals_data_BATTERYHEALTH_NULL,
        battery_capacity ? battery_capacity->valuedouble : 0,
        biometric_pass ? biometric_pass->valuedouble : 0
        );

    return peripherals_data_local_var;
end:
    if (accelerationList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, accelerationList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(accelerationList);
        accelerationList = NULL;
    }
    if (gyroscopeList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, gyroscopeList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(gyroscopeList);
        gyroscopeList = NULL;
    }
    if (magneticList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, magneticList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(magneticList);
        magneticList = NULL;
    }
    if (orientationList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, orientationList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(orientationList);
        orientationList = NULL;
    }
    return NULL;

}
