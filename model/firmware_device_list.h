/*
 * firmware_device_list.h
 *
 * 
 */

#ifndef _firmware_device_list_H_
#define _firmware_device_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct firmware_device_list_t firmware_device_list_t;

#include "firmware_device.h"



typedef struct firmware_device_list_t {
    list_t *results; //nonprimitive container
    double count; //numeric
    double total; //numeric
    double limit; //numeric
    double offset; //numeric
    int has_more; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} firmware_device_list_t;

__attribute__((deprecated)) firmware_device_list_t *firmware_device_list_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
);

void firmware_device_list_free(firmware_device_list_t *firmware_device_list);

firmware_device_list_t *firmware_device_list_parseFromJSON(cJSON *firmware_device_listJSON);

cJSON *firmware_device_list_convertToJSON(firmware_device_list_t *firmware_device_list);

#endif /* _firmware_device_list_H_ */

