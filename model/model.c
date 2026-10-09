#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "model.h"



static model_t *model_create_internal(
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
    ) {
    model_t *model_local_var = malloc(sizeof(model_t));
    if (!model_local_var) {
        return NULL;
    }
    model_local_var->type = type;
    model_local_var->flavor = flavor;
    model_local_var->description = description;
    model_local_var->model = model;
    model_local_var->hardware_model = hardware_model;
    model_local_var->board_config = board_config;
    model_local_var->platform = platform;
    model_local_var->cpid = cpid;
    model_local_var->bdid = bdid;
    model_local_var->vendor = vendor;
    model_local_var->hidden = hidden;
    model_local_var->is_beta = is_beta;
    model_local_var->peripherals = peripherals;
    model_local_var->has_software = has_software;
    model_local_var->supports_rapid_start = supports_rapid_start;
    model_local_var->default_firmware = default_firmware;
    model_local_var->cores = cores;
    model_local_var->cores_min = cores_min;
    model_local_var->cores_max = cores_max;
    model_local_var->cores_step = cores_step;
    model_local_var->cores_allowed = cores_allowed;
    model_local_var->ram = ram;
    model_local_var->ram_min = ram_min;
    model_local_var->ram_max = ram_max;
    model_local_var->dynamic_hardware_changes = dynamic_hardware_changes;
    model_local_var->partitions = partitions;
    model_local_var->frame = frame;
    model_local_var->product_image = product_image;
    model_local_var->has_frame_variant = has_frame_variant;
    model_local_var->show_options = show_options;
    model_local_var->string_udid = string_udid;
    model_local_var->charm_boot_args = charm_boot_args;
    model_local_var->requires_preset_boot_options = requires_preset_boot_options;
    model_local_var->supports_preset_boot_options = supports_preset_boot_options;
    model_local_var->supports_custom_firmware = supports_custom_firmware;
    model_local_var->supports_custom_firmware_image = supports_custom_firmware_image;
    model_local_var->supports_custom_kernel = supports_custom_kernel;
    model_local_var->supports_custom_devicetree = supports_custom_devicetree;
    model_local_var->supports_custom_mmio = supports_custom_mmio;
    model_local_var->supports_fvp = supports_fvp;
    model_local_var->mast = mast;

    model_local_var->_library_owned = 1;
    return model_local_var;
}

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
    ) {
    return model_create_internal (
        type,
        flavor,
        description,
        model,
        hardware_model,
        board_config,
        platform,
        cpid,
        bdid,
        vendor,
        hidden,
        is_beta,
        peripherals,
        has_software,
        supports_rapid_start,
        default_firmware,
        cores,
        cores_min,
        cores_max,
        cores_step,
        cores_allowed,
        ram,
        ram_min,
        ram_max,
        dynamic_hardware_changes,
        partitions,
        frame,
        product_image,
        has_frame_variant,
        show_options,
        string_udid,
        charm_boot_args,
        requires_preset_boot_options,
        supports_preset_boot_options,
        supports_custom_firmware,
        supports_custom_firmware_image,
        supports_custom_kernel,
        supports_custom_devicetree,
        supports_custom_mmio,
        supports_fvp,
        mast
        );
}

