#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "login_result_domain_snapshot_sharing_permissions.h"



static login_result_domain_snapshot_sharing_permissions_t *login_result_domain_snapshot_sharing_permissions_create_internal(
    int cloud_enabled,
    int domain_enabled,
    int public_link,
    int domain_restricted_link,
    int password_public_link,
    int email_invite
    ) {
    login_result_domain_snapshot_sharing_permissions_t *login_result_domain_snapshot_sharing_permissions_local_var = malloc(sizeof(login_result_domain_snapshot_sharing_permissions_t));
    if (!login_result_domain_snapshot_sharing_permissions_local_var) {
        return NULL;
    }
    login_result_domain_snapshot_sharing_permissions_local_var->cloud_enabled = cloud_enabled;
    login_result_domain_snapshot_sharing_permissions_local_var->domain_enabled = domain_enabled;
    login_result_domain_snapshot_sharing_permissions_local_var->public_link = public_link;
    login_result_domain_snapshot_sharing_permissions_local_var->domain_restricted_link = domain_restricted_link;
    login_result_domain_snapshot_sharing_permissions_local_var->password_public_link = password_public_link;
    login_result_domain_snapshot_sharing_permissions_local_var->email_invite = email_invite;

    login_result_domain_snapshot_sharing_permissions_local_var->_library_owned = 1;
    return login_result_domain_snapshot_sharing_permissions_local_var;
}

__attribute__((deprecated)) login_result_domain_snapshot_sharing_permissions_t *login_result_domain_snapshot_sharing_permissions_create(
    int cloud_enabled,
    int domain_enabled,
    int public_link,
    int domain_restricted_link,
    int password_public_link,
    int email_invite
    ) {
    return login_result_domain_snapshot_sharing_permissions_create_internal (
        cloud_enabled,
        domain_enabled,
        public_link,
        domain_restricted_link,
        password_public_link,
        email_invite
        );
}

void login_result_domain_snapshot_sharing_permissions_free(login_result_domain_snapshot_sharing_permissions_t *login_result_domain_snapshot_sharing_permissions) {
    if(NULL == login_result_domain_snapshot_sharing_permissions){
        return ;
    }
    if(login_result_domain_snapshot_sharing_permissions->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "login_result_domain_snapshot_sharing_permissions_free");
        return ;
    }
    listEntry_t *listEntry;
    free(login_result_domain_snapshot_sharing_permissions);
}

