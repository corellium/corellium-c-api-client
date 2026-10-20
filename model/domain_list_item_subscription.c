#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "domain_list_item_subscription.h"


char* domain_list_item_subscription_billing_type_ToString(corellium_api_domain_list_item_subscription_BILLINGTYPE_e billing_type) {
    char* billing_typeArray[] =  { "NULL", "prepaid", "usage", "metered", "credit", "cores_metered" };
    return billing_typeArray[billing_type];
}

corellium_api_domain_list_item_subscription_BILLINGTYPE_e domain_list_item_subscription_billing_type_FromString(char* billing_type){
    int stringToReturn = 0;
    char *billing_typeArray[] =  { "NULL", "prepaid", "usage", "metered", "credit", "cores_metered" };
    size_t sizeofArray = sizeof(billing_typeArray) / sizeof(billing_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(billing_type, billing_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static domain_list_item_subscription_t *domain_list_item_subscription_create_internal(
    object_t *renew_action,
    char *domain,
    corellium_api_domain_list_item_subscription_BILLINGTYPE_e billing_type,
    char *billing_backend,
    char *billing_id,
    char *next_bill,
    int usage_based,
    char *last_usage_bill,
    double last_payment_amount,
    double usage_bill_interval_days,
    double usage_billing_threshold_dollars,
    int past_due,
    double payment_attempts,
    char *last_payment_attempt,
    char *created_at,
    char *updated_at
    ) {
    domain_list_item_subscription_t *domain_list_item_subscription_local_var = malloc(sizeof(domain_list_item_subscription_t));
    if (!domain_list_item_subscription_local_var) {
        return NULL;
    }
    domain_list_item_subscription_local_var->renew_action = renew_action;
    domain_list_item_subscription_local_var->domain = domain;
    domain_list_item_subscription_local_var->billing_type = billing_type;
    domain_list_item_subscription_local_var->billing_backend = billing_backend;
    domain_list_item_subscription_local_var->billing_id = billing_id;
    domain_list_item_subscription_local_var->next_bill = next_bill;
    domain_list_item_subscription_local_var->usage_based = usage_based;
    domain_list_item_subscription_local_var->last_usage_bill = last_usage_bill;
    domain_list_item_subscription_local_var->last_payment_amount = last_payment_amount;
    domain_list_item_subscription_local_var->usage_bill_interval_days = usage_bill_interval_days;
    domain_list_item_subscription_local_var->usage_billing_threshold_dollars = usage_billing_threshold_dollars;
    domain_list_item_subscription_local_var->past_due = past_due;
    domain_list_item_subscription_local_var->payment_attempts = payment_attempts;
    domain_list_item_subscription_local_var->last_payment_attempt = last_payment_attempt;
    domain_list_item_subscription_local_var->created_at = created_at;
    domain_list_item_subscription_local_var->updated_at = updated_at;

    domain_list_item_subscription_local_var->_library_owned = 1;
    return domain_list_item_subscription_local_var;
}

__attribute__((deprecated)) domain_list_item_subscription_t *domain_list_item_subscription_create(
    object_t *renew_action,
    char *domain,
    corellium_api_domain_list_item_subscription_BILLINGTYPE_e billing_type,
    char *billing_backend,
    char *billing_id,
    char *next_bill,
    int usage_based,
    char *last_usage_bill,
    double last_payment_amount,
    double usage_bill_interval_days,
    double usage_billing_threshold_dollars,
    int past_due,
    double payment_attempts,
    char *last_payment_attempt,
    char *created_at,
    char *updated_at
    ) {
    return domain_list_item_subscription_create_internal (
        renew_action,
        domain,
        billing_type,
        billing_backend,
        billing_id,
        next_bill,
        usage_based,
        last_usage_bill,
        last_payment_amount,
        usage_bill_interval_days,
        usage_billing_threshold_dollars,
        past_due,
        payment_attempts,
        last_payment_attempt,
        created_at,
        updated_at
        );
}

void domain_list_item_subscription_free(domain_list_item_subscription_t *domain_list_item_subscription) {
    if(NULL == domain_list_item_subscription){
        return ;
    }
    if(domain_list_item_subscription->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "domain_list_item_subscription_free");
        return ;
    }
    listEntry_t *listEntry;
    if (domain_list_item_subscription->renew_action) {
        object_free(domain_list_item_subscription->renew_action);
        domain_list_item_subscription->renew_action = NULL;
    }
    if (domain_list_item_subscription->domain) {
        free(domain_list_item_subscription->domain);
        domain_list_item_subscription->domain = NULL;
    }
    if (domain_list_item_subscription->billing_backend) {
        free(domain_list_item_subscription->billing_backend);
        domain_list_item_subscription->billing_backend = NULL;
    }
    if (domain_list_item_subscription->billing_id) {
        free(domain_list_item_subscription->billing_id);
        domain_list_item_subscription->billing_id = NULL;
    }
    if (domain_list_item_subscription->next_bill) {
        free(domain_list_item_subscription->next_bill);
        domain_list_item_subscription->next_bill = NULL;
    }
    if (domain_list_item_subscription->last_usage_bill) {
        free(domain_list_item_subscription->last_usage_bill);
        domain_list_item_subscription->last_usage_bill = NULL;
    }
    if (domain_list_item_subscription->last_payment_attempt) {
        free(domain_list_item_subscription->last_payment_attempt);
        domain_list_item_subscription->last_payment_attempt = NULL;
    }
    if (domain_list_item_subscription->created_at) {
        free(domain_list_item_subscription->created_at);
        domain_list_item_subscription->created_at = NULL;
    }
    if (domain_list_item_subscription->updated_at) {
        free(domain_list_item_subscription->updated_at);
        domain_list_item_subscription->updated_at = NULL;
    }
    free(domain_list_item_subscription);
}

cJSON *domain_list_item_subscription_convertToJSON(domain_list_item_subscription_t *domain_list_item_subscription) {
    cJSON *item = cJSON_CreateObject();

    // domain_list_item_subscription->renew_action
    if(domain_list_item_subscription->renew_action) {
    cJSON *renew_action_object = object_convertToJSON(domain_list_item_subscription->renew_action);
    if(renew_action_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "renewAction", renew_action_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // domain_list_item_subscription->domain
    if (!domain_list_item_subscription->domain) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "domain", domain_list_item_subscription->domain) == NULL) {
    goto fail; //String
    }


    // domain_list_item_subscription->billing_type
    if (corellium_api_domain_list_item_subscription_BILLINGTYPE_NULL == domain_list_item_subscription->billing_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "billingType", domain_list_item_subscription_billing_type_ToString(domain_list_item_subscription->billing_type)) == NULL)
    {
    goto fail; //Enum
    }


    // domain_list_item_subscription->billing_backend
    if (!domain_list_item_subscription->billing_backend) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "billingBackend", domain_list_item_subscription->billing_backend) == NULL) {
    goto fail; //String
    }


    // domain_list_item_subscription->billing_id
    if(domain_list_item_subscription->billing_id) {
    if(cJSON_AddStringToObject(item, "billingId", domain_list_item_subscription->billing_id) == NULL) {
    goto fail; //String
    }
    }


    // domain_list_item_subscription->next_bill
    if(domain_list_item_subscription->next_bill) {
    if(cJSON_AddStringToObject(item, "nextBill", domain_list_item_subscription->next_bill) == NULL) {
    goto fail; //Date-Time
    }
    }


    // domain_list_item_subscription->usage_based
    if (!domain_list_item_subscription->usage_based) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "usageBased", domain_list_item_subscription->usage_based) == NULL) {
    goto fail; //Bool
    }


    // domain_list_item_subscription->last_usage_bill
    if(domain_list_item_subscription->last_usage_bill) {
    if(cJSON_AddStringToObject(item, "lastUsageBill", domain_list_item_subscription->last_usage_bill) == NULL) {
    goto fail; //Date-Time
    }
    }


    // domain_list_item_subscription->last_payment_amount
    if(domain_list_item_subscription->last_payment_amount) {
    if(cJSON_AddNumberToObject(item, "lastPaymentAmount", domain_list_item_subscription->last_payment_amount) == NULL) {
    goto fail; //Numeric
    }
    }


    // domain_list_item_subscription->usage_bill_interval_days
    if(domain_list_item_subscription->usage_bill_interval_days) {
    if(cJSON_AddNumberToObject(item, "usageBillIntervalDays", domain_list_item_subscription->usage_bill_interval_days) == NULL) {
    goto fail; //Numeric
    }
    }


    // domain_list_item_subscription->usage_billing_threshold_dollars
    if(domain_list_item_subscription->usage_billing_threshold_dollars) {
    if(cJSON_AddNumberToObject(item, "usageBillingThresholdDollars", domain_list_item_subscription->usage_billing_threshold_dollars) == NULL) {
    goto fail; //Numeric
    }
    }


    // domain_list_item_subscription->past_due
    if(domain_list_item_subscription->past_due) {
    if(cJSON_AddBoolToObject(item, "pastDue", domain_list_item_subscription->past_due) == NULL) {
    goto fail; //Bool
    }
    }


    // domain_list_item_subscription->payment_attempts
    if(domain_list_item_subscription->payment_attempts) {
    if(cJSON_AddNumberToObject(item, "paymentAttempts", domain_list_item_subscription->payment_attempts) == NULL) {
    goto fail; //Numeric
    }
    }


    // domain_list_item_subscription->last_payment_attempt
    if(domain_list_item_subscription->last_payment_attempt) {
    if(cJSON_AddStringToObject(item, "lastPaymentAttempt", domain_list_item_subscription->last_payment_attempt) == NULL) {
    goto fail; //Date-Time
    }
    }


    // domain_list_item_subscription->created_at
    if (!domain_list_item_subscription->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "createdAt", domain_list_item_subscription->created_at) == NULL) {
    goto fail; //Date-Time
    }


    // domain_list_item_subscription->updated_at
    if (!domain_list_item_subscription->updated_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "updatedAt", domain_list_item_subscription->updated_at) == NULL) {
    goto fail; //Date-Time
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

domain_list_item_subscription_t *domain_list_item_subscription_parseFromJSON(cJSON *domain_list_item_subscriptionJSON){

    domain_list_item_subscription_t *domain_list_item_subscription_local_var = NULL;

    // domain_list_item_subscription->renew_action
    cJSON *renew_action = cJSON_GetObjectItemCaseSensitive(domain_list_item_subscriptionJSON, "renewAction");
    if (cJSON_IsNull(renew_action)) {
        renew_action = NULL;
    }
    object_t *renew_action_local_object = NULL;
    if (renew_action) { 
    renew_action_local_object = object_parseFromJSON(renew_action); //object
    }

    // domain_list_item_subscription->domain
    cJSON *domain = cJSON_GetObjectItemCaseSensitive(domain_list_item_subscriptionJSON, "domain");
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

    // domain_list_item_subscription->billing_type
    cJSON *billing_type = cJSON_GetObjectItemCaseSensitive(domain_list_item_subscriptionJSON, "billingType");
    if (cJSON_IsNull(billing_type)) {
        billing_type = NULL;
    }
    if (!billing_type) {
        goto end;
    }

    corellium_api_domain_list_item_subscription_BILLINGTYPE_e billing_typeVariable;
    
    if(!cJSON_IsString(billing_type))
    {
    goto end; //Enum
    }
    billing_typeVariable = domain_list_item_subscription_billing_type_FromString(billing_type->valuestring);

    // domain_list_item_subscription->billing_backend
    cJSON *billing_backend = cJSON_GetObjectItemCaseSensitive(domain_list_item_subscriptionJSON, "billingBackend");
    if (cJSON_IsNull(billing_backend)) {
        billing_backend = NULL;
    }
    if (!billing_backend) {
        goto end;
    }

    
    if(!cJSON_IsString(billing_backend))
    {
    goto end; //String
    }

    // domain_list_item_subscription->billing_id
    cJSON *billing_id = cJSON_GetObjectItemCaseSensitive(domain_list_item_subscriptionJSON, "billingId");
    if (cJSON_IsNull(billing_id)) {
        billing_id = NULL;
    }
    if (billing_id) { 
    if(!cJSON_IsString(billing_id) && !cJSON_IsNull(billing_id))
    {
    goto end; //String
    }
    }

    // domain_list_item_subscription->next_bill
    cJSON *next_bill = cJSON_GetObjectItemCaseSensitive(domain_list_item_subscriptionJSON, "nextBill");
    if (cJSON_IsNull(next_bill)) {
        next_bill = NULL;
    }
    if (next_bill) { 
    if(!cJSON_IsString(next_bill) && !cJSON_IsNull(next_bill))
    {
    goto end; //DateTime
    }
    }

    // domain_list_item_subscription->usage_based
    cJSON *usage_based = cJSON_GetObjectItemCaseSensitive(domain_list_item_subscriptionJSON, "usageBased");
    if (cJSON_IsNull(usage_based)) {
        usage_based = NULL;
    }
    if (!usage_based) {
        goto end;
    }

    
    if(!cJSON_IsBool(usage_based))
    {
    goto end; //Bool
    }

    // domain_list_item_subscription->last_usage_bill
    cJSON *last_usage_bill = cJSON_GetObjectItemCaseSensitive(domain_list_item_subscriptionJSON, "lastUsageBill");
    if (cJSON_IsNull(last_usage_bill)) {
        last_usage_bill = NULL;
    }
    if (last_usage_bill) { 
    if(!cJSON_IsString(last_usage_bill) && !cJSON_IsNull(last_usage_bill))
    {
    goto end; //DateTime
    }
    }

    // domain_list_item_subscription->last_payment_amount
    cJSON *last_payment_amount = cJSON_GetObjectItemCaseSensitive(domain_list_item_subscriptionJSON, "lastPaymentAmount");
    if (cJSON_IsNull(last_payment_amount)) {
        last_payment_amount = NULL;
    }
    if (last_payment_amount) { 
    if(!cJSON_IsNumber(last_payment_amount))
    {
    goto end; //Numeric
    }
    }

    // domain_list_item_subscription->usage_bill_interval_days
    cJSON *usage_bill_interval_days = cJSON_GetObjectItemCaseSensitive(domain_list_item_subscriptionJSON, "usageBillIntervalDays");
    if (cJSON_IsNull(usage_bill_interval_days)) {
        usage_bill_interval_days = NULL;
    }
    if (usage_bill_interval_days) { 
    if(!cJSON_IsNumber(usage_bill_interval_days))
    {
    goto end; //Numeric
    }
    }

    // domain_list_item_subscription->usage_billing_threshold_dollars
    cJSON *usage_billing_threshold_dollars = cJSON_GetObjectItemCaseSensitive(domain_list_item_subscriptionJSON, "usageBillingThresholdDollars");
    if (cJSON_IsNull(usage_billing_threshold_dollars)) {
        usage_billing_threshold_dollars = NULL;
    }
    if (usage_billing_threshold_dollars) { 
    if(!cJSON_IsNumber(usage_billing_threshold_dollars))
    {
    goto end; //Numeric
    }
    }

    // domain_list_item_subscription->past_due
    cJSON *past_due = cJSON_GetObjectItemCaseSensitive(domain_list_item_subscriptionJSON, "pastDue");
    if (cJSON_IsNull(past_due)) {
        past_due = NULL;
    }
    if (past_due) { 
    if(!cJSON_IsBool(past_due))
    {
    goto end; //Bool
    }
    }

    // domain_list_item_subscription->payment_attempts
    cJSON *payment_attempts = cJSON_GetObjectItemCaseSensitive(domain_list_item_subscriptionJSON, "paymentAttempts");
    if (cJSON_IsNull(payment_attempts)) {
        payment_attempts = NULL;
    }
    if (payment_attempts) { 
    if(!cJSON_IsNumber(payment_attempts))
    {
    goto end; //Numeric
    }
    }

    // domain_list_item_subscription->last_payment_attempt
    cJSON *last_payment_attempt = cJSON_GetObjectItemCaseSensitive(domain_list_item_subscriptionJSON, "lastPaymentAttempt");
    if (cJSON_IsNull(last_payment_attempt)) {
        last_payment_attempt = NULL;
    }
    if (last_payment_attempt) { 
    if(!cJSON_IsString(last_payment_attempt) && !cJSON_IsNull(last_payment_attempt))
    {
    goto end; //DateTime
    }
    }

    // domain_list_item_subscription->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(domain_list_item_subscriptionJSON, "createdAt");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (!created_at) {
        goto end;
    }

    
    if(!cJSON_IsString(created_at) && !cJSON_IsNull(created_at))
    {
    goto end; //DateTime
    }

    // domain_list_item_subscription->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(domain_list_item_subscriptionJSON, "updatedAt");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (!updated_at) {
        goto end;
    }

    
    if(!cJSON_IsString(updated_at) && !cJSON_IsNull(updated_at))
    {
    goto end; //DateTime
    }


    domain_list_item_subscription_local_var = domain_list_item_subscription_create_internal (
        renew_action ? renew_action_local_object : NULL,
        strdup(domain->valuestring),
        billing_typeVariable,
        strdup(billing_backend->valuestring),
        billing_id && !cJSON_IsNull(billing_id) ? strdup(billing_id->valuestring) : NULL,
        next_bill && !cJSON_IsNull(next_bill) ? strdup(next_bill->valuestring) : NULL,
        usage_based->valueint,
        last_usage_bill && !cJSON_IsNull(last_usage_bill) ? strdup(last_usage_bill->valuestring) : NULL,
        last_payment_amount ? last_payment_amount->valuedouble : 0,
        usage_bill_interval_days ? usage_bill_interval_days->valuedouble : 0,
        usage_billing_threshold_dollars ? usage_billing_threshold_dollars->valuedouble : 0,
        past_due ? past_due->valueint : 0,
        payment_attempts ? payment_attempts->valuedouble : 0,
        last_payment_attempt && !cJSON_IsNull(last_payment_attempt) ? strdup(last_payment_attempt->valuestring) : NULL,
        strdup(created_at->valuestring),
        strdup(updated_at->valuestring)
        );

    return domain_list_item_subscription_local_var;
end:
    return NULL;

}
