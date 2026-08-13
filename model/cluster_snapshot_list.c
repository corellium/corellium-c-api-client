#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cluster_snapshot_list.h"



static cluster_snapshot_list_t *cluster_snapshot_list_create_internal(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    cluster_snapshot_list_t *cluster_snapshot_list_local_var = malloc(sizeof(cluster_snapshot_list_t));
    if (!cluster_snapshot_list_local_var) {
        return NULL;
    }
    cluster_snapshot_list_local_var->results = results;
    cluster_snapshot_list_local_var->count = count;
    cluster_snapshot_list_local_var->total = total;
    cluster_snapshot_list_local_var->limit = limit;
    cluster_snapshot_list_local_var->offset = offset;
    cluster_snapshot_list_local_var->has_more = has_more;

    cluster_snapshot_list_local_var->_library_owned = 1;
    return cluster_snapshot_list_local_var;
}

__attribute__((deprecated)) cluster_snapshot_list_t *cluster_snapshot_list_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    return cluster_snapshot_list_create_internal (
        results,
        count,
        total,
        limit,
        offset,
        has_more
        );
}

void cluster_snapshot_list_free(cluster_snapshot_list_t *cluster_snapshot_list) {
    if(NULL == cluster_snapshot_list){
        return ;
    }
    if(cluster_snapshot_list->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cluster_snapshot_list_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cluster_snapshot_list->results) {
        list_ForEach(listEntry, cluster_snapshot_list->results) {
            cluster_snapshot_free(listEntry->data);
        }
        list_freeList(cluster_snapshot_list->results);
        cluster_snapshot_list->results = NULL;
    }
    free(cluster_snapshot_list);
}

cJSON *cluster_snapshot_list_convertToJSON(cluster_snapshot_list_t *cluster_snapshot_list) {
    cJSON *item = cJSON_CreateObject();

    // cluster_snapshot_list->results
    if (!cluster_snapshot_list->results) {
        goto fail;
    }
    cJSON *results = cJSON_AddArrayToObject(item, "results");
    if(results == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resultsListEntry;
    if (cluster_snapshot_list->results) {
    list_ForEach(resultsListEntry, cluster_snapshot_list->results) {
    cJSON *itemLocal = cluster_snapshot_convertToJSON(resultsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(results, itemLocal);
    }
    }


    // cluster_snapshot_list->count
    if (!cluster_snapshot_list->count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "count", cluster_snapshot_list->count) == NULL) {
    goto fail; //Numeric
    }


    // cluster_snapshot_list->total
    if (!cluster_snapshot_list->total) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "total", cluster_snapshot_list->total) == NULL) {
    goto fail; //Numeric
    }


    // cluster_snapshot_list->limit
    if (!cluster_snapshot_list->limit) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "limit", cluster_snapshot_list->limit) == NULL) {
    goto fail; //Numeric
    }


    // cluster_snapshot_list->offset
    if (!cluster_snapshot_list->offset) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "offset", cluster_snapshot_list->offset) == NULL) {
    goto fail; //Numeric
    }


    // cluster_snapshot_list->has_more
    if (!cluster_snapshot_list->has_more) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "hasMore", cluster_snapshot_list->has_more) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

cluster_snapshot_list_t *cluster_snapshot_list_parseFromJSON(cJSON *cluster_snapshot_listJSON){

    cluster_snapshot_list_t *cluster_snapshot_list_local_var = NULL;

    // define the local list for cluster_snapshot_list->results
    list_t *resultsList = NULL;

    // cluster_snapshot_list->results
    cJSON *results = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_listJSON, "results");
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
        cluster_snapshot_t *resultsItem = cluster_snapshot_parseFromJSON(results_local_nonprimitive);

        list_addElement(resultsList, resultsItem);
    }

    // cluster_snapshot_list->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_listJSON, "count");
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

    // cluster_snapshot_list->total
    cJSON *total = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_listJSON, "total");
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

    // cluster_snapshot_list->limit
    cJSON *limit = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_listJSON, "limit");
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

    // cluster_snapshot_list->offset
    cJSON *offset = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_listJSON, "offset");
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

    // cluster_snapshot_list->has_more
    cJSON *has_more = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_listJSON, "hasMore");
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


    cluster_snapshot_list_local_var = cluster_snapshot_list_create_internal (
        resultsList,
        count->valuedouble,
        total->valuedouble,
        limit->valuedouble,
        offset->valuedouble,
        has_more->valueint
        );

    return cluster_snapshot_list_local_var;
end:
    if (resultsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resultsList) {
            cluster_snapshot_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resultsList);
        resultsList = NULL;
    }
    return NULL;

}
