/*
 * firmware_service_config_download_ipsw_filters.h
 *
 * 
 */

#ifndef _firmware_service_config_download_ipsw_filters_H_
#define _firmware_service_config_download_ipsw_filters_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct firmware_service_config_download_ipsw_filters_t firmware_service_config_download_ipsw_filters_t;

#include "ipsw_filter_v3.h"



typedef struct firmware_service_config_download_ipsw_filters_t {
    list_t *value; //nonprimitive container
    char *component; // string
    char *title; // string
    char *description; // string
    char *type; // string

    int _library_owned; // Is the library responsible for freeing this object?
} firmware_service_config_download_ipsw_filters_t;

__attribute__((deprecated)) firmware_service_config_download_ipsw_filters_t *firmware_service_config_download_ipsw_filters_create(
    list_t *value,
    char *component,
    char *title,
    char *description,
    char *type
);

void firmware_service_config_download_ipsw_filters_free(firmware_service_config_download_ipsw_filters_t *firmware_service_config_download_ipsw_filters);

firmware_service_config_download_ipsw_filters_t *firmware_service_config_download_ipsw_filters_parseFromJSON(cJSON *firmware_service_config_download_ipsw_filtersJSON);

cJSON *firmware_service_config_download_ipsw_filters_convertToJSON(firmware_service_config_download_ipsw_filters_t *firmware_service_config_download_ipsw_filters);

#endif /* _firmware_service_config_download_ipsw_filters_H_ */

