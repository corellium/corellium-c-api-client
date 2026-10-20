/*
 * compute_node_file.h
 *
 * 
 */

#ifndef _compute_node_file_H_
#define _compute_node_file_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct compute_node_file_t compute_node_file_t;




typedef struct compute_node_file_t {
    char *path; // string
    double size; //numeric
    char *mtime; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} compute_node_file_t;

__attribute__((deprecated)) compute_node_file_t *compute_node_file_create(
    char *path,
    double size,
    char *mtime
);

void compute_node_file_free(compute_node_file_t *compute_node_file);

compute_node_file_t *compute_node_file_parseFromJSON(cJSON *compute_node_fileJSON);

cJSON *compute_node_file_convertToJSON(compute_node_file_t *compute_node_file);

#endif /* _compute_node_file_H_ */

