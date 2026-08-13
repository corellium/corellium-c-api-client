#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "install_firmware_response_v1.h"



static install_firmware_response_v1_t *install_firmware_response_v1_create_internal(
    char *task_id,
    char *installed_firmware_url
    ) {
    install_firmware_response_v1_t *install_firmware_response_v1_local_var = malloc(sizeof(install_firmware_response_v1_t));
    if (!install_firmware_response_v1_local_var) {
        return NULL;
    }
    install_firmware_response_v1_local_var->task_id = task_id;
    install_firmware_response_v1_local_var->installed_firmware_url = installed_firmware_url;

    install_firmware_response_v1_local_var->_library_owned = 1;
    return install_firmware_response_v1_local_var;
}

__attribute__((deprecated)) install_firmware_response_v1_t *install_firmware_response_v1_create(
    char *task_id,
    char *installed_firmware_url
    ) {
    return install_firmware_response_v1_create_internal (
        task_id,
        installed_firmware_url
        );
}

void install_firmware_response_v1_free(install_firmware_response_v1_t *install_firmware_response_v1) {
    if(NULL == install_firmware_response_v1){
        return ;
    }
    if(install_firmware_response_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "install_firmware_response_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (install_firmware_response_v1->task_id) {
        free(install_firmware_response_v1->task_id);
        install_firmware_response_v1->task_id = NULL;
    }
    if (install_firmware_response_v1->installed_firmware_url) {
        free(install_firmware_response_v1->installed_firmware_url);
        install_firmware_response_v1->installed_firmware_url = NULL;
    }
    free(install_firmware_response_v1);
}

cJSON *install_firmware_response_v1_convertToJSON(install_firmware_response_v1_t *install_firmware_response_v1) {
    cJSON *item = cJSON_CreateObject();

    // install_firmware_response_v1->task_id
    if(install_firmware_response_v1->task_id) {
    if(cJSON_AddStringToObject(item, "taskId", install_firmware_response_v1->task_id) == NULL) {
    goto fail; //String
    }
    }


    // install_firmware_response_v1->installed_firmware_url
    if(install_firmware_response_v1->installed_firmware_url) {
    if(cJSON_AddStringToObject(item, "installedFirmwareUrl", install_firmware_response_v1->installed_firmware_url) == NULL) {
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

install_firmware_response_v1_t *install_firmware_response_v1_parseFromJSON(cJSON *install_firmware_response_v1JSON){

    install_firmware_response_v1_t *install_firmware_response_v1_local_var = NULL;

    // install_firmware_response_v1->task_id
    cJSON *task_id = cJSON_GetObjectItemCaseSensitive(install_firmware_response_v1JSON, "taskId");
    if (cJSON_IsNull(task_id)) {
        task_id = NULL;
    }
    if (task_id) { 
    if(!cJSON_IsString(task_id) && !cJSON_IsNull(task_id))
    {
    goto end; //String
    }
    }

    // install_firmware_response_v1->installed_firmware_url
    cJSON *installed_firmware_url = cJSON_GetObjectItemCaseSensitive(install_firmware_response_v1JSON, "installedFirmwareUrl");
    if (cJSON_IsNull(installed_firmware_url)) {
        installed_firmware_url = NULL;
    }
    if (installed_firmware_url) { 
    if(!cJSON_IsString(installed_firmware_url) && !cJSON_IsNull(installed_firmware_url))
    {
    goto end; //String
    }
    }


    install_firmware_response_v1_local_var = install_firmware_response_v1_create_internal (
        task_id && !cJSON_IsNull(task_id) ? strdup(task_id->valuestring) : NULL,
        installed_firmware_url && !cJSON_IsNull(installed_firmware_url) ? strdup(installed_firmware_url->valuestring) : NULL
        );

    return install_firmware_response_v1_local_var;
end:
    return NULL;

}
