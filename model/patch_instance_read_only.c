#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "patch_instance_read_only.h"



static patch_instance_read_only_t *patch_instance_read_only_create_internal(
    char *read_only
    ) {
    patch_instance_read_only_t *patch_instance_read_only_local_var = malloc(sizeof(patch_instance_read_only_t));
    if (!patch_instance_read_only_local_var) {
        return NULL;
    }
    patch_instance_read_only_local_var->read_only = read_only;

    patch_instance_read_only_local_var->_library_owned = 1;
    return patch_instance_read_only_local_var;
}

__attribute__((deprecated)) patch_instance_read_only_t *patch_instance_read_only_create(
    char *read_only
    ) {
    return patch_instance_read_only_create_internal (
        read_only
        );
}

void patch_instance_read_only_free(patch_instance_read_only_t *patch_instance_read_only) {
    if(NULL == patch_instance_read_only){
        return ;
    }
    if(patch_instance_read_only->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "patch_instance_read_only_free");
        return ;
    }
    listEntry_t *listEntry;
    if (patch_instance_read_only->read_only) {
        free(patch_instance_read_only->read_only);
        patch_instance_read_only->read_only = NULL;
    }
    free(patch_instance_read_only);
}

cJSON *patch_instance_read_only_convertToJSON(patch_instance_read_only_t *patch_instance_read_only) {
    cJSON *item = cJSON_CreateObject();

    // patch_instance_read_only->read_only
    if(patch_instance_read_only->read_only) {
    if(cJSON_AddStringToObject(item, "readOnly", patch_instance_read_only->read_only) == NULL) {
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

patch_instance_read_only_t *patch_instance_read_only_parseFromJSON(cJSON *patch_instance_read_onlyJSON){

    patch_instance_read_only_t *patch_instance_read_only_local_var = NULL;

    // patch_instance_read_only->read_only
    cJSON *read_only = cJSON_GetObjectItemCaseSensitive(patch_instance_read_onlyJSON, "readOnly");
    if (cJSON_IsNull(read_only)) {
        read_only = NULL;
    }
    if (read_only) { 
    if(!cJSON_IsString(read_only) && !cJSON_IsNull(read_only))
    {
    goto end; //String
    }
    }


    patch_instance_read_only_local_var = patch_instance_read_only_create_internal (
        read_only && !cJSON_IsNull(read_only) ? strdup(read_only->valuestring) : NULL
        );

    return patch_instance_read_only_local_var;
end:
    return NULL;

}
