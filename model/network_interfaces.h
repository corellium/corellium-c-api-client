/*
 * network_interfaces.h
 *
 * 
 */

#ifndef _network_interfaces_H_
#define _network_interfaces_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct network_interfaces_t network_interfaces_t;




typedef struct network_interfaces_t {
    list_t *results; //primitive container
    double count; //numeric
    double total; //numeric
    double limit; //numeric
    double offset; //numeric
    int has_more; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} network_interfaces_t;

__attribute__((deprecated)) network_interfaces_t *network_interfaces_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
);

void network_interfaces_free(network_interfaces_t *network_interfaces);

network_interfaces_t *network_interfaces_parseFromJSON(cJSON *network_interfacesJSON);

cJSON *network_interfaces_convertToJSON(network_interfaces_t *network_interfaces);

#endif /* _network_interfaces_H_ */

