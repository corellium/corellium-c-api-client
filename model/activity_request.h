/*
 * activity_request.h
 *
 * 
 */

#ifndef _activity_request_H_
#define _activity_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct activity_request_t activity_request_t;




typedef struct activity_request_t {
    char *resource; // string
    double limit; //numeric
    char *order_by; // string
    double page; //numeric
    char *instance; // string
    char *project; // string
    char *actor; // string
    char *search; // string
    char *to; // string
    char *from; // string

    int _library_owned; // Is the library responsible for freeing this object?
} activity_request_t;

__attribute__((deprecated)) activity_request_t *activity_request_create(
    char *resource,
    double limit,
    char *order_by,
    double page,
    char *instance,
    char *project,
    char *actor,
    char *search,
    char *to,
    char *from
);

void activity_request_free(activity_request_t *activity_request);

activity_request_t *activity_request_parseFromJSON(cJSON *activity_requestJSON);

cJSON *activity_request_convertToJSON(activity_request_t *activity_request);

#endif /* _activity_request_H_ */

