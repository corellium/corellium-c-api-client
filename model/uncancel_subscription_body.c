#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "uncancel_subscription_body.h"



static uncancel_subscription_body_t *uncancel_subscription_body_create_internal(
    char *domain_id
    ) {
    uncancel_subscription_body_t *uncancel_subscription_body_local_var = malloc(sizeof(uncancel_subscription_body_t));
    if (!uncancel_subscription_body_local_var) {
        return NULL;
    }
    uncancel_subscription_body_local_var->domain_id = domain_id;

    uncancel_subscription_body_local_var->_library_owned = 1;
    return uncancel_subscription_body_local_var;
}

__attribute__((deprecated)) uncancel_subscription_body_t *uncancel_subscription_body_create(
    char *domain_id
    ) {
    return uncancel_subscription_body_create_internal (
        domain_id
        );
}

void uncancel_subscription_body_free(uncancel_subscription_body_t *uncancel_subscription_body) {
    if(NULL == uncancel_subscription_body){
        return ;
    }
    if(uncancel_subscription_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "uncancel_subscription_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (uncancel_subscription_body->domain_id) {
        free(uncancel_subscription_body->domain_id);
        uncancel_subscription_body->domain_id = NULL;
    }
    free(uncancel_subscription_body);
}

cJSON *uncancel_subscription_body_convertToJSON(uncancel_subscription_body_t *uncancel_subscription_body) {
    cJSON *item = cJSON_CreateObject();

    // uncancel_subscription_body->domain_id
    if(uncancel_subscription_body->domain_id) {
    if(cJSON_AddStringToObject(item, "domainId", uncancel_subscription_body->domain_id) == NULL) {
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

uncancel_subscription_body_t *uncancel_subscription_body_parseFromJSON(cJSON *uncancel_subscription_bodyJSON){

    uncancel_subscription_body_t *uncancel_subscription_body_local_var = NULL;

    // uncancel_subscription_body->domain_id
    cJSON *domain_id = cJSON_GetObjectItemCaseSensitive(uncancel_subscription_bodyJSON, "domainId");
    if (cJSON_IsNull(domain_id)) {
        domain_id = NULL;
    }
    if (domain_id) { 
    if(!cJSON_IsString(domain_id) && !cJSON_IsNull(domain_id))
    {
    goto end; //String
    }
    }


    uncancel_subscription_body_local_var = uncancel_subscription_body_create_internal (
        domain_id && !cJSON_IsNull(domain_id) ? strdup(domain_id->valuestring) : NULL
        );

    return uncancel_subscription_body_local_var;
end:
    return NULL;

}
