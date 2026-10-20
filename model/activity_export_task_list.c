#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "activity_export_task_list.h"



static activity_export_task_list_t *activity_export_task_list_create_internal(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    activity_export_task_list_t *activity_export_task_list_local_var = malloc(sizeof(activity_export_task_list_t));
    if (!activity_export_task_list_local_var) {
        return NULL;
    }
    activity_export_task_list_local_var->results = results;
    activity_export_task_list_local_var->count = count;
    activity_export_task_list_local_var->total = total;
    activity_export_task_list_local_var->limit = limit;
    activity_export_task_list_local_var->offset = offset;
    activity_export_task_list_local_var->has_more = has_more;

    activity_export_task_list_local_var->_library_owned = 1;
    return activity_export_task_list_local_var;
}

__attribute__((deprecated)) activity_export_task_list_t *activity_export_task_list_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    return activity_export_task_list_create_internal (
        results,
        count,
        total,
        limit,
        offset,
        has_more
        );
}

void activity_export_task_list_free(activity_export_task_list_t *activity_export_task_list) {
    if(NULL == activity_export_task_list){
        return ;
    }
    if(activity_export_task_list->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "activity_export_task_list_free");
        return ;
    }
    listEntry_t *listEntry;
    if (activity_export_task_list->results) {
        list_ForEach(listEntry, activity_export_task_list->results) {
            activity_export_task_free(listEntry->data);
        }
        list_freeList(activity_export_task_list->results);
        activity_export_task_list->results = NULL;
    }
    free(activity_export_task_list);
}

cJSON *activity_export_task_list_convertToJSON(activity_export_task_list_t *activity_export_task_list) {
    cJSON *item = cJSON_CreateObject();

    // activity_export_task_list->results
    if (!activity_export_task_list->results) {
        goto fail;
    }
    cJSON *results = cJSON_AddArrayToObject(item, "results");
    if(results == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resultsListEntry;
    if (activity_export_task_list->results) {
    list_ForEach(resultsListEntry, activity_export_task_list->results) {
    cJSON *itemLocal = activity_export_task_convertToJSON(resultsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(results, itemLocal);
    }
    }


    // activity_export_task_list->count
    if (!activity_export_task_list->count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "count", activity_export_task_list->count) == NULL) {
    goto fail; //Numeric
    }


    // activity_export_task_list->total
    if (!activity_export_task_list->total) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "total", activity_export_task_list->total) == NULL) {
    goto fail; //Numeric
    }


    // activity_export_task_list->limit
    if (!activity_export_task_list->limit) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "limit", activity_export_task_list->limit) == NULL) {
    goto fail; //Numeric
    }


    // activity_export_task_list->offset
    if (!activity_export_task_list->offset) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "offset", activity_export_task_list->offset) == NULL) {
    goto fail; //Numeric
    }


    // activity_export_task_list->has_more
    if (!activity_export_task_list->has_more) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "hasMore", activity_export_task_list->has_more) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

activity_export_task_list_t *activity_export_task_list_parseFromJSON(cJSON *activity_export_task_listJSON){

    activity_export_task_list_t *activity_export_task_list_local_var = NULL;

    // define the local list for activity_export_task_list->results
    list_t *resultsList = NULL;

    // activity_export_task_list->results
    cJSON *results = cJSON_GetObjectItemCaseSensitive(activity_export_task_listJSON, "results");
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
        activity_export_task_t *resultsItem = activity_export_task_parseFromJSON(results_local_nonprimitive);

        list_addElement(resultsList, resultsItem);
    }

    // activity_export_task_list->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(activity_export_task_listJSON, "count");
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

    // activity_export_task_list->total
    cJSON *total = cJSON_GetObjectItemCaseSensitive(activity_export_task_listJSON, "total");
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

    // activity_export_task_list->limit
    cJSON *limit = cJSON_GetObjectItemCaseSensitive(activity_export_task_listJSON, "limit");
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

    // activity_export_task_list->offset
    cJSON *offset = cJSON_GetObjectItemCaseSensitive(activity_export_task_listJSON, "offset");
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

    // activity_export_task_list->has_more
    cJSON *has_more = cJSON_GetObjectItemCaseSensitive(activity_export_task_listJSON, "hasMore");
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


    activity_export_task_list_local_var = activity_export_task_list_create_internal (
        resultsList,
        count->valuedouble,
        total->valuedouble,
        limit->valuedouble,
        offset->valuedouble,
        has_more->valueint
        );

    return activity_export_task_list_local_var;
end:
    if (resultsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resultsList) {
            activity_export_task_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resultsList);
        resultsList = NULL;
    }
    return NULL;

}
