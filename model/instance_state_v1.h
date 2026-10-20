/*
 * instance_state_v1.h
 *
 * Current Instance State
 */

#ifndef _instance_state_v1_H_
#define _instance_state_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct instance_state_v1_t instance_state_v1_t;


// Enum  for instance_state_v1

typedef enum { corellium_api_instance_state_v1__NULL = 0, corellium_api_instance_state_v1__on, corellium_api_instance_state_v1__off, corellium_api_instance_state_v1__booting, corellium_api_instance_state_v1__deleting, corellium_api_instance_state_v1__creating, corellium_api_instance_state_v1__restoring, corellium_api_instance_state_v1__paused, corellium_api_instance_state_v1__rebooting, corellium_api_instance_state_v1__error } corellium_api_instance_state_v1__e;

char* instance_state_v1_instance_state_v1_ToString(corellium_api_instance_state_v1__e instance_state_v1);

corellium_api_instance_state_v1__e instance_state_v1_instance_state_v1_FromString(char* instance_state_v1);

cJSON *instance_state_v1_convertToJSON(corellium_api_instance_state_v1__e instance_state_v1);

corellium_api_instance_state_v1__e instance_state_v1_parseFromJSON(cJSON *instance_state_v1JSON);

#endif /* _instance_state_v1_H_ */

