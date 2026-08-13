#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "billing_summary_pending_usage_based.h"



static billing_summary_pending_usage_based_t *billing_summary_pending_usage_based_create_internal(
    double last_bill_date,
    double next_bill_date,
    double billing_threshold,
    char *total,
    list_t *line_items
    ) {
    billing_summary_pending_usage_based_t *billing_summary_pending_usage_based_local_var = malloc(sizeof(billing_summary_pending_usage_based_t));
    if (!billing_summary_pending_usage_based_local_var) {
        return NULL;
    }
    billing_summary_pending_usage_based_local_var->last_bill_date = last_bill_date;
    billing_summary_pending_usage_based_local_var->next_bill_date = next_bill_date;
    billing_summary_pending_usage_based_local_var->billing_threshold = billing_threshold;
    billing_summary_pending_usage_based_local_var->total = total;
    billing_summary_pending_usage_based_local_var->line_items = line_items;

    billing_summary_pending_usage_based_local_var->_library_owned = 1;
    return billing_summary_pending_usage_based_local_var;
}

__attribute__((deprecated)) billing_summary_pending_usage_based_t *billing_summary_pending_usage_based_create(
    double last_bill_date,
    double next_bill_date,
    double billing_threshold,
    char *total,
    list_t *line_items
    ) {
    return billing_summary_pending_usage_based_create_internal (
        last_bill_date,
        next_bill_date,
        billing_threshold,
        total,
        line_items
        );
}

void billing_summary_pending_usage_based_free(billing_summary_pending_usage_based_t *billing_summary_pending_usage_based) {
    if(NULL == billing_summary_pending_usage_based){
        return ;
    }
    if(billing_summary_pending_usage_based->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "billing_summary_pending_usage_based_free");
        return ;
    }
    listEntry_t *listEntry;
    if (billing_summary_pending_usage_based->total) {
        free(billing_summary_pending_usage_based->total);
        billing_summary_pending_usage_based->total = NULL;
    }
    if (billing_summary_pending_usage_based->line_items) {
        list_ForEach(listEntry, billing_summary_pending_usage_based->line_items) {
            billing_line_item_free(listEntry->data);
        }
        list_freeList(billing_summary_pending_usage_based->line_items);
        billing_summary_pending_usage_based->line_items = NULL;
    }
    free(billing_summary_pending_usage_based);
}

cJSON *billing_summary_pending_usage_based_convertToJSON(billing_summary_pending_usage_based_t *billing_summary_pending_usage_based) {
    cJSON *item = cJSON_CreateObject();

    // billing_summary_pending_usage_based->last_bill_date
    if (!billing_summary_pending_usage_based->last_bill_date) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "lastBillDate", billing_summary_pending_usage_based->last_bill_date) == NULL) {
    goto fail; //Numeric
    }


    // billing_summary_pending_usage_based->next_bill_date
    if (!billing_summary_pending_usage_based->next_bill_date) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "nextBillDate", billing_summary_pending_usage_based->next_bill_date) == NULL) {
    goto fail; //Numeric
    }


    // billing_summary_pending_usage_based->billing_threshold
    if (!billing_summary_pending_usage_based->billing_threshold) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "billingThreshold", billing_summary_pending_usage_based->billing_threshold) == NULL) {
    goto fail; //Numeric
    }


    // billing_summary_pending_usage_based->total
    if (!billing_summary_pending_usage_based->total) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "total", billing_summary_pending_usage_based->total) == NULL) {
    goto fail; //String
    }


    // billing_summary_pending_usage_based->line_items
    if (!billing_summary_pending_usage_based->line_items) {
        goto fail;
    }
    cJSON *line_items = cJSON_AddArrayToObject(item, "lineItems");
    if(line_items == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *line_itemsListEntry;
    if (billing_summary_pending_usage_based->line_items) {
    list_ForEach(line_itemsListEntry, billing_summary_pending_usage_based->line_items) {
    cJSON *itemLocal = billing_line_item_convertToJSON(line_itemsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(line_items, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

billing_summary_pending_usage_based_t *billing_summary_pending_usage_based_parseFromJSON(cJSON *billing_summary_pending_usage_basedJSON){

    billing_summary_pending_usage_based_t *billing_summary_pending_usage_based_local_var = NULL;

    // define the local list for billing_summary_pending_usage_based->line_items
    list_t *line_itemsList = NULL;

    // billing_summary_pending_usage_based->last_bill_date
    cJSON *last_bill_date = cJSON_GetObjectItemCaseSensitive(billing_summary_pending_usage_basedJSON, "lastBillDate");
    if (cJSON_IsNull(last_bill_date)) {
        last_bill_date = NULL;
    }
    if (!last_bill_date) {
        goto end;
    }

    
    if(!cJSON_IsNumber(last_bill_date))
    {
    goto end; //Numeric
    }

    // billing_summary_pending_usage_based->next_bill_date
    cJSON *next_bill_date = cJSON_GetObjectItemCaseSensitive(billing_summary_pending_usage_basedJSON, "nextBillDate");
    if (cJSON_IsNull(next_bill_date)) {
        next_bill_date = NULL;
    }
    if (!next_bill_date) {
        goto end;
    }

    
    if(!cJSON_IsNumber(next_bill_date))
    {
    goto end; //Numeric
    }

    // billing_summary_pending_usage_based->billing_threshold
    cJSON *billing_threshold = cJSON_GetObjectItemCaseSensitive(billing_summary_pending_usage_basedJSON, "billingThreshold");
    if (cJSON_IsNull(billing_threshold)) {
        billing_threshold = NULL;
    }
    if (!billing_threshold) {
        goto end;
    }

    
    if(!cJSON_IsNumber(billing_threshold))
    {
    goto end; //Numeric
    }

    // billing_summary_pending_usage_based->total
    cJSON *total = cJSON_GetObjectItemCaseSensitive(billing_summary_pending_usage_basedJSON, "total");
    if (cJSON_IsNull(total)) {
        total = NULL;
    }
    if (!total) {
        goto end;
    }

    
    if(!cJSON_IsString(total))
    {
    goto end; //String
    }

    // billing_summary_pending_usage_based->line_items
    cJSON *line_items = cJSON_GetObjectItemCaseSensitive(billing_summary_pending_usage_basedJSON, "lineItems");
    if (cJSON_IsNull(line_items)) {
        line_items = NULL;
    }
    if (!line_items) {
        goto end;
    }

    
    cJSON *line_items_local_nonprimitive = NULL;
    if(!cJSON_IsArray(line_items)){
        goto end; //nonprimitive container
    }

    line_itemsList = list_createList();

    cJSON_ArrayForEach(line_items_local_nonprimitive,line_items )
    {
        if(!cJSON_IsObject(line_items_local_nonprimitive)){
            goto end;
        }
        billing_line_item_t *line_itemsItem = billing_line_item_parseFromJSON(line_items_local_nonprimitive);

        list_addElement(line_itemsList, line_itemsItem);
    }


    billing_summary_pending_usage_based_local_var = billing_summary_pending_usage_based_create_internal (
        last_bill_date->valuedouble,
        next_bill_date->valuedouble,
        billing_threshold->valuedouble,
        strdup(total->valuestring),
        line_itemsList
        );

    return billing_summary_pending_usage_based_local_var;
end:
    if (line_itemsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, line_itemsList) {
            billing_line_item_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(line_itemsList);
        line_itemsList = NULL;
    }
    return NULL;

}
