/*
 * activity_list_response.h
 *
 * 
 */

#ifndef _activity_list_response_H_
#define _activity_list_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct activity_list_response_t activity_list_response_t;

#include "activity.h"



typedef struct activity_list_response_t {
    list_t *results; //nonprimitive container
    double count; //numeric
    double total; //numeric
    double limit; //numeric
    double offset; //numeric
    int has_more; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} activity_list_response_t;

__attribute__((deprecated)) activity_list_response_t *activity_list_response_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
);

void activity_list_response_free(activity_list_response_t *activity_list_response);

activity_list_response_t *activity_list_response_parseFromJSON(cJSON *activity_list_responseJSON);

cJSON *activity_list_response_convertToJSON(activity_list_response_t *activity_list_response);

#endif /* _activity_list_response_H_ */

