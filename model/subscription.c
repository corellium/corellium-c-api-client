#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "subscription.h"



static subscription_t *subscription_create_internal(
    subscription_trial_t *trial,
    char *status,
    char *billing_type,
    char *plan_name,
    char *next_bill,
    int use_device_accounting,
    int is_enterprise,
    int is_usage_based,
    char *cancel_policy
    ) {
    subscription_t *subscription_local_var = malloc(sizeof(subscription_t));
    if (!subscription_local_var) {
        return NULL;
    }
    subscription_local_var->trial = trial;
    subscription_local_var->status = status;
    subscription_local_var->billing_type = billing_type;
    subscription_local_var->plan_name = plan_name;
    subscription_local_var->next_bill = next_bill;
    subscription_local_var->use_device_accounting = use_device_accounting;
    subscription_local_var->is_enterprise = is_enterprise;
    subscription_local_var->is_usage_based = is_usage_based;
    subscription_local_var->cancel_policy = cancel_policy;

    subscription_local_var->_library_owned = 1;
    return subscription_local_var;
}

__attribute__((deprecated)) subscription_t *subscription_create(
    subscription_trial_t *trial,
    char *status,
    char *billing_type,
    char *plan_name,
    char *next_bill,
    int use_device_accounting,
    int is_enterprise,
    int is_usage_based,
    char *cancel_policy
    ) {
    return subscription_create_internal (
        trial,
        status,
        billing_type,
        plan_name,
        next_bill,
        use_device_accounting,
        is_enterprise,
        is_usage_based,
        cancel_policy
        );
}

void subscription_free(subscription_t *subscription) {
    if(NULL == subscription){
        return ;
    }
    if(subscription->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "subscription_free");
        return ;
    }
    listEntry_t *listEntry;
    if (subscription->trial) {
        subscription_trial_free(subscription->trial);
        subscription->trial = NULL;
    }
    if (subscription->status) {
        free(subscription->status);
        subscription->status = NULL;
    }
    if (subscription->billing_type) {
        free(subscription->billing_type);
        subscription->billing_type = NULL;
    }
    if (subscription->plan_name) {
        free(subscription->plan_name);
        subscription->plan_name = NULL;
    }
    if (subscription->next_bill) {
        free(subscription->next_bill);
        subscription->next_bill = NULL;
    }
    if (subscription->cancel_policy) {
        free(subscription->cancel_policy);
        subscription->cancel_policy = NULL;
    }
    free(subscription);
}

