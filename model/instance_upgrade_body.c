#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "instance_upgrade_body.h"



static instance_upgrade_body_t *instance_upgrade_body_create_internal(
    char *os_version,
    char *os_build,
    char *image_id
    ) {
    instance_upgrade_body_t *instance_upgrade_body_local_var = malloc(sizeof(instance_upgrade_body_t));
    if (!instance_upgrade_body_local_var) {
        return NULL;
    }
    instance_upgrade_body_local_var->os_version = os_version;
    instance_upgrade_body_local_var->os_build = os_build;
    instance_upgrade_body_local_var->image_id = image_id;

    instance_upgrade_body_local_var->_library_owned = 1;
    return instance_upgrade_body_local_var;
}

__attribute__((deprecated)) instance_upgrade_body_t *instance_upgrade_body_create(
    char *os_version,
    char *os_build,
    char *image_id
    ) {
    return instance_upgrade_body_create_internal (
        os_version,
        os_build,
        image_id
        );
}

void instance_upgrade_body_free(instance_upgrade_body_t *instance_upgrade_body) {
    if(NULL == instance_upgrade_body){
        return ;
    }
    if(instance_upgrade_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "instance_upgrade_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (instance_upgrade_body->os_version) {
        free(instance_upgrade_body->os_version);
        instance_upgrade_body->os_version = NULL;
    }
    if (instance_upgrade_body->os_build) {
        free(instance_upgrade_body->os_build);
        instance_upgrade_body->os_build = NULL;
    }
    if (instance_upgrade_body->image_id) {
        free(instance_upgrade_body->image_id);
        instance_upgrade_body->image_id = NULL;
    }
    free(instance_upgrade_body);
}

cJSON *instance_upgrade_body_convertToJSON(instance_upgrade_body_t *instance_upgrade_body) {
    cJSON *item = cJSON_CreateObject();

    // instance_upgrade_body->os_version
    if (!instance_upgrade_body->os_version) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "osVersion", instance_upgrade_body->os_version) == NULL) {
    goto fail; //String
    }


    // instance_upgrade_body->os_build
    if(instance_upgrade_body->os_build) {
    if(cJSON_AddStringToObject(item, "osBuild", instance_upgrade_body->os_build) == NULL) {
    goto fail; //String
    }
    }


    // instance_upgrade_body->image_id
    if(instance_upgrade_body->image_id) {
    if(cJSON_AddStringToObject(item, "imageId", instance_upgrade_body->image_id) == NULL) {
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

instance_upgrade_body_t *instance_upgrade_body_parseFromJSON(cJSON *instance_upgrade_bodyJSON){

    instance_upgrade_body_t *instance_upgrade_body_local_var = NULL;

    // instance_upgrade_body->os_version
    cJSON *os_version = cJSON_GetObjectItemCaseSensitive(instance_upgrade_bodyJSON, "osVersion");
    if (cJSON_IsNull(os_version)) {
        os_version = NULL;
    }
    if (!os_version) {
        goto end;
    }

    
    if(!cJSON_IsString(os_version))
    {
    goto end; //String
    }

    // instance_upgrade_body->os_build
    cJSON *os_build = cJSON_GetObjectItemCaseSensitive(instance_upgrade_bodyJSON, "osBuild");
    if (cJSON_IsNull(os_build)) {
        os_build = NULL;
    }
    if (os_build) { 
    if(!cJSON_IsString(os_build) && !cJSON_IsNull(os_build))
    {
    goto end; //String
    }
    }

    // instance_upgrade_body->image_id
    cJSON *image_id = cJSON_GetObjectItemCaseSensitive(instance_upgrade_bodyJSON, "imageId");
    if (cJSON_IsNull(image_id)) {
        image_id = NULL;
    }
    if (image_id) { 
    if(!cJSON_IsString(image_id) && !cJSON_IsNull(image_id))
    {
    goto end; //String
    }
    }


    instance_upgrade_body_local_var = instance_upgrade_body_create_internal (
        strdup(os_version->valuestring),
        os_build && !cJSON_IsNull(os_build) ? strdup(os_build->valuestring) : NULL,
        image_id && !cJSON_IsNull(image_id) ? strdup(image_id->valuestring) : NULL
        );

    return instance_upgrade_body_local_var;
end:
    return NULL;

}
