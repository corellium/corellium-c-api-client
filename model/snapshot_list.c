#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "snapshot_list.h"



static snapshot_list_t *snapshot_list_create_internal(
    list_t *results,
    double offset,
    double limit,
    double count
    ) {
    snapshot_list_t *snapshot_list_local_var = malloc(sizeof(snapshot_list_t));
    if (!snapshot_list_local_var) {
        return NULL;
    }
    snapshot_list_local_var->results = results;
    snapshot_list_local_var->offset = offset;
    snapshot_list_local_var->limit = limit;
    snapshot_list_local_var->count = count;

    snapshot_list_local_var->_library_owned = 1;
    return snapshot_list_local_var;
}

__attribute__((deprecated)) snapshot_list_t *snapshot_list_create(
    list_t *results,
    double offset,
    double limit,
    double count
    ) {
    return snapshot_list_create_internal (
        results,
        offset,
        limit,
        count
        );
}

void snapshot_list_free(snapshot_list_t *snapshot_list) {
    if(NULL == snapshot_list){
        return ;
    }
    if(snapshot_list->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "snapshot_list_free");
        return ;
    }
    listEntry_t *listEntry;
    if (snapshot_list->results) {
        list_ForEach(listEntry, snapshot_list->results) {
            cluster_snapshot_v1_free(listEntry->data);
        }
        list_freeList(snapshot_list->results);
        snapshot_list->results = NULL;
    }
    free(snapshot_list);
}

cJSON *snapshot_list_convertToJSON(snapshot_list_t *snapshot_list) {
    cJSON *item = cJSON_CreateObject();

    // snapshot_list->results
    if(snapshot_list->results) {
    cJSON *results = cJSON_AddArrayToObject(item, "results");
    if(results == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resultsListEntry;
    if (snapshot_list->results) {
    list_ForEach(resultsListEntry, snapshot_list->results) {
    cJSON *itemLocal = cluster_snapshot_v1_convertToJSON(resultsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(results, itemLocal);
    }
    }
    }


    // snapshot_list->offset
    if(snapshot_list->offset) {
    if(cJSON_AddNumberToObject(item, "offset", snapshot_list->offset) == NULL) {
    goto fail; //Numeric
    }
    }


    // snapshot_list->limit
    if(snapshot_list->limit) {
    if(cJSON_AddNumberToObject(item, "limit", snapshot_list->limit) == NULL) {
    goto fail; //Numeric
    }
    }


    // snapshot_list->count
    if(snapshot_list->count) {
    if(cJSON_AddNumberToObject(item, "count", snapshot_list->count) == NULL) {
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

snapshot_list_t *snapshot_list_parseFromJSON(cJSON *snapshot_listJSON){

    snapshot_list_t *snapshot_list_local_var = NULL;

    // define the local list for snapshot_list->results
    list_t *resultsList = NULL;

    // snapshot_list->results
    cJSON *results = cJSON_GetObjectItemCaseSensitive(snapshot_listJSON, "results");
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
        cluster_snapshot_v1_t *resultsItem = cluster_snapshot_v1_parseFromJSON(results_local_nonprimitive);

        list_addElement(resultsList, resultsItem);
    }
    }

    // snapshot_list->offset
    cJSON *offset = cJSON_GetObjectItemCaseSensitive(snapshot_listJSON, "offset");
    if (cJSON_IsNull(offset)) {
        offset = NULL;
    }
    if (offset) { 
    if(!cJSON_IsNumber(offset))
    {
    goto end; //Numeric
    }
    }

    // snapshot_list->limit
    cJSON *limit = cJSON_GetObjectItemCaseSensitive(snapshot_listJSON, "limit");
    if (cJSON_IsNull(limit)) {
        limit = NULL;
    }
    if (limit) { 
    if(!cJSON_IsNumber(limit))
    {
    goto end; //Numeric
    }
    }

    // snapshot_list->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(snapshot_listJSON, "count");
    if (cJSON_IsNull(count)) {
        count = NULL;
    }
    if (count) { 
    if(!cJSON_IsNumber(count))
    {
    goto end; //Numeric
    }
    }


    snapshot_list_local_var = snapshot_list_create_internal (
        results ? resultsList : NULL,
        offset ? offset->valuedouble : 0,
        limit ? limit->valuedouble : 0,
        count ? count->valuedouble : 0
        );

    return snapshot_list_local_var;
end:
    if (resultsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resultsList) {
            cluster_snapshot_v1_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resultsList);
        resultsList = NULL;
    }
    return NULL;

}
