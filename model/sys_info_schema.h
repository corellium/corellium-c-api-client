/*
 * sys_info_schema.h
 *
 * System information for this node.
 */

#ifndef _sys_info_schema_H_
#define _sys_info_schema_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct sys_info_schema_t sys_info_schema_t;

#include "any_type.h"
#include "object.h"



typedef struct sys_info_schema_t {
    double numa_nodes; //numeric
    object_t *cpu; //object
    object_t *cpu_avail; //object
    double slot; //numeric
    double slot_avail; //numeric
    double ram; //numeric
    double ram_avail; //numeric
    double vpn; //numeric
    double vpn_avail; //numeric
    double gpu; //numeric
    double gpu_avail; //numeric
    char *ram_cpu; // string
    char *el032; // string
    char *el132; // string
    char *mmu_tg16k; // string
    double hw_pac; //numeric
    char *arm_trace; // string
    double cores; //numeric
    double cores_avail; //numeric
    double ram_core; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} sys_info_schema_t;

__attribute__((deprecated)) sys_info_schema_t *sys_info_schema_create(
    double numa_nodes,
    object_t *cpu,
    object_t *cpu_avail,
    double slot,
    double slot_avail,
    double ram,
    double ram_avail,
    double vpn,
    double vpn_avail,
    double gpu,
    double gpu_avail,
    char *ram_cpu,
    char *el032,
    char *el132,
    char *mmu_tg16k,
    double hw_pac,
    char *arm_trace,
    double cores,
    double cores_avail,
    double ram_core
);

void sys_info_schema_free(sys_info_schema_t *sys_info_schema);

sys_info_schema_t *sys_info_schema_parseFromJSON(cJSON *sys_info_schemaJSON);

cJSON *sys_info_schema_convertToJSON(sys_info_schema_t *sys_info_schema);

#endif /* _sys_info_schema_H_ */

