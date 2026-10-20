/*
 * enable_btrace_body.h
 *
 * 
 */

#ifndef _enable_btrace_body_H_
#define _enable_btrace_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct enable_btrace_body_t enable_btrace_body_t;




typedef struct enable_btrace_body_t {
    list_t *ranges; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} enable_btrace_body_t;

__attribute__((deprecated)) enable_btrace_body_t *enable_btrace_body_create(
    list_t *ranges
);

void enable_btrace_body_free(enable_btrace_body_t *enable_btrace_body);

enable_btrace_body_t *enable_btrace_body_parseFromJSON(cJSON *enable_btrace_bodyJSON);

cJSON *enable_btrace_body_convertToJSON(enable_btrace_body_t *enable_btrace_body);

#endif /* _enable_btrace_body_H_ */

