/*
 * compute_node_file_list.h
 *
 * 
 */

#ifndef _compute_node_file_list_H_
#define _compute_node_file_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct compute_node_file_list_t compute_node_file_list_t;

#include "compute_node_file.h"



typedef struct compute_node_file_list_t {
    list_t *files; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} compute_node_file_list_t;

__attribute__((deprecated)) compute_node_file_list_t *compute_node_file_list_create(
    list_t *files
);

void compute_node_file_list_free(compute_node_file_list_t *compute_node_file_list);

compute_node_file_list_t *compute_node_file_list_parseFromJSON(cJSON *compute_node_file_listJSON);

cJSON *compute_node_file_list_convertToJSON(compute_node_file_list_t *compute_node_file_list);

#endif /* _compute_node_file_list_H_ */

