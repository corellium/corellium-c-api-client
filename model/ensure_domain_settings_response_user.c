#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ensure_domain_settings_response_user.h"



static ensure_domain_settings_response_user_t *ensure_domain_settings_response_user_create_internal(
    char *identifier,
    int created
    ) {
    ensure_domain_settings_response_user_t *ensure_domain_settings_response_user_local_var = malloc(sizeof(ensure_domain_settings_response_user_t));
    if (!ensure_domain_settings_response_user_local_var) {
        return NULL;
    }
    ensure_domain_settings_response_user_local_var->identifier = identifier;
    ensure_domain_settings_response_user_local_var->created = created;

    ensure_domain_settings_response_user_local_var->_library_owned = 1;
    return ensure_domain_settings_response_user_local_var;
}

__attribute__((deprecated)) ensure_domain_settings_response_user_t *ensure_domain_settings_response_user_create(
    char *identifier,
    int created
    ) {
    return ensure_domain_settings_response_user_create_internal (
        identifier,
        created
        );
}

void ensure_domain_settings_response_user_free(ensure_domain_settings_response_user_t *ensure_domain_settings_response_user) {
    if(NULL == ensure_domain_settings_response_user){
        return ;
    }
    if(ensure_domain_settings_response_user->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ensure_domain_settings_response_user_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ensure_domain_settings_response_user->identifier) {
        free(ensure_domain_settings_response_user->identifier);
        ensure_domain_settings_response_user->identifier = NULL;
    }
    free(ensure_domain_settings_response_user);
}

cJSON *ensure_domain_settings_response_user_convertToJSON(ensure_domain_settings_response_user_t *ensure_domain_settings_response_user) {
    cJSON *item = cJSON_CreateObject();

    // ensure_domain_settings_response_user->identifier
    if (!ensure_domain_settings_response_user->identifier) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "identifier", ensure_domain_settings_response_user->identifier) == NULL) {
    goto fail; //String
    }


    // ensure_domain_settings_response_user->created
    if (!ensure_domain_settings_response_user->created) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "created", ensure_domain_settings_response_user->created) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ensure_domain_settings_response_user_t *ensure_domain_settings_response_user_parseFromJSON(cJSON *ensure_domain_settings_response_userJSON){

    ensure_domain_settings_response_user_t *ensure_domain_settings_response_user_local_var = NULL;

    // ensure_domain_settings_response_user->identifier
    cJSON *identifier = cJSON_GetObjectItemCaseSensitive(ensure_domain_settings_response_userJSON, "identifier");
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

    // ensure_domain_settings_response_user->created
    cJSON *created = cJSON_GetObjectItemCaseSensitive(ensure_domain_settings_response_userJSON, "created");
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


    ensure_domain_settings_response_user_local_var = ensure_domain_settings_response_user_create_internal (
        strdup(identifier->valuestring),
        created->valueint
        );

    return ensure_domain_settings_response_user_local_var;
end:
    return NULL;

}
