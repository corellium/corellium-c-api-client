#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "node_list.h"



static node_list_t *node_list_create_internal(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    node_list_t *node_list_local_var = malloc(sizeof(node_list_t));
    if (!node_list_local_var) {
        return NULL;
    }
    node_list_local_var->results = results;
    node_list_local_var->count = count;
    node_list_local_var->total = total;
    node_list_local_var->limit = limit;
    node_list_local_var->offset = offset;
    node_list_local_var->has_more = has_more;

    node_list_local_var->_library_owned = 1;
    return node_list_local_var;
}

__attribute__((deprecated)) node_list_t *node_list_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    return node_list_create_internal (
        results,
        count,
        total,
        limit,
        offset,
        has_more
        );
}

void node_list_free(node_list_t *node_list) {
    if(NULL == node_list){
        return ;
    }
    if(node_list->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "node_list_free");
        return ;
    }
    listEntry_t *listEntry;
    if (node_list->results) {
        list_ForEach(listEntry, node_list->results) {
            node_information_free(listEntry->data);
        }
        list_freeList(node_list->results);
        node_list->results = NULL;
    }
    free(node_list);
}

cJSON *node_list_convertToJSON(node_list_t *node_list) {
    cJSON *item = cJSON_CreateObject();

    // node_list->results
    if (!node_list->results) {
        goto fail;
    }
    cJSON *results = cJSON_AddArrayToObject(item, "results");
    if(results == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resultsListEntry;
    if (node_list->results) {
    list_ForEach(resultsListEntry, node_list->results) {
    cJSON *itemLocal = node_information_convertToJSON(resultsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(results, itemLocal);
    }
    }


    // node_list->count
    if (!node_list->count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "count", node_list->count) == NULL) {
    goto fail; //Numeric
    }


    // node_list->total
    if (!node_list->total) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "total", node_list->total) == NULL) {
    goto fail; //Numeric
    }


    // node_list->limit
    if (!node_list->limit) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "limit", node_list->limit) == NULL) {
    goto fail; //Numeric
    }


    // node_list->offset
    if (!node_list->offset) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "offset", node_list->offset) == NULL) {
    goto fail; //Numeric
    }


    // node_list->has_more
    if (!node_list->has_more) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "hasMore", node_list->has_more) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

node_list_t *node_list_parseFromJSON(cJSON *node_listJSON){

    node_list_t *node_list_local_var = NULL;

    // define the local list for node_list->results
    list_t *resultsList = NULL;

    // node_list->results
    cJSON *results = cJSON_GetObjectItemCaseSensitive(node_listJSON, "results");
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
        node_information_t *resultsItem = node_information_parseFromJSON(results_local_nonprimitive);

        list_addElement(resultsList, resultsItem);
    }

    // node_list->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(node_listJSON, "count");
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

    // node_list->total
    cJSON *total = cJSON_GetObjectItemCaseSensitive(node_listJSON, "total");
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

    // node_list->limit
    cJSON *limit = cJSON_GetObjectItemCaseSensitive(node_listJSON, "limit");
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

    // node_list->offset
    cJSON *offset = cJSON_GetObjectItemCaseSensitive(node_listJSON, "offset");
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

    // node_list->has_more
    cJSON *has_more = cJSON_GetObjectItemCaseSensitive(node_listJSON, "hasMore");
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


    node_list_local_var = node_list_create_internal (
        resultsList,
        count->valuedouble,
        total->valuedouble,
        limit->valuedouble,
        offset->valuedouble,
        has_more->valueint
        );

    return node_list_local_var;
end:
    if (resultsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resultsList) {
            node_information_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resultsList);
        resultsList = NULL;
    }
    return NULL;

}
