#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "domain_list_item_subscription_history_inner.h"



static domain_list_item_subscription_history_inner_t *domain_list_item_subscription_history_inner_create_internal(
    char *plan_name,
    char *plan_start,
    char *plan_end,
    char *status,
    domain_list_item_subscription_history_inner_administrator_t *administrator,
    char *stripe_link
    ) {
    domain_list_item_subscription_history_inner_t *domain_list_item_subscription_history_inner_local_var = malloc(sizeof(domain_list_item_subscription_history_inner_t));
    if (!domain_list_item_subscription_history_inner_local_var) {
        return NULL;
    }
    domain_list_item_subscription_history_inner_local_var->plan_name = plan_name;
    domain_list_item_subscription_history_inner_local_var->plan_start = plan_start;
    domain_list_item_subscription_history_inner_local_var->plan_end = plan_end;
    domain_list_item_subscription_history_inner_local_var->status = status;
    domain_list_item_subscription_history_inner_local_var->administrator = administrator;
    domain_list_item_subscription_history_inner_local_var->stripe_link = stripe_link;

    domain_list_item_subscription_history_inner_local_var->_library_owned = 1;
    return domain_list_item_subscription_history_inner_local_var;
}

__attribute__((deprecated)) domain_list_item_subscription_history_inner_t *domain_list_item_subscription_history_inner_create(
    char *plan_name,
    char *plan_start,
    char *plan_end,
    char *status,
    domain_list_item_subscription_history_inner_administrator_t *administrator,
    char *stripe_link
    ) {
    return domain_list_item_subscription_history_inner_create_internal (
        plan_name,
        plan_start,
        plan_end,
        status,
        administrator,
        stripe_link
        );
}

void domain_list_item_subscription_history_inner_free(domain_list_item_subscription_history_inner_t *domain_list_item_subscription_history_inner) {
    if(NULL == domain_list_item_subscription_history_inner){
        return ;
    }
    if(domain_list_item_subscription_history_inner->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "domain_list_item_subscription_history_inner_free");
        return ;
    }
    listEntry_t *listEntry;
    if (domain_list_item_subscription_history_inner->plan_name) {
        free(domain_list_item_subscription_history_inner->plan_name);
        domain_list_item_subscription_history_inner->plan_name = NULL;
    }
    if (domain_list_item_subscription_history_inner->plan_start) {
        free(domain_list_item_subscription_history_inner->plan_start);
        domain_list_item_subscription_history_inner->plan_start = NULL;
    }
    if (domain_list_item_subscription_history_inner->plan_end) {
        free(domain_list_item_subscription_history_inner->plan_end);
        domain_list_item_subscription_history_inner->plan_end = NULL;
    }
    if (domain_list_item_subscription_history_inner->status) {
        free(domain_list_item_subscription_history_inner->status);
        domain_list_item_subscription_history_inner->status = NULL;
    }
    if (domain_list_item_subscription_history_inner->administrator) {
        domain_list_item_subscription_history_inner_administrator_free(domain_list_item_subscription_history_inner->administrator);
        domain_list_item_subscription_history_inner->administrator = NULL;
    }
    if (domain_list_item_subscription_history_inner->stripe_link) {
        free(domain_list_item_subscription_history_inner->stripe_link);
        domain_list_item_subscription_history_inner->stripe_link = NULL;
    }
    free(domain_list_item_subscription_history_inner);
}