cJSON *login_result_domain_snapshot_sharing_permissions_convertToJSON(login_result_domain_snapshot_sharing_permissions_t *login_result_domain_snapshot_sharing_permissions) {
    cJSON *item = cJSON_CreateObject();

    // login_result_domain_snapshot_sharing_permissions->cloud_enabled
    if(login_result_domain_snapshot_sharing_permissions->cloud_enabled) {
    if(cJSON_AddBoolToObject(item, "cloudEnabled", login_result_domain_snapshot_sharing_permissions->cloud_enabled) == NULL) {
    goto fail; //Bool
    }
    }


    // login_result_domain_snapshot_sharing_permissions->domain_enabled
    if(login_result_domain_snapshot_sharing_permissions->domain_enabled) {
    if(cJSON_AddBoolToObject(item, "domainEnabled", login_result_domain_snapshot_sharing_permissions->domain_enabled) == NULL) {
    goto fail; //Bool
    }
    }


    // login_result_domain_snapshot_sharing_permissions->public_link
    if(login_result_domain_snapshot_sharing_permissions->public_link) {
    if(cJSON_AddBoolToObject(item, "publicLink", login_result_domain_snapshot_sharing_permissions->public_link) == NULL) {
    goto fail; //Bool
    }
    }


    // login_result_domain_snapshot_sharing_permissions->domain_restricted_link
    if(login_result_domain_snapshot_sharing_permissions->domain_restricted_link) {
    if(cJSON_AddBoolToObject(item, "domainRestrictedLink", login_result_domain_snapshot_sharing_permissions->domain_restricted_link) == NULL) {
    goto fail; //Bool
    }
    }


    // login_result_domain_snapshot_sharing_permissions->password_public_link
    if(login_result_domain_snapshot_sharing_permissions->password_public_link) {
    if(cJSON_AddBoolToObject(item, "passwordPublicLink", login_result_domain_snapshot_sharing_permissions->password_public_link) == NULL) {
    goto fail; //Bool
    }
    }


    // login_result_domain_snapshot_sharing_permissions->email_invite
    if(login_result_domain_snapshot_sharing_permissions->email_invite) {
    if(cJSON_AddBoolToObject(item, "emailInvite", login_result_domain_snapshot_sharing_permissions->email_invite) == NULL) {
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

login_result_domain_snapshot_sharing_permissions_t *login_result_domain_snapshot_sharing_permissions_parseFromJSON(cJSON *login_result_domain_snapshot_sharing_permissionsJSON){

    login_result_domain_snapshot_sharing_permissions_t *login_result_domain_snapshot_sharing_permissions_local_var = NULL;

    // login_result_domain_snapshot_sharing_permissions->cloud_enabled
    cJSON *cloud_enabled = cJSON_GetObjectItemCaseSensitive(login_result_domain_snapshot_sharing_permissionsJSON, "cloudEnabled");
    if (cJSON_IsNull(cloud_enabled)) {
        cloud_enabled = NULL;
    }
    if (cloud_enabled) { 
    if(!cJSON_IsBool(cloud_enabled))
    {
    goto end; //Bool
    }
    }

    // login_result_domain_snapshot_sharing_permissions->domain_enabled
    cJSON *domain_enabled = cJSON_GetObjectItemCaseSensitive(login_result_domain_snapshot_sharing_permissionsJSON, "domainEnabled");
    if (cJSON_IsNull(domain_enabled)) {
        domain_enabled = NULL;
    }
    if (domain_enabled) { 
    if(!cJSON_IsBool(domain_enabled))
    {
    goto end; //Bool
    }
    }

    // login_result_domain_snapshot_sharing_permissions->public_link
    cJSON *public_link = cJSON_GetObjectItemCaseSensitive(login_result_domain_snapshot_sharing_permissionsJSON, "publicLink");
    if (cJSON_IsNull(public_link)) {
        public_link = NULL;
    }
    if (public_link) { 
    if(!cJSON_IsBool(public_link))
    {
    goto end; //Bool
    }
    }

    // login_result_domain_snapshot_sharing_permissions->domain_restricted_link
    cJSON *domain_restricted_link = cJSON_GetObjectItemCaseSensitive(login_result_domain_snapshot_sharing_permissionsJSON, "domainRestrictedLink");
    if (cJSON_IsNull(domain_restricted_link)) {
        domain_restricted_link = NULL;
    }
    if (domain_restricted_link) { 
    if(!cJSON_IsBool(domain_restricted_link))
    {
    goto end; //Bool
    }
    }

    // login_result_domain_snapshot_sharing_permissions->password_public_link
    cJSON *password_public_link = cJSON_GetObjectItemCaseSensitive(login_result_domain_snapshot_sharing_permissionsJSON, "passwordPublicLink");
    if (cJSON_IsNull(password_public_link)) {
        password_public_link = NULL;
    }
    if (password_public_link) { 
    if(!cJSON_IsBool(password_public_link))
    {
    goto end; //Bool
    }
    }

    // login_result_domain_snapshot_sharing_permissions->email_invite
    cJSON *email_invite = cJSON_GetObjectItemCaseSensitive(login_result_domain_snapshot_sharing_permissionsJSON, "emailInvite");
    if (cJSON_IsNull(email_invite)) {
        email_invite = NULL;
    }
    if (email_invite) { 
    if(!cJSON_IsBool(email_invite))
    {
    goto end; //Bool
    }
    }


    login_result_domain_snapshot_sharing_permissions_local_var = login_result_domain_snapshot_sharing_permissions_create_internal (
        cloud_enabled ? cloud_enabled->valueint : 0,
        domain_enabled ? domain_enabled->valueint : 0,
        public_link ? public_link->valueint : 0,
        domain_restricted_link ? domain_restricted_link->valueint : 0,
        password_public_link ? password_public_link->valueint : 0,
        email_invite ? email_invite->valueint : 0
        );

    return login_result_domain_snapshot_sharing_permissions_local_var;
end:
    return NULL;

}
