/*
 * instance_uefi_bootloader.h
 *
 * UEFI bootloader descriptor, when the device uses one.
 */

#ifndef _instance_uefi_bootloader_H_
#define _instance_uefi_bootloader_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct instance_uefi_bootloader_t instance_uefi_bootloader_t;




typedef struct instance_uefi_bootloader_t {
    char *label; // string
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} instance_uefi_bootloader_t;

__attribute__((deprecated)) instance_uefi_bootloader_t *instance_uefi_bootloader_create(
    char *label,
    char *name
);

void instance_uefi_bootloader_free(instance_uefi_bootloader_t *instance_uefi_bootloader);

instance_uefi_bootloader_t *instance_uefi_bootloader_parseFromJSON(cJSON *instance_uefi_bootloaderJSON);

cJSON *instance_uefi_bootloader_convertToJSON(instance_uefi_bootloader_t *instance_uefi_bootloader);

#endif /* _instance_uefi_bootloader_H_ */

