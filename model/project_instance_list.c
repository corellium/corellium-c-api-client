#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "project_instance_list.h"



static project_instance_list_t *project_instance_list_create_internal(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    project_instance_list_t *project_instance_list_local_var = malloc(sizeof(project_instance_list_t));
    if (!project_instance_list_local_var) {
        return NULL;
    }
    project_instance_list_local_var->results = results;
    project_instance_list_local_var->count = count;
    project_instance_list_local_var->total = total;
    project_instance_list_local_var->limit = limit;
    project_instance_list_local_var->offset = offset;
    project_instance_list_local_var->has_more = has_more;

    project_instance_list_local_var->_library_owned = 1;
    return project_instance_list_local_var;
}

__attribute__((deprecated)) project_instance_list_t *project_instance_list_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
    ) {
    return project_instance_list_create_internal (
        results,
        count,
        total,
        limit,
        offset,
        has_more
        );
}

void project_instance_list_free(project_instance_list_t *project_instance_list) {
    if(NULL == project_instance_list){
        return ;
    }
    if(project_instance_list->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "project_instance_list_free");
        return ;
    }
    listEntry_t *listEntry;
    if (project_instance_list->results) {
        list_ForEach(listEntry, project_instance_list->results) {
            project_instance_summary_free(listEntry->data);
        }
        list_freeList(project_instance_list->results);
        project_instance_list->results = NULL;
    }
    free(project_instance_list);
}

cJSON *project_instance_list_convertToJSON(project_instance_list_t *project_instance_list) {
    cJSON *item = cJSON_CreateObject();

    // project_instance_list->results
    if (!project_instance_list->results) {
        goto fail;
    }
    cJSON *results = cJSON_AddArrayToObject(item, "results");
    if(results == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resultsListEntry;
    if (project_instance_list->results) {
    list_ForEach(resultsListEntry, project_instance_list->results) {
    cJSON *itemLocal = project_instance_summary_convertToJSON(resultsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(results, itemLocal);
    }
    }


    // project_instance_list->count
    if (!project_instance_list->count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "count", project_instance_list->count) == NULL) {
    goto fail; //Numeric
    }


    // project_instance_list->total
    if (!project_instance_list->total) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "total", project_instance_list->total) == NULL) {
    goto fail; //Numeric
    }


    // project_instance_list->limit
    if (!project_instance_list->limit) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "limit", project_instance_list->limit) == NULL) {
    goto fail; //Numeric
    }


    // project_instance_list->offset
    if (!project_instance_list->offset) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "offset", project_instance_list->offset) == NULL) {
    goto fail; //Numeric
    }


    // project_instance_list->has_more
    if (!project_instance_list->has_more) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "hasMore", project_instance_list->has_more) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

project_instance_list_t *project_instance_list_parseFromJSON(cJSON *project_instance_listJSON){

    project_instance_list_t *project_instance_list_local_var = NULL;

    // define the local list for project_instance_list->results
    list_t *resultsList = NULL;

    // project_instance_list->results
    cJSON *results = cJSON_GetObjectItemCaseSensitive(project_instance_listJSON, "results");
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
        project_instance_summary_t *resultsItem = project_instance_summary_parseFromJSON(results_local_nonprimitive);

        list_addElement(resultsList, resultsItem);
    }

    // project_instance_list->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(project_instance_listJSON, "count");
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

    // project_instance_list->total
    cJSON *total = cJSON_GetObjectItemCaseSensitive(project_instance_listJSON, "total");
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

    // project_instance_list->limit
    cJSON *limit = cJSON_GetObjectItemCaseSensitive(project_instance_listJSON, "limit");
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

    // project_instance_list->offset
    cJSON *offset = cJSON_GetObjectItemCaseSensitive(project_instance_listJSON, "offset");
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

    // project_instance_list->has_more
    cJSON *has_more = cJSON_GetObjectItemCaseSensitive(project_instance_listJSON, "hasMore");
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


    project_instance_list_local_var = project_instance_list_create_internal (
        resultsList,
        count->valuedouble,
        total->valuedouble,
        limit->valuedouble,
        offset->valuedouble,
        has_more->valueint
        );

    return project_instance_list_local_var;
end:
    if (resultsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resultsList) {
            project_instance_summary_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resultsList);
        resultsList = NULL;
    }
    return NULL;

}
