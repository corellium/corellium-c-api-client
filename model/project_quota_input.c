#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "project_quota_input.h"



static project_quota_input_t *project_quota_input_create_internal(
    double cores,
    double instances,
    double ram
    ) {
    project_quota_input_t *project_quota_input_local_var = malloc(sizeof(project_quota_input_t));
    if (!project_quota_input_local_var) {
        return NULL;
    }
    project_quota_input_local_var->cores = cores;
    project_quota_input_local_var->instances = instances;
    project_quota_input_local_var->ram = ram;

    project_quota_input_local_var->_library_owned = 1;
    return project_quota_input_local_var;
}

__attribute__((deprecated)) project_quota_input_t *project_quota_input_create(
    double cores,
    double instances,
    double ram
    ) {
    return project_quota_input_create_internal (
        cores,
        instances,
        ram
        );
}

void project_quota_input_free(project_quota_input_t *project_quota_input) {
    if(NULL == project_quota_input){
        return ;
    }
    if(project_quota_input->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "project_quota_input_free");
        return ;
    }
    listEntry_t *listEntry;
    free(project_quota_input);
}

cJSON *project_quota_input_convertToJSON(project_quota_input_t *project_quota_input) {
    cJSON *item = cJSON_CreateObject();

    // project_quota_input->cores
    if (!project_quota_input->cores) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "cores", project_quota_input->cores) == NULL) {
    goto fail; //Numeric
    }


    // project_quota_input->instances
    if(project_quota_input->instances) {
    if(cJSON_AddNumberToObject(item, "instances", project_quota_input->instances) == NULL) {
    goto fail; //Numeric
    }
    }


    // project_quota_input->ram
    if(project_quota_input->ram) {
    if(cJSON_AddNumberToObject(item, "ram", project_quota_input->ram) == NULL) {
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

project_quota_input_t *project_quota_input_parseFromJSON(cJSON *project_quota_inputJSON){

    project_quota_input_t *project_quota_input_local_var = NULL;

    // project_quota_input->cores
    cJSON *cores = cJSON_GetObjectItemCaseSensitive(project_quota_inputJSON, "cores");
    if (cJSON_IsNull(cores)) {
        cores = NULL;
    }
    if (!cores) {
        goto end;
    }

    
    if(!cJSON_IsNumber(cores))
    {
    goto end; //Numeric
    }

    // project_quota_input->instances
    cJSON *instances = cJSON_GetObjectItemCaseSensitive(project_quota_inputJSON, "instances");
    if (cJSON_IsNull(instances)) {
        instances = NULL;
    }
    if (instances) { 
    if(!cJSON_IsNumber(instances))
    {
    goto end; //Numeric
    }
    }

    // project_quota_input->ram
    cJSON *ram = cJSON_GetObjectItemCaseSensitive(project_quota_inputJSON, "ram");
    if (cJSON_IsNull(ram)) {
        ram = NULL;
    }
    if (ram) { 
    if(!cJSON_IsNumber(ram))
    {
    goto end; //Numeric
    }
    }


    project_quota_input_local_var = project_quota_input_create_internal (
        cores->valuedouble,
        instances ? instances->valuedouble : 0,
        ram ? ram->valuedouble : 0
        );

    return project_quota_input_local_var;
end:
    return NULL;

}
