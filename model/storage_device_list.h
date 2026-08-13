/*
 * storage_device_list.h
 *
 * 
 */

#ifndef _storage_device_list_H_
#define _storage_device_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct storage_device_list_t storage_device_list_t;

#include "storage_device.h"



typedef struct storage_device_list_t {
    list_t *results; //nonprimitive container
    double count; //numeric
    double total; //numeric
    double limit; //numeric
    double offset; //numeric
    int has_more; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} storage_device_list_t;

__attribute__((deprecated)) storage_device_list_t *storage_device_list_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
);

void storage_device_list_free(storage_device_list_t *storage_device_list);

storage_device_list_t *storage_device_list_parseFromJSON(cJSON *storage_device_listJSON);

cJSON *storage_device_list_convertToJSON(storage_device_list_t *storage_device_list);

#endif /* _storage_device_list_H_ */

