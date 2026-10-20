#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "domain_info.h"



static domain_info_t *domain_info_create_internal(
    domain_info_domain_info_t *domain_info
    ) {
    domain_info_t *domain_info_local_var = malloc(sizeof(domain_info_t));
    if (!domain_info_local_var) {
        return NULL;
    }
    domain_info_local_var->domain_info = domain_info;

    domain_info_local_var->_library_owned = 1;
    return domain_info_local_var;
}

__attribute__((deprecated)) domain_info_t *domain_info_create(
    domain_info_domain_info_t *domain_info
    ) {
    return domain_info_create_internal (
        domain_info
        );
}

void domain_info_free(domain_info_t *domain_info) {
    if(NULL == domain_info){
        return ;
    }
    if(domain_info->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "domain_info_free");
        return ;
    }
    listEntry_t *listEntry;
    if (domain_info->domain_info) {
        domain_info_domain_info_free(domain_info->domain_info);
        domain_info->domain_info = NULL;
    }
    free(domain_info);
}

cJSON *domain_info_convertToJSON(domain_info_t *domain_info) {
    cJSON *item = cJSON_CreateObject();

    // domain_info->domain_info
    if (!domain_info->domain_info) {
        goto fail;
    }
    cJSON *domain_info_local_JSON = domain_info_domain_info_convertToJSON(domain_info->domain_info);
    if(domain_info_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "domainInfo", domain_info_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

domain_info_t *domain_info_parseFromJSON(cJSON *domain_infoJSON){

    domain_info_t *domain_info_local_var = NULL;

    // define the local variable for domain_info->domain_info
    domain_info_domain_info_t *domain_info_local_nonprim = NULL;

    // domain_info->domain_info
    cJSON *domain_info = cJSON_GetObjectItemCaseSensitive(domain_infoJSON, "domainInfo");
    if (cJSON_IsNull(domain_info)) {
        domain_info = NULL;
    }
    if (!domain_info) {
        goto end;
    }

    
    domain_info_local_nonprim = domain_info_domain_info_parseFromJSON(domain_info); //nonprimitive


    domain_info_local_var = domain_info_create_internal (
        domain_info_local_nonprim
        );

    return domain_info_local_var;
end:
    if (domain_info_local_nonprim) {
        domain_info_domain_info_free(domain_info_local_nonprim);
        domain_info_local_nonprim = NULL;
    }
    return NULL;

}
