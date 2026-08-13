#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "activity_download.h"



static activity_download_t *activity_download_create_internal(
    list_t *data,
    activity_query_options_t *filters
    ) {
    activity_download_t *activity_download_local_var = malloc(sizeof(activity_download_t));
    if (!activity_download_local_var) {
        return NULL;
    }
    activity_download_local_var->data = data;
    activity_download_local_var->filters = filters;

    activity_download_local_var->_library_owned = 1;
    return activity_download_local_var;
}

__attribute__((deprecated)) activity_download_t *activity_download_create(
    list_t *data,
    activity_query_options_t *filters
    ) {
    return activity_download_create_internal (
        data,
        filters
        );
}

void activity_download_free(activity_download_t *activity_download) {
    if(NULL == activity_download){
        return ;
    }
    if(activity_download->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "activity_download_free");
        return ;
    }
    listEntry_t *listEntry;
    if (activity_download->data) {
        list_ForEach(listEntry, activity_download->data) {
            activity_free(listEntry->data);
        }
        list_freeList(activity_download->data);
        activity_download->data = NULL;
    }
    if (activity_download->filters) {
        activity_query_options_free(activity_download->filters);
        activity_download->filters = NULL;
    }
    free(activity_download);
}

cJSON *activity_download_convertToJSON(activity_download_t *activity_download) {
    cJSON *item = cJSON_CreateObject();

    // activity_download->data
    if (!activity_download->data) {
        goto fail;
    }
    cJSON *data = cJSON_AddArrayToObject(item, "data");
    if(data == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *dataListEntry;
    if (activity_download->data) {
    list_ForEach(dataListEntry, activity_download->data) {
    cJSON *itemLocal = activity_convertToJSON(dataListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(data, itemLocal);
    }
    }


    // activity_download->filters
    if (!activity_download->filters) {
        goto fail;
    }
    cJSON *filters_local_JSON = activity_query_options_convertToJSON(activity_download->filters);
    if(filters_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "filters", filters_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

activity_download_t *activity_download_parseFromJSON(cJSON *activity_downloadJSON){

    activity_download_t *activity_download_local_var = NULL;

    // define the local list for activity_download->data
    list_t *dataList = NULL;

    // define the local variable for activity_download->filters
    activity_query_options_t *filters_local_nonprim = NULL;

    // activity_download->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(activity_downloadJSON, "data");
    if (cJSON_IsNull(data)) {
        data = NULL;
    }
    if (!data) {
        goto end;
    }

    
    cJSON *data_local_nonprimitive = NULL;
    if(!cJSON_IsArray(data)){
        goto end; //nonprimitive container
    }

    dataList = list_createList();

    cJSON_ArrayForEach(data_local_nonprimitive,data )
    {
        if(!cJSON_IsObject(data_local_nonprimitive)){
            goto end;
        }
        activity_t *dataItem = activity_parseFromJSON(data_local_nonprimitive);

        list_addElement(dataList, dataItem);
    }

    // activity_download->filters
    cJSON *filters = cJSON_GetObjectItemCaseSensitive(activity_downloadJSON, "filters");
    if (cJSON_IsNull(filters)) {
        filters = NULL;
    }
    if (!filters) {
        goto end;
    }

    
    filters_local_nonprim = activity_query_options_parseFromJSON(filters); //nonprimitive


    activity_download_local_var = activity_download_create_internal (
        dataList,
        filters_local_nonprim
        );

    return activity_download_local_var;
end:
    if (dataList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, dataList) {
            activity_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(dataList);
        dataList = NULL;
    }
    if (filters_local_nonprim) {
        activity_query_options_free(filters_local_nonprim);
        filters_local_nonprim = NULL;
    }
    return NULL;

}
