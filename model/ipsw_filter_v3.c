#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ipsw_filter_v3.h"



static ipsw_filter_v3_t *ipsw_filter_v3_create_internal(
    ipsw_filter_v3_version_t *version,
    ipsw_filter_v3_device_t *device,
    int exclude,
    int include
    ) {
    ipsw_filter_v3_t *ipsw_filter_v3_local_var = malloc(sizeof(ipsw_filter_v3_t));
    if (!ipsw_filter_v3_local_var) {
        return NULL;
    }
    ipsw_filter_v3_local_var->version = version;
    ipsw_filter_v3_local_var->device = device;
    ipsw_filter_v3_local_var->exclude = exclude;
    ipsw_filter_v3_local_var->include = include;

    ipsw_filter_v3_local_var->_library_owned = 1;
    return ipsw_filter_v3_local_var;
}

__attribute__((deprecated)) ipsw_filter_v3_t *ipsw_filter_v3_create(
    ipsw_filter_v3_version_t *version,
    ipsw_filter_v3_device_t *device,
    int exclude,
    int include
    ) {
    return ipsw_filter_v3_create_internal (
        version,
        device,
        exclude,
        include
        );
}

void ipsw_filter_v3_free(ipsw_filter_v3_t *ipsw_filter_v3) {
    if(NULL == ipsw_filter_v3){
        return ;
    }
    if(ipsw_filter_v3->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ipsw_filter_v3_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ipsw_filter_v3->version) {
        ipsw_filter_v3_version_free(ipsw_filter_v3->version);
        ipsw_filter_v3->version = NULL;
    }
    if (ipsw_filter_v3->device) {
        ipsw_filter_v3_device_free(ipsw_filter_v3->device);
        ipsw_filter_v3->device = NULL;
    }
    free(ipsw_filter_v3);
}

cJSON *ipsw_filter_v3_convertToJSON(ipsw_filter_v3_t *ipsw_filter_v3) {
    cJSON *item = cJSON_CreateObject();

    // ipsw_filter_v3->version
    if(ipsw_filter_v3->version) {
    cJSON *version_local_JSON = ipsw_filter_v3_version_convertToJSON(ipsw_filter_v3->version);
    if(version_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "version", version_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // ipsw_filter_v3->device
    if(ipsw_filter_v3->device) {
    cJSON *device_local_JSON = ipsw_filter_v3_device_convertToJSON(ipsw_filter_v3->device);
    if(device_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "device", device_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // ipsw_filter_v3->exclude
    if(ipsw_filter_v3->exclude) {
    if(cJSON_AddBoolToObject(item, "exclude", ipsw_filter_v3->exclude) == NULL) {
    goto fail; //Bool
    }
    }


    // ipsw_filter_v3->include
    if(ipsw_filter_v3->include) {
    if(cJSON_AddBoolToObject(item, "include", ipsw_filter_v3->include) == NULL) {
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

ipsw_filter_v3_t *ipsw_filter_v3_parseFromJSON(cJSON *ipsw_filter_v3JSON){

    ipsw_filter_v3_t *ipsw_filter_v3_local_var = NULL;

    // define the local variable for ipsw_filter_v3->version
    ipsw_filter_v3_version_t *version_local_nonprim = NULL;

    // define the local variable for ipsw_filter_v3->device
    ipsw_filter_v3_device_t *device_local_nonprim = NULL;

    // ipsw_filter_v3->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(ipsw_filter_v3JSON, "version");
    if (cJSON_IsNull(version)) {
        version = NULL;
    }
    if (version) { 
    version_local_nonprim = ipsw_filter_v3_version_parseFromJSON(version); //nonprimitive
    }

    // ipsw_filter_v3->device
    cJSON *device = cJSON_GetObjectItemCaseSensitive(ipsw_filter_v3JSON, "device");
    if (cJSON_IsNull(device)) {
        device = NULL;
    }
    if (device) { 
    device_local_nonprim = ipsw_filter_v3_device_parseFromJSON(device); //nonprimitive
    }

    // ipsw_filter_v3->exclude
    cJSON *exclude = cJSON_GetObjectItemCaseSensitive(ipsw_filter_v3JSON, "exclude");
    if (cJSON_IsNull(exclude)) {
        exclude = NULL;
    }
    if (exclude) { 
    if(!cJSON_IsBool(exclude))
    {
    goto end; //Bool
    }
    }

    // ipsw_filter_v3->include
    cJSON *include = cJSON_GetObjectItemCaseSensitive(ipsw_filter_v3JSON, "include");
    if (cJSON_IsNull(include)) {
        include = NULL;
    }
    if (include) { 
    if(!cJSON_IsBool(include))
    {
    goto end; //Bool
    }
    }


    ipsw_filter_v3_local_var = ipsw_filter_v3_create_internal (
        version ? version_local_nonprim : NULL,
        device ? device_local_nonprim : NULL,
        exclude ? exclude->valueint : 0,
        include ? include->valueint : 0
        );

    return ipsw_filter_v3_local_var;
end:
    if (version_local_nonprim) {
        ipsw_filter_v3_version_free(version_local_nonprim);
        version_local_nonprim = NULL;
    }
    if (device_local_nonprim) {
        ipsw_filter_v3_device_free(device_local_nonprim);
        device_local_nonprim = NULL;
    }
    return NULL;

}
