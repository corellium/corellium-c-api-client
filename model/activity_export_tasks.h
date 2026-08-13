/*
 * activity_export_tasks.h
 *
 * 
 */

#ifndef _activity_export_tasks_H_
#define _activity_export_tasks_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct activity_export_tasks_t activity_export_tasks_t;

#include "any_type.h"
#include "object.h"

// Enum STATUS for activity_export_tasks

typedef enum  { corellium_api_activity_export_tasks_STATUS_NULL = 0, corellium_api_activity_export_tasks_STATUS_in_progress, corellium_api_activity_export_tasks_STATUS_complete, corellium_api_activity_export_tasks_STATUS_error } corellium_api_activity_export_tasks_STATUS_e;

char* activity_export_tasks_status_ToString(corellium_api_activity_export_tasks_STATUS_e status);

corellium_api_activity_export_tasks_STATUS_e activity_export_tasks_status_FromString(char* status);



typedef struct activity_export_tasks_t {
    char *identifier; // string
    char *scheduled_at; //date time
    corellium_api_activity_export_tasks_STATUS_e status; //enum
    object_t *args; //object
    char *created_at; //date time
    char *updated_at; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} activity_export_tasks_t;

__attribute__((deprecated)) activity_export_tasks_t *activity_export_tasks_create(
    char *identifier,
    char *scheduled_at,
    corellium_api_activity_export_tasks_STATUS_e status,
    object_t *args,
    char *created_at,
    char *updated_at
);

void activity_export_tasks_free(activity_export_tasks_t *activity_export_tasks);

activity_export_tasks_t *activity_export_tasks_parseFromJSON(cJSON *activity_export_tasksJSON);

cJSON *activity_export_tasks_convertToJSON(activity_export_tasks_t *activity_export_tasks);

#endif /* _activity_export_tasks_H_ */

