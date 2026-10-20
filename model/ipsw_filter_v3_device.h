/*
 * ipsw_filter_v3_device.h
 *
 * Device constraint.
 */

#ifndef _ipsw_filter_v3_device_H_
#define _ipsw_filter_v3_device_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ipsw_filter_v3_device_t ipsw_filter_v3_device_t;




typedef struct ipsw_filter_v3_device_t {
    char *product; // string

    int _library_owned; // Is the library responsible for freeing this object?
} ipsw_filter_v3_device_t;

__attribute__((deprecated)) ipsw_filter_v3_device_t *ipsw_filter_v3_device_create(
    char *product
);

void ipsw_filter_v3_device_free(ipsw_filter_v3_device_t *ipsw_filter_v3_device);

ipsw_filter_v3_device_t *ipsw_filter_v3_device_parseFromJSON(cJSON *ipsw_filter_v3_deviceJSON);

cJSON *ipsw_filter_v3_device_convertToJSON(ipsw_filter_v3_device_t *ipsw_filter_v3_device);

#endif /* _ipsw_filter_v3_device_H_ */

