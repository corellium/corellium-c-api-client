#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "extension_flavor.h"



static extension_flavor_t *extension_flavor_create_internal(
    char *type,
    char *flavor,
    char *flavor_id,
    char *product,
    double cores,
    double ram,
    int supports_gdb,
    int supports_serial_console,
    int supports_preset_boot_options
    ) {
    extension_flavor_t *extension_flavor_local_var = malloc(sizeof(extension_flavor_t));
    if (!extension_flavor_local_var) {
        return NULL;
    }
    extension_flavor_local_var->type = type;
    extension_flavor_local_var->flavor = flavor;
    extension_flavor_local_var->flavor_id = flavor_id;
    extension_flavor_local_var->product = product;
    extension_flavor_local_var->cores = cores;
    extension_flavor_local_var->ram = ram;
    extension_flavor_local_var->supports_gdb = supports_gdb;
    extension_flavor_local_var->supports_serial_console = supports_serial_console;
    extension_flavor_local_var->supports_preset_boot_options = supports_preset_boot_options;

    extension_flavor_local_var->_library_owned = 1;
    return extension_flavor_local_var;
}

__attribute__((deprecated)) extension_flavor_t *extension_flavor_create(
    char *type,
    char *flavor,
    char *flavor_id,
    char *product,
    double cores,
    double ram,
    int supports_gdb,
    int supports_serial_console,
    int supports_preset_boot_options
    ) {
    return extension_flavor_create_internal (
        type,
        flavor,
        flavor_id,
        product,
        cores,
        ram,
        supports_gdb,
        supports_serial_console,
        supports_preset_boot_options
        );
}

void extension_flavor_free(extension_flavor_t *extension_flavor) {
    if(NULL == extension_flavor){
        return ;
    }
    if(extension_flavor->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "extension_flavor_free");
        return ;
    }
    listEntry_t *listEntry;
    if (extension_flavor->type) {
        free(extension_flavor->type);
        extension_flavor->type = NULL;
    }
    if (extension_flavor->flavor) {
        free(extension_flavor->flavor);
        extension_flavor->flavor = NULL;
    }
    if (extension_flavor->flavor_id) {
        free(extension_flavor->flavor_id);
        extension_flavor->flavor_id = NULL;
    }
    if (extension_flavor->product) {
        free(extension_flavor->product);
        extension_flavor->product = NULL;
    }
    free(extension_flavor);
}

