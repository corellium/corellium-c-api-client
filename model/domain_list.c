#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "domain_list.h"



static domain_list_t *domain_list_create_internal(
    double count,
    double page,
    double per_page,
    list_t *items,
    domain_list_usage_t *usage
    ) {
    domain_list_t *domain_list_local_var = malloc(sizeof(domain_list_t));
    if (!domain_list_local_var) {
        return NULL;
    }
    domain_list_local_var->count = count;
    domain_list_local_var->page = page;
    domain_list_local_var->per_page = per_page;
    domain_list_local_var->items = items;
    domain_list_local_var->usage = usage;

    domain_list_local_var->_library_owned = 1;
    return domain_list_local_var;
}

__attribute__((deprecated)) domain_list_t *domain_list_create(
    double count,
    double page,
    double per_page,
    list_t *items,
    domain_list_usage_t *usage
    ) {
    return domain_list_create_internal (
        count,
        page,
        per_page,
        items,
        usage
        );
}

void domain_list_free(domain_list_t *domain_list) {
    if(NULL == domain_list){
        return ;
    }
    if(domain_list->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "domain_list_free");
        return ;
    }
    listEntry_t *listEntry;
    if (domain_list->items) {
        list_ForEach(listEntry, domain_list->items) {
            domain_list_item_free(listEntry->data);
        }
        list_freeList(domain_list->items);
        domain_list->items = NULL;
    }
    if (domain_list->usage) {
        domain_list_usage_free(domain_list->usage);
        domain_list->usage = NULL;
    }
    free(domain_list);
}

cJSON *domain_list_convertToJSON(domain_list_t *domain_list) {
    cJSON *item = cJSON_CreateObject();

    // domain_list->count
    if (!domain_list->count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "count", domain_list->count) == NULL) {
    goto fail; //Numeric
    }


    // domain_list->page
    if (!domain_list->page) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "page", domain_list->page) == NULL) {
    goto fail; //Numeric
    }


    // domain_list->per_page
    if (!domain_list->per_page) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "perPage", domain_list->per_page) == NULL) {
    goto fail; //Numeric
    }


    // domain_list->items
    if (!domain_list->items) {
        goto fail;
    }
    cJSON *items = cJSON_AddArrayToObject(item, "items");
    if(items == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *itemsListEntry;
    if (domain_list->items) {
    list_ForEach(itemsListEntry, domain_list->items) {
    cJSON *itemLocal = domain_list_item_convertToJSON(itemsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(items, itemLocal);
    }
    }


    // domain_list->usage
    if (!domain_list->usage) {
        goto fail;
    }
    cJSON *usage_local_JSON = domain_list_usage_convertToJSON(domain_list->usage);
    if(usage_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "usage", usage_local_JSON);
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

domain_list_t *domain_list_parseFromJSON(cJSON *domain_listJSON){

    domain_list_t *domain_list_local_var = NULL;

    // define the local list for domain_list->items
    list_t *itemsList = NULL;

    // define the local variable for domain_list->usage
    domain_list_usage_t *usage_local_nonprim = NULL;

    // domain_list->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(domain_listJSON, "count");
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

    // domain_list->page
    cJSON *page = cJSON_GetObjectItemCaseSensitive(domain_listJSON, "page");
    if (cJSON_IsNull(page)) {
        page = NULL;
    }
    if (!page) {
        goto end;
    }

    
    if(!cJSON_IsNumber(page))
    {
    goto end; //Numeric
    }

    // domain_list->per_page
    cJSON *per_page = cJSON_GetObjectItemCaseSensitive(domain_listJSON, "perPage");
    if (cJSON_IsNull(per_page)) {
        per_page = NULL;
    }
    if (!per_page) {
        goto end;
    }

    
    if(!cJSON_IsNumber(per_page))
    {
    goto end; //Numeric
    }

    // domain_list->items
    cJSON *items = cJSON_GetObjectItemCaseSensitive(domain_listJSON, "items");
    if (cJSON_IsNull(items)) {
        items = NULL;
    }
    if (!items) {
        goto end;
    }

    
    cJSON *items_local_nonprimitive = NULL;
    if(!cJSON_IsArray(items)){
        goto end; //nonprimitive container
    }

    itemsList = list_createList();

    cJSON_ArrayForEach(items_local_nonprimitive,items )
    {
        if(!cJSON_IsObject(items_local_nonprimitive)){
            goto end;
        }
        domain_list_item_t *itemsItem = domain_list_item_parseFromJSON(items_local_nonprimitive);

        list_addElement(itemsList, itemsItem);
    }

    // domain_list->usage
    cJSON *usage = cJSON_GetObjectItemCaseSensitive(domain_listJSON, "usage");
    if (cJSON_IsNull(usage)) {
        usage = NULL;
    }
    if (!usage) {
        goto end;
    }

    
    usage_local_nonprim = domain_list_usage_parseFromJSON(usage); //nonprimitive


    domain_list_local_var = domain_list_create_internal (
        count->valuedouble,
        page->valuedouble,
        per_page->valuedouble,
        itemsList,
        usage_local_nonprim
        );

    return domain_list_local_var;
end:
    if (itemsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, itemsList) {
            domain_list_item_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(itemsList);
        itemsList = NULL;
    }
    if (usage_local_nonprim) {
        domain_list_usage_free(usage_local_nonprim);
        usage_local_nonprim = NULL;
    }
    return NULL;

}
