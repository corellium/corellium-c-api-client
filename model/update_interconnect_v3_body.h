/*
 * update_interconnect_v3_body.h
 *
 * 
 */

#ifndef _update_interconnect_v3_body_H_
#define _update_interconnect_v3_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct update_interconnect_v3_body_t update_interconnect_v3_body_t;

#include "interfaces_schema_inner.h"

// Enum TYPE for update_interconnect_v3_body

typedef enum  { corellium_api_update_interconnect_v3_body_TYPE_NULL = 0, corellium_api_update_interconnect_v3_body_TYPE_hub, corellium_api_update_interconnect_v3_body_TYPE__switch } corellium_api_update_interconnect_v3_body_TYPE_e;

char* update_interconnect_v3_body_type_ToString(corellium_api_update_interconnect_v3_body_TYPE_e type);

corellium_api_update_interconnect_v3_body_TYPE_e update_interconnect_v3_body_type_FromString(char* type);



typedef struct update_interconnect_v3_body_t {
    char *name; // string
    list_t *interfaces; //nonprimitive container
    char *protocol; // string
    corellium_api_update_interconnect_v3_body_TYPE_e type; //enum
    char *project_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} update_interconnect_v3_body_t;

__attribute__((deprecated)) update_interconnect_v3_body_t *update_interconnect_v3_body_create(
    char *name,
    list_t *interfaces,
    char *protocol,
    corellium_api_update_interconnect_v3_body_TYPE_e type,
    char *project_id
);

void update_interconnect_v3_body_free(update_interconnect_v3_body_t *update_interconnect_v3_body);

update_interconnect_v3_body_t *update_interconnect_v3_body_parseFromJSON(cJSON *update_interconnect_v3_bodyJSON);

cJSON *update_interconnect_v3_body_convertToJSON(update_interconnect_v3_body_t *update_interconnect_v3_body);

#endif /* _update_interconnect_v3_body_H_ */

