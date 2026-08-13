/*
 * vpn_definition_v1.h
 *
 * 
 */

#ifndef _vpn_definition_v1_H_
#define _vpn_definition_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct vpn_definition_v1_t vpn_definition_v1_t;

#include "any_type.h"
#include "object.h"



typedef struct vpn_definition_v1_t {
    list_t *proxy; //nonprimitive container
    list_t *listeners; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} vpn_definition_v1_t;

__attribute__((deprecated)) vpn_definition_v1_t *vpn_definition_v1_create(
    list_t *proxy,
    list_t *listeners
);

void vpn_definition_v1_free(vpn_definition_v1_t *vpn_definition_v1);

vpn_definition_v1_t *vpn_definition_v1_parseFromJSON(cJSON *vpn_definition_v1JSON);

cJSON *vpn_definition_v1_convertToJSON(vpn_definition_v1_t *vpn_definition_v1);

#endif /* _vpn_definition_v1_H_ */

