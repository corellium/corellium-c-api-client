/*
 * start_instance_body.h
 *
 * 
 */

#ifndef _start_instance_body_H_
#define _start_instance_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct start_instance_body_t start_instance_body_t;




typedef struct start_instance_body_t {
    int paused; //boolean
    int sock_cap; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} start_instance_body_t;

__attribute__((deprecated)) start_instance_body_t *start_instance_body_create(
    int paused,
    int sock_cap
);

void start_instance_body_free(start_instance_body_t *start_instance_body);

start_instance_body_t *start_instance_body_parseFromJSON(cJSON *start_instance_bodyJSON);

cJSON *start_instance_body_convertToJSON(start_instance_body_t *start_instance_body);

#endif /* _start_instance_body_H_ */

