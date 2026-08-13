/*
 * instance_state.h
 *
 * Current instance state.
 */

#ifndef _instance_state_H_
#define _instance_state_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct instance_state_t instance_state_t;


// Enum  for instance_state

typedef enum { corellium_api_instance_state__NULL = 0, corellium_api_instance_state__on, corellium_api_instance_state__off, corellium_api_instance_state__booting, corellium_api_instance_state__deleting, corellium_api_instance_state__creating, corellium_api_instance_state__restoring, corellium_api_instance_state__paused, corellium_api_instance_state__rebooting, corellium_api_instance_state__error } corellium_api_instance_state__e;

char* instance_state_instance_state_ToString(corellium_api_instance_state__e instance_state);

corellium_api_instance_state__e instance_state_instance_state_FromString(char* instance_state);

cJSON *instance_state_convertToJSON(corellium_api_instance_state__e instance_state);

corellium_api_instance_state__e instance_state_parseFromJSON(cJSON *instance_stateJSON);

#endif /* _instance_state_H_ */

