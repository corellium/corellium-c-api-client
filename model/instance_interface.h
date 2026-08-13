/*
 * instance_interface.h
 *
 * 
 */

#ifndef _instance_interface_H_
#define _instance_interface_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct instance_interface_t instance_interface_t;




typedef struct instance_interface_t {
    char *device_id; // string
    char *interface_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} instance_interface_t;

__attribute__((deprecated)) instance_interface_t *instance_interface_create(
    char *device_id,
    char *interface_id
);

void instance_interface_free(instance_interface_t *instance_interface);

instance_interface_t *instance_interface_parseFromJSON(cJSON *instance_interfaceJSON);

cJSON *instance_interface_convertToJSON(instance_interface_t *instance_interface);

#endif /* _instance_interface_H_ */

