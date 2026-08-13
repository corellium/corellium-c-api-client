#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "patch_instance_body_proxy_inner.h"



static patch_instance_body_proxy_inner_t *patch_instance_body_proxy_inner_create_internal(
    double device_port,
    int first_available,
    int expose,
    double router_port
    ) {
    patch_instance_body_proxy_inner_t *patch_instance_body_proxy_inner_local_var = malloc(sizeof(patch_instance_body_proxy_inner_t));
    if (!patch_instance_body_proxy_inner_local_var) {
        return NULL;
    }
    patch_instance_body_proxy_inner_local_var->device_port = device_port;
    patch_instance_body_proxy_inner_local_var->first_available = first_available;
    patch_instance_body_proxy_inner_local_var->expose = expose;
    patch_instance_body_proxy_inner_local_var->router_port = router_port;

    patch_instance_body_proxy_inner_local_var->_library_owned = 1;
    return patch_instance_body_proxy_inner_local_var;
}

__attribute__((deprecated)) patch_instance_body_proxy_inner_t *patch_instance_body_proxy_inner_create(
    double device_port,
    int first_available,
    int expose,
    double router_port
    ) {
    return patch_instance_body_proxy_inner_create_internal (
        device_port,
        first_available,
        expose,
        router_port
        );
}

void patch_instance_body_proxy_inner_free(patch_instance_body_proxy_inner_t *patch_instance_body_proxy_inner) {
    if(NULL == patch_instance_body_proxy_inner){
        return ;
    }
    if(patch_instance_body_proxy_inner->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "patch_instance_body_proxy_inner_free");
        return ;
    }
    listEntry_t *listEntry;
    free(patch_instance_body_proxy_inner);
}

cJSON *patch_instance_body_proxy_inner_convertToJSON(patch_instance_body_proxy_inner_t *patch_instance_body_proxy_inner) {
    cJSON *item = cJSON_CreateObject();

    // patch_instance_body_proxy_inner->device_port
    if (!patch_instance_body_proxy_inner->device_port) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "devicePort", patch_instance_body_proxy_inner->device_port) == NULL) {
    goto fail; //Numeric
    }


    // patch_instance_body_proxy_inner->first_available
    if (!patch_instance_body_proxy_inner->first_available) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "firstAvailable", patch_instance_body_proxy_inner->first_available) == NULL) {
    goto fail; //Bool
    }


    // patch_instance_body_proxy_inner->expose
    if (!patch_instance_body_proxy_inner->expose) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "expose", patch_instance_body_proxy_inner->expose) == NULL) {
    goto fail; //Bool
    }


    // patch_instance_body_proxy_inner->router_port
    if (!patch_instance_body_proxy_inner->router_port) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "routerPort", patch_instance_body_proxy_inner->router_port) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

patch_instance_body_proxy_inner_t *patch_instance_body_proxy_inner_parseFromJSON(cJSON *patch_instance_body_proxy_innerJSON){

    patch_instance_body_proxy_inner_t *patch_instance_body_proxy_inner_local_var = NULL;

    // patch_instance_body_proxy_inner->device_port
    cJSON *device_port = cJSON_GetObjectItemCaseSensitive(patch_instance_body_proxy_innerJSON, "devicePort");
    if (cJSON_IsNull(device_port)) {
        device_port = NULL;
    }
    if (!device_port) {
        goto end;
    }

    
    if(!cJSON_IsNumber(device_port))
    {
    goto end; //Numeric
    }

    // patch_instance_body_proxy_inner->first_available
    cJSON *first_available = cJSON_GetObjectItemCaseSensitive(patch_instance_body_proxy_innerJSON, "firstAvailable");
    if (cJSON_IsNull(first_available)) {
        first_available = NULL;
    }
    if (!first_available) {
        goto end;
    }

    
    if(!cJSON_IsBool(first_available))
    {
    goto end; //Bool
    }

    // patch_instance_body_proxy_inner->expose
    cJSON *expose = cJSON_GetObjectItemCaseSensitive(patch_instance_body_proxy_innerJSON, "expose");
    if (cJSON_IsNull(expose)) {
        expose = NULL;
    }
    if (!expose) {
        goto end;
    }

    
    if(!cJSON_IsBool(expose))
    {
    goto end; //Bool
    }

    // patch_instance_body_proxy_inner->router_port
    cJSON *router_port = cJSON_GetObjectItemCaseSensitive(patch_instance_body_proxy_innerJSON, "routerPort");
    if (cJSON_IsNull(router_port)) {
        router_port = NULL;
    }
    if (!router_port) {
        goto end;
    }

    
    if(!cJSON_IsNumber(router_port))
    {
    goto end; //Numeric
    }


    patch_instance_body_proxy_inner_local_var = patch_instance_body_proxy_inner_create_internal (
        device_port->valuedouble,
        first_available->valueint,
        expose->valueint,
        router_port->valuedouble
        );

    return patch_instance_body_proxy_inner_local_var;
end:
    return NULL;

}
