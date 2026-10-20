#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gpios_state_v1.h"



static gpios_state_v1_t *gpios_state_v1_create_internal(
    gpio_state_definition_v1_t *led,
    gpio_state_definition_v1_t *button,
    gpio_state_definition_v1_t *_switch
    ) {
    gpios_state_v1_t *gpios_state_v1_local_var = malloc(sizeof(gpios_state_v1_t));
    if (!gpios_state_v1_local_var) {
        return NULL;
    }
    gpios_state_v1_local_var->led = led;
    gpios_state_v1_local_var->button = button;
    gpios_state_v1_local_var->_switch = _switch;

    gpios_state_v1_local_var->_library_owned = 1;
    return gpios_state_v1_local_var;
}

__attribute__((deprecated)) gpios_state_v1_t *gpios_state_v1_create(
    gpio_state_definition_v1_t *led,
    gpio_state_definition_v1_t *button,
    gpio_state_definition_v1_t *_switch
    ) {
    return gpios_state_v1_create_internal (
        led,
        button,
        _switch
        );
}

void gpios_state_v1_free(gpios_state_v1_t *gpios_state_v1) {
    if(NULL == gpios_state_v1){
        return ;
    }
    if(gpios_state_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "gpios_state_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (gpios_state_v1->led) {
        gpio_state_definition_v1_free(gpios_state_v1->led);
        gpios_state_v1->led = NULL;
    }
    if (gpios_state_v1->button) {
        gpio_state_definition_v1_free(gpios_state_v1->button);
        gpios_state_v1->button = NULL;
    }
    if (gpios_state_v1->_switch) {
        gpio_state_definition_v1_free(gpios_state_v1->_switch);
        gpios_state_v1->_switch = NULL;
    }
    free(gpios_state_v1);
}

cJSON *gpios_state_v1_convertToJSON(gpios_state_v1_t *gpios_state_v1) {
    cJSON *item = cJSON_CreateObject();

    // gpios_state_v1->led
    if(gpios_state_v1->led) {
    cJSON *led_local_JSON = gpio_state_definition_v1_convertToJSON(gpios_state_v1->led);
    if(led_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "led", led_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // gpios_state_v1->button
    if(gpios_state_v1->button) {
    cJSON *button_local_JSON = gpio_state_definition_v1_convertToJSON(gpios_state_v1->button);
    if(button_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "button", button_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // gpios_state_v1->_switch
    if(gpios_state_v1->_switch) {
    cJSON *_switch_local_JSON = gpio_state_definition_v1_convertToJSON(gpios_state_v1->_switch);
    if(_switch_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "switch", _switch_local_JSON);
    if(item->child == NULL) {
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

gpios_state_v1_t *gpios_state_v1_parseFromJSON(cJSON *gpios_state_v1JSON){

    gpios_state_v1_t *gpios_state_v1_local_var = NULL;

    // define the local variable for gpios_state_v1->led
    gpio_state_definition_v1_t *led_local_nonprim = NULL;

    // define the local variable for gpios_state_v1->button
    gpio_state_definition_v1_t *button_local_nonprim = NULL;

    // define the local variable for gpios_state_v1->_switch
    gpio_state_definition_v1_t *_switch_local_nonprim = NULL;

    // gpios_state_v1->led
    cJSON *led = cJSON_GetObjectItemCaseSensitive(gpios_state_v1JSON, "led");
    if (cJSON_IsNull(led)) {
        led = NULL;
    }
    if (led) { 
    led_local_nonprim = gpio_state_definition_v1_parseFromJSON(led); //nonprimitive
    }

    // gpios_state_v1->button
    cJSON *button = cJSON_GetObjectItemCaseSensitive(gpios_state_v1JSON, "button");
    if (cJSON_IsNull(button)) {
        button = NULL;
    }
    if (button) { 
    button_local_nonprim = gpio_state_definition_v1_parseFromJSON(button); //nonprimitive
    }

    // gpios_state_v1->_switch
    cJSON *_switch = cJSON_GetObjectItemCaseSensitive(gpios_state_v1JSON, "switch");
    if (cJSON_IsNull(_switch)) {
        _switch = NULL;
    }
    if (_switch) { 
    _switch_local_nonprim = gpio_state_definition_v1_parseFromJSON(_switch); //nonprimitive
    }


    gpios_state_v1_local_var = gpios_state_v1_create_internal (
        led ? led_local_nonprim : NULL,
        button ? button_local_nonprim : NULL,
        _switch ? _switch_local_nonprim : NULL
        );

    return gpios_state_v1_local_var;
end:
    if (led_local_nonprim) {
        gpio_state_definition_v1_free(led_local_nonprim);
        led_local_nonprim = NULL;
    }
    if (button_local_nonprim) {
        gpio_state_definition_v1_free(button_local_nonprim);
        button_local_nonprim = NULL;
    }
    if (_switch_local_nonprim) {
        gpio_state_definition_v1_free(_switch_local_nonprim);
        _switch_local_nonprim = NULL;
    }
    return NULL;

}
