#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gpio_state_definition_v1.h"



static gpio_state_definition_v1_t *gpio_state_definition_v1_create_internal(
    double bit_count,
    list_t *banks
    ) {
    gpio_state_definition_v1_t *gpio_state_definition_v1_local_var = malloc(sizeof(gpio_state_definition_v1_t));
    if (!gpio_state_definition_v1_local_var) {
        return NULL;
    }
    gpio_state_definition_v1_local_var->bit_count = bit_count;
    gpio_state_definition_v1_local_var->banks = banks;

    gpio_state_definition_v1_local_var->_library_owned = 1;
    return gpio_state_definition_v1_local_var;
}

__attribute__((deprecated)) gpio_state_definition_v1_t *gpio_state_definition_v1_create(
    double bit_count,
    list_t *banks
    ) {
    return gpio_state_definition_v1_create_internal (
        bit_count,
        banks
        );
}

void gpio_state_definition_v1_free(gpio_state_definition_v1_t *gpio_state_definition_v1) {
    if(NULL == gpio_state_definition_v1){
        return ;
    }
    if(gpio_state_definition_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "gpio_state_definition_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (gpio_state_definition_v1->banks) {
        list_ForEach(listEntry, gpio_state_definition_v1->banks) {
            free(listEntry->data);
        }
        list_freeList(gpio_state_definition_v1->banks);
        gpio_state_definition_v1->banks = NULL;
    }
    free(gpio_state_definition_v1);
}

cJSON *gpio_state_definition_v1_convertToJSON(gpio_state_definition_v1_t *gpio_state_definition_v1) {
    cJSON *item = cJSON_CreateObject();

    // gpio_state_definition_v1->bit_count
    if (!gpio_state_definition_v1->bit_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "bitCount", gpio_state_definition_v1->bit_count) == NULL) {
    goto fail; //Numeric
    }


    // gpio_state_definition_v1->banks
    if (!gpio_state_definition_v1->banks) {
        goto fail;
    }
    cJSON *banks = cJSON_AddArrayToObject(item, "banks");
    if(banks == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *banksListEntry;
    list_ForEach(banksListEntry, gpio_state_definition_v1->banks) {
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

gpio_state_definition_v1_t *gpio_state_definition_v1_parseFromJSON(cJSON *gpio_state_definition_v1JSON){

    gpio_state_definition_v1_t *gpio_state_definition_v1_local_var = NULL;

    // define the local list for gpio_state_definition_v1->banks
    list_t *banksList = NULL;

    // gpio_state_definition_v1->bit_count
    cJSON *bit_count = cJSON_GetObjectItemCaseSensitive(gpio_state_definition_v1JSON, "bitCount");
    if (cJSON_IsNull(bit_count)) {
        bit_count = NULL;
    }
    if (!bit_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(bit_count))
    {
    goto end; //Numeric
    }

    // gpio_state_definition_v1->banks
    cJSON *banks = cJSON_GetObjectItemCaseSensitive(gpio_state_definition_v1JSON, "banks");
    if (cJSON_IsNull(banks)) {
        banks = NULL;
    }
    if (!banks) {
        goto end;
    }

    
    cJSON *banks_local = NULL;
    if(!cJSON_IsArray(banks)) {
        goto end;//primitive container
    }
    banksList = list_createList();

    cJSON_ArrayForEach(banks_local, banks)
    {
    }


    gpio_state_definition_v1_local_var = gpio_state_definition_v1_create_internal (
        bit_count->valuedouble,
        banksList
        );

    return gpio_state_definition_v1_local_var;
end:
    if (banksList) {
        list_freeList(banksList);
        banksList = NULL;
    }
    return NULL;

}
