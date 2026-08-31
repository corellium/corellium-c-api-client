/*
 * cluster_config_stripe.h
 *
 * 
 */

#ifndef _cluster_config_stripe_H_
#define _cluster_config_stripe_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cluster_config_stripe_t cluster_config_stripe_t;




typedef struct cluster_config_stripe_t {
    char *public_key; // string
    char *private_key; // string
    char *webhook_key; // string

    int _library_owned; // Is the library responsible for freeing this object?
} cluster_config_stripe_t;

__attribute__((deprecated)) cluster_config_stripe_t *cluster_config_stripe_create(
    char *public_key,
    char *private_key,
    char *webhook_key
);

void cluster_config_stripe_free(cluster_config_stripe_t *cluster_config_stripe);

cluster_config_stripe_t *cluster_config_stripe_parseFromJSON(cJSON *cluster_config_stripeJSON);

cJSON *cluster_config_stripe_convertToJSON(cluster_config_stripe_t *cluster_config_stripe);

#endif /* _cluster_config_stripe_H_ */

