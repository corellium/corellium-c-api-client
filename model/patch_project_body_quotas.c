#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "patch_project_body_quotas.h"



static patch_project_body_quotas_t *patch_project_body_quotas_create_internal(
    double cores,
    double instances,
    double ram
    ) {
    patch_project_body_quotas_t *patch_project_body_quotas_local_var = malloc(sizeof(patch_project_body_quotas_t));
    if (!patch_project_body_quotas_local_var) {
        return NULL;
    }
    patch_project_body_quotas_local_var->cores = cores;
    patch_project_body_quotas_local_var->instances = instances;
    patch_project_body_quotas_local_var->ram = ram;

    patch_project_body_quotas_local_var->_library_owned = 1;
    return patch_project_body_quotas_local_var;
}

__attribute__((deprecated)) patch_project_body_quotas_t *patch_project_body_quotas_create(
    double cores,
    double instances,
    double ram
    ) {
    return patch_project_body_quotas_create_internal (
        cores,
        instances,
        ram
        );
}

void patch_project_body_quotas_free(patch_project_body_quotas_t *patch_project_body_quotas) {
    if(NULL == patch_project_body_quotas){
        return ;
    }
    if(patch_project_body_quotas->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "patch_project_body_quotas_free");
        return ;
    }
    listEntry_t *listEntry;
    free(patch_project_body_quotas);
}

cJSON *patch_project_body_quotas_convertToJSON(patch_project_body_quotas_t *patch_project_body_quotas) {
    cJSON *item = cJSON_CreateObject();

    // patch_project_body_quotas->cores
    if (!patch_project_body_quotas->cores) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "cores", patch_project_body_quotas->cores) == NULL) {
    goto fail; //Numeric
    }


    // patch_project_body_quotas->instances
    if(patch_project_body_quotas->instances) {
    if(cJSON_AddNumberToObject(item, "instances", patch_project_body_quotas->instances) == NULL) {
    goto fail; //Numeric
    }
    }


    // patch_project_body_quotas->ram
    if(patch_project_body_quotas->ram) {
    if(cJSON_AddNumberToObject(item, "ram", patch_project_body_quotas->ram) == NULL) {
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

patch_project_body_quotas_t *patch_project_body_quotas_parseFromJSON(cJSON *patch_project_body_quotasJSON){

    patch_project_body_quotas_t *patch_project_body_quotas_local_var = NULL;

    // patch_project_body_quotas->cores
    cJSON *cores = cJSON_GetObjectItemCaseSensitive(patch_project_body_quotasJSON, "cores");
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

    // patch_project_body_quotas->instances
    cJSON *instances = cJSON_GetObjectItemCaseSensitive(patch_project_body_quotasJSON, "instances");
    if (cJSON_IsNull(instances)) {
        instances = NULL;
    }
    if (instances) { 
    if(!cJSON_IsNumber(instances))
    {
    goto end; //Numeric
    }
    }

    // patch_project_body_quotas->ram
    cJSON *ram = cJSON_GetObjectItemCaseSensitive(patch_project_body_quotasJSON, "ram");
    if (cJSON_IsNull(ram)) {
        ram = NULL;
    }
    if (ram) { 
    if(!cJSON_IsNumber(ram))
    {
    goto end; //Numeric
    }
    }


    patch_project_body_quotas_local_var = patch_project_body_quotas_create_internal (
        cores->valuedouble,
        instances ? instances->valuedouble : 0,
        ram ? ram->valuedouble : 0
        );

    return patch_project_body_quotas_local_var;
end:
    return NULL;

}
