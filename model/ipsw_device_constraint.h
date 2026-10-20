/*
 * ipsw_device_constraint.h
 *
 * 
 */

#ifndef _ipsw_device_constraint_H_
#define _ipsw_device_constraint_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ipsw_device_constraint_t ipsw_device_constraint_t;




typedef struct ipsw_device_constraint_t {
    char *product; // string

    int _library_owned; // Is the library responsible for freeing this object?
} ipsw_device_constraint_t;

__attribute__((deprecated)) ipsw_device_constraint_t *ipsw_device_constraint_create(
    char *product
);

void ipsw_device_constraint_free(ipsw_device_constraint_t *ipsw_device_constraint);

ipsw_device_constraint_t *ipsw_device_constraint_parseFromJSON(cJSON *ipsw_device_constraintJSON);

cJSON *ipsw_device_constraint_convertToJSON(ipsw_device_constraint_t *ipsw_device_constraint);

#endif /* _ipsw_device_constraint_H_ */

