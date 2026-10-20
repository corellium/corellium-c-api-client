/*
 * firmware_info_device_firmwares_inner.h
 *
 * 
 */

#ifndef _firmware_info_device_firmwares_inner_H_
#define _firmware_info_device_firmwares_inner_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct firmware_info_device_firmwares_inner_t firmware_info_device_firmwares_inner_t;




typedef struct firmware_info_device_firmwares_inner_t {
    char *filename; // string
    char *version; // string
    char *build_id; // string
    char *url; // string
    char *orig_url; // string

    int _library_owned; // Is the library responsible for freeing this object?
} firmware_info_device_firmwares_inner_t;

__attribute__((deprecated)) firmware_info_device_firmwares_inner_t *firmware_info_device_firmwares_inner_create(
    char *filename,
    char *version,
    char *build_id,
    char *url,
    char *orig_url
);

void firmware_info_device_firmwares_inner_free(firmware_info_device_firmwares_inner_t *firmware_info_device_firmwares_inner);

firmware_info_device_firmwares_inner_t *firmware_info_device_firmwares_inner_parseFromJSON(cJSON *firmware_info_device_firmwares_innerJSON);

cJSON *firmware_info_device_firmwares_inner_convertToJSON(firmware_info_device_firmwares_inner_t *firmware_info_device_firmwares_inner);

#endif /* _firmware_info_device_firmwares_inner_H_ */

