#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "config_response_maintenance.h"



static config_response_maintenance_t *config_response_maintenance_create_internal(
    char *message,
    char *header
    ) {
    config_response_maintenance_t *config_response_maintenance_local_var = malloc(sizeof(config_response_maintenance_t));
    if (!config_response_maintenance_local_var) {
        return NULL;
    }
    config_response_maintenance_local_var->message = message;
    config_response_maintenance_local_var->header = header;

    config_response_maintenance_local_var->_library_owned = 1;
    return config_response_maintenance_local_var;
}

__attribute__((deprecated)) config_response_maintenance_t *config_response_maintenance_create(
    char *message,
    char *header
    ) {
    return config_response_maintenance_create_internal (
        message,
        header
        );
}

void config_response_maintenance_free(config_response_maintenance_t *config_response_maintenance) {
    if(NULL == config_response_maintenance){
        return ;
    }
    if(config_response_maintenance->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "config_response_maintenance_free");
        return ;
    }
    listEntry_t *listEntry;
    if (config_response_maintenance->message) {
        free(config_response_maintenance->message);
        config_response_maintenance->message = NULL;
    }
    if (config_response_maintenance->header) {
        free(config_response_maintenance->header);
        config_response_maintenance->header = NULL;
    }
    free(config_response_maintenance);
}

cJSON *config_response_maintenance_convertToJSON(config_response_maintenance_t *config_response_maintenance) {
    cJSON *item = cJSON_CreateObject();

    // config_response_maintenance->message
    if (!config_response_maintenance->message) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message", config_response_maintenance->message) == NULL) {
    goto fail; //String
    }


    // config_response_maintenance->header
    if (!config_response_maintenance->header) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "header", config_response_maintenance->header) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

config_response_maintenance_t *config_response_maintenance_parseFromJSON(cJSON *config_response_maintenanceJSON){

    config_response_maintenance_t *config_response_maintenance_local_var = NULL;

    // config_response_maintenance->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(config_response_maintenanceJSON, "message");
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

    // config_response_maintenance->header
    cJSON *header = cJSON_GetObjectItemCaseSensitive(config_response_maintenanceJSON, "header");
    if (cJSON_IsNull(header)) {
        header = NULL;
    }
    if (!header) {
        goto end;
    }

    
    if(!cJSON_IsString(header))
    {
    goto end; //String
    }


    config_response_maintenance_local_var = config_response_maintenance_create_internal (
        strdup(message->valuestring),
        strdup(header->valuestring)
        );

    return config_response_maintenance_local_var;
end:
    return NULL;

}
