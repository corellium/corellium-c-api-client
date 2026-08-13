/*
 * instance_boot_options.h
 *
 * 
 */

#ifndef _instance_boot_options_H_
#define _instance_boot_options_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct instance_boot_options_t instance_boot_options_t;

#include "instance_boot_options_kernel.h"
#include "instance_boot_options_pongo.h"



typedef struct instance_boot_options_t {
    char *boot_args; // string
    char *restore_boot_args; // string
    char *udid; // string
    char *ecid; // string
    char *random_seed; // string
    int pac; //boolean
    int aprr; //boolean
    double cores; //numeric
    double ram; //numeric
    list_t *additional_tags; //primitive container
    struct instance_boot_options_kernel_t *kernel; //model
    struct instance_boot_options_pongo_t *pongo; //model

    int _library_owned; // Is the library responsible for freeing this object?
} instance_boot_options_t;

__attribute__((deprecated)) instance_boot_options_t *instance_boot_options_create(
    char *boot_args,
    char *restore_boot_args,
    char *udid,
    char *ecid,
    char *random_seed,
    int pac,
    int aprr,
    double cores,
    double ram,
    list_t *additional_tags,
    instance_boot_options_kernel_t *kernel,
    instance_boot_options_pongo_t *pongo
);

void instance_boot_options_free(instance_boot_options_t *instance_boot_options);

instance_boot_options_t *instance_boot_options_parseFromJSON(cJSON *instance_boot_optionsJSON);

cJSON *instance_boot_options_convertToJSON(instance_boot_options_t *instance_boot_options);

#endif /* _instance_boot_options_H_ */

