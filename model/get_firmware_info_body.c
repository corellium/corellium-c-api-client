#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_firmware_info_body.h"



static get_firmware_info_body_t *get_firmware_info_body_create_internal(
    char *password,
    int extended
    ) {
    get_firmware_info_body_t *get_firmware_info_body_local_var = malloc(sizeof(get_firmware_info_body_t));
    if (!get_firmware_info_body_local_var) {
        return NULL;
    }
    get_firmware_info_body_local_var->password = password;
    get_firmware_info_body_local_var->extended = extended;

    get_firmware_info_body_local_var->_library_owned = 1;
    return get_firmware_info_body_local_var;
}

__attribute__((deprecated)) get_firmware_info_body_t *get_firmware_info_body_create(
    char *password,
    int extended
    ) {
    return get_firmware_info_body_create_internal (
        password,
        extended
        );
}

void get_firmware_info_body_free(get_firmware_info_body_t *get_firmware_info_body) {
    if(NULL == get_firmware_info_body){
        return ;
    }
    if(get_firmware_info_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "get_firmware_info_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (get_firmware_info_body->password) {
        free(get_firmware_info_body->password);
        get_firmware_info_body->password = NULL;
    }
    free(get_firmware_info_body);
}

cJSON *get_firmware_info_body_convertToJSON(get_firmware_info_body_t *get_firmware_info_body) {
    cJSON *item = cJSON_CreateObject();

    // get_firmware_info_body->password
    if(get_firmware_info_body->password) {
    if(cJSON_AddStringToObject(item, "password", get_firmware_info_body->password) == NULL) {
    goto fail; //String
    }
    }


    // get_firmware_info_body->extended
    if(get_firmware_info_body->extended) {
    if(cJSON_AddBoolToObject(item, "extended", get_firmware_info_body->extended) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

get_firmware_info_body_t *get_firmware_info_body_parseFromJSON(cJSON *get_firmware_info_bodyJSON){

    get_firmware_info_body_t *get_firmware_info_body_local_var = NULL;

    // get_firmware_info_body->password
    cJSON *password = cJSON_GetObjectItemCaseSensitive(get_firmware_info_bodyJSON, "password");
    if (cJSON_IsNull(password)) {
        password = NULL;
    }
    if (password) { 
    if(!cJSON_IsString(password) && !cJSON_IsNull(password))
    {
    goto end; //String
    }
    }

    // get_firmware_info_body->extended
    cJSON *extended = cJSON_GetObjectItemCaseSensitive(get_firmware_info_bodyJSON, "extended");
    if (cJSON_IsNull(extended)) {
        extended = NULL;
    }
    if (extended) { 
    if(!cJSON_IsBool(extended))
    {
    goto end; //Bool
    }
    }


    get_firmware_info_body_local_var = get_firmware_info_body_create_internal (
        password && !cJSON_IsNull(password) ? strdup(password->valuestring) : NULL,
        extended ? extended->valueint : 0
        );

    return get_firmware_info_body_local_var;
end:
    return NULL;

}
