#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "network_connections.h"



static network_connections_t *network_connections_create_internal(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    network_connections_t *network_connections_local_var = malloc(sizeof(network_connections_t));
    if (!network_connections_local_var) {
        return NULL;
    }
    network_connections_local_var->results = results;
    network_connections_local_var->count = count;
    network_connections_local_var->total = total;
    network_connections_local_var->limit = limit;
    network_connections_local_var->offset = offset;
    network_connections_local_var->has_more = has_more;

    network_connections_local_var->_library_owned = 1;
    return network_connections_local_var;
}

__attribute__((deprecated)) network_connections_t *network_connections_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    return network_connections_create_internal (
        results,
        count,
        total,
        limit,
        offset,
        has_more
        );
}

void network_connections_free(network_connections_t *network_connections) {
    if(NULL == network_connections){
        return ;
    }
    if(network_connections->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "network_connections_free");
        return ;
    }
    listEntry_t *listEntry;
    if (network_connections->results) {
        list_ForEach(listEntry, network_connections->results) {
            object_free(listEntry->data);
        }
        list_freeList(network_connections->results);
        network_connections->results = NULL;
    }
    free(network_connections);
}

cJSON *network_connections_convertToJSON(network_connections_t *network_connections) {
    cJSON *item = cJSON_CreateObject();

    // network_connections->results
    if (!network_connections->results) {
        goto fail;
    }
    cJSON *results = cJSON_AddArrayToObject(item, "results");
    if(results == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resultsListEntry;
    if (network_connections->results) {
    list_ForEach(resultsListEntry, network_connections->results) {
    cJSON *itemLocal = object_convertToJSON(resultsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(results, itemLocal);
    }
    }


    // network_connections->count
    if (!network_connections->count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "count", network_connections->count) == NULL) {
    goto fail; //Numeric
    }


    // network_connections->total
    if (!network_connections->total) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "total", network_connections->total) == NULL) {
    goto fail; //Numeric
    }


    // network_connections->limit
    if (!network_connections->limit) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "limit", network_connections->limit) == NULL) {
    goto fail; //Numeric
    }


    // network_connections->offset
    if (!network_connections->offset) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "offset", network_connections->offset) == NULL) {
    goto fail; //Numeric
    }


    // network_connections->has_more
    if (!network_connections->has_more) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "hasMore", network_connections->has_more) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

network_connections_t *network_connections_parseFromJSON(cJSON *network_connectionsJSON){

    network_connections_t *network_connections_local_var = NULL;

    // define the local list for network_connections->results
    list_t *resultsList = NULL;

    // network_connections->results
    cJSON *results = cJSON_GetObjectItemCaseSensitive(network_connectionsJSON, "results");
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

    // network_connections->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(network_connectionsJSON, "count");
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

    // network_connections->total
    cJSON *total = cJSON_GetObjectItemCaseSensitive(network_connectionsJSON, "total");
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

    // network_connections->limit
    cJSON *limit = cJSON_GetObjectItemCaseSensitive(network_connectionsJSON, "limit");
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

    // network_connections->offset
    cJSON *offset = cJSON_GetObjectItemCaseSensitive(network_connectionsJSON, "offset");
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

    // network_connections->has_more
    cJSON *has_more = cJSON_GetObjectItemCaseSensitive(network_connectionsJSON, "hasMore");
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


    network_connections_local_var = network_connections_create_internal (
        resultsList,
        count->valuedouble,
        total->valuedouble,
        limit->valuedouble,
        offset->valuedouble,
        has_more->valueint
        );

    return network_connections_local_var;
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
