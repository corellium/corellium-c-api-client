/*
 * stripe_webhook_ack.h
 *
 * 
 */

#ifndef _stripe_webhook_ack_H_
#define _stripe_webhook_ack_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct stripe_webhook_ack_t stripe_webhook_ack_t;




typedef struct stripe_webhook_ack_t {
    int received; //boolean
    char *ignored; // string

    int _library_owned; // Is the library responsible for freeing this object?
} stripe_webhook_ack_t;

__attribute__((deprecated)) stripe_webhook_ack_t *stripe_webhook_ack_create(
    int received,
    char *ignored
);

void stripe_webhook_ack_free(stripe_webhook_ack_t *stripe_webhook_ack);

stripe_webhook_ack_t *stripe_webhook_ack_parseFromJSON(cJSON *stripe_webhook_ackJSON);

cJSON *stripe_webhook_ack_convertToJSON(stripe_webhook_ack_t *stripe_webhook_ack);

#endif /* _stripe_webhook_ack_H_ */

