#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "domain_config_input_snapshot_sharing_permissions.h"



static domain_config_input_snapshot_sharing_permissions_t *domain_config_input_snapshot_sharing_permissions_create_internal(
    int enabled,
    int public_link,
    int domain_restricted_link,
    int password_public_link,
    int email_invite
    ) {
    domain_config_input_snapshot_sharing_permissions_t *domain_config_input_snapshot_sharing_permissions_local_var = malloc(sizeof(domain_config_input_snapshot_sharing_permissions_t));
    if (!domain_config_input_snapshot_sharing_permissions_local_var) {
        return NULL;
    }
    domain_config_input_snapshot_sharing_permissions_local_var->enabled = enabled;
    domain_config_input_snapshot_sharing_permissions_local_var->public_link = public_link;
    domain_config_input_snapshot_sharing_permissions_local_var->domain_restricted_link = domain_restricted_link;
    domain_config_input_snapshot_sharing_permissions_local_var->password_public_link = password_public_link;
    domain_config_input_snapshot_sharing_permissions_local_var->email_invite = email_invite;

    domain_config_input_snapshot_sharing_permissions_local_var->_library_owned = 1;
    return domain_config_input_snapshot_sharing_permissions_local_var;
}

__attribute__((deprecated)) domain_config_input_snapshot_sharing_permissions_t *domain_config_input_snapshot_sharing_permissions_create(
    int enabled,
    int public_link,
    int domain_restricted_link,
    int password_public_link,
    int email_invite
    ) {
    return domain_config_input_snapshot_sharing_permissions_create_internal (
        enabled,
        public_link,
        domain_restricted_link,
        password_public_link,
        email_invite
        );
}

void domain_config_input_snapshot_sharing_permissions_free(domain_config_input_snapshot_sharing_permissions_t *domain_config_input_snapshot_sharing_permissions) {
    if(NULL == domain_config_input_snapshot_sharing_permissions){
        return ;
    }
    if(domain_config_input_snapshot_sharing_permissions->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "domain_config_input_snapshot_sharing_permissions_free");
        return ;
    }
    listEntry_t *listEntry;
    free(domain_config_input_snapshot_sharing_permissions);
}

cJSON *domain_config_input_snapshot_sharing_permissions_convertToJSON(domain_config_input_snapshot_sharing_permissions_t *domain_config_input_snapshot_sharing_permissions) {
    cJSON *item = cJSON_CreateObject();

    // domain_config_input_snapshot_sharing_permissions->enabled
    if(domain_config_input_snapshot_sharing_permissions->enabled) {
    if(cJSON_AddBoolToObject(item, "enabled", domain_config_input_snapshot_sharing_permissions->enabled) == NULL) {
    goto fail; //Bool
    }
    }


    // domain_config_input_snapshot_sharing_permissions->public_link
    if(domain_config_input_snapshot_sharing_permissions->public_link) {
    if(cJSON_AddBoolToObject(item, "publicLink", domain_config_input_snapshot_sharing_permissions->public_link) == NULL) {
    goto fail; //Bool
    }
    }


    // domain_config_input_snapshot_sharing_permissions->domain_restricted_link
    if(domain_config_input_snapshot_sharing_permissions->domain_restricted_link) {
    if(cJSON_AddBoolToObject(item, "domainRestrictedLink", domain_config_input_snapshot_sharing_permissions->domain_restricted_link) == NULL) {
    goto fail; //Bool
    }
    }


    // domain_config_input_snapshot_sharing_permissions->password_public_link
    if(domain_config_input_snapshot_sharing_permissions->password_public_link) {
    if(cJSON_AddBoolToObject(item, "passwordPublicLink", domain_config_input_snapshot_sharing_permissions->password_public_link) == NULL) {
    goto fail; //Bool
    }
    }


    // domain_config_input_snapshot_sharing_permissions->email_invite
    if(domain_config_input_snapshot_sharing_permissions->email_invite) {
    if(cJSON_AddBoolToObject(item, "emailInvite", domain_config_input_snapshot_sharing_permissions->email_invite) == NULL) {
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

domain_config_input_snapshot_sharing_permissions_t *domain_config_input_snapshot_sharing_permissions_parseFromJSON(cJSON *domain_config_input_snapshot_sharing_permissionsJSON){

    domain_config_input_snapshot_sharing_permissions_t *domain_config_input_snapshot_sharing_permissions_local_var = NULL;

    // domain_config_input_snapshot_sharing_permissions->enabled
    cJSON *enabled = cJSON_GetObjectItemCaseSensitive(domain_config_input_snapshot_sharing_permissionsJSON, "enabled");
    if (cJSON_IsNull(enabled)) {
        enabled = NULL;
    }
    if (enabled) { 
    if(!cJSON_IsBool(enabled))
    {
    goto end; //Bool
    }
    }

    // domain_config_input_snapshot_sharing_permissions->public_link
    cJSON *public_link = cJSON_GetObjectItemCaseSensitive(domain_config_input_snapshot_sharing_permissionsJSON, "publicLink");
    if (cJSON_IsNull(public_link)) {
        public_link = NULL;
    }
    if (public_link) { 
    if(!cJSON_IsBool(public_link))
    {
    goto end; //Bool
    }
    }

    // domain_config_input_snapshot_sharing_permissions->domain_restricted_link
    cJSON *domain_restricted_link = cJSON_GetObjectItemCaseSensitive(domain_config_input_snapshot_sharing_permissionsJSON, "domainRestrictedLink");
    if (cJSON_IsNull(domain_restricted_link)) {
        domain_restricted_link = NULL;
    }
    if (domain_restricted_link) { 
    if(!cJSON_IsBool(domain_restricted_link))
    {
    goto end; //Bool
    }
    }

    // domain_config_input_snapshot_sharing_permissions->password_public_link
    cJSON *password_public_link = cJSON_GetObjectItemCaseSensitive(domain_config_input_snapshot_sharing_permissionsJSON, "passwordPublicLink");
    if (cJSON_IsNull(password_public_link)) {
        password_public_link = NULL;
    }
    if (password_public_link) { 
    if(!cJSON_IsBool(password_public_link))
    {
    goto end; //Bool
    }
    }

    // domain_config_input_snapshot_sharing_permissions->email_invite
    cJSON *email_invite = cJSON_GetObjectItemCaseSensitive(domain_config_input_snapshot_sharing_permissionsJSON, "emailInvite");
    if (cJSON_IsNull(email_invite)) {
        email_invite = NULL;
    }
    if (email_invite) { 
    if(!cJSON_IsBool(email_invite))
    {
    goto end; //Bool
    }
    }


    domain_config_input_snapshot_sharing_permissions_local_var = domain_config_input_snapshot_sharing_permissions_create_internal (
        enabled ? enabled->valueint : 0,
        public_link ? public_link->valueint : 0,
        domain_restricted_link ? domain_restricted_link->valueint : 0,
        password_public_link ? password_public_link->valueint : 0,
        email_invite ? email_invite->valueint : 0
        );

    return domain_config_input_snapshot_sharing_permissions_local_var;
end:
    return NULL;

}
