#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "available_plans_list_response.h"



static available_plans_list_response_t *available_plans_list_response_create_internal(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    available_plans_list_response_t *available_plans_list_response_local_var = malloc(sizeof(available_plans_list_response_t));
    if (!available_plans_list_response_local_var) {
        return NULL;
    }
    available_plans_list_response_local_var->results = results;
    available_plans_list_response_local_var->count = count;
    available_plans_list_response_local_var->total = total;
    available_plans_list_response_local_var->limit = limit;
    available_plans_list_response_local_var->offset = offset;
    available_plans_list_response_local_var->has_more = has_more;

    available_plans_list_response_local_var->_library_owned = 1;
    return available_plans_list_response_local_var;
}

__attribute__((deprecated)) available_plans_list_response_t *available_plans_list_response_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    return available_plans_list_response_create_internal (
        results,
        count,
        total,
        limit,
        offset,
        has_more
        );
}

void available_plans_list_response_free(available_plans_list_response_t *available_plans_list_response) {
    if(NULL == available_plans_list_response){
        return ;
    }
    if(available_plans_list_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "available_plans_list_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (available_plans_list_response->results) {
        list_ForEach(listEntry, available_plans_list_response->results) {
            plan_free(listEntry->data);
        }
        list_freeList(available_plans_list_response->results);
        available_plans_list_response->results = NULL;
    }
    free(available_plans_list_response);
}

cJSON *available_plans_list_response_convertToJSON(available_plans_list_response_t *available_plans_list_response) {
    cJSON *item = cJSON_CreateObject();

    // available_plans_list_response->results
    if (!available_plans_list_response->results) {
        goto fail;
    }
    cJSON *results = cJSON_AddArrayToObject(item, "results");
    if(results == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resultsListEntry;
    if (available_plans_list_response->results) {
    list_ForEach(resultsListEntry, available_plans_list_response->results) {
    cJSON *itemLocal = plan_convertToJSON(resultsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(results, itemLocal);
    }
    }


    // available_plans_list_response->count
    if (!available_plans_list_response->count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "count", available_plans_list_response->count) == NULL) {
    goto fail; //Numeric
    }


    // available_plans_list_response->total
    if (!available_plans_list_response->total) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "total", available_plans_list_response->total) == NULL) {
    goto fail; //Numeric
    }


    // available_plans_list_response->limit
    if (!available_plans_list_response->limit) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "limit", available_plans_list_response->limit) == NULL) {
    goto fail; //Numeric
    }


    // available_plans_list_response->offset
    if (!available_plans_list_response->offset) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "offset", available_plans_list_response->offset) == NULL) {
    goto fail; //Numeric
    }


    // available_plans_list_response->has_more
    if (!available_plans_list_response->has_more) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "hasMore", available_plans_list_response->has_more) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

available_plans_list_response_t *available_plans_list_response_parseFromJSON(cJSON *available_plans_list_responseJSON){

    available_plans_list_response_t *available_plans_list_response_local_var = NULL;

    // define the local list for available_plans_list_response->results
    list_t *resultsList = NULL;

    // available_plans_list_response->results
    cJSON *results = cJSON_GetObjectItemCaseSensitive(available_plans_list_responseJSON, "results");
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
        plan_t *resultsItem = plan_parseFromJSON(results_local_nonprimitive);

        list_addElement(resultsList, resultsItem);
    }

    // available_plans_list_response->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(available_plans_list_responseJSON, "count");
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

    // available_plans_list_response->total
    cJSON *total = cJSON_GetObjectItemCaseSensitive(available_plans_list_responseJSON, "total");
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

    // available_plans_list_response->limit
    cJSON *limit = cJSON_GetObjectItemCaseSensitive(available_plans_list_responseJSON, "limit");
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

    // available_plans_list_response->offset
    cJSON *offset = cJSON_GetObjectItemCaseSensitive(available_plans_list_responseJSON, "offset");
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

    // available_plans_list_response->has_more
    cJSON *has_more = cJSON_GetObjectItemCaseSensitive(available_plans_list_responseJSON, "hasMore");
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


    available_plans_list_response_local_var = available_plans_list_response_create_internal (
        resultsList,
        count->valuedouble,
        total->valuedouble,
        limit->valuedouble,
        offset->valuedouble,
        has_more->valueint
        );

    return available_plans_list_response_local_var;
end:
    if (resultsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resultsList) {
            plan_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resultsList);
        resultsList = NULL;
    }
    return NULL;

}
