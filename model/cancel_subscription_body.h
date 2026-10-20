/*
 * cancel_subscription_body.h
 *
 * 
 */

#ifndef _cancel_subscription_body_H_
#define _cancel_subscription_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cancel_subscription_body_t cancel_subscription_body_t;




typedef struct cancel_subscription_body_t {
    char *domain_id; // string
    int delete_domain; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} cancel_subscription_body_t;

__attribute__((deprecated)) cancel_subscription_body_t *cancel_subscription_body_create(
    char *domain_id,
    int delete_domain
);

void cancel_subscription_body_free(cancel_subscription_body_t *cancel_subscription_body);

cancel_subscription_body_t *cancel_subscription_body_parseFromJSON(cJSON *cancel_subscription_bodyJSON);

cJSON *cancel_subscription_body_convertToJSON(cancel_subscription_body_t *cancel_subscription_body);

#endif /* _cancel_subscription_body_H_ */

