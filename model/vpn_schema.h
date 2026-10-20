/*
 * vpn_schema.h
 *
 * 
 */

#ifndef _vpn_schema_H_
#define _vpn_schema_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct vpn_schema_t vpn_schema_t;

#include "any_type.h"
#include "object.h"



typedef struct vpn_schema_t {
    char *type; // string
    char *project_id; // string
    char *state; // string
    object_t *details; //object

    int _library_owned; // Is the library responsible for freeing this object?
} vpn_schema_t;

__attribute__((deprecated)) vpn_schema_t *vpn_schema_create(
    char *type,
    char *project_id,
    char *state,
    object_t *details
);

void vpn_schema_free(vpn_schema_t *vpn_schema);

vpn_schema_t *vpn_schema_parseFromJSON(cJSON *vpn_schemaJSON);

cJSON *vpn_schema_convertToJSON(vpn_schema_t *vpn_schema);

#endif /* _vpn_schema_H_ */

