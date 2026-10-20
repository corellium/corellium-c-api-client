#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "extension_list.h"



static extension_list_t *extension_list_create_internal(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    extension_list_t *extension_list_local_var = malloc(sizeof(extension_list_t));
    if (!extension_list_local_var) {
        return NULL;
    }
    extension_list_local_var->results = results;
    extension_list_local_var->count = count;
    extension_list_local_var->total = total;
    extension_list_local_var->limit = limit;
    extension_list_local_var->offset = offset;
    extension_list_local_var->has_more = has_more;

    extension_list_local_var->_library_owned = 1;
    return extension_list_local_var;
}

__attribute__((deprecated)) extension_list_t *extension_list_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    return extension_list_create_internal (
        results,
        count,
        total,
        limit,
        offset,
        has_more
        );
}

void extension_list_free(extension_list_t *extension_list) {
    if(NULL == extension_list){
        return ;
    }
    if(extension_list->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "extension_list_free");
        return ;
    }
    listEntry_t *listEntry;
    if (extension_list->results) {
        list_ForEach(listEntry, extension_list->results) {
            extension_free(listEntry->data);
        }
        list_freeList(extension_list->results);
        extension_list->results = NULL;
    }
    free(extension_list);
}

cJSON *extension_list_convertToJSON(extension_list_t *extension_list) {
    cJSON *item = cJSON_CreateObject();

    // extension_list->results
    if (!extension_list->results) {
        goto fail;
    }
    cJSON *results = cJSON_AddArrayToObject(item, "results");
    if(results == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resultsListEntry;
    if (extension_list->results) {
    list_ForEach(resultsListEntry, extension_list->results) {
    cJSON *itemLocal = extension_convertToJSON(resultsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(results, itemLocal);
    }
    }


    // extension_list->count
    if (!extension_list->count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "count", extension_list->count) == NULL) {
    goto fail; //Numeric
    }


    // extension_list->total
    if (!extension_list->total) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "total", extension_list->total) == NULL) {
    goto fail; //Numeric
    }


    // extension_list->limit
    if (!extension_list->limit) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "limit", extension_list->limit) == NULL) {
    goto fail; //Numeric
    }


    // extension_list->offset
    if (!extension_list->offset) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "offset", extension_list->offset) == NULL) {
    goto fail; //Numeric
    }


    // extension_list->has_more
    if (!extension_list->has_more) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "hasMore", extension_list->has_more) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

extension_list_t *extension_list_parseFromJSON(cJSON *extension_listJSON){

    extension_list_t *extension_list_local_var = NULL;

    // define the local list for extension_list->results
    list_t *resultsList = NULL;

    // extension_list->results
    cJSON *results = cJSON_GetObjectItemCaseSensitive(extension_listJSON, "results");
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
        extension_t *resultsItem = extension_parseFromJSON(results_local_nonprimitive);

        list_addElement(resultsList, resultsItem);
    }

    // extension_list->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(extension_listJSON, "count");
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

    // extension_list->total
    cJSON *total = cJSON_GetObjectItemCaseSensitive(extension_listJSON, "total");
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

    // extension_list->limit
    cJSON *limit = cJSON_GetObjectItemCaseSensitive(extension_listJSON, "limit");
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

    // extension_list->offset
    cJSON *offset = cJSON_GetObjectItemCaseSensitive(extension_listJSON, "offset");
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

    // extension_list->has_more
    cJSON *has_more = cJSON_GetObjectItemCaseSensitive(extension_listJSON, "hasMore");
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


    extension_list_local_var = extension_list_create_internal (
        resultsList,
        count->valuedouble,
        total->valuedouble,
        limit->valuedouble,
        offset->valuedouble,
        has_more->valueint
        );

    return extension_list_local_var;
end:
    if (resultsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resultsList) {
            extension_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resultsList);
        resultsList = NULL;
    }
    return NULL;

}
