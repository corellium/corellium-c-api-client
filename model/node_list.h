/*
 * node_list.h
 *
 * 
 */

#ifndef _node_list_H_
#define _node_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct node_list_t node_list_t;

#include "node_information.h"



typedef struct node_list_t {
    list_t *results; //nonprimitive container
    double count; //numeric
    double total; //numeric
    double limit; //numeric
    double offset; //numeric
    int has_more; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} node_list_t;

__attribute__((deprecated)) node_list_t *node_list_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
);

void node_list_free(node_list_t *node_list);

node_list_t *node_list_parseFromJSON(cJSON *node_listJSON);

cJSON *node_list_convertToJSON(node_list_t *node_list);

#endif /* _node_list_H_ */

