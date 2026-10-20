#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "metered_subscription_usage_v1.h"



static metered_subscription_usage_v1_t *metered_subscription_usage_v1_create_internal(
    double burst_rate,
    double allocated_hours,
    double plan_billed_amount,
    double plan_billed_units,
    double burst_billed_amount,
    double burst_billed_units,
    double burst_outstanding_amount,
    double burst_outstanding_units,
    double total_usage_amount,
    double total_used_units
    ) {
    metered_subscription_usage_v1_t *metered_subscription_usage_v1_local_var = malloc(sizeof(metered_subscription_usage_v1_t));
    if (!metered_subscription_usage_v1_local_var) {
        return NULL;
    }
    metered_subscription_usage_v1_local_var->burst_rate = burst_rate;
    metered_subscription_usage_v1_local_var->allocated_hours = allocated_hours;
    metered_subscription_usage_v1_local_var->plan_billed_amount = plan_billed_amount;
    metered_subscription_usage_v1_local_var->plan_billed_units = plan_billed_units;
    metered_subscription_usage_v1_local_var->burst_billed_amount = burst_billed_amount;
    metered_subscription_usage_v1_local_var->burst_billed_units = burst_billed_units;
    metered_subscription_usage_v1_local_var->burst_outstanding_amount = burst_outstanding_amount;
    metered_subscription_usage_v1_local_var->burst_outstanding_units = burst_outstanding_units;
    metered_subscription_usage_v1_local_var->total_usage_amount = total_usage_amount;
    metered_subscription_usage_v1_local_var->total_used_units = total_used_units;

    metered_subscription_usage_v1_local_var->_library_owned = 1;
    return metered_subscription_usage_v1_local_var;
}

__attribute__((deprecated)) metered_subscription_usage_v1_t *metered_subscription_usage_v1_create(
    double burst_rate,
    double allocated_hours,
    double plan_billed_amount,
    double plan_billed_units,
    double burst_billed_amount,
    double burst_billed_units,
    double burst_outstanding_amount,
    double burst_outstanding_units,
    double total_usage_amount,
    double total_used_units
    ) {
    return metered_subscription_usage_v1_create_internal (
        burst_rate,
        allocated_hours,
        plan_billed_amount,
        plan_billed_units,
        burst_billed_amount,
        burst_billed_units,
        burst_outstanding_amount,
        burst_outstanding_units,
        total_usage_amount,
        total_used_units
        );
}

