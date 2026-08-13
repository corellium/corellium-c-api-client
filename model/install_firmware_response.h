/*
 * install_firmware_response.h
 *
 * 
 */

#ifndef _install_firmware_response_H_
#define _install_firmware_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct install_firmware_response_t install_firmware_response_t;




typedef struct install_firmware_response_t {
    char *task_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} install_firmware_response_t;

__attribute__((deprecated)) install_firmware_response_t *install_firmware_response_create(
    char *task_id
);

void install_firmware_response_free(install_firmware_response_t *install_firmware_response);

install_firmware_response_t *install_firmware_response_parseFromJSON(cJSON *install_firmware_responseJSON);

cJSON *install_firmware_response_convertToJSON(install_firmware_response_t *install_firmware_response);

#endif /* _install_firmware_response_H_ */

