/*
 * snapshot_request.h
 *
 * 
 */

#ifndef _snapshot_request_H_
#define _snapshot_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct snapshot_request_t snapshot_request_t;




typedef struct snapshot_request_t {
    double limit; //numeric
    double offset; //numeric
    int springboard; //boolean
    int live; //boolean
    int fresh; //boolean
    char *device_name; // string
    char *task; // string
    char *to; // string
    char *from; // string
    char *order_by; // string
    char *search; // string

    int _library_owned; // Is the library responsible for freeing this object?
} snapshot_request_t;

__attribute__((deprecated)) snapshot_request_t *snapshot_request_create(
    double limit,
    double offset,
    int springboard,
    int live,
    int fresh,
    char *device_name,
    char *task,
    char *to,
    char *from,
    char *order_by,
    char *search
);

void snapshot_request_free(snapshot_request_t *snapshot_request);

snapshot_request_t *snapshot_request_parseFromJSON(cJSON *snapshot_requestJSON);

cJSON *snapshot_request_convertToJSON(snapshot_request_t *snapshot_request);

#endif /* _snapshot_request_H_ */

