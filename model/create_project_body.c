#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_project_body.h"



static create_project_body_t *create_project_body_create_internal(
    char *name,
    double color,
    create_project_body_settings_t *settings,
    project_quota_input_t *quotas
    ) {
    create_project_body_t *create_project_body_local_var = malloc(sizeof(create_project_body_t));
    if (!create_project_body_local_var) {
        return NULL;
    }
    create_project_body_local_var->name = name;
    create_project_body_local_var->color = color;
    create_project_body_local_var->settings = settings;
    create_project_body_local_var->quotas = quotas;

    create_project_body_local_var->_library_owned = 1;
    return create_project_body_local_var;
}

__attribute__((deprecated)) create_project_body_t *create_project_body_create(
    char *name,
    double color,
    create_project_body_settings_t *settings,
    project_quota_input_t *quotas
    ) {
    return create_project_body_create_internal (
        name,
        color,
        settings,
        quotas
        );
}

void create_project_body_free(create_project_body_t *create_project_body) {
    if(NULL == create_project_body){
        return ;
    }
    if(create_project_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "create_project_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (create_project_body->name) {
        free(create_project_body->name);
        create_project_body->name = NULL;
    }
    if (create_project_body->settings) {
        create_project_body_settings_free(create_project_body->settings);
        create_project_body->settings = NULL;
    }
    if (create_project_body->quotas) {
        project_quota_input_free(create_project_body->quotas);
        create_project_body->quotas = NULL;
    }
    free(create_project_body);
}

cJSON *create_project_body_convertToJSON(create_project_body_t *create_project_body) {
    cJSON *item = cJSON_CreateObject();

    // create_project_body->name
    if (!create_project_body->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", create_project_body->name) == NULL) {
    goto fail; //String
    }


    // create_project_body->color
    if(create_project_body->color) {
    if(cJSON_AddNumberToObject(item, "color", create_project_body->color) == NULL) {
    goto fail; //Numeric
    }
    }


    // create_project_body->settings
    if(create_project_body->settings) {
    cJSON *settings_local_JSON = create_project_body_settings_convertToJSON(create_project_body->settings);
    if(settings_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "settings", settings_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // create_project_body->quotas
    if(create_project_body->quotas) {
    cJSON *quotas_local_JSON = project_quota_input_convertToJSON(create_project_body->quotas);
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

create_project_body_t *create_project_body_parseFromJSON(cJSON *create_project_bodyJSON){

    create_project_body_t *create_project_body_local_var = NULL;

    // define the local variable for create_project_body->settings
    create_project_body_settings_t *settings_local_nonprim = NULL;

    // define the local variable for create_project_body->quotas
    project_quota_input_t *quotas_local_nonprim = NULL;

    // create_project_body->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(create_project_bodyJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // create_project_body->color
    cJSON *color = cJSON_GetObjectItemCaseSensitive(create_project_bodyJSON, "color");
    if (cJSON_IsNull(color)) {
        color = NULL;
    }
    if (color) { 
    if(!cJSON_IsNumber(color))
    {
    goto end; //Numeric
    }
    }

    // create_project_body->settings
    cJSON *settings = cJSON_GetObjectItemCaseSensitive(create_project_bodyJSON, "settings");
    if (cJSON_IsNull(settings)) {
        settings = NULL;
    }
    if (settings) { 
    settings_local_nonprim = create_project_body_settings_parseFromJSON(settings); //nonprimitive
    }

    // create_project_body->quotas
    cJSON *quotas = cJSON_GetObjectItemCaseSensitive(create_project_bodyJSON, "quotas");
    if (cJSON_IsNull(quotas)) {
        quotas = NULL;
    }
    if (quotas) { 
    quotas_local_nonprim = project_quota_input_parseFromJSON(quotas); //nonprimitive
    }


    create_project_body_local_var = create_project_body_create_internal (
        strdup(name->valuestring),
        color ? color->valuedouble : 0,
        settings ? settings_local_nonprim : NULL,
        quotas ? quotas_local_nonprim : NULL
        );

    return create_project_body_local_var;
end:
    if (settings_local_nonprim) {
        create_project_body_settings_free(settings_local_nonprim);
        settings_local_nonprim = NULL;
    }
    if (quotas_local_nonprim) {
        project_quota_input_free(quotas_local_nonprim);
        quotas_local_nonprim = NULL;
    }
    return NULL;

}
