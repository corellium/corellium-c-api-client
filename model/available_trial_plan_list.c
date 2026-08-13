#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "available_trial_plan_list.h"



static available_trial_plan_list_t *available_trial_plan_list_create_internal(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    available_trial_plan_list_t *available_trial_plan_list_local_var = malloc(sizeof(available_trial_plan_list_t));
    if (!available_trial_plan_list_local_var) {
        return NULL;
    }
    available_trial_plan_list_local_var->results = results;
    available_trial_plan_list_local_var->count = count;
    available_trial_plan_list_local_var->total = total;
    available_trial_plan_list_local_var->limit = limit;
    available_trial_plan_list_local_var->offset = offset;
    available_trial_plan_list_local_var->has_more = has_more;

    available_trial_plan_list_local_var->_library_owned = 1;
    return available_trial_plan_list_local_var;
}

__attribute__((deprecated)) available_trial_plan_list_t *available_trial_plan_list_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    return available_trial_plan_list_create_internal (
        results,
        count,
        total,
        limit,
        offset,
        has_more
        );
}

void available_trial_plan_list_free(available_trial_plan_list_t *available_trial_plan_list) {
    if(NULL == available_trial_plan_list){
        return ;
    }
    if(available_trial_plan_list->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "available_trial_plan_list_free");
        return ;
    }
    listEntry_t *listEntry;
    if (available_trial_plan_list->results) {
        list_ForEach(listEntry, available_trial_plan_list->results) {
            available_trial_plan_free(listEntry->data);
        }
        list_freeList(available_trial_plan_list->results);
        available_trial_plan_list->results = NULL;
    }
    free(available_trial_plan_list);
}

cJSON *available_trial_plan_list_convertToJSON(available_trial_plan_list_t *available_trial_plan_list) {
    cJSON *item = cJSON_CreateObject();

    // available_trial_plan_list->results
    if (!available_trial_plan_list->results) {
        goto fail;
    }
    cJSON *results = cJSON_AddArrayToObject(item, "results");
    if(results == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resultsListEntry;
    if (available_trial_plan_list->results) {
    list_ForEach(resultsListEntry, available_trial_plan_list->results) {
    cJSON *itemLocal = available_trial_plan_convertToJSON(resultsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(results, itemLocal);
    }
    }


    // available_trial_plan_list->count
    if (!available_trial_plan_list->count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "count", available_trial_plan_list->count) == NULL) {
    goto fail; //Numeric
    }


    // available_trial_plan_list->total
    if (!available_trial_plan_list->total) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "total", available_trial_plan_list->total) == NULL) {
    goto fail; //Numeric
    }


    // available_trial_plan_list->limit
    if (!available_trial_plan_list->limit) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "limit", available_trial_plan_list->limit) == NULL) {
    goto fail; //Numeric
    }


    // available_trial_plan_list->offset
    if (!available_trial_plan_list->offset) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "offset", available_trial_plan_list->offset) == NULL) {
    goto fail; //Numeric
    }


    // available_trial_plan_list->has_more
    if (!available_trial_plan_list->has_more) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "hasMore", available_trial_plan_list->has_more) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

available_trial_plan_list_t *available_trial_plan_list_parseFromJSON(cJSON *available_trial_plan_listJSON){

    available_trial_plan_list_t *available_trial_plan_list_local_var = NULL;

    // define the local list for available_trial_plan_list->results
    list_t *resultsList = NULL;

    // available_trial_plan_list->results
    cJSON *results = cJSON_GetObjectItemCaseSensitive(available_trial_plan_listJSON, "results");
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
        available_trial_plan_t *resultsItem = available_trial_plan_parseFromJSON(results_local_nonprimitive);

        list_addElement(resultsList, resultsItem);
    }

    // available_trial_plan_list->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(available_trial_plan_listJSON, "count");
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

    // available_trial_plan_list->total
    cJSON *total = cJSON_GetObjectItemCaseSensitive(available_trial_plan_listJSON, "total");
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

    // available_trial_plan_list->limit
    cJSON *limit = cJSON_GetObjectItemCaseSensitive(available_trial_plan_listJSON, "limit");
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

    // available_trial_plan_list->offset
    cJSON *offset = cJSON_GetObjectItemCaseSensitive(available_trial_plan_listJSON, "offset");
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

    // available_trial_plan_list->has_more
    cJSON *has_more = cJSON_GetObjectItemCaseSensitive(available_trial_plan_listJSON, "hasMore");
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


    available_trial_plan_list_local_var = available_trial_plan_list_create_internal (
        resultsList,
        count->valuedouble,
        total->valuedouble,
        limit->valuedouble,
        offset->valuedouble,
        has_more->valueint
        );

    return available_trial_plan_list_local_var;
end:
    if (resultsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resultsList) {
            available_trial_plan_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resultsList);
        resultsList = NULL;
    }
    return NULL;

}
