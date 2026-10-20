#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cluster_config_coordinator_config_aws_marketplace.h"



static cluster_config_coordinator_config_aws_marketplace_t *cluster_config_coordinator_config_aws_marketplace_create_internal(
    char *suger_token,
    char *suger_webhook_secret,
    char *suger_api_client_secret,
    object_t *suger_stripe_mapping
    ) {
    cluster_config_coordinator_config_aws_marketplace_t *cluster_config_coordinator_config_aws_marketplace_local_var = malloc(sizeof(cluster_config_coordinator_config_aws_marketplace_t));
    if (!cluster_config_coordinator_config_aws_marketplace_local_var) {
        return NULL;
    }
    cluster_config_coordinator_config_aws_marketplace_local_var->suger_token = suger_token;
    cluster_config_coordinator_config_aws_marketplace_local_var->suger_webhook_secret = suger_webhook_secret;
    cluster_config_coordinator_config_aws_marketplace_local_var->suger_api_client_secret = suger_api_client_secret;
    cluster_config_coordinator_config_aws_marketplace_local_var->suger_stripe_mapping = suger_stripe_mapping;

    cluster_config_coordinator_config_aws_marketplace_local_var->_library_owned = 1;
    return cluster_config_coordinator_config_aws_marketplace_local_var;
}

__attribute__((deprecated)) cluster_config_coordinator_config_aws_marketplace_t *cluster_config_coordinator_config_aws_marketplace_create(
    char *suger_token,
    char *suger_webhook_secret,
    char *suger_api_client_secret,
    object_t *suger_stripe_mapping
    ) {
    return cluster_config_coordinator_config_aws_marketplace_create_internal (
        suger_token,
        suger_webhook_secret,
        suger_api_client_secret,
        suger_stripe_mapping
        );
}

void cluster_config_coordinator_config_aws_marketplace_free(cluster_config_coordinator_config_aws_marketplace_t *cluster_config_coordinator_config_aws_marketplace) {
    if(NULL == cluster_config_coordinator_config_aws_marketplace){
        return ;
    }
    if(cluster_config_coordinator_config_aws_marketplace->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cluster_config_coordinator_config_aws_marketplace_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cluster_config_coordinator_config_aws_marketplace->suger_token) {
        free(cluster_config_coordinator_config_aws_marketplace->suger_token);
        cluster_config_coordinator_config_aws_marketplace->suger_token = NULL;
    }
    if (cluster_config_coordinator_config_aws_marketplace->suger_webhook_secret) {
        free(cluster_config_coordinator_config_aws_marketplace->suger_webhook_secret);
        cluster_config_coordinator_config_aws_marketplace->suger_webhook_secret = NULL;
    }
    if (cluster_config_coordinator_config_aws_marketplace->suger_api_client_secret) {
        free(cluster_config_coordinator_config_aws_marketplace->suger_api_client_secret);
        cluster_config_coordinator_config_aws_marketplace->suger_api_client_secret = NULL;
    }
    if (cluster_config_coordinator_config_aws_marketplace->suger_stripe_mapping) {
        object_free(cluster_config_coordinator_config_aws_marketplace->suger_stripe_mapping);
        cluster_config_coordinator_config_aws_marketplace->suger_stripe_mapping = NULL;
    }
    free(cluster_config_coordinator_config_aws_marketplace);
}

cJSON *cluster_config_coordinator_config_aws_marketplace_convertToJSON(cluster_config_coordinator_config_aws_marketplace_t *cluster_config_coordinator_config_aws_marketplace) {
    cJSON *item = cJSON_CreateObject();

    // cluster_config_coordinator_config_aws_marketplace->suger_token
    if (!cluster_config_coordinator_config_aws_marketplace->suger_token) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sugerToken", cluster_config_coordinator_config_aws_marketplace->suger_token) == NULL) {
    goto fail; //String
    }


    // cluster_config_coordinator_config_aws_marketplace->suger_webhook_secret
    if (!cluster_config_coordinator_config_aws_marketplace->suger_webhook_secret) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sugerWebhookSecret", cluster_config_coordinator_config_aws_marketplace->suger_webhook_secret) == NULL) {
    goto fail; //String
    }


    // cluster_config_coordinator_config_aws_marketplace->suger_api_client_secret
    if (!cluster_config_coordinator_config_aws_marketplace->suger_api_client_secret) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sugerAPIClientSecret", cluster_config_coordinator_config_aws_marketplace->suger_api_client_secret) == NULL) {
    goto fail; //String
    }


    // cluster_config_coordinator_config_aws_marketplace->suger_stripe_mapping
    if (!cluster_config_coordinator_config_aws_marketplace->suger_stripe_mapping) {
        goto fail;
    }
    cJSON *suger_stripe_mapping_object = object_convertToJSON(cluster_config_coordinator_config_aws_marketplace->suger_stripe_mapping);
    if(suger_stripe_mapping_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "sugerStripeMapping", suger_stripe_mapping_object);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

cluster_config_coordinator_config_aws_marketplace_t *cluster_config_coordinator_config_aws_marketplace_parseFromJSON(cJSON *cluster_config_coordinator_config_aws_marketplaceJSON){

    cluster_config_coordinator_config_aws_marketplace_t *cluster_config_coordinator_config_aws_marketplace_local_var = NULL;

    // cluster_config_coordinator_config_aws_marketplace->suger_token
    cJSON *suger_token = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_config_aws_marketplaceJSON, "sugerToken");
    if (cJSON_IsNull(suger_token)) {
        suger_token = NULL;
    }
    if (!suger_token) {
        goto end;
    }

    
    if(!cJSON_IsString(suger_token))
    {
    goto end; //String
    }

    // cluster_config_coordinator_config_aws_marketplace->suger_webhook_secret
    cJSON *suger_webhook_secret = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_config_aws_marketplaceJSON, "sugerWebhookSecret");
    if (cJSON_IsNull(suger_webhook_secret)) {
        suger_webhook_secret = NULL;
    }
    if (!suger_webhook_secret) {
        goto end;
    }

    
    if(!cJSON_IsString(suger_webhook_secret))
    {
    goto end; //String
    }

    // cluster_config_coordinator_config_aws_marketplace->suger_api_client_secret
    cJSON *suger_api_client_secret = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_config_aws_marketplaceJSON, "sugerAPIClientSecret");
    if (cJSON_IsNull(suger_api_client_secret)) {
        suger_api_client_secret = NULL;
    }
    if (!suger_api_client_secret) {
        goto end;
    }

    
    if(!cJSON_IsString(suger_api_client_secret))
    {
    goto end; //String
    }

    // cluster_config_coordinator_config_aws_marketplace->suger_stripe_mapping
    cJSON *suger_stripe_mapping = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_config_aws_marketplaceJSON, "sugerStripeMapping");
    if (cJSON_IsNull(suger_stripe_mapping)) {
        suger_stripe_mapping = NULL;
    }
    if (!suger_stripe_mapping) {
        goto end;
    }

    object_t *suger_stripe_mapping_local_object = NULL;
    
    suger_stripe_mapping_local_object = object_parseFromJSON(suger_stripe_mapping); //object


    cluster_config_coordinator_config_aws_marketplace_local_var = cluster_config_coordinator_config_aws_marketplace_create_internal (
        strdup(suger_token->valuestring),
        strdup(suger_webhook_secret->valuestring),
        strdup(suger_api_client_secret->valuestring),
        suger_stripe_mapping_local_object
        );

    return cluster_config_coordinator_config_aws_marketplace_local_var;
end:
    return NULL;

}