void model_free(model_t *model) {
    if(NULL == model){
        return ;
    }
    if(model->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "model_free");
        return ;
    }
    listEntry_t *listEntry;
    if (model->type) {
        free(model->type);
        model->type = NULL;
    }
    if (model->flavor) {
        free(model->flavor);
        model->flavor = NULL;
    }
    if (model->description) {
        free(model->description);
        model->description = NULL;
    }
    if (model->model) {
        free(model->model);
        model->model = NULL;
    }
    if (model->hardware_model) {
        free(model->hardware_model);
        model->hardware_model = NULL;
    }
    if (model->board_config) {
        free(model->board_config);
        model->board_config = NULL;
    }
    if (model->platform) {
        free(model->platform);
        model->platform = NULL;
    }
    if (model->vendor) {
        free(model->vendor);
        model->vendor = NULL;
    }
    if (model->default_firmware) {
        free(model->default_firmware);
        model->default_firmware = NULL;
    }
    if (model->cores_allowed) {
        list_ForEach(listEntry, model->cores_allowed) {
            free(listEntry->data);
        }
        list_freeList(model->cores_allowed);
        model->cores_allowed = NULL;
    }
    if (model->partitions) {
        list_ForEach(listEntry, model->partitions) {
            model_partition_free(listEntry->data);
        }
        list_freeList(model->partitions);
        model->partitions = NULL;
    }
    if (model->frame) {
        model_frame_free(model->frame);
        model->frame = NULL;
    }
    if (model->product_image) {
        model_product_image_free(model->product_image);
        model->product_image = NULL;
    }
    if (model->show_options) {
        list_ForEach(listEntry, model->show_options) {
            free(listEntry->data);
        }
        list_freeList(model->show_options);
        model->show_options = NULL;
    }
    if (model->charm_boot_args) {
        list_ForEach(listEntry, model->charm_boot_args) {
            object_free(listEntry->data);
        }
        list_freeList(model->charm_boot_args);
        model->charm_boot_args = NULL;
    }
    free(model);
}

