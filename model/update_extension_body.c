#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "update_extension_body.h"



static update_extension_body_t *update_extension_body_create_internal(
    int enabled
    ) {
    update_extension_body_t *update_extension_body_local_var = malloc(sizeof(update_extension_body_t));
    if (!update_extension_body_local_var) {
        return NULL;
    }
    update_extension_body_local_var->enabled = enabled;

    update_extension_body_local_var->_library_owned = 1;
    return update_extension_body_local_var;
}

__attribute__((deprecated)) update_extension_body_t *update_extension_body_create(
    int enabled
    ) {
    return update_extension_body_create_internal (
        enabled
        );
}

void update_extension_body_free(update_extension_body_t *update_extension_body) {
    if(NULL == update_extension_body){
        return ;
    }
    if(update_extension_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "update_extension_body_free");
        return ;
    }
    listEntry_t *listEntry;
    free(update_extension_body);
}

cJSON *update_extension_body_convertToJSON(update_extension_body_t *update_extension_body) {
    cJSON *item = cJSON_CreateObject();

    // update_extension_body->enabled
    if (!update_extension_body->enabled) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "enabled", update_extension_body->enabled) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

update_extension_body_t *update_extension_body_parseFromJSON(cJSON *update_extension_bodyJSON){

    update_extension_body_t *update_extension_body_local_var = NULL;

    // update_extension_body->enabled
    cJSON *enabled = cJSON_GetObjectItemCaseSensitive(update_extension_bodyJSON, "enabled");
    if (cJSON_IsNull(enabled)) {
        enabled = NULL;
    }
    if (!enabled) {
        goto end;
    }

    
    if(!cJSON_IsBool(enabled))
    {
    goto end; //Bool
    }


    update_extension_body_local_var = update_extension_body_create_internal (
        enabled->valueint
        );

    return update_extension_body_local_var;
end:
    return NULL;

}
