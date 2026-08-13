#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_interconnects_response_schema.h"



static get_interconnects_response_schema_t *get_interconnects_response_schema_create_internal(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    get_interconnects_response_schema_t *get_interconnects_response_schema_local_var = malloc(sizeof(get_interconnects_response_schema_t));
    if (!get_interconnects_response_schema_local_var) {
        return NULL;
    }
    get_interconnects_response_schema_local_var->results = results;
    get_interconnects_response_schema_local_var->count = count;
    get_interconnects_response_schema_local_var->total = total;
    get_interconnects_response_schema_local_var->limit = limit;
    get_interconnects_response_schema_local_var->offset = offset;
    get_interconnects_response_schema_local_var->has_more = has_more;

    get_interconnects_response_schema_local_var->_library_owned = 1;
    return get_interconnects_response_schema_local_var;
}

__attribute__((deprecated)) get_interconnects_response_schema_t *get_interconnects_response_schema_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    return get_interconnects_response_schema_create_internal (
        results,
        count,
        total,
        limit,
        offset,
        has_more
        );
}

void get_interconnects_response_schema_free(get_interconnects_response_schema_t *get_interconnects_response_schema) {
    if(NULL == get_interconnects_response_schema){
        return ;
    }
    if(get_interconnects_response_schema->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "get_interconnects_response_schema_free");
        return ;
    }
    listEntry_t *listEntry;
    if (get_interconnects_response_schema->results) {
        list_ForEach(listEntry, get_interconnects_response_schema->results) {
            get_interconnect_response_schema_free(listEntry->data);
        }
        list_freeList(get_interconnects_response_schema->results);
        get_interconnects_response_schema->results = NULL;
    }
    free(get_interconnects_response_schema);
}

cJSON *get_interconnects_response_schema_convertToJSON(get_interconnects_response_schema_t *get_interconnects_response_schema) {
    cJSON *item = cJSON_CreateObject();

    // get_interconnects_response_schema->results
    if (!get_interconnects_response_schema->results) {
        goto fail;
    }
    cJSON *results = cJSON_AddArrayToObject(item, "results");
    if(results == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resultsListEntry;
    if (get_interconnects_response_schema->results) {
    list_ForEach(resultsListEntry, get_interconnects_response_schema->results) {
    cJSON *itemLocal = get_interconnect_response_schema_convertToJSON(resultsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(results, itemLocal);
    }
    }


    // get_interconnects_response_schema->count
    if (!get_interconnects_response_schema->count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "count", get_interconnects_response_schema->count) == NULL) {
    goto fail; //Numeric
    }


    // get_interconnects_response_schema->total
    if (!get_interconnects_response_schema->total) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "total", get_interconnects_response_schema->total) == NULL) {
    goto fail; //Numeric
    }


    // get_interconnects_response_schema->limit
    if (!get_interconnects_response_schema->limit) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "limit", get_interconnects_response_schema->limit) == NULL) {
    goto fail; //Numeric
    }


    // get_interconnects_response_schema->offset
    if (!get_interconnects_response_schema->offset) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "offset", get_interconnects_response_schema->offset) == NULL) {
    goto fail; //Numeric
    }


    // get_interconnects_response_schema->has_more
    if (!get_interconnects_response_schema->has_more) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "hasMore", get_interconnects_response_schema->has_more) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

get_interconnects_response_schema_t *get_interconnects_response_schema_parseFromJSON(cJSON *get_interconnects_response_schemaJSON){

    get_interconnects_response_schema_t *get_interconnects_response_schema_local_var = NULL;

    // define the local list for get_interconnects_response_schema->results
    list_t *resultsList = NULL;

    // get_interconnects_response_schema->results
    cJSON *results = cJSON_GetObjectItemCaseSensitive(get_interconnects_response_schemaJSON, "results");
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
        get_interconnect_response_schema_t *resultsItem = get_interconnect_response_schema_parseFromJSON(results_local_nonprimitive);

        list_addElement(resultsList, resultsItem);
    }

    // get_interconnects_response_schema->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(get_interconnects_response_schemaJSON, "count");
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

    // get_interconnects_response_schema->total
    cJSON *total = cJSON_GetObjectItemCaseSensitive(get_interconnects_response_schemaJSON, "total");
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

    // get_interconnects_response_schema->limit
    cJSON *limit = cJSON_GetObjectItemCaseSensitive(get_interconnects_response_schemaJSON, "limit");
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

    // get_interconnects_response_schema->offset
    cJSON *offset = cJSON_GetObjectItemCaseSensitive(get_interconnects_response_schemaJSON, "offset");
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

    // get_interconnects_response_schema->has_more
    cJSON *has_more = cJSON_GetObjectItemCaseSensitive(get_interconnects_response_schemaJSON, "hasMore");
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


    get_interconnects_response_schema_local_var = get_interconnects_response_schema_create_internal (
        resultsList,
        count->valuedouble,
        total->valuedouble,
        limit->valuedouble,
        offset->valuedouble,
        has_more->valueint
        );

    return get_interconnects_response_schema_local_var;
end:
    if (resultsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resultsList) {
            get_interconnect_response_schema_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resultsList);
        resultsList = NULL;
    }
    return NULL;

}
