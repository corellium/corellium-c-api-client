#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "assessment_results.h"



static assessment_results_t *assessment_results_create_internal(
    double pass,
    double fail,
    double error,
    double info,
    double na,
    double artifact,
    double score
    ) {
    assessment_results_t *assessment_results_local_var = malloc(sizeof(assessment_results_t));
    if (!assessment_results_local_var) {
        return NULL;
    }
    assessment_results_local_var->pass = pass;
    assessment_results_local_var->fail = fail;
    assessment_results_local_var->error = error;
    assessment_results_local_var->info = info;
    assessment_results_local_var->na = na;
    assessment_results_local_var->artifact = artifact;
    assessment_results_local_var->score = score;

    assessment_results_local_var->_library_owned = 1;
    return assessment_results_local_var;
}

__attribute__((deprecated)) assessment_results_t *assessment_results_create(
    double pass,
    double fail,
    double error,
    double info,
    double na,
    double artifact,
    double score
    ) {
    return assessment_results_create_internal (
        pass,
        fail,
        error,
        info,
        na,
        artifact,
        score
        );
}

void assessment_results_free(assessment_results_t *assessment_results) {
    if(NULL == assessment_results){
        return ;
    }
    if(assessment_results->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "assessment_results_free");
        return ;
    }
    listEntry_t *listEntry;
    free(assessment_results);
}

cJSON *assessment_results_convertToJSON(assessment_results_t *assessment_results) {
    cJSON *item = cJSON_CreateObject();

    // assessment_results->pass
    if (!assessment_results->pass) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "pass", assessment_results->pass) == NULL) {
    goto fail; //Numeric
    }


    // assessment_results->fail
    if (!assessment_results->fail) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "fail", assessment_results->fail) == NULL) {
    goto fail; //Numeric
    }


    // assessment_results->error
    if (!assessment_results->error) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "error", assessment_results->error) == NULL) {
    goto fail; //Numeric
    }


    // assessment_results->info
    if (!assessment_results->info) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "info", assessment_results->info) == NULL) {
    goto fail; //Numeric
    }


    // assessment_results->na
    if (!assessment_results->na) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "na", assessment_results->na) == NULL) {
    goto fail; //Numeric
    }


    // assessment_results->artifact
    if (!assessment_results->artifact) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "artifact", assessment_results->artifact) == NULL) {
    goto fail; //Numeric
    }


    // assessment_results->score
    if(assessment_results->score) {
    if(cJSON_AddNumberToObject(item, "score", assessment_results->score) == NULL) {
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

assessment_results_t *assessment_results_parseFromJSON(cJSON *assessment_resultsJSON){

    assessment_results_t *assessment_results_local_var = NULL;

    // assessment_results->pass
    cJSON *pass = cJSON_GetObjectItemCaseSensitive(assessment_resultsJSON, "pass");
    if (cJSON_IsNull(pass)) {
        pass = NULL;
    }
    if (!pass) {
        goto end;
    }

    
    if(!cJSON_IsNumber(pass))
    {
    goto end; //Numeric
    }

    // assessment_results->fail
    cJSON *fail = cJSON_GetObjectItemCaseSensitive(assessment_resultsJSON, "fail");
    if (cJSON_IsNull(fail)) {
        fail = NULL;
    }
    if (!fail) {
        goto end;
    }

    
    if(!cJSON_IsNumber(fail))
    {
    goto end; //Numeric
    }

    // assessment_results->error
    cJSON *error = cJSON_GetObjectItemCaseSensitive(assessment_resultsJSON, "error");
    if (cJSON_IsNull(error)) {
        error = NULL;
    }
    if (!error) {
        goto end;
    }

    
    if(!cJSON_IsNumber(error))
    {
    goto end; //Numeric
    }

    // assessment_results->info
    cJSON *info = cJSON_GetObjectItemCaseSensitive(assessment_resultsJSON, "info");
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

    // assessment_results->na
    cJSON *na = cJSON_GetObjectItemCaseSensitive(assessment_resultsJSON, "na");
    if (cJSON_IsNull(na)) {
        na = NULL;
    }
    if (!na) {
        goto end;
    }

    
    if(!cJSON_IsNumber(na))
    {
    goto end; //Numeric
    }

    // assessment_results->artifact
    cJSON *artifact = cJSON_GetObjectItemCaseSensitive(assessment_resultsJSON, "artifact");
    if (cJSON_IsNull(artifact)) {
        artifact = NULL;
    }
    if (!artifact) {
        goto end;
    }

    
    if(!cJSON_IsNumber(artifact))
    {
    goto end; //Numeric
    }

    // assessment_results->score
    cJSON *score = cJSON_GetObjectItemCaseSensitive(assessment_resultsJSON, "score");
    if (cJSON_IsNull(score)) {
        score = NULL;
    }
    if (score) { 
    if(!cJSON_IsNumber(score))
    {
    goto end; //Numeric
    }
    }


    assessment_results_local_var = assessment_results_create_internal (
        pass->valuedouble,
        fail->valuedouble,
        error->valuedouble,
        info->valuedouble,
        na->valuedouble,
        artifact->valuedouble,
        score ? score->valuedouble : 0
        );

    return assessment_results_local_var;
end:
    return NULL;

}
