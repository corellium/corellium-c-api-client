/*
 * project_usage_v1.h
 *
 * 
 */

#ifndef _project_usage_v1_H_
#define _project_usage_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct project_usage_v1_t project_usage_v1_t;




typedef struct project_usage_v1_t {
    double cores; //numeric
    double instances; //numeric
    double ram; //numeric
    double gpu; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} project_usage_v1_t;

__attribute__((deprecated)) project_usage_v1_t *project_usage_v1_create(
    double cores,
    double instances,
    double ram,
    double gpu
);

void project_usage_v1_free(project_usage_v1_t *project_usage_v1);

project_usage_v1_t *project_usage_v1_parseFromJSON(cJSON *project_usage_v1JSON);

cJSON *project_usage_v1_convertToJSON(project_usage_v1_t *project_usage_v1);

#endif /* _project_usage_v1_H_ */

