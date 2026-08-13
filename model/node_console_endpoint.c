#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "node_console_endpoint.h"



static node_console_endpoint_t *node_console_endpoint_create_internal(
    char *url
    ) {
    node_console_endpoint_t *node_console_endpoint_local_var = malloc(sizeof(node_console_endpoint_t));
    if (!node_console_endpoint_local_var) {
        return NULL;
    }
    node_console_endpoint_local_var->url = url;

    node_console_endpoint_local_var->_library_owned = 1;
    return node_console_endpoint_local_var;
}

__attribute__((deprecated)) node_console_endpoint_t *node_console_endpoint_create(
    char *url
    ) {
    return node_console_endpoint_create_internal (
        url
        );
}

void node_console_endpoint_free(node_console_endpoint_t *node_console_endpoint) {
    if(NULL == node_console_endpoint){
        return ;
    }
    if(node_console_endpoint->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "node_console_endpoint_free");
        return ;
    }
    listEntry_t *listEntry;
    if (node_console_endpoint->url) {
        free(node_console_endpoint->url);
        node_console_endpoint->url = NULL;
    }
    free(node_console_endpoint);
}

cJSON *node_console_endpoint_convertToJSON(node_console_endpoint_t *node_console_endpoint) {
    cJSON *item = cJSON_CreateObject();

    // node_console_endpoint->url
    if (!node_console_endpoint->url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "url", node_console_endpoint->url) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

node_console_endpoint_t *node_console_endpoint_parseFromJSON(cJSON *node_console_endpointJSON){

    node_console_endpoint_t *node_console_endpoint_local_var = NULL;

    // node_console_endpoint->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(node_console_endpointJSON, "url");
    if (cJSON_IsNull(url)) {
        url = NULL;
    }
    if (!url) {
        goto end;
    }

    
    if(!cJSON_IsString(url))
    {
    goto end; //String
    }


    node_console_endpoint_local_var = node_console_endpoint_create_internal (
        strdup(url->valuestring)
        );

    return node_console_endpoint_local_var;
end:
    return NULL;

}
