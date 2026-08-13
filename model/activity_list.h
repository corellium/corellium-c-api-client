/*
 * activity_list.h
 *
 * 
 */

#ifndef _activity_list_H_
#define _activity_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct activity_list_t activity_list_t;

#include "activity_v1.h"
#include "pagination.h"



typedef struct activity_list_t {
    list_t *data; //nonprimitive container
    struct pagination_t *pagination; //model

    int _library_owned; // Is the library responsible for freeing this object?
} activity_list_t;

__attribute__((deprecated)) activity_list_t *activity_list_create(
    list_t *data,
    pagination_t *pagination
);

void activity_list_free(activity_list_t *activity_list);

activity_list_t *activity_list_parseFromJSON(cJSON *activity_listJSON);

cJSON *activity_list_convertToJSON(activity_list_t *activity_list);

#endif /* _activity_list_H_ */

