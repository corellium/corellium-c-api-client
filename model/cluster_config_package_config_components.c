#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cluster_config_package_config_components.h"



static cluster_config_package_config_components_t *cluster_config_package_config_components_create_internal(
    int cellebrite_device_image
    ) {
    cluster_config_package_config_components_t *cluster_config_package_config_components_local_var = malloc(sizeof(cluster_config_package_config_components_t));
    if (!cluster_config_package_config_components_local_var) {
        return NULL;
    }
    cluster_config_package_config_components_local_var->cellebrite_device_image = cellebrite_device_image;

    cluster_config_package_config_components_local_var->_library_owned = 1;
    return cluster_config_package_config_components_local_var;
}

__attribute__((deprecated)) cluster_config_package_config_components_t *cluster_config_package_config_components_create(
    int cellebrite_device_image
    ) {
    return cluster_config_package_config_components_create_internal (
        cellebrite_device_image
        );
}

void cluster_config_package_config_components_free(cluster_config_package_config_components_t *cluster_config_package_config_components) {
    if(NULL == cluster_config_package_config_components){
        return ;
    }
    if(cluster_config_package_config_components->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cluster_config_package_config_components_free");
        return ;
    }
    listEntry_t *listEntry;
    free(cluster_config_package_config_components);
}

cJSON *cluster_config_package_config_components_convertToJSON(cluster_config_package_config_components_t *cluster_config_package_config_components) {
    cJSON *item = cJSON_CreateObject();

    // cluster_config_package_config_components->cellebrite_device_image
    if(cluster_config_package_config_components->cellebrite_device_image) {
    if(cJSON_AddBoolToObject(item, "cellebriteDeviceImage", cluster_config_package_config_components->cellebrite_device_image) == NULL) {
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

cluster_config_package_config_components_t *cluster_config_package_config_components_parseFromJSON(cJSON *cluster_config_package_config_componentsJSON){

    cluster_config_package_config_components_t *cluster_config_package_config_components_local_var = NULL;

    // cluster_config_package_config_components->cellebrite_device_image
    cJSON *cellebrite_device_image = cJSON_GetObjectItemCaseSensitive(cluster_config_package_config_componentsJSON, "cellebriteDeviceImage");
    if (cJSON_IsNull(cellebrite_device_image)) {
        cellebrite_device_image = NULL;
    }
    if (cellebrite_device_image) { 
    if(!cJSON_IsBool(cellebrite_device_image))
    {
    goto end; //Bool
    }
    }


    cluster_config_package_config_components_local_var = cluster_config_package_config_components_create_internal (
        cellebrite_device_image ? cellebrite_device_image->valueint : 0
        );

    return cluster_config_package_config_components_local_var;
end:
    return NULL;

}
