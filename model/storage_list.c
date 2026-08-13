#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "storage_list.h"



static storage_list_t *storage_list_create_internal(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    storage_list_t *storage_list_local_var = malloc(sizeof(storage_list_t));
    if (!storage_list_local_var) {
        return NULL;
    }
    storage_list_local_var->results = results;
    storage_list_local_var->count = count;
    storage_list_local_var->total = total;
    storage_list_local_var->limit = limit;
    storage_list_local_var->offset = offset;
    storage_list_local_var->has_more = has_more;

    storage_list_local_var->_library_owned = 1;
    return storage_list_local_var;
}

__attribute__((deprecated)) storage_list_t *storage_list_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    return storage_list_create_internal (
        results,
        count,
        total,
        limit,
        offset,
        has_more
        );
}

void storage_list_free(storage_list_t *storage_list) {
    if(NULL == storage_list){
        return ;
    }
    if(storage_list->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "storage_list_free");
        return ;
    }
    listEntry_t *listEntry;
    if (storage_list->results) {
        list_ForEach(listEntry, storage_list->results) {
            media_store_free(listEntry->data);
        }
        list_freeList(storage_list->results);
        storage_list->results = NULL;
    }
    free(storage_list);
}

cJSON *storage_list_convertToJSON(storage_list_t *storage_list) {
    cJSON *item = cJSON_CreateObject();

    // storage_list->results
    if (!storage_list->results) {
        goto fail;
    }
    cJSON *results = cJSON_AddArrayToObject(item, "results");
    if(results == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resultsListEntry;
    if (storage_list->results) {
    list_ForEach(resultsListEntry, storage_list->results) {
    cJSON *itemLocal = media_store_convertToJSON(resultsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(results, itemLocal);
    }
    }


    // storage_list->count
    if (!storage_list->count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "count", storage_list->count) == NULL) {
    goto fail; //Numeric
    }


    // storage_list->total
    if (!storage_list->total) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "total", storage_list->total) == NULL) {
    goto fail; //Numeric
    }


    // storage_list->limit
    if (!storage_list->limit) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "limit", storage_list->limit) == NULL) {
    goto fail; //Numeric
    }


    // storage_list->offset
    if (!storage_list->offset) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "offset", storage_list->offset) == NULL) {
    goto fail; //Numeric
    }


    // storage_list->has_more
    if (!storage_list->has_more) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "hasMore", storage_list->has_more) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

storage_list_t *storage_list_parseFromJSON(cJSON *storage_listJSON){

    storage_list_t *storage_list_local_var = NULL;

    // define the local list for storage_list->results
    list_t *resultsList = NULL;

    // storage_list->results
    cJSON *results = cJSON_GetObjectItemCaseSensitive(storage_listJSON, "results");
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
        media_store_t *resultsItem = media_store_parseFromJSON(results_local_nonprimitive);

        list_addElement(resultsList, resultsItem);
    }

    // storage_list->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(storage_listJSON, "count");
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

    // storage_list->total
    cJSON *total = cJSON_GetObjectItemCaseSensitive(storage_listJSON, "total");
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

    // storage_list->limit
    cJSON *limit = cJSON_GetObjectItemCaseSensitive(storage_listJSON, "limit");
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

    // storage_list->offset
    cJSON *offset = cJSON_GetObjectItemCaseSensitive(storage_listJSON, "offset");
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

    // storage_list->has_more
    cJSON *has_more = cJSON_GetObjectItemCaseSensitive(storage_listJSON, "hasMore");
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


    storage_list_local_var = storage_list_create_internal (
        resultsList,
        count->valuedouble,
        total->valuedouble,
        limit->valuedouble,
        offset->valuedouble,
        has_more->valueint
        );

    return storage_list_local_var;
end:
    if (resultsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resultsList) {
            media_store_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resultsList);
        resultsList = NULL;
    }
    return NULL;

}
