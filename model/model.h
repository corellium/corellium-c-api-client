/*
 * model.h
 *
 * 
 */

#ifndef _model_H_
#define _model_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct model_t model_t;

#include "any_type.h"
#include "model_frame.h"
#include "model_partition.h"
#include "model_product_image.h"
#include "object.h"



typedef struct model_t {
    char *type; // string
    char *flavor; // string
    char *description; // string
    char *model; // string
    char *hardware_model; // string
    char *board_config; // string
    char *platform; // string
    double cpid; //numeric
    double bdid; //numeric
    char *vendor; // string
    int hidden; //boolean
    int is_beta; //boolean
    int peripherals; //boolean
    int has_software; //boolean
    int supports_rapid_start; //boolean
    char *default_firmware; // string
    double cores; //numeric
    double cores_min; //numeric
    double cores_max; //numeric
    double cores_step; //numeric
    list_t *cores_allowed; //primitive container
    double ram; //numeric
    double ram_min; //numeric
    double ram_max; //numeric
    int dynamic_hardware_changes; //boolean
    list_t *partitions; //nonprimitive container
    struct model_frame_t *frame; //model
    struct model_product_image_t *product_image; //model
    int has_frame_variant; //boolean
    list_t *show_options; //primitive container
    int string_udid; //boolean
    list_t *charm_boot_args; //nonprimitive container
    int requires_preset_boot_options; //boolean
    int supports_preset_boot_options; //boolean
    int supports_custom_firmware; //boolean
    int supports_custom_firmware_image; //boolean
    int supports_custom_kernel; //boolean
    int supports_custom_devicetree; //boolean
    int supports_custom_mmio; //boolean
    int supports_fvp; //boolean
    int mast; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} model_t;

__attribute__((deprecated)) model_t *model_create(
    char *type,
    char *flavor,
    char *description,
    char *model,
    char *hardware_model,
    char *board_config,
    char *platform,
    double cpid,
    double bdid,
    char *vendor,
    int hidden,
    int is_beta,
    int peripherals,
    int has_software,
    int supports_rapid_start,
    char *default_firmware,
    double cores,
    double cores_min,
    double cores_max,
    double cores_step,
    list_t *cores_allowed,
    double ram,
    double ram_min,
    double ram_max,
    int dynamic_hardware_changes,
    list_t *partitions,
    model_frame_t *frame,
    model_product_image_t *product_image,
    int has_frame_variant,
    list_t *show_options,
    int string_udid,
    list_t *charm_boot_args,
    int requires_preset_boot_options,
    int supports_preset_boot_options,
    int supports_custom_firmware,
    int supports_custom_firmware_image,
    int supports_custom_kernel,
    int supports_custom_devicetree,
    int supports_custom_mmio,
    int supports_fvp,
    int mast
);

void model_free(model_t *model);

model_t *model_parseFromJSON(cJSON *modelJSON);

cJSON *model_convertToJSON(model_t *model);

#endif /* _model_H_ */

