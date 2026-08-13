/*
 * create_interconnect_response_schema.h
 *
 * 
 */

#ifndef _create_interconnect_response_schema_H_
#define _create_interconnect_response_schema_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_interconnect_response_schema_t create_interconnect_response_schema_t;

#include "interfaces_schema_inner.h"

// Enum TYPE for create_interconnect_response_schema

typedef enum  { corellium_api_create_interconnect_response_schema_TYPE_NULL = 0, corellium_api_create_interconnect_response_schema_TYPE_hub, corellium_api_create_interconnect_response_schema_TYPE__switch } corellium_api_create_interconnect_response_schema_TYPE_e;

char* create_interconnect_response_schema_type_ToString(corellium_api_create_interconnect_response_schema_TYPE_e type);

corellium_api_create_interconnect_response_schema_TYPE_e create_interconnect_response_schema_type_FromString(char* type);

// Enum STATUS for create_interconnect_response_schema

typedef enum  { corellium_api_create_interconnect_response_schema_STATUS_NULL = 0, corellium_api_create_interconnect_response_schema_STATUS_attached, corellium_api_create_interconnect_response_schema_STATUS_detached, corellium_api_create_interconnect_response_schema_STATUS_connected } corellium_api_create_interconnect_response_schema_STATUS_e;

char* create_interconnect_response_schema_status_ToString(corellium_api_create_interconnect_response_schema_STATUS_e status);

corellium_api_create_interconnect_response_schema_STATUS_e create_interconnect_response_schema_status_FromString(char* status);



typedef struct create_interconnect_response_schema_t {
    char *name; // string
    char *protocol; // string
    corellium_api_create_interconnect_response_schema_TYPE_e type; //enum
    char *project; // string
    list_t *interfaces; //nonprimitive container
    char *id; // string
    corellium_api_create_interconnect_response_schema_STATUS_e status; //enum
    char *created_at; //date time
    char *updated_at; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} create_interconnect_response_schema_t;

__attribute__((deprecated)) create_interconnect_response_schema_t *create_interconnect_response_schema_create(
    char *name,
    char *protocol,
    corellium_api_create_interconnect_response_schema_TYPE_e type,
    char *project,
    list_t *interfaces,
    char *id,
    corellium_api_create_interconnect_response_schema_STATUS_e status,
    char *created_at,
    char *updated_at
);

void create_interconnect_response_schema_free(create_interconnect_response_schema_t *create_interconnect_response_schema);

create_interconnect_response_schema_t *create_interconnect_response_schema_parseFromJSON(cJSON *create_interconnect_response_schemaJSON);

cJSON *create_interconnect_response_schema_convertToJSON(create_interconnect_response_schema_t *create_interconnect_response_schema);

#endif /* _create_interconnect_response_schema_H_ */

