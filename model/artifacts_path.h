/*
 * artifacts_path.h
 *
 * 
 */

#ifndef _artifacts_path_H_
#define _artifacts_path_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct artifacts_path_t artifacts_path_t;




typedef struct artifacts_path_t {
    char *path; // string

    int _library_owned; // Is the library responsible for freeing this object?
} artifacts_path_t;

__attribute__((deprecated)) artifacts_path_t *artifacts_path_create(
    char *path
);

void artifacts_path_free(artifacts_path_t *artifacts_path);

artifacts_path_t *artifacts_path_parseFromJSON(cJSON *artifacts_pathJSON);

cJSON *artifacts_path_convertToJSON(artifacts_path_t *artifacts_path);

#endif /* _artifacts_path_H_ */

