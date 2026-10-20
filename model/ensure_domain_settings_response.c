#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ensure_domain_settings_response.h"



static ensure_domain_settings_response_t *ensure_domain_settings_response_create_internal(
    int created,
    char *identifier,
    ensure_domain_settings_response_user_t *user
    ) {
    ensure_domain_settings_response_t *ensure_domain_settings_response_local_var = malloc(sizeof(ensure_domain_settings_response_t));
    if (!ensure_domain_settings_response_local_var) {
        return NULL;
    }
    ensure_domain_settings_response_local_var->created = created;
    ensure_domain_settings_response_local_var->identifier = identifier;
    ensure_domain_settings_response_local_var->user = user;

    ensure_domain_settings_response_local_var->_library_owned = 1;
    return ensure_domain_settings_response_local_var;
}

__attribute__((deprecated)) ensure_domain_settings_response_t *ensure_domain_settings_response_create(
    int created,
    char *identifier,
    ensure_domain_settings_response_user_t *user
    ) {
    return ensure_domain_settings_response_create_internal (
        created,
        identifier,
        user
        );
}

void ensure_domain_settings_response_free(ensure_domain_settings_response_t *ensure_domain_settings_response) {
    if(NULL == ensure_domain_settings_response){
        return ;
    }
    if(ensure_domain_settings_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ensure_domain_settings_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ensure_domain_settings_response->identifier) {
        free(ensure_domain_settings_response->identifier);
        ensure_domain_settings_response->identifier = NULL;
    }
    if (ensure_domain_settings_response->user) {
        ensure_domain_settings_response_user_free(ensure_domain_settings_response->user);
        ensure_domain_settings_response->user = NULL;
    }
    free(ensure_domain_settings_response);
}

cJSON *ensure_domain_settings_response_convertToJSON(ensure_domain_settings_response_t *ensure_domain_settings_response) {
    cJSON *item = cJSON_CreateObject();

    // ensure_domain_settings_response->created
    if (!ensure_domain_settings_response->created) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "created", ensure_domain_settings_response->created) == NULL) {
    goto fail; //Bool
    }


    // ensure_domain_settings_response->identifier
    if (!ensure_domain_settings_response->identifier) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "identifier", ensure_domain_settings_response->identifier) == NULL) {
    goto fail; //String
    }


    // ensure_domain_settings_response->user
    if (!ensure_domain_settings_response->user) {
        goto fail;
    }
    cJSON *user_local_JSON = ensure_domain_settings_response_user_convertToJSON(ensure_domain_settings_response->user);
    if(user_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "user", user_local_JSON);
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

ensure_domain_settings_response_t *ensure_domain_settings_response_parseFromJSON(cJSON *ensure_domain_settings_responseJSON){

    ensure_domain_settings_response_t *ensure_domain_settings_response_local_var = NULL;

    // define the local variable for ensure_domain_settings_response->user
    ensure_domain_settings_response_user_t *user_local_nonprim = NULL;

    // ensure_domain_settings_response->created
    cJSON *created = cJSON_GetObjectItemCaseSensitive(ensure_domain_settings_responseJSON, "created");
    if (cJSON_IsNull(created)) {
        created = NULL;
    }
    if (!created) {
        goto end;
    }

    
    if(!cJSON_IsBool(created))
    {
    goto end; //Bool
    }

    // ensure_domain_settings_response->identifier
    cJSON *identifier = cJSON_GetObjectItemCaseSensitive(ensure_domain_settings_responseJSON, "identifier");
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

    // ensure_domain_settings_response->user
    cJSON *user = cJSON_GetObjectItemCaseSensitive(ensure_domain_settings_responseJSON, "user");
    if (cJSON_IsNull(user)) {
        user = NULL;
    }
    if (!user) {
        goto end;
    }

    
    user_local_nonprim = ensure_domain_settings_response_user_parseFromJSON(user); //nonprimitive


    ensure_domain_settings_response_local_var = ensure_domain_settings_response_create_internal (
        created->valueint,
        strdup(identifier->valuestring),
        user_local_nonprim
        );

    return ensure_domain_settings_response_local_var;
end:
    if (user_local_nonprim) {
        ensure_domain_settings_response_user_free(user_local_nonprim);
        user_local_nonprim = NULL;
    }
    return NULL;

}