cJSON *extension_flavor_convertToJSON(extension_flavor_t *extension_flavor) {
    cJSON *item = cJSON_CreateObject();

    // extension_flavor->type
    if(extension_flavor->type) {
    if(cJSON_AddStringToObject(item, "type", extension_flavor->type) == NULL) {
    goto fail; //String
    }
    }


    // extension_flavor->flavor
    if(extension_flavor->flavor) {
    if(cJSON_AddStringToObject(item, "flavor", extension_flavor->flavor) == NULL) {
    goto fail; //String
    }
    }


    // extension_flavor->flavor_id
    if(extension_flavor->flavor_id) {
    if(cJSON_AddStringToObject(item, "flavorId", extension_flavor->flavor_id) == NULL) {
    goto fail; //String
    }
    }


    // extension_flavor->product
    if(extension_flavor->product) {
    if(cJSON_AddStringToObject(item, "product", extension_flavor->product) == NULL) {
    goto fail; //String
    }
    }


    // extension_flavor->cores
    if(extension_flavor->cores) {
    if(cJSON_AddNumberToObject(item, "cores", extension_flavor->cores) == NULL) {
    goto fail; //Numeric
    }
    }


    // extension_flavor->ram
    if(extension_flavor->ram) {
    if(cJSON_AddNumberToObject(item, "ram", extension_flavor->ram) == NULL) {
    goto fail; //Numeric
    }
    }


    // extension_flavor->supports_gdb
    if(extension_flavor->supports_gdb) {
    if(cJSON_AddBoolToObject(item, "supportsGdb", extension_flavor->supports_gdb) == NULL) {
    goto fail; //Bool
    }
    }


    // extension_flavor->supports_serial_console
    if(extension_flavor->supports_serial_console) {
    if(cJSON_AddBoolToObject(item, "supportsSerialConsole", extension_flavor->supports_serial_console) == NULL) {
    goto fail; //Bool
    }
    }


    // extension_flavor->supports_preset_boot_options
    if(extension_flavor->supports_preset_boot_options) {
    if(cJSON_AddBoolToObject(item, "supportsPresetBootOptions", extension_flavor->supports_preset_boot_options) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

extension_flavor_t *extension_flavor_parseFromJSON(cJSON *extension_flavorJSON){

    extension_flavor_t *extension_flavor_local_var = NULL;

    // extension_flavor->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(extension_flavorJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (type) { 
    if(!cJSON_IsString(type) && !cJSON_IsNull(type))
    {
    goto end; //String
    }
    }

    // extension_flavor->flavor
    cJSON *flavor = cJSON_GetObjectItemCaseSensitive(extension_flavorJSON, "flavor");
    if (cJSON_IsNull(flavor)) {
        flavor = NULL;
    }
    if (flavor) { 
    if(!cJSON_IsString(flavor) && !cJSON_IsNull(flavor))
    {
    goto end; //String
    }
    }

    // extension_flavor->flavor_id
    cJSON *flavor_id = cJSON_GetObjectItemCaseSensitive(extension_flavorJSON, "flavorId");
    if (cJSON_IsNull(flavor_id)) {
        flavor_id = NULL;
    }
    if (flavor_id) { 
    if(!cJSON_IsString(flavor_id) && !cJSON_IsNull(flavor_id))
    {
    goto end; //String
    }
    }

    // extension_flavor->product
    cJSON *product = cJSON_GetObjectItemCaseSensitive(extension_flavorJSON, "product");
    if (cJSON_IsNull(product)) {
        product = NULL;
    }
    if (product) { 
    if(!cJSON_IsString(product) && !cJSON_IsNull(product))
    {
    goto end; //String
    }
    }

    // extension_flavor->cores
    cJSON *cores = cJSON_GetObjectItemCaseSensitive(extension_flavorJSON, "cores");
    if (cJSON_IsNull(cores)) {
        cores = NULL;
    }
    if (cores) { 
    if(!cJSON_IsNumber(cores))
    {
    goto end; //Numeric
    }
    }

    // extension_flavor->ram
    cJSON *ram = cJSON_GetObjectItemCaseSensitive(extension_flavorJSON, "ram");
    if (cJSON_IsNull(ram)) {
        ram = NULL;
    }
    if (ram) { 
    if(!cJSON_IsNumber(ram))
    {
    goto end; //Numeric
    }
    }

    // extension_flavor->supports_gdb
    cJSON *supports_gdb = cJSON_GetObjectItemCaseSensitive(extension_flavorJSON, "supportsGdb");
    if (cJSON_IsNull(supports_gdb)) {
        supports_gdb = NULL;
    }
    if (supports_gdb) { 
    if(!cJSON_IsBool(supports_gdb))
    {
    goto end; //Bool
    }
    }

    // extension_flavor->supports_serial_console
    cJSON *supports_serial_console = cJSON_GetObjectItemCaseSensitive(extension_flavorJSON, "supportsSerialConsole");
    if (cJSON_IsNull(supports_serial_console)) {
        supports_serial_console = NULL;
    }
    if (supports_serial_console) { 
    if(!cJSON_IsBool(supports_serial_console))
    {
    goto end; //Bool
    }
    }

    // extension_flavor->supports_preset_boot_options
    cJSON *supports_preset_boot_options = cJSON_GetObjectItemCaseSensitive(extension_flavorJSON, "supportsPresetBootOptions");
    if (cJSON_IsNull(supports_preset_boot_options)) {
        supports_preset_boot_options = NULL;
    }
    if (supports_preset_boot_options) { 
    if(!cJSON_IsBool(supports_preset_boot_options))
    {
    goto end; //Bool
    }
    }


    extension_flavor_local_var = extension_flavor_create_internal (
        type && !cJSON_IsNull(type) ? strdup(type->valuestring) : NULL,
        flavor && !cJSON_IsNull(flavor) ? strdup(flavor->valuestring) : NULL,
        flavor_id && !cJSON_IsNull(flavor_id) ? strdup(flavor_id->valuestring) : NULL,
        product && !cJSON_IsNull(product) ? strdup(product->valuestring) : NULL,
        cores ? cores->valuedouble : 0,
        ram ? ram->valuedouble : 0,
        supports_gdb ? supports_gdb->valueint : 0,
        supports_serial_console ? supports_serial_console->valueint : 0,
        supports_preset_boot_options ? supports_preset_boot_options->valueint : 0
        );

    return extension_flavor_local_var;
end:
    return NULL;

}
