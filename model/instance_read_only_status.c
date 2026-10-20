#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "instance_read_only_status.h"



static instance_read_only_status_t *instance_read_only_status_create_internal(
    char *read_only_status
    ) {
    instance_read_only_status_t *instance_read_only_status_local_var = malloc(sizeof(instance_read_only_status_t));
    if (!instance_read_only_status_local_var) {
        return NULL;
    }
    instance_read_only_status_local_var->read_only_status = read_only_status;

    instance_read_only_status_local_var->_library_owned = 1;
    return instance_read_only_status_local_var;
}

__attribute__((deprecated)) instance_read_only_status_t *instance_read_only_status_create(
    char *read_only_status
    ) {
    return instance_read_only_status_create_internal (
        read_only_status
        );
}

void instance_read_only_status_free(instance_read_only_status_t *instance_read_only_status) {
    if(NULL == instance_read_only_status){
        return ;
    }
    if(instance_read_only_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "instance_read_only_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (instance_read_only_status->read_only_status) {
        free(instance_read_only_status->read_only_status);
        instance_read_only_status->read_only_status = NULL;
    }
    free(instance_read_only_status);
}

cJSON *instance_read_only_status_convertToJSON(instance_read_only_status_t *instance_read_only_status) {
    cJSON *item = cJSON_CreateObject();

    // instance_read_only_status->read_only_status
    if (!instance_read_only_status->read_only_status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "readOnlyStatus", instance_read_only_status->read_only_status) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

instance_read_only_status_t *instance_read_only_status_parseFromJSON(cJSON *instance_read_only_statusJSON){

    instance_read_only_status_t *instance_read_only_status_local_var = NULL;

    // instance_read_only_status->read_only_status
    cJSON *read_only_status = cJSON_GetObjectItemCaseSensitive(instance_read_only_statusJSON, "readOnlyStatus");
    if (cJSON_IsNull(read_only_status)) {
        read_only_status = NULL;
    }
    if (!read_only_status) {
        goto end;
    }

    
    if(!cJSON_IsString(read_only_status))
    {
    goto end; //String
    }


    instance_read_only_status_local_var = instance_read_only_status_create_internal (
        strdup(read_only_status->valuestring)
        );

    return instance_read_only_status_local_var;
end:
    return NULL;

}
