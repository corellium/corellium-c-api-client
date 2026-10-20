/*
 * instance_boot_options_kernel_v1.h
 *
 * 
 */

#ifndef _instance_boot_options_kernel_v1_H_
#define _instance_boot_options_kernel_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct instance_boot_options_kernel_v1_t instance_boot_options_kernel_v1_t;




typedef struct instance_boot_options_kernel_v1_t {
    char *firmware_path; // string

    int _library_owned; // Is the library responsible for freeing this object?
} instance_boot_options_kernel_v1_t;

__attribute__((deprecated)) instance_boot_options_kernel_v1_t *instance_boot_options_kernel_v1_create(
    char *firmware_path
);

void instance_boot_options_kernel_v1_free(instance_boot_options_kernel_v1_t *instance_boot_options_kernel_v1);

instance_boot_options_kernel_v1_t *instance_boot_options_kernel_v1_parseFromJSON(cJSON *instance_boot_options_kernel_v1JSON);

cJSON *instance_boot_options_kernel_v1_convertToJSON(instance_boot_options_kernel_v1_t *instance_boot_options_kernel_v1);

#endif /* _instance_boot_options_kernel_v1_H_ */

