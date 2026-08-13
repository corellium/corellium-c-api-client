/*
 * attach_interface_body.h
 *
 * 
 */

#ifndef _attach_interface_body_H_
#define _attach_interface_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct attach_interface_body_t attach_interface_body_t;




typedef struct attach_interface_body_t {
    char *interface_id; // string
    char *interconnect_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} attach_interface_body_t;

__attribute__((deprecated)) attach_interface_body_t *attach_interface_body_create(
    char *interface_id,
    char *interconnect_id
);

void attach_interface_body_free(attach_interface_body_t *attach_interface_body);

attach_interface_body_t *attach_interface_body_parseFromJSON(cJSON *attach_interface_bodyJSON);

cJSON *attach_interface_body_convertToJSON(attach_interface_body_t *attach_interface_body);

#endif /* _attach_interface_body_H_ */