cJSON *domain_list_item_subscription_history_inner_convertToJSON(domain_list_item_subscription_history_inner_t *domain_list_item_subscription_history_inner) {
    cJSON *item = cJSON_CreateObject();

    // domain_list_item_subscription_history_inner->plan_name
    if (!domain_list_item_subscription_history_inner->plan_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "planName", domain_list_item_subscription_history_inner->plan_name) == NULL) {
    goto fail; //String
    }


    // domain_list_item_subscription_history_inner->plan_start
    if (!domain_list_item_subscription_history_inner->plan_start) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "planStart", domain_list_item_subscription_history_inner->plan_start) == NULL) {
    goto fail; //Date-Time
    }


    // domain_list_item_subscription_history_inner->plan_end
    if(domain_list_item_subscription_history_inner->plan_end) {
    if(cJSON_AddStringToObject(item, "planEnd", domain_list_item_subscription_history_inner->plan_end) == NULL) {
    goto fail; //Date-Time
    }
    }


    // domain_list_item_subscription_history_inner->status
    if (!domain_list_item_subscription_history_inner->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", domain_list_item_subscription_history_inner->status) == NULL) {
    goto fail; //String
    }


    // domain_list_item_subscription_history_inner->administrator
    if (!domain_list_item_subscription_history_inner->administrator) {
        goto fail;
    }
    cJSON *administrator_local_JSON = domain_list_item_subscription_history_inner_administrator_convertToJSON(domain_list_item_subscription_history_inner->administrator);
    if(administrator_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "administrator", administrator_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // domain_list_item_subscription_history_inner->stripe_link
    if(domain_list_item_subscription_history_inner->stripe_link) {
    if(cJSON_AddStringToObject(item, "stripeLink", domain_list_item_subscription_history_inner->stripe_link) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

domain_list_item_subscription_history_inner_t *domain_list_item_subscription_history_inner_parseFromJSON(cJSON *domain_list_item_subscription_history_innerJSON){

    domain_list_item_subscription_history_inner_t *domain_list_item_subscription_history_inner_local_var = NULL;

    // define the local variable for domain_list_item_subscription_history_inner->administrator
    domain_list_item_subscription_history_inner_administrator_t *administrator_local_nonprim = NULL;

    // domain_list_item_subscription_history_inner->plan_name
    cJSON *plan_name = cJSON_GetObjectItemCaseSensitive(domain_list_item_subscription_history_innerJSON, "planName");
    if (cJSON_IsNull(plan_name)) {
        plan_name = NULL;
    }
    if (!plan_name) {
        goto end;
    }

    
    if(!cJSON_IsString(plan_name))
    {
    goto end; //String
    }

    // domain_list_item_subscription_history_inner->plan_start
    cJSON *plan_start = cJSON_GetObjectItemCaseSensitive(domain_list_item_subscription_history_innerJSON, "planStart");
    if (cJSON_IsNull(plan_start)) {
        plan_start = NULL;
    }
    if (!plan_start) {
        goto end;
    }

    
    if(!cJSON_IsString(plan_start) && !cJSON_IsNull(plan_start))
    {
    goto end; //DateTime
    }

    // domain_list_item_subscription_history_inner->plan_end
    cJSON *plan_end = cJSON_GetObjectItemCaseSensitive(domain_list_item_subscription_history_innerJSON, "planEnd");
    if (cJSON_IsNull(plan_end)) {
        plan_end = NULL;
    }
    if (plan_end) { 
    if(!cJSON_IsString(plan_end) && !cJSON_IsNull(plan_end))
    {
    goto end; //DateTime
    }
    }

    // domain_list_item_subscription_history_inner->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(domain_list_item_subscription_history_innerJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    if(!cJSON_IsString(status))
    {
    goto end; //String
    }

    // domain_list_item_subscription_history_inner->administrator
    cJSON *administrator = cJSON_GetObjectItemCaseSensitive(domain_list_item_subscription_history_innerJSON, "administrator");
    if (cJSON_IsNull(administrator)) {
        administrator = NULL;
    }
    if (!administrator) {
        goto end;
    }

    
    administrator_local_nonprim = domain_list_item_subscription_history_inner_administrator_parseFromJSON(administrator); //nonprimitive

    // domain_list_item_subscription_history_inner->stripe_link
    cJSON *stripe_link = cJSON_GetObjectItemCaseSensitive(domain_list_item_subscription_history_innerJSON, "stripeLink");
    if (cJSON_IsNull(stripe_link)) {
        stripe_link = NULL;
    }
    if (stripe_link) { 
    if(!cJSON_IsString(stripe_link) && !cJSON_IsNull(stripe_link))
    {
    goto end; //String
    }
    }


    domain_list_item_subscription_history_inner_local_var = domain_list_item_subscription_history_inner_create_internal (
        strdup(plan_name->valuestring),
        strdup(plan_start->valuestring),
        plan_end && !cJSON_IsNull(plan_end) ? strdup(plan_end->valuestring) : NULL,
        strdup(status->valuestring),
        administrator_local_nonprim,
        stripe_link && !cJSON_IsNull(stripe_link) ? strdup(stripe_link->valuestring) : NULL
        );

    return domain_list_item_subscription_history_inner_local_var;
end:
    if (administrator_local_nonprim) {
        domain_list_item_subscription_history_inner_administrator_free(administrator_local_nonprim);
        administrator_local_nonprim = NULL;
    }
    return NULL;

}
