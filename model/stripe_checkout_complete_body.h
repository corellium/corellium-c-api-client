/*
 * stripe_checkout_complete_body.h
 *
 * 
 */

#ifndef _stripe_checkout_complete_body_H_
#define _stripe_checkout_complete_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct stripe_checkout_complete_body_t stripe_checkout_complete_body_t;




typedef struct stripe_checkout_complete_body_t {
    char *session_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} stripe_checkout_complete_body_t;

__attribute__((deprecated)) stripe_checkout_complete_body_t *stripe_checkout_complete_body_create(
    char *session_id
);

void stripe_checkout_complete_body_free(stripe_checkout_complete_body_t *stripe_checkout_complete_body);

stripe_checkout_complete_body_t *stripe_checkout_complete_body_parseFromJSON(cJSON *stripe_checkout_complete_bodyJSON);

cJSON *stripe_checkout_complete_body_convertToJSON(stripe_checkout_complete_body_t *stripe_checkout_complete_body);

#endif /* _stripe_checkout_complete_body_H_ */

