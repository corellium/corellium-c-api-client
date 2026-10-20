#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "domain_list_item_subscription_history_inner_administrator.h"



static domain_list_item_subscription_history_inner_administrator_t *domain_list_item_subscription_history_inner_administrator_create_internal(
    char *name,
    char *email
    ) {
    domain_list_item_subscription_history_inner_administrator_t *domain_list_item_subscription_history_inner_administrator_local_var = malloc(sizeof(domain_list_item_subscription_history_inner_administrator_t));
    if (!domain_list_item_subscription_history_inner_administrator_local_var) {
        return NULL;
    }
    domain_list_item_subscription_history_inner_administrator_local_var->name = name;
    domain_list_item_subscription_history_inner_administrator_local_var->email = email;

    domain_list_item_subscription_history_inner_administrator_local_var->_library_owned = 1;
    return domain_list_item_subscription_history_inner_administrator_local_var;
}

__attribute__((deprecated)) domain_list_item_subscription_history_inner_administrator_t *domain_list_item_subscription_history_inner_administrator_create(
    char *name,
    char *email
    ) {
    return domain_list_item_subscription_history_inner_administrator_create_internal (
        name,
        email
        );
}

void domain_list_item_subscription_history_inner_administrator_free(domain_list_item_subscription_history_inner_administrator_t *domain_list_item_subscription_history_inner_administrator) {
    if(NULL == domain_list_item_subscription_history_inner_administrator){
        return ;
    }
    if(domain_list_item_subscription_history_inner_administrator->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "domain_list_item_subscription_history_inner_administrator_free");
        return ;
    }
    listEntry_t *listEntry;
    if (domain_list_item_subscription_history_inner_administrator->name) {
        free(domain_list_item_subscription_history_inner_administrator->name);
        domain_list_item_subscription_history_inner_administrator->name = NULL;
    }
    if (domain_list_item_subscription_history_inner_administrator->email) {
        free(domain_list_item_subscription_history_inner_administrator->email);
        domain_list_item_subscription_history_inner_administrator->email = NULL;
    }
    free(domain_list_item_subscription_history_inner_administrator);
}

cJSON *domain_list_item_subscription_history_inner_administrator_convertToJSON(domain_list_item_subscription_history_inner_administrator_t *domain_list_item_subscription_history_inner_administrator) {
    cJSON *item = cJSON_CreateObject();

    // domain_list_item_subscription_history_inner_administrator->name
    if (!domain_list_item_subscription_history_inner_administrator->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", domain_list_item_subscription_history_inner_administrator->name) == NULL) {
    goto fail; //String
    }


    // domain_list_item_subscription_history_inner_administrator->email
    if (!domain_list_item_subscription_history_inner_administrator->email) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "email", domain_list_item_subscription_history_inner_administrator->email) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

domain_list_item_subscription_history_inner_administrator_t *domain_list_item_subscription_history_inner_administrator_parseFromJSON(cJSON *domain_list_item_subscription_history_inner_administratorJSON){

    domain_list_item_subscription_history_inner_administrator_t *domain_list_item_subscription_history_inner_administrator_local_var = NULL;

    // domain_list_item_subscription_history_inner_administrator->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(domain_list_item_subscription_history_inner_administratorJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // domain_list_item_subscription_history_inner_administrator->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(domain_list_item_subscription_history_inner_administratorJSON, "email");
    if (cJSON_IsNull(email)) {
        email = NULL;
    }
    if (!email) {
        goto end;
    }

    
    if(!cJSON_IsString(email))
    {
    goto end; //String
    }


    domain_list_item_subscription_history_inner_administrator_local_var = domain_list_item_subscription_history_inner_administrator_create_internal (
        strdup(name->valuestring),
        strdup(email->valuestring)
        );

    return domain_list_item_subscription_history_inner_administrator_local_var;
end:
    return NULL;

}
