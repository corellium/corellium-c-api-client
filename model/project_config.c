#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "project_config.h"



static project_config_t *project_config_create_internal(
    double color
    ) {
    project_config_t *project_config_local_var = malloc(sizeof(project_config_t));
    if (!project_config_local_var) {
        return NULL;
    }
    project_config_local_var->color = color;

    project_config_local_var->_library_owned = 1;
    return project_config_local_var;
}

__attribute__((deprecated)) project_config_t *project_config_create(
    double color
    ) {
    return project_config_create_internal (
        color
        );
}

void project_config_free(project_config_t *project_config) {
    if(NULL == project_config){
        return ;
    }
    if(project_config->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "project_config_free");
        return ;
    }
    listEntry_t *listEntry;
    free(project_config);
}

cJSON *project_config_convertToJSON(project_config_t *project_config) {
    cJSON *item = cJSON_CreateObject();

    // project_config->color
    if(project_config->color) {
    if(cJSON_AddNumberToObject(item, "color", project_config->color) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

project_config_t *project_config_parseFromJSON(cJSON *project_configJSON){

    project_config_t *project_config_local_var = NULL;

    // project_config->color
    cJSON *color = cJSON_GetObjectItemCaseSensitive(project_configJSON, "color");
    if (cJSON_IsNull(color)) {
        color = NULL;
    }
    if (color) { 
    if(!cJSON_IsNumber(color))
    {
    goto end; //Numeric
    }
    }


    project_config_local_var = project_config_create_internal (
        color ? color->valuedouble : 0
        );

    return project_config_local_var;
end:
    return NULL;

}
