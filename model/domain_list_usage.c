#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "domain_list_usage.h"



static domain_list_usage_t *domain_list_usage_create_internal(
    double active_instances,
    double image_bytes,
    double cores,
    double instances,
    double ram,
    double gpu,
    double reserved_cores
    ) {
    domain_list_usage_t *domain_list_usage_local_var = malloc(sizeof(domain_list_usage_t));
    if (!domain_list_usage_local_var) {
        return NULL;
    }
    domain_list_usage_local_var->active_instances = active_instances;
    domain_list_usage_local_var->image_bytes = image_bytes;
    domain_list_usage_local_var->cores = cores;
    domain_list_usage_local_var->instances = instances;
    domain_list_usage_local_var->ram = ram;
    domain_list_usage_local_var->gpu = gpu;
    domain_list_usage_local_var->reserved_cores = reserved_cores;

    domain_list_usage_local_var->_library_owned = 1;
    return domain_list_usage_local_var;
}

__attribute__((deprecated)) domain_list_usage_t *domain_list_usage_create(
    double active_instances,
    double image_bytes,
    double cores,
    double instances,
    double ram,
    double gpu,
    double reserved_cores
    ) {
    return domain_list_usage_create_internal (
        active_instances,
        image_bytes,
        cores,
        instances,
        ram,
        gpu,
        reserved_cores
        );
}

void domain_list_usage_free(domain_list_usage_t *domain_list_usage) {
    if(NULL == domain_list_usage){
        return ;
    }
    if(domain_list_usage->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "domain_list_usage_free");
        return ;
    }
    listEntry_t *listEntry;
    free(domain_list_usage);
}

cJSON *domain_list_usage_convertToJSON(domain_list_usage_t *domain_list_usage) {
    cJSON *item = cJSON_CreateObject();

    // domain_list_usage->active_instances
    if (!domain_list_usage->active_instances) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "activeInstances", domain_list_usage->active_instances) == NULL) {
    goto fail; //Numeric
    }


    // domain_list_usage->image_bytes
    if (!domain_list_usage->image_bytes) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "imageBytes", domain_list_usage->image_bytes) == NULL) {
    goto fail; //Numeric
    }


    // domain_list_usage->cores
    if (!domain_list_usage->cores) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "cores", domain_list_usage->cores) == NULL) {
    goto fail; //Numeric
    }


    // domain_list_usage->instances
    if (!domain_list_usage->instances) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "instances", domain_list_usage->instances) == NULL) {
    goto fail; //Numeric
    }


    // domain_list_usage->ram
    if (!domain_list_usage->ram) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "ram", domain_list_usage->ram) == NULL) {
    goto fail; //Numeric
    }


    // domain_list_usage->gpu
    if (!domain_list_usage->gpu) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "gpu", domain_list_usage->gpu) == NULL) {
    goto fail; //Numeric
    }


    // domain_list_usage->reserved_cores
    if(domain_list_usage->reserved_cores) {
    if(cJSON_AddNumberToObject(item, "reservedCores", domain_list_usage->reserved_cores) == NULL) {
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

domain_list_usage_t *domain_list_usage_parseFromJSON(cJSON *domain_list_usageJSON){

    domain_list_usage_t *domain_list_usage_local_var = NULL;

    // domain_list_usage->active_instances
    cJSON *active_instances = cJSON_GetObjectItemCaseSensitive(domain_list_usageJSON, "activeInstances");
    if (cJSON_IsNull(active_instances)) {
        active_instances = NULL;
    }
    if (!active_instances) {
        goto end;
    }

    
    if(!cJSON_IsNumber(active_instances))
    {
    goto end; //Numeric
    }

    // domain_list_usage->image_bytes
    cJSON *image_bytes = cJSON_GetObjectItemCaseSensitive(domain_list_usageJSON, "imageBytes");
    if (cJSON_IsNull(image_bytes)) {
        image_bytes = NULL;
    }
    if (!image_bytes) {
        goto end;
    }

    
    if(!cJSON_IsNumber(image_bytes))
    {
    goto end; //Numeric
    }

    // domain_list_usage->cores
    cJSON *cores = cJSON_GetObjectItemCaseSensitive(domain_list_usageJSON, "cores");
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

    // domain_list_usage->instances
    cJSON *instances = cJSON_GetObjectItemCaseSensitive(domain_list_usageJSON, "instances");
    if (cJSON_IsNull(instances)) {
        instances = NULL;
    }
    if (!instances) {
        goto end;
    }

    
    if(!cJSON_IsNumber(instances))
    {
    goto end; //Numeric
    }

    // domain_list_usage->ram
    cJSON *ram = cJSON_GetObjectItemCaseSensitive(domain_list_usageJSON, "ram");
    if (cJSON_IsNull(ram)) {
        ram = NULL;
    }
    if (!ram) {
        goto end;
    }

    
    if(!cJSON_IsNumber(ram))
    {
    goto end; //Numeric
    }

    // domain_list_usage->gpu
    cJSON *gpu = cJSON_GetObjectItemCaseSensitive(domain_list_usageJSON, "gpu");
    if (cJSON_IsNull(gpu)) {
        gpu = NULL;
    }
    if (!gpu) {
        goto end;
    }

    
    if(!cJSON_IsNumber(gpu))
    {
    goto end; //Numeric
    }

    // domain_list_usage->reserved_cores
    cJSON *reserved_cores = cJSON_GetObjectItemCaseSensitive(domain_list_usageJSON, "reservedCores");
    if (cJSON_IsNull(reserved_cores)) {
        reserved_cores = NULL;
    }
    if (reserved_cores) { 
    if(!cJSON_IsNumber(reserved_cores))
    {
    goto end; //Numeric
    }
    }


    domain_list_usage_local_var = domain_list_usage_create_internal (
        active_instances->valuedouble,
        image_bytes->valuedouble,
        cores->valuedouble,
        instances->valuedouble,
        ram->valuedouble,
        gpu->valuedouble,
        reserved_cores ? reserved_cores->valuedouble : 0
        );

    return domain_list_usage_local_var;
end:
    return NULL;

}
