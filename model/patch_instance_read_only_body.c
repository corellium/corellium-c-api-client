#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "patch_instance_read_only_body.h"



static patch_instance_read_only_body_t *patch_instance_read_only_body_create_internal(
    int read_only
    ) {
    patch_instance_read_only_body_t *patch_instance_read_only_body_local_var = malloc(sizeof(patch_instance_read_only_body_t));
    if (!patch_instance_read_only_body_local_var) {
        return NULL;
    }
    patch_instance_read_only_body_local_var->read_only = read_only;

    patch_instance_read_only_body_local_var->_library_owned = 1;
    return patch_instance_read_only_body_local_var;
}

__attribute__((deprecated)) patch_instance_read_only_body_t *patch_instance_read_only_body_create(
    int read_only
    ) {
    return patch_instance_read_only_body_create_internal (
        read_only
        );
}

void patch_instance_read_only_body_free(patch_instance_read_only_body_t *patch_instance_read_only_body) {
    if(NULL == patch_instance_read_only_body){
        return ;
    }
    if(patch_instance_read_only_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "patch_instance_read_only_body_free");
        return ;
    }
    listEntry_t *listEntry;
    free(patch_instance_read_only_body);
}

cJSON *patch_instance_read_only_body_convertToJSON(patch_instance_read_only_body_t *patch_instance_read_only_body) {
    cJSON *item = cJSON_CreateObject();

    // patch_instance_read_only_body->read_only
    if (!patch_instance_read_only_body->read_only) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "readOnly", patch_instance_read_only_body->read_only) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

patch_instance_read_only_body_t *patch_instance_read_only_body_parseFromJSON(cJSON *patch_instance_read_only_bodyJSON){

    patch_instance_read_only_body_t *patch_instance_read_only_body_local_var = NULL;

    // patch_instance_read_only_body->read_only
    cJSON *read_only = cJSON_GetObjectItemCaseSensitive(patch_instance_read_only_bodyJSON, "readOnly");
    if (cJSON_IsNull(read_only)) {
        read_only = NULL;
    }
    if (!read_only) {
        goto end;
    }

    
    if(!cJSON_IsBool(read_only))
    {
    goto end; //Bool
    }


    patch_instance_read_only_body_local_var = patch_instance_read_only_body_create_internal (
        read_only->valueint
        );

    return patch_instance_read_only_body_local_var;
end:
    return NULL;

}
