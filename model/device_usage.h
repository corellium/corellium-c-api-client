/*
 * device_usage.h
 *
 * 
 */

#ifndef _device_usage_H_
#define _device_usage_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct device_usage_t device_usage_t;




typedef struct device_usage_t {
    double hours_used; //numeric
    double hours_max; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} device_usage_t;

__attribute__((deprecated)) device_usage_t *device_usage_create(
    double hours_used,
    double hours_max
);

void device_usage_free(device_usage_t *device_usage);

device_usage_t *device_usage_parseFromJSON(cJSON *device_usageJSON);

cJSON *device_usage_convertToJSON(device_usage_t *device_usage);

#endif /* _device_usage_H_ */

