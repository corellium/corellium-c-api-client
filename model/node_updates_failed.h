/*
 * node_updates_failed.h
 *
 * 
 */

#ifndef _node_updates_failed_H_
#define _node_updates_failed_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct node_updates_failed_t node_updates_failed_t;

#include "node_information_v1.h"



typedef struct node_updates_failed_t {
    char *message; // string
    list_t *nodes; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} node_updates_failed_t;

__attribute__((deprecated)) node_updates_failed_t *node_updates_failed_create(
    char *message,
    list_t *nodes
);

void node_updates_failed_free(node_updates_failed_t *node_updates_failed);

node_updates_failed_t *node_updates_failed_parseFromJSON(cJSON *node_updates_failedJSON);

cJSON *node_updates_failed_convertToJSON(node_updates_failed_t *node_updates_failed);

#endif /* _node_updates_failed_H_ */

