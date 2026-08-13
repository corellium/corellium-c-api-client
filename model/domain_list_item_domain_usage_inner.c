#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "domain_list_item_domain_usage_inner.h"



static domain_list_item_domain_usage_inner_t *domain_list_item_domain_usage_inner_create_internal(
    char *domain,
    char *month,
    double hours
    ) {
    domain_list_item_domain_usage_inner_t *domain_list_item_domain_usage_inner_local_var = malloc(sizeof(domain_list_item_domain_usage_inner_t));
    if (!domain_list_item_domain_usage_inner_local_var) {
        return NULL;
    }
    domain_list_item_domain_usage_inner_local_var->domain = domain;
    domain_list_item_domain_usage_inner_local_var->month = month;
    domain_list_item_domain_usage_inner_local_var->hours = hours;

    domain_list_item_domain_usage_inner_local_var->_library_owned = 1;
    return domain_list_item_domain_usage_inner_local_var;
}

__attribute__((deprecated)) domain_list_item_domain_usage_inner_t *domain_list_item_domain_usage_inner_create(
    char *domain,
    char *month,
    double hours
    ) {
    return domain_list_item_domain_usage_inner_create_internal (
        domain,
        month,
        hours
        );
}

void domain_list_item_domain_usage_inner_free(domain_list_item_domain_usage_inner_t *domain_list_item_domain_usage_inner) {
    if(NULL == domain_list_item_domain_usage_inner){
        return ;
    }
    if(domain_list_item_domain_usage_inner->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "domain_list_item_domain_usage_inner_free");
        return ;
    }
    listEntry_t *listEntry;
    if (domain_list_item_domain_usage_inner->domain) {
        free(domain_list_item_domain_usage_inner->domain);
        domain_list_item_domain_usage_inner->domain = NULL;
    }
    if (domain_list_item_domain_usage_inner->month) {
        free(domain_list_item_domain_usage_inner->month);
        domain_list_item_domain_usage_inner->month = NULL;
    }
    free(domain_list_item_domain_usage_inner);
}

cJSON *domain_list_item_domain_usage_inner_convertToJSON(domain_list_item_domain_usage_inner_t *domain_list_item_domain_usage_inner) {
    cJSON *item = cJSON_CreateObject();

    // domain_list_item_domain_usage_inner->domain
    if (!domain_list_item_domain_usage_inner->domain) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "domain", domain_list_item_domain_usage_inner->domain) == NULL) {
    goto fail; //String
    }


    // domain_list_item_domain_usage_inner->month
    if (!domain_list_item_domain_usage_inner->month) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "month", domain_list_item_domain_usage_inner->month) == NULL) {
    goto fail; //Date
    }


    // domain_list_item_domain_usage_inner->hours
    if (!domain_list_item_domain_usage_inner->hours) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "hours", domain_list_item_domain_usage_inner->hours) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

domain_list_item_domain_usage_inner_t *domain_list_item_domain_usage_inner_parseFromJSON(cJSON *domain_list_item_domain_usage_innerJSON){

    domain_list_item_domain_usage_inner_t *domain_list_item_domain_usage_inner_local_var = NULL;

    // domain_list_item_domain_usage_inner->domain
    cJSON *domain = cJSON_GetObjectItemCaseSensitive(domain_list_item_domain_usage_innerJSON, "domain");
    if (cJSON_IsNull(domain)) {
        domain = NULL;
    }
    if (!domain) {
        goto end;
    }

    
    if(!cJSON_IsString(domain))
    {
    goto end; //String
    }

    // domain_list_item_domain_usage_inner->month
    cJSON *month = cJSON_GetObjectItemCaseSensitive(domain_list_item_domain_usage_innerJSON, "month");
    if (cJSON_IsNull(month)) {
        month = NULL;
    }
    if (!month) {
        goto end;
    }

    
    if(!cJSON_IsString(month))
    {
    goto end; //Date
    }

    // domain_list_item_domain_usage_inner->hours
    cJSON *hours = cJSON_GetObjectItemCaseSensitive(domain_list_item_domain_usage_innerJSON, "hours");
    if (cJSON_IsNull(hours)) {
        hours = NULL;
    }
    if (!hours) {
        goto end;
    }

    
    if(!cJSON_IsNumber(hours))
    {
    goto end; //Numeric
    }


    domain_list_item_domain_usage_inner_local_var = domain_list_item_domain_usage_inner_create_internal (
        strdup(domain->valuestring),
        strdup(month->valuestring),
        hours->valuedouble
        );

    return domain_list_item_domain_usage_inner_local_var;
end:
    return NULL;

}
