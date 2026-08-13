#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cloud_notification_list.h"



static cloud_notification_list_t *cloud_notification_list_create_internal(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    cloud_notification_list_t *cloud_notification_list_local_var = malloc(sizeof(cloud_notification_list_t));
    if (!cloud_notification_list_local_var) {
        return NULL;
    }
    cloud_notification_list_local_var->results = results;
    cloud_notification_list_local_var->count = count;
    cloud_notification_list_local_var->total = total;
    cloud_notification_list_local_var->limit = limit;
    cloud_notification_list_local_var->offset = offset;
    cloud_notification_list_local_var->has_more = has_more;

    cloud_notification_list_local_var->_library_owned = 1;
    return cloud_notification_list_local_var;
}

__attribute__((deprecated)) cloud_notification_list_t *cloud_notification_list_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    return cloud_notification_list_create_internal (
        results,
        count,
        total,
        limit,
        offset,
        has_more
        );
}

void cloud_notification_list_free(cloud_notification_list_t *cloud_notification_list) {
    if(NULL == cloud_notification_list){
        return ;
    }
    if(cloud_notification_list->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cloud_notification_list_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cloud_notification_list->results) {
        list_ForEach(listEntry, cloud_notification_list->results) {
            cloud_notification_item_free(listEntry->data);
        }
        list_freeList(cloud_notification_list->results);
        cloud_notification_list->results = NULL;
    }
    free(cloud_notification_list);
}

cJSON *cloud_notification_list_convertToJSON(cloud_notification_list_t *cloud_notification_list) {
    cJSON *item = cJSON_CreateObject();

    // cloud_notification_list->results
    if (!cloud_notification_list->results) {
        goto fail;
    }
    cJSON *results = cJSON_AddArrayToObject(item, "results");
    if(results == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resultsListEntry;
    if (cloud_notification_list->results) {
    list_ForEach(resultsListEntry, cloud_notification_list->results) {
    cJSON *itemLocal = cloud_notification_item_convertToJSON(resultsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(results, itemLocal);
    }
    }


    // cloud_notification_list->count
    if (!cloud_notification_list->count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "count", cloud_notification_list->count) == NULL) {
    goto fail; //Numeric
    }


    // cloud_notification_list->total
    if (!cloud_notification_list->total) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "total", cloud_notification_list->total) == NULL) {
    goto fail; //Numeric
    }


    // cloud_notification_list->limit
    if (!cloud_notification_list->limit) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "limit", cloud_notification_list->limit) == NULL) {
    goto fail; //Numeric
    }


    // cloud_notification_list->offset
    if (!cloud_notification_list->offset) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "offset", cloud_notification_list->offset) == NULL) {
    goto fail; //Numeric
    }


    // cloud_notification_list->has_more
    if (!cloud_notification_list->has_more) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "hasMore", cloud_notification_list->has_more) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

cloud_notification_list_t *cloud_notification_list_parseFromJSON(cJSON *cloud_notification_listJSON){

    cloud_notification_list_t *cloud_notification_list_local_var = NULL;

    // define the local list for cloud_notification_list->results
    list_t *resultsList = NULL;

    // cloud_notification_list->results
    cJSON *results = cJSON_GetObjectItemCaseSensitive(cloud_notification_listJSON, "results");
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
        cloud_notification_item_t *resultsItem = cloud_notification_item_parseFromJSON(results_local_nonprimitive);

        list_addElement(resultsList, resultsItem);
    }

    // cloud_notification_list->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(cloud_notification_listJSON, "count");
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

    // cloud_notification_list->total
    cJSON *total = cJSON_GetObjectItemCaseSensitive(cloud_notification_listJSON, "total");
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

    // cloud_notification_list->limit
    cJSON *limit = cJSON_GetObjectItemCaseSensitive(cloud_notification_listJSON, "limit");
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

    // cloud_notification_list->offset
    cJSON *offset = cJSON_GetObjectItemCaseSensitive(cloud_notification_listJSON, "offset");
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

    // cloud_notification_list->has_more
    cJSON *has_more = cJSON_GetObjectItemCaseSensitive(cloud_notification_listJSON, "hasMore");
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


    cloud_notification_list_local_var = cloud_notification_list_create_internal (
        resultsList,
        count->valuedouble,
        total->valuedouble,
        limit->valuedouble,
        offset->valuedouble,
        has_more->valueint
        );

    return cloud_notification_list_local_var;
end:
    if (resultsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resultsList) {
            cloud_notification_item_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resultsList);
        resultsList = NULL;
    }
    return NULL;

}
