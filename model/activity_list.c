#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "activity_list.h"



static activity_list_t *activity_list_create_internal(
    list_t *data,
    pagination_t *pagination
    ) {
    activity_list_t *activity_list_local_var = malloc(sizeof(activity_list_t));
    if (!activity_list_local_var) {
        return NULL;
    }
    activity_list_local_var->data = data;
    activity_list_local_var->pagination = pagination;

    activity_list_local_var->_library_owned = 1;
    return activity_list_local_var;
}

__attribute__((deprecated)) activity_list_t *activity_list_create(
    list_t *data,
    pagination_t *pagination
    ) {
    return activity_list_create_internal (
        data,
        pagination
        );
}

void activity_list_free(activity_list_t *activity_list) {
    if(NULL == activity_list){
        return ;
    }
    if(activity_list->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "activity_list_free");
        return ;
    }
    listEntry_t *listEntry;
    if (activity_list->data) {
        list_ForEach(listEntry, activity_list->data) {
            activity_v1_free(listEntry->data);
        }
        list_freeList(activity_list->data);
        activity_list->data = NULL;
    }
    if (activity_list->pagination) {
        pagination_free(activity_list->pagination);
        activity_list->pagination = NULL;
    }
    free(activity_list);
}

cJSON *activity_list_convertToJSON(activity_list_t *activity_list) {
    cJSON *item = cJSON_CreateObject();

    // activity_list->data
    if(activity_list->data) {
    cJSON *data = cJSON_AddArrayToObject(item, "data");
    if(data == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *dataListEntry;
    if (activity_list->data) {
    list_ForEach(dataListEntry, activity_list->data) {
    cJSON *itemLocal = activity_v1_convertToJSON(dataListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(data, itemLocal);
    }
    }
    }


    // activity_list->pagination
    if(activity_list->pagination) {
    cJSON *pagination_local_JSON = pagination_convertToJSON(activity_list->pagination);
    if(pagination_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "pagination", pagination_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

activity_list_t *activity_list_parseFromJSON(cJSON *activity_listJSON){

    activity_list_t *activity_list_local_var = NULL;

    // define the local list for activity_list->data
    list_t *dataList = NULL;

    // define the local variable for activity_list->pagination
    pagination_t *pagination_local_nonprim = NULL;

    // activity_list->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(activity_listJSON, "data");
    if (cJSON_IsNull(data)) {
        data = NULL;
    }
    if (data) { 
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
        activity_v1_t *dataItem = activity_v1_parseFromJSON(data_local_nonprimitive);

        list_addElement(dataList, dataItem);
    }
    }

    // activity_list->pagination
    cJSON *pagination = cJSON_GetObjectItemCaseSensitive(activity_listJSON, "pagination");
    if (cJSON_IsNull(pagination)) {
        pagination = NULL;
    }
    if (pagination) { 
    pagination_local_nonprim = pagination_parseFromJSON(pagination); //nonprimitive
    }


    activity_list_local_var = activity_list_create_internal (
        data ? dataList : NULL,
        pagination ? pagination_local_nonprim : NULL
        );

    return activity_list_local_var;
end:
    if (dataList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, dataList) {
            activity_v1_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(dataList);
        dataList = NULL;
    }
    if (pagination_local_nonprim) {
        pagination_free(pagination_local_nonprim);
        pagination_local_nonprim = NULL;
    }
    return NULL;

}
