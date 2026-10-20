#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "metered_subscription_usage.h"



static metered_subscription_usage_t *metered_subscription_usage_create_internal(
    double burst_rate,
    double allocated_hours,
    double plan_billed_amount,
    double burst_billed_amount,
    double burst_billed_units,
    double burst_outstanding_amount,
    double burst_outstanding_units,
    double total_usage_amount,
    double total_used_units
    ) {
    metered_subscription_usage_t *metered_subscription_usage_local_var = malloc(sizeof(metered_subscription_usage_t));
    if (!metered_subscription_usage_local_var) {
        return NULL;
    }
    metered_subscription_usage_local_var->burst_rate = burst_rate;
    metered_subscription_usage_local_var->allocated_hours = allocated_hours;
    metered_subscription_usage_local_var->plan_billed_amount = plan_billed_amount;
    metered_subscription_usage_local_var->burst_billed_amount = burst_billed_amount;
    metered_subscription_usage_local_var->burst_billed_units = burst_billed_units;
    metered_subscription_usage_local_var->burst_outstanding_amount = burst_outstanding_amount;
    metered_subscription_usage_local_var->burst_outstanding_units = burst_outstanding_units;
    metered_subscription_usage_local_var->total_usage_amount = total_usage_amount;
    metered_subscription_usage_local_var->total_used_units = total_used_units;

    metered_subscription_usage_local_var->_library_owned = 1;
    return metered_subscription_usage_local_var;
}

__attribute__((deprecated)) metered_subscription_usage_t *metered_subscription_usage_create(
    double burst_rate,
    double allocated_hours,
    double plan_billed_amount,
    double burst_billed_amount,
    double burst_billed_units,
    double burst_outstanding_amount,
    double burst_outstanding_units,
    double total_usage_amount,
    double total_used_units
    ) {
    return metered_subscription_usage_create_internal (
        burst_rate,
        allocated_hours,
        plan_billed_amount,
        burst_billed_amount,
        burst_billed_units,
        burst_outstanding_amount,
        burst_outstanding_units,
        total_usage_amount,
        total_used_units
        );
}

void metered_subscription_usage_free(metered_subscription_usage_t *metered_subscription_usage) {
    if(NULL == metered_subscription_usage){
        return ;
    }
    if(metered_subscription_usage->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "metered_subscription_usage_free");
        return ;
    }
    listEntry_t *listEntry;
    free(metered_subscription_usage);
}

cJSON *metered_subscription_usage_convertToJSON(metered_subscription_usage_t *metered_subscription_usage) {
    cJSON *item = cJSON_CreateObject();

    // metered_subscription_usage->burst_rate
    if (!metered_subscription_usage->burst_rate) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "burstRate", metered_subscription_usage->burst_rate) == NULL) {
    goto fail; //Numeric
    }


    // metered_subscription_usage->allocated_hours
    if (!metered_subscription_usage->allocated_hours) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "allocatedHours", metered_subscription_usage->allocated_hours) == NULL) {
    goto fail; //Numeric
    }


    // metered_subscription_usage->plan_billed_amount
    if (!metered_subscription_usage->plan_billed_amount) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "planBilledAmount", metered_subscription_usage->plan_billed_amount) == NULL) {
    goto fail; //Numeric
    }


    // metered_subscription_usage->burst_billed_amount
    if (!metered_subscription_usage->burst_billed_amount) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "burstBilledAmount", metered_subscription_usage->burst_billed_amount) == NULL) {
    goto fail; //Numeric
    }


    // metered_subscription_usage->burst_billed_units
    if (!metered_subscription_usage->burst_billed_units) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "burstBilledUnits", metered_subscription_usage->burst_billed_units) == NULL) {
    goto fail; //Numeric
    }


    // metered_subscription_usage->burst_outstanding_amount
    if (!metered_subscription_usage->burst_outstanding_amount) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "burstOutstandingAmount", metered_subscription_usage->burst_outstanding_amount) == NULL) {
    goto fail; //Numeric
    }


    // metered_subscription_usage->burst_outstanding_units
    if (!metered_subscription_usage->burst_outstanding_units) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "burstOutstandingUnits", metered_subscription_usage->burst_outstanding_units) == NULL) {
    goto fail; //Numeric
    }


    // metered_subscription_usage->total_usage_amount
    if (!metered_subscription_usage->total_usage_amount) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "totalUsageAmount", metered_subscription_usage->total_usage_amount) == NULL) {
    goto fail; //Numeric
    }


    // metered_subscription_usage->total_used_units
    if (!metered_subscription_usage->total_used_units) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "totalUsedUnits", metered_subscription_usage->total_used_units) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

