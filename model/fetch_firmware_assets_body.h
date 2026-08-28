/*
 * fetch_firmware_assets_body.h
 *
 * 
 */

#ifndef _fetch_firmware_assets_body_H_
#define _fetch_firmware_assets_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct fetch_firmware_assets_body_t fetch_firmware_assets_body_t;




typedef struct fetch_firmware_assets_body_t {
    list_t *asset_urls; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} fetch_firmware_assets_body_t;

__attribute__((deprecated)) fetch_firmware_assets_body_t *fetch_firmware_assets_body_create(
    list_t *asset_urls
);

void fetch_firmware_assets_body_free(fetch_firmware_assets_body_t *fetch_firmware_assets_body);

fetch_firmware_assets_body_t *fetch_firmware_assets_body_parseFromJSON(cJSON *fetch_firmware_assets_bodyJSON);

cJSON *fetch_firmware_assets_body_convertToJSON(fetch_firmware_assets_body_t *fetch_firmware_assets_body);

#endif /* _fetch_firmware_assets_body_H_ */

