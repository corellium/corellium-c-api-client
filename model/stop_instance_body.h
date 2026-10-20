/*
 * stop_instance_body.h
 *
 * 
 */

#ifndef _stop_instance_body_H_
#define _stop_instance_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct stop_instance_body_t stop_instance_body_t;




typedef struct stop_instance_body_t {
    int soft; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} stop_instance_body_t;

__attribute__((deprecated)) stop_instance_body_t *stop_instance_body_create(
    int soft
);

void stop_instance_body_free(stop_instance_body_t *stop_instance_body);

stop_instance_body_t *stop_instance_body_parseFromJSON(cJSON *stop_instance_bodyJSON);

cJSON *stop_instance_body_convertToJSON(stop_instance_body_t *stop_instance_body);

#endif /* _stop_instance_body_H_ */

