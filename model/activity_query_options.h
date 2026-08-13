/*
 * activity_query_options.h
 *
 * 
 */

#ifndef _activity_query_options_H_
#define _activity_query_options_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct activity_query_options_t activity_query_options_t;

#include "any_type.h"
#include "object.h"



typedef struct activity_query_options_t {
    object_t *resource; //object
    double limit; //numeric
    double offset; //numeric
    char *order_by; // string
    char *instance; // string
    char *project_id; // string
    char *actor; // string
    char *search; // string
    char *to; //date time
    char *from; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} activity_query_options_t;

__attribute__((deprecated)) activity_query_options_t *activity_query_options_create(
    object_t *resource,
    double limit,
    double offset,
    char *order_by,
    char *instance,
    char *project_id,
    char *actor,
    char *search,
    char *to,
    char *from
);

void activity_query_options_free(activity_query_options_t *activity_query_options);

activity_query_options_t *activity_query_options_parseFromJSON(cJSON *activity_query_optionsJSON);

cJSON *activity_query_options_convertToJSON(activity_query_options_t *activity_query_options);

#endif /* _activity_query_options_H_ */

