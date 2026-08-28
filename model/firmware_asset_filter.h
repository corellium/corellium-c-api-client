/*
 * firmware_asset_filter.h
 *
 * Exact-match filters (filter[url], filter[domain]).
 */

#ifndef _firmware_asset_filter_H_
#define _firmware_asset_filter_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct firmware_asset_filter_t firmware_asset_filter_t;




typedef struct firmware_asset_filter_t {
    char *url; // string
    char *domain; // string

    int _library_owned; // Is the library responsible for freeing this object?
} firmware_asset_filter_t;

__attribute__((deprecated)) firmware_asset_filter_t *firmware_asset_filter_create(
    char *url,
    char *domain
);

void firmware_asset_filter_free(firmware_asset_filter_t *firmware_asset_filter);

firmware_asset_filter_t *firmware_asset_filter_parseFromJSON(cJSON *firmware_asset_filterJSON);

cJSON *firmware_asset_filter_convertToJSON(firmware_asset_filter_t *firmware_asset_filter);

#endif /* _firmware_asset_filter_H_ */

