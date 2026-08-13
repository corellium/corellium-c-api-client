#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "invites_list_response.h"



static invites_list_response_t *invites_list_response_create_internal(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    invites_list_response_t *invites_list_response_local_var = malloc(sizeof(invites_list_response_t));
    if (!invites_list_response_local_var) {
        return NULL;
    }
    invites_list_response_local_var->results = results;
    invites_list_response_local_var->count = count;
    invites_list_response_local_var->total = total;
    invites_list_response_local_var->limit = limit;
    invites_list_response_local_var->offset = offset;
    invites_list_response_local_var->has_more = has_more;

    invites_list_response_local_var->_library_owned = 1;
    return invites_list_response_local_var;
}

__attribute__((deprecated)) invites_list_response_t *invites_list_response_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    return invites_list_response_create_internal (
        results,
        count,
        total,
        limit,
        offset,
        has_more
        );
}

void invites_list_response_free(invites_list_response_t *invites_list_response) {
    if(NULL == invites_list_response){
        return ;
    }
    if(invites_list_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "invites_list_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (invites_list_response->results) {
        list_ForEach(listEntry, invites_list_response->results) {
            invitation_free(listEntry->data);
        }
        list_freeList(invites_list_response->results);
        invites_list_response->results = NULL;
    }
    free(invites_list_response);
}

cJSON *invites_list_response_convertToJSON(invites_list_response_t *invites_list_response) {
    cJSON *item = cJSON_CreateObject();

    // invites_list_response->results
    if (!invites_list_response->results) {
        goto fail;
    }
    cJSON *results = cJSON_AddArrayToObject(item, "results");
    if(results == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resultsListEntry;
    if (invites_list_response->results) {
    list_ForEach(resultsListEntry, invites_list_response->results) {
    cJSON *itemLocal = invitation_convertToJSON(resultsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(results, itemLocal);
    }
    }


    // invites_list_response->count
    if (!invites_list_response->count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "count", invites_list_response->count) == NULL) {
    goto fail; //Numeric
    }


    // invites_list_response->total
    if (!invites_list_response->total) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "total", invites_list_response->total) == NULL) {
    goto fail; //Numeric
    }


    // invites_list_response->limit
    if (!invites_list_response->limit) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "limit", invites_list_response->limit) == NULL) {
    goto fail; //Numeric
    }


    // invites_list_response->offset
    if (!invites_list_response->offset) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "offset", invites_list_response->offset) == NULL) {
    goto fail; //Numeric
    }


    // invites_list_response->has_more
    if (!invites_list_response->has_more) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "hasMore", invites_list_response->has_more) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

invites_list_response_t *invites_list_response_parseFromJSON(cJSON *invites_list_responseJSON){

    invites_list_response_t *invites_list_response_local_var = NULL;

    // define the local list for invites_list_response->results
    list_t *resultsList = NULL;

    // invites_list_response->results
    cJSON *results = cJSON_GetObjectItemCaseSensitive(invites_list_responseJSON, "results");
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
        invitation_t *resultsItem = invitation_parseFromJSON(results_local_nonprimitive);

        list_addElement(resultsList, resultsItem);
    }

    // invites_list_response->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(invites_list_responseJSON, "count");
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

    // invites_list_response->total
    cJSON *total = cJSON_GetObjectItemCaseSensitive(invites_list_responseJSON, "total");
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

    // invites_list_response->limit
    cJSON *limit = cJSON_GetObjectItemCaseSensitive(invites_list_responseJSON, "limit");
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

    // invites_list_response->offset
    cJSON *offset = cJSON_GetObjectItemCaseSensitive(invites_list_responseJSON, "offset");
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

    // invites_list_response->has_more
    cJSON *has_more = cJSON_GetObjectItemCaseSensitive(invites_list_responseJSON, "hasMore");
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


    invites_list_response_local_var = invites_list_response_create_internal (
        resultsList,
        count->valuedouble,
        total->valuedouble,
        limit->valuedouble,
        offset->valuedouble,
        has_more->valueint
        );

    return invites_list_response_local_var;
end:
    if (resultsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resultsList) {
            invitation_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resultsList);
        resultsList = NULL;
    }
    return NULL;

}
