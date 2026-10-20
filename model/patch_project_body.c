#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "patch_project_body.h"



static patch_project_body_t *patch_project_body_create_internal(
    char *name,
    patch_project_body_settings_t *settings,
    patch_project_body_quotas_t *quotas
    ) {
    patch_project_body_t *patch_project_body_local_var = malloc(sizeof(patch_project_body_t));
    if (!patch_project_body_local_var) {
        return NULL;
    }
    patch_project_body_local_var->name = name;
    patch_project_body_local_var->settings = settings;
    patch_project_body_local_var->quotas = quotas;

    patch_project_body_local_var->_library_owned = 1;
    return patch_project_body_local_var;
}

__attribute__((deprecated)) patch_project_body_t *patch_project_body_create(
    char *name,
    patch_project_body_settings_t *settings,
    patch_project_body_quotas_t *quotas
    ) {
    return patch_project_body_create_internal (
        name,
        settings,
        quotas
        );
}

void patch_project_body_free(patch_project_body_t *patch_project_body) {
    if(NULL == patch_project_body){
        return ;
    }
    if(patch_project_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "patch_project_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (patch_project_body->name) {
        free(patch_project_body->name);
        patch_project_body->name = NULL;
    }
    if (patch_project_body->settings) {
        patch_project_body_settings_free(patch_project_body->settings);
        patch_project_body->settings = NULL;
    }
    if (patch_project_body->quotas) {
        patch_project_body_quotas_free(patch_project_body->quotas);
        patch_project_body->quotas = NULL;
    }
    free(patch_project_body);
}

cJSON *patch_project_body_convertToJSON(patch_project_body_t *patch_project_body) {
    cJSON *item = cJSON_CreateObject();

    // patch_project_body->name
    if(patch_project_body->name) {
    if(cJSON_AddStringToObject(item, "name", patch_project_body->name) == NULL) {
    goto fail; //String
    }
    }


    // patch_project_body->settings
    if(patch_project_body->settings) {
    cJSON *settings_local_JSON = patch_project_body_settings_convertToJSON(patch_project_body->settings);
    if(settings_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "settings", settings_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // patch_project_body->quotas
    if(patch_project_body->quotas) {
    cJSON *quotas_local_JSON = patch_project_body_quotas_convertToJSON(patch_project_body->quotas);
    if(quotas_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "quotas", quotas_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

patch_project_body_t *patch_project_body_parseFromJSON(cJSON *patch_project_bodyJSON){

    patch_project_body_t *patch_project_body_local_var = NULL;

    // define the local variable for patch_project_body->settings
    patch_project_body_settings_t *settings_local_nonprim = NULL;

    // define the local variable for patch_project_body->quotas
    patch_project_body_quotas_t *quotas_local_nonprim = NULL;

    // patch_project_body->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(patch_project_bodyJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // patch_project_body->settings
    cJSON *settings = cJSON_GetObjectItemCaseSensitive(patch_project_bodyJSON, "settings");
    if (cJSON_IsNull(settings)) {
        settings = NULL;
    }
    if (settings) { 
    settings_local_nonprim = patch_project_body_settings_parseFromJSON(settings); //nonprimitive
    }

    // patch_project_body->quotas
    cJSON *quotas = cJSON_GetObjectItemCaseSensitive(patch_project_bodyJSON, "quotas");
    if (cJSON_IsNull(quotas)) {
        quotas = NULL;
    }
    if (quotas) { 
    quotas_local_nonprim = patch_project_body_quotas_parseFromJSON(quotas); //nonprimitive
    }


    patch_project_body_local_var = patch_project_body_create_internal (
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        settings ? settings_local_nonprim : NULL,
        quotas ? quotas_local_nonprim : NULL
        );

    return patch_project_body_local_var;
end:
    if (settings_local_nonprim) {
        patch_project_body_settings_free(settings_local_nonprim);
        settings_local_nonprim = NULL;
    }
    if (quotas_local_nonprim) {
        patch_project_body_quotas_free(quotas_local_nonprim);
        quotas_local_nonprim = NULL;
    }
    return NULL;

}
