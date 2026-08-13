#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "list_instance_snapshots_response.h"



static list_instance_snapshots_response_t *list_instance_snapshots_response_create_internal(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    list_instance_snapshots_response_t *list_instance_snapshots_response_local_var = malloc(sizeof(list_instance_snapshots_response_t));
    if (!list_instance_snapshots_response_local_var) {
        return NULL;
    }
    list_instance_snapshots_response_local_var->results = results;
    list_instance_snapshots_response_local_var->count = count;
    list_instance_snapshots_response_local_var->total = total;
    list_instance_snapshots_response_local_var->limit = limit;
    list_instance_snapshots_response_local_var->offset = offset;
    list_instance_snapshots_response_local_var->has_more = has_more;

    list_instance_snapshots_response_local_var->_library_owned = 1;
    return list_instance_snapshots_response_local_var;
}

__attribute__((deprecated)) list_instance_snapshots_response_t *list_instance_snapshots_response_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    return list_instance_snapshots_response_create_internal (
        results,
        count,
        total,
        limit,
        offset,
        has_more
        );
}

void list_instance_snapshots_response_free(list_instance_snapshots_response_t *list_instance_snapshots_response) {
    if(NULL == list_instance_snapshots_response){
        return ;
    }
    if(list_instance_snapshots_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "list_instance_snapshots_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (list_instance_snapshots_response->results) {
        list_ForEach(listEntry, list_instance_snapshots_response->results) {
            snapshot_free(listEntry->data);
        }
        list_freeList(list_instance_snapshots_response->results);
        list_instance_snapshots_response->results = NULL;
    }
    free(list_instance_snapshots_response);
}

cJSON *list_instance_snapshots_response_convertToJSON(list_instance_snapshots_response_t *list_instance_snapshots_response) {
    cJSON *item = cJSON_CreateObject();

    // list_instance_snapshots_response->results
    if (!list_instance_snapshots_response->results) {
        goto fail;
    }
    cJSON *results = cJSON_AddArrayToObject(item, "results");
    if(results == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resultsListEntry;
    if (list_instance_snapshots_response->results) {
    list_ForEach(resultsListEntry, list_instance_snapshots_response->results) {
    cJSON *itemLocal = snapshot_convertToJSON(resultsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(results, itemLocal);
    }
    }


    // list_instance_snapshots_response->count
    if (!list_instance_snapshots_response->count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "count", list_instance_snapshots_response->count) == NULL) {
    goto fail; //Numeric
    }


    // list_instance_snapshots_response->total
    if (!list_instance_snapshots_response->total) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "total", list_instance_snapshots_response->total) == NULL) {
    goto fail; //Numeric
    }


    // list_instance_snapshots_response->limit
    if (!list_instance_snapshots_response->limit) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "limit", list_instance_snapshots_response->limit) == NULL) {
    goto fail; //Numeric
    }


    // list_instance_snapshots_response->offset
    if (!list_instance_snapshots_response->offset) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "offset", list_instance_snapshots_response->offset) == NULL) {
    goto fail; //Numeric
    }


    // list_instance_snapshots_response->has_more
    if (!list_instance_snapshots_response->has_more) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "hasMore", list_instance_snapshots_response->has_more) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

list_instance_snapshots_response_t *list_instance_snapshots_response_parseFromJSON(cJSON *list_instance_snapshots_responseJSON){

    list_instance_snapshots_response_t *list_instance_snapshots_response_local_var = NULL;

    // define the local list for list_instance_snapshots_response->results
    list_t *resultsList = NULL;

    // list_instance_snapshots_response->results
    cJSON *results = cJSON_GetObjectItemCaseSensitive(list_instance_snapshots_responseJSON, "results");
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
        snapshot_t *resultsItem = snapshot_parseFromJSON(results_local_nonprimitive);

        list_addElement(resultsList, resultsItem);
    }

    // list_instance_snapshots_response->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(list_instance_snapshots_responseJSON, "count");
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

    // list_instance_snapshots_response->total
    cJSON *total = cJSON_GetObjectItemCaseSensitive(list_instance_snapshots_responseJSON, "total");
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

    // list_instance_snapshots_response->limit
    cJSON *limit = cJSON_GetObjectItemCaseSensitive(list_instance_snapshots_responseJSON, "limit");
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

    // list_instance_snapshots_response->offset
    cJSON *offset = cJSON_GetObjectItemCaseSensitive(list_instance_snapshots_responseJSON, "offset");
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

    // list_instance_snapshots_response->has_more
    cJSON *has_more = cJSON_GetObjectItemCaseSensitive(list_instance_snapshots_responseJSON, "hasMore");
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


    list_instance_snapshots_response_local_var = list_instance_snapshots_response_create_internal (
        resultsList,
        count->valuedouble,
        total->valuedouble,
        limit->valuedouble,
        offset->valuedouble,
        has_more->valueint
        );

    return list_instance_snapshots_response_local_var;
end:
    if (resultsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resultsList) {
            snapshot_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resultsList);
        resultsList = NULL;
    }
    return NULL;

}
