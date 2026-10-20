/*
 * pool_usage_schema.h
 *
 * Storage pool usage.
 */

#ifndef _pool_usage_schema_H_
#define _pool_usage_schema_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct pool_usage_schema_t pool_usage_schema_t;




typedef struct pool_usage_schema_t {
    double used; //numeric
    double size; //numeric
    double free; //numeric
    double lv_count; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} pool_usage_schema_t;

__attribute__((deprecated)) pool_usage_schema_t *pool_usage_schema_create(
    double used,
    double size,
    double free,
    double lv_count
);

void pool_usage_schema_free(pool_usage_schema_t *pool_usage_schema);

pool_usage_schema_t *pool_usage_schema_parseFromJSON(cJSON *pool_usage_schemaJSON);

cJSON *pool_usage_schema_convertToJSON(pool_usage_schema_t *pool_usage_schema);

#endif /* _pool_usage_schema_H_ */

