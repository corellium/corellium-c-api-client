#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "assessment.h"



static assessment_t *assessment_create_internal(
    char *id,
    corellium_api_assessment_status__e status,
    char *instance_id,
    assessment_bundle_t *bundle,
    assessment_wordlist_t *wordlist,
    assessment_frida_script_t *frida_script,
    char *report_id,
    assessment_results_t *results,
    assessment_metadata_t *metadata,
    assessment_severity_counts_t *severity_counts,
    char *error,
    char *created_by,
    char *created_at,
    char *updated_at
    ) {
    assessment_t *assessment_local_var = malloc(sizeof(assessment_t));
    if (!assessment_local_var) {
        return NULL;
    }
    assessment_local_var->id = id;
    assessment_local_var->status = status;
    assessment_local_var->instance_id = instance_id;
    assessment_local_var->bundle = bundle;
    assessment_local_var->wordlist = wordlist;
    assessment_local_var->frida_script = frida_script;
    assessment_local_var->report_id = report_id;
    assessment_local_var->results = results;
    assessment_local_var->metadata = metadata;
    assessment_local_var->severity_counts = severity_counts;
    assessment_local_var->error = error;
    assessment_local_var->created_by = created_by;
    assessment_local_var->created_at = created_at;
    assessment_local_var->updated_at = updated_at;

    assessment_local_var->_library_owned = 1;
    return assessment_local_var;
}

__attribute__((deprecated)) assessment_t *assessment_create(
    char *id,
    corellium_api_assessment_status__e status,
    char *instance_id,
    assessment_bundle_t *bundle,
    assessment_wordlist_t *wordlist,
    assessment_frida_script_t *frida_script,
    char *report_id,
    assessment_results_t *results,
    assessment_metadata_t *metadata,
    assessment_severity_counts_t *severity_counts,
    char *error,
    char *created_by,
    char *created_at,
    char *updated_at
    ) {
    return assessment_create_internal (
        id,
        status,
        instance_id,
        bundle,
        wordlist,
        frida_script,
        report_id,
        results,
        metadata,
        severity_counts,
        error,
        created_by,
        created_at,
        updated_at
        );
}

void assessment_free(assessment_t *assessment) {
    if(NULL == assessment){
        return ;
    }
    if(assessment->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "assessment_free");
        return ;
    }
    listEntry_t *listEntry;
    if (assessment->id) {
        free(assessment->id);
        assessment->id = NULL;
    }
    if (assessment->instance_id) {
        free(assessment->instance_id);
        assessment->instance_id = NULL;
    }
    if (assessment->bundle) {
        assessment_bundle_free(assessment->bundle);
        assessment->bundle = NULL;
    }
    if (assessment->wordlist) {
        assessment_wordlist_free(assessment->wordlist);
        assessment->wordlist = NULL;
    }
    if (assessment->frida_script) {
        assessment_frida_script_free(assessment->frida_script);
        assessment->frida_script = NULL;
    }
    if (assessment->report_id) {
        free(assessment->report_id);
        assessment->report_id = NULL;
    }
    if (assessment->results) {
        assessment_results_free(assessment->results);
        assessment->results = NULL;
    }
    if (assessment->metadata) {
        assessment_metadata_free(assessment->metadata);
        assessment->metadata = NULL;
    }
    if (assessment->severity_counts) {
        assessment_severity_counts_free(assessment->severity_counts);
        assessment->severity_counts = NULL;
    }
    if (assessment->error) {
        free(assessment->error);
        assessment->error = NULL;
    }
    if (assessment->created_by) {
        free(assessment->created_by);
        assessment->created_by = NULL;
    }
    if (assessment->created_at) {
        free(assessment->created_at);
        assessment->created_at = NULL;
    }
    if (assessment->updated_at) {
        free(assessment->updated_at);
        assessment->updated_at = NULL;
    }
    free(assessment);
}

