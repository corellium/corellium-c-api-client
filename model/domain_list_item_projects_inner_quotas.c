#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "domain_list_item_projects_inner_quotas.h"



static domain_list_item_projects_inner_quotas_t *domain_list_item_projects_inner_quotas_create_internal(
    double cores,
    double instances,
    double ram
    ) {
    domain_list_item_projects_inner_quotas_t *domain_list_item_projects_inner_quotas_local_var = malloc(sizeof(domain_list_item_projects_inner_quotas_t));
    if (!domain_list_item_projects_inner_quotas_local_var) {
        return NULL;
    }
    domain_list_item_projects_inner_quotas_local_var->cores = cores;
    domain_list_item_projects_inner_quotas_local_var->instances = instances;
    domain_list_item_projects_inner_quotas_local_var->ram = ram;

    domain_list_item_projects_inner_quotas_local_var->_library_owned = 1;
    return domain_list_item_projects_inner_quotas_local_var;
}

__attribute__((deprecated)) domain_list_item_projects_inner_quotas_t *domain_list_item_projects_inner_quotas_create(
    double cores,
    double instances,
    double ram
    ) {
    return domain_list_item_projects_inner_quotas_create_internal (
        cores,
        instances,
        ram
        );
}

void domain_list_item_projects_inner_quotas_free(domain_list_item_projects_inner_quotas_t *domain_list_item_projects_inner_quotas) {
    if(NULL == domain_list_item_projects_inner_quotas){
        return ;
    }
    if(domain_list_item_projects_inner_quotas->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "domain_list_item_projects_inner_quotas_free");
        return ;
    }
    listEntry_t *listEntry;
    free(domain_list_item_projects_inner_quotas);
}

cJSON *domain_list_item_projects_inner_quotas_convertToJSON(domain_list_item_projects_inner_quotas_t *domain_list_item_projects_inner_quotas) {
    cJSON *item = cJSON_CreateObject();

    // domain_list_item_projects_inner_quotas->cores
    if (!domain_list_item_projects_inner_quotas->cores) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "cores", domain_list_item_projects_inner_quotas->cores) == NULL) {
    goto fail; //Numeric
    }


    // domain_list_item_projects_inner_quotas->instances
    if (!domain_list_item_projects_inner_quotas->instances) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "instances", domain_list_item_projects_inner_quotas->instances) == NULL) {
    goto fail; //Numeric
    }


    // domain_list_item_projects_inner_quotas->ram
    if (!domain_list_item_projects_inner_quotas->ram) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "ram", domain_list_item_projects_inner_quotas->ram) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

domain_list_item_projects_inner_quotas_t *domain_list_item_projects_inner_quotas_parseFromJSON(cJSON *domain_list_item_projects_inner_quotasJSON){

    domain_list_item_projects_inner_quotas_t *domain_list_item_projects_inner_quotas_local_var = NULL;

    // domain_list_item_projects_inner_quotas->cores
    cJSON *cores = cJSON_GetObjectItemCaseSensitive(domain_list_item_projects_inner_quotasJSON, "cores");
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

    // domain_list_item_projects_inner_quotas->instances
    cJSON *instances = cJSON_GetObjectItemCaseSensitive(domain_list_item_projects_inner_quotasJSON, "instances");
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

    // domain_list_item_projects_inner_quotas->ram
    cJSON *ram = cJSON_GetObjectItemCaseSensitive(domain_list_item_projects_inner_quotasJSON, "ram");
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


    domain_list_item_projects_inner_quotas_local_var = domain_list_item_projects_inner_quotas_create_internal (
        cores->valuedouble,
        instances->valuedouble,
        ram->valuedouble
        );

    return domain_list_item_projects_inner_quotas_local_var;
end:
    return NULL;

}
