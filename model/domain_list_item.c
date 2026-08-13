#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "domain_list_item.h"



static domain_list_item_t *domain_list_item_create_internal(
    char *identifier,
    char *user_id,
    list_t *domain_usage,
    double user_count,
    list_t *users_info,
    char *domain,
    char *domain_name,
    domain_list_item_disabled_t *disabled,
    domain_config_t *config,
    domain_list_item_quotas_t *quotas,
    domain_list_item_usage_t *usage,
    double created_at,
    domain_list_item_subscription_t *subscription,
    list_t *subscription_history,
    char *plan_name,
    list_t *projects
    ) {
    domain_list_item_t *domain_list_item_local_var = malloc(sizeof(domain_list_item_t));
    if (!domain_list_item_local_var) {
        return NULL;
    }
    domain_list_item_local_var->identifier = identifier;
    domain_list_item_local_var->user_id = user_id;
    domain_list_item_local_var->domain_usage = domain_usage;
    domain_list_item_local_var->user_count = user_count;
    domain_list_item_local_var->users_info = users_info;
    domain_list_item_local_var->domain = domain;
    domain_list_item_local_var->domain_name = domain_name;
    domain_list_item_local_var->disabled = disabled;
    domain_list_item_local_var->config = config;
    domain_list_item_local_var->quotas = quotas;
    domain_list_item_local_var->usage = usage;
    domain_list_item_local_var->created_at = created_at;
    domain_list_item_local_var->subscription = subscription;
    domain_list_item_local_var->subscription_history = subscription_history;
    domain_list_item_local_var->plan_name = plan_name;
    domain_list_item_local_var->projects = projects;

    domain_list_item_local_var->_library_owned = 1;
    return domain_list_item_local_var;
}

__attribute__((deprecated)) domain_list_item_t *domain_list_item_create(
    char *identifier,
    char *user_id,
    list_t *domain_usage,
    double user_count,
    list_t *users_info,
    char *domain,
    char *domain_name,
    domain_list_item_disabled_t *disabled,
    domain_config_t *config,
    domain_list_item_quotas_t *quotas,
    domain_list_item_usage_t *usage,
    double created_at,
    domain_list_item_subscription_t *subscription,
    list_t *subscription_history,
    char *plan_name,
    list_t *projects
    ) {
    return domain_list_item_create_internal (
        identifier,
        user_id,
        domain_usage,
        user_count,
        users_info,
        domain,
        domain_name,
        disabled,
        config,
        quotas,
        usage,
        created_at,
        subscription,
        subscription_history,
        plan_name,
        projects
        );
}

void domain_list_item_free(domain_list_item_t *domain_list_item) {
    if(NULL == domain_list_item){
        return ;
    }
    if(domain_list_item->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "domain_list_item_free");
        return ;
    }
    listEntry_t *listEntry;
    if (domain_list_item->identifier) {
        free(domain_list_item->identifier);
        domain_list_item->identifier = NULL;
    }
    if (domain_list_item->user_id) {
        free(domain_list_item->user_id);
        domain_list_item->user_id = NULL;
    }
    if (domain_list_item->domain_usage) {
        list_ForEach(listEntry, domain_list_item->domain_usage) {
            domain_list_item_domain_usage_inner_free(listEntry->data);
        }
        list_freeList(domain_list_item->domain_usage);
        domain_list_item->domain_usage = NULL;
    }
    if (domain_list_item->users_info) {
        list_ForEach(listEntry, domain_list_item->users_info) {
            domain_list_item_users_info_inner_free(listEntry->data);
        }
        list_freeList(domain_list_item->users_info);
        domain_list_item->users_info = NULL;
    }
    if (domain_list_item->domain) {
        free(domain_list_item->domain);
        domain_list_item->domain = NULL;
    }
    if (domain_list_item->domain_name) {
        free(domain_list_item->domain_name);
        domain_list_item->domain_name = NULL;
    }
    if (domain_list_item->disabled) {
        domain_list_item_disabled_free(domain_list_item->disabled);
        domain_list_item->disabled = NULL;
    }
    if (domain_list_item->config) {
        domain_config_free(domain_list_item->config);
        domain_list_item->config = NULL;
    }
    if (domain_list_item->quotas) {
        domain_list_item_quotas_free(domain_list_item->quotas);
        domain_list_item->quotas = NULL;
    }
    if (domain_list_item->usage) {
        domain_list_item_usage_free(domain_list_item->usage);
        domain_list_item->usage = NULL;
    }
    if (domain_list_item->subscription) {
        domain_list_item_subscription_free(domain_list_item->subscription);
        domain_list_item->subscription = NULL;
    }
    if (domain_list_item->subscription_history) {
        list_ForEach(listEntry, domain_list_item->subscription_history) {
            domain_list_item_subscription_history_inner_free(listEntry->data);
        }
        list_freeList(domain_list_item->subscription_history);
        domain_list_item->subscription_history = NULL;
    }
    if (domain_list_item->plan_name) {
        free(domain_list_item->plan_name);
        domain_list_item->plan_name = NULL;
    }
    if (domain_list_item->projects) {
        list_ForEach(listEntry, domain_list_item->projects) {
            domain_list_item_projects_inner_free(listEntry->data);
        }
        list_freeList(domain_list_item->projects);
        domain_list_item->projects = NULL;
    }
    free(domain_list_item);
}

