/*
 * stripe_checkout_body.h
 *
 * 
 */

#ifndef _stripe_checkout_body_H_
#define _stripe_checkout_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct stripe_checkout_body_t stripe_checkout_body_t;




typedef struct stripe_checkout_body_t {
    int terms_of_service; //boolean
    char *email; // string
    char *name; // string
    char *domain; // string
    double cores; //numeric
    char *license_type; // string
    int existing_domain; //boolean
    char *price_id; // string
    char *coupon_code; // string

    int _library_owned; // Is the library responsible for freeing this object?
} stripe_checkout_body_t;

__attribute__((deprecated)) stripe_checkout_body_t *stripe_checkout_body_create(
    int terms_of_service,
    char *email,
    char *name,
    char *domain,
    double cores,
    char *license_type,
    int existing_domain,
    char *price_id,
    char *coupon_code
);

void stripe_checkout_body_free(stripe_checkout_body_t *stripe_checkout_body);

stripe_checkout_body_t *stripe_checkout_body_parseFromJSON(cJSON *stripe_checkout_bodyJSON);

cJSON *stripe_checkout_body_convertToJSON(stripe_checkout_body_t *stripe_checkout_body);

#endif /* _stripe_checkout_body_H_ */

