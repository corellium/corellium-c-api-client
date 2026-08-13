#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "subscription_trial.h"


char* subscription_trial_status_ToString(corellium_api_subscription_trial_STATUS_e status) {
    char* statusArray[] =  { "NULL", "not_started", "active", "completed" };
    return statusArray[status];
}

corellium_api_subscription_trial_STATUS_e subscription_trial_status_FromString(char* status){
    int stringToReturn = 0;
    char *statusArray[] =  { "NULL", "not_started", "active", "completed" };
    size_t sizeofArray = sizeof(statusArray) / sizeof(statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(status, statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static subscription_trial_t *subscription_trial_create_internal(
    corellium_api_subscription_trial_STATUS_e status,
    char *start,
    char *end,
    double used_hours,
    double max_hours
    ) {
    subscription_trial_t *subscription_trial_local_var = malloc(sizeof(subscription_trial_t));
    if (!subscription_trial_local_var) {
        return NULL;
    }
    subscription_trial_local_var->status = status;
    subscription_trial_local_var->start = start;
    subscription_trial_local_var->end = end;
    subscription_trial_local_var->used_hours = used_hours;
    subscription_trial_local_var->max_hours = max_hours;

    subscription_trial_local_var->_library_owned = 1;
    return subscription_trial_local_var;
}

__attribute__((deprecated)) subscription_trial_t *subscription_trial_create(
    corellium_api_subscription_trial_STATUS_e status,
    char *start,
    char *end,
    double used_hours,
    double max_hours
    ) {
    return subscription_trial_create_internal (
        status,
        start,
        end,
        used_hours,
        max_hours
        );
}

void subscription_trial_free(subscription_trial_t *subscription_trial) {
    if(NULL == subscription_trial){
        return ;
    }
    if(subscription_trial->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "subscription_trial_free");
        return ;
    }
    listEntry_t *listEntry;
    if (subscription_trial->start) {
        free(subscription_trial->start);
        subscription_trial->start = NULL;
    }
    if (subscription_trial->end) {
        free(subscription_trial->end);
        subscription_trial->end = NULL;
    }
    free(subscription_trial);
}

cJSON *subscription_trial_convertToJSON(subscription_trial_t *subscription_trial) {
    cJSON *item = cJSON_CreateObject();

    // subscription_trial->status
    if (corellium_api_subscription_trial_STATUS_NULL == subscription_trial->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", subscription_trial_status_ToString(subscription_trial->status)) == NULL)
    {
    goto fail; //Enum
    }


    // subscription_trial->start
    if(subscription_trial->start) {
    if(cJSON_AddStringToObject(item, "start", subscription_trial->start) == NULL) {
    goto fail; //Date-Time
    }
    }


    // subscription_trial->end
    if(subscription_trial->end) {
    if(cJSON_AddStringToObject(item, "end", subscription_trial->end) == NULL) {
    goto fail; //Date-Time
    }
    }


    // subscription_trial->used_hours
    if(subscription_trial->used_hours) {
    if(cJSON_AddNumberToObject(item, "usedHours", subscription_trial->used_hours) == NULL) {
    goto fail; //Numeric
    }
    }


    // subscription_trial->max_hours
    if(subscription_trial->max_hours) {
    if(cJSON_AddNumberToObject(item, "maxHours", subscription_trial->max_hours) == NULL) {
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

subscription_trial_t *subscription_trial_parseFromJSON(cJSON *subscription_trialJSON){

    subscription_trial_t *subscription_trial_local_var = NULL;

    // subscription_trial->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(subscription_trialJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    corellium_api_subscription_trial_STATUS_e statusVariable;
    
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = subscription_trial_status_FromString(status->valuestring);

    // subscription_trial->start
    cJSON *start = cJSON_GetObjectItemCaseSensitive(subscription_trialJSON, "start");
    if (cJSON_IsNull(start)) {
        start = NULL;
    }
    if (start) { 
    if(!cJSON_IsString(start) && !cJSON_IsNull(start))
    {
    goto end; //DateTime
    }
    }

    // subscription_trial->end
    cJSON *end = cJSON_GetObjectItemCaseSensitive(subscription_trialJSON, "end");
    if (cJSON_IsNull(end)) {
        end = NULL;
    }
    if (end) { 
    if(!cJSON_IsString(end) && !cJSON_IsNull(end))
    {
    goto end; //DateTime
    }
    }

    // subscription_trial->used_hours
    cJSON *used_hours = cJSON_GetObjectItemCaseSensitive(subscription_trialJSON, "usedHours");
    if (cJSON_IsNull(used_hours)) {
        used_hours = NULL;
    }
    if (used_hours) { 
    if(!cJSON_IsNumber(used_hours))
    {
    goto end; //Numeric
    }
    }

    // subscription_trial->max_hours
    cJSON *max_hours = cJSON_GetObjectItemCaseSensitive(subscription_trialJSON, "maxHours");
    if (cJSON_IsNull(max_hours)) {
        max_hours = NULL;
    }
    if (max_hours) { 
    if(!cJSON_IsNumber(max_hours))
    {
    goto end; //Numeric
    }
    }


    subscription_trial_local_var = subscription_trial_create_internal (
        statusVariable,
        start && !cJSON_IsNull(start) ? strdup(start->valuestring) : NULL,
        end && !cJSON_IsNull(end) ? strdup(end->valuestring) : NULL,
        used_hours ? used_hours->valuedouble : 0,
        max_hours ? max_hours->valuedouble : 0
        );

    return subscription_trial_local_var;
end:
    return NULL;

}
