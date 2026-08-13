#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ipsw_device_constraint.h"



static ipsw_device_constraint_t *ipsw_device_constraint_create_internal(
    char *product
    ) {
    ipsw_device_constraint_t *ipsw_device_constraint_local_var = malloc(sizeof(ipsw_device_constraint_t));
    if (!ipsw_device_constraint_local_var) {
        return NULL;
    }
    ipsw_device_constraint_local_var->product = product;

    ipsw_device_constraint_local_var->_library_owned = 1;
    return ipsw_device_constraint_local_var;
}

__attribute__((deprecated)) ipsw_device_constraint_t *ipsw_device_constraint_create(
    char *product
    ) {
    return ipsw_device_constraint_create_internal (
        product
        );
}

void ipsw_device_constraint_free(ipsw_device_constraint_t *ipsw_device_constraint) {
    if(NULL == ipsw_device_constraint){
        return ;
    }
    if(ipsw_device_constraint->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ipsw_device_constraint_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ipsw_device_constraint->product) {
        free(ipsw_device_constraint->product);
        ipsw_device_constraint->product = NULL;
    }
    free(ipsw_device_constraint);
}

cJSON *ipsw_device_constraint_convertToJSON(ipsw_device_constraint_t *ipsw_device_constraint) {
    cJSON *item = cJSON_CreateObject();

    // ipsw_device_constraint->product
    if(ipsw_device_constraint->product) {
    if(cJSON_AddStringToObject(item, "product", ipsw_device_constraint->product) == NULL) {
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

ipsw_device_constraint_t *ipsw_device_constraint_parseFromJSON(cJSON *ipsw_device_constraintJSON){

    ipsw_device_constraint_t *ipsw_device_constraint_local_var = NULL;

    // ipsw_device_constraint->product
    cJSON *product = cJSON_GetObjectItemCaseSensitive(ipsw_device_constraintJSON, "product");
    if (cJSON_IsNull(product)) {
        product = NULL;
    }
    if (product) { 
    if(!cJSON_IsString(product) && !cJSON_IsNull(product))
    {
    goto end; //String
    }
    }


    ipsw_device_constraint_local_var = ipsw_device_constraint_create_internal (
        product && !cJSON_IsNull(product) ? strdup(product->valuestring) : NULL
        );

    return ipsw_device_constraint_local_var;
end:
    return NULL;

}
