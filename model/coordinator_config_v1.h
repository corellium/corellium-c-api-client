/*
 * coordinator_config_v1.h
 *
 * 
 */

#ifndef _coordinator_config_v1_H_
#define _coordinator_config_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct coordinator_config_v1_t coordinator_config_v1_t;




typedef struct coordinator_config_v1_t {
    int usb_media_access_enabled; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} coordinator_config_v1_t;

__attribute__((deprecated)) coordinator_config_v1_t *coordinator_config_v1_create(
    int usb_media_access_enabled
);

void coordinator_config_v1_free(coordinator_config_v1_t *coordinator_config_v1);

coordinator_config_v1_t *coordinator_config_v1_parseFromJSON(cJSON *coordinator_config_v1JSON);

cJSON *coordinator_config_v1_convertToJSON(coordinator_config_v1_t *coordinator_config_v1);

#endif /* _coordinator_config_v1_H_ */

