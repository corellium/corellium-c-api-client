/*
 * config_response_coordinator_config.h
 *
 * 
 */

#ifndef _config_response_coordinator_config_H_
#define _config_response_coordinator_config_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct config_response_coordinator_config_t config_response_coordinator_config_t;




typedef struct config_response_coordinator_config_t {
    int usb_media_access_enabled; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} config_response_coordinator_config_t;

__attribute__((deprecated)) config_response_coordinator_config_t *config_response_coordinator_config_create(
    int usb_media_access_enabled
);

void config_response_coordinator_config_free(config_response_coordinator_config_t *config_response_coordinator_config);

config_response_coordinator_config_t *config_response_coordinator_config_parseFromJSON(cJSON *config_response_coordinator_configJSON);

cJSON *config_response_coordinator_config_convertToJSON(config_response_coordinator_config_t *config_response_coordinator_config);

#endif /* _config_response_coordinator_config_H_ */

