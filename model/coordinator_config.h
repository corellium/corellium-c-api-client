/*
 * coordinator_config.h
 *
 * Partial coordinator configuration to update.
 */

#ifndef _coordinator_config_H_
#define _coordinator_config_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct coordinator_config_t coordinator_config_t;




typedef struct coordinator_config_t {
    int usb_media_access_enabled; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} coordinator_config_t;

__attribute__((deprecated)) coordinator_config_t *coordinator_config_create(
    int usb_media_access_enabled
);

void coordinator_config_free(coordinator_config_t *coordinator_config);

coordinator_config_t *coordinator_config_parseFromJSON(cJSON *coordinator_configJSON);

cJSON *coordinator_config_convertToJSON(coordinator_config_t *coordinator_config);

#endif /* _coordinator_config_H_ */

