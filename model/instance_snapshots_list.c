#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "instance_snapshots_list.h"



static instance_snapshots_list_t *instance_snapshots_list_create_internal(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    instance_snapshots_list_t *instance_snapshots_list_local_var = malloc(sizeof(instance_snapshots_list_t));
    if (!instance_snapshots_list_local_var) {
        return NULL;
    }
    instance_snapshots_list_local_var->results = results;
    instance_snapshots_list_local_var->count = count;
    instance_snapshots_list_local_var->total = total;
    instance_snapshots_list_local_var->limit = limit;
    instance_snapshots_list_local_var->offset = offset;
    instance_snapshots_list_local_var->has_more = has_more;

    instance_snapshots_list_local_var->_library_owned = 1;
    return instance_snapshots_list_local_var;
}

__attribute__((deprecated)) instance_snapshots_list_t *instance_snapshots_list_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    return instance_snapshots_list_create_internal (
        results,
        count,
        total,
        limit,
        offset,
        has_more
        );
}

void instance_snapshots_list_free(instance_snapshots_list_t *instance_snapshots_list) {
    if(NULL == instance_snapshots_list){
        return ;
    }
    if(instance_snapshots_list->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "instance_snapshots_list_free");
        return ;
    }
    listEntry_t *listEntry;
    if (instance_snapshots_list->results) {
        list_ForEach(listEntry, instance_snapshots_list->results) {
            snapshot_free(listEntry->data);
        }
        list_freeList(instance_snapshots_list->results);
        instance_snapshots_list->results = NULL;
    }
    free(instance_snapshots_list);
}

cJSON *instance_snapshots_list_convertToJSON(instance_snapshots_list_t *instance_snapshots_list) {
    cJSON *item = cJSON_CreateObject();

    // instance_snapshots_list->results
    if (!instance_snapshots_list->results) {
        goto fail;
    }
    cJSON *results = cJSON_AddArrayToObject(item, "results");
    if(results == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resultsListEntry;
    if (instance_snapshots_list->results) {
    list_ForEach(resultsListEntry, instance_snapshots_list->results) {
    cJSON *itemLocal = snapshot_convertToJSON(resultsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(results, itemLocal);
    }
    }


    // instance_snapshots_list->count
    if (!instance_snapshots_list->count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "count", instance_snapshots_list->count) == NULL) {
    goto fail; //Numeric
    }


    // instance_snapshots_list->total
    if (!instance_snapshots_list->total) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "total", instance_snapshots_list->total) == NULL) {
    goto fail; //Numeric
    }


    // instance_snapshots_list->limit
    if (!instance_snapshots_list->limit) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "limit", instance_snapshots_list->limit) == NULL) {
    goto fail; //Numeric
    }


    // instance_snapshots_list->offset
    if (!instance_snapshots_list->offset) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "offset", instance_snapshots_list->offset) == NULL) {
    goto fail; //Numeric
    }


    // instance_snapshots_list->has_more
    if (!instance_snapshots_list->has_more) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "hasMore", instance_snapshots_list->has_more) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

instance_snapshots_list_t *instance_snapshots_list_parseFromJSON(cJSON *instance_snapshots_listJSON){

    instance_snapshots_list_t *instance_snapshots_list_local_var = NULL;

    // define the local list for instance_snapshots_list->results
    list_t *resultsList = NULL;

    // instance_snapshots_list->results
    cJSON *results = cJSON_GetObjectItemCaseSensitive(instance_snapshots_listJSON, "results");
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

    // instance_snapshots_list->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(instance_snapshots_listJSON, "count");
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

    // instance_snapshots_list->total
    cJSON *total = cJSON_GetObjectItemCaseSensitive(instance_snapshots_listJSON, "total");
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

    // instance_snapshots_list->limit
    cJSON *limit = cJSON_GetObjectItemCaseSensitive(instance_snapshots_listJSON, "limit");
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

    // instance_snapshots_list->offset
    cJSON *offset = cJSON_GetObjectItemCaseSensitive(instance_snapshots_listJSON, "offset");
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

    // instance_snapshots_list->has_more
    cJSON *has_more = cJSON_GetObjectItemCaseSensitive(instance_snapshots_listJSON, "hasMore");
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


    instance_snapshots_list_local_var = instance_snapshots_list_create_internal (
        resultsList,
        count->valuedouble,
        total->valuedouble,
        limit->valuedouble,
        offset->valuedouble,
        has_more->valueint
        );

    return instance_snapshots_list_local_var;
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
