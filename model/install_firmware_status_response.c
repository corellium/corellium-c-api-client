#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "install_firmware_status_response.h"



static install_firmware_status_response_t *install_firmware_status_response_create_internal(
    corellium_api_task_status__e status,
    char *installed_firmware_url
    ) {
    install_firmware_status_response_t *install_firmware_status_response_local_var = malloc(sizeof(install_firmware_status_response_t));
    if (!install_firmware_status_response_local_var) {
        return NULL;
    }
    install_firmware_status_response_local_var->status = status;
    install_firmware_status_response_local_var->installed_firmware_url = installed_firmware_url;

    install_firmware_status_response_local_var->_library_owned = 1;
    return install_firmware_status_response_local_var;
}

__attribute__((deprecated)) install_firmware_status_response_t *install_firmware_status_response_create(
    corellium_api_task_status__e status,
    char *installed_firmware_url
    ) {
    return install_firmware_status_response_create_internal (
        status,
        installed_firmware_url
        );
}

void install_firmware_status_response_free(install_firmware_status_response_t *install_firmware_status_response) {
    if(NULL == install_firmware_status_response){
        return ;
    }
    if(install_firmware_status_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "install_firmware_status_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (install_firmware_status_response->installed_firmware_url) {
        free(install_firmware_status_response->installed_firmware_url);
        install_firmware_status_response->installed_firmware_url = NULL;
    }
    free(install_firmware_status_response);
}

cJSON *install_firmware_status_response_convertToJSON(install_firmware_status_response_t *install_firmware_status_response) {
    cJSON *item = cJSON_CreateObject();

    // install_firmware_status_response->status
    if (corellium_api_task_status__NULL == install_firmware_status_response->status) {
        goto fail;
    }
    cJSON *status_local_JSON = task_status_convertToJSON(install_firmware_status_response->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // install_firmware_status_response->installed_firmware_url
    if(install_firmware_status_response->installed_firmware_url) {
    if(cJSON_AddStringToObject(item, "installedFirmwareUrl", install_firmware_status_response->installed_firmware_url) == NULL) {
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

install_firmware_status_response_t *install_firmware_status_response_parseFromJSON(cJSON *install_firmware_status_responseJSON){

    install_firmware_status_response_t *install_firmware_status_response_local_var = NULL;

    // define the local variable for install_firmware_status_response->status
    corellium_api_task_status__e status_local_nonprim = 0;

    // install_firmware_status_response->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(install_firmware_status_responseJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    status_local_nonprim = task_status_parseFromJSON(status); //custom

    // install_firmware_status_response->installed_firmware_url
    cJSON *installed_firmware_url = cJSON_GetObjectItemCaseSensitive(install_firmware_status_responseJSON, "installedFirmwareUrl");
    if (cJSON_IsNull(installed_firmware_url)) {
        installed_firmware_url = NULL;
    }
    if (installed_firmware_url) { 
    if(!cJSON_IsString(installed_firmware_url) && !cJSON_IsNull(installed_firmware_url))
    {
    goto end; //String
    }
    }


    install_firmware_status_response_local_var = install_firmware_status_response_create_internal (
        status_local_nonprim,
        installed_firmware_url && !cJSON_IsNull(installed_firmware_url) ? strdup(installed_firmware_url->valuestring) : NULL
        );

    return install_firmware_status_response_local_var;
end:
    if (status_local_nonprim) {
        status_local_nonprim = 0;
    }
    return NULL;

}
