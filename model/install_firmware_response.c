#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "install_firmware_response.h"



static install_firmware_response_t *install_firmware_response_create_internal(
    char *task_id
    ) {
    install_firmware_response_t *install_firmware_response_local_var = malloc(sizeof(install_firmware_response_t));
    if (!install_firmware_response_local_var) {
        return NULL;
    }
    install_firmware_response_local_var->task_id = task_id;

    install_firmware_response_local_var->_library_owned = 1;
    return install_firmware_response_local_var;
}

__attribute__((deprecated)) install_firmware_response_t *install_firmware_response_create(
    char *task_id
    ) {
    return install_firmware_response_create_internal (
        task_id
        );
}

void install_firmware_response_free(install_firmware_response_t *install_firmware_response) {
    if(NULL == install_firmware_response){
        return ;
    }
    if(install_firmware_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "install_firmware_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (install_firmware_response->task_id) {
        free(install_firmware_response->task_id);
        install_firmware_response->task_id = NULL;
    }
    free(install_firmware_response);
}

cJSON *install_firmware_response_convertToJSON(install_firmware_response_t *install_firmware_response) {
    cJSON *item = cJSON_CreateObject();

    // install_firmware_response->task_id
    if (!install_firmware_response->task_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "taskId", install_firmware_response->task_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

install_firmware_response_t *install_firmware_response_parseFromJSON(cJSON *install_firmware_responseJSON){

    install_firmware_response_t *install_firmware_response_local_var = NULL;

    // install_firmware_response->task_id
    cJSON *task_id = cJSON_GetObjectItemCaseSensitive(install_firmware_responseJSON, "taskId");
    if (cJSON_IsNull(task_id)) {
        task_id = NULL;
    }
    if (!task_id) {
        goto end;
    }

    
    if(!cJSON_IsString(task_id))
    {
    goto end; //String
    }


    install_firmware_response_local_var = install_firmware_response_create_internal (
        strdup(task_id->valuestring)
        );

    return install_firmware_response_local_var;
end:
    return NULL;

}
