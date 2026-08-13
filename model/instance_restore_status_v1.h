/*
 * instance_restore_status_v1.h
 *
 * 
 */

#ifndef _instance_restore_status_v1_H_
#define _instance_restore_status_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct instance_restore_status_v1_t instance_restore_status_v1_t;




typedef struct instance_restore_status_v1_t {
    char *type; // string
    char *stage; // string
    double progress; //numeric
    double total_progress; //numeric
    char *heading; // string
    char *description; // string

    int _library_owned; // Is the library responsible for freeing this object?
} instance_restore_status_v1_t;

__attribute__((deprecated)) instance_restore_status_v1_t *instance_restore_status_v1_create(
    char *type,
    char *stage,
    double progress,
    double total_progress,
    char *heading,
    char *description
);

void instance_restore_status_v1_free(instance_restore_status_v1_t *instance_restore_status_v1);

instance_restore_status_v1_t *instance_restore_status_v1_parseFromJSON(cJSON *instance_restore_status_v1JSON);

cJSON *instance_restore_status_v1_convertToJSON(instance_restore_status_v1_t *instance_restore_status_v1);

#endif /* _instance_restore_status_v1_H_ */

