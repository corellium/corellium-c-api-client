/*
 * extended_firmware_asset_info.h
 *
 * 
 */

#ifndef _extended_firmware_asset_info_H_
#define _extended_firmware_asset_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct extended_firmware_asset_info_t extended_firmware_asset_info_t;




typedef struct extended_firmware_asset_info_t {
    list_t *firmwares; //primitive container
    list_t *instances; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} extended_firmware_asset_info_t;

__attribute__((deprecated)) extended_firmware_asset_info_t *extended_firmware_asset_info_create(
    list_t *firmwares,
    list_t *instances
);

void extended_firmware_asset_info_free(extended_firmware_asset_info_t *extended_firmware_asset_info);

extended_firmware_asset_info_t *extended_firmware_asset_info_parseFromJSON(cJSON *extended_firmware_asset_infoJSON);

cJSON *extended_firmware_asset_info_convertToJSON(extended_firmware_asset_info_t *extended_firmware_asset_info);

#endif /* _extended_firmware_asset_info_H_ */