cJSON *assessment_convertToJSON(assessment_t *assessment) {
    cJSON *item = cJSON_CreateObject();

    // assessment->id
    if (!assessment->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", assessment->id) == NULL) {
    goto fail; //String
    }


    // assessment->status
    if (corellium_api_assessment_status__NULL == assessment->status) {
        goto fail;
    }
    cJSON *status_local_JSON = assessment_status_convertToJSON(assessment->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // assessment->instance_id
    if (!assessment->instance_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "instanceId", assessment->instance_id) == NULL) {
    goto fail; //String
    }


    // assessment->bundle
    if (!assessment->bundle) {
        goto fail;
    }
    cJSON *bundle_local_JSON = assessment_bundle_convertToJSON(assessment->bundle);
    if(bundle_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "bundle", bundle_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // assessment->wordlist
    if(assessment->wordlist) {
    cJSON *wordlist_local_JSON = assessment_wordlist_convertToJSON(assessment->wordlist);
    if(wordlist_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "wordlist", wordlist_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // assessment->frida_script
    if(assessment->frida_script) {
    cJSON *frida_script_local_JSON = assessment_frida_script_convertToJSON(assessment->frida_script);
    if(frida_script_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "fridaScript", frida_script_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // assessment->report_id
    if(assessment->report_id) {
    if(cJSON_AddStringToObject(item, "reportId", assessment->report_id) == NULL) {
    goto fail; //String
    }
    }


    // assessment->results
    if (!assessment->results) {
        goto fail;
    }
    cJSON *results_local_JSON = assessment_results_convertToJSON(assessment->results);
    if(results_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "results", results_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // assessment->metadata
    if (!assessment->metadata) {
        goto fail;
    }
    cJSON *metadata_local_JSON = assessment_metadata_convertToJSON(assessment->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // assessment->severity_counts
    if (!assessment->severity_counts) {
        goto fail;
    }
    cJSON *severity_counts_local_JSON = assessment_severity_counts_convertToJSON(assessment->severity_counts);
    if(severity_counts_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "severityCounts", severity_counts_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // assessment->error
    if(assessment->error) {
    if(cJSON_AddStringToObject(item, "error", assessment->error) == NULL) {
    goto fail; //String
    }
    }


    // assessment->created_by
    if(assessment->created_by) {
    if(cJSON_AddStringToObject(item, "createdBy", assessment->created_by) == NULL) {
    goto fail; //String
    }
    }


    // assessment->created_at
    if(assessment->created_at) {
    if(cJSON_AddStringToObject(item, "createdAt", assessment->created_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // assessment->updated_at
    if(assessment->updated_at) {
    if(cJSON_AddStringToObject(item, "updatedAt", assessment->updated_at) == NULL) {
    goto fail; //Date-Time
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

assessment_t *assessment_parseFromJSON(cJSON *assessmentJSON){

    assessment_t *assessment_local_var = NULL;

    // define the local variable for assessment->status
    corellium_api_assessment_status__e status_local_nonprim = 0;

    // define the local variable for assessment->bundle
    assessment_bundle_t *bundle_local_nonprim = NULL;

    // define the local variable for assessment->wordlist
    assessment_wordlist_t *wordlist_local_nonprim = NULL;

    // define the local variable for assessment->frida_script
    assessment_frida_script_t *frida_script_local_nonprim = NULL;

    // define the local variable for assessment->results
    assessment_results_t *results_local_nonprim = NULL;

    // define the local variable for assessment->metadata
    assessment_metadata_t *metadata_local_nonprim = NULL;

    // define the local variable for assessment->severity_counts
    assessment_severity_counts_t *severity_counts_local_nonprim = NULL;

    // assessment->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(assessmentJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }

    // assessment->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(assessmentJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    status_local_nonprim = assessment_status_parseFromJSON(status); //custom

    // assessment->instance_id
    cJSON *instance_id = cJSON_GetObjectItemCaseSensitive(assessmentJSON, "instanceId");
    if (cJSON_IsNull(instance_id)) {
        instance_id = NULL;
    }
    if (!instance_id) {
        goto end;
    }

    
    if(!cJSON_IsString(instance_id))
    {
    goto end; //String
    }

    // assessment->bundle
    cJSON *bundle = cJSON_GetObjectItemCaseSensitive(assessmentJSON, "bundle");
    if (cJSON_IsNull(bundle)) {
        bundle = NULL;
    }
    if (!bundle) {
        goto end;
    }

    
    bundle_local_nonprim = assessment_bundle_parseFromJSON(bundle); //nonprimitive

    // assessment->wordlist
    cJSON *wordlist = cJSON_GetObjectItemCaseSensitive(assessmentJSON, "wordlist");
    if (cJSON_IsNull(wordlist)) {
        wordlist = NULL;
    }
    if (wordlist) { 
    wordlist_local_nonprim = assessment_wordlist_parseFromJSON(wordlist); //nonprimitive
    }

    // assessment->frida_script
    cJSON *frida_script = cJSON_GetObjectItemCaseSensitive(assessmentJSON, "fridaScript");
    if (cJSON_IsNull(frida_script)) {
        frida_script = NULL;
    }
    if (frida_script) { 
    frida_script_local_nonprim = assessment_frida_script_parseFromJSON(frida_script); //nonprimitive
    }

    // assessment->report_id
    cJSON *report_id = cJSON_GetObjectItemCaseSensitive(assessmentJSON, "reportId");
    if (cJSON_IsNull(report_id)) {
        report_id = NULL;
    }
    if (report_id) { 
    if(!cJSON_IsString(report_id) && !cJSON_IsNull(report_id))
    {
    goto end; //String
    }
    }

    // assessment->results
    cJSON *results = cJSON_GetObjectItemCaseSensitive(assessmentJSON, "results");
    if (cJSON_IsNull(results)) {
        results = NULL;
    }
    if (!results) {
        goto end;
    }

    
    results_local_nonprim = assessment_results_parseFromJSON(results); //nonprimitive

    // assessment->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(assessmentJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (!metadata) {
        goto end;
    }

    
    metadata_local_nonprim = assessment_metadata_parseFromJSON(metadata); //nonprimitive

    // assessment->severity_counts
    cJSON *severity_counts = cJSON_GetObjectItemCaseSensitive(assessmentJSON, "severityCounts");
    if (cJSON_IsNull(severity_counts)) {
        severity_counts = NULL;
    }
    if (!severity_counts) {
        goto end;
    }

    
    severity_counts_local_nonprim = assessment_severity_counts_parseFromJSON(severity_counts); //nonprimitive

    // assessment->error
    cJSON *error = cJSON_GetObjectItemCaseSensitive(assessmentJSON, "error");
    if (cJSON_IsNull(error)) {
        error = NULL;
    }
    if (error) { 
    if(!cJSON_IsString(error) && !cJSON_IsNull(error))
    {
    goto end; //String
    }
    }

    // assessment->created_by
    cJSON *created_by = cJSON_GetObjectItemCaseSensitive(assessmentJSON, "createdBy");
    if (cJSON_IsNull(created_by)) {
        created_by = NULL;
    }
    if (created_by) { 
    if(!cJSON_IsString(created_by) && !cJSON_IsNull(created_by))
    {
    goto end; //String
    }
    }

    // assessment->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(assessmentJSON, "createdAt");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (created_at) { 
    if(!cJSON_IsString(created_at) && !cJSON_IsNull(created_at))
    {
    goto end; //DateTime
    }
    }

    // assessment->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(assessmentJSON, "updatedAt");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (updated_at) { 
    if(!cJSON_IsString(updated_at) && !cJSON_IsNull(updated_at))
    {
    goto end; //DateTime
    }
    }


    assessment_local_var = assessment_create_internal (
        strdup(id->valuestring),
        status_local_nonprim,
        strdup(instance_id->valuestring),
        bundle_local_nonprim,
        wordlist ? wordlist_local_nonprim : NULL,
        frida_script ? frida_script_local_nonprim : NULL,
        report_id && !cJSON_IsNull(report_id) ? strdup(report_id->valuestring) : NULL,
        results_local_nonprim,
        metadata_local_nonprim,
        severity_counts_local_nonprim,
        error && !cJSON_IsNull(error) ? strdup(error->valuestring) : NULL,
        created_by && !cJSON_IsNull(created_by) ? strdup(created_by->valuestring) : NULL,
        created_at && !cJSON_IsNull(created_at) ? strdup(created_at->valuestring) : NULL,
        updated_at && !cJSON_IsNull(updated_at) ? strdup(updated_at->valuestring) : NULL
        );

    return assessment_local_var;
end:
    if (status_local_nonprim) {
        status_local_nonprim = 0;
    }
    if (bundle_local_nonprim) {
        assessment_bundle_free(bundle_local_nonprim);
        bundle_local_nonprim = NULL;
    }
    if (wordlist_local_nonprim) {
        assessment_wordlist_free(wordlist_local_nonprim);
        wordlist_local_nonprim = NULL;
    }
    if (frida_script_local_nonprim) {
        assessment_frida_script_free(frida_script_local_nonprim);
        frida_script_local_nonprim = NULL;
    }
    if (results_local_nonprim) {
        assessment_results_free(results_local_nonprim);
        results_local_nonprim = NULL;
    }
    if (metadata_local_nonprim) {
        assessment_metadata_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (severity_counts_local_nonprim) {
        assessment_severity_counts_free(severity_counts_local_nonprim);
        severity_counts_local_nonprim = NULL;
    }
    return NULL;

}
