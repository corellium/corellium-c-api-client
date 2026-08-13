/*
 * instance_boot_options_kernel.h
 *
 * 
 */

#ifndef _instance_boot_options_kernel_H_
#define _instance_boot_options_kernel_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct instance_boot_options_kernel_t instance_boot_options_kernel_t;




typedef struct instance_boot_options_kernel_t {
    char *firmware_path; // string

    int _library_owned; // Is the library responsible for freeing this object?
} instance_boot_options_kernel_t;

__attribute__((deprecated)) instance_boot_options_kernel_t *instance_boot_options_kernel_create(
    char *firmware_path
);

void instance_boot_options_kernel_free(instance_boot_options_kernel_t *instance_boot_options_kernel);

instance_boot_options_kernel_t *instance_boot_options_kernel_parseFromJSON(cJSON *instance_boot_options_kernelJSON);

cJSON *instance_boot_options_kernel_convertToJSON(instance_boot_options_kernel_t *instance_boot_options_kernel);

#endif /* _instance_boot_options_kernel_H_ */

