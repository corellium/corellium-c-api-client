/*
 * instance_restore_status.h
 *
 * 
 */

#ifndef _instance_restore_status_H_
#define _instance_restore_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct instance_restore_status_t instance_restore_status_t;

#include "any_type.h"
#include "object.h"



typedef struct instance_restore_status_t {
    char *type; // string
    char *stage; // string
    object_t *progress; //object
    object_t *total_progress; //object
    char *heading; // string
    char *description; // string

    int _library_owned; // Is the library responsible for freeing this object?
} instance_restore_status_t;

__attribute__((deprecated)) instance_restore_status_t *instance_restore_status_create(
    char *type,
    char *stage,
    object_t *progress,
    object_t *total_progress,
    char *heading,
    char *description
);

void instance_restore_status_free(instance_restore_status_t *instance_restore_status);

instance_restore_status_t *instance_restore_status_parseFromJSON(cJSON *instance_restore_statusJSON);

cJSON *instance_restore_status_convertToJSON(instance_restore_status_t *instance_restore_status);

#endif /* _instance_restore_status_H_ */

