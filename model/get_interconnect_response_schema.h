/*
 * get_interconnect_response_schema.h
 *
 * 
 */

#ifndef _get_interconnect_response_schema_H_
#define _get_interconnect_response_schema_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_interconnect_response_schema_t get_interconnect_response_schema_t;

#include "interfaces_schema_inner.h"

// Enum TYPE for get_interconnect_response_schema

typedef enum  { corellium_api_get_interconnect_response_schema_TYPE_NULL = 0, corellium_api_get_interconnect_response_schema_TYPE_hub, corellium_api_get_interconnect_response_schema_TYPE__switch } corellium_api_get_interconnect_response_schema_TYPE_e;

char* get_interconnect_response_schema_type_ToString(corellium_api_get_interconnect_response_schema_TYPE_e type);

corellium_api_get_interconnect_response_schema_TYPE_e get_interconnect_response_schema_type_FromString(char* type);

// Enum STATUS for get_interconnect_response_schema

typedef enum  { corellium_api_get_interconnect_response_schema_STATUS_NULL = 0, corellium_api_get_interconnect_response_schema_STATUS_attached, corellium_api_get_interconnect_response_schema_STATUS_detached, corellium_api_get_interconnect_response_schema_STATUS_connected } corellium_api_get_interconnect_response_schema_STATUS_e;

char* get_interconnect_response_schema_status_ToString(corellium_api_get_interconnect_response_schema_STATUS_e status);

corellium_api_get_interconnect_response_schema_STATUS_e get_interconnect_response_schema_status_FromString(char* status);



typedef struct get_interconnect_response_schema_t {
    char *name; // string
    char *protocol; // string
    corellium_api_get_interconnect_response_schema_TYPE_e type; //enum
    char *project; // string
    list_t *interfaces; //nonprimitive container
    char *id; // string
    corellium_api_get_interconnect_response_schema_STATUS_e status; //enum
    char *created_at; //date time
    char *updated_at; //date time
    double instance_count; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} get_interconnect_response_schema_t;

__attribute__((deprecated)) get_interconnect_response_schema_t *get_interconnect_response_schema_create(
    char *name,
    char *protocol,
    corellium_api_get_interconnect_response_schema_TYPE_e type,
    char *project,
    list_t *interfaces,
    char *id,
    corellium_api_get_interconnect_response_schema_STATUS_e status,
    char *created_at,
    char *updated_at,
    double instance_count
);

void get_interconnect_response_schema_free(get_interconnect_response_schema_t *get_interconnect_response_schema);

get_interconnect_response_schema_t *get_interconnect_response_schema_parseFromJSON(cJSON *get_interconnect_response_schemaJSON);

cJSON *get_interconnect_response_schema_convertToJSON(get_interconnect_response_schema_t *get_interconnect_response_schema);

#endif /* _get_interconnect_response_schema_H_ */

