#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "billing_line_item.h"



static billing_line_item_t *billing_line_item_create_internal(
    char *type,
    char *name,
    char *short_name,
    char *description,
    double quantity,
    double unit_cost
    ) {
    billing_line_item_t *billing_line_item_local_var = malloc(sizeof(billing_line_item_t));
    if (!billing_line_item_local_var) {
        return NULL;
    }
    billing_line_item_local_var->type = type;
    billing_line_item_local_var->name = name;
    billing_line_item_local_var->short_name = short_name;
    billing_line_item_local_var->description = description;
    billing_line_item_local_var->quantity = quantity;
    billing_line_item_local_var->unit_cost = unit_cost;

    billing_line_item_local_var->_library_owned = 1;
    return billing_line_item_local_var;
}

__attribute__((deprecated)) billing_line_item_t *billing_line_item_create(
    char *type,
    char *name,
    char *short_name,
    char *description,
    double quantity,
    double unit_cost
    ) {
    return billing_line_item_create_internal (
        type,
        name,
        short_name,
        description,
        quantity,
        unit_cost
        );
}

void billing_line_item_free(billing_line_item_t *billing_line_item) {
    if(NULL == billing_line_item){
        return ;
    }
    if(billing_line_item->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "billing_line_item_free");
        return ;
    }
    listEntry_t *listEntry;
    if (billing_line_item->type) {
        free(billing_line_item->type);
        billing_line_item->type = NULL;
    }
    if (billing_line_item->name) {
        free(billing_line_item->name);
        billing_line_item->name = NULL;
    }
    if (billing_line_item->short_name) {
        free(billing_line_item->short_name);
        billing_line_item->short_name = NULL;
    }
    if (billing_line_item->description) {
        free(billing_line_item->description);
        billing_line_item->description = NULL;
    }
    free(billing_line_item);
}

cJSON *billing_line_item_convertToJSON(billing_line_item_t *billing_line_item) {
    cJSON *item = cJSON_CreateObject();

    // billing_line_item->type
    if (!billing_line_item->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", billing_line_item->type) == NULL) {
    goto fail; //String
    }


    // billing_line_item->name
    if (!billing_line_item->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", billing_line_item->name) == NULL) {
    goto fail; //String
    }


    // billing_line_item->short_name
    if (!billing_line_item->short_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "shortName", billing_line_item->short_name) == NULL) {
    goto fail; //String
    }


    // billing_line_item->description
    if (!billing_line_item->description) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "description", billing_line_item->description) == NULL) {
    goto fail; //String
    }


    // billing_line_item->quantity
    if (!billing_line_item->quantity) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "quantity", billing_line_item->quantity) == NULL) {
    goto fail; //Numeric
    }


    // billing_line_item->unit_cost
    if (!billing_line_item->unit_cost) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "unit_cost", billing_line_item->unit_cost) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

billing_line_item_t *billing_line_item_parseFromJSON(cJSON *billing_line_itemJSON){

    billing_line_item_t *billing_line_item_local_var = NULL;

    // billing_line_item->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(billing_line_itemJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }

    // billing_line_item->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(billing_line_itemJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // billing_line_item->short_name
    cJSON *short_name = cJSON_GetObjectItemCaseSensitive(billing_line_itemJSON, "shortName");
    if (cJSON_IsNull(short_name)) {
        short_name = NULL;
    }
    if (!short_name) {
        goto end;
    }

    
    if(!cJSON_IsString(short_name))
    {
    goto end; //String
    }

    // billing_line_item->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(billing_line_itemJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (!description) {
        goto end;
    }

    
    if(!cJSON_IsString(description))
    {
    goto end; //String
    }

    // billing_line_item->quantity
    cJSON *quantity = cJSON_GetObjectItemCaseSensitive(billing_line_itemJSON, "quantity");
    if (cJSON_IsNull(quantity)) {
        quantity = NULL;
    }
    if (!quantity) {
        goto end;
    }

    
    if(!cJSON_IsNumber(quantity))
    {
    goto end; //Numeric
    }

    // billing_line_item->unit_cost
    cJSON *unit_cost = cJSON_GetObjectItemCaseSensitive(billing_line_itemJSON, "unit_cost");
    if (cJSON_IsNull(unit_cost)) {
        unit_cost = NULL;
    }
    if (!unit_cost) {
        goto end;
    }

    
    if(!cJSON_IsNumber(unit_cost))
    {
    goto end; //Numeric
    }


    billing_line_item_local_var = billing_line_item_create_internal (
        strdup(type->valuestring),
        strdup(name->valuestring),
        strdup(short_name->valuestring),
        strdup(description->valuestring),
        quantity->valuedouble,
        unit_cost->valuedouble
        );

    return billing_line_item_local_var;
end:
    return NULL;

}