void metered_subscription_usage_v1_free(metered_subscription_usage_v1_t *metered_subscription_usage_v1) {
    if(NULL == metered_subscription_usage_v1){
        return ;
    }
    if(metered_subscription_usage_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "metered_subscription_usage_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    free(metered_subscription_usage_v1);
}

cJSON *metered_subscription_usage_v1_convertToJSON(metered_subscription_usage_v1_t *metered_subscription_usage_v1) {
    cJSON *item = cJSON_CreateObject();

    // metered_subscription_usage_v1->burst_rate
    if(metered_subscription_usage_v1->burst_rate) {
    if(cJSON_AddNumberToObject(item, "burst_rate", metered_subscription_usage_v1->burst_rate) == NULL) {
    goto fail; //Numeric
    }
    }


    // metered_subscription_usage_v1->allocated_hours
    if(metered_subscription_usage_v1->allocated_hours) {
    if(cJSON_AddNumberToObject(item, "allocated_hours", metered_subscription_usage_v1->allocated_hours) == NULL) {
    goto fail; //Numeric
    }
    }


    // metered_subscription_usage_v1->plan_billed_amount
    if(metered_subscription_usage_v1->plan_billed_amount) {
    if(cJSON_AddNumberToObject(item, "plan_billed_amount", metered_subscription_usage_v1->plan_billed_amount) == NULL) {
    goto fail; //Numeric
    }
    }


    // metered_subscription_usage_v1->plan_billed_units
    if(metered_subscription_usage_v1->plan_billed_units) {
    if(cJSON_AddNumberToObject(item, "plan_billed_units", metered_subscription_usage_v1->plan_billed_units) == NULL) {
    goto fail; //Numeric
    }
    }


    // metered_subscription_usage_v1->burst_billed_amount
    if(metered_subscription_usage_v1->burst_billed_amount) {
    if(cJSON_AddNumberToObject(item, "burst_billed_amount", metered_subscription_usage_v1->burst_billed_amount) == NULL) {
    goto fail; //Numeric
    }
    }


    // metered_subscription_usage_v1->burst_billed_units
    if(metered_subscription_usage_v1->burst_billed_units) {
    if(cJSON_AddNumberToObject(item, "burst_billed_units", metered_subscription_usage_v1->burst_billed_units) == NULL) {
    goto fail; //Numeric
    }
    }


    // metered_subscription_usage_v1->burst_outstanding_amount
    if(metered_subscription_usage_v1->burst_outstanding_amount) {
    if(cJSON_AddNumberToObject(item, "burst_outstanding_amount", metered_subscription_usage_v1->burst_outstanding_amount) == NULL) {
    goto fail; //Numeric
    }
    }


    // metered_subscription_usage_v1->burst_outstanding_units
    if(metered_subscription_usage_v1->burst_outstanding_units) {
    if(cJSON_AddNumberToObject(item, "burst_outstanding_units", metered_subscription_usage_v1->burst_outstanding_units) == NULL) {
    goto fail; //Numeric
    }
    }


    // metered_subscription_usage_v1->total_usage_amount
    if(metered_subscription_usage_v1->total_usage_amount) {
    if(cJSON_AddNumberToObject(item, "total_usage_amount", metered_subscription_usage_v1->total_usage_amount) == NULL) {
    goto fail; //Numeric
    }
    }


    // metered_subscription_usage_v1->total_used_units
    if(metered_subscription_usage_v1->total_used_units) {
    if(cJSON_AddNumberToObject(item, "total_used_units", metered_subscription_usage_v1->total_used_units) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

metered_subscription_usage_v1_t *metered_subscription_usage_v1_parseFromJSON(cJSON *metered_subscription_usage_v1JSON){

    metered_subscription_usage_v1_t *metered_subscription_usage_v1_local_var = NULL;

    // metered_subscription_usage_v1->burst_rate
    cJSON *burst_rate = cJSON_GetObjectItemCaseSensitive(metered_subscription_usage_v1JSON, "burst_rate");
    if (cJSON_IsNull(burst_rate)) {
        burst_rate = NULL;
    }
    if (burst_rate) { 
    if(!cJSON_IsNumber(burst_rate))
    {
    goto end; //Numeric
    }
    }

    // metered_subscription_usage_v1->allocated_hours
    cJSON *allocated_hours = cJSON_GetObjectItemCaseSensitive(metered_subscription_usage_v1JSON, "allocated_hours");
    if (cJSON_IsNull(allocated_hours)) {
        allocated_hours = NULL;
    }
    if (allocated_hours) { 
    if(!cJSON_IsNumber(allocated_hours))
    {
    goto end; //Numeric
    }
    }

    // metered_subscription_usage_v1->plan_billed_amount
    cJSON *plan_billed_amount = cJSON_GetObjectItemCaseSensitive(metered_subscription_usage_v1JSON, "plan_billed_amount");
    if (cJSON_IsNull(plan_billed_amount)) {
        plan_billed_amount = NULL;
    }
    if (plan_billed_amount) { 
    if(!cJSON_IsNumber(plan_billed_amount))
    {
    goto end; //Numeric
    }
    }

    // metered_subscription_usage_v1->plan_billed_units
    cJSON *plan_billed_units = cJSON_GetObjectItemCaseSensitive(metered_subscription_usage_v1JSON, "plan_billed_units");
    if (cJSON_IsNull(plan_billed_units)) {
        plan_billed_units = NULL;
    }
    if (plan_billed_units) { 
    if(!cJSON_IsNumber(plan_billed_units))
    {
    goto end; //Numeric
    }
    }

    // metered_subscription_usage_v1->burst_billed_amount
    cJSON *burst_billed_amount = cJSON_GetObjectItemCaseSensitive(metered_subscription_usage_v1JSON, "burst_billed_amount");
    if (cJSON_IsNull(burst_billed_amount)) {
        burst_billed_amount = NULL;
    }
    if (burst_billed_amount) { 
    if(!cJSON_IsNumber(burst_billed_amount))
    {
    goto end; //Numeric
    }
    }

    // metered_subscription_usage_v1->burst_billed_units
    cJSON *burst_billed_units = cJSON_GetObjectItemCaseSensitive(metered_subscription_usage_v1JSON, "burst_billed_units");
    if (cJSON_IsNull(burst_billed_units)) {
        burst_billed_units = NULL;
    }
    if (burst_billed_units) { 
    if(!cJSON_IsNumber(burst_billed_units))
    {
    goto end; //Numeric
    }
    }

    // metered_subscription_usage_v1->burst_outstanding_amount
    cJSON *burst_outstanding_amount = cJSON_GetObjectItemCaseSensitive(metered_subscription_usage_v1JSON, "burst_outstanding_amount");
    if (cJSON_IsNull(burst_outstanding_amount)) {
        burst_outstanding_amount = NULL;
    }
    if (burst_outstanding_amount) { 
    if(!cJSON_IsNumber(burst_outstanding_amount))
    {
    goto end; //Numeric
    }
    }

    // metered_subscription_usage_v1->burst_outstanding_units
    cJSON *burst_outstanding_units = cJSON_GetObjectItemCaseSensitive(metered_subscription_usage_v1JSON, "burst_outstanding_units");
    if (cJSON_IsNull(burst_outstanding_units)) {
        burst_outstanding_units = NULL;
    }
    if (burst_outstanding_units) { 
    if(!cJSON_IsNumber(burst_outstanding_units))
    {
    goto end; //Numeric
    }
    }

    // metered_subscription_usage_v1->total_usage_amount
    cJSON *total_usage_amount = cJSON_GetObjectItemCaseSensitive(metered_subscription_usage_v1JSON, "total_usage_amount");
    if (cJSON_IsNull(total_usage_amount)) {
        total_usage_amount = NULL;
    }
    if (total_usage_amount) { 
    if(!cJSON_IsNumber(total_usage_amount))
    {
    goto end; //Numeric
    }
    }

    // metered_subscription_usage_v1->total_used_units
    cJSON *total_used_units = cJSON_GetObjectItemCaseSensitive(metered_subscription_usage_v1JSON, "total_used_units");
    if (cJSON_IsNull(total_used_units)) {
        total_used_units = NULL;
    }
    if (total_used_units) { 
    if(!cJSON_IsNumber(total_used_units))
    {
    goto end; //Numeric
    }
    }


    metered_subscription_usage_v1_local_var = metered_subscription_usage_v1_create_internal (
        burst_rate ? burst_rate->valuedouble : 0,
        allocated_hours ? allocated_hours->valuedouble : 0,
        plan_billed_amount ? plan_billed_amount->valuedouble : 0,
        plan_billed_units ? plan_billed_units->valuedouble : 0,
        burst_billed_amount ? burst_billed_amount->valuedouble : 0,
        burst_billed_units ? burst_billed_units->valuedouble : 0,
        burst_outstanding_amount ? burst_outstanding_amount->valuedouble : 0,
        burst_outstanding_units ? burst_outstanding_units->valuedouble : 0,
        total_usage_amount ? total_usage_amount->valuedouble : 0,
        total_used_units ? total_used_units->valuedouble : 0
        );

    return metered_subscription_usage_v1_local_var;
end:
    return NULL;

}
