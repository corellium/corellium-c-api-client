#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "auth_provider_types_list_response.h"



static auth_provider_types_list_response_t *auth_provider_types_list_response_create_internal(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    auth_provider_types_list_response_t *auth_provider_types_list_response_local_var = malloc(sizeof(auth_provider_types_list_response_t));
    if (!auth_provider_types_list_response_local_var) {
        return NULL;
    }
    auth_provider_types_list_response_local_var->results = results;
    auth_provider_types_list_response_local_var->count = count;
    auth_provider_types_list_response_local_var->total = total;
    auth_provider_types_list_response_local_var->limit = limit;
    auth_provider_types_list_response_local_var->offset = offset;
    auth_provider_types_list_response_local_var->has_more = has_more;

    auth_provider_types_list_response_local_var->_library_owned = 1;
    return auth_provider_types_list_response_local_var;
}

__attribute__((deprecated)) auth_provider_types_list_response_t *auth_provider_types_list_response_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    return auth_provider_types_list_response_create_internal (
        results,
        count,
        total,
        limit,
        offset,
        has_more
        );
}

void auth_provider_types_list_response_free(auth_provider_types_list_response_t *auth_provider_types_list_response) {
    if(NULL == auth_provider_types_list_response){
        return ;
    }
    if(auth_provider_types_list_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "auth_provider_types_list_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (auth_provider_types_list_response->results) {
        list_ForEach(listEntry, auth_provider_types_list_response->results) {
            auth_provider_type_free(listEntry->data);
        }
        list_freeList(auth_provider_types_list_response->results);
        auth_provider_types_list_response->results = NULL;
    }
    free(auth_provider_types_list_response);
}

cJSON *auth_provider_types_list_response_convertToJSON(auth_provider_types_list_response_t *auth_provider_types_list_response) {
    cJSON *item = cJSON_CreateObject();

    // auth_provider_types_list_response->results
    if (!auth_provider_types_list_response->results) {
        goto fail;
    }
    cJSON *results = cJSON_AddArrayToObject(item, "results");
    if(results == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resultsListEntry;
    if (auth_provider_types_list_response->results) {
    list_ForEach(resultsListEntry, auth_provider_types_list_response->results) {
    cJSON *itemLocal = auth_provider_type_convertToJSON(resultsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(results, itemLocal);
    }
    }


    // auth_provider_types_list_response->count
    if (!auth_provider_types_list_response->count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "count", auth_provider_types_list_response->count) == NULL) {
    goto fail; //Numeric
    }


    // auth_provider_types_list_response->total
    if (!auth_provider_types_list_response->total) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "total", auth_provider_types_list_response->total) == NULL) {
    goto fail; //Numeric
    }


    // auth_provider_types_list_response->limit
    if (!auth_provider_types_list_response->limit) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "limit", auth_provider_types_list_response->limit) == NULL) {
    goto fail; //Numeric
    }


    // auth_provider_types_list_response->offset
    if (!auth_provider_types_list_response->offset) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "offset", auth_provider_types_list_response->offset) == NULL) {
    goto fail; //Numeric
    }


    // auth_provider_types_list_response->has_more
    if (!auth_provider_types_list_response->has_more) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "hasMore", auth_provider_types_list_response->has_more) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

auth_provider_types_list_response_t *auth_provider_types_list_response_parseFromJSON(cJSON *auth_provider_types_list_responseJSON){

    auth_provider_types_list_response_t *auth_provider_types_list_response_local_var = NULL;

    // define the local list for auth_provider_types_list_response->results
    list_t *resultsList = NULL;

    // auth_provider_types_list_response->results
    cJSON *results = cJSON_GetObjectItemCaseSensitive(auth_provider_types_list_responseJSON, "results");
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
        auth_provider_type_t *resultsItem = auth_provider_type_parseFromJSON(results_local_nonprimitive);

        list_addElement(resultsList, resultsItem);
    }

    // auth_provider_types_list_response->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(auth_provider_types_list_responseJSON, "count");
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

    // auth_provider_types_list_response->total
    cJSON *total = cJSON_GetObjectItemCaseSensitive(auth_provider_types_list_responseJSON, "total");
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

    // auth_provider_types_list_response->limit
    cJSON *limit = cJSON_GetObjectItemCaseSensitive(auth_provider_types_list_responseJSON, "limit");
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

    // auth_provider_types_list_response->offset
    cJSON *offset = cJSON_GetObjectItemCaseSensitive(auth_provider_types_list_responseJSON, "offset");
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

    // auth_provider_types_list_response->has_more
    cJSON *has_more = cJSON_GetObjectItemCaseSensitive(auth_provider_types_list_responseJSON, "hasMore");
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


    auth_provider_types_list_response_local_var = auth_provider_types_list_response_create_internal (
        resultsList,
        count->valuedouble,
        total->valuedouble,
        limit->valuedouble,
        offset->valuedouble,
        has_more->valueint
        );

    return auth_provider_types_list_response_local_var;
end:
    if (resultsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resultsList) {
            auth_provider_type_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resultsList);
        resultsList = NULL;
    }
    return NULL;

}
