#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ipsw_filter_v3_device.h"



static ipsw_filter_v3_device_t *ipsw_filter_v3_device_create_internal(
    char *product
    ) {
    ipsw_filter_v3_device_t *ipsw_filter_v3_device_local_var = malloc(sizeof(ipsw_filter_v3_device_t));
    if (!ipsw_filter_v3_device_local_var) {
        return NULL;
    }
    ipsw_filter_v3_device_local_var->product = product;

    ipsw_filter_v3_device_local_var->_library_owned = 1;
    return ipsw_filter_v3_device_local_var;
}

__attribute__((deprecated)) ipsw_filter_v3_device_t *ipsw_filter_v3_device_create(
    char *product
    ) {
    return ipsw_filter_v3_device_create_internal (
        product
        );
}

void ipsw_filter_v3_device_free(ipsw_filter_v3_device_t *ipsw_filter_v3_device) {
    if(NULL == ipsw_filter_v3_device){
        return ;
    }
    if(ipsw_filter_v3_device->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ipsw_filter_v3_device_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ipsw_filter_v3_device->product) {
        free(ipsw_filter_v3_device->product);
        ipsw_filter_v3_device->product = NULL;
    }
    free(ipsw_filter_v3_device);
}

cJSON *ipsw_filter_v3_device_convertToJSON(ipsw_filter_v3_device_t *ipsw_filter_v3_device) {
    cJSON *item = cJSON_CreateObject();

    // ipsw_filter_v3_device->product
    if(ipsw_filter_v3_device->product) {
    if(cJSON_AddStringToObject(item, "product", ipsw_filter_v3_device->product) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ipsw_filter_v3_device_t *ipsw_filter_v3_device_parseFromJSON(cJSON *ipsw_filter_v3_deviceJSON){

    ipsw_filter_v3_device_t *ipsw_filter_v3_device_local_var = NULL;

    // ipsw_filter_v3_device->product
    cJSON *product = cJSON_GetObjectItemCaseSensitive(ipsw_filter_v3_deviceJSON, "product");
    if (cJSON_IsNull(product)) {
        product = NULL;
    }
    if (product) { 
    if(!cJSON_IsString(product) && !cJSON_IsNull(product))
    {
    goto end; //String
    }
    }


    ipsw_filter_v3_device_local_var = ipsw_filter_v3_device_create_internal (
        product && !cJSON_IsNull(product) ? strdup(product->valuestring) : NULL
        );

    return ipsw_filter_v3_device_local_var;
end:
    return NULL;

}
