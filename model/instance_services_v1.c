#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "instance_services_v1.h"



static instance_services_v1_t *instance_services_v1_create_internal(
    vpn_definition_v1_t *vpn
    ) {
    instance_services_v1_t *instance_services_v1_local_var = malloc(sizeof(instance_services_v1_t));
    if (!instance_services_v1_local_var) {
        return NULL;
    }
    instance_services_v1_local_var->vpn = vpn;

    instance_services_v1_local_var->_library_owned = 1;
    return instance_services_v1_local_var;
}

__attribute__((deprecated)) instance_services_v1_t *instance_services_v1_create(
    vpn_definition_v1_t *vpn
    ) {
    return instance_services_v1_create_internal (
        vpn
        );
}

void instance_services_v1_free(instance_services_v1_t *instance_services_v1) {
    if(NULL == instance_services_v1){
        return ;
    }
    if(instance_services_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "instance_services_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (instance_services_v1->vpn) {
        vpn_definition_v1_free(instance_services_v1->vpn);
        instance_services_v1->vpn = NULL;
    }
    free(instance_services_v1);
}

cJSON *instance_services_v1_convertToJSON(instance_services_v1_t *instance_services_v1) {
    cJSON *item = cJSON_CreateObject();

    // instance_services_v1->vpn
    if(instance_services_v1->vpn) {
    cJSON *vpn_local_JSON = vpn_definition_v1_convertToJSON(instance_services_v1->vpn);
    if(vpn_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "vpn", vpn_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

instance_services_v1_t *instance_services_v1_parseFromJSON(cJSON *instance_services_v1JSON){

    instance_services_v1_t *instance_services_v1_local_var = NULL;

    // define the local variable for instance_services_v1->vpn
    vpn_definition_v1_t *vpn_local_nonprim = NULL;

    // instance_services_v1->vpn
    cJSON *vpn = cJSON_GetObjectItemCaseSensitive(instance_services_v1JSON, "vpn");
    if (cJSON_IsNull(vpn)) {
        vpn = NULL;
    }
    if (vpn) { 
    vpn_local_nonprim = vpn_definition_v1_parseFromJSON(vpn); //nonprimitive
    }


    instance_services_v1_local_var = instance_services_v1_create_internal (
        vpn ? vpn_local_nonprim : NULL
        );

    return instance_services_v1_local_var;
end:
    if (vpn_local_nonprim) {
        vpn_definition_v1_free(vpn_local_nonprim);
        vpn_local_nonprim = NULL;
    }
    return NULL;

}
