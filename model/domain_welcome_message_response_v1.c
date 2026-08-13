#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "domain_welcome_message_response_v1.h"



static domain_welcome_message_response_v1_t *domain_welcome_message_response_v1_create_internal(
    char *identifier,
    char *domain,
    char *message,
    char *created_at,
    char *updated_at
    ) {
    domain_welcome_message_response_v1_t *domain_welcome_message_response_v1_local_var = malloc(sizeof(domain_welcome_message_response_v1_t));
    if (!domain_welcome_message_response_v1_local_var) {
        return NULL;
    }
    domain_welcome_message_response_v1_local_var->identifier = identifier;
    domain_welcome_message_response_v1_local_var->domain = domain;
    domain_welcome_message_response_v1_local_var->message = message;
    domain_welcome_message_response_v1_local_var->created_at = created_at;
    domain_welcome_message_response_v1_local_var->updated_at = updated_at;

    domain_welcome_message_response_v1_local_var->_library_owned = 1;
    return domain_welcome_message_response_v1_local_var;
}

__attribute__((deprecated)) domain_welcome_message_response_v1_t *domain_welcome_message_response_v1_create(
    char *identifier,
    char *domain,
    char *message,
    char *created_at,
    char *updated_at
    ) {
    return domain_welcome_message_response_v1_create_internal (
        identifier,
        domain,
        message,
        created_at,
        updated_at
        );
}

void domain_welcome_message_response_v1_free(domain_welcome_message_response_v1_t *domain_welcome_message_response_v1) {
    if(NULL == domain_welcome_message_response_v1){
        return ;
    }
    if(domain_welcome_message_response_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "domain_welcome_message_response_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (domain_welcome_message_response_v1->identifier) {
        free(domain_welcome_message_response_v1->identifier);
        domain_welcome_message_response_v1->identifier = NULL;
    }
    if (domain_welcome_message_response_v1->domain) {
        free(domain_welcome_message_response_v1->domain);
        domain_welcome_message_response_v1->domain = NULL;
    }
    if (domain_welcome_message_response_v1->message) {
        free(domain_welcome_message_response_v1->message);
        domain_welcome_message_response_v1->message = NULL;
    }
    if (domain_welcome_message_response_v1->created_at) {
        free(domain_welcome_message_response_v1->created_at);
        domain_welcome_message_response_v1->created_at = NULL;
    }
    if (domain_welcome_message_response_v1->updated_at) {
        free(domain_welcome_message_response_v1->updated_at);
        domain_welcome_message_response_v1->updated_at = NULL;
    }
    free(domain_welcome_message_response_v1);
}

cJSON *domain_welcome_message_response_v1_convertToJSON(domain_welcome_message_response_v1_t *domain_welcome_message_response_v1) {
    cJSON *item = cJSON_CreateObject();

    // domain_welcome_message_response_v1->identifier
    if (!domain_welcome_message_response_v1->identifier) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "identifier", domain_welcome_message_response_v1->identifier) == NULL) {
    goto fail; //String
    }


    // domain_welcome_message_response_v1->domain
    if (!domain_welcome_message_response_v1->domain) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "domain", domain_welcome_message_response_v1->domain) == NULL) {
    goto fail; //String
    }


    // domain_welcome_message_response_v1->message
    if (!domain_welcome_message_response_v1->message) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message", domain_welcome_message_response_v1->message) == NULL) {
    goto fail; //String
    }


    // domain_welcome_message_response_v1->created_at
    if (!domain_welcome_message_response_v1->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "createdAt", domain_welcome_message_response_v1->created_at) == NULL) {
    goto fail; //String
    }


    // domain_welcome_message_response_v1->updated_at
    if (!domain_welcome_message_response_v1->updated_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "updatedAt", domain_welcome_message_response_v1->updated_at) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

domain_welcome_message_response_v1_t *domain_welcome_message_response_v1_parseFromJSON(cJSON *domain_welcome_message_response_v1JSON){

    domain_welcome_message_response_v1_t *domain_welcome_message_response_v1_local_var = NULL;

    // domain_welcome_message_response_v1->identifier
    cJSON *identifier = cJSON_GetObjectItemCaseSensitive(domain_welcome_message_response_v1JSON, "identifier");
    if (cJSON_IsNull(identifier)) {
        identifier = NULL;
    }
    if (!identifier) {
        goto end;
    }

    
    if(!cJSON_IsString(identifier))
    {
    goto end; //String
    }

    // domain_welcome_message_response_v1->domain
    cJSON *domain = cJSON_GetObjectItemCaseSensitive(domain_welcome_message_response_v1JSON, "domain");
    if (cJSON_IsNull(domain)) {
        domain = NULL;
    }
    if (!domain) {
        goto end;
    }

    
    if(!cJSON_IsString(domain))
    {
    goto end; //String
    }

    // domain_welcome_message_response_v1->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(domain_welcome_message_response_v1JSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (!message) {
        goto end;
    }

    
    if(!cJSON_IsString(message))
    {
    goto end; //String
    }

    // domain_welcome_message_response_v1->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(domain_welcome_message_response_v1JSON, "createdAt");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (!created_at) {
        goto end;
    }

    
    if(!cJSON_IsString(created_at))
    {
    goto end; //String
    }

    // domain_welcome_message_response_v1->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(domain_welcome_message_response_v1JSON, "updatedAt");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (!updated_at) {
        goto end;
    }

    
    if(!cJSON_IsString(updated_at))
    {
    goto end; //String
    }


    domain_welcome_message_response_v1_local_var = domain_welcome_message_response_v1_create_internal (
        strdup(identifier->valuestring),
        strdup(domain->valuestring),
        strdup(message->valuestring),
        strdup(created_at->valuestring),
        strdup(updated_at->valuestring)
        );

    return domain_welcome_message_response_v1_local_var;
end:
    return NULL;

}
