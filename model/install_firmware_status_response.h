/*
 * install_firmware_status_response.h
 *
 * 
 */

#ifndef _install_firmware_status_response_H_
#define _install_firmware_status_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct install_firmware_status_response_t install_firmware_status_response_t;

#include "task_status.h"



typedef struct install_firmware_status_response_t {
    corellium_api_task_status__e status; //referenced enum
    char *installed_firmware_url; // string

    int _library_owned; // Is the library responsible for freeing this object?
} install_firmware_status_response_t;

__attribute__((deprecated)) install_firmware_status_response_t *install_firmware_status_response_create(
    corellium_api_task_status__e status,
    char *installed_firmware_url
);

void install_firmware_status_response_free(install_firmware_status_response_t *install_firmware_status_response);

install_firmware_status_response_t *install_firmware_status_response_parseFromJSON(cJSON *install_firmware_status_responseJSON);

cJSON *install_firmware_status_response_convertToJSON(install_firmware_status_response_t *install_firmware_status_response);

#endif /* _install_firmware_status_response_H_ */

