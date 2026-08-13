#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "assessment_history_results_inner.h"



static assessment_history_results_inner_t *assessment_history_results_inner_create_internal(
    char *date,
    double complete,
    double incomplete
    ) {
    assessment_history_results_inner_t *assessment_history_results_inner_local_var = malloc(sizeof(assessment_history_results_inner_t));
    if (!assessment_history_results_inner_local_var) {
        return NULL;
    }
    assessment_history_results_inner_local_var->date = date;
    assessment_history_results_inner_local_var->complete = complete;
    assessment_history_results_inner_local_var->incomplete = incomplete;

    assessment_history_results_inner_local_var->_library_owned = 1;
    return assessment_history_results_inner_local_var;
}

__attribute__((deprecated)) assessment_history_results_inner_t *assessment_history_results_inner_create(
    char *date,
    double complete,
    double incomplete
    ) {
    return assessment_history_results_inner_create_internal (
        date,
        complete,
        incomplete
        );
}

void assessment_history_results_inner_free(assessment_history_results_inner_t *assessment_history_results_inner) {
    if(NULL == assessment_history_results_inner){
        return ;
    }
    if(assessment_history_results_inner->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "assessment_history_results_inner_free");
        return ;
    }
    listEntry_t *listEntry;
    if (assessment_history_results_inner->date) {
        free(assessment_history_results_inner->date);
        assessment_history_results_inner->date = NULL;
    }
    free(assessment_history_results_inner);
}

cJSON *assessment_history_results_inner_convertToJSON(assessment_history_results_inner_t *assessment_history_results_inner) {
    cJSON *item = cJSON_CreateObject();

    // assessment_history_results_inner->date
    if (!assessment_history_results_inner->date) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "date", assessment_history_results_inner->date) == NULL) {
    goto fail; //String
    }


    // assessment_history_results_inner->complete
    if (!assessment_history_results_inner->complete) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "complete", assessment_history_results_inner->complete) == NULL) {
    goto fail; //Numeric
    }


    // assessment_history_results_inner->incomplete
    if (!assessment_history_results_inner->incomplete) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "incomplete", assessment_history_results_inner->incomplete) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

assessment_history_results_inner_t *assessment_history_results_inner_parseFromJSON(cJSON *assessment_history_results_innerJSON){

    assessment_history_results_inner_t *assessment_history_results_inner_local_var = NULL;

    // assessment_history_results_inner->date
    cJSON *date = cJSON_GetObjectItemCaseSensitive(assessment_history_results_innerJSON, "date");
    if (cJSON_IsNull(date)) {
        date = NULL;
    }
    if (!date) {
        goto end;
    }

    
    if(!cJSON_IsString(date))
    {
    goto end; //String
    }

    // assessment_history_results_inner->complete
    cJSON *complete = cJSON_GetObjectItemCaseSensitive(assessment_history_results_innerJSON, "complete");
    if (cJSON_IsNull(complete)) {
        complete = NULL;
    }
    if (!complete) {
        goto end;
    }

    
    if(!cJSON_IsNumber(complete))
    {
    goto end; //Numeric
    }

    // assessment_history_results_inner->incomplete
    cJSON *incomplete = cJSON_GetObjectItemCaseSensitive(assessment_history_results_innerJSON, "incomplete");
    if (cJSON_IsNull(incomplete)) {
        incomplete = NULL;
    }
    if (!incomplete) {
        goto end;
    }

    
    if(!cJSON_IsNumber(incomplete))
    {
    goto end; //Numeric
    }


    assessment_history_results_inner_local_var = assessment_history_results_inner_create_internal (
        strdup(date->valuestring),
        complete->valuedouble,
        incomplete->valuedouble
        );

    return assessment_history_results_inner_local_var;
end:
    return NULL;

}
