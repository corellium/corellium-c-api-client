#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "domain_welcome_message_response.h"



static domain_welcome_message_response_t *domain_welcome_message_response_create_internal(
    char *identifier,
    char *domain,
    char *message,
    int enabled,
    char *created_at,
    char *updated_at
    ) {
    domain_welcome_message_response_t *domain_welcome_message_response_local_var = malloc(sizeof(domain_welcome_message_response_t));
    if (!domain_welcome_message_response_local_var) {
        return NULL;
    }
    domain_welcome_message_response_local_var->identifier = identifier;
    domain_welcome_message_response_local_var->domain = domain;
    domain_welcome_message_response_local_var->message = message;
    domain_welcome_message_response_local_var->enabled = enabled;
    domain_welcome_message_response_local_var->created_at = created_at;
    domain_welcome_message_response_local_var->updated_at = updated_at;

    domain_welcome_message_response_local_var->_library_owned = 1;
    return domain_welcome_message_response_local_var;
}

__attribute__((deprecated)) domain_welcome_message_response_t *domain_welcome_message_response_create(
    char *identifier,
    char *domain,
    char *message,
    int enabled,
    char *created_at,
    char *updated_at
    ) {
    return domain_welcome_message_response_create_internal (
        identifier,
        domain,
        message,
        enabled,
        created_at,
        updated_at
        );
}

void domain_welcome_message_response_free(domain_welcome_message_response_t *domain_welcome_message_response) {
    if(NULL == domain_welcome_message_response){
        return ;
    }
    if(domain_welcome_message_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "domain_welcome_message_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (domain_welcome_message_response->identifier) {
        free(domain_welcome_message_response->identifier);
        domain_welcome_message_response->identifier = NULL;
    }
    if (domain_welcome_message_response->domain) {
        free(domain_welcome_message_response->domain);
        domain_welcome_message_response->domain = NULL;
    }
    if (domain_welcome_message_response->message) {
        free(domain_welcome_message_response->message);
        domain_welcome_message_response->message = NULL;
    }
    if (domain_welcome_message_response->created_at) {
        free(domain_welcome_message_response->created_at);
        domain_welcome_message_response->created_at = NULL;
    }
    if (domain_welcome_message_response->updated_at) {
        free(domain_welcome_message_response->updated_at);
        domain_welcome_message_response->updated_at = NULL;
    }
    free(domain_welcome_message_response);
}

cJSON *domain_welcome_message_response_convertToJSON(domain_welcome_message_response_t *domain_welcome_message_response) {
    cJSON *item = cJSON_CreateObject();

    // domain_welcome_message_response->identifier
    if (!domain_welcome_message_response->identifier) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "identifier", domain_welcome_message_response->identifier) == NULL) {
    goto fail; //String
    }


    // domain_welcome_message_response->domain
    if (!domain_welcome_message_response->domain) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "domain", domain_welcome_message_response->domain) == NULL) {
    goto fail; //String
    }


    // domain_welcome_message_response->message
    if (!domain_welcome_message_response->message) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message", domain_welcome_message_response->message) == NULL) {
    goto fail; //String
    }


    // domain_welcome_message_response->enabled
    if (!domain_welcome_message_response->enabled) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "enabled", domain_welcome_message_response->enabled) == NULL) {
    goto fail; //Bool
    }


    // domain_welcome_message_response->created_at
    if (!domain_welcome_message_response->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "createdAt", domain_welcome_message_response->created_at) == NULL) {
    goto fail; //Date-Time
    }


    // domain_welcome_message_response->updated_at
    if (!domain_welcome_message_response->updated_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "updatedAt", domain_welcome_message_response->updated_at) == NULL) {
    goto fail; //Date-Time
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

domain_welcome_message_response_t *domain_welcome_message_response_parseFromJSON(cJSON *domain_welcome_message_responseJSON){

    domain_welcome_message_response_t *domain_welcome_message_response_local_var = NULL;

    // domain_welcome_message_response->identifier
    cJSON *identifier = cJSON_GetObjectItemCaseSensitive(domain_welcome_message_responseJSON, "identifier");
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

    // domain_welcome_message_response->domain
    cJSON *domain = cJSON_GetObjectItemCaseSensitive(domain_welcome_message_responseJSON, "domain");
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

    // domain_welcome_message_response->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(domain_welcome_message_responseJSON, "message");
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

    // domain_welcome_message_response->enabled
    cJSON *enabled = cJSON_GetObjectItemCaseSensitive(domain_welcome_message_responseJSON, "enabled");
    if (cJSON_IsNull(enabled)) {
        enabled = NULL;
    }
    if (!enabled) {
        goto end;
    }

    
    if(!cJSON_IsBool(enabled))
    {
    goto end; //Bool
    }

    // domain_welcome_message_response->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(domain_welcome_message_responseJSON, "createdAt");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (!created_at) {
        goto end;
    }

    
    if(!cJSON_IsString(created_at) && !cJSON_IsNull(created_at))
    {
    goto end; //DateTime
    }

    // domain_welcome_message_response->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(domain_welcome_message_responseJSON, "updatedAt");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (!updated_at) {
        goto end;
    }

    
    if(!cJSON_IsString(updated_at) && !cJSON_IsNull(updated_at))
    {
    goto end; //DateTime
    }


    domain_welcome_message_response_local_var = domain_welcome_message_response_create_internal (
        strdup(identifier->valuestring),
        strdup(domain->valuestring),
        strdup(message->valuestring),
        enabled->valueint,
        strdup(created_at->valuestring),
        strdup(updated_at->valuestring)
        );

    return domain_welcome_message_response_local_var;
end:
    return NULL;

}
