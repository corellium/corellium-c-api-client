/*
 * node_information.h
 *
 * 
 */

#ifndef _node_information_H_
#define _node_information_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct node_information_t node_information_t;




typedef struct node_information_t {
    char *node_id; // string
    char *address; // string
    char *hostname; // string
    double ssh_port; //numeric
    list_t *node_types; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} node_information_t;

__attribute__((deprecated)) node_information_t *node_information_create(
    char *node_id,
    char *address,
    char *hostname,
    double ssh_port,
    list_t *node_types
);

void node_information_free(node_information_t *node_information);

node_information_t *node_information_parseFromJSON(cJSON *node_informationJSON);

cJSON *node_information_convertToJSON(node_information_t *node_information);

#endif /* _node_information_H_ */

