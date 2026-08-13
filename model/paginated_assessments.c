#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "paginated_assessments.h"



static paginated_assessments_t *paginated_assessments_create_internal(
    double limit,
    double offset,
    double count,
    double total,
    list_t *results
    ) {
    paginated_assessments_t *paginated_assessments_local_var = malloc(sizeof(paginated_assessments_t));
    if (!paginated_assessments_local_var) {
        return NULL;
    }
    paginated_assessments_local_var->limit = limit;
    paginated_assessments_local_var->offset = offset;
    paginated_assessments_local_var->count = count;
    paginated_assessments_local_var->total = total;
    paginated_assessments_local_var->results = results;

    paginated_assessments_local_var->_library_owned = 1;
    return paginated_assessments_local_var;
}

__attribute__((deprecated)) paginated_assessments_t *paginated_assessments_create(
    double limit,
    double offset,
    double count,
    double total,
    list_t *results
    ) {
    return paginated_assessments_create_internal (
        limit,
        offset,
        count,
        total,
        results
        );
}

void paginated_assessments_free(paginated_assessments_t *paginated_assessments) {
    if(NULL == paginated_assessments){
        return ;
    }
    if(paginated_assessments->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "paginated_assessments_free");
        return ;
    }
    listEntry_t *listEntry;
    if (paginated_assessments->results) {
        list_ForEach(listEntry, paginated_assessments->results) {
            assessment_free(listEntry->data);
        }
        list_freeList(paginated_assessments->results);
        paginated_assessments->results = NULL;
    }
    free(paginated_assessments);
}

cJSON *paginated_assessments_convertToJSON(paginated_assessments_t *paginated_assessments) {
    cJSON *item = cJSON_CreateObject();

    // paginated_assessments->limit
    if (!paginated_assessments->limit) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "limit", paginated_assessments->limit) == NULL) {
    goto fail; //Numeric
    }


    // paginated_assessments->offset
    if (!paginated_assessments->offset) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "offset", paginated_assessments->offset) == NULL) {
    goto fail; //Numeric
    }


    // paginated_assessments->count
    if (!paginated_assessments->count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "count", paginated_assessments->count) == NULL) {
    goto fail; //Numeric
    }


    // paginated_assessments->total
    if (!paginated_assessments->total) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "total", paginated_assessments->total) == NULL) {
    goto fail; //Numeric
    }


    // paginated_assessments->results
    if (!paginated_assessments->results) {
        goto fail;
    }
    cJSON *results = cJSON_AddArrayToObject(item, "results");
    if(results == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resultsListEntry;
    if (paginated_assessments->results) {
    list_ForEach(resultsListEntry, paginated_assessments->results) {
    cJSON *itemLocal = assessment_convertToJSON(resultsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(results, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

paginated_assessments_t *paginated_assessments_parseFromJSON(cJSON *paginated_assessmentsJSON){

    paginated_assessments_t *paginated_assessments_local_var = NULL;

    // define the local list for paginated_assessments->results
    list_t *resultsList = NULL;

    // paginated_assessments->limit
    cJSON *limit = cJSON_GetObjectItemCaseSensitive(paginated_assessmentsJSON, "limit");
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

    // paginated_assessments->offset
    cJSON *offset = cJSON_GetObjectItemCaseSensitive(paginated_assessmentsJSON, "offset");
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

    // paginated_assessments->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(paginated_assessmentsJSON, "count");
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

    // paginated_assessments->total
    cJSON *total = cJSON_GetObjectItemCaseSensitive(paginated_assessmentsJSON, "total");
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

    // paginated_assessments->results
    cJSON *results = cJSON_GetObjectItemCaseSensitive(paginated_assessmentsJSON, "results");
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
        assessment_t *resultsItem = assessment_parseFromJSON(results_local_nonprimitive);

        list_addElement(resultsList, resultsItem);
    }


    paginated_assessments_local_var = paginated_assessments_create_internal (
        limit->valuedouble,
        offset->valuedouble,
        count->valuedouble,
        total->valuedouble,
        resultsList
        );

    return paginated_assessments_local_var;
end:
    if (resultsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resultsList) {
            assessment_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resultsList);
        resultsList = NULL;
    }
    return NULL;

}
