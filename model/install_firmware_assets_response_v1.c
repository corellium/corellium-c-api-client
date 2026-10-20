#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "install_firmware_assets_response_v1.h"



static install_firmware_assets_response_v1_t *install_firmware_assets_response_v1_create_internal(
    char *message
    ) {
    install_firmware_assets_response_v1_t *install_firmware_assets_response_v1_local_var = malloc(sizeof(install_firmware_assets_response_v1_t));
    if (!install_firmware_assets_response_v1_local_var) {
        return NULL;
    }
    install_firmware_assets_response_v1_local_var->message = message;

    install_firmware_assets_response_v1_local_var->_library_owned = 1;
    return install_firmware_assets_response_v1_local_var;
}

__attribute__((deprecated)) install_firmware_assets_response_v1_t *install_firmware_assets_response_v1_create(
    char *message
    ) {
    return install_firmware_assets_response_v1_create_internal (
        message
        );
}

void install_firmware_assets_response_v1_free(install_firmware_assets_response_v1_t *install_firmware_assets_response_v1) {
    if(NULL == install_firmware_assets_response_v1){
        return ;
    }
    if(install_firmware_assets_response_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "install_firmware_assets_response_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (install_firmware_assets_response_v1->message) {
        free(install_firmware_assets_response_v1->message);
        install_firmware_assets_response_v1->message = NULL;
    }
    free(install_firmware_assets_response_v1);
}

cJSON *install_firmware_assets_response_v1_convertToJSON(install_firmware_assets_response_v1_t *install_firmware_assets_response_v1) {
    cJSON *item = cJSON_CreateObject();

    // install_firmware_assets_response_v1->message
    if(install_firmware_assets_response_v1->message) {
    if(cJSON_AddStringToObject(item, "message", install_firmware_assets_response_v1->message) == NULL) {
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

install_firmware_assets_response_v1_t *install_firmware_assets_response_v1_parseFromJSON(cJSON *install_firmware_assets_response_v1JSON){

    install_firmware_assets_response_v1_t *install_firmware_assets_response_v1_local_var = NULL;

    // install_firmware_assets_response_v1->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(install_firmware_assets_response_v1JSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (message) { 
    if(!cJSON_IsString(message) && !cJSON_IsNull(message))
    {
    goto end; //String
    }
    }


    install_firmware_assets_response_v1_local_var = install_firmware_assets_response_v1_create_internal (
        message && !cJSON_IsNull(message) ? strdup(message->valuestring) : NULL
        );

    return install_firmware_assets_response_v1_local_var;
end:
    return NULL;

}
