#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "restore_backup_data.h"



static restore_backup_data_t *restore_backup_data_create_internal(
    char *password
    ) {
    restore_backup_data_t *restore_backup_data_local_var = malloc(sizeof(restore_backup_data_t));
    if (!restore_backup_data_local_var) {
        return NULL;
    }
    restore_backup_data_local_var->password = password;

    restore_backup_data_local_var->_library_owned = 1;
    return restore_backup_data_local_var;
}

__attribute__((deprecated)) restore_backup_data_t *restore_backup_data_create(
    char *password
    ) {
    return restore_backup_data_create_internal (
        password
        );
}

void restore_backup_data_free(restore_backup_data_t *restore_backup_data) {
    if(NULL == restore_backup_data){
        return ;
    }
    if(restore_backup_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "restore_backup_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (restore_backup_data->password) {
        free(restore_backup_data->password);
        restore_backup_data->password = NULL;
    }
    free(restore_backup_data);
}

cJSON *restore_backup_data_convertToJSON(restore_backup_data_t *restore_backup_data) {
    cJSON *item = cJSON_CreateObject();

    // restore_backup_data->password
    if(restore_backup_data->password) {
    if(cJSON_AddStringToObject(item, "password", restore_backup_data->password) == NULL) {
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

restore_backup_data_t *restore_backup_data_parseFromJSON(cJSON *restore_backup_dataJSON){

    restore_backup_data_t *restore_backup_data_local_var = NULL;

    // restore_backup_data->password
    cJSON *password = cJSON_GetObjectItemCaseSensitive(restore_backup_dataJSON, "password");
    if (cJSON_IsNull(password)) {
        password = NULL;
    }
    if (password) { 
    if(!cJSON_IsString(password) && !cJSON_IsNull(password))
    {
    goto end; //String
    }
    }


    restore_backup_data_local_var = restore_backup_data_create_internal (
        password && !cJSON_IsNull(password) ? strdup(password->valuestring) : NULL
        );

    return restore_backup_data_local_var;
end:
    return NULL;

}
