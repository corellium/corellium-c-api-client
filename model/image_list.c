#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "image_list.h"



static image_list_t *image_list_create_internal(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    image_list_t *image_list_local_var = malloc(sizeof(image_list_t));
    if (!image_list_local_var) {
        return NULL;
    }
    image_list_local_var->results = results;
    image_list_local_var->count = count;
    image_list_local_var->total = total;
    image_list_local_var->limit = limit;
    image_list_local_var->offset = offset;
    image_list_local_var->has_more = has_more;

    image_list_local_var->_library_owned = 1;
    return image_list_local_var;
}

__attribute__((deprecated)) image_list_t *image_list_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    return image_list_create_internal (
        results,
        count,
        total,
        limit,
        offset,
        has_more
        );
}

void image_list_free(image_list_t *image_list) {
    if(NULL == image_list){
        return ;
    }
    if(image_list->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "image_list_free");
        return ;
    }
    listEntry_t *listEntry;
    if (image_list->results) {
        list_ForEach(listEntry, image_list->results) {
            image_free(listEntry->data);
        }
        list_freeList(image_list->results);
        image_list->results = NULL;
    }
    free(image_list);
}

cJSON *image_list_convertToJSON(image_list_t *image_list) {
    cJSON *item = cJSON_CreateObject();

    // image_list->results
    if (!image_list->results) {
        goto fail;
    }
    cJSON *results = cJSON_AddArrayToObject(item, "results");
    if(results == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resultsListEntry;
    if (image_list->results) {
    list_ForEach(resultsListEntry, image_list->results) {
    cJSON *itemLocal = image_convertToJSON(resultsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(results, itemLocal);
    }
    }


    // image_list->count
    if (!image_list->count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "count", image_list->count) == NULL) {
    goto fail; //Numeric
    }


    // image_list->total
    if (!image_list->total) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "total", image_list->total) == NULL) {
    goto fail; //Numeric
    }


    // image_list->limit
    if (!image_list->limit) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "limit", image_list->limit) == NULL) {
    goto fail; //Numeric
    }


    // image_list->offset
    if (!image_list->offset) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "offset", image_list->offset) == NULL) {
    goto fail; //Numeric
    }


    // image_list->has_more
    if (!image_list->has_more) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "hasMore", image_list->has_more) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

image_list_t *image_list_parseFromJSON(cJSON *image_listJSON){

    image_list_t *image_list_local_var = NULL;

    // define the local list for image_list->results
    list_t *resultsList = NULL;

    // image_list->results
    cJSON *results = cJSON_GetObjectItemCaseSensitive(image_listJSON, "results");
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
        image_t *resultsItem = image_parseFromJSON(results_local_nonprimitive);

        list_addElement(resultsList, resultsItem);
    }

    // image_list->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(image_listJSON, "count");
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

    // image_list->total
    cJSON *total = cJSON_GetObjectItemCaseSensitive(image_listJSON, "total");
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

    // image_list->limit
    cJSON *limit = cJSON_GetObjectItemCaseSensitive(image_listJSON, "limit");
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

    // image_list->offset
    cJSON *offset = cJSON_GetObjectItemCaseSensitive(image_listJSON, "offset");
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

    // image_list->has_more
    cJSON *has_more = cJSON_GetObjectItemCaseSensitive(image_listJSON, "hasMore");
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


    image_list_local_var = image_list_create_internal (
        resultsList,
        count->valuedouble,
        total->valuedouble,
        limit->valuedouble,
        offset->valuedouble,
        has_more->valueint
        );

    return image_list_local_var;
end:
    if (resultsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resultsList) {
            image_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resultsList);
        resultsList = NULL;
    }
    return NULL;

}
