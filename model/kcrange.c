#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "kcrange.h"



static kcrange_t *kcrange_create_internal(
    char *kernel_extension,
    list_t *range
    ) {
    kcrange_t *kcrange_local_var = malloc(sizeof(kcrange_t));
    if (!kcrange_local_var) {
        return NULL;
    }
    kcrange_local_var->kernel_extension = kernel_extension;
    kcrange_local_var->range = range;

    kcrange_local_var->_library_owned = 1;
    return kcrange_local_var;
}

__attribute__((deprecated)) kcrange_t *kcrange_create(
    char *kernel_extension,
    list_t *range
    ) {
    return kcrange_create_internal (
        kernel_extension,
        range
        );
}

void kcrange_free(kcrange_t *kcrange) {
    if(NULL == kcrange){
        return ;
    }
    if(kcrange->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "kcrange_free");
        return ;
    }
    listEntry_t *listEntry;
    if (kcrange->kernel_extension) {
        free(kcrange->kernel_extension);
        kcrange->kernel_extension = NULL;
    }
    if (kcrange->range) {
        list_ForEach(listEntry, kcrange->range) {
            free(listEntry->data);
        }
        list_freeList(kcrange->range);
        kcrange->range = NULL;
    }
    free(kcrange);
}

cJSON *kcrange_convertToJSON(kcrange_t *kcrange) {
    cJSON *item = cJSON_CreateObject();

    // kcrange->kernel_extension
    if (!kcrange->kernel_extension) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kernelExtension", kcrange->kernel_extension) == NULL) {
    goto fail; //String
    }


    // kcrange->range
    if (!kcrange->range) {
        goto fail;
    }
    cJSON *range = cJSON_AddArrayToObject(item, "range");
    if(range == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *rangeListEntry;
    list_ForEach(rangeListEntry, kcrange->range) {
    if(cJSON_AddStringToObject(range, "", rangeListEntry->data) == NULL)
    {
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

kcrange_t *kcrange_parseFromJSON(cJSON *kcrangeJSON){

    kcrange_t *kcrange_local_var = NULL;

    // define the local list for kcrange->range
    list_t *rangeList = NULL;

    // kcrange->kernel_extension
    cJSON *kernel_extension = cJSON_GetObjectItemCaseSensitive(kcrangeJSON, "kernelExtension");
    if (cJSON_IsNull(kernel_extension)) {
        kernel_extension = NULL;
    }
    if (!kernel_extension) {
        goto end;
    }

    
    if(!cJSON_IsString(kernel_extension))
    {
    goto end; //String
    }

    // kcrange->range
    cJSON *range = cJSON_GetObjectItemCaseSensitive(kcrangeJSON, "range");
    if (cJSON_IsNull(range)) {
        range = NULL;
    }
    if (!range) {
        goto end;
    }

    
    cJSON *range_local = NULL;
    if(!cJSON_IsArray(range)) {
        goto end;//primitive container
    }
    rangeList = list_createList();

    cJSON_ArrayForEach(range_local, range)
    {
        if(!cJSON_IsString(range_local))
        {
            goto end;
        }
        list_addElement(rangeList , strdup(range_local->valuestring));
    }


    kcrange_local_var = kcrange_create_internal (
        strdup(kernel_extension->valuestring),
        rangeList
        );

    return kcrange_local_var;
end:
    if (rangeList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, rangeList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(rangeList);
        rangeList = NULL;
    }
    return NULL;

}
