/*
 * install_firmware_assets_response.h
 *
 * 
 */

#ifndef _install_firmware_assets_response_H_
#define _install_firmware_assets_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct install_firmware_assets_response_t install_firmware_assets_response_t;




typedef struct install_firmware_assets_response_t {
    char *message; // string

    int _library_owned; // Is the library responsible for freeing this object?
} install_firmware_assets_response_t;

__attribute__((deprecated)) install_firmware_assets_response_t *install_firmware_assets_response_create(
    char *message
);

void install_firmware_assets_response_free(install_firmware_assets_response_t *install_firmware_assets_response);

install_firmware_assets_response_t *install_firmware_assets_response_parseFromJSON(cJSON *install_firmware_assets_responseJSON);

cJSON *install_firmware_assets_response_convertToJSON(install_firmware_assets_response_t *install_firmware_assets_response);

#endif /* _install_firmware_assets_response_H_ */

