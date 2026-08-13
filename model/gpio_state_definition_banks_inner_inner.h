/*
 * gpio_state_definition_banks_inner_inner.h
 *
 * 
 */

#ifndef _gpio_state_definition_banks_inner_inner_H_
#define _gpio_state_definition_banks_inner_inner_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct gpio_state_definition_banks_inner_inner_t gpio_state_definition_banks_inner_inner_t;




typedef struct gpio_state_definition_banks_inner_inner_t {

    int _library_owned; // Is the library responsible for freeing this object?
} gpio_state_definition_banks_inner_inner_t;

__attribute__((deprecated)) gpio_state_definition_banks_inner_inner_t *gpio_state_definition_banks_inner_inner_create(
);

void gpio_state_definition_banks_inner_inner_free(gpio_state_definition_banks_inner_inner_t *gpio_state_definition_banks_inner_inner);

gpio_state_definition_banks_inner_inner_t *gpio_state_definition_banks_inner_inner_parseFromJSON(cJSON *gpio_state_definition_banks_inner_innerJSON);

cJSON *gpio_state_definition_banks_inner_inner_convertToJSON(gpio_state_definition_banks_inner_inner_t *gpio_state_definition_banks_inner_inner);

#endif /* _gpio_state_definition_banks_inner_inner_H_ */

