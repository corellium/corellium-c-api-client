#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "interconnect_list.h"



static interconnect_list_t *interconnect_list_create_internal(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    interconnect_list_t *interconnect_list_local_var = malloc(sizeof(interconnect_list_t));
    if (!interconnect_list_local_var) {
        return NULL;
    }
    interconnect_list_local_var->results = results;
    interconnect_list_local_var->count = count;
    interconnect_list_local_var->total = total;
    interconnect_list_local_var->limit = limit;
    interconnect_list_local_var->offset = offset;
    interconnect_list_local_var->has_more = has_more;

    interconnect_list_local_var->_library_owned = 1;
    return interconnect_list_local_var;
}

__attribute__((deprecated)) interconnect_list_t *interconnect_list_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    return interconnect_list_create_internal (
        results,
        count,
        total,
        limit,
        offset,
        has_more
        );
}

void interconnect_list_free(interconnect_list_t *interconnect_list) {
    if(NULL == interconnect_list){
        return ;
    }
    if(interconnect_list->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "interconnect_list_free");
        return ;
    }
    listEntry_t *listEntry;
    if (interconnect_list->results) {
        list_ForEach(listEntry, interconnect_list->results) {
            interconnect_free(listEntry->data);
        }
        list_freeList(interconnect_list->results);
        interconnect_list->results = NULL;
    }
    free(interconnect_list);
}

cJSON *interconnect_list_convertToJSON(interconnect_list_t *interconnect_list) {
    cJSON *item = cJSON_CreateObject();

    // interconnect_list->results
    if (!interconnect_list->results) {
        goto fail;
    }
    cJSON *results = cJSON_AddArrayToObject(item, "results");
    if(results == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resultsListEntry;
    if (interconnect_list->results) {
    list_ForEach(resultsListEntry, interconnect_list->results) {
    cJSON *itemLocal = interconnect_convertToJSON(resultsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(results, itemLocal);
    }
    }


    // interconnect_list->count
    if (!interconnect_list->count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "count", interconnect_list->count) == NULL) {
    goto fail; //Numeric
    }


    // interconnect_list->total
    if (!interconnect_list->total) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "total", interconnect_list->total) == NULL) {
    goto fail; //Numeric
    }


    // interconnect_list->limit
    if (!interconnect_list->limit) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "limit", interconnect_list->limit) == NULL) {
    goto fail; //Numeric
    }


    // interconnect_list->offset
    if (!interconnect_list->offset) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "offset", interconnect_list->offset) == NULL) {
    goto fail; //Numeric
    }


    // interconnect_list->has_more
    if (!interconnect_list->has_more) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "hasMore", interconnect_list->has_more) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

interconnect_list_t *interconnect_list_parseFromJSON(cJSON *interconnect_listJSON){

    interconnect_list_t *interconnect_list_local_var = NULL;

    // define the local list for interconnect_list->results
    list_t *resultsList = NULL;

    // interconnect_list->results
    cJSON *results = cJSON_GetObjectItemCaseSensitive(interconnect_listJSON, "results");
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
        interconnect_t *resultsItem = interconnect_parseFromJSON(results_local_nonprimitive);

        list_addElement(resultsList, resultsItem);
    }

    // interconnect_list->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(interconnect_listJSON, "count");
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

    // interconnect_list->total
    cJSON *total = cJSON_GetObjectItemCaseSensitive(interconnect_listJSON, "total");
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

    // interconnect_list->limit
    cJSON *limit = cJSON_GetObjectItemCaseSensitive(interconnect_listJSON, "limit");
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

    // interconnect_list->offset
    cJSON *offset = cJSON_GetObjectItemCaseSensitive(interconnect_listJSON, "offset");
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

    // interconnect_list->has_more
    cJSON *has_more = cJSON_GetObjectItemCaseSensitive(interconnect_listJSON, "hasMore");
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


    interconnect_list_local_var = interconnect_list_create_internal (
        resultsList,
        count->valuedouble,
        total->valuedouble,
        limit->valuedouble,
        offset->valuedouble,
        has_more->valueint
        );

    return interconnect_list_local_var;
end:
    if (resultsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resultsList) {
            interconnect_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resultsList);
        resultsList = NULL;
    }
    return NULL;

}
