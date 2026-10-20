/*
 * extended_firmware_asset_info_v1.h
 *
 * 
 */

#ifndef _extended_firmware_asset_info_v1_H_
#define _extended_firmware_asset_info_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct extended_firmware_asset_info_v1_t extended_firmware_asset_info_v1_t;




typedef struct extended_firmware_asset_info_v1_t {
    list_t *firmwares; //primitive container
    list_t *instances; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} extended_firmware_asset_info_v1_t;

__attribute__((deprecated)) extended_firmware_asset_info_v1_t *extended_firmware_asset_info_v1_create(
    list_t *firmwares,
    list_t *instances
);

void extended_firmware_asset_info_v1_free(extended_firmware_asset_info_v1_t *extended_firmware_asset_info_v1);

extended_firmware_asset_info_v1_t *extended_firmware_asset_info_v1_parseFromJSON(cJSON *extended_firmware_asset_info_v1JSON);

cJSON *extended_firmware_asset_info_v1_convertToJSON(extended_firmware_asset_info_v1_t *extended_firmware_asset_info_v1);

#endif /* _extended_firmware_asset_info_v1_H_ */

