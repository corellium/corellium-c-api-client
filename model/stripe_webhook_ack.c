#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "stripe_webhook_ack.h"



static stripe_webhook_ack_t *stripe_webhook_ack_create_internal(
    int received,
    char *ignored
    ) {
    stripe_webhook_ack_t *stripe_webhook_ack_local_var = malloc(sizeof(stripe_webhook_ack_t));
    if (!stripe_webhook_ack_local_var) {
        return NULL;
    }
    stripe_webhook_ack_local_var->received = received;
    stripe_webhook_ack_local_var->ignored = ignored;

    stripe_webhook_ack_local_var->_library_owned = 1;
    return stripe_webhook_ack_local_var;
}

__attribute__((deprecated)) stripe_webhook_ack_t *stripe_webhook_ack_create(
    int received,
    char *ignored
    ) {
    return stripe_webhook_ack_create_internal (
        received,
        ignored
        );
}

void stripe_webhook_ack_free(stripe_webhook_ack_t *stripe_webhook_ack) {
    if(NULL == stripe_webhook_ack){
        return ;
    }
    if(stripe_webhook_ack->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "stripe_webhook_ack_free");
        return ;
    }
    listEntry_t *listEntry;
    if (stripe_webhook_ack->ignored) {
        free(stripe_webhook_ack->ignored);
        stripe_webhook_ack->ignored = NULL;
    }
    free(stripe_webhook_ack);
}

cJSON *stripe_webhook_ack_convertToJSON(stripe_webhook_ack_t *stripe_webhook_ack) {
    cJSON *item = cJSON_CreateObject();

    // stripe_webhook_ack->received
    if (!stripe_webhook_ack->received) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "received", stripe_webhook_ack->received) == NULL) {
    goto fail; //Bool
    }


    // stripe_webhook_ack->ignored
    if(stripe_webhook_ack->ignored) {
    if(cJSON_AddStringToObject(item, "ignored", stripe_webhook_ack->ignored) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

stripe_webhook_ack_t *stripe_webhook_ack_parseFromJSON(cJSON *stripe_webhook_ackJSON){

    stripe_webhook_ack_t *stripe_webhook_ack_local_var = NULL;

    // stripe_webhook_ack->received
    cJSON *received = cJSON_GetObjectItemCaseSensitive(stripe_webhook_ackJSON, "received");
    if (cJSON_IsNull(received)) {
        received = NULL;
    }
    if (!received) {
        goto end;
    }

    
    if(!cJSON_IsBool(received))
    {
    goto end; //Bool
    }

    // stripe_webhook_ack->ignored
    cJSON *ignored = cJSON_GetObjectItemCaseSensitive(stripe_webhook_ackJSON, "ignored");
    if (cJSON_IsNull(ignored)) {
        ignored = NULL;
    }
    if (ignored) { 
    if(!cJSON_IsString(ignored) && !cJSON_IsNull(ignored))
    {
    goto end; //String
    }
    }


    stripe_webhook_ack_local_var = stripe_webhook_ack_create_internal (
        received->valueint,
        ignored && !cJSON_IsNull(ignored) ? strdup(ignored->valuestring) : NULL
        );

    return stripe_webhook_ack_local_var;
end:
    return NULL;

}
