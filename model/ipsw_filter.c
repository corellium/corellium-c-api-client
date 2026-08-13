#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ipsw_filter.h"



static ipsw_filter_t *ipsw_filter_create_internal(
    ipsw_version_constraint_t *version,
    ipsw_device_constraint_t *device,
    int exclude,
    int include
    ) {
    ipsw_filter_t *ipsw_filter_local_var = malloc(sizeof(ipsw_filter_t));
    if (!ipsw_filter_local_var) {
        return NULL;
    }
    ipsw_filter_local_var->version = version;
    ipsw_filter_local_var->device = device;
    ipsw_filter_local_var->exclude = exclude;
    ipsw_filter_local_var->include = include;

    ipsw_filter_local_var->_library_owned = 1;
    return ipsw_filter_local_var;
}

__attribute__((deprecated)) ipsw_filter_t *ipsw_filter_create(
    ipsw_version_constraint_t *version,
    ipsw_device_constraint_t *device,
    int exclude,
    int include
    ) {
    return ipsw_filter_create_internal (
        version,
        device,
        exclude,
        include
        );
}

void ipsw_filter_free(ipsw_filter_t *ipsw_filter) {
    if(NULL == ipsw_filter){
        return ;
    }
    if(ipsw_filter->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ipsw_filter_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ipsw_filter->version) {
        ipsw_version_constraint_free(ipsw_filter->version);
        ipsw_filter->version = NULL;
    }
    if (ipsw_filter->device) {
        ipsw_device_constraint_free(ipsw_filter->device);
        ipsw_filter->device = NULL;
    }
    free(ipsw_filter);
}

cJSON *ipsw_filter_convertToJSON(ipsw_filter_t *ipsw_filter) {
    cJSON *item = cJSON_CreateObject();

    // ipsw_filter->version
    if(ipsw_filter->version) {
    cJSON *version_local_JSON = ipsw_version_constraint_convertToJSON(ipsw_filter->version);
    if(version_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "version", version_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // ipsw_filter->device
    if(ipsw_filter->device) {
    cJSON *device_local_JSON = ipsw_device_constraint_convertToJSON(ipsw_filter->device);
    if(device_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "device", device_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // ipsw_filter->exclude
    if(ipsw_filter->exclude) {
    if(cJSON_AddBoolToObject(item, "exclude", ipsw_filter->exclude) == NULL) {
    goto fail; //Bool
    }
    }


    // ipsw_filter->include
    if(ipsw_filter->include) {
    if(cJSON_AddBoolToObject(item, "include", ipsw_filter->include) == NULL) {
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

ipsw_filter_t *ipsw_filter_parseFromJSON(cJSON *ipsw_filterJSON){

    ipsw_filter_t *ipsw_filter_local_var = NULL;

    // define the local variable for ipsw_filter->version
    ipsw_version_constraint_t *version_local_nonprim = NULL;

    // define the local variable for ipsw_filter->device
    ipsw_device_constraint_t *device_local_nonprim = NULL;

    // ipsw_filter->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(ipsw_filterJSON, "version");
    if (cJSON_IsNull(version)) {
        version = NULL;
    }
    if (version) { 
    version_local_nonprim = ipsw_version_constraint_parseFromJSON(version); //nonprimitive
    }

    // ipsw_filter->device
    cJSON *device = cJSON_GetObjectItemCaseSensitive(ipsw_filterJSON, "device");
    if (cJSON_IsNull(device)) {
        device = NULL;
    }
    if (device) { 
    device_local_nonprim = ipsw_device_constraint_parseFromJSON(device); //nonprimitive
    }

    // ipsw_filter->exclude
    cJSON *exclude = cJSON_GetObjectItemCaseSensitive(ipsw_filterJSON, "exclude");
    if (cJSON_IsNull(exclude)) {
        exclude = NULL;
    }
    if (exclude) { 
    if(!cJSON_IsBool(exclude))
    {
    goto end; //Bool
    }
    }

    // ipsw_filter->include
    cJSON *include = cJSON_GetObjectItemCaseSensitive(ipsw_filterJSON, "include");
    if (cJSON_IsNull(include)) {
        include = NULL;
    }
    if (include) { 
    if(!cJSON_IsBool(include))
    {
    goto end; //Bool
    }
    }


    ipsw_filter_local_var = ipsw_filter_create_internal (
        version ? version_local_nonprim : NULL,
        device ? device_local_nonprim : NULL,
        exclude ? exclude->valueint : 0,
        include ? include->valueint : 0
        );

    return ipsw_filter_local_var;
end:
    if (version_local_nonprim) {
        ipsw_version_constraint_free(version_local_nonprim);
        version_local_nonprim = NULL;
    }
    if (device_local_nonprim) {
        ipsw_device_constraint_free(device_local_nonprim);
        device_local_nonprim = NULL;
    }
    return NULL;

}
