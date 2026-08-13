#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "trial_request_list_response.h"



static trial_request_list_response_t *trial_request_list_response_create_internal(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    trial_request_list_response_t *trial_request_list_response_local_var = malloc(sizeof(trial_request_list_response_t));
    if (!trial_request_list_response_local_var) {
        return NULL;
    }
    trial_request_list_response_local_var->results = results;
    trial_request_list_response_local_var->count = count;
    trial_request_list_response_local_var->total = total;
    trial_request_list_response_local_var->limit = limit;
    trial_request_list_response_local_var->offset = offset;
    trial_request_list_response_local_var->has_more = has_more;

    trial_request_list_response_local_var->_library_owned = 1;
    return trial_request_list_response_local_var;
}

__attribute__((deprecated)) trial_request_list_response_t *trial_request_list_response_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    return trial_request_list_response_create_internal (
        results,
        count,
        total,
        limit,
        offset,
        has_more
        );
}

void trial_request_list_response_free(trial_request_list_response_t *trial_request_list_response) {
    if(NULL == trial_request_list_response){
        return ;
    }
    if(trial_request_list_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "trial_request_list_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (trial_request_list_response->results) {
        list_ForEach(listEntry, trial_request_list_response->results) {
            trial_request_free(listEntry->data);
        }
        list_freeList(trial_request_list_response->results);
        trial_request_list_response->results = NULL;
    }
    free(trial_request_list_response);
}

cJSON *trial_request_list_response_convertToJSON(trial_request_list_response_t *trial_request_list_response) {
    cJSON *item = cJSON_CreateObject();

    // trial_request_list_response->results
    if (!trial_request_list_response->results) {
        goto fail;
    }
    cJSON *results = cJSON_AddArrayToObject(item, "results");
    if(results == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resultsListEntry;
    if (trial_request_list_response->results) {
    list_ForEach(resultsListEntry, trial_request_list_response->results) {
    cJSON *itemLocal = trial_request_convertToJSON(resultsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(results, itemLocal);
    }
    }


    // trial_request_list_response->count
    if (!trial_request_list_response->count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "count", trial_request_list_response->count) == NULL) {
    goto fail; //Numeric
    }


    // trial_request_list_response->total
    if (!trial_request_list_response->total) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "total", trial_request_list_response->total) == NULL) {
    goto fail; //Numeric
    }


    // trial_request_list_response->limit
    if (!trial_request_list_response->limit) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "limit", trial_request_list_response->limit) == NULL) {
    goto fail; //Numeric
    }


    // trial_request_list_response->offset
    if (!trial_request_list_response->offset) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "offset", trial_request_list_response->offset) == NULL) {
    goto fail; //Numeric
    }


    // trial_request_list_response->has_more
    if (!trial_request_list_response->has_more) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "hasMore", trial_request_list_response->has_more) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

trial_request_list_response_t *trial_request_list_response_parseFromJSON(cJSON *trial_request_list_responseJSON){

    trial_request_list_response_t *trial_request_list_response_local_var = NULL;

    // define the local list for trial_request_list_response->results
    list_t *resultsList = NULL;

    // trial_request_list_response->results
    cJSON *results = cJSON_GetObjectItemCaseSensitive(trial_request_list_responseJSON, "results");
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
        trial_request_t *resultsItem = trial_request_parseFromJSON(results_local_nonprimitive);

        list_addElement(resultsList, resultsItem);
    }

    // trial_request_list_response->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(trial_request_list_responseJSON, "count");
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

    // trial_request_list_response->total
    cJSON *total = cJSON_GetObjectItemCaseSensitive(trial_request_list_responseJSON, "total");
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

    // trial_request_list_response->limit
    cJSON *limit = cJSON_GetObjectItemCaseSensitive(trial_request_list_responseJSON, "limit");
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

    // trial_request_list_response->offset
    cJSON *offset = cJSON_GetObjectItemCaseSensitive(trial_request_list_responseJSON, "offset");
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

    // trial_request_list_response->has_more
    cJSON *has_more = cJSON_GetObjectItemCaseSensitive(trial_request_list_responseJSON, "hasMore");
    if (cJSON_IsNull(has_more)) {
        has_more = NULL;
    }
    if (!has_more) {
        goto end;
    }

    
    if(!cJSON_IsBool(has_more))
    {
    goto end; //Bool
    }


    trial_request_list_response_local_var = trial_request_list_response_create_internal (
        resultsList,
        count->valuedouble,
        total->valuedouble,
        limit->valuedouble,
        offset->valuedouble,
        has_more->valueint
        );

    return trial_request_list_response_local_var;
end:
    if (resultsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resultsList) {
            trial_request_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resultsList);
        resultsList = NULL;
    }
    return NULL;

}
