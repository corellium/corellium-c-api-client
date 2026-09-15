#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "domain_software_list.h"



static domain_software_list_t *domain_software_list_create_internal(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    domain_software_list_t *domain_software_list_local_var = malloc(sizeof(domain_software_list_t));
    if (!domain_software_list_local_var) {
        return NULL;
    }
    domain_software_list_local_var->results = results;
    domain_software_list_local_var->count = count;
    domain_software_list_local_var->total = total;
    domain_software_list_local_var->limit = limit;
    domain_software_list_local_var->offset = offset;
    domain_software_list_local_var->has_more = has_more;

    domain_software_list_local_var->_library_owned = 1;
    return domain_software_list_local_var;
}

__attribute__((deprecated)) domain_software_list_t *domain_software_list_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    return domain_software_list_create_internal (
        results,
        count,
        total,
        limit,
        offset,
        has_more
        );
}

void domain_software_list_free(domain_software_list_t *domain_software_list) {
    if(NULL == domain_software_list){
        return ;
    }
    if(domain_software_list->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "domain_software_list_free");
        return ;
    }
    listEntry_t *listEntry;
    if (domain_software_list->results) {
        list_ForEach(listEntry, domain_software_list->results) {
            domain_software_free(listEntry->data);
        }
        list_freeList(domain_software_list->results);
        domain_software_list->results = NULL;
    }
    free(domain_software_list);
}

cJSON *domain_software_list_convertToJSON(domain_software_list_t *domain_software_list) {
    cJSON *item = cJSON_CreateObject();

    // domain_software_list->results
    if (!domain_software_list->results) {
        goto fail;
    }
    cJSON *results = cJSON_AddArrayToObject(item, "results");
    if(results == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resultsListEntry;
    if (domain_software_list->results) {
    list_ForEach(resultsListEntry, domain_software_list->results) {
    cJSON *itemLocal = domain_software_convertToJSON(resultsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(results, itemLocal);
    }
    }


    // domain_software_list->count
    if (!domain_software_list->count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "count", domain_software_list->count) == NULL) {
    goto fail; //Numeric
    }


    // domain_software_list->total
    if (!domain_software_list->total) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "total", domain_software_list->total) == NULL) {
    goto fail; //Numeric
    }


    // domain_software_list->limit
    if (!domain_software_list->limit) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "limit", domain_software_list->limit) == NULL) {
    goto fail; //Numeric
    }


    // domain_software_list->offset
    if (!domain_software_list->offset) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "offset", domain_software_list->offset) == NULL) {
    goto fail; //Numeric
    }


    // domain_software_list->has_more
    if (!domain_software_list->has_more) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "hasMore", domain_software_list->has_more) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

domain_software_list_t *domain_software_list_parseFromJSON(cJSON *domain_software_listJSON){

    domain_software_list_t *domain_software_list_local_var = NULL;

    // define the local list for domain_software_list->results
    list_t *resultsList = NULL;

    // domain_software_list->results
    cJSON *results = cJSON_GetObjectItemCaseSensitive(domain_software_listJSON, "results");
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
        domain_software_t *resultsItem = domain_software_parseFromJSON(results_local_nonprimitive);

        list_addElement(resultsList, resultsItem);
    }

    // domain_software_list->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(domain_software_listJSON, "count");
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

    // domain_software_list->total
    cJSON *total = cJSON_GetObjectItemCaseSensitive(domain_software_listJSON, "total");
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

    // domain_software_list->limit
    cJSON *limit = cJSON_GetObjectItemCaseSensitive(domain_software_listJSON, "limit");
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

    // domain_software_list->offset
    cJSON *offset = cJSON_GetObjectItemCaseSensitive(domain_software_listJSON, "offset");
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

    // domain_software_list->has_more
    cJSON *has_more = cJSON_GetObjectItemCaseSensitive(domain_software_listJSON, "hasMore");
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


    domain_software_list_local_var = domain_software_list_create_internal (
        resultsList,
        count->valuedouble,
        total->valuedouble,
        limit->valuedouble,
        offset->valuedouble,
        has_more->valueint
        );

    return domain_software_list_local_var;
end:
    if (resultsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resultsList) {
            domain_software_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resultsList);
        resultsList = NULL;
    }
    return NULL;

}
