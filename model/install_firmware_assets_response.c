#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "install_firmware_assets_response.h"



static install_firmware_assets_response_t *install_firmware_assets_response_create_internal(
    char *message
    ) {
    install_firmware_assets_response_t *install_firmware_assets_response_local_var = malloc(sizeof(install_firmware_assets_response_t));
    if (!install_firmware_assets_response_local_var) {
        return NULL;
    }
    install_firmware_assets_response_local_var->message = message;

    install_firmware_assets_response_local_var->_library_owned = 1;
    return install_firmware_assets_response_local_var;
}

__attribute__((deprecated)) install_firmware_assets_response_t *install_firmware_assets_response_create(
    char *message
    ) {
    return install_firmware_assets_response_create_internal (
        message
        );
}

void install_firmware_assets_response_free(install_firmware_assets_response_t *install_firmware_assets_response) {
    if(NULL == install_firmware_assets_response){
        return ;
    }
    if(install_firmware_assets_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "install_firmware_assets_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (install_firmware_assets_response->message) {
        free(install_firmware_assets_response->message);
        install_firmware_assets_response->message = NULL;
    }
    free(install_firmware_assets_response);
}

cJSON *install_firmware_assets_response_convertToJSON(install_firmware_assets_response_t *install_firmware_assets_response) {
    cJSON *item = cJSON_CreateObject();

    // install_firmware_assets_response->message
    if (!install_firmware_assets_response->message) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message", install_firmware_assets_response->message) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

install_firmware_assets_response_t *install_firmware_assets_response_parseFromJSON(cJSON *install_firmware_assets_responseJSON){

    install_firmware_assets_response_t *install_firmware_assets_response_local_var = NULL;

    // install_firmware_assets_response->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(install_firmware_assets_responseJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (!message) {
        goto end;
    }

    
    if(!cJSON_IsString(message))
    {
    goto end; //String
    }


    install_firmware_assets_response_local_var = install_firmware_assets_response_create_internal (
        strdup(message->valuestring)
        );

    return install_firmware_assets_response_local_var;
end:
    return NULL;

}
