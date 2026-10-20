/*
 * available_plans_list_response.h
 *
 * 
 */

#ifndef _available_plans_list_response_H_
#define _available_plans_list_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct available_plans_list_response_t available_plans_list_response_t;

#include "plan.h"



typedef struct available_plans_list_response_t {
    list_t *results; //nonprimitive container
    double count; //numeric
    double total; //numeric
    double limit; //numeric
    double offset; //numeric
    int has_more; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} available_plans_list_response_t;

__attribute__((deprecated)) available_plans_list_response_t *available_plans_list_response_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
);

void available_plans_list_response_free(available_plans_list_response_t *available_plans_list_response);

available_plans_list_response_t *available_plans_list_response_parseFromJSON(cJSON *available_plans_list_responseJSON);

cJSON *available_plans_list_response_convertToJSON(available_plans_list_response_t *available_plans_list_response);

#endif /* _available_plans_list_response_H_ */

