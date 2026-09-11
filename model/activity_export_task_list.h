/*
 * activity_export_task_list.h
 *
 * 
 */

#ifndef _activity_export_task_list_H_
#define _activity_export_task_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct activity_export_task_list_t activity_export_task_list_t;

#include "activity_export_task.h"



typedef struct activity_export_task_list_t {
    list_t *results; //nonprimitive container
    double count; //numeric
    double total; //numeric
    double limit; //numeric
    double offset; //numeric
    int has_more; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} activity_export_task_list_t;

__attribute__((deprecated)) activity_export_task_list_t *activity_export_task_list_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
);

void activity_export_task_list_free(activity_export_task_list_t *activity_export_task_list);

activity_export_task_list_t *activity_export_task_list_parseFromJSON(cJSON *activity_export_task_listJSON);

cJSON *activity_export_task_list_convertToJSON(activity_export_task_list_t *activity_export_task_list);

#endif /* _activity_export_task_list_H_ */

