#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "firmware_device_list.h"



static firmware_device_list_t *firmware_device_list_create_internal(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    firmware_device_list_t *firmware_device_list_local_var = malloc(sizeof(firmware_device_list_t));
    if (!firmware_device_list_local_var) {
        return NULL;
    }
    firmware_device_list_local_var->results = results;
    firmware_device_list_local_var->count = count;
    firmware_device_list_local_var->total = total;
    firmware_device_list_local_var->limit = limit;
    firmware_device_list_local_var->offset = offset;
    firmware_device_list_local_var->has_more = has_more;

    firmware_device_list_local_var->_library_owned = 1;
    return firmware_device_list_local_var;
}

__attribute__((deprecated)) firmware_device_list_t *firmware_device_list_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    return firmware_device_list_create_internal (
        results,
        count,
        total,
        limit,
        offset,
        has_more
        );
}

void firmware_device_list_free(firmware_device_list_t *firmware_device_list) {
    if(NULL == firmware_device_list){
        return ;
    }
    if(firmware_device_list->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "firmware_device_list_free");
        return ;
    }
    listEntry_t *listEntry;
    if (firmware_device_list->results) {
        list_ForEach(listEntry, firmware_device_list->results) {
            firmware_device_free(listEntry->data);
        }
        list_freeList(firmware_device_list->results);
        firmware_device_list->results = NULL;
    }
    free(firmware_device_list);
}

cJSON *firmware_device_list_convertToJSON(firmware_device_list_t *firmware_device_list) {
    cJSON *item = cJSON_CreateObject();

    // firmware_device_list->results
    if (!firmware_device_list->results) {
        goto fail;
    }
    cJSON *results = cJSON_AddArrayToObject(item, "results");
    if(results == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resultsListEntry;
    if (firmware_device_list->results) {
    list_ForEach(resultsListEntry, firmware_device_list->results) {
    cJSON *itemLocal = firmware_device_convertToJSON(resultsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(results, itemLocal);
    }
    }


    // firmware_device_list->count
    if (!firmware_device_list->count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "count", firmware_device_list->count) == NULL) {
    goto fail; //Numeric
    }


    // firmware_device_list->total
    if (!firmware_device_list->total) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "total", firmware_device_list->total) == NULL) {
    goto fail; //Numeric
    }


    // firmware_device_list->limit
    if (!firmware_device_list->limit) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "limit", firmware_device_list->limit) == NULL) {
    goto fail; //Numeric
    }


    // firmware_device_list->offset
    if (!firmware_device_list->offset) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "offset", firmware_device_list->offset) == NULL) {
    goto fail; //Numeric
    }


    // firmware_device_list->has_more
    if (!firmware_device_list->has_more) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "hasMore", firmware_device_list->has_more) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

firmware_device_list_t *firmware_device_list_parseFromJSON(cJSON *firmware_device_listJSON){

    firmware_device_list_t *firmware_device_list_local_var = NULL;

    // define the local list for firmware_device_list->results
    list_t *resultsList = NULL;

    // firmware_device_list->results
    cJSON *results = cJSON_GetObjectItemCaseSensitive(firmware_device_listJSON, "results");
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
        firmware_device_t *resultsItem = firmware_device_parseFromJSON(results_local_nonprimitive);

        list_addElement(resultsList, resultsItem);
    }

    // firmware_device_list->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(firmware_device_listJSON, "count");
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

    // firmware_device_list->total
    cJSON *total = cJSON_GetObjectItemCaseSensitive(firmware_device_listJSON, "total");
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

    // firmware_device_list->limit
    cJSON *limit = cJSON_GetObjectItemCaseSensitive(firmware_device_listJSON, "limit");
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

    // firmware_device_list->offset
    cJSON *offset = cJSON_GetObjectItemCaseSensitive(firmware_device_listJSON, "offset");
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

    // firmware_device_list->has_more
    cJSON *has_more = cJSON_GetObjectItemCaseSensitive(firmware_device_listJSON, "hasMore");
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


    firmware_device_list_local_var = firmware_device_list_create_internal (
        resultsList,
        count->valuedouble,
        total->valuedouble,
        limit->valuedouble,
        offset->valuedouble,
        has_more->valueint
        );

    return firmware_device_list_local_var;
end:
    if (resultsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resultsList) {
            firmware_device_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resultsList);
        resultsList = NULL;
    }
    return NULL;

}
