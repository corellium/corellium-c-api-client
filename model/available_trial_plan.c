#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "available_trial_plan.h"



static available_trial_plan_t *available_trial_plan_create_internal(
    char *product_id,
    char *name,
    char *license,
    int workspace,
    double cores,
    double devices,
    double trial_duration
    ) {
    available_trial_plan_t *available_trial_plan_local_var = malloc(sizeof(available_trial_plan_t));
    if (!available_trial_plan_local_var) {
        return NULL;
    }
    available_trial_plan_local_var->product_id = product_id;
    available_trial_plan_local_var->name = name;
    available_trial_plan_local_var->license = license;
    available_trial_plan_local_var->workspace = workspace;
    available_trial_plan_local_var->cores = cores;
    available_trial_plan_local_var->devices = devices;
    available_trial_plan_local_var->trial_duration = trial_duration;

    available_trial_plan_local_var->_library_owned = 1;
    return available_trial_plan_local_var;
}

__attribute__((deprecated)) available_trial_plan_t *available_trial_plan_create(
    char *product_id,
    char *name,
    char *license,
    int workspace,
    double cores,
    double devices,
    double trial_duration
    ) {
    return available_trial_plan_create_internal (
        product_id,
        name,
        license,
        workspace,
        cores,
        devices,
        trial_duration
        );
}

void available_trial_plan_free(available_trial_plan_t *available_trial_plan) {
    if(NULL == available_trial_plan){
        return ;
    }
    if(available_trial_plan->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "available_trial_plan_free");
        return ;
    }
    listEntry_t *listEntry;
    if (available_trial_plan->product_id) {
        free(available_trial_plan->product_id);
        available_trial_plan->product_id = NULL;
    }
    if (available_trial_plan->name) {
        free(available_trial_plan->name);
        available_trial_plan->name = NULL;
    }
    if (available_trial_plan->license) {
        free(available_trial_plan->license);
        available_trial_plan->license = NULL;
    }
    free(available_trial_plan);
}

cJSON *available_trial_plan_convertToJSON(available_trial_plan_t *available_trial_plan) {
    cJSON *item = cJSON_CreateObject();

    // available_trial_plan->product_id
    if (!available_trial_plan->product_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "productId", available_trial_plan->product_id) == NULL) {
    goto fail; //String
    }


    // available_trial_plan->name
    if (!available_trial_plan->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", available_trial_plan->name) == NULL) {
    goto fail; //String
    }


    // available_trial_plan->license
    if (!available_trial_plan->license) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "license", available_trial_plan->license) == NULL) {
    goto fail; //String
    }


    // available_trial_plan->workspace
    if (!available_trial_plan->workspace) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "workspace", available_trial_plan->workspace) == NULL) {
    goto fail; //Bool
    }


    // available_trial_plan->cores
    if (!available_trial_plan->cores) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "cores", available_trial_plan->cores) == NULL) {
    goto fail; //Numeric
    }


    // available_trial_plan->devices
    if (!available_trial_plan->devices) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "devices", available_trial_plan->devices) == NULL) {
    goto fail; //Numeric
    }


    // available_trial_plan->trial_duration
    if (!available_trial_plan->trial_duration) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "trialDuration", available_trial_plan->trial_duration) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

available_trial_plan_t *available_trial_plan_parseFromJSON(cJSON *available_trial_planJSON){

    available_trial_plan_t *available_trial_plan_local_var = NULL;

    // available_trial_plan->product_id
    cJSON *product_id = cJSON_GetObjectItemCaseSensitive(available_trial_planJSON, "productId");
    if (cJSON_IsNull(product_id)) {
        product_id = NULL;
    }
    if (!product_id) {
        goto end;
    }

    
    if(!cJSON_IsString(product_id))
    {
    goto end; //String
    }

    // available_trial_plan->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(available_trial_planJSON, "name");
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

    // available_trial_plan->license
    cJSON *license = cJSON_GetObjectItemCaseSensitive(available_trial_planJSON, "license");
    if (cJSON_IsNull(license)) {
        license = NULL;
    }
    if (!license) {
        goto end;
    }

    
    if(!cJSON_IsString(license))
    {
    goto end; //String
    }

    // available_trial_plan->workspace
    cJSON *workspace = cJSON_GetObjectItemCaseSensitive(available_trial_planJSON, "workspace");
    if (cJSON_IsNull(workspace)) {
        workspace = NULL;
    }
    if (!workspace) {
        goto end;
    }

    
    if(!cJSON_IsBool(workspace))
    {
    goto end; //Bool
    }

    // available_trial_plan->cores
    cJSON *cores = cJSON_GetObjectItemCaseSensitive(available_trial_planJSON, "cores");
    if (cJSON_IsNull(cores)) {
        cores = NULL;
    }
    if (!cores) {
        goto end;
    }

    
    if(!cJSON_IsNumber(cores))
    {
    goto end; //Numeric
    }

    // available_trial_plan->devices
    cJSON *devices = cJSON_GetObjectItemCaseSensitive(available_trial_planJSON, "devices");
    if (cJSON_IsNull(devices)) {
        devices = NULL;
    }
    if (!devices) {
        goto end;
    }

    
    if(!cJSON_IsNumber(devices))
    {
    goto end; //Numeric
    }

    // available_trial_plan->trial_duration
    cJSON *trial_duration = cJSON_GetObjectItemCaseSensitive(available_trial_planJSON, "trialDuration");
    if (cJSON_IsNull(trial_duration)) {
        trial_duration = NULL;
    }
    if (!trial_duration) {
        goto end;
    }

    
    if(!cJSON_IsNumber(trial_duration))
    {
    goto end; //Numeric
    }


    available_trial_plan_local_var = available_trial_plan_create_internal (
        strdup(product_id->valuestring),
        strdup(name->valuestring),
        strdup(license->valuestring),
        workspace->valueint,
        cores->valuedouble,
        devices->valuedouble,
        trial_duration->valuedouble
        );

    return available_trial_plan_local_var;
end:
    return NULL;

}
