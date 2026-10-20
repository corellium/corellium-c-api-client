/*
 * install_firmware_assets_body.h
 *
 * 
 */

#ifndef _install_firmware_assets_body_H_
#define _install_firmware_assets_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct install_firmware_assets_body_t install_firmware_assets_body_t;




typedef struct install_firmware_assets_body_t {
    char *image_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} install_firmware_assets_body_t;

__attribute__((deprecated)) install_firmware_assets_body_t *install_firmware_assets_body_create(
    char *image_id
);

void install_firmware_assets_body_free(install_firmware_assets_body_t *install_firmware_assets_body);

install_firmware_assets_body_t *install_firmware_assets_body_parseFromJSON(cJSON *install_firmware_assets_bodyJSON);

cJSON *install_firmware_assets_body_convertToJSON(install_firmware_assets_body_t *install_firmware_assets_body);

#endif /* _install_firmware_assets_body_H_ */

