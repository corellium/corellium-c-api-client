/*
 * instance_boot_options_v1.h
 *
 * 
 */

#ifndef _instance_boot_options_v1_H_
#define _instance_boot_options_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct instance_boot_options_v1_t instance_boot_options_v1_t;

#include "instance_boot_options_kernel_v1.h"
#include "instance_boot_options_pongo_v1.h"



typedef struct instance_boot_options_v1_t {
    char *boot_args; // string
    char *restore_boot_args; // string
    char *udid; // string
    char *ecid; // string
    char *random_seed; // string
    int pac; //boolean
    int aprr; //boolean
    list_t *additional_tags; //primitive container
    struct instance_boot_options_kernel_v1_t *kernel; //model
    struct instance_boot_options_pongo_v1_t *pongo; //model

    int _library_owned; // Is the library responsible for freeing this object?
} instance_boot_options_v1_t;

__attribute__((deprecated)) instance_boot_options_v1_t *instance_boot_options_v1_create(
    char *boot_args,
    char *restore_boot_args,
    char *udid,
    char *ecid,
    char *random_seed,
    int pac,
    int aprr,
    list_t *additional_tags,
    instance_boot_options_kernel_v1_t *kernel,
    instance_boot_options_pongo_v1_t *pongo
);

void instance_boot_options_v1_free(instance_boot_options_v1_t *instance_boot_options_v1);

instance_boot_options_v1_t *instance_boot_options_v1_parseFromJSON(cJSON *instance_boot_options_v1JSON);

cJSON *instance_boot_options_v1_convertToJSON(instance_boot_options_v1_t *instance_boot_options_v1);

#endif /* _instance_boot_options_v1_H_ */

