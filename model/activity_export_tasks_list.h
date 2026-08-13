/*
 * activity_export_tasks_list.h
 *
 * 
 */

#ifndef _activity_export_tasks_list_H_
#define _activity_export_tasks_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct activity_export_tasks_list_t activity_export_tasks_list_t;

#include "activity_export_tasks.h"



typedef struct activity_export_tasks_list_t {
    list_t *results; //nonprimitive container
    double count; //numeric
    double total; //numeric
    double limit; //numeric
    double offset; //numeric
    int has_more; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} activity_export_tasks_list_t;

__attribute__((deprecated)) activity_export_tasks_list_t *activity_export_tasks_list_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
);

void activity_export_tasks_list_free(activity_export_tasks_list_t *activity_export_tasks_list);

activity_export_tasks_list_t *activity_export_tasks_list_parseFromJSON(cJSON *activity_export_tasks_listJSON);

cJSON *activity_export_tasks_list_convertToJSON(activity_export_tasks_list_t *activity_export_tasks_list);

#endif /* _activity_export_tasks_list_H_ */

