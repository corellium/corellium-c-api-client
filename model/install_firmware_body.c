#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "install_firmware_body.h"



static install_firmware_body_t *install_firmware_body_create_internal(
    char *image_id,
    char *filename
    ) {
    install_firmware_body_t *install_firmware_body_local_var = malloc(sizeof(install_firmware_body_t));
    if (!install_firmware_body_local_var) {
        return NULL;
    }
    install_firmware_body_local_var->image_id = image_id;
    install_firmware_body_local_var->filename = filename;

    install_firmware_body_local_var->_library_owned = 1;
    return install_firmware_body_local_var;
}

__attribute__((deprecated)) install_firmware_body_t *install_firmware_body_create(
    char *image_id,
    char *filename
    ) {
    return install_firmware_body_create_internal (
        image_id,
        filename
        );
}

void install_firmware_body_free(install_firmware_body_t *install_firmware_body) {
    if(NULL == install_firmware_body){
        return ;
    }
    if(install_firmware_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "install_firmware_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (install_firmware_body->image_id) {
        free(install_firmware_body->image_id);
        install_firmware_body->image_id = NULL;
    }
    if (install_firmware_body->filename) {
        free(install_firmware_body->filename);
        install_firmware_body->filename = NULL;
    }
    free(install_firmware_body);
}

cJSON *install_firmware_body_convertToJSON(install_firmware_body_t *install_firmware_body) {
    cJSON *item = cJSON_CreateObject();

    // install_firmware_body->image_id
    if (!install_firmware_body->image_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "imageId", install_firmware_body->image_id) == NULL) {
    goto fail; //String
    }


    // install_firmware_body->filename
    if(install_firmware_body->filename) {
    if(cJSON_AddStringToObject(item, "filename", install_firmware_body->filename) == NULL) {
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

install_firmware_body_t *install_firmware_body_parseFromJSON(cJSON *install_firmware_bodyJSON){

    install_firmware_body_t *install_firmware_body_local_var = NULL;

    // install_firmware_body->image_id
    cJSON *image_id = cJSON_GetObjectItemCaseSensitive(install_firmware_bodyJSON, "imageId");
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

    // install_firmware_body->filename
    cJSON *filename = cJSON_GetObjectItemCaseSensitive(install_firmware_bodyJSON, "filename");
    if (cJSON_IsNull(filename)) {
        filename = NULL;
    }
    if (filename) { 
    if(!cJSON_IsString(filename) && !cJSON_IsNull(filename))
    {
    goto end; //String
    }
    }


    install_firmware_body_local_var = install_firmware_body_create_internal (
        strdup(image_id->valuestring),
        filename && !cJSON_IsNull(filename) ? strdup(filename->valuestring) : NULL
        );

    return install_firmware_body_local_var;
end:
    return NULL;

}
