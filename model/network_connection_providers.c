#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "network_connection_providers.h"



static network_connection_providers_t *network_connection_providers_create_internal(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    network_connection_providers_t *network_connection_providers_local_var = malloc(sizeof(network_connection_providers_t));
    if (!network_connection_providers_local_var) {
        return NULL;
    }
    network_connection_providers_local_var->results = results;
    network_connection_providers_local_var->count = count;
    network_connection_providers_local_var->total = total;
    network_connection_providers_local_var->limit = limit;
    network_connection_providers_local_var->offset = offset;
    network_connection_providers_local_var->has_more = has_more;

    network_connection_providers_local_var->_library_owned = 1;
    return network_connection_providers_local_var;
}

__attribute__((deprecated)) network_connection_providers_t *network_connection_providers_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    return network_connection_providers_create_internal (
        results,
        count,
        total,
        limit,
        offset,
        has_more
        );
}

void network_connection_providers_free(network_connection_providers_t *network_connection_providers) {
    if(NULL == network_connection_providers){
        return ;
    }
    if(network_connection_providers->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "network_connection_providers_free");
        return ;
    }
    listEntry_t *listEntry;
    if (network_connection_providers->results) {
        list_ForEach(listEntry, network_connection_providers->results) {
            network_connection_providers_results_inner_free(listEntry->data);
        }
        list_freeList(network_connection_providers->results);
        network_connection_providers->results = NULL;
    }
    free(network_connection_providers);
}

cJSON *network_connection_providers_convertToJSON(network_connection_providers_t *network_connection_providers) {
    cJSON *item = cJSON_CreateObject();

    // network_connection_providers->results
    if (!network_connection_providers->results) {
        goto fail;
    }
    cJSON *results = cJSON_AddArrayToObject(item, "results");
    if(results == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resultsListEntry;
    if (network_connection_providers->results) {
    list_ForEach(resultsListEntry, network_connection_providers->results) {
    cJSON *itemLocal = network_connection_providers_results_inner_convertToJSON(resultsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(results, itemLocal);
    }
    }


    // network_connection_providers->count
    if (!network_connection_providers->count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "count", network_connection_providers->count) == NULL) {
    goto fail; //Numeric
    }


    // network_connection_providers->total
    if (!network_connection_providers->total) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "total", network_connection_providers->total) == NULL) {
    goto fail; //Numeric
    }


    // network_connection_providers->limit
    if (!network_connection_providers->limit) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "limit", network_connection_providers->limit) == NULL) {
    goto fail; //Numeric
    }


    // network_connection_providers->offset
    if (!network_connection_providers->offset) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "offset", network_connection_providers->offset) == NULL) {
    goto fail; //Numeric
    }


    // network_connection_providers->has_more
    if (!network_connection_providers->has_more) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "hasMore", network_connection_providers->has_more) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

network_connection_providers_t *network_connection_providers_parseFromJSON(cJSON *network_connection_providersJSON){

    network_connection_providers_t *network_connection_providers_local_var = NULL;

    // define the local list for network_connection_providers->results
    list_t *resultsList = NULL;

    // network_connection_providers->results
    cJSON *results = cJSON_GetObjectItemCaseSensitive(network_connection_providersJSON, "results");
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
        network_connection_providers_results_inner_t *resultsItem = network_connection_providers_results_inner_parseFromJSON(results_local_nonprimitive);

        list_addElement(resultsList, resultsItem);
    }

    // network_connection_providers->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(network_connection_providersJSON, "count");
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

    // network_connection_providers->total
    cJSON *total = cJSON_GetObjectItemCaseSensitive(network_connection_providersJSON, "total");
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

    // network_connection_providers->limit
    cJSON *limit = cJSON_GetObjectItemCaseSensitive(network_connection_providersJSON, "limit");
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

    // network_connection_providers->offset
    cJSON *offset = cJSON_GetObjectItemCaseSensitive(network_connection_providersJSON, "offset");
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

    // network_connection_providers->has_more
    cJSON *has_more = cJSON_GetObjectItemCaseSensitive(network_connection_providersJSON, "hasMore");
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


    network_connection_providers_local_var = network_connection_providers_create_internal (
        resultsList,
        count->valuedouble,
        total->valuedouble,
        limit->valuedouble,
        offset->valuedouble,
        has_more->valueint
        );

    return network_connection_providers_local_var;
end:
    if (resultsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resultsList) {
            network_connection_providers_results_inner_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resultsList);
        resultsList = NULL;
    }
    return NULL;

}
