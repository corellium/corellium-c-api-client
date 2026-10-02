/*
 * instance_state.h
 *
 * What the device is doing right now. - &#x60;creating&#x60;: being built after &#x60;v3CreateInstance&#x60;. Not usable yet; poll until it changes. - &#x60;booting&#x60;: starting up. Wait for &#x60;on&#x60;. - &#x60;on&#x60;: running and usable. - &#x60;paused&#x60;: stopped mid-run and held in place; &#x60;v3UnpauseInstance&#x60; resumes it. - &#x60;rebooting&#x60;: restarting after &#x60;v3RebootInstance&#x60;. - &#x60;restoring&#x60;: being restored from a snapshot or backup. - &#x60;off&#x60;: shut down. &#x60;v3StartInstance&#x60; turns it on. - &#x60;deleting&#x60;: being removed after &#x60;v3DeleteInstance&#x60;. - &#x60;error&#x60;: something went wrong. See the instance&#39;s &#x60;error&#x60; field.
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

