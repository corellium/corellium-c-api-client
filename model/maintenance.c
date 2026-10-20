#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "maintenance.h"



static maintenance_t *maintenance_create_internal(
    char *message,
    char *header
    ) {
    maintenance_t *maintenance_local_var = malloc(sizeof(maintenance_t));
    if (!maintenance_local_var) {
        return NULL;
    }
    maintenance_local_var->message = message;
    maintenance_local_var->header = header;

    maintenance_local_var->_library_owned = 1;
    return maintenance_local_var;
}

__attribute__((deprecated)) maintenance_t *maintenance_create(
    char *message,
    char *header
    ) {
    return maintenance_create_internal (
        message,
        header
        );
}

void maintenance_free(maintenance_t *maintenance) {
    if(NULL == maintenance){
        return ;
    }
    if(maintenance->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "maintenance_free");
        return ;
    }
    listEntry_t *listEntry;
    if (maintenance->message) {
        free(maintenance->message);
        maintenance->message = NULL;
    }
    if (maintenance->header) {
        free(maintenance->header);
        maintenance->header = NULL;
    }
    free(maintenance);
}

cJSON *maintenance_convertToJSON(maintenance_t *maintenance) {
    cJSON *item = cJSON_CreateObject();

    // maintenance->message
    if(maintenance->message) {
    if(cJSON_AddStringToObject(item, "message", maintenance->message) == NULL) {
    goto fail; //String
    }
    }


    // maintenance->header
    if(maintenance->header) {
    if(cJSON_AddStringToObject(item, "header", maintenance->header) == NULL) {
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

maintenance_t *maintenance_parseFromJSON(cJSON *maintenanceJSON){

    maintenance_t *maintenance_local_var = NULL;

    // maintenance->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(maintenanceJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (message) { 
    if(!cJSON_IsString(message) && !cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // maintenance->header
    cJSON *header = cJSON_GetObjectItemCaseSensitive(maintenanceJSON, "header");
    if (cJSON_IsNull(header)) {
        header = NULL;
    }
    if (header) { 
    if(!cJSON_IsString(header) && !cJSON_IsNull(header))
    {
    goto end; //String
    }
    }


    maintenance_local_var = maintenance_create_internal (
        message && !cJSON_IsNull(message) ? strdup(message->valuestring) : NULL,
        header && !cJSON_IsNull(header) ? strdup(header->valuestring) : NULL
        );

    return maintenance_local_var;
end:
    return NULL;

}
