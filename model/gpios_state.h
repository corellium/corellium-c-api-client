/*
 * gpios_state.h
 *
 * State of the simulated LEDs, buttons and switches on an IoT or embedded board model. Each group (&#x60;led&#x60;, &#x60;button&#x60;, &#x60;switch&#x60;) has one or more banks, and each bank is a list of bits: 1 is on (pressed, lit), 0 is off. Only board models that wire these up report them; phones (iOS and Android) do not.
 */

#ifndef _gpios_state_H_
#define _gpios_state_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct gpios_state_t gpios_state_t;

#include "gpio_state_definition.h"



typedef struct gpios_state_t {
    struct gpio_state_definition_t *led; //model
    struct gpio_state_definition_t *button; //model
    struct gpio_state_definition_t *_switch; //model

    int _library_owned; // Is the library responsible for freeing this object?
} gpios_state_t;

__attribute__((deprecated)) gpios_state_t *gpios_state_create(
    gpio_state_definition_t *led,
    gpio_state_definition_t *button,
    gpio_state_definition_t *_switch
);

void gpios_state_free(gpios_state_t *gpios_state);

gpios_state_t *gpios_state_parseFromJSON(cJSON *gpios_stateJSON);

cJSON *gpios_state_convertToJSON(gpios_state_t *gpios_state);

#endif /* _gpios_state_H_ */

