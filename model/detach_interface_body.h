/*
 * detach_interface_body.h
 *
 * 
 */

#ifndef _detach_interface_body_H_
#define _detach_interface_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct detach_interface_body_t detach_interface_body_t;




typedef struct detach_interface_body_t {
    char *interconnect_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} detach_interface_body_t;

__attribute__((deprecated)) detach_interface_body_t *detach_interface_body_create(
    char *interconnect_id
);

void detach_interface_body_free(detach_interface_body_t *detach_interface_body);

detach_interface_body_t *detach_interface_body_parseFromJSON(cJSON *detach_interface_bodyJSON);

cJSON *detach_interface_body_convertToJSON(detach_interface_body_t *detach_interface_body);

#endif /* _detach_interface_body_H_ */

