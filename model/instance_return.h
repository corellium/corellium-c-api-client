/*
 * instance_return.h
 *
 * 
 */

#ifndef _instance_return_H_
#define _instance_return_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct instance_return_t instance_return_t;


// Enum STATE for instance_return

typedef enum  { corellium_api_instance_return_STATE_NULL = 0, corellium_api_instance_return_STATE_creating } corellium_api_instance_return_STATE_e;

char* instance_return_state_ToString(corellium_api_instance_return_STATE_e state);

corellium_api_instance_return_STATE_e instance_return_state_FromString(char* state);



typedef struct instance_return_t {
    char *id; // string
    corellium_api_instance_return_STATE_e state; //enum

    int _library_owned; // Is the library responsible for freeing this object?
} instance_return_t;

__attribute__((deprecated)) instance_return_t *instance_return_create(
    char *id,
    corellium_api_instance_return_STATE_e state
);

void instance_return_free(instance_return_t *instance_return);

instance_return_t *instance_return_parseFromJSON(cJSON *instance_returnJSON);

cJSON *instance_return_convertToJSON(instance_return_t *instance_return);

#endif /* _instance_return_H_ */

