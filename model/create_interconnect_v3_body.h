/*
 * create_interconnect_v3_body.h
 *
 * 
 */

#ifndef _create_interconnect_v3_body_H_
#define _create_interconnect_v3_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_interconnect_v3_body_t create_interconnect_v3_body_t;

#include "interconnect_protocol.h"
#include "interfaces_schema_inner.h"

// Enum TYPE for create_interconnect_v3_body

typedef enum  { corellium_api_create_interconnect_v3_body_TYPE_NULL = 0, corellium_api_create_interconnect_v3_body_TYPE_hub, corellium_api_create_interconnect_v3_body_TYPE__switch } corellium_api_create_interconnect_v3_body_TYPE_e;

char* create_interconnect_v3_body_type_ToString(corellium_api_create_interconnect_v3_body_TYPE_e type);

corellium_api_create_interconnect_v3_body_TYPE_e create_interconnect_v3_body_type_FromString(char* type);



typedef struct create_interconnect_v3_body_t {
    char *name; // string
    corellium_api_create_interconnect_v3_body_TYPE_e type; //enum
    list_t *interfaces; //nonprimitive container
    char *project_id; // string
    corellium_api_interconnect_protocol__e protocol; //referenced enum

    int _library_owned; // Is the library responsible for freeing this object?
} create_interconnect_v3_body_t;

__attribute__((deprecated)) create_interconnect_v3_body_t *create_interconnect_v3_body_create(
    char *name,
    corellium_api_create_interconnect_v3_body_TYPE_e type,
    list_t *interfaces,
    char *project_id,
    corellium_api_interconnect_protocol__e protocol
);

void create_interconnect_v3_body_free(create_interconnect_v3_body_t *create_interconnect_v3_body);

create_interconnect_v3_body_t *create_interconnect_v3_body_parseFromJSON(cJSON *create_interconnect_v3_bodyJSON);

cJSON *create_interconnect_v3_body_convertToJSON(create_interconnect_v3_body_t *create_interconnect_v3_body);

#endif /* _create_interconnect_v3_body_H_ */

