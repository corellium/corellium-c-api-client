/*
 * project_instance_list.h
 *
 * 
 */

#ifndef _project_instance_list_H_
#define _project_instance_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct project_instance_list_t project_instance_list_t;

#include "project_instance_summary.h"



typedef struct project_instance_list_t {
    list_t *results; //nonprimitive container
    double count; //numeric
    double total; //numeric
    double limit; //numeric
    double offset; //numeric
    int has_more; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} project_instance_list_t;

__attribute__((deprecated)) project_instance_list_t *project_instance_list_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
);

void project_instance_list_free(project_instance_list_t *project_instance_list);

project_instance_list_t *project_instance_list_parseFromJSON(cJSON *project_instance_listJSON);

cJSON *project_instance_list_convertToJSON(project_instance_list_t *project_instance_list);

#endif /* _project_instance_list_H_ */

