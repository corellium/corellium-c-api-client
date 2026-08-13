/*
 * interconnect_response.h
 *
 * 
 */

#ifndef _interconnect_response_H_
#define _interconnect_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct interconnect_response_t interconnect_response_t;

#include "instance_interface.h"

// Enum TYPE for interconnect_response

typedef enum  { corellium_api_interconnect_response_TYPE_NULL = 0, corellium_api_interconnect_response_TYPE_hub, corellium_api_interconnect_response_TYPE__switch } corellium_api_interconnect_response_TYPE_e;

char* interconnect_response_type_ToString(corellium_api_interconnect_response_TYPE_e type);

corellium_api_interconnect_response_TYPE_e interconnect_response_type_FromString(char* type);



typedef struct interconnect_response_t {
    char *id; // string
    char *name; // string
    char *protocol; // string
    corellium_api_interconnect_response_TYPE_e type; //enum
    char *project; // string
    char *status; // string
    list_t *interfaces; //nonprimitive container
    char *created_at; // string
    char *updated_at; // string

    int _library_owned; // Is the library responsible for freeing this object?
} interconnect_response_t;

__attribute__((deprecated)) interconnect_response_t *interconnect_response_create(
    char *id,
    char *name,
    char *protocol,
    corellium_api_interconnect_response_TYPE_e type,
    char *project,
    char *status,
    list_t *interfaces,
    char *created_at,
    char *updated_at
);

void interconnect_response_free(interconnect_response_t *interconnect_response);

interconnect_response_t *interconnect_response_parseFromJSON(cJSON *interconnect_responseJSON);

cJSON *interconnect_response_convertToJSON(interconnect_response_t *interconnect_response);

#endif /* _interconnect_response_H_ */

