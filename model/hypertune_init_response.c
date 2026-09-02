#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hypertune_init_response.h"



static hypertune_init_response_t *hypertune_init_response_create_internal(
    double commit_id,
    char *hash,
    object_t *reduced_expression,
    object_t *splits,
    object_t *commit_config
    ) {
    hypertune_init_response_t *hypertune_init_response_local_var = malloc(sizeof(hypertune_init_response_t));
    if (!hypertune_init_response_local_var) {
        return NULL;
    }
    hypertune_init_response_local_var->commit_id = commit_id;
    hypertune_init_response_local_var->hash = hash;
    hypertune_init_response_local_var->reduced_expression = reduced_expression;
    hypertune_init_response_local_var->splits = splits;
    hypertune_init_response_local_var->commit_config = commit_config;

    hypertune_init_response_local_var->_library_owned = 1;
    return hypertune_init_response_local_var;
}

__attribute__((deprecated)) hypertune_init_response_t *hypertune_init_response_create(
    double commit_id,
    char *hash,
    object_t *reduced_expression,
    object_t *splits,
    object_t *commit_config
    ) {
    return hypertune_init_response_create_internal (
        commit_id,
        hash,
        reduced_expression,
        splits,
        commit_config
        );
}

void hypertune_init_response_free(hypertune_init_response_t *hypertune_init_response) {
    if(NULL == hypertune_init_response){
        return ;
    }
    if(hypertune_init_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "hypertune_init_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (hypertune_init_response->hash) {
        free(hypertune_init_response->hash);
        hypertune_init_response->hash = NULL;
    }
    if (hypertune_init_response->reduced_expression) {
        object_free(hypertune_init_response->reduced_expression);
        hypertune_init_response->reduced_expression = NULL;
    }
    if (hypertune_init_response->splits) {
        object_free(hypertune_init_response->splits);
        hypertune_init_response->splits = NULL;
    }
    if (hypertune_init_response->commit_config) {
        object_free(hypertune_init_response->commit_config);
        hypertune_init_response->commit_config = NULL;
    }
    free(hypertune_init_response);
}

cJSON *hypertune_init_response_convertToJSON(hypertune_init_response_t *hypertune_init_response) {
    cJSON *item = cJSON_CreateObject();

    // hypertune_init_response->commit_id
    if(hypertune_init_response->commit_id) {
    if(cJSON_AddNumberToObject(item, "commitId", hypertune_init_response->commit_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // hypertune_init_response->hash
    if(hypertune_init_response->hash) {
    if(cJSON_AddStringToObject(item, "hash", hypertune_init_response->hash) == NULL) {
    goto fail; //String
    }
    }


    // hypertune_init_response->reduced_expression
    if(hypertune_init_response->reduced_expression) {
    cJSON *reduced_expression_object = object_convertToJSON(hypertune_init_response->reduced_expression);
    if(reduced_expression_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reducedExpression", reduced_expression_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // hypertune_init_response->splits
    if(hypertune_init_response->splits) {
    cJSON *splits_object = object_convertToJSON(hypertune_init_response->splits);
    if(splits_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "splits", splits_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // hypertune_init_response->commit_config
    if(hypertune_init_response->commit_config) {
    cJSON *commit_config_object = object_convertToJSON(hypertune_init_response->commit_config);
    if(commit_config_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "commitConfig", commit_config_object);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

hypertune_init_response_t *hypertune_init_response_parseFromJSON(cJSON *hypertune_init_responseJSON){

    hypertune_init_response_t *hypertune_init_response_local_var = NULL;

    // hypertune_init_response->commit_id
    cJSON *commit_id = cJSON_GetObjectItemCaseSensitive(hypertune_init_responseJSON, "commitId");
    if (cJSON_IsNull(commit_id)) {
        commit_id = NULL;
    }
    if (commit_id) { 
    if(!cJSON_IsNumber(commit_id))
    {
    goto end; //Numeric
    }
    }

    // hypertune_init_response->hash
    cJSON *hash = cJSON_GetObjectItemCaseSensitive(hypertune_init_responseJSON, "hash");
    if (cJSON_IsNull(hash)) {
        hash = NULL;
    }
    if (hash) { 
    if(!cJSON_IsString(hash) && !cJSON_IsNull(hash))
    {
    goto end; //String
    }
    }

    // hypertune_init_response->reduced_expression
    cJSON *reduced_expression = cJSON_GetObjectItemCaseSensitive(hypertune_init_responseJSON, "reducedExpression");
    if (cJSON_IsNull(reduced_expression)) {
        reduced_expression = NULL;
    }
    object_t *reduced_expression_local_object = NULL;
    if (reduced_expression) { 
    reduced_expression_local_object = object_parseFromJSON(reduced_expression); //object
    }

    // hypertune_init_response->splits
    cJSON *splits = cJSON_GetObjectItemCaseSensitive(hypertune_init_responseJSON, "splits");
    if (cJSON_IsNull(splits)) {
        splits = NULL;
    }
    object_t *splits_local_object = NULL;
    if (splits) { 
    splits_local_object = object_parseFromJSON(splits); //object
    }

    // hypertune_init_response->commit_config
    cJSON *commit_config = cJSON_GetObjectItemCaseSensitive(hypertune_init_responseJSON, "commitConfig");
    if (cJSON_IsNull(commit_config)) {
        commit_config = NULL;
    }
    object_t *commit_config_local_object = NULL;
    if (commit_config) { 
    commit_config_local_object = object_parseFromJSON(commit_config); //object
    }


    hypertune_init_response_local_var = hypertune_init_response_create_internal (
        commit_id ? commit_id->valuedouble : 0,
        hash && !cJSON_IsNull(hash) ? strdup(hash->valuestring) : NULL,
        reduced_expression ? reduced_expression_local_object : NULL,
        splits ? splits_local_object : NULL,
        commit_config ? commit_config_local_object : NULL
        );

    return hypertune_init_response_local_var;
end:
    return NULL;

}