cJSON *subscription_convertToJSON(subscription_t *subscription) {
    cJSON *item = cJSON_CreateObject();

    // subscription->trial
    if(subscription->trial) {
    cJSON *trial_local_JSON = subscription_trial_convertToJSON(subscription->trial);
    if(trial_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "trial", trial_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // subscription->status
    if(subscription->status) {
    if(cJSON_AddStringToObject(item, "status", subscription->status) == NULL) {
    goto fail; //String
    }
    }


    // subscription->billing_type
    if (!subscription->billing_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "billingType", subscription->billing_type) == NULL) {
    goto fail; //String
    }


    // subscription->plan_name
    if(subscription->plan_name) {
    if(cJSON_AddStringToObject(item, "planName", subscription->plan_name) == NULL) {
    goto fail; //String
    }
    }


    // subscription->next_bill
    if(subscription->next_bill) {
    if(cJSON_AddStringToObject(item, "nextBill", subscription->next_bill) == NULL) {
    goto fail; //String
    }
    }


    // subscription->use_device_accounting
    if(subscription->use_device_accounting) {
    if(cJSON_AddBoolToObject(item, "useDeviceAccounting", subscription->use_device_accounting) == NULL) {
    goto fail; //Bool
    }
    }


    // subscription->is_enterprise
    if(subscription->is_enterprise) {
    if(cJSON_AddBoolToObject(item, "isEnterprise", subscription->is_enterprise) == NULL) {
    goto fail; //Bool
    }
    }


    // subscription->is_usage_based
    if(subscription->is_usage_based) {
    if(cJSON_AddBoolToObject(item, "isUsageBased", subscription->is_usage_based) == NULL) {
    goto fail; //Bool
    }
    }


    // subscription->cancel_policy
    if(subscription->cancel_policy) {
    if(cJSON_AddStringToObject(item, "cancelPolicy", subscription->cancel_policy) == NULL) {
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

subscription_t *subscription_parseFromJSON(cJSON *subscriptionJSON){

    subscription_t *subscription_local_var = NULL;

    // define the local variable for subscription->trial
    subscription_trial_t *trial_local_nonprim = NULL;

    // subscription->trial
    cJSON *trial = cJSON_GetObjectItemCaseSensitive(subscriptionJSON, "trial");
    if (cJSON_IsNull(trial)) {
        trial = NULL;
    }
    if (trial) { 
    trial_local_nonprim = subscription_trial_parseFromJSON(trial); //nonprimitive
    }

    // subscription->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(subscriptionJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    if(!cJSON_IsString(status) && !cJSON_IsNull(status))
    {
    goto end; //String
    }
    }

    // subscription->billing_type
    cJSON *billing_type = cJSON_GetObjectItemCaseSensitive(subscriptionJSON, "billingType");
    if (cJSON_IsNull(billing_type)) {
        billing_type = NULL;
    }
    if (!billing_type) {
        goto end;
    }

    
    if(!cJSON_IsString(billing_type))
    {
    goto end; //String
    }

    // subscription->plan_name
    cJSON *plan_name = cJSON_GetObjectItemCaseSensitive(subscriptionJSON, "planName");
    if (cJSON_IsNull(plan_name)) {
        plan_name = NULL;
    }
    if (plan_name) { 
    if(!cJSON_IsString(plan_name) && !cJSON_IsNull(plan_name))
    {
    goto end; //String
    }
    }

    // subscription->next_bill
    cJSON *next_bill = cJSON_GetObjectItemCaseSensitive(subscriptionJSON, "nextBill");
    if (cJSON_IsNull(next_bill)) {
        next_bill = NULL;
    }
    if (next_bill) { 
    if(!cJSON_IsString(next_bill) && !cJSON_IsNull(next_bill))
    {
    goto end; //String
    }
    }

    // subscription->use_device_accounting
    cJSON *use_device_accounting = cJSON_GetObjectItemCaseSensitive(subscriptionJSON, "useDeviceAccounting");
    if (cJSON_IsNull(use_device_accounting)) {
        use_device_accounting = NULL;
    }
    if (use_device_accounting) { 
    if(!cJSON_IsBool(use_device_accounting))
    {
    goto end; //Bool
    }
    }

    // subscription->is_enterprise
    cJSON *is_enterprise = cJSON_GetObjectItemCaseSensitive(subscriptionJSON, "isEnterprise");
    if (cJSON_IsNull(is_enterprise)) {
        is_enterprise = NULL;
    }
    if (is_enterprise) { 
    if(!cJSON_IsBool(is_enterprise))
    {
    goto end; //Bool
    }
    }

    // subscription->is_usage_based
    cJSON *is_usage_based = cJSON_GetObjectItemCaseSensitive(subscriptionJSON, "isUsageBased");
    if (cJSON_IsNull(is_usage_based)) {
        is_usage_based = NULL;
    }
    if (is_usage_based) { 
    if(!cJSON_IsBool(is_usage_based))
    {
    goto end; //Bool
    }
    }

    // subscription->cancel_policy
    cJSON *cancel_policy = cJSON_GetObjectItemCaseSensitive(subscriptionJSON, "cancelPolicy");
    if (cJSON_IsNull(cancel_policy)) {
        cancel_policy = NULL;
    }
    if (cancel_policy) { 
    if(!cJSON_IsString(cancel_policy) && !cJSON_IsNull(cancel_policy))
    {
    goto end; //String
    }
    }


    subscription_local_var = subscription_create_internal (
        trial ? trial_local_nonprim : NULL,
        status && !cJSON_IsNull(status) ? strdup(status->valuestring) : NULL,
        strdup(billing_type->valuestring),
        plan_name && !cJSON_IsNull(plan_name) ? strdup(plan_name->valuestring) : NULL,
        next_bill && !cJSON_IsNull(next_bill) ? strdup(next_bill->valuestring) : NULL,
        use_device_accounting ? use_device_accounting->valueint : 0,
        is_enterprise ? is_enterprise->valueint : 0,
        is_usage_based ? is_usage_based->valueint : 0,
        cancel_policy && !cJSON_IsNull(cancel_policy) ? strdup(cancel_policy->valuestring) : NULL
        );

    return subscription_local_var;
end:
    if (trial_local_nonprim) {
        subscription_trial_free(trial_local_nonprim);
        trial_local_nonprim = NULL;
    }
    return NULL;

}
