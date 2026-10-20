/*
 * install_firmware_assets_body_v1.h
 *
 * 
 */

#ifndef _install_firmware_assets_body_v1_H_
#define _install_firmware_assets_body_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct install_firmware_assets_body_v1_t install_firmware_assets_body_v1_t;




typedef struct install_firmware_assets_body_v1_t {
    char *image_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} install_firmware_assets_body_v1_t;

__attribute__((deprecated)) install_firmware_assets_body_v1_t *install_firmware_assets_body_v1_create(
    char *image_id
);

void install_firmware_assets_body_v1_free(install_firmware_assets_body_v1_t *install_firmware_assets_body_v1);

install_firmware_assets_body_v1_t *install_firmware_assets_body_v1_parseFromJSON(cJSON *install_firmware_assets_body_v1JSON);

cJSON *install_firmware_assets_body_v1_convertToJSON(install_firmware_assets_body_v1_t *install_firmware_assets_body_v1);

#endif /* _install_firmware_assets_body_v1_H_ */

