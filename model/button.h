/*
 * button.h
 *
 * Button definition
 */

#ifndef _button_H_
#define _button_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct button_t button_t;


// Enum  for button

typedef enum { corellium_api_button__NULL = 0, corellium_api_button__finger, corellium_api_button__homeButton, corellium_api_button__holdButton, corellium_api_button__volumeUp, corellium_api_button__volumeDown, corellium_api_button__ringerSwitch, corellium_api_button__backButton, corellium_api_button__overviewButton } corellium_api_button__e;

char* button_button_ToString(corellium_api_button__e button);

corellium_api_button__e button_button_FromString(char* button);

cJSON *button_convertToJSON(corellium_api_button__e button);

corellium_api_button__e button_parseFromJSON(cJSON *buttonJSON);

#endif /* _button_H_ */

