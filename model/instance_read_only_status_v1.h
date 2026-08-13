/*
 * instance_read_only_status_v1.h
 *
 * 
 */

#ifndef _instance_read_only_status_v1_H_
#define _instance_read_only_status_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct instance_read_only_status_v1_t instance_read_only_status_v1_t;




typedef struct instance_read_only_status_v1_t {
    char *read_only_status; // string

    int _library_owned; // Is the library responsible for freeing this object?
} instance_read_only_status_v1_t;

__attribute__((deprecated)) instance_read_only_status_v1_t *instance_read_only_status_v1_create(
    char *read_only_status
);

void instance_read_only_status_v1_free(instance_read_only_status_v1_t *instance_read_only_status_v1);

instance_read_only_status_v1_t *instance_read_only_status_v1_parseFromJSON(cJSON *instance_read_only_status_v1JSON);

cJSON *instance_read_only_status_v1_convertToJSON(instance_read_only_status_v1_t *instance_read_only_status_v1);

#endif /* _instance_read_only_status_v1_H_ */

