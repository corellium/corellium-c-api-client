#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "roles_list_response.h"



static roles_list_response_t *roles_list_response_create_internal(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    roles_list_response_t *roles_list_response_local_var = malloc(sizeof(roles_list_response_t));
    if (!roles_list_response_local_var) {
        return NULL;
    }
    roles_list_response_local_var->results = results;
    roles_list_response_local_var->count = count;
    roles_list_response_local_var->total = total;
    roles_list_response_local_var->limit = limit;
    roles_list_response_local_var->offset = offset;
    roles_list_response_local_var->has_more = has_more;

    roles_list_response_local_var->_library_owned = 1;
    return roles_list_response_local_var;
}

__attribute__((deprecated)) roles_list_response_t *roles_list_response_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    return roles_list_response_create_internal (
        results,
        count,
        total,
        limit,
        offset,
        has_more
        );
}

void roles_list_response_free(roles_list_response_t *roles_list_response) {
    if(NULL == roles_list_response){
        return ;
    }
    if(roles_list_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "roles_list_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (roles_list_response->results) {
        list_ForEach(listEntry, roles_list_response->results) {
            role_free(listEntry->data);
        }
        list_freeList(roles_list_response->results);
        roles_list_response->results = NULL;
    }
    free(roles_list_response);
}

cJSON *roles_list_response_convertToJSON(roles_list_response_t *roles_list_response) {
    cJSON *item = cJSON_CreateObject();

    // roles_list_response->results
    if (!roles_list_response->results) {
        goto fail;
    }
    cJSON *results = cJSON_AddArrayToObject(item, "results");
    if(results == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resultsListEntry;
    if (roles_list_response->results) {
    list_ForEach(resultsListEntry, roles_list_response->results) {
    cJSON *itemLocal = role_convertToJSON(resultsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(results, itemLocal);
    }
    }


    // roles_list_response->count
    if (!roles_list_response->count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "count", roles_list_response->count) == NULL) {
    goto fail; //Numeric
    }


    // roles_list_response->total
    if (!roles_list_response->total) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "total", roles_list_response->total) == NULL) {
    goto fail; //Numeric
    }


    // roles_list_response->limit
    if (!roles_list_response->limit) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "limit", roles_list_response->limit) == NULL) {
    goto fail; //Numeric
    }


    // roles_list_response->offset
    if (!roles_list_response->offset) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "offset", roles_list_response->offset) == NULL) {
    goto fail; //Numeric
    }


    // roles_list_response->has_more
    if (!roles_list_response->has_more) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "hasMore", roles_list_response->has_more) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

roles_list_response_t *roles_list_response_parseFromJSON(cJSON *roles_list_responseJSON){

    roles_list_response_t *roles_list_response_local_var = NULL;

    // define the local list for roles_list_response->results
    list_t *resultsList = NULL;

    // roles_list_response->results
    cJSON *results = cJSON_GetObjectItemCaseSensitive(roles_list_responseJSON, "results");
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
        role_t *resultsItem = role_parseFromJSON(results_local_nonprimitive);

        list_addElement(resultsList, resultsItem);
    }

    // roles_list_response->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(roles_list_responseJSON, "count");
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

    // roles_list_response->total
    cJSON *total = cJSON_GetObjectItemCaseSensitive(roles_list_responseJSON, "total");
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

    // roles_list_response->limit
    cJSON *limit = cJSON_GetObjectItemCaseSensitive(roles_list_responseJSON, "limit");
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

    // roles_list_response->offset
    cJSON *offset = cJSON_GetObjectItemCaseSensitive(roles_list_responseJSON, "offset");
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

    // roles_list_response->has_more
    cJSON *has_more = cJSON_GetObjectItemCaseSensitive(roles_list_responseJSON, "hasMore");
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


    roles_list_response_local_var = roles_list_response_create_internal (
        resultsList,
        count->valuedouble,
        total->valuedouble,
        limit->valuedouble,
        offset->valuedouble,
        has_more->valueint
        );

    return roles_list_response_local_var;
end:
    if (resultsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resultsList) {
            role_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resultsList);
        resultsList = NULL;
    }
    return NULL;

}
