/*
 * interconnect.h
 *
 * 
 */

#ifndef _interconnect_H_
#define _interconnect_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct interconnect_t interconnect_t;

#include "interfaces_schema_inner.h"

// Enum TYPE for interconnect

typedef enum  { corellium_api_interconnect_TYPE_NULL = 0, corellium_api_interconnect_TYPE_hub, corellium_api_interconnect_TYPE__switch } corellium_api_interconnect_TYPE_e;

char* interconnect_type_ToString(corellium_api_interconnect_TYPE_e type);

corellium_api_interconnect_TYPE_e interconnect_type_FromString(char* type);

// Enum STATUS for interconnect

typedef enum  { corellium_api_interconnect_STATUS_NULL = 0, corellium_api_interconnect_STATUS_attached, corellium_api_interconnect_STATUS_detached, corellium_api_interconnect_STATUS_connected } corellium_api_interconnect_STATUS_e;

char* interconnect_status_ToString(corellium_api_interconnect_STATUS_e status);

corellium_api_interconnect_STATUS_e interconnect_status_FromString(char* status);



typedef struct interconnect_t {
    char *name; // string
    corellium_api_interconnect_TYPE_e type; //enum
    char *project_id; // string
    list_t *interfaces; //nonprimitive container
    char *id; // string
    char *protocol; // string
    corellium_api_interconnect_STATUS_e status; //enum
    double instance_count; //numeric
    char *created_at; //date time
    char *updated_at; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} interconnect_t;

__attribute__((deprecated)) interconnect_t *interconnect_create(
    char *name,
    corellium_api_interconnect_TYPE_e type,
    char *project_id,
    list_t *interfaces,
    char *id,
    char *protocol,
    corellium_api_interconnect_STATUS_e status,
    double instance_count,
    char *created_at,
    char *updated_at
);

void interconnect_free(interconnect_t *interconnect);

interconnect_t *interconnect_parseFromJSON(cJSON *interconnectJSON);

cJSON *interconnect_convertToJSON(interconnect_t *interconnect);

#endif /* _interconnect_H_ */