cJSON *domain_list_item_convertToJSON(domain_list_item_t *domain_list_item) {
    cJSON *item = cJSON_CreateObject();

    // domain_list_item->identifier
    if (!domain_list_item->identifier) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "identifier", domain_list_item->identifier) == NULL) {
    goto fail; //String
    }


    // domain_list_item->user_id
    if (!domain_list_item->user_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "userId", domain_list_item->user_id) == NULL) {
    goto fail; //String
    }


    // domain_list_item->domain_usage
    if (!domain_list_item->domain_usage) {
        goto fail;
    }
    cJSON *domain_usage = cJSON_AddArrayToObject(item, "domainUsage");
    if(domain_usage == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *domain_usageListEntry;
    if (domain_list_item->domain_usage) {
    list_ForEach(domain_usageListEntry, domain_list_item->domain_usage) {
    cJSON *itemLocal = domain_list_item_domain_usage_inner_convertToJSON(domain_usageListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(domain_usage, itemLocal);
    }
    }


    // domain_list_item->user_count
    if (!domain_list_item->user_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "userCount", domain_list_item->user_count) == NULL) {
    goto fail; //Numeric
    }


    // domain_list_item->users_info
    if (!domain_list_item->users_info) {
        goto fail;
    }
    cJSON *users_info = cJSON_AddArrayToObject(item, "usersInfo");
    if(users_info == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *users_infoListEntry;
    if (domain_list_item->users_info) {
    list_ForEach(users_infoListEntry, domain_list_item->users_info) {
    cJSON *itemLocal = domain_list_item_users_info_inner_convertToJSON(users_infoListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(users_info, itemLocal);
    }
    }


    // domain_list_item->domain
    if (!domain_list_item->domain) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "domain", domain_list_item->domain) == NULL) {
    goto fail; //String
    }


    // domain_list_item->domain_name
    if (!domain_list_item->domain_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "domainName", domain_list_item->domain_name) == NULL) {
    goto fail; //String
    }


    // domain_list_item->disabled
    if(domain_list_item->disabled) {
    cJSON *disabled_local_JSON = domain_list_item_disabled_convertToJSON(domain_list_item->disabled);
    if(disabled_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "disabled", disabled_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // domain_list_item->config
    if (!domain_list_item->config) {
        goto fail;
    }
    cJSON *config_local_JSON = domain_config_convertToJSON(domain_list_item->config);
    if(config_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "config", config_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // domain_list_item->quotas
    if (!domain_list_item->quotas) {
        goto fail;
    }
    cJSON *quotas_local_JSON = domain_list_item_quotas_convertToJSON(domain_list_item->quotas);
    if(quotas_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "quotas", quotas_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // domain_list_item->usage
    if (!domain_list_item->usage) {
        goto fail;
    }
    cJSON *usage_local_JSON = domain_list_item_usage_convertToJSON(domain_list_item->usage);
    if(usage_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "usage", usage_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // domain_list_item->created_at
    if (!domain_list_item->created_at) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "createdAt", domain_list_item->created_at) == NULL) {
    goto fail; //Numeric
    }


    // domain_list_item->subscription
    if(domain_list_item->subscription) {
    cJSON *subscription_local_JSON = domain_list_item_subscription_convertToJSON(domain_list_item->subscription);
    if(subscription_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "subscription", subscription_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // domain_list_item->subscription_history
    if(domain_list_item->subscription_history) {
    cJSON *subscription_history = cJSON_AddArrayToObject(item, "subscriptionHistory");
    if(subscription_history == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *subscription_historyListEntry;
    if (domain_list_item->subscription_history) {
    list_ForEach(subscription_historyListEntry, domain_list_item->subscription_history) {
    cJSON *itemLocal = domain_list_item_subscription_history_inner_convertToJSON(subscription_historyListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(subscription_history, itemLocal);
    }
    }
    }


    // domain_list_item->plan_name
    if(domain_list_item->plan_name) {
    if(cJSON_AddStringToObject(item, "planName", domain_list_item->plan_name) == NULL) {
    goto fail; //String
    }
    }


    // domain_list_item->projects
    if (!domain_list_item->projects) {
        goto fail;
    }
    cJSON *projects = cJSON_AddArrayToObject(item, "projects");
    if(projects == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *projectsListEntry;
    if (domain_list_item->projects) {
    list_ForEach(projectsListEntry, domain_list_item->projects) {
    cJSON *itemLocal = domain_list_item_projects_inner_convertToJSON(projectsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(projects, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

domain_list_item_t *domain_list_item_parseFromJSON(cJSON *domain_list_itemJSON){

    domain_list_item_t *domain_list_item_local_var = NULL;

    // define the local list for domain_list_item->domain_usage
    list_t *domain_usageList = NULL;

    // define the local list for domain_list_item->users_info
    list_t *users_infoList = NULL;

    // define the local variable for domain_list_item->disabled
    domain_list_item_disabled_t *disabled_local_nonprim = NULL;

    // define the local variable for domain_list_item->config
    domain_config_t *config_local_nonprim = NULL;

    // define the local variable for domain_list_item->quotas
    domain_list_item_quotas_t *quotas_local_nonprim = NULL;

    // define the local variable for domain_list_item->usage
    domain_list_item_usage_t *usage_local_nonprim = NULL;

    // define the local variable for domain_list_item->subscription
    domain_list_item_subscription_t *subscription_local_nonprim = NULL;

    // define the local list for domain_list_item->subscription_history
    list_t *subscription_historyList = NULL;

    // define the local list for domain_list_item->projects
    list_t *projectsList = NULL;

    // domain_list_item->identifier
    cJSON *identifier = cJSON_GetObjectItemCaseSensitive(domain_list_itemJSON, "identifier");
    if (cJSON_IsNull(identifier)) {
        identifier = NULL;
    }
    if (!identifier) {
        goto end;
    }

    
    if(!cJSON_IsString(identifier))
    {
    goto end; //String
    }

    // domain_list_item->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(domain_list_itemJSON, "userId");
    if (cJSON_IsNull(user_id)) {
        user_id = NULL;
    }
    if (!user_id) {
        goto end;
    }

    
    if(!cJSON_IsString(user_id))
    {
    goto end; //String
    }

    // domain_list_item->domain_usage
    cJSON *domain_usage = cJSON_GetObjectItemCaseSensitive(domain_list_itemJSON, "domainUsage");
    if (cJSON_IsNull(domain_usage)) {
        domain_usage = NULL;
    }
    if (!domain_usage) {
        goto end;
    }

    
    cJSON *domain_usage_local_nonprimitive = NULL;
    if(!cJSON_IsArray(domain_usage)){
        goto end; //nonprimitive container
    }

    domain_usageList = list_createList();

    cJSON_ArrayForEach(domain_usage_local_nonprimitive,domain_usage )
    {
        if(!cJSON_IsObject(domain_usage_local_nonprimitive)){
            goto end;
        }
        domain_list_item_domain_usage_inner_t *domain_usageItem = domain_list_item_domain_usage_inner_parseFromJSON(domain_usage_local_nonprimitive);

        list_addElement(domain_usageList, domain_usageItem);
    }

    // domain_list_item->user_count
    cJSON *user_count = cJSON_GetObjectItemCaseSensitive(domain_list_itemJSON, "userCount");
    if (cJSON_IsNull(user_count)) {
        user_count = NULL;
    }
    if (!user_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(user_count))
    {
    goto end; //Numeric
    }

    // domain_list_item->users_info
    cJSON *users_info = cJSON_GetObjectItemCaseSensitive(domain_list_itemJSON, "usersInfo");
    if (cJSON_IsNull(users_info)) {
        users_info = NULL;
    }
    if (!users_info) {
        goto end;
    }

    
    cJSON *users_info_local_nonprimitive = NULL;
    if(!cJSON_IsArray(users_info)){
        goto end; //nonprimitive container
    }

    users_infoList = list_createList();

    cJSON_ArrayForEach(users_info_local_nonprimitive,users_info )
    {
        if(!cJSON_IsObject(users_info_local_nonprimitive)){
            goto end;
        }
        domain_list_item_users_info_inner_t *users_infoItem = domain_list_item_users_info_inner_parseFromJSON(users_info_local_nonprimitive);

        list_addElement(users_infoList, users_infoItem);
    }

    // domain_list_item->domain
    cJSON *domain = cJSON_GetObjectItemCaseSensitive(domain_list_itemJSON, "domain");
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

    // domain_list_item->domain_name
    cJSON *domain_name = cJSON_GetObjectItemCaseSensitive(domain_list_itemJSON, "domainName");
    if (cJSON_IsNull(domain_name)) {
        domain_name = NULL;
    }
    if (!domain_name) {
        goto end;
    }

    
    if(!cJSON_IsString(domain_name))
    {
    goto end; //String
    }

    // domain_list_item->disabled
    cJSON *disabled = cJSON_GetObjectItemCaseSensitive(domain_list_itemJSON, "disabled");
    if (cJSON_IsNull(disabled)) {
        disabled = NULL;
    }
    if (disabled) { 
    disabled_local_nonprim = domain_list_item_disabled_parseFromJSON(disabled); //nonprimitive
    }

    // domain_list_item->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(domain_list_itemJSON, "config");
    if (cJSON_IsNull(config)) {
        config = NULL;
    }
    if (!config) {
        goto end;
    }

    
    config_local_nonprim = domain_config_parseFromJSON(config); //nonprimitive

    // domain_list_item->quotas
    cJSON *quotas = cJSON_GetObjectItemCaseSensitive(domain_list_itemJSON, "quotas");
    if (cJSON_IsNull(quotas)) {
        quotas = NULL;
    }
    if (!quotas) {
        goto end;
    }

    
    quotas_local_nonprim = domain_list_item_quotas_parseFromJSON(quotas); //nonprimitive

    // domain_list_item->usage
    cJSON *usage = cJSON_GetObjectItemCaseSensitive(domain_list_itemJSON, "usage");
    if (cJSON_IsNull(usage)) {
        usage = NULL;
    }
    if (!usage) {
        goto end;
    }

    
    usage_local_nonprim = domain_list_item_usage_parseFromJSON(usage); //nonprimitive

    // domain_list_item->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(domain_list_itemJSON, "createdAt");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (!created_at) {
        goto end;
    }

    
    if(!cJSON_IsNumber(created_at))
    {
    goto end; //Numeric
    }

    // domain_list_item->subscription
    cJSON *subscription = cJSON_GetObjectItemCaseSensitive(domain_list_itemJSON, "subscription");
    if (cJSON_IsNull(subscription)) {
        subscription = NULL;
    }
    if (subscription) { 
    subscription_local_nonprim = domain_list_item_subscription_parseFromJSON(subscription); //nonprimitive
    }

    // domain_list_item->subscription_history
    cJSON *subscription_history = cJSON_GetObjectItemCaseSensitive(domain_list_itemJSON, "subscriptionHistory");
    if (cJSON_IsNull(subscription_history)) {
        subscription_history = NULL;
    }
    if (subscription_history) { 
    cJSON *subscription_history_local_nonprimitive = NULL;
    if(!cJSON_IsArray(subscription_history)){
        goto end; //nonprimitive container
    }

    subscription_historyList = list_createList();

    cJSON_ArrayForEach(subscription_history_local_nonprimitive,subscription_history )
    {
        if(!cJSON_IsObject(subscription_history_local_nonprimitive)){
            goto end;
        }
        domain_list_item_subscription_history_inner_t *subscription_historyItem = domain_list_item_subscription_history_inner_parseFromJSON(subscription_history_local_nonprimitive);

        list_addElement(subscription_historyList, subscription_historyItem);
    }
    }

    // domain_list_item->plan_name
    cJSON *plan_name = cJSON_GetObjectItemCaseSensitive(domain_list_itemJSON, "planName");
    if (cJSON_IsNull(plan_name)) {
        plan_name = NULL;
    }
    if (plan_name) { 
    if(!cJSON_IsString(plan_name) && !cJSON_IsNull(plan_name))
    {
    goto end; //String
    }
    }

    // domain_list_item->projects
    cJSON *projects = cJSON_GetObjectItemCaseSensitive(domain_list_itemJSON, "projects");
    if (cJSON_IsNull(projects)) {
        projects = NULL;
    }
    if (!projects) {
        goto end;
    }

    
    cJSON *projects_local_nonprimitive = NULL;
    if(!cJSON_IsArray(projects)){
        goto end; //nonprimitive container
    }

    projectsList = list_createList();

    cJSON_ArrayForEach(projects_local_nonprimitive,projects )
    {
        if(!cJSON_IsObject(projects_local_nonprimitive)){
            goto end;
        }
        domain_list_item_projects_inner_t *projectsItem = domain_list_item_projects_inner_parseFromJSON(projects_local_nonprimitive);

        list_addElement(projectsList, projectsItem);
    }


    domain_list_item_local_var = domain_list_item_create_internal (
        strdup(identifier->valuestring),
        strdup(user_id->valuestring),
        domain_usageList,
        user_count->valuedouble,
        users_infoList,
        strdup(domain->valuestring),
        strdup(domain_name->valuestring),
        disabled ? disabled_local_nonprim : NULL,
        config_local_nonprim,
        quotas_local_nonprim,
        usage_local_nonprim,
        created_at->valuedouble,
        subscription ? subscription_local_nonprim : NULL,
        subscription_history ? subscription_historyList : NULL,
        plan_name && !cJSON_IsNull(plan_name) ? strdup(plan_name->valuestring) : NULL,
        projectsList
        );

    return domain_list_item_local_var;
end:
    if (domain_usageList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, domain_usageList) {
            domain_list_item_domain_usage_inner_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(domain_usageList);
        domain_usageList = NULL;
    }
    if (users_infoList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, users_infoList) {
            domain_list_item_users_info_inner_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(users_infoList);
        users_infoList = NULL;
    }
    if (disabled_local_nonprim) {
        domain_list_item_disabled_free(disabled_local_nonprim);
        disabled_local_nonprim = NULL;
    }
    if (config_local_nonprim) {
        domain_config_free(config_local_nonprim);
        config_local_nonprim = NULL;
    }
    if (quotas_local_nonprim) {
        domain_list_item_quotas_free(quotas_local_nonprim);
        quotas_local_nonprim = NULL;
    }
    if (usage_local_nonprim) {
        domain_list_item_usage_free(usage_local_nonprim);
        usage_local_nonprim = NULL;
    }
    if (subscription_local_nonprim) {
        domain_list_item_subscription_free(subscription_local_nonprim);
        subscription_local_nonprim = NULL;
    }
    if (subscription_historyList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, subscription_historyList) {
            domain_list_item_subscription_history_inner_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(subscription_historyList);
        subscription_historyList = NULL;
    }
    if (projectsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, projectsList) {
            domain_list_item_projects_inner_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(projectsList);
        projectsList = NULL;
    }
    return NULL;

}
