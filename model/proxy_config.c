#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "proxy_config.h"



static proxy_config_t *proxy_config_create_internal(
    double device_port,
    int first_available,
    int expose,
    double router_port
    ) {
    proxy_config_t *proxy_config_local_var = malloc(sizeof(proxy_config_t));
    if (!proxy_config_local_var) {
        return NULL;
    }
    proxy_config_local_var->device_port = device_port;
    proxy_config_local_var->first_available = first_available;
    proxy_config_local_var->expose = expose;
    proxy_config_local_var->router_port = router_port;

    proxy_config_local_var->_library_owned = 1;
    return proxy_config_local_var;
}

__attribute__((deprecated)) proxy_config_t *proxy_config_create(
    double device_port,
    int first_available,
    int expose,
    double router_port
    ) {
    return proxy_config_create_internal (
        device_port,
        first_available,
        expose,
        router_port
        );
}

void proxy_config_free(proxy_config_t *proxy_config) {
    if(NULL == proxy_config){
        return ;
    }
    if(proxy_config->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "proxy_config_free");
        return ;
    }
    listEntry_t *listEntry;
    free(proxy_config);
}

cJSON *proxy_config_convertToJSON(proxy_config_t *proxy_config) {
    cJSON *item = cJSON_CreateObject();

    // proxy_config->device_port
    if(proxy_config->device_port) {
    if(cJSON_AddNumberToObject(item, "devicePort", proxy_config->device_port) == NULL) {
    goto fail; //Numeric
    }
    }


    // proxy_config->first_available
    if(proxy_config->first_available) {
    if(cJSON_AddBoolToObject(item, "firstAvailable", proxy_config->first_available) == NULL) {
    goto fail; //Bool
    }
    }


    // proxy_config->expose
    if(proxy_config->expose) {
    if(cJSON_AddBoolToObject(item, "expose", proxy_config->expose) == NULL) {
    goto fail; //Bool
    }
    }


    // proxy_config->router_port
    if(proxy_config->router_port) {
    if(cJSON_AddNumberToObject(item, "routerPort", proxy_config->router_port) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

proxy_config_t *proxy_config_parseFromJSON(cJSON *proxy_configJSON){

    proxy_config_t *proxy_config_local_var = NULL;

    // proxy_config->device_port
    cJSON *device_port = cJSON_GetObjectItemCaseSensitive(proxy_configJSON, "devicePort");
    if (cJSON_IsNull(device_port)) {
        device_port = NULL;
    }
    if (device_port) { 
    if(!cJSON_IsNumber(device_port))
    {
    goto end; //Numeric
    }
    }

    // proxy_config->first_available
    cJSON *first_available = cJSON_GetObjectItemCaseSensitive(proxy_configJSON, "firstAvailable");
    if (cJSON_IsNull(first_available)) {
        first_available = NULL;
    }
    if (first_available) { 
    if(!cJSON_IsBool(first_available))
    {
    goto end; //Bool
    }
    }

    // proxy_config->expose
    cJSON *expose = cJSON_GetObjectItemCaseSensitive(proxy_configJSON, "expose");
    if (cJSON_IsNull(expose)) {
        expose = NULL;
    }
    if (expose) { 
    if(!cJSON_IsBool(expose))
    {
    goto end; //Bool
    }
    }

    // proxy_config->router_port
    cJSON *router_port = cJSON_GetObjectItemCaseSensitive(proxy_configJSON, "routerPort");
    if (cJSON_IsNull(router_port)) {
        router_port = NULL;
    }
    if (router_port) { 
    if(!cJSON_IsNumber(router_port))
    {
    goto end; //Numeric
    }
    }


    proxy_config_local_var = proxy_config_create_internal (
        device_port ? device_port->valuedouble : 0,
        first_available ? first_available->valueint : 0,
        expose ? expose->valueint : 0,
        router_port ? router_port->valuedouble : 0
        );

    return proxy_config_local_var;
end:
    return NULL;

}
