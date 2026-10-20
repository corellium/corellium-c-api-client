/*
 * instance_read_only_status.h
 *
 * 
 */

#ifndef _instance_read_only_status_H_
#define _instance_read_only_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct instance_read_only_status_t instance_read_only_status_t;




typedef struct instance_read_only_status_t {
    char *read_only_status; // string

    int _library_owned; // Is the library responsible for freeing this object?
} instance_read_only_status_t;

__attribute__((deprecated)) instance_read_only_status_t *instance_read_only_status_create(
    char *read_only_status
);

void instance_read_only_status_free(instance_read_only_status_t *instance_read_only_status);

instance_read_only_status_t *instance_read_only_status_parseFromJSON(cJSON *instance_read_only_statusJSON);

cJSON *instance_read_only_status_convertToJSON(instance_read_only_status_t *instance_read_only_status);

#endif /* _instance_read_only_status_H_ */

