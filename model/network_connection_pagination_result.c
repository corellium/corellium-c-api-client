#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "network_connection_pagination_result.h"



static network_connection_pagination_result_t *network_connection_pagination_result_create_internal(
    double total,
    double count,
    double limit,
    double offset,
    int has_more,
    list_t *results
    ) {
    network_connection_pagination_result_t *network_connection_pagination_result_local_var = malloc(sizeof(network_connection_pagination_result_t));
    if (!network_connection_pagination_result_local_var) {
        return NULL;
    }
    network_connection_pagination_result_local_var->total = total;
    network_connection_pagination_result_local_var->count = count;
    network_connection_pagination_result_local_var->limit = limit;
    network_connection_pagination_result_local_var->offset = offset;
    network_connection_pagination_result_local_var->has_more = has_more;
    network_connection_pagination_result_local_var->results = results;

    network_connection_pagination_result_local_var->_library_owned = 1;
    return network_connection_pagination_result_local_var;
}

__attribute__((deprecated)) network_connection_pagination_result_t *network_connection_pagination_result_create(
    double total,
    double count,
    double limit,
    double offset,
    int has_more,
    list_t *results
    ) {
    return network_connection_pagination_result_create_internal (
        total,
        count,
        limit,
        offset,
        has_more,
        results
        );
}

void network_connection_pagination_result_free(network_connection_pagination_result_t *network_connection_pagination_result) {
    if(NULL == network_connection_pagination_result){
        return ;
    }
    if(network_connection_pagination_result->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "network_connection_pagination_result_free");
        return ;
    }
    listEntry_t *listEntry;
    if (network_connection_pagination_result->results) {
        list_ForEach(listEntry, network_connection_pagination_result->results) {
            object_free(listEntry->data);
        }
        list_freeList(network_connection_pagination_result->results);
        network_connection_pagination_result->results = NULL;
    }
    free(network_connection_pagination_result);
}

cJSON *network_connection_pagination_result_convertToJSON(network_connection_pagination_result_t *network_connection_pagination_result) {
    cJSON *item = cJSON_CreateObject();

    // network_connection_pagination_result->total
    if (!network_connection_pagination_result->total) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "total", network_connection_pagination_result->total) == NULL) {
    goto fail; //Numeric
    }


    // network_connection_pagination_result->count
    if (!network_connection_pagination_result->count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "count", network_connection_pagination_result->count) == NULL) {
    goto fail; //Numeric
    }


    // network_connection_pagination_result->limit
    if (!network_connection_pagination_result->limit) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "limit", network_connection_pagination_result->limit) == NULL) {
    goto fail; //Numeric
    }


    // network_connection_pagination_result->offset
    if (!network_connection_pagination_result->offset) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "offset", network_connection_pagination_result->offset) == NULL) {
    goto fail; //Numeric
    }


    // network_connection_pagination_result->has_more
    if (!network_connection_pagination_result->has_more) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "hasMore", network_connection_pagination_result->has_more) == NULL) {
    goto fail; //Bool
    }


    // network_connection_pagination_result->results
    if (!network_connection_pagination_result->results) {
        goto fail;
    }
    cJSON *results = cJSON_AddArrayToObject(item, "results");
    if(results == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resultsListEntry;
    if (network_connection_pagination_result->results) {
    list_ForEach(resultsListEntry, network_connection_pagination_result->results) {
    cJSON *itemLocal = object_convertToJSON(resultsListEntry->data);
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

network_connection_pagination_result_t *network_connection_pagination_result_parseFromJSON(cJSON *network_connection_pagination_resultJSON){

    network_connection_pagination_result_t *network_connection_pagination_result_local_var = NULL;

    // define the local list for network_connection_pagination_result->results
    list_t *resultsList = NULL;

    // network_connection_pagination_result->total
    cJSON *total = cJSON_GetObjectItemCaseSensitive(network_connection_pagination_resultJSON, "total");
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

    // network_connection_pagination_result->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(network_connection_pagination_resultJSON, "count");
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

    // network_connection_pagination_result->limit
    cJSON *limit = cJSON_GetObjectItemCaseSensitive(network_connection_pagination_resultJSON, "limit");
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

    // network_connection_pagination_result->offset
    cJSON *offset = cJSON_GetObjectItemCaseSensitive(network_connection_pagination_resultJSON, "offset");
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

    // network_connection_pagination_result->has_more
    cJSON *has_more = cJSON_GetObjectItemCaseSensitive(network_connection_pagination_resultJSON, "hasMore");
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

    // network_connection_pagination_result->results
    cJSON *results = cJSON_GetObjectItemCaseSensitive(network_connection_pagination_resultJSON, "results");
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
        object_t *resultsItem = object_parseFromJSON(results_local_nonprimitive);

        list_addElement(resultsList, resultsItem);
    }


    network_connection_pagination_result_local_var = network_connection_pagination_result_create_internal (
        total->valuedouble,
        count->valuedouble,
        limit->valuedouble,
        offset->valuedouble,
        has_more->valueint,
        resultsList
        );

    return network_connection_pagination_result_local_var;
end:
    if (resultsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resultsList) {
            object_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resultsList);
        resultsList = NULL;
    }
    return NULL;

}
