#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cluster_config_ipsw_filters_inner_device.h"



static cluster_config_ipsw_filters_inner_device_t *cluster_config_ipsw_filters_inner_device_create_internal(
    char *product
    ) {
    cluster_config_ipsw_filters_inner_device_t *cluster_config_ipsw_filters_inner_device_local_var = malloc(sizeof(cluster_config_ipsw_filters_inner_device_t));
    if (!cluster_config_ipsw_filters_inner_device_local_var) {
        return NULL;
    }
    cluster_config_ipsw_filters_inner_device_local_var->product = product;

    cluster_config_ipsw_filters_inner_device_local_var->_library_owned = 1;
    return cluster_config_ipsw_filters_inner_device_local_var;
}

__attribute__((deprecated)) cluster_config_ipsw_filters_inner_device_t *cluster_config_ipsw_filters_inner_device_create(
    char *product
    ) {
    return cluster_config_ipsw_filters_inner_device_create_internal (
        product
        );
}

void cluster_config_ipsw_filters_inner_device_free(cluster_config_ipsw_filters_inner_device_t *cluster_config_ipsw_filters_inner_device) {
    if(NULL == cluster_config_ipsw_filters_inner_device){
        return ;
    }
    if(cluster_config_ipsw_filters_inner_device->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cluster_config_ipsw_filters_inner_device_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cluster_config_ipsw_filters_inner_device->product) {
        free(cluster_config_ipsw_filters_inner_device->product);
        cluster_config_ipsw_filters_inner_device->product = NULL;
    }
    free(cluster_config_ipsw_filters_inner_device);
}

cJSON *cluster_config_ipsw_filters_inner_device_convertToJSON(cluster_config_ipsw_filters_inner_device_t *cluster_config_ipsw_filters_inner_device) {
    cJSON *item = cJSON_CreateObject();

    // cluster_config_ipsw_filters_inner_device->product
    if (!cluster_config_ipsw_filters_inner_device->product) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "product", cluster_config_ipsw_filters_inner_device->product) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

cluster_config_ipsw_filters_inner_device_t *cluster_config_ipsw_filters_inner_device_parseFromJSON(cJSON *cluster_config_ipsw_filters_inner_deviceJSON){

    cluster_config_ipsw_filters_inner_device_t *cluster_config_ipsw_filters_inner_device_local_var = NULL;

    // cluster_config_ipsw_filters_inner_device->product
    cJSON *product = cJSON_GetObjectItemCaseSensitive(cluster_config_ipsw_filters_inner_deviceJSON, "product");
    if (cJSON_IsNull(product)) {
        product = NULL;
    }
    if (!product) {
        goto end;
    }

    
    if(!cJSON_IsString(product))
    {
    goto end; //String
    }


    cluster_config_ipsw_filters_inner_device_local_var = cluster_config_ipsw_filters_inner_device_create_internal (
        strdup(product->valuestring)
        );

    return cluster_config_ipsw_filters_inner_device_local_var;
end:
    return NULL;

}
