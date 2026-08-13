#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pagination.h"



static pagination_t *pagination_create_internal(
    double current_page,
    double total_pages,
    double total_items,
    double items_per_page
    ) {
    pagination_t *pagination_local_var = malloc(sizeof(pagination_t));
    if (!pagination_local_var) {
        return NULL;
    }
    pagination_local_var->current_page = current_page;
    pagination_local_var->total_pages = total_pages;
    pagination_local_var->total_items = total_items;
    pagination_local_var->items_per_page = items_per_page;

    pagination_local_var->_library_owned = 1;
    return pagination_local_var;
}

__attribute__((deprecated)) pagination_t *pagination_create(
    double current_page,
    double total_pages,
    double total_items,
    double items_per_page
    ) {
    return pagination_create_internal (
        current_page,
        total_pages,
        total_items,
        items_per_page
        );
}

void pagination_free(pagination_t *pagination) {
    if(NULL == pagination){
        return ;
    }
    if(pagination->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "pagination_free");
        return ;
    }
    listEntry_t *listEntry;
    free(pagination);
}

cJSON *pagination_convertToJSON(pagination_t *pagination) {
    cJSON *item = cJSON_CreateObject();

    // pagination->current_page
    if(pagination->current_page) {
    if(cJSON_AddNumberToObject(item, "currentPage", pagination->current_page) == NULL) {
    goto fail; //Numeric
    }
    }


    // pagination->total_pages
    if(pagination->total_pages) {
    if(cJSON_AddNumberToObject(item, "totalPages", pagination->total_pages) == NULL) {
    goto fail; //Numeric
    }
    }


    // pagination->total_items
    if(pagination->total_items) {
    if(cJSON_AddNumberToObject(item, "totalItems", pagination->total_items) == NULL) {
    goto fail; //Numeric
    }
    }


    // pagination->items_per_page
    if(pagination->items_per_page) {
    if(cJSON_AddNumberToObject(item, "itemsPerPage", pagination->items_per_page) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

pagination_t *pagination_parseFromJSON(cJSON *paginationJSON){

    pagination_t *pagination_local_var = NULL;

    // pagination->current_page
    cJSON *current_page = cJSON_GetObjectItemCaseSensitive(paginationJSON, "currentPage");
    if (cJSON_IsNull(current_page)) {
        current_page = NULL;
    }
    if (current_page) { 
    if(!cJSON_IsNumber(current_page))
    {
    goto end; //Numeric
    }
    }

    // pagination->total_pages
    cJSON *total_pages = cJSON_GetObjectItemCaseSensitive(paginationJSON, "totalPages");
    if (cJSON_IsNull(total_pages)) {
        total_pages = NULL;
    }
    if (total_pages) { 
    if(!cJSON_IsNumber(total_pages))
    {
    goto end; //Numeric
    }
    }

    // pagination->total_items
    cJSON *total_items = cJSON_GetObjectItemCaseSensitive(paginationJSON, "totalItems");
    if (cJSON_IsNull(total_items)) {
        total_items = NULL;
    }
    if (total_items) { 
    if(!cJSON_IsNumber(total_items))
    {
    goto end; //Numeric
    }
    }

    // pagination->items_per_page
    cJSON *items_per_page = cJSON_GetObjectItemCaseSensitive(paginationJSON, "itemsPerPage");
    if (cJSON_IsNull(items_per_page)) {
        items_per_page = NULL;
    }
    if (items_per_page) { 
    if(!cJSON_IsNumber(items_per_page))
    {
    goto end; //Numeric
    }
    }


    pagination_local_var = pagination_create_internal (
        current_page ? current_page->valuedouble : 0,
        total_pages ? total_pages->valuedouble : 0,
        total_items ? total_items->valuedouble : 0,
        items_per_page ? items_per_page->valuedouble : 0
        );

    return pagination_local_var;
end:
    return NULL;

}
