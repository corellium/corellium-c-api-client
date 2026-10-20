#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "instance_console_endpoint_v1.h"



static instance_console_endpoint_v1_t *instance_console_endpoint_v1_create_internal(
    char *url
    ) {
    instance_console_endpoint_v1_t *instance_console_endpoint_v1_local_var = malloc(sizeof(instance_console_endpoint_v1_t));
    if (!instance_console_endpoint_v1_local_var) {
        return NULL;
    }
    instance_console_endpoint_v1_local_var->url = url;

    instance_console_endpoint_v1_local_var->_library_owned = 1;
    return instance_console_endpoint_v1_local_var;
}

__attribute__((deprecated)) instance_console_endpoint_v1_t *instance_console_endpoint_v1_create(
    char *url
    ) {
    return instance_console_endpoint_v1_create_internal (
        url
        );
}

void instance_console_endpoint_v1_free(instance_console_endpoint_v1_t *instance_console_endpoint_v1) {
    if(NULL == instance_console_endpoint_v1){
        return ;
    }
    if(instance_console_endpoint_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "instance_console_endpoint_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (instance_console_endpoint_v1->url) {
        free(instance_console_endpoint_v1->url);
        instance_console_endpoint_v1->url = NULL;
    }
    free(instance_console_endpoint_v1);
}

cJSON *instance_console_endpoint_v1_convertToJSON(instance_console_endpoint_v1_t *instance_console_endpoint_v1) {
    cJSON *item = cJSON_CreateObject();

    // instance_console_endpoint_v1->url
    if(instance_console_endpoint_v1->url) {
    if(cJSON_AddStringToObject(item, "url", instance_console_endpoint_v1->url) == NULL) {
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

instance_console_endpoint_v1_t *instance_console_endpoint_v1_parseFromJSON(cJSON *instance_console_endpoint_v1JSON){

    instance_console_endpoint_v1_t *instance_console_endpoint_v1_local_var = NULL;

    // instance_console_endpoint_v1->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(instance_console_endpoint_v1JSON, "url");
    if (cJSON_IsNull(url)) {
        url = NULL;
    }
    if (url) { 
    if(!cJSON_IsString(url) && !cJSON_IsNull(url))
    {
    goto end; //String
    }
    }


    instance_console_endpoint_v1_local_var = instance_console_endpoint_v1_create_internal (
        url && !cJSON_IsNull(url) ? strdup(url->valuestring) : NULL
        );

    return instance_console_endpoint_v1_local_var;
end:
    return NULL;

}
