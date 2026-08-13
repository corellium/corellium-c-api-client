/*
 * gpios_state_v1.h
 *
 * Current state of GPIOs
 */

#ifndef _gpios_state_v1_H_
#define _gpios_state_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct gpios_state_v1_t gpios_state_v1_t;

#include "gpio_state_definition_v1.h"



typedef struct gpios_state_v1_t {
    struct gpio_state_definition_v1_t *led; //model
    struct gpio_state_definition_v1_t *button; //model
    struct gpio_state_definition_v1_t *_switch; //model

    int _library_owned; // Is the library responsible for freeing this object?
} gpios_state_v1_t;

__attribute__((deprecated)) gpios_state_v1_t *gpios_state_v1_create(
    gpio_state_definition_v1_t *led,
    gpio_state_definition_v1_t *button,
    gpio_state_definition_v1_t *_switch
);

void gpios_state_v1_free(gpios_state_v1_t *gpios_state_v1);

gpios_state_v1_t *gpios_state_v1_parseFromJSON(cJSON *gpios_state_v1JSON);

cJSON *gpios_state_v1_convertToJSON(gpios_state_v1_t *gpios_state_v1);

#endif /* _gpios_state_v1_H_ */