cJSON *model_convertToJSON(model_t *model) {
    cJSON *item = cJSON_CreateObject();

    // model->type
    if (!model->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", model->type) == NULL) {
    goto fail; //String
    }


    // model->flavor
    if (!model->flavor) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "flavor", model->flavor) == NULL) {
    goto fail; //String
    }


    // model->description
    if(model->description) {
    if(cJSON_AddStringToObject(item, "description", model->description) == NULL) {
    goto fail; //String
    }
    }


    // model->model
    if (!model->model) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "model", model->model) == NULL) {
    goto fail; //String
    }


    // model->hardware_model
    if(model->hardware_model) {
    if(cJSON_AddStringToObject(item, "hardwareModel", model->hardware_model) == NULL) {
    goto fail; //String
    }
    }


    // model->board_config
    if(model->board_config) {
    if(cJSON_AddStringToObject(item, "boardConfig", model->board_config) == NULL) {
    goto fail; //String
    }
    }


    // model->platform
    if(model->platform) {
    if(cJSON_AddStringToObject(item, "platform", model->platform) == NULL) {
    goto fail; //String
    }
    }


    // model->cpid
    if(model->cpid) {
    if(cJSON_AddNumberToObject(item, "cpid", model->cpid) == NULL) {
    goto fail; //Numeric
    }
    }


    // model->bdid
    if(model->bdid) {
    if(cJSON_AddNumberToObject(item, "bdid", model->bdid) == NULL) {
    goto fail; //Numeric
    }
    }


    // model->vendor
    if(model->vendor) {
    if(cJSON_AddStringToObject(item, "vendor", model->vendor) == NULL) {
    goto fail; //String
    }
    }


    // model->hidden
    if (!model->hidden) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "hidden", model->hidden) == NULL) {
    goto fail; //Bool
    }


    // model->is_beta
    if (!model->is_beta) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "isBeta", model->is_beta) == NULL) {
    goto fail; //Bool
    }


    // model->peripherals
    if (!model->peripherals) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "peripherals", model->peripherals) == NULL) {
    goto fail; //Bool
    }


    // model->has_software
    if (!model->has_software) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "hasSoftware", model->has_software) == NULL) {
    goto fail; //Bool
    }


    // model->supports_rapid_start
    if (!model->supports_rapid_start) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "supportsRapidStart", model->supports_rapid_start) == NULL) {
    goto fail; //Bool
    }


    // model->default_firmware
    if(model->default_firmware) {
    if(cJSON_AddStringToObject(item, "defaultFirmware", model->default_firmware) == NULL) {
    goto fail; //String
    }
    }


    // model->cores
    if (!model->cores) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "cores", model->cores) == NULL) {
    goto fail; //Numeric
    }


    // model->cores_min
    if (!model->cores_min) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "coresMin", model->cores_min) == NULL) {
    goto fail; //Numeric
    }


    // model->cores_max
    if (!model->cores_max) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "coresMax", model->cores_max) == NULL) {
    goto fail; //Numeric
    }


    // model->cores_step
    if(model->cores_step) {
    if(cJSON_AddNumberToObject(item, "coresStep", model->cores_step) == NULL) {
    goto fail; //Numeric
    }
    }


    // model->cores_allowed
    if(model->cores_allowed) {
    cJSON *cores_allowed = cJSON_AddArrayToObject(item, "coresAllowed");
    if(cores_allowed == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *cores_allowedListEntry;
    list_ForEach(cores_allowedListEntry, model->cores_allowed) {
    if(cJSON_AddNumberToObject(cores_allowed, "", *(double *)cores_allowedListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // model->ram
    if (!model->ram) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "ram", model->ram) == NULL) {
    goto fail; //Numeric
    }


    // model->ram_min
    if (!model->ram_min) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "ramMin", model->ram_min) == NULL) {
    goto fail; //Numeric
    }


    // model->ram_max
    if (!model->ram_max) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "ramMax", model->ram_max) == NULL) {
    goto fail; //Numeric
    }


    // model->dynamic_hardware_changes
    if (!model->dynamic_hardware_changes) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "dynamicHardwareChanges", model->dynamic_hardware_changes) == NULL) {
    goto fail; //Bool
    }


    // model->partitions
    if (!model->partitions) {
        goto fail;
    }
    cJSON *partitions = cJSON_AddArrayToObject(item, "partitions");
    if(partitions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *partitionsListEntry;
    if (model->partitions) {
    list_ForEach(partitionsListEntry, model->partitions) {
    cJSON *itemLocal = model_partition_convertToJSON(partitionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(partitions, itemLocal);
    }
    }


    // model->frame
    if (!model->frame) {
        goto fail;
    }
    cJSON *frame_local_JSON = model_frame_convertToJSON(model->frame);
    if(frame_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "frame", frame_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // model->product_image
    if (!model->product_image) {
        goto fail;
    }
    cJSON *product_image_local_JSON = model_product_image_convertToJSON(model->product_image);
    if(product_image_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "productImage", product_image_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // model->has_frame_variant
    if (!model->has_frame_variant) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "hasFrameVariant", model->has_frame_variant) == NULL) {
    goto fail; //Bool
    }


    // model->show_options
    if (!model->show_options) {
        goto fail;
    }
    cJSON *show_options = cJSON_AddArrayToObject(item, "showOptions");
    if(show_options == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *show_optionsListEntry;
    list_ForEach(show_optionsListEntry, model->show_options) {
    if(cJSON_AddStringToObject(show_options, "", show_optionsListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // model->string_udid
    if (!model->string_udid) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "stringUdid", model->string_udid) == NULL) {
    goto fail; //Bool
    }


    // model->charm_boot_args
    if(model->charm_boot_args) {
    cJSON *charm_boot_args = cJSON_AddArrayToObject(item, "charmBootArgs");
    if(charm_boot_args == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *charm_boot_argsListEntry;
    if (model->charm_boot_args) {
    list_ForEach(charm_boot_argsListEntry, model->charm_boot_args) {
    cJSON *itemLocal = object_convertToJSON(charm_boot_argsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(charm_boot_args, itemLocal);
    }
    }
    }


    // model->requires_preset_boot_options
    if (!model->requires_preset_boot_options) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "requiresPresetBootOptions", model->requires_preset_boot_options) == NULL) {
    goto fail; //Bool
    }


    // model->supports_preset_boot_options
    if (!model->supports_preset_boot_options) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "supportsPresetBootOptions", model->supports_preset_boot_options) == NULL) {
    goto fail; //Bool
    }


    // model->supports_custom_firmware
    if (!model->supports_custom_firmware) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "supportsCustomFirmware", model->supports_custom_firmware) == NULL) {
    goto fail; //Bool
    }


    // model->supports_custom_firmware_image
    if (!model->supports_custom_firmware_image) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "supportsCustomFirmwareImage", model->supports_custom_firmware_image) == NULL) {
    goto fail; //Bool
    }


    // model->supports_custom_kernel
    if (!model->supports_custom_kernel) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "supportsCustomKernel", model->supports_custom_kernel) == NULL) {
    goto fail; //Bool
    }


    // model->supports_custom_devicetree
    if (!model->supports_custom_devicetree) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "supportsCustomDevicetree", model->supports_custom_devicetree) == NULL) {
    goto fail; //Bool
    }


    // model->supports_custom_mmio
    if (!model->supports_custom_mmio) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "supportsCustomMmio", model->supports_custom_mmio) == NULL) {
    goto fail; //Bool
    }


    // model->supports_fvp
    if (!model->supports_fvp) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "supportsFvp", model->supports_fvp) == NULL) {
    goto fail; //Bool
    }


    // model->mast
    if (!model->mast) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "mast", model->mast) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

