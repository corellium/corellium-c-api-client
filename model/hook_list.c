#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hook_list.h"



static hook_list_t *hook_list_create_internal(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    hook_list_t *hook_list_local_var = malloc(sizeof(hook_list_t));
    if (!hook_list_local_var) {
        return NULL;
    }
    hook_list_local_var->results = results;
    hook_list_local_var->count = count;
    hook_list_local_var->total = total;
    hook_list_local_var->limit = limit;
    hook_list_local_var->offset = offset;
    hook_list_local_var->has_more = has_more;

    hook_list_local_var->_library_owned = 1;
    return hook_list_local_var;
}

__attribute__((deprecated)) hook_list_t *hook_list_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    return hook_list_create_internal (
        results,
        count,
        total,
        limit,
        offset,
        has_more
        );
}

void hook_list_free(hook_list_t *hook_list) {
    if(NULL == hook_list){
        return ;
    }
    if(hook_list->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "hook_list_free");
        return ;
    }
    listEntry_t *listEntry;
    if (hook_list->results) {
        list_ForEach(listEntry, hook_list->results) {
            hook_free(listEntry->data);
        }
        list_freeList(hook_list->results);
        hook_list->results = NULL;
    }
    free(hook_list);
}

cJSON *hook_list_convertToJSON(hook_list_t *hook_list) {
    cJSON *item = cJSON_CreateObject();

    // hook_list->results
    if (!hook_list->results) {
        goto fail;
    }
    cJSON *results = cJSON_AddArrayToObject(item, "results");
    if(results == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resultsListEntry;
    if (hook_list->results) {
    list_ForEach(resultsListEntry, hook_list->results) {
    cJSON *itemLocal = hook_convertToJSON(resultsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(results, itemLocal);
    }
    }


    // hook_list->count
    if (!hook_list->count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "count", hook_list->count) == NULL) {
    goto fail; //Numeric
    }


    // hook_list->total
    if (!hook_list->total) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "total", hook_list->total) == NULL) {
    goto fail; //Numeric
    }


    // hook_list->limit
    if (!hook_list->limit) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "limit", hook_list->limit) == NULL) {
    goto fail; //Numeric
    }


    // hook_list->offset
    if (!hook_list->offset) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "offset", hook_list->offset) == NULL) {
    goto fail; //Numeric
    }


    // hook_list->has_more
    if (!hook_list->has_more) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "hasMore", hook_list->has_more) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

hook_list_t *hook_list_parseFromJSON(cJSON *hook_listJSON){

    hook_list_t *hook_list_local_var = NULL;

    // define the local list for hook_list->results
    list_t *resultsList = NULL;

    // hook_list->results
    cJSON *results = cJSON_GetObjectItemCaseSensitive(hook_listJSON, "results");
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
        hook_t *resultsItem = hook_parseFromJSON(results_local_nonprimitive);

        list_addElement(resultsList, resultsItem);
    }

    // hook_list->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(hook_listJSON, "count");
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

    // hook_list->total
    cJSON *total = cJSON_GetObjectItemCaseSensitive(hook_listJSON, "total");
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

    // hook_list->limit
    cJSON *limit = cJSON_GetObjectItemCaseSensitive(hook_listJSON, "limit");
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

    // hook_list->offset
    cJSON *offset = cJSON_GetObjectItemCaseSensitive(hook_listJSON, "offset");
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

    // hook_list->has_more
    cJSON *has_more = cJSON_GetObjectItemCaseSensitive(hook_listJSON, "hasMore");
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


    hook_list_local_var = hook_list_create_internal (
        resultsList,
        count->valuedouble,
        total->valuedouble,
        limit->valuedouble,
        offset->valuedouble,
        has_more->valueint
        );

    return hook_list_local_var;
end:
    if (resultsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resultsList) {
            hook_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resultsList);
        resultsList = NULL;
    }
    return NULL;

}
