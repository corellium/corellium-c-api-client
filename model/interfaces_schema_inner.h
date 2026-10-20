/*
 * interfaces_schema_inner.h
 *
 * 
 */

#ifndef _interfaces_schema_inner_H_
#define _interfaces_schema_inner_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct interfaces_schema_inner_t interfaces_schema_inner_t;




typedef struct interfaces_schema_inner_t {
    char *device_id; // string
    char *interface_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} interfaces_schema_inner_t;

__attribute__((deprecated)) interfaces_schema_inner_t *interfaces_schema_inner_create(
    char *device_id,
    char *interface_id
);

void interfaces_schema_inner_free(interfaces_schema_inner_t *interfaces_schema_inner);

interfaces_schema_inner_t *interfaces_schema_inner_parseFromJSON(cJSON *interfaces_schema_innerJSON);

cJSON *interfaces_schema_inner_convertToJSON(interfaces_schema_inner_t *interfaces_schema_inner);

#endif /* _interfaces_schema_inner_H_ */

