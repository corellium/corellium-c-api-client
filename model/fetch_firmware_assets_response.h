/*
 * fetch_firmware_assets_response.h
 *
 * 
 */

#ifndef _fetch_firmware_assets_response_H_
#define _fetch_firmware_assets_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct fetch_firmware_assets_response_t fetch_firmware_assets_response_t;

#include "fetch_firmware_assets_response_failed_inner.h"



typedef struct fetch_firmware_assets_response_t {
    list_t *added; //primitive container
    list_t *existing; //primitive container
    list_t *failed; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} fetch_firmware_assets_response_t;

__attribute__((deprecated)) fetch_firmware_assets_response_t *fetch_firmware_assets_response_create(
    list_t *added,
    list_t *existing,
    list_t *failed
);

void fetch_firmware_assets_response_free(fetch_firmware_assets_response_t *fetch_firmware_assets_response);

fetch_firmware_assets_response_t *fetch_firmware_assets_response_parseFromJSON(cJSON *fetch_firmware_assets_responseJSON);

cJSON *fetch_firmware_assets_response_convertToJSON(fetch_firmware_assets_response_t *fetch_firmware_assets_response);

#endif /* _fetch_firmware_assets_response_H_ */

