#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "fetch_firmware_assets_response.h"



static fetch_firmware_assets_response_t *fetch_firmware_assets_response_create_internal(
    list_t *added,
    list_t *existing,
    list_t *failed
    ) {
    fetch_firmware_assets_response_t *fetch_firmware_assets_response_local_var = malloc(sizeof(fetch_firmware_assets_response_t));
    if (!fetch_firmware_assets_response_local_var) {
        return NULL;
    }
    fetch_firmware_assets_response_local_var->added = added;
    fetch_firmware_assets_response_local_var->existing = existing;
    fetch_firmware_assets_response_local_var->failed = failed;

    fetch_firmware_assets_response_local_var->_library_owned = 1;
    return fetch_firmware_assets_response_local_var;
}

__attribute__((deprecated)) fetch_firmware_assets_response_t *fetch_firmware_assets_response_create(
    list_t *added,
    list_t *existing,
    list_t *failed
    ) {
    return fetch_firmware_assets_response_create_internal (
        added,
        existing,
        failed
        );
}

void fetch_firmware_assets_response_free(fetch_firmware_assets_response_t *fetch_firmware_assets_response) {
    if(NULL == fetch_firmware_assets_response){
        return ;
    }
    if(fetch_firmware_assets_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "fetch_firmware_assets_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (fetch_firmware_assets_response->added) {
        list_ForEach(listEntry, fetch_firmware_assets_response->added) {
            free(listEntry->data);
        }
        list_freeList(fetch_firmware_assets_response->added);
        fetch_firmware_assets_response->added = NULL;
    }
    if (fetch_firmware_assets_response->existing) {
        list_ForEach(listEntry, fetch_firmware_assets_response->existing) {
            free(listEntry->data);
        }
        list_freeList(fetch_firmware_assets_response->existing);
        fetch_firmware_assets_response->existing = NULL;
    }
    if (fetch_firmware_assets_response->failed) {
        list_ForEach(listEntry, fetch_firmware_assets_response->failed) {
            fetch_firmware_assets_response_failed_inner_free(listEntry->data);
        }
        list_freeList(fetch_firmware_assets_response->failed);
        fetch_firmware_assets_response->failed = NULL;
    }
    free(fetch_firmware_assets_response);
}

cJSON *fetch_firmware_assets_response_convertToJSON(fetch_firmware_assets_response_t *fetch_firmware_assets_response) {
    cJSON *item = cJSON_CreateObject();

    // fetch_firmware_assets_response->added
    if (!fetch_firmware_assets_response->added) {
        goto fail;
    }
    cJSON *added = cJSON_AddArrayToObject(item, "added");
    if(added == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *addedListEntry;
    list_ForEach(addedListEntry, fetch_firmware_assets_response->added) {
    if(cJSON_AddStringToObject(added, "", addedListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // fetch_firmware_assets_response->existing
    if (!fetch_firmware_assets_response->existing) {
        goto fail;
    }
    cJSON *existing = cJSON_AddArrayToObject(item, "existing");
    if(existing == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *existingListEntry;
    list_ForEach(existingListEntry, fetch_firmware_assets_response->existing) {
    if(cJSON_AddStringToObject(existing, "", existingListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // fetch_firmware_assets_response->failed
    if (!fetch_firmware_assets_response->failed) {
        goto fail;
    }
    cJSON *failed = cJSON_AddArrayToObject(item, "failed");
    if(failed == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *failedListEntry;
    if (fetch_firmware_assets_response->failed) {
    list_ForEach(failedListEntry, fetch_firmware_assets_response->failed) {
    cJSON *itemLocal = fetch_firmware_assets_response_failed_inner_convertToJSON(failedListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(failed, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

fetch_firmware_assets_response_t *fetch_firmware_assets_response_parseFromJSON(cJSON *fetch_firmware_assets_responseJSON){

    fetch_firmware_assets_response_t *fetch_firmware_assets_response_local_var = NULL;

    // define the local list for fetch_firmware_assets_response->added
    list_t *addedList = NULL;

    // define the local list for fetch_firmware_assets_response->existing
    list_t *existingList = NULL;

    // define the local list for fetch_firmware_assets_response->failed
    list_t *failedList = NULL;

    // fetch_firmware_assets_response->added
    cJSON *added = cJSON_GetObjectItemCaseSensitive(fetch_firmware_assets_responseJSON, "added");
    if (cJSON_IsNull(added)) {
        added = NULL;
    }
    if (!added) {
        goto end;
    }

    
    cJSON *added_local = NULL;
    if(!cJSON_IsArray(added)) {
        goto end;//primitive container
    }
    addedList = list_createList();

    cJSON_ArrayForEach(added_local, added)
    {
        if(!cJSON_IsString(added_local))
        {
            goto end;
        }
        list_addElement(addedList , strdup(added_local->valuestring));
    }

    // fetch_firmware_assets_response->existing
    cJSON *existing = cJSON_GetObjectItemCaseSensitive(fetch_firmware_assets_responseJSON, "existing");
    if (cJSON_IsNull(existing)) {
        existing = NULL;
    }
    if (!existing) {
        goto end;
    }

    
    cJSON *existing_local = NULL;
    if(!cJSON_IsArray(existing)) {
        goto end;//primitive container
    }
    existingList = list_createList();

    cJSON_ArrayForEach(existing_local, existing)
    {
        if(!cJSON_IsString(existing_local))
        {
            goto end;
        }
        list_addElement(existingList , strdup(existing_local->valuestring));
    }

    // fetch_firmware_assets_response->failed
    cJSON *failed = cJSON_GetObjectItemCaseSensitive(fetch_firmware_assets_responseJSON, "failed");
    if (cJSON_IsNull(failed)) {
        failed = NULL;
    }
    if (!failed) {
        goto end;
    }

    
    cJSON *failed_local_nonprimitive = NULL;
    if(!cJSON_IsArray(failed)){
        goto end; //nonprimitive container
    }

    failedList = list_createList();

    cJSON_ArrayForEach(failed_local_nonprimitive,failed )
    {
        if(!cJSON_IsObject(failed_local_nonprimitive)){
            goto end;
        }
        fetch_firmware_assets_response_failed_inner_t *failedItem = fetch_firmware_assets_response_failed_inner_parseFromJSON(failed_local_nonprimitive);

        list_addElement(failedList, failedItem);
    }


    fetch_firmware_assets_response_local_var = fetch_firmware_assets_response_create_internal (
        addedList,
        existingList,
        failedList
        );

    return fetch_firmware_assets_response_local_var;
end:
    if (addedList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, addedList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(addedList);
        addedList = NULL;
    }
    if (existingList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, existingList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(existingList);
        existingList = NULL;
    }
    if (failedList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, failedList) {
            fetch_firmware_assets_response_failed_inner_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(failedList);
        failedList = NULL;
    }
    return NULL;

}
