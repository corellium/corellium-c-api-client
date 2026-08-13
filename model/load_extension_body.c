#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "load_extension_body.h"



static load_extension_body_t *load_extension_body_create_internal(
    char *image_id
    ) {
    load_extension_body_t *load_extension_body_local_var = malloc(sizeof(load_extension_body_t));
    if (!load_extension_body_local_var) {
        return NULL;
    }
    load_extension_body_local_var->image_id = image_id;

    load_extension_body_local_var->_library_owned = 1;
    return load_extension_body_local_var;
}

__attribute__((deprecated)) load_extension_body_t *load_extension_body_create(
    char *image_id
    ) {
    return load_extension_body_create_internal (
        image_id
        );
}

void load_extension_body_free(load_extension_body_t *load_extension_body) {
    if(NULL == load_extension_body){
        return ;
    }
    if(load_extension_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "load_extension_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (load_extension_body->image_id) {
        free(load_extension_body->image_id);
        load_extension_body->image_id = NULL;
    }
    free(load_extension_body);
}

cJSON *load_extension_body_convertToJSON(load_extension_body_t *load_extension_body) {
    cJSON *item = cJSON_CreateObject();

    // load_extension_body->image_id
    if (!load_extension_body->image_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "imageId", load_extension_body->image_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

load_extension_body_t *load_extension_body_parseFromJSON(cJSON *load_extension_bodyJSON){

    load_extension_body_t *load_extension_body_local_var = NULL;

    // load_extension_body->image_id
    cJSON *image_id = cJSON_GetObjectItemCaseSensitive(load_extension_bodyJSON, "imageId");
    if (cJSON_IsNull(image_id)) {
        image_id = NULL;
    }
    if (!image_id) {
        goto end;
    }

    
    if(!cJSON_IsString(image_id))
    {
    goto end; //String
    }


    load_extension_body_local_var = load_extension_body_create_internal (
        strdup(image_id->valuestring)
        );

    return load_extension_body_local_var;
end:
    return NULL;

}
