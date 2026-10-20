/*
 * project_list.h
 *
 * 
 */

#ifndef _project_list_H_
#define _project_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct project_list_t project_list_t;

#include "project_list_item.h"



typedef struct project_list_t {
    list_t *results; //nonprimitive container
    double count; //numeric
    double total; //numeric
    double limit; //numeric
    double offset; //numeric
    int has_more; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} project_list_t;

__attribute__((deprecated)) project_list_t *project_list_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
);

void project_list_free(project_list_t *project_list);

project_list_t *project_list_parseFromJSON(cJSON *project_listJSON);

cJSON *project_list_convertToJSON(project_list_t *project_list);

#endif /* _project_list_H_ */

