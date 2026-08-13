/*
 * activity_v1.h
 *
 * 
 */

#ifndef _activity_v1_H_
#define _activity_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct activity_v1_t activity_v1_t;

#include "any_type.h"
#include "object.h"



typedef struct activity_v1_t {
    char *identifier; // string
    char *domain; // string
    char *actor; // string
    char *event; // string
    char *outcome; // string
    object_t *metadata; //object
    char *corellium_version; // string
    char *project_id; // string
    char *instance_id; // string
    char *created_at; // string
    char *updated_at; // string

    int _library_owned; // Is the library responsible for freeing this object?
} activity_v1_t;

__attribute__((deprecated)) activity_v1_t *activity_v1_create(
    char *identifier,
    char *domain,
    char *actor,
    char *event,
    char *outcome,
    object_t *metadata,
    char *corellium_version,
    char *project_id,
    char *instance_id,
    char *created_at,
    char *updated_at
);

void activity_v1_free(activity_v1_t *activity_v1);

activity_v1_t *activity_v1_parseFromJSON(cJSON *activity_v1JSON);

cJSON *activity_v1_convertToJSON(activity_v1_t *activity_v1);

#endif /* _activity_v1_H_ */

