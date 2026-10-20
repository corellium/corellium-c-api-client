#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "domain_list_item_projects_inner_instances_inner_usage.h"



static domain_list_item_projects_inner_instances_inner_usage_t *domain_list_item_projects_inner_instances_inner_usage_create_internal(
    double image_bytes
    ) {
    domain_list_item_projects_inner_instances_inner_usage_t *domain_list_item_projects_inner_instances_inner_usage_local_var = malloc(sizeof(domain_list_item_projects_inner_instances_inner_usage_t));
    if (!domain_list_item_projects_inner_instances_inner_usage_local_var) {
        return NULL;
    }
    domain_list_item_projects_inner_instances_inner_usage_local_var->image_bytes = image_bytes;

    domain_list_item_projects_inner_instances_inner_usage_local_var->_library_owned = 1;
    return domain_list_item_projects_inner_instances_inner_usage_local_var;
}

__attribute__((deprecated)) domain_list_item_projects_inner_instances_inner_usage_t *domain_list_item_projects_inner_instances_inner_usage_create(
    double image_bytes
    ) {
    return domain_list_item_projects_inner_instances_inner_usage_create_internal (
        image_bytes
        );
}

void domain_list_item_projects_inner_instances_inner_usage_free(domain_list_item_projects_inner_instances_inner_usage_t *domain_list_item_projects_inner_instances_inner_usage) {
    if(NULL == domain_list_item_projects_inner_instances_inner_usage){
        return ;
    }
    if(domain_list_item_projects_inner_instances_inner_usage->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "domain_list_item_projects_inner_instances_inner_usage_free");
        return ;
    }
    listEntry_t *listEntry;
    free(domain_list_item_projects_inner_instances_inner_usage);
}

cJSON *domain_list_item_projects_inner_instances_inner_usage_convertToJSON(domain_list_item_projects_inner_instances_inner_usage_t *domain_list_item_projects_inner_instances_inner_usage) {
    cJSON *item = cJSON_CreateObject();

    // domain_list_item_projects_inner_instances_inner_usage->image_bytes
    if (!domain_list_item_projects_inner_instances_inner_usage->image_bytes) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "imageBytes", domain_list_item_projects_inner_instances_inner_usage->image_bytes) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

domain_list_item_projects_inner_instances_inner_usage_t *domain_list_item_projects_inner_instances_inner_usage_parseFromJSON(cJSON *domain_list_item_projects_inner_instances_inner_usageJSON){

    domain_list_item_projects_inner_instances_inner_usage_t *domain_list_item_projects_inner_instances_inner_usage_local_var = NULL;

    // domain_list_item_projects_inner_instances_inner_usage->image_bytes
    cJSON *image_bytes = cJSON_GetObjectItemCaseSensitive(domain_list_item_projects_inner_instances_inner_usageJSON, "imageBytes");
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


    domain_list_item_projects_inner_instances_inner_usage_local_var = domain_list_item_projects_inner_instances_inner_usage_create_internal (
        image_bytes->valuedouble
        );

    return domain_list_item_projects_inner_instances_inner_usage_local_var;
end:
    return NULL;

}
