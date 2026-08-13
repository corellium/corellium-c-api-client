/*
 * netdump_filter.h
 *
 * 
 */

#ifndef _netdump_filter_H_
#define _netdump_filter_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct netdump_filter_t netdump_filter_t;




typedef struct netdump_filter_t {
    list_t *port_ranges; //primitive container
    list_t *src_ports; //primitive container
    list_t *dst_ports; //primitive container
    list_t *ports; //primitive container
    list_t *protocols; //primitive container
    list_t *processes; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} netdump_filter_t;

__attribute__((deprecated)) netdump_filter_t *netdump_filter_create(
    list_t *port_ranges,
    list_t *src_ports,
    list_t *dst_ports,
    list_t *ports,
    list_t *protocols,
    list_t *processes
);

void netdump_filter_free(netdump_filter_t *netdump_filter);

netdump_filter_t *netdump_filter_parseFromJSON(cJSON *netdump_filterJSON);

cJSON *netdump_filter_convertToJSON(netdump_filter_t *netdump_filter);

#endif /* _netdump_filter_H_ */

