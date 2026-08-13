/*
 * node_console_endpoint.h
 *
 * 
 */

#ifndef _node_console_endpoint_H_
#define _node_console_endpoint_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct node_console_endpoint_t node_console_endpoint_t;




typedef struct node_console_endpoint_t {
    char *url; // string

    int _library_owned; // Is the library responsible for freeing this object?
} node_console_endpoint_t;

__attribute__((deprecated)) node_console_endpoint_t *node_console_endpoint_create(
    char *url
);

void node_console_endpoint_free(node_console_endpoint_t *node_console_endpoint);

node_console_endpoint_t *node_console_endpoint_parseFromJSON(cJSON *node_console_endpointJSON);

cJSON *node_console_endpoint_convertToJSON(node_console_endpoint_t *node_console_endpoint);

#endif /* _node_console_endpoint_H_ */

