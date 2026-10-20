/*
 * activity_export_status.h
 *
 * 
 */

#ifndef _activity_export_status_H_
#define _activity_export_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct activity_export_status_t activity_export_status_t;


// Enum STATUS for activity_export_status

typedef enum  { corellium_api_activity_export_status_STATUS_NULL = 0, corellium_api_activity_export_status_STATUS_in_progress, corellium_api_activity_export_status_STATUS_complete, corellium_api_activity_export_status_STATUS_error } corellium_api_activity_export_status_STATUS_e;

char* activity_export_status_status_ToString(corellium_api_activity_export_status_STATUS_e status);

corellium_api_activity_export_status_STATUS_e activity_export_status_status_FromString(char* status);



typedef struct activity_export_status_t {
    corellium_api_activity_export_status_STATUS_e status; //enum

    int _library_owned; // Is the library responsible for freeing this object?
} activity_export_status_t;

__attribute__((deprecated)) activity_export_status_t *activity_export_status_create(
    corellium_api_activity_export_status_STATUS_e status
);

void activity_export_status_free(activity_export_status_t *activity_export_status);

activity_export_status_t *activity_export_status_parseFromJSON(cJSON *activity_export_statusJSON);

cJSON *activity_export_status_convertToJSON(activity_export_status_t *activity_export_status);

#endif /* _activity_export_status_H_ */

