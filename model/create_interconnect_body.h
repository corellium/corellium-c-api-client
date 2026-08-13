/*
 * create_interconnect_body.h
 *
 * 
 */

#ifndef _create_interconnect_body_H_
#define _create_interconnect_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_interconnect_body_t create_interconnect_body_t;


// Enum TYPE for create_interconnect_body

typedef enum  { corellium_api_create_interconnect_body_TYPE_NULL = 0, corellium_api_create_interconnect_body_TYPE_hub, corellium_api_create_interconnect_body_TYPE__switch } corellium_api_create_interconnect_body_TYPE_e;

char* create_interconnect_body_type_ToString(corellium_api_create_interconnect_body_TYPE_e type);

corellium_api_create_interconnect_body_TYPE_e create_interconnect_body_type_FromString(char* type);



typedef struct create_interconnect_body_t {
    char *name; // string
    char *protocol; // string
    corellium_api_create_interconnect_body_TYPE_e type; //enum
    char *project; // string
    list_t *interfaces; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} create_interconnect_body_t;

__attribute__((deprecated)) create_interconnect_body_t *create_interconnect_body_create(
    char *name,
    char *protocol,
    corellium_api_create_interconnect_body_TYPE_e type,
    char *project,
    list_t *interfaces
);

void create_interconnect_body_free(create_interconnect_body_t *create_interconnect_body);

create_interconnect_body_t *create_interconnect_body_parseFromJSON(cJSON *create_interconnect_bodyJSON);

cJSON *create_interconnect_body_convertToJSON(create_interconnect_body_t *create_interconnect_body);

#endif /* _create_interconnect_body_H_ */

