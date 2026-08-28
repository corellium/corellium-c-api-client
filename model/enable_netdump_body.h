/*
 * enable_netdump_body.h
 *
 * 
 */

#ifndef _enable_netdump_body_H_
#define _enable_netdump_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct enable_netdump_body_t enable_netdump_body_t;




typedef struct enable_netdump_body_t {
    list_t *port_ranges; //primitive container
    list_t *src_ports; //primitive container
    list_t *dst_ports; //primitive container
    list_t *ports; //primitive container
    list_t *protocols; //primitive container
    list_t *processes; //primitive container
    list_t *hosts; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} enable_netdump_body_t;

__attribute__((deprecated)) enable_netdump_body_t *enable_netdump_body_create(
    list_t *port_ranges,
    list_t *src_ports,
    list_t *dst_ports,
    list_t *ports,
    list_t *protocols,
    list_t *processes,
    list_t *hosts
);

void enable_netdump_body_free(enable_netdump_body_t *enable_netdump_body);

enable_netdump_body_t *enable_netdump_body_parseFromJSON(cJSON *enable_netdump_bodyJSON);

cJSON *enable_netdump_body_convertToJSON(enable_netdump_body_t *enable_netdump_body);

#endif /* _enable_netdump_body_H_ */

