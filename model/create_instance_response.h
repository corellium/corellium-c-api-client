/*
 * create_instance_response.h
 *
 * 
 */

#ifndef _create_instance_response_H_
#define _create_instance_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_instance_response_t create_instance_response_t;


// Enum STATE for create_instance_response

typedef enum  { corellium_api_create_instance_response_STATE_NULL = 0, corellium_api_create_instance_response_STATE_creating } corellium_api_create_instance_response_STATE_e;

char* create_instance_response_state_ToString(corellium_api_create_instance_response_STATE_e state);

corellium_api_create_instance_response_STATE_e create_instance_response_state_FromString(char* state);



typedef struct create_instance_response_t {
    char *id; // string
    corellium_api_create_instance_response_STATE_e state; //enum

    int _library_owned; // Is the library responsible for freeing this object?
} create_instance_response_t;

__attribute__((deprecated)) create_instance_response_t *create_instance_response_create(
    char *id,
    corellium_api_create_instance_response_STATE_e state
);

void create_instance_response_free(create_instance_response_t *create_instance_response);

create_instance_response_t *create_instance_response_parseFromJSON(cJSON *create_instance_responseJSON);

cJSON *create_instance_response_convertToJSON(create_instance_response_t *create_instance_response);

#endif /* _create_instance_response_H_ */

