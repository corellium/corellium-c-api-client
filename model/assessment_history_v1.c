#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "assessment_history_v1.h"



static assessment_history_v1_t *assessment_history_v1_create_internal(
    double total,
    double count,
    double limit,
    double offset,
    list_t *results
    ) {
    assessment_history_v1_t *assessment_history_v1_local_var = malloc(sizeof(assessment_history_v1_t));
    if (!assessment_history_v1_local_var) {
        return NULL;
    }
    assessment_history_v1_local_var->total = total;
    assessment_history_v1_local_var->count = count;
    assessment_history_v1_local_var->limit = limit;
    assessment_history_v1_local_var->offset = offset;
    assessment_history_v1_local_var->results = results;

    assessment_history_v1_local_var->_library_owned = 1;
    return assessment_history_v1_local_var;
}

__attribute__((deprecated)) assessment_history_v1_t *assessment_history_v1_create(
    double total,
    double count,
    double limit,
    double offset,
    list_t *results
    ) {
    return assessment_history_v1_create_internal (
        total,
        count,
        limit,
        offset,
        results
        );
}

void assessment_history_v1_free(assessment_history_v1_t *assessment_history_v1) {
    if(NULL == assessment_history_v1){
        return ;
    }
    if(assessment_history_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "assessment_history_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (assessment_history_v1->results) {
        list_ForEach(listEntry, assessment_history_v1->results) {
            assessment_history_line_item_free(listEntry->data);
        }
        list_freeList(assessment_history_v1->results);
        assessment_history_v1->results = NULL;
    }
    free(assessment_history_v1);
}

cJSON *assessment_history_v1_convertToJSON(assessment_history_v1_t *assessment_history_v1) {
    cJSON *item = cJSON_CreateObject();

    // assessment_history_v1->total
    if (!assessment_history_v1->total) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "total", assessment_history_v1->total) == NULL) {
    goto fail; //Numeric
    }


    // assessment_history_v1->count
    if (!assessment_history_v1->count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "count", assessment_history_v1->count) == NULL) {
    goto fail; //Numeric
    }


    // assessment_history_v1->limit
    if (!assessment_history_v1->limit) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "limit", assessment_history_v1->limit) == NULL) {
    goto fail; //Numeric
    }


    // assessment_history_v1->offset
    if (!assessment_history_v1->offset) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "offset", assessment_history_v1->offset) == NULL) {
    goto fail; //Numeric
    }


    // assessment_history_v1->results
    if (!assessment_history_v1->results) {
        goto fail;
    }
    cJSON *results = cJSON_AddArrayToObject(item, "results");
    if(results == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resultsListEntry;
    if (assessment_history_v1->results) {
    list_ForEach(resultsListEntry, assessment_history_v1->results) {
    cJSON *itemLocal = assessment_history_line_item_convertToJSON(resultsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(results, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

assessment_history_v1_t *assessment_history_v1_parseFromJSON(cJSON *assessment_history_v1JSON){

    assessment_history_v1_t *assessment_history_v1_local_var = NULL;

    // define the local list for assessment_history_v1->results
    list_t *resultsList = NULL;

    // assessment_history_v1->total
    cJSON *total = cJSON_GetObjectItemCaseSensitive(assessment_history_v1JSON, "total");
    if (cJSON_IsNull(total)) {
        total = NULL;
    }
    if (!total) {
        goto end;
    }

    
    if(!cJSON_IsNumber(total))
    {
    goto end; //Numeric
    }

    // assessment_history_v1->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(assessment_history_v1JSON, "count");
    if (cJSON_IsNull(count)) {
        count = NULL;
    }
    if (!count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(count))
    {
    goto end; //Numeric
    }

    // assessment_history_v1->limit
    cJSON *limit = cJSON_GetObjectItemCaseSensitive(assessment_history_v1JSON, "limit");
    if (cJSON_IsNull(limit)) {
        limit = NULL;
    }
    if (!limit) {
        goto end;
    }

    
    if(!cJSON_IsNumber(limit))
    {
    goto end; //Numeric
    }

    // assessment_history_v1->offset
    cJSON *offset = cJSON_GetObjectItemCaseSensitive(assessment_history_v1JSON, "offset");
    if (cJSON_IsNull(offset)) {
        offset = NULL;
    }
    if (!offset) {
        goto end;
    }

    
    if(!cJSON_IsNumber(offset))
    {
    goto end; //Numeric
    }

    // assessment_history_v1->results
    cJSON *results = cJSON_GetObjectItemCaseSensitive(assessment_history_v1JSON, "results");
    if (cJSON_IsNull(results)) {
        results = NULL;
    }
    if (!results) {
        goto end;
    }

    
    cJSON *results_local_nonprimitive = NULL;
    if(!cJSON_IsArray(results)){
        goto end; //nonprimitive container
    }

    resultsList = list_createList();

    cJSON_ArrayForEach(results_local_nonprimitive,results )
    {
        if(!cJSON_IsObject(results_local_nonprimitive)){
            goto end;
        }
        assessment_history_line_item_t *resultsItem = assessment_history_line_item_parseFromJSON(results_local_nonprimitive);

        list_addElement(resultsList, resultsItem);
    }


    assessment_history_v1_local_var = assessment_history_v1_create_internal (
        total->valuedouble,
        count->valuedouble,
        limit->valuedouble,
        offset->valuedouble,
        resultsList
        );

    return assessment_history_v1_local_var;
end:
    if (resultsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resultsList) {
            assessment_history_line_item_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resultsList);
        resultsList = NULL;
    }
    return NULL;

}
