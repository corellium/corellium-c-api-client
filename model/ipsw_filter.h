/*
 * ipsw_filter.h
 *
 * 
 */

#ifndef _ipsw_filter_H_
#define _ipsw_filter_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ipsw_filter_t ipsw_filter_t;

#include "ipsw_device_constraint.h"
#include "ipsw_version_constraint.h"



typedef struct ipsw_filter_t {
    struct ipsw_version_constraint_t *version; //model
    struct ipsw_device_constraint_t *device; //model
    int exclude; //boolean
    int include; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} ipsw_filter_t;

__attribute__((deprecated)) ipsw_filter_t *ipsw_filter_create(
    ipsw_version_constraint_t *version,
    ipsw_device_constraint_t *device,
    int exclude,
    int include
);

void ipsw_filter_free(ipsw_filter_t *ipsw_filter);

ipsw_filter_t *ipsw_filter_parseFromJSON(cJSON *ipsw_filterJSON);

cJSON *ipsw_filter_convertToJSON(ipsw_filter_t *ipsw_filter);

#endif /* _ipsw_filter_H_ */

