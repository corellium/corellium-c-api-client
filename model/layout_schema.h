/*
 * layout_schema.h
 *
 * Resource layout for this node.
 */

#ifndef _layout_schema_H_
#define _layout_schema_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct layout_schema_t layout_schema_t;

#include "any_type.h"
#include "object.h"



typedef struct layout_schema_t {
    object_t *free_cpus; //object
    object_t *free_ram; //object
    double free_ranges; //numeric
    double numa_nodes; //numeric
    char *ram_cpu; // string
    object_t *node_map; //object
    object_t *free_cores; //object
    double ram_core; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} layout_schema_t;

__attribute__((deprecated)) layout_schema_t *layout_schema_create(
    object_t *free_cpus,
    object_t *free_ram,
    double free_ranges,
    double numa_nodes,
    char *ram_cpu,
    object_t *node_map,
    object_t *free_cores,
    double ram_core
);

void layout_schema_free(layout_schema_t *layout_schema);

layout_schema_t *layout_schema_parseFromJSON(cJSON *layout_schemaJSON);

cJSON *layout_schema_convertToJSON(layout_schema_t *layout_schema);

#endif /* _layout_schema_H_ */

