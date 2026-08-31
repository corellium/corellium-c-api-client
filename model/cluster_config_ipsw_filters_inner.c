#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cluster_config_ipsw_filters_inner.h"



static cluster_config_ipsw_filters_inner_t *cluster_config_ipsw_filters_inner_create_internal(
    cluster_config_ipsw_filters_inner_device_t *device,
    cluster_config_ipsw_filters_inner_version_t *version,
    int include,
    int exclude
    ) {
    cluster_config_ipsw_filters_inner_t *cluster_config_ipsw_filters_inner_local_var = malloc(sizeof(cluster_config_ipsw_filters_inner_t));
    if (!cluster_config_ipsw_filters_inner_local_var) {
        return NULL;
    }
    cluster_config_ipsw_filters_inner_local_var->device = device;
    cluster_config_ipsw_filters_inner_local_var->version = version;
    cluster_config_ipsw_filters_inner_local_var->include = include;
    cluster_config_ipsw_filters_inner_local_var->exclude = exclude;

    cluster_config_ipsw_filters_inner_local_var->_library_owned = 1;
    return cluster_config_ipsw_filters_inner_local_var;
}

__attribute__((deprecated)) cluster_config_ipsw_filters_inner_t *cluster_config_ipsw_filters_inner_create(
    cluster_config_ipsw_filters_inner_device_t *device,
    cluster_config_ipsw_filters_inner_version_t *version,
    int include,
    int exclude
    ) {
    return cluster_config_ipsw_filters_inner_create_internal (
        device,
        version,
        include,
        exclude
        );
}

void cluster_config_ipsw_filters_inner_free(cluster_config_ipsw_filters_inner_t *cluster_config_ipsw_filters_inner) {
    if(NULL == cluster_config_ipsw_filters_inner){
        return ;
    }
    if(cluster_config_ipsw_filters_inner->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cluster_config_ipsw_filters_inner_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cluster_config_ipsw_filters_inner->device) {
        cluster_config_ipsw_filters_inner_device_free(cluster_config_ipsw_filters_inner->device);
        cluster_config_ipsw_filters_inner->device = NULL;
    }
    if (cluster_config_ipsw_filters_inner->version) {
        cluster_config_ipsw_filters_inner_version_free(cluster_config_ipsw_filters_inner->version);
        cluster_config_ipsw_filters_inner->version = NULL;
    }
    free(cluster_config_ipsw_filters_inner);
}

cJSON *cluster_config_ipsw_filters_inner_convertToJSON(cluster_config_ipsw_filters_inner_t *cluster_config_ipsw_filters_inner) {
    cJSON *item = cJSON_CreateObject();

    // cluster_config_ipsw_filters_inner->device
    if(cluster_config_ipsw_filters_inner->device) {
    cJSON *device_local_JSON = cluster_config_ipsw_filters_inner_device_convertToJSON(cluster_config_ipsw_filters_inner->device);
    if(device_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "device", device_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // cluster_config_ipsw_filters_inner->version
    if(cluster_config_ipsw_filters_inner->version) {
    cJSON *version_local_JSON = cluster_config_ipsw_filters_inner_version_convertToJSON(cluster_config_ipsw_filters_inner->version);
    if(version_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "version", version_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // cluster_config_ipsw_filters_inner->include
    if(cluster_config_ipsw_filters_inner->include) {
    if(cJSON_AddBoolToObject(item, "include", cluster_config_ipsw_filters_inner->include) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_ipsw_filters_inner->exclude
    if(cluster_config_ipsw_filters_inner->exclude) {
    if(cJSON_AddBoolToObject(item, "exclude", cluster_config_ipsw_filters_inner->exclude) == NULL) {
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

cluster_config_ipsw_filters_inner_t *cluster_config_ipsw_filters_inner_parseFromJSON(cJSON *cluster_config_ipsw_filters_innerJSON){

    cluster_config_ipsw_filters_inner_t *cluster_config_ipsw_filters_inner_local_var = NULL;

    // define the local variable for cluster_config_ipsw_filters_inner->device
    cluster_config_ipsw_filters_inner_device_t *device_local_nonprim = NULL;

    // define the local variable for cluster_config_ipsw_filters_inner->version
    cluster_config_ipsw_filters_inner_version_t *version_local_nonprim = NULL;

    // cluster_config_ipsw_filters_inner->device
    cJSON *device = cJSON_GetObjectItemCaseSensitive(cluster_config_ipsw_filters_innerJSON, "device");
    if (cJSON_IsNull(device)) {
        device = NULL;
    }
    if (device) { 
    device_local_nonprim = cluster_config_ipsw_filters_inner_device_parseFromJSON(device); //nonprimitive
    }

    // cluster_config_ipsw_filters_inner->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(cluster_config_ipsw_filters_innerJSON, "version");
    if (cJSON_IsNull(version)) {
        version = NULL;
    }
    if (version) { 
    version_local_nonprim = cluster_config_ipsw_filters_inner_version_parseFromJSON(version); //nonprimitive
    }

    // cluster_config_ipsw_filters_inner->include
    cJSON *include = cJSON_GetObjectItemCaseSensitive(cluster_config_ipsw_filters_innerJSON, "include");
    if (cJSON_IsNull(include)) {
        include = NULL;
    }
    if (include) { 
    if(!cJSON_IsBool(include))
    {
    goto end; //Bool
    }
    }

    // cluster_config_ipsw_filters_inner->exclude
    cJSON *exclude = cJSON_GetObjectItemCaseSensitive(cluster_config_ipsw_filters_innerJSON, "exclude");
    if (cJSON_IsNull(exclude)) {
        exclude = NULL;
    }
    if (exclude) { 
    if(!cJSON_IsBool(exclude))
    {
    goto end; //Bool
    }
    }


    cluster_config_ipsw_filters_inner_local_var = cluster_config_ipsw_filters_inner_create_internal (
        device ? device_local_nonprim : NULL,
        version ? version_local_nonprim : NULL,
        include ? include->valueint : 0,
        exclude ? exclude->valueint : 0
        );

    return cluster_config_ipsw_filters_inner_local_var;
end:
    if (device_local_nonprim) {
        cluster_config_ipsw_filters_inner_device_free(device_local_nonprim);
        device_local_nonprim = NULL;
    }
    if (version_local_nonprim) {
        cluster_config_ipsw_filters_inner_version_free(version_local_nonprim);
        version_local_nonprim = NULL;
    }
    return NULL;

}