metered_subscription_usage_t *metered_subscription_usage_parseFromJSON(cJSON *metered_subscription_usageJSON){

    metered_subscription_usage_t *metered_subscription_usage_local_var = NULL;

    // metered_subscription_usage->burst_rate
    cJSON *burst_rate = cJSON_GetObjectItemCaseSensitive(metered_subscription_usageJSON, "burstRate");
    if (cJSON_IsNull(burst_rate)) {
        burst_rate = NULL;
    }
    if (!burst_rate) {
        goto end;
    }

    
    if(!cJSON_IsNumber(burst_rate))
    {
    goto end; //Numeric
    }

    // metered_subscription_usage->allocated_hours
    cJSON *allocated_hours = cJSON_GetObjectItemCaseSensitive(metered_subscription_usageJSON, "allocatedHours");
    if (cJSON_IsNull(allocated_hours)) {
        allocated_hours = NULL;
    }
    if (!allocated_hours) {
        goto end;
    }

    
    if(!cJSON_IsNumber(allocated_hours))
    {
    goto end; //Numeric
    }

    // metered_subscription_usage->plan_billed_amount
    cJSON *plan_billed_amount = cJSON_GetObjectItemCaseSensitive(metered_subscription_usageJSON, "planBilledAmount");
    if (cJSON_IsNull(plan_billed_amount)) {
        plan_billed_amount = NULL;
    }
    if (!plan_billed_amount) {
        goto end;
    }

    
    if(!cJSON_IsNumber(plan_billed_amount))
    {
    goto end; //Numeric
    }

    // metered_subscription_usage->burst_billed_amount
    cJSON *burst_billed_amount = cJSON_GetObjectItemCaseSensitive(metered_subscription_usageJSON, "burstBilledAmount");
    if (cJSON_IsNull(burst_billed_amount)) {
        burst_billed_amount = NULL;
    }
    if (!burst_billed_amount) {
        goto end;
    }

    
    if(!cJSON_IsNumber(burst_billed_amount))
    {
    goto end; //Numeric
    }

    // metered_subscription_usage->burst_billed_units
    cJSON *burst_billed_units = cJSON_GetObjectItemCaseSensitive(metered_subscription_usageJSON, "burstBilledUnits");
    if (cJSON_IsNull(burst_billed_units)) {
        burst_billed_units = NULL;
    }
    if (!burst_billed_units) {
        goto end;
    }

    
    if(!cJSON_IsNumber(burst_billed_units))
    {
    goto end; //Numeric
    }

    // metered_subscription_usage->burst_outstanding_amount
    cJSON *burst_outstanding_amount = cJSON_GetObjectItemCaseSensitive(metered_subscription_usageJSON, "burstOutstandingAmount");
    if (cJSON_IsNull(burst_outstanding_amount)) {
        burst_outstanding_amount = NULL;
    }
    if (!burst_outstanding_amount) {
        goto end;
    }

    
    if(!cJSON_IsNumber(burst_outstanding_amount))
    {
    goto end; //Numeric
    }

    // metered_subscription_usage->burst_outstanding_units
    cJSON *burst_outstanding_units = cJSON_GetObjectItemCaseSensitive(metered_subscription_usageJSON, "burstOutstandingUnits");
    if (cJSON_IsNull(burst_outstanding_units)) {
        burst_outstanding_units = NULL;
    }
    if (!burst_outstanding_units) {
        goto end;
    }

    
    if(!cJSON_IsNumber(burst_outstanding_units))
    {
    goto end; //Numeric
    }

    // metered_subscription_usage->total_usage_amount
    cJSON *total_usage_amount = cJSON_GetObjectItemCaseSensitive(metered_subscription_usageJSON, "totalUsageAmount");
    if (cJSON_IsNull(total_usage_amount)) {
        total_usage_amount = NULL;
    }
    if (!total_usage_amount) {
        goto end;
    }

    
    if(!cJSON_IsNumber(total_usage_amount))
    {
    goto end; //Numeric
    }

    // metered_subscription_usage->total_used_units
    cJSON *total_used_units = cJSON_GetObjectItemCaseSensitive(metered_subscription_usageJSON, "totalUsedUnits");
    if (cJSON_IsNull(total_used_units)) {
        total_used_units = NULL;
    }
    if (!total_used_units) {
        goto end;
    }

    
    if(!cJSON_IsNumber(total_used_units))
    {
    goto end; //Numeric
    }


    metered_subscription_usage_local_var = metered_subscription_usage_create_internal (
        burst_rate->valuedouble,
        allocated_hours->valuedouble,
        plan_billed_amount->valuedouble,
        burst_billed_amount->valuedouble,
        burst_billed_units->valuedouble,
        burst_outstanding_amount->valuedouble,
        burst_outstanding_units->valuedouble,
        total_usage_amount->valuedouble,
        total_used_units->valuedouble
        );

    return metered_subscription_usage_local_var;
end:
    return NULL;

}
