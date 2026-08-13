#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "web_player_session_list_response.h"



static web_player_session_list_response_t *web_player_session_list_response_create_internal(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    web_player_session_list_response_t *web_player_session_list_response_local_var = malloc(sizeof(web_player_session_list_response_t));
    if (!web_player_session_list_response_local_var) {
        return NULL;
    }
    web_player_session_list_response_local_var->results = results;
    web_player_session_list_response_local_var->count = count;
    web_player_session_list_response_local_var->total = total;
    web_player_session_list_response_local_var->limit = limit;
    web_player_session_list_response_local_var->offset = offset;
    web_player_session_list_response_local_var->has_more = has_more;

    web_player_session_list_response_local_var->_library_owned = 1;
    return web_player_session_list_response_local_var;
}

__attribute__((deprecated)) web_player_session_list_response_t *web_player_session_list_response_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    return web_player_session_list_response_create_internal (
        results,
        count,
        total,
        limit,
        offset,
        has_more
        );
}

void web_player_session_list_response_free(web_player_session_list_response_t *web_player_session_list_response) {
    if(NULL == web_player_session_list_response){
        return ;
    }
    if(web_player_session_list_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "web_player_session_list_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (web_player_session_list_response->results) {
        list_ForEach(listEntry, web_player_session_list_response->results) {
            web_player_session_free(listEntry->data);
        }
        list_freeList(web_player_session_list_response->results);
        web_player_session_list_response->results = NULL;
    }
    free(web_player_session_list_response);
}

cJSON *web_player_session_list_response_convertToJSON(web_player_session_list_response_t *web_player_session_list_response) {
    cJSON *item = cJSON_CreateObject();

    // web_player_session_list_response->results
    if (!web_player_session_list_response->results) {
        goto fail;
    }
    cJSON *results = cJSON_AddArrayToObject(item, "results");
    if(results == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resultsListEntry;
    if (web_player_session_list_response->results) {
    list_ForEach(resultsListEntry, web_player_session_list_response->results) {
    cJSON *itemLocal = web_player_session_convertToJSON(resultsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(results, itemLocal);
    }
    }


    // web_player_session_list_response->count
    if (!web_player_session_list_response->count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "count", web_player_session_list_response->count) == NULL) {
    goto fail; //Numeric
    }


    // web_player_session_list_response->total
    if (!web_player_session_list_response->total) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "total", web_player_session_list_response->total) == NULL) {
    goto fail; //Numeric
    }


    // web_player_session_list_response->limit
    if (!web_player_session_list_response->limit) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "limit", web_player_session_list_response->limit) == NULL) {
    goto fail; //Numeric
    }


    // web_player_session_list_response->offset
    if (!web_player_session_list_response->offset) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "offset", web_player_session_list_response->offset) == NULL) {
    goto fail; //Numeric
    }


    // web_player_session_list_response->has_more
    if (!web_player_session_list_response->has_more) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "hasMore", web_player_session_list_response->has_more) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

web_player_session_list_response_t *web_player_session_list_response_parseFromJSON(cJSON *web_player_session_list_responseJSON){

    web_player_session_list_response_t *web_player_session_list_response_local_var = NULL;

    // define the local list for web_player_session_list_response->results
    list_t *resultsList = NULL;

    // web_player_session_list_response->results
    cJSON *results = cJSON_GetObjectItemCaseSensitive(web_player_session_list_responseJSON, "results");
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
        web_player_session_t *resultsItem = web_player_session_parseFromJSON(results_local_nonprimitive);

        list_addElement(resultsList, resultsItem);
    }

    // web_player_session_list_response->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(web_player_session_list_responseJSON, "count");
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

    // web_player_session_list_response->total
    cJSON *total = cJSON_GetObjectItemCaseSensitive(web_player_session_list_responseJSON, "total");
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

    // web_player_session_list_response->limit
    cJSON *limit = cJSON_GetObjectItemCaseSensitive(web_player_session_list_responseJSON, "limit");
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

    // web_player_session_list_response->offset
    cJSON *offset = cJSON_GetObjectItemCaseSensitive(web_player_session_list_responseJSON, "offset");
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

    // web_player_session_list_response->has_more
    cJSON *has_more = cJSON_GetObjectItemCaseSensitive(web_player_session_list_responseJSON, "hasMore");
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


    web_player_session_list_response_local_var = web_player_session_list_response_create_internal (
        resultsList,
        count->valuedouble,
        total->valuedouble,
        limit->valuedouble,
        offset->valuedouble,
        has_more->valueint
        );

    return web_player_session_list_response_local_var;
end:
    if (resultsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resultsList) {
            web_player_session_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resultsList);
        resultsList = NULL;
    }
    return NULL;

}
