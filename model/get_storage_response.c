#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_storage_response.h"



static get_storage_response_t *get_storage_response_create_internal(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset
    ) {
    get_storage_response_t *get_storage_response_local_var = malloc(sizeof(get_storage_response_t));
    if (!get_storage_response_local_var) {
        return NULL;
    }
    get_storage_response_local_var->results = results;
    get_storage_response_local_var->count = count;
    get_storage_response_local_var->total = total;
    get_storage_response_local_var->limit = limit;
    get_storage_response_local_var->offset = offset;

    get_storage_response_local_var->_library_owned = 1;
    return get_storage_response_local_var;
}

__attribute__((deprecated)) get_storage_response_t *get_storage_response_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset
    ) {
    return get_storage_response_create_internal (
        results,
        count,
        total,
        limit,
        offset
        );
}

void get_storage_response_free(get_storage_response_t *get_storage_response) {
    if(NULL == get_storage_response){
        return ;
    }
    if(get_storage_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "get_storage_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (get_storage_response->results) {
        list_ForEach(listEntry, get_storage_response->results) {
            media_store_v1_free(listEntry->data);
        }
        list_freeList(get_storage_response->results);
        get_storage_response->results = NULL;
    }
    free(get_storage_response);
}

cJSON *get_storage_response_convertToJSON(get_storage_response_t *get_storage_response) {
    cJSON *item = cJSON_CreateObject();

    // get_storage_response->results
    if(get_storage_response->results) {
    cJSON *results = cJSON_AddArrayToObject(item, "results");
    if(results == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resultsListEntry;
    if (get_storage_response->results) {
    list_ForEach(resultsListEntry, get_storage_response->results) {
    cJSON *itemLocal = media_store_v1_convertToJSON(resultsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(results, itemLocal);
    }
    }
    }


    // get_storage_response->count
    if(get_storage_response->count) {
    if(cJSON_AddNumberToObject(item, "count", get_storage_response->count) == NULL) {
    goto fail; //Numeric
    }
    }


    // get_storage_response->total
    if(get_storage_response->total) {
    if(cJSON_AddNumberToObject(item, "total", get_storage_response->total) == NULL) {
    goto fail; //Numeric
    }
    }


    // get_storage_response->limit
    if(get_storage_response->limit) {
    if(cJSON_AddNumberToObject(item, "limit", get_storage_response->limit) == NULL) {
    goto fail; //Numeric
    }
    }


    // get_storage_response->offset
    if(get_storage_response->offset) {
    if(cJSON_AddNumberToObject(item, "offset", get_storage_response->offset) == NULL) {
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

get_storage_response_t *get_storage_response_parseFromJSON(cJSON *get_storage_responseJSON){

    get_storage_response_t *get_storage_response_local_var = NULL;

    // define the local list for get_storage_response->results
    list_t *resultsList = NULL;

    // get_storage_response->results
    cJSON *results = cJSON_GetObjectItemCaseSensitive(get_storage_responseJSON, "results");
    if (cJSON_IsNull(results)) {
        results = NULL;
    }
    if (results) { 
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
        media_store_v1_t *resultsItem = media_store_v1_parseFromJSON(results_local_nonprimitive);

        list_addElement(resultsList, resultsItem);
    }
    }

    // get_storage_response->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(get_storage_responseJSON, "count");
    if (cJSON_IsNull(count)) {
        count = NULL;
    }
    if (count) { 
    if(!cJSON_IsNumber(count))
    {
    goto end; //Numeric
    }
    }

    // get_storage_response->total
    cJSON *total = cJSON_GetObjectItemCaseSensitive(get_storage_responseJSON, "total");
    if (cJSON_IsNull(total)) {
        total = NULL;
    }
    if (total) { 
    if(!cJSON_IsNumber(total))
    {
    goto end; //Numeric
    }
    }

    // get_storage_response->limit
    cJSON *limit = cJSON_GetObjectItemCaseSensitive(get_storage_responseJSON, "limit");
    if (cJSON_IsNull(limit)) {
        limit = NULL;
    }
    if (limit) { 
    if(!cJSON_IsNumber(limit))
    {
    goto end; //Numeric
    }
    }

    // get_storage_response->offset
    cJSON *offset = cJSON_GetObjectItemCaseSensitive(get_storage_responseJSON, "offset");
    if (cJSON_IsNull(offset)) {
        offset = NULL;
    }
    if (offset) { 
    if(!cJSON_IsNumber(offset))
    {
    goto end; //Numeric
    }
    }


    get_storage_response_local_var = get_storage_response_create_internal (
        results ? resultsList : NULL,
        count ? count->valuedouble : 0,
        total ? total->valuedouble : 0,
        limit ? limit->valuedouble : 0,
        offset ? offset->valuedouble : 0
        );

    return get_storage_response_local_var;
end:
    if (resultsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resultsList) {
            media_store_v1_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resultsList);
        resultsList = NULL;
    }
    return NULL;

}