model_t *model_parseFromJSON(cJSON *modelJSON){

    model_t *model_local_var = NULL;

    // define the local list for model->cores_allowed
    list_t *cores_allowedList = NULL;

    // define the local list for model->partitions
    list_t *partitionsList = NULL;

    // define the local variable for model->frame
    model_frame_t *frame_local_nonprim = NULL;

    // define the local variable for model->product_image
    model_product_image_t *product_image_local_nonprim = NULL;

    // define the local list for model->show_options
    list_t *show_optionsList = NULL;

    // define the local list for model->charm_boot_args
    list_t *charm_boot_argsList = NULL;

    // model->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(modelJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }

    // model->flavor
    cJSON *flavor = cJSON_GetObjectItemCaseSensitive(modelJSON, "flavor");
    if (cJSON_IsNull(flavor)) {
        flavor = NULL;
    }
    if (!flavor) {
        goto end;
    }

    
    if(!cJSON_IsString(flavor))
    {
    goto end; //String
    }

    // model->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(modelJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // model->model
    cJSON *model = cJSON_GetObjectItemCaseSensitive(modelJSON, "model");
    if (cJSON_IsNull(model)) {
        model = NULL;
    }
    if (!model) {
        goto end;
    }

    
    if(!cJSON_IsString(model))
    {
    goto end; //String
    }

    // model->hardware_model
    cJSON *hardware_model = cJSON_GetObjectItemCaseSensitive(modelJSON, "hardwareModel");
    if (cJSON_IsNull(hardware_model)) {
        hardware_model = NULL;
    }
    if (hardware_model) { 
    if(!cJSON_IsString(hardware_model) && !cJSON_IsNull(hardware_model))
    {
    goto end; //String
    }
    }

    // model->board_config
    cJSON *board_config = cJSON_GetObjectItemCaseSensitive(modelJSON, "boardConfig");
    if (cJSON_IsNull(board_config)) {
        board_config = NULL;
    }
    if (board_config) { 
    if(!cJSON_IsString(board_config) && !cJSON_IsNull(board_config))
    {
    goto end; //String
    }
    }

    // model->platform
    cJSON *platform = cJSON_GetObjectItemCaseSensitive(modelJSON, "platform");
    if (cJSON_IsNull(platform)) {
        platform = NULL;
    }
    if (platform) { 
    if(!cJSON_IsString(platform) && !cJSON_IsNull(platform))
    {
    goto end; //String
    }
    }

    // model->cpid
    cJSON *cpid = cJSON_GetObjectItemCaseSensitive(modelJSON, "cpid");
    if (cJSON_IsNull(cpid)) {
        cpid = NULL;
    }
    if (cpid) { 
    if(!cJSON_IsNumber(cpid))
    {
    goto end; //Numeric
    }
    }

    // model->bdid
    cJSON *bdid = cJSON_GetObjectItemCaseSensitive(modelJSON, "bdid");
    if (cJSON_IsNull(bdid)) {
        bdid = NULL;
    }
    if (bdid) { 
    if(!cJSON_IsNumber(bdid))
    {
    goto end; //Numeric
    }
    }

    // model->vendor
    cJSON *vendor = cJSON_GetObjectItemCaseSensitive(modelJSON, "vendor");
    if (cJSON_IsNull(vendor)) {
        vendor = NULL;
    }
    if (vendor) { 
    if(!cJSON_IsString(vendor) && !cJSON_IsNull(vendor))
    {
    goto end; //String
    }
    }

    // model->hidden
    cJSON *hidden = cJSON_GetObjectItemCaseSensitive(modelJSON, "hidden");
    if (cJSON_IsNull(hidden)) {
        hidden = NULL;
    }
    if (!hidden) {
        goto end;
    }

    
    if(!cJSON_IsBool(hidden))
    {
    goto end; //Bool
    }

    // model->is_beta
    cJSON *is_beta = cJSON_GetObjectItemCaseSensitive(modelJSON, "isBeta");
    if (cJSON_IsNull(is_beta)) {
        is_beta = NULL;
    }
    if (!is_beta) {
        goto end;
    }

    
    if(!cJSON_IsBool(is_beta))
    {
    goto end; //Bool
    }

    // model->peripherals
    cJSON *peripherals = cJSON_GetObjectItemCaseSensitive(modelJSON, "peripherals");
    if (cJSON_IsNull(peripherals)) {
        peripherals = NULL;
    }
    if (!peripherals) {
        goto end;
    }

    
    if(!cJSON_IsBool(peripherals))
    {
    goto end; //Bool
    }

    // model->has_software
    cJSON *has_software = cJSON_GetObjectItemCaseSensitive(modelJSON, "hasSoftware");
    if (cJSON_IsNull(has_software)) {
        has_software = NULL;
    }
    if (!has_software) {
        goto end;
    }

    
    if(!cJSON_IsBool(has_software))
    {
    goto end; //Bool
    }

    // model->supports_rapid_start
    cJSON *supports_rapid_start = cJSON_GetObjectItemCaseSensitive(modelJSON, "supportsRapidStart");
    if (cJSON_IsNull(supports_rapid_start)) {
        supports_rapid_start = NULL;
    }
    if (!supports_rapid_start) {
        goto end;
    }

    
    if(!cJSON_IsBool(supports_rapid_start))
    {
    goto end; //Bool
    }

    // model->default_firmware
    cJSON *default_firmware = cJSON_GetObjectItemCaseSensitive(modelJSON, "defaultFirmware");
    if (cJSON_IsNull(default_firmware)) {
        default_firmware = NULL;
    }
    if (default_firmware) { 
    if(!cJSON_IsString(default_firmware) && !cJSON_IsNull(default_firmware))
    {
    goto end; //String
    }
    }

    // model->cores
    cJSON *cores = cJSON_GetObjectItemCaseSensitive(modelJSON, "cores");
    if (cJSON_IsNull(cores)) {
        cores = NULL;
    }
    if (!cores) {
        goto end;
    }

    
    if(!cJSON_IsNumber(cores))
    {
    goto end; //Numeric
    }

    // model->cores_min
    cJSON *cores_min = cJSON_GetObjectItemCaseSensitive(modelJSON, "coresMin");
    if (cJSON_IsNull(cores_min)) {
        cores_min = NULL;
    }
    if (!cores_min) {
        goto end;
    }

    
    if(!cJSON_IsNumber(cores_min))
    {
    goto end; //Numeric
    }

    // model->cores_max
    cJSON *cores_max = cJSON_GetObjectItemCaseSensitive(modelJSON, "coresMax");
    if (cJSON_IsNull(cores_max)) {
        cores_max = NULL;
    }
    if (!cores_max) {
        goto end;
    }

    
    if(!cJSON_IsNumber(cores_max))
    {
    goto end; //Numeric
    }

    // model->cores_step
    cJSON *cores_step = cJSON_GetObjectItemCaseSensitive(modelJSON, "coresStep");
    if (cJSON_IsNull(cores_step)) {
        cores_step = NULL;
    }
    if (cores_step) { 
    if(!cJSON_IsNumber(cores_step))
    {
    goto end; //Numeric
    }
    }

    // model->cores_allowed
    cJSON *cores_allowed = cJSON_GetObjectItemCaseSensitive(modelJSON, "coresAllowed");
    if (cJSON_IsNull(cores_allowed)) {
        cores_allowed = NULL;
    }
    if (cores_allowed) { 
    cJSON *cores_allowed_local = NULL;
    if(!cJSON_IsArray(cores_allowed)) {
        goto end;//primitive container
    }
    cores_allowedList = list_createList();

    cJSON_ArrayForEach(cores_allowed_local, cores_allowed)
    {
        if(!cJSON_IsNumber(cores_allowed_local))
        {
            goto end;
        }
        double *cores_allowed_local_value = calloc(1, sizeof(double));
        if(!cores_allowed_local_value)
        {
            goto end;
        }
        *cores_allowed_local_value = cores_allowed_local->valuedouble;
        list_addElement(cores_allowedList , cores_allowed_local_value);
    }
    }

    // model->ram
    cJSON *ram = cJSON_GetObjectItemCaseSensitive(modelJSON, "ram");
    if (cJSON_IsNull(ram)) {
        ram = NULL;
    }
    if (!ram) {
        goto end;
    }

    
    if(!cJSON_IsNumber(ram))
    {
    goto end; //Numeric
    }

    // model->ram_min
    cJSON *ram_min = cJSON_GetObjectItemCaseSensitive(modelJSON, "ramMin");
    if (cJSON_IsNull(ram_min)) {
        ram_min = NULL;
    }
    if (!ram_min) {
        goto end;
    }

    
    if(!cJSON_IsNumber(ram_min))
    {
    goto end; //Numeric
    }

    // model->ram_max
    cJSON *ram_max = cJSON_GetObjectItemCaseSensitive(modelJSON, "ramMax");
    if (cJSON_IsNull(ram_max)) {
        ram_max = NULL;
    }
    if (!ram_max) {
        goto end;
    }

    
    if(!cJSON_IsNumber(ram_max))
    {
    goto end; //Numeric
    }

    // model->dynamic_hardware_changes
    cJSON *dynamic_hardware_changes = cJSON_GetObjectItemCaseSensitive(modelJSON, "dynamicHardwareChanges");
    if (cJSON_IsNull(dynamic_hardware_changes)) {
        dynamic_hardware_changes = NULL;
    }
    if (!dynamic_hardware_changes) {
        goto end;
    }

    
    if(!cJSON_IsBool(dynamic_hardware_changes))
    {
    goto end; //Bool
    }

    // model->partitions
    cJSON *partitions = cJSON_GetObjectItemCaseSensitive(modelJSON, "partitions");
    if (cJSON_IsNull(partitions)) {
        partitions = NULL;
    }
    if (!partitions) {
        goto end;
    }

    
    cJSON *partitions_local_nonprimitive = NULL;
    if(!cJSON_IsArray(partitions)){
        goto end; //nonprimitive container
    }

    partitionsList = list_createList();

    cJSON_ArrayForEach(partitions_local_nonprimitive,partitions )
    {
        if(!cJSON_IsObject(partitions_local_nonprimitive)){
            goto end;
        }
        model_partition_t *partitionsItem = model_partition_parseFromJSON(partitions_local_nonprimitive);

        list_addElement(partitionsList, partitionsItem);
    }

    // model->frame
    cJSON *frame = cJSON_GetObjectItemCaseSensitive(modelJSON, "frame");
    if (cJSON_IsNull(frame)) {
        frame = NULL;
    }
    if (!frame) {
        goto end;
    }

    
    frame_local_nonprim = model_frame_parseFromJSON(frame); //nonprimitive

    // model->product_image
    cJSON *product_image = cJSON_GetObjectItemCaseSensitive(modelJSON, "productImage");
    if (cJSON_IsNull(product_image)) {
        product_image = NULL;
    }
    if (!product_image) {
        goto end;
    }

    
    product_image_local_nonprim = model_product_image_parseFromJSON(product_image); //nonprimitive

    // model->has_frame_variant
    cJSON *has_frame_variant = cJSON_GetObjectItemCaseSensitive(modelJSON, "hasFrameVariant");
    if (cJSON_IsNull(has_frame_variant)) {
        has_frame_variant = NULL;
    }
    if (!has_frame_variant) {
        goto end;
    }

    
    if(!cJSON_IsBool(has_frame_variant))
    {
    goto end; //Bool
    }

    // model->show_options
    cJSON *show_options = cJSON_GetObjectItemCaseSensitive(modelJSON, "showOptions");
    if (cJSON_IsNull(show_options)) {
        show_options = NULL;
    }
    if (!show_options) {
        goto end;
    }

    
    cJSON *show_options_local = NULL;
    if(!cJSON_IsArray(show_options)) {
        goto end;//primitive container
    }
    show_optionsList = list_createList();

    cJSON_ArrayForEach(show_options_local, show_options)
    {
        if(!cJSON_IsString(show_options_local))
        {
            goto end;
        }
        list_addElement(show_optionsList , strdup(show_options_local->valuestring));
    }

    // model->string_udid
    cJSON *string_udid = cJSON_GetObjectItemCaseSensitive(modelJSON, "stringUdid");
    if (cJSON_IsNull(string_udid)) {
        string_udid = NULL;
    }
    if (!string_udid) {
        goto end;
    }

    
    if(!cJSON_IsBool(string_udid))
    {
    goto end; //Bool
    }

    // model->charm_boot_args
    cJSON *charm_boot_args = cJSON_GetObjectItemCaseSensitive(modelJSON, "charmBootArgs");
    if (cJSON_IsNull(charm_boot_args)) {
        charm_boot_args = NULL;
    }
    if (charm_boot_args) { 
    cJSON *charm_boot_args_local_nonprimitive = NULL;
    if(!cJSON_IsArray(charm_boot_args)){
        goto end; //nonprimitive container
    }

    charm_boot_argsList = list_createList();

    cJSON_ArrayForEach(charm_boot_args_local_nonprimitive,charm_boot_args )
    {
        if(!cJSON_IsObject(charm_boot_args_local_nonprimitive)){
            goto end;
        }
        object_t *charm_boot_argsItem = object_parseFromJSON(charm_boot_args_local_nonprimitive);

        list_addElement(charm_boot_argsList, charm_boot_argsItem);
    }
    }

    // model->requires_preset_boot_options
    cJSON *requires_preset_boot_options = cJSON_GetObjectItemCaseSensitive(modelJSON, "requiresPresetBootOptions");
    if (cJSON_IsNull(requires_preset_boot_options)) {
        requires_preset_boot_options = NULL;
    }
    if (!requires_preset_boot_options) {
        goto end;
    }

    
    if(!cJSON_IsBool(requires_preset_boot_options))
    {
    goto end; //Bool
    }

    // model->supports_preset_boot_options
    cJSON *supports_preset_boot_options = cJSON_GetObjectItemCaseSensitive(modelJSON, "supportsPresetBootOptions");
    if (cJSON_IsNull(supports_preset_boot_options)) {
        supports_preset_boot_options = NULL;
    }
    if (!supports_preset_boot_options) {
        goto end;
    }

    
    if(!cJSON_IsBool(supports_preset_boot_options))
    {
    goto end; //Bool
    }

    // model->supports_custom_firmware
    cJSON *supports_custom_firmware = cJSON_GetObjectItemCaseSensitive(modelJSON, "supportsCustomFirmware");
    if (cJSON_IsNull(supports_custom_firmware)) {
        supports_custom_firmware = NULL;
    }
    if (!supports_custom_firmware) {
        goto end;
    }

    
    if(!cJSON_IsBool(supports_custom_firmware))
    {
    goto end; //Bool
    }

    // model->supports_custom_firmware_image
    cJSON *supports_custom_firmware_image = cJSON_GetObjectItemCaseSensitive(modelJSON, "supportsCustomFirmwareImage");
    if (cJSON_IsNull(supports_custom_firmware_image)) {
        supports_custom_firmware_image = NULL;
    }
    if (!supports_custom_firmware_image) {
        goto end;
    }

    
    if(!cJSON_IsBool(supports_custom_firmware_image))
    {
    goto end; //Bool
    }

    // model->supports_custom_kernel
    cJSON *supports_custom_kernel = cJSON_GetObjectItemCaseSensitive(modelJSON, "supportsCustomKernel");
    if (cJSON_IsNull(supports_custom_kernel)) {
        supports_custom_kernel = NULL;
    }
    if (!supports_custom_kernel) {
        goto end;
    }

    
    if(!cJSON_IsBool(supports_custom_kernel))
    {
    goto end; //Bool
    }

    // model->supports_custom_devicetree
    cJSON *supports_custom_devicetree = cJSON_GetObjectItemCaseSensitive(modelJSON, "supportsCustomDevicetree");
    if (cJSON_IsNull(supports_custom_devicetree)) {
        supports_custom_devicetree = NULL;
    }
    if (!supports_custom_devicetree) {
        goto end;
    }

    
    if(!cJSON_IsBool(supports_custom_devicetree))
    {
    goto end; //Bool
    }

    // model->supports_custom_mmio
    cJSON *supports_custom_mmio = cJSON_GetObjectItemCaseSensitive(modelJSON, "supportsCustomMmio");
    if (cJSON_IsNull(supports_custom_mmio)) {
        supports_custom_mmio = NULL;
    }
    if (!supports_custom_mmio) {
        goto end;
    }

    
    if(!cJSON_IsBool(supports_custom_mmio))
    {
    goto end; //Bool
    }

    // model->supports_fvp
    cJSON *supports_fvp = cJSON_GetObjectItemCaseSensitive(modelJSON, "supportsFvp");
    if (cJSON_IsNull(supports_fvp)) {
        supports_fvp = NULL;
    }
    if (!supports_fvp) {
        goto end;
    }

    
    if(!cJSON_IsBool(supports_fvp))
    {
    goto end; //Bool
    }

    // model->mast
    cJSON *mast = cJSON_GetObjectItemCaseSensitive(modelJSON, "mast");
    if (cJSON_IsNull(mast)) {
        mast = NULL;
    }
    if (!mast) {
        goto end;
    }

    
    if(!cJSON_IsBool(mast))
    {
    goto end; //Bool
    }


    model_local_var = model_create_internal (
        strdup(type->valuestring),
        strdup(flavor->valuestring),
        description && !cJSON_IsNull(description) ? strdup(description->valuestring) : NULL,
        strdup(model->valuestring),
        hardware_model && !cJSON_IsNull(hardware_model) ? strdup(hardware_model->valuestring) : NULL,
        board_config && !cJSON_IsNull(board_config) ? strdup(board_config->valuestring) : NULL,
        platform && !cJSON_IsNull(platform) ? strdup(platform->valuestring) : NULL,
        cpid ? cpid->valuedouble : 0,
        bdid ? bdid->valuedouble : 0,
        vendor && !cJSON_IsNull(vendor) ? strdup(vendor->valuestring) : NULL,
        hidden->valueint,
        is_beta->valueint,
        peripherals->valueint,
        has_software->valueint,
        supports_rapid_start->valueint,
        default_firmware && !cJSON_IsNull(default_firmware) ? strdup(default_firmware->valuestring) : NULL,
        cores->valuedouble,
        cores_min->valuedouble,
        cores_max->valuedouble,
        cores_step ? cores_step->valuedouble : 0,
        cores_allowed ? cores_allowedList : NULL,
        ram->valuedouble,
        ram_min->valuedouble,
        ram_max->valuedouble,
        dynamic_hardware_changes->valueint,
        partitionsList,
        frame_local_nonprim,
        product_image_local_nonprim,
        has_frame_variant->valueint,
        show_optionsList,
        string_udid->valueint,
        charm_boot_args ? charm_boot_argsList : NULL,
        requires_preset_boot_options->valueint,
        supports_preset_boot_options->valueint,
        supports_custom_firmware->valueint,
        supports_custom_firmware_image->valueint,
        supports_custom_kernel->valueint,
        supports_custom_devicetree->valueint,
        supports_custom_mmio->valueint,
        supports_fvp->valueint,
        mast->valueint
        );

    return model_local_var;
end:
    if (cores_allowedList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, cores_allowedList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(cores_allowedList);
        cores_allowedList = NULL;
    }
    if (partitionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, partitionsList) {
            model_partition_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(partitionsList);
        partitionsList = NULL;
    }
    if (frame_local_nonprim) {
        model_frame_free(frame_local_nonprim);
        frame_local_nonprim = NULL;
    }
    if (product_image_local_nonprim) {
        model_product_image_free(product_image_local_nonprim);
        product_image_local_nonprim = NULL;
    }
    if (show_optionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, show_optionsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(show_optionsList);
        show_optionsList = NULL;
    }
    if (charm_boot_argsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, charm_boot_argsList) {
            object_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(charm_boot_argsList);
        charm_boot_argsList = NULL;
    }
    return NULL;

}
