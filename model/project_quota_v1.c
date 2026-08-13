#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "project_quota_v1.h"



static project_quota_v1_t *project_quota_v1_create_internal(
    double cores,
    double instances,
    double ram
    ) {
    project_quota_v1_t *project_quota_v1_local_var = malloc(sizeof(project_quota_v1_t));
    if (!project_quota_v1_local_var) {
        return NULL;
    }
    project_quota_v1_local_var->cores = cores;
    project_quota_v1_local_var->instances = instances;
    project_quota_v1_local_var->ram = ram;

    project_quota_v1_local_var->_library_owned = 1;
    return project_quota_v1_local_var;
}

__attribute__((deprecated)) project_quota_v1_t *project_quota_v1_create(
    double cores,
    double instances,
    double ram
    ) {
    return project_quota_v1_create_internal (
        cores,
        instances,
        ram
        );
}

void project_quota_v1_free(project_quota_v1_t *project_quota_v1) {
    if(NULL == project_quota_v1){
        return ;
    }
    if(project_quota_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "project_quota_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    free(project_quota_v1);
}

cJSON *project_quota_v1_convertToJSON(project_quota_v1_t *project_quota_v1) {
    cJSON *item = cJSON_CreateObject();

    // project_quota_v1->cores
    if(project_quota_v1->cores) {
    if(cJSON_AddNumberToObject(item, "cores", project_quota_v1->cores) == NULL) {
    goto fail; //Numeric
    }
    }


    // project_quota_v1->instances
    if(project_quota_v1->instances) {
    if(cJSON_AddNumberToObject(item, "instances", project_quota_v1->instances) == NULL) {
    goto fail; //Numeric
    }
    }


    // project_quota_v1->ram
    if(project_quota_v1->ram) {
    if(cJSON_AddNumberToObject(item, "ram", project_quota_v1->ram) == NULL) {
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

project_quota_v1_t *project_quota_v1_parseFromJSON(cJSON *project_quota_v1JSON){

    project_quota_v1_t *project_quota_v1_local_var = NULL;

    // project_quota_v1->cores
    cJSON *cores = cJSON_GetObjectItemCaseSensitive(project_quota_v1JSON, "cores");
    if (cJSON_IsNull(cores)) {
        cores = NULL;
    }
    if (cores) { 
    if(!cJSON_IsNumber(cores))
    {
    goto end; //Numeric
    }
    }

    // project_quota_v1->instances
    cJSON *instances = cJSON_GetObjectItemCaseSensitive(project_quota_v1JSON, "instances");
    if (cJSON_IsNull(instances)) {
        instances = NULL;
    }
    if (instances) { 
    if(!cJSON_IsNumber(instances))
    {
    goto end; //Numeric
    }
    }

    // project_quota_v1->ram
    cJSON *ram = cJSON_GetObjectItemCaseSensitive(project_quota_v1JSON, "ram");
    if (cJSON_IsNull(ram)) {
        ram = NULL;
    }
    if (ram) { 
    if(!cJSON_IsNumber(ram))
    {
    goto end; //Numeric
    }
    }


    project_quota_v1_local_var = project_quota_v1_create_internal (
        cores ? cores->valuedouble : 0,
        instances ? instances->valuedouble : 0,
        ram ? ram->valuedouble : 0
        );

    return project_quota_v1_local_var;
end:
    return NULL;

}
