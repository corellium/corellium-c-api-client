/*
 * uncancel_subscription_body.h
 *
 * 
 */

#ifndef _uncancel_subscription_body_H_
#define _uncancel_subscription_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct uncancel_subscription_body_t uncancel_subscription_body_t;




typedef struct uncancel_subscription_body_t {
    char *domain_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} uncancel_subscription_body_t;

__attribute__((deprecated)) uncancel_subscription_body_t *uncancel_subscription_body_create(
    char *domain_id
);

void uncancel_subscription_body_free(uncancel_subscription_body_t *uncancel_subscription_body);

uncancel_subscription_body_t *uncancel_subscription_body_parseFromJSON(cJSON *uncancel_subscription_bodyJSON);

cJSON *uncancel_subscription_body_convertToJSON(uncancel_subscription_body_t *uncancel_subscription_body);

#endif /* _uncancel_subscription_body_H_ */

