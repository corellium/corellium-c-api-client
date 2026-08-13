#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cancel_subscription_body.h"



static cancel_subscription_body_t *cancel_subscription_body_create_internal(
    char *domain_id,
    int delete_domain
    ) {
    cancel_subscription_body_t *cancel_subscription_body_local_var = malloc(sizeof(cancel_subscription_body_t));
    if (!cancel_subscription_body_local_var) {
        return NULL;
    }
    cancel_subscription_body_local_var->domain_id = domain_id;
    cancel_subscription_body_local_var->delete_domain = delete_domain;

    cancel_subscription_body_local_var->_library_owned = 1;
    return cancel_subscription_body_local_var;
}

__attribute__((deprecated)) cancel_subscription_body_t *cancel_subscription_body_create(
    char *domain_id,
    int delete_domain
    ) {
    return cancel_subscription_body_create_internal (
        domain_id,
        delete_domain
        );
}

void cancel_subscription_body_free(cancel_subscription_body_t *cancel_subscription_body) {
    if(NULL == cancel_subscription_body){
        return ;
    }
    if(cancel_subscription_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cancel_subscription_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cancel_subscription_body->domain_id) {
        free(cancel_subscription_body->domain_id);
        cancel_subscription_body->domain_id = NULL;
    }
    free(cancel_subscription_body);
}

cJSON *cancel_subscription_body_convertToJSON(cancel_subscription_body_t *cancel_subscription_body) {
    cJSON *item = cJSON_CreateObject();

    // cancel_subscription_body->domain_id
    if(cancel_subscription_body->domain_id) {
    if(cJSON_AddStringToObject(item, "domainId", cancel_subscription_body->domain_id) == NULL) {
    goto fail; //String
    }
    }


    // cancel_subscription_body->delete_domain
    if(cancel_subscription_body->delete_domain) {
    if(cJSON_AddBoolToObject(item, "deleteDomain", cancel_subscription_body->delete_domain) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

cancel_subscription_body_t *cancel_subscription_body_parseFromJSON(cJSON *cancel_subscription_bodyJSON){

    cancel_subscription_body_t *cancel_subscription_body_local_var = NULL;

    // cancel_subscription_body->domain_id
    cJSON *domain_id = cJSON_GetObjectItemCaseSensitive(cancel_subscription_bodyJSON, "domainId");
    if (cJSON_IsNull(domain_id)) {
        domain_id = NULL;
    }
    if (domain_id) { 
    if(!cJSON_IsString(domain_id) && !cJSON_IsNull(domain_id))
    {
    goto end; //String
    }
    }

    // cancel_subscription_body->delete_domain
    cJSON *delete_domain = cJSON_GetObjectItemCaseSensitive(cancel_subscription_bodyJSON, "deleteDomain");
    if (cJSON_IsNull(delete_domain)) {
        delete_domain = NULL;
    }
    if (delete_domain) { 
    if(!cJSON_IsBool(delete_domain))
    {
    goto end; //Bool
    }
    }


    cancel_subscription_body_local_var = cancel_subscription_body_create_internal (
        domain_id && !cJSON_IsNull(domain_id) ? strdup(domain_id->valuestring) : NULL,
        delete_domain ? delete_domain->valueint : 0
        );

    return cancel_subscription_body_local_var;
end:
    return NULL;

}
