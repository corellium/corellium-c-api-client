/*
 * instance_console_endpoint_v1.h
 *
 * 
 */

#ifndef _instance_console_endpoint_v1_H_
#define _instance_console_endpoint_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct instance_console_endpoint_v1_t instance_console_endpoint_v1_t;




typedef struct instance_console_endpoint_v1_t {
    char *url; // string

    int _library_owned; // Is the library responsible for freeing this object?
} instance_console_endpoint_v1_t;

__attribute__((deprecated)) instance_console_endpoint_v1_t *instance_console_endpoint_v1_create(
    char *url
);

void instance_console_endpoint_v1_free(instance_console_endpoint_v1_t *instance_console_endpoint_v1);

instance_console_endpoint_v1_t *instance_console_endpoint_v1_parseFromJSON(cJSON *instance_console_endpoint_v1JSON);

cJSON *instance_console_endpoint_v1_convertToJSON(instance_console_endpoint_v1_t *instance_console_endpoint_v1);

#endif /* _instance_console_endpoint_v1_H_ */

