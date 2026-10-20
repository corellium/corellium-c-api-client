/*
 * instance_upgrade_response.h
 *
 * 
 */

#ifndef _instance_upgrade_response_H_
#define _instance_upgrade_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct instance_upgrade_response_t instance_upgrade_response_t;


// Enum STATE for instance_upgrade_response

typedef enum  { corellium_api_instance_upgrade_response_STATE_NULL = 0, corellium_api_instance_upgrade_response_STATE_updating } corellium_api_instance_upgrade_response_STATE_e;

char* instance_upgrade_response_state_ToString(corellium_api_instance_upgrade_response_STATE_e state);

corellium_api_instance_upgrade_response_STATE_e instance_upgrade_response_state_FromString(char* state);



typedef struct instance_upgrade_response_t {
    char *id; // string
    corellium_api_instance_upgrade_response_STATE_e state; //enum

    int _library_owned; // Is the library responsible for freeing this object?
} instance_upgrade_response_t;

__attribute__((deprecated)) instance_upgrade_response_t *instance_upgrade_response_create(
    char *id,
    corellium_api_instance_upgrade_response_STATE_e state
);

void instance_upgrade_response_free(instance_upgrade_response_t *instance_upgrade_response);

instance_upgrade_response_t *instance_upgrade_response_parseFromJSON(cJSON *instance_upgrade_responseJSON);

cJSON *instance_upgrade_response_convertToJSON(instance_upgrade_response_t *instance_upgrade_response);

#endif /* _instance_upgrade_response_H_ */

