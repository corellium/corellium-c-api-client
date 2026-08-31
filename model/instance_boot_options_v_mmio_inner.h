/*
 * instance_boot_options_v_mmio_inner.h
 *
 * 
 */

#ifndef _instance_boot_options_v_mmio_inner_H_
#define _instance_boot_options_v_mmio_inner_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct instance_boot_options_v_mmio_inner_t instance_boot_options_v_mmio_inner_t;




typedef struct instance_boot_options_v_mmio_inner_t {
    char *start; // string
    char *size; // string
    char *irq; // string

    int _library_owned; // Is the library responsible for freeing this object?
} instance_boot_options_v_mmio_inner_t;

__attribute__((deprecated)) instance_boot_options_v_mmio_inner_t *instance_boot_options_v_mmio_inner_create(
    char *start,
    char *size,
    char *irq
);

void instance_boot_options_v_mmio_inner_free(instance_boot_options_v_mmio_inner_t *instance_boot_options_v_mmio_inner);

instance_boot_options_v_mmio_inner_t *instance_boot_options_v_mmio_inner_parseFromJSON(cJSON *instance_boot_options_v_mmio_innerJSON);

cJSON *instance_boot_options_v_mmio_inner_convertToJSON(instance_boot_options_v_mmio_inner_t *instance_boot_options_v_mmio_inner);

#endif /* _instance_boot_options_v_mmio_inner_H_ */

