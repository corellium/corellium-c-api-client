/*
 * image_firmware_info_boot_args.h
 *
 * Embedded boot arguments.
 */

#ifndef _image_firmware_info_boot_args_H_
#define _image_firmware_info_boot_args_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct image_firmware_info_boot_args_t image_firmware_info_boot_args_t;




typedef struct image_firmware_info_boot_args_t {
    char *normal; // string
    char *restore; // string

    int _library_owned; // Is the library responsible for freeing this object?
} image_firmware_info_boot_args_t;

__attribute__((deprecated)) image_firmware_info_boot_args_t *image_firmware_info_boot_args_create(
    char *normal,
    char *restore
);

void image_firmware_info_boot_args_free(image_firmware_info_boot_args_t *image_firmware_info_boot_args);

image_firmware_info_boot_args_t *image_firmware_info_boot_args_parseFromJSON(cJSON *image_firmware_info_boot_argsJSON);

cJSON *image_firmware_info_boot_args_convertToJSON(image_firmware_info_boot_args_t *image_firmware_info_boot_args);

#endif /* _image_firmware_info_boot_args_H_ */

