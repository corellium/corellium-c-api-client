#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cluster_config_stripe.h"



static cluster_config_stripe_t *cluster_config_stripe_create_internal(
    char *public_key,
    char *private_key,
    char *webhook_key
    ) {
    cluster_config_stripe_t *cluster_config_stripe_local_var = malloc(sizeof(cluster_config_stripe_t));
    if (!cluster_config_stripe_local_var) {
        return NULL;
    }
    cluster_config_stripe_local_var->public_key = public_key;
    cluster_config_stripe_local_var->private_key = private_key;
    cluster_config_stripe_local_var->webhook_key = webhook_key;

    cluster_config_stripe_local_var->_library_owned = 1;
    return cluster_config_stripe_local_var;
}

__attribute__((deprecated)) cluster_config_stripe_t *cluster_config_stripe_create(
    char *public_key,
    char *private_key,
    char *webhook_key
    ) {
    return cluster_config_stripe_create_internal (
        public_key,
        private_key,
        webhook_key
        );
}

void cluster_config_stripe_free(cluster_config_stripe_t *cluster_config_stripe) {
    if(NULL == cluster_config_stripe){
        return ;
    }
    if(cluster_config_stripe->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cluster_config_stripe_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cluster_config_stripe->public_key) {
        free(cluster_config_stripe->public_key);
        cluster_config_stripe->public_key = NULL;
    }
    if (cluster_config_stripe->private_key) {
        free(cluster_config_stripe->private_key);
        cluster_config_stripe->private_key = NULL;
    }
    if (cluster_config_stripe->webhook_key) {
        free(cluster_config_stripe->webhook_key);
        cluster_config_stripe->webhook_key = NULL;
    }
    free(cluster_config_stripe);
}

cJSON *cluster_config_stripe_convertToJSON(cluster_config_stripe_t *cluster_config_stripe) {
    cJSON *item = cJSON_CreateObject();

    // cluster_config_stripe->public_key
    if (!cluster_config_stripe->public_key) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "publicKey", cluster_config_stripe->public_key) == NULL) {
    goto fail; //String
    }


    // cluster_config_stripe->private_key
    if (!cluster_config_stripe->private_key) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "privateKey", cluster_config_stripe->private_key) == NULL) {
    goto fail; //String
    }


    // cluster_config_stripe->webhook_key
    if (!cluster_config_stripe->webhook_key) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "webhookKey", cluster_config_stripe->webhook_key) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

cluster_config_stripe_t *cluster_config_stripe_parseFromJSON(cJSON *cluster_config_stripeJSON){

    cluster_config_stripe_t *cluster_config_stripe_local_var = NULL;

    // cluster_config_stripe->public_key
    cJSON *public_key = cJSON_GetObjectItemCaseSensitive(cluster_config_stripeJSON, "publicKey");
    if (cJSON_IsNull(public_key)) {
        public_key = NULL;
    }
    if (!public_key) {
        goto end;
    }

    
    if(!cJSON_IsString(public_key))
    {
    goto end; //String
    }

    // cluster_config_stripe->private_key
    cJSON *private_key = cJSON_GetObjectItemCaseSensitive(cluster_config_stripeJSON, "privateKey");
    if (cJSON_IsNull(private_key)) {
        private_key = NULL;
    }
    if (!private_key) {
        goto end;
    }

    
    if(!cJSON_IsString(private_key))
    {
    goto end; //String
    }

    // cluster_config_stripe->webhook_key
    cJSON *webhook_key = cJSON_GetObjectItemCaseSensitive(cluster_config_stripeJSON, "webhookKey");
    if (cJSON_IsNull(webhook_key)) {
        webhook_key = NULL;
    }
    if (!webhook_key) {
        goto end;
    }

    
    if(!cJSON_IsString(webhook_key))
    {
    goto end; //String
    }


    cluster_config_stripe_local_var = cluster_config_stripe_create_internal (
        strdup(public_key->valuestring),
        strdup(private_key->valuestring),
        strdup(webhook_key->valuestring)
        );

    return cluster_config_stripe_local_var;
end:
    return NULL;

}
