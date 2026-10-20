/*
 * cluster_config_coordinator_config_aws_marketplace.h
 *
 * 
 */

#ifndef _cluster_config_coordinator_config_aws_marketplace_H_
#define _cluster_config_coordinator_config_aws_marketplace_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cluster_config_coordinator_config_aws_marketplace_t cluster_config_coordinator_config_aws_marketplace_t;

#include "any_type.h"
#include "object.h"



typedef struct cluster_config_coordinator_config_aws_marketplace_t {
    char *suger_token; // string
    char *suger_webhook_secret; // string
    char *suger_api_client_secret; // string
    object_t *suger_stripe_mapping; //object

    int _library_owned; // Is the library responsible for freeing this object?
} cluster_config_coordinator_config_aws_marketplace_t;

__attribute__((deprecated)) cluster_config_coordinator_config_aws_marketplace_t *cluster_config_coordinator_config_aws_marketplace_create(
    char *suger_token,
    char *suger_webhook_secret,
    char *suger_api_client_secret,
    object_t *suger_stripe_mapping
);

void cluster_config_coordinator_config_aws_marketplace_free(cluster_config_coordinator_config_aws_marketplace_t *cluster_config_coordinator_config_aws_marketplace);

cluster_config_coordinator_config_aws_marketplace_t *cluster_config_coordinator_config_aws_marketplace_parseFromJSON(cJSON *cluster_config_coordinator_config_aws_marketplaceJSON);

cJSON *cluster_config_coordinator_config_aws_marketplace_convertToJSON(cluster_config_coordinator_config_aws_marketplace_t *cluster_config_coordinator_config_aws_marketplace);

#endif /* _cluster_config_coordinator_config_aws_marketplace_H_ */

