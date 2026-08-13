#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "project_usage_v1.h"



static project_usage_v1_t *project_usage_v1_create_internal(
    double cores,
    double instances,
    double ram,
    double gpu
    ) {
    project_usage_v1_t *project_usage_v1_local_var = malloc(sizeof(project_usage_v1_t));
    if (!project_usage_v1_local_var) {
        return NULL;
    }
    project_usage_v1_local_var->cores = cores;
    project_usage_v1_local_var->instances = instances;
    project_usage_v1_local_var->ram = ram;
    project_usage_v1_local_var->gpu = gpu;

    project_usage_v1_local_var->_library_owned = 1;
    return project_usage_v1_local_var;
}

__attribute__((deprecated)) project_usage_v1_t *project_usage_v1_create(
    double cores,
    double instances,
    double ram,
    double gpu
    ) {
    return project_usage_v1_create_internal (
        cores,
        instances,
        ram,
        gpu
        );
}

void project_usage_v1_free(project_usage_v1_t *project_usage_v1) {
    if(NULL == project_usage_v1){
        return ;
    }
    if(project_usage_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "project_usage_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    free(project_usage_v1);
}

cJSON *project_usage_v1_convertToJSON(project_usage_v1_t *project_usage_v1) {
    cJSON *item = cJSON_CreateObject();

    // project_usage_v1->cores
    if(project_usage_v1->cores) {
    if(cJSON_AddNumberToObject(item, "cores", project_usage_v1->cores) == NULL) {
    goto fail; //Numeric
    }
    }


    // project_usage_v1->instances
    if(project_usage_v1->instances) {
    if(cJSON_AddNumberToObject(item, "instances", project_usage_v1->instances) == NULL) {
    goto fail; //Numeric
    }
    }


    // project_usage_v1->ram
    if(project_usage_v1->ram) {
    if(cJSON_AddNumberToObject(item, "ram", project_usage_v1->ram) == NULL) {
    goto fail; //Numeric
    }
    }


    // project_usage_v1->gpu
    if(project_usage_v1->gpu) {
    if(cJSON_AddNumberToObject(item, "gpu", project_usage_v1->gpu) == NULL) {
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

project_usage_v1_t *project_usage_v1_parseFromJSON(cJSON *project_usage_v1JSON){

    project_usage_v1_t *project_usage_v1_local_var = NULL;

    // project_usage_v1->cores
    cJSON *cores = cJSON_GetObjectItemCaseSensitive(project_usage_v1JSON, "cores");
    if (cJSON_IsNull(cores)) {
        cores = NULL;
    }
    if (cores) { 
    if(!cJSON_IsNumber(cores))
    {
    goto end; //Numeric
    }
    }

    // project_usage_v1->instances
    cJSON *instances = cJSON_GetObjectItemCaseSensitive(project_usage_v1JSON, "instances");
    if (cJSON_IsNull(instances)) {
        instances = NULL;
    }
    if (instances) { 
    if(!cJSON_IsNumber(instances))
    {
    goto end; //Numeric
    }
    }

    // project_usage_v1->ram
    cJSON *ram = cJSON_GetObjectItemCaseSensitive(project_usage_v1JSON, "ram");
    if (cJSON_IsNull(ram)) {
        ram = NULL;
    }
    if (ram) { 
    if(!cJSON_IsNumber(ram))
    {
    goto end; //Numeric
    }
    }

    // project_usage_v1->gpu
    cJSON *gpu = cJSON_GetObjectItemCaseSensitive(project_usage_v1JSON, "gpu");
    if (cJSON_IsNull(gpu)) {
        gpu = NULL;
    }
    if (gpu) { 
    if(!cJSON_IsNumber(gpu))
    {
    goto end; //Numeric
    }
    }


    project_usage_v1_local_var = project_usage_v1_create_internal (
        cores ? cores->valuedouble : 0,
        instances ? instances->valuedouble : 0,
        ram ? ram->valuedouble : 0,
        gpu ? gpu->valuedouble : 0
        );

    return project_usage_v1_local_var;
end:
    return NULL;

}
