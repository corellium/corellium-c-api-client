/*
 * ipsw_filter_v3.h
 *
 * 
 */

#ifndef _ipsw_filter_v3_H_
#define _ipsw_filter_v3_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ipsw_filter_v3_t ipsw_filter_v3_t;

#include "ipsw_filter_v3_device.h"
#include "ipsw_filter_v3_version.h"



typedef struct ipsw_filter_v3_t {
    struct ipsw_filter_v3_version_t *version; //model
    struct ipsw_filter_v3_device_t *device; //model
    int exclude; //boolean
    int include; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} ipsw_filter_v3_t;

__attribute__((deprecated)) ipsw_filter_v3_t *ipsw_filter_v3_create(
    ipsw_filter_v3_version_t *version,
    ipsw_filter_v3_device_t *device,
    int exclude,
    int include
);

void ipsw_filter_v3_free(ipsw_filter_v3_t *ipsw_filter_v3);

ipsw_filter_v3_t *ipsw_filter_v3_parseFromJSON(cJSON *ipsw_filter_v3JSON);

cJSON *ipsw_filter_v3_convertToJSON(ipsw_filter_v3_t *ipsw_filter_v3);

#endif /* _ipsw_filter_v3_H_ */

