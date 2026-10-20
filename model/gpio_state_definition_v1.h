/*
 * gpio_state_definition_v1.h
 *
 * 
 */

#ifndef _gpio_state_definition_v1_H_
#define _gpio_state_definition_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct gpio_state_definition_v1_t gpio_state_definition_v1_t;




typedef struct gpio_state_definition_v1_t {
    double bit_count; //numeric
    list_t *banks; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} gpio_state_definition_v1_t;

__attribute__((deprecated)) gpio_state_definition_v1_t *gpio_state_definition_v1_create(
    double bit_count,
    list_t *banks
);

void gpio_state_definition_v1_free(gpio_state_definition_v1_t *gpio_state_definition_v1);

gpio_state_definition_v1_t *gpio_state_definition_v1_parseFromJSON(cJSON *gpio_state_definition_v1JSON);

cJSON *gpio_state_definition_v1_convertToJSON(gpio_state_definition_v1_t *gpio_state_definition_v1);

#endif /* _gpio_state_definition_v1_H_ */

