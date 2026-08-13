/*
 * activity.h
 *
 * 
 */

#ifndef _activity_H_
#define _activity_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct activity_t activity_t;

#include "any_type.h"
#include "object.h"

// Enum OUTCOME for activity

typedef enum  { corellium_api_activity_OUTCOME_NULL = 0, corellium_api_activity_OUTCOME_success, corellium_api_activity_OUTCOME_fail } corellium_api_activity_OUTCOME_e;

char* activity_outcome_ToString(corellium_api_activity_OUTCOME_e outcome);

corellium_api_activity_OUTCOME_e activity_outcome_FromString(char* outcome);



typedef struct activity_t {
    char *identifier; // string
    char *domain; // string
    char *actor; // string
    char *event; // string
    corellium_api_activity_OUTCOME_e outcome; //enum
    object_t *metadata; //object
    char *corellium_version; // string
    char *project_id; // string
    char *instance_id; // string
    char *created_at; //date time
    char *updated_at; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} activity_t;

__attribute__((deprecated)) activity_t *activity_create(
    char *identifier,
    char *domain,
    char *actor,
    char *event,
    corellium_api_activity_OUTCOME_e outcome,
    object_t *metadata,
    char *corellium_version,
    char *project_id,
    char *instance_id,
    char *created_at,
    char *updated_at
);

void activity_free(activity_t *activity);

activity_t *activity_parseFromJSON(cJSON *activityJSON);

cJSON *activity_convertToJSON(activity_t *activity);

#endif /* _activity_H_ */

