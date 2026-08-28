/*
 * image_firmware_info.h
 *
 * 
 */

#ifndef _image_firmware_info_H_
#define _image_firmware_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct image_firmware_info_t image_firmware_info_t;

#include "firmware_info_device.h"
#include "image_firmware_info_boot_args.h"



typedef struct image_firmware_info_t {
    char *type; // string
    char *version; // string
    char *build_id; // string
    list_t *device_ids; //primitive container
    char *board_config; // string
    double bdid; //numeric
    double cpid; //numeric
    char *platform; // string
    struct image_firmware_info_boot_args_t *boot_args; //model
    list_t *variants; //primitive container
    struct firmware_info_device_t *device; //model

    int _library_owned; // Is the library responsible for freeing this object?
} image_firmware_info_t;

__attribute__((deprecated)) image_firmware_info_t *image_firmware_info_create(
    char *type,
    char *version,
    char *build_id,
    list_t *device_ids,
    char *board_config,
    double bdid,
    double cpid,
    char *platform,
    image_firmware_info_boot_args_t *boot_args,
    list_t *variants,
    firmware_info_device_t *device
);

void image_firmware_info_free(image_firmware_info_t *image_firmware_info);

image_firmware_info_t *image_firmware_info_parseFromJSON(cJSON *image_firmware_infoJSON);

cJSON *image_firmware_info_convertToJSON(image_firmware_info_t *image_firmware_info);

#endif /* _image_firmware_info_H_ */

