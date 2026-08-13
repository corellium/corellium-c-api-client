/*
 * node_information_v1.h
 *
 * 
 */

#ifndef _node_information_v1_H_
#define _node_information_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct node_information_v1_t node_information_v1_t;




typedef struct node_information_v1_t {
    char *node_id; // string
    char *address; // string
    char *hostname; // string
    double ssh_port; //numeric
    list_t *node_types; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} node_information_v1_t;

__attribute__((deprecated)) node_information_v1_t *node_information_v1_create(
    char *node_id,
    char *address,
    char *hostname,
    double ssh_port,
    list_t *node_types
);

void node_information_v1_free(node_information_v1_t *node_information_v1);

node_information_v1_t *node_information_v1_parseFromJSON(cJSON *node_information_v1JSON);

cJSON *node_information_v1_convertToJSON(node_information_v1_t *node_information_v1);

#endif /* _node_information_v1_H_ */

