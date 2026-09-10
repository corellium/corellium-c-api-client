#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "compute_node_file_list.h"



static compute_node_file_list_t *compute_node_file_list_create_internal(
    list_t *files
    ) {
    compute_node_file_list_t *compute_node_file_list_local_var = malloc(sizeof(compute_node_file_list_t));
    if (!compute_node_file_list_local_var) {
        return NULL;
    }
    compute_node_file_list_local_var->files = files;

    compute_node_file_list_local_var->_library_owned = 1;
    return compute_node_file_list_local_var;
}

__attribute__((deprecated)) compute_node_file_list_t *compute_node_file_list_create(
    list_t *files
    ) {
    return compute_node_file_list_create_internal (
        files
        );
}

void compute_node_file_list_free(compute_node_file_list_t *compute_node_file_list) {
    if(NULL == compute_node_file_list){
        return ;
    }
    if(compute_node_file_list->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "compute_node_file_list_free");
        return ;
    }
    listEntry_t *listEntry;
    if (compute_node_file_list->files) {
        list_ForEach(listEntry, compute_node_file_list->files) {
            compute_node_file_free(listEntry->data);
        }
        list_freeList(compute_node_file_list->files);
        compute_node_file_list->files = NULL;
    }
    free(compute_node_file_list);
}

cJSON *compute_node_file_list_convertToJSON(compute_node_file_list_t *compute_node_file_list) {
    cJSON *item = cJSON_CreateObject();

    // compute_node_file_list->files
    if (!compute_node_file_list->files) {
        goto fail;
    }
    cJSON *files = cJSON_AddArrayToObject(item, "files");
    if(files == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *filesListEntry;
    if (compute_node_file_list->files) {
    list_ForEach(filesListEntry, compute_node_file_list->files) {
    cJSON *itemLocal = compute_node_file_convertToJSON(filesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(files, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

compute_node_file_list_t *compute_node_file_list_parseFromJSON(cJSON *compute_node_file_listJSON){

    compute_node_file_list_t *compute_node_file_list_local_var = NULL;

    // define the local list for compute_node_file_list->files
    list_t *filesList = NULL;

    // compute_node_file_list->files
    cJSON *files = cJSON_GetObjectItemCaseSensitive(compute_node_file_listJSON, "files");
    if (cJSON_IsNull(files)) {
        files = NULL;
    }
    if (!files) {
        goto end;
    }

    
    cJSON *files_local_nonprimitive = NULL;
    if(!cJSON_IsArray(files)){
        goto end; //nonprimitive container
    }

    filesList = list_createList();

    cJSON_ArrayForEach(files_local_nonprimitive,files )
    {
        if(!cJSON_IsObject(files_local_nonprimitive)){
            goto end;
        }
        compute_node_file_t *filesItem = compute_node_file_parseFromJSON(files_local_nonprimitive);

        list_addElement(filesList, filesItem);
    }


    compute_node_file_list_local_var = compute_node_file_list_create_internal (
        filesList
        );

    return compute_node_file_list_local_var;
end:
    if (filesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, filesList) {
            compute_node_file_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(filesList);
        filesList = NULL;
    }
    return NULL;

}
