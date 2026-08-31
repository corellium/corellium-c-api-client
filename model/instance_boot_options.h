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

#include "instance_boot_options_fvp.h"
#include "instance_boot_options_kernel.h"
#include "instance_boot_options_pongo.h"
#include "instance_boot_options_v_mmio_inner.h"



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
    char *serial; // string
    int no_snapshot_mount; //boolean
    char *kernel_slide; // string
    list_t *cd_hashes; //primitive container
    char *imei; // string
    char *imsi; // string
    char *ssid0; // string
    char *ssid1; // string
    char *wifi_mac; // string
    char *model_id; // string
    char *manufacturer_id; // string
    char *kernel_patches; // string
    int stop_on_fault; //boolean
    char *boot_addr; // string
    int tzen; //boolean
    char *authorized_keys; // string
    list_t *v_mmio; //nonprimitive container
    struct instance_boot_options_fvp_t *fvp; //model

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
    instance_boot_options_pongo_t *pongo,
    char *serial,
    int no_snapshot_mount,
    char *kernel_slide,
    list_t *cd_hashes,
    char *imei,
    char *imsi,
    char *ssid0,
    char *ssid1,
    char *wifi_mac,
    char *model_id,
    char *manufacturer_id,
    char *kernel_patches,
    int stop_on_fault,
    char *boot_addr,
    int tzen,
    char *authorized_keys,
    list_t *v_mmio,
    instance_boot_options_fvp_t *fvp
);

void instance_boot_options_free(instance_boot_options_t *instance_boot_options);

instance_boot_options_t *instance_boot_options_parseFromJSON(cJSON *instance_boot_optionsJSON);

cJSON *instance_boot_options_convertToJSON(instance_boot_options_t *instance_boot_options);

#endif /* _instance_boot_options_H_ */

