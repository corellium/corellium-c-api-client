/*
 * fetch_firmware_assets_response_failed_inner.h
 *
 * 
 */

#ifndef _fetch_firmware_assets_response_failed_inner_H_
#define _fetch_firmware_assets_response_failed_inner_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct fetch_firmware_assets_response_failed_inner_t fetch_firmware_assets_response_failed_inner_t;




typedef struct fetch_firmware_assets_response_failed_inner_t {
    char *url; // string
    char *error; // string

    int _library_owned; // Is the library responsible for freeing this object?
} fetch_firmware_assets_response_failed_inner_t;

__attribute__((deprecated)) fetch_firmware_assets_response_failed_inner_t *fetch_firmware_assets_response_failed_inner_create(
    char *url,
    char *error
);

void fetch_firmware_assets_response_failed_inner_free(fetch_firmware_assets_response_failed_inner_t *fetch_firmware_assets_response_failed_inner);

fetch_firmware_assets_response_failed_inner_t *fetch_firmware_assets_response_failed_inner_parseFromJSON(cJSON *fetch_firmware_assets_response_failed_innerJSON);

cJSON *fetch_firmware_assets_response_failed_inner_convertToJSON(fetch_firmware_assets_response_failed_inner_t *fetch_firmware_assets_response_failed_inner);

#endif /* _fetch_firmware_assets_response_failed_inner_H_ */

