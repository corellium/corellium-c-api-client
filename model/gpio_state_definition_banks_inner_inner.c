#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gpio_state_definition_banks_inner_inner.h"



static gpio_state_definition_banks_inner_inner_t *gpio_state_definition_banks_inner_inner_create_internal(
    ) {
    gpio_state_definition_banks_inner_inner_t *gpio_state_definition_banks_inner_inner_local_var = malloc(sizeof(gpio_state_definition_banks_inner_inner_t));
    if (!gpio_state_definition_banks_inner_inner_local_var) {
        return NULL;
    }

    gpio_state_definition_banks_inner_inner_local_var->_library_owned = 1;
    return gpio_state_definition_banks_inner_inner_local_var;
}

__attribute__((deprecated)) gpio_state_definition_banks_inner_inner_t *gpio_state_definition_banks_inner_inner_create(
    ) {
    return gpio_state_definition_banks_inner_inner_create_internal (
        );
}

void gpio_state_definition_banks_inner_inner_free(gpio_state_definition_banks_inner_inner_t *gpio_state_definition_banks_inner_inner) {
    if(NULL == gpio_state_definition_banks_inner_inner){
        return ;
    }
    if(gpio_state_definition_banks_inner_inner->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "gpio_state_definition_banks_inner_inner_free");
        return ;
    }
    listEntry_t *listEntry;
    free(gpio_state_definition_banks_inner_inner);
}

cJSON *gpio_state_definition_banks_inner_inner_convertToJSON(gpio_state_definition_banks_inner_inner_t *gpio_state_definition_banks_inner_inner) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

gpio_state_definition_banks_inner_inner_t *gpio_state_definition_banks_inner_inner_parseFromJSON(cJSON *gpio_state_definition_banks_inner_innerJSON){

    gpio_state_definition_banks_inner_inner_t *gpio_state_definition_banks_inner_inner_local_var = NULL;


    gpio_state_definition_banks_inner_inner_local_var = gpio_state_definition_banks_inner_inner_create_internal (
        );

    return gpio_state_definition_banks_inner_inner_local_var;
end:
    return NULL;

}
