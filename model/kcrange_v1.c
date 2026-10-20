#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "kcrange_v1.h"



static kcrange_v1_t *kcrange_v1_create_internal(
    char *kext,
    list_t *range
    ) {
    kcrange_v1_t *kcrange_v1_local_var = malloc(sizeof(kcrange_v1_t));
    if (!kcrange_v1_local_var) {
        return NULL;
    }
    kcrange_v1_local_var->kext = kext;
    kcrange_v1_local_var->range = range;

    kcrange_v1_local_var->_library_owned = 1;
    return kcrange_v1_local_var;
}

__attribute__((deprecated)) kcrange_v1_t *kcrange_v1_create(
    char *kext,
    list_t *range
    ) {
    return kcrange_v1_create_internal (
        kext,
        range
        );
}

void kcrange_v1_free(kcrange_v1_t *kcrange_v1) {
    if(NULL == kcrange_v1){
        return ;
    }
    if(kcrange_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "kcrange_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (kcrange_v1->kext) {
        free(kcrange_v1->kext);
        kcrange_v1->kext = NULL;
    }
    if (kcrange_v1->range) {
        list_ForEach(listEntry, kcrange_v1->range) {
            free(listEntry->data);
        }
        list_freeList(kcrange_v1->range);
        kcrange_v1->range = NULL;
    }
    free(kcrange_v1);
}

cJSON *kcrange_v1_convertToJSON(kcrange_v1_t *kcrange_v1) {
    cJSON *item = cJSON_CreateObject();

    // kcrange_v1->kext
    if(kcrange_v1->kext) {
    if(cJSON_AddStringToObject(item, "kext", kcrange_v1->kext) == NULL) {
    goto fail; //String
    }
    }


    // kcrange_v1->range
    if(kcrange_v1->range) {
    cJSON *range = cJSON_AddArrayToObject(item, "range");
    if(range == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *rangeListEntry;
    list_ForEach(rangeListEntry, kcrange_v1->range) {
    if(cJSON_AddStringToObject(range, "", rangeListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

kcrange_v1_t *kcrange_v1_parseFromJSON(cJSON *kcrange_v1JSON){

    kcrange_v1_t *kcrange_v1_local_var = NULL;

    // define the local list for kcrange_v1->range
    list_t *rangeList = NULL;

    // kcrange_v1->kext
    cJSON *kext = cJSON_GetObjectItemCaseSensitive(kcrange_v1JSON, "kext");
    if (cJSON_IsNull(kext)) {
        kext = NULL;
    }
    if (kext) { 
    if(!cJSON_IsString(kext) && !cJSON_IsNull(kext))
    {
    goto end; //String
    }
    }

    // kcrange_v1->range
    cJSON *range = cJSON_GetObjectItemCaseSensitive(kcrange_v1JSON, "range");
    if (cJSON_IsNull(range)) {
        range = NULL;
    }
    if (range) { 
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
    }


    kcrange_v1_local_var = kcrange_v1_create_internal (
        kext && !cJSON_IsNull(kext) ? strdup(kext->valuestring) : NULL,
        range ? rangeList : NULL
        );

    return kcrange_v1_local_var;
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
