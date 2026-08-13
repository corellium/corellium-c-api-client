#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "assessment_severity_counts.h"



static assessment_severity_counts_t *assessment_severity_counts_create_internal(
    double high,
    double medium,
    double low,
    double info
    ) {
    assessment_severity_counts_t *assessment_severity_counts_local_var = malloc(sizeof(assessment_severity_counts_t));
    if (!assessment_severity_counts_local_var) {
        return NULL;
    }
    assessment_severity_counts_local_var->high = high;
    assessment_severity_counts_local_var->medium = medium;
    assessment_severity_counts_local_var->low = low;
    assessment_severity_counts_local_var->info = info;

    assessment_severity_counts_local_var->_library_owned = 1;
    return assessment_severity_counts_local_var;
}

__attribute__((deprecated)) assessment_severity_counts_t *assessment_severity_counts_create(
    double high,
    double medium,
    double low,
    double info
    ) {
    return assessment_severity_counts_create_internal (
        high,
        medium,
        low,
        info
        );
}

void assessment_severity_counts_free(assessment_severity_counts_t *assessment_severity_counts) {
    if(NULL == assessment_severity_counts){
        return ;
    }
    if(assessment_severity_counts->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "assessment_severity_counts_free");
        return ;
    }
    listEntry_t *listEntry;
    free(assessment_severity_counts);
}

cJSON *assessment_severity_counts_convertToJSON(assessment_severity_counts_t *assessment_severity_counts) {
    cJSON *item = cJSON_CreateObject();

    // assessment_severity_counts->high
    if (!assessment_severity_counts->high) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "high", assessment_severity_counts->high) == NULL) {
    goto fail; //Numeric
    }


    // assessment_severity_counts->medium
    if (!assessment_severity_counts->medium) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "medium", assessment_severity_counts->medium) == NULL) {
    goto fail; //Numeric
    }


    // assessment_severity_counts->low
    if (!assessment_severity_counts->low) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "low", assessment_severity_counts->low) == NULL) {
    goto fail; //Numeric
    }


    // assessment_severity_counts->info
    if (!assessment_severity_counts->info) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "info", assessment_severity_counts->info) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

assessment_severity_counts_t *assessment_severity_counts_parseFromJSON(cJSON *assessment_severity_countsJSON){

    assessment_severity_counts_t *assessment_severity_counts_local_var = NULL;

    // assessment_severity_counts->high
    cJSON *high = cJSON_GetObjectItemCaseSensitive(assessment_severity_countsJSON, "high");
    if (cJSON_IsNull(high)) {
        high = NULL;
    }
    if (!high) {
        goto end;
    }

    
    if(!cJSON_IsNumber(high))
    {
    goto end; //Numeric
    }

    // assessment_severity_counts->medium
    cJSON *medium = cJSON_GetObjectItemCaseSensitive(assessment_severity_countsJSON, "medium");
    if (cJSON_IsNull(medium)) {
        medium = NULL;
    }
    if (!medium) {
        goto end;
    }

    
    if(!cJSON_IsNumber(medium))
    {
    goto end; //Numeric
    }

    // assessment_severity_counts->low
    cJSON *low = cJSON_GetObjectItemCaseSensitive(assessment_severity_countsJSON, "low");
    if (cJSON_IsNull(low)) {
        low = NULL;
    }
    if (!low) {
        goto end;
    }

    
    if(!cJSON_IsNumber(low))
    {
    goto end; //Numeric
    }

    // assessment_severity_counts->info
    cJSON *info = cJSON_GetObjectItemCaseSensitive(assessment_severity_countsJSON, "info");
    if (cJSON_IsNull(info)) {
        info = NULL;
    }
    if (!info) {
        goto end;
    }

    
    if(!cJSON_IsNumber(info))
    {
    goto end; //Numeric
    }


    assessment_severity_counts_local_var = assessment_severity_counts_create_internal (
        high->valuedouble,
        medium->valuedouble,
        low->valuedouble,
        info->valuedouble
        );

    return assessment_severity_counts_local_var;
end:
    return NULL;

}
