#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "snapshot_sharing_permissions.h"



static snapshot_sharing_permissions_t *snapshot_sharing_permissions_create_internal(
    int cloud_enabled,
    int domain_enabled,
    int public_link,
    int domain_restricted_link,
    int password_public_link,
    int email_invite
    ) {
    snapshot_sharing_permissions_t *snapshot_sharing_permissions_local_var = malloc(sizeof(snapshot_sharing_permissions_t));
    if (!snapshot_sharing_permissions_local_var) {
        return NULL;
    }
    snapshot_sharing_permissions_local_var->cloud_enabled = cloud_enabled;
    snapshot_sharing_permissions_local_var->domain_enabled = domain_enabled;
    snapshot_sharing_permissions_local_var->public_link = public_link;
    snapshot_sharing_permissions_local_var->domain_restricted_link = domain_restricted_link;
    snapshot_sharing_permissions_local_var->password_public_link = password_public_link;
    snapshot_sharing_permissions_local_var->email_invite = email_invite;

    snapshot_sharing_permissions_local_var->_library_owned = 1;
    return snapshot_sharing_permissions_local_var;
}

__attribute__((deprecated)) snapshot_sharing_permissions_t *snapshot_sharing_permissions_create(
    int cloud_enabled,
    int domain_enabled,
    int public_link,
    int domain_restricted_link,
    int password_public_link,
    int email_invite
    ) {
    return snapshot_sharing_permissions_create_internal (
        cloud_enabled,
        domain_enabled,
        public_link,
        domain_restricted_link,
        password_public_link,
        email_invite
        );
}

void snapshot_sharing_permissions_free(snapshot_sharing_permissions_t *snapshot_sharing_permissions) {
    if(NULL == snapshot_sharing_permissions){
        return ;
    }
    if(snapshot_sharing_permissions->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "snapshot_sharing_permissions_free");
        return ;
    }
    listEntry_t *listEntry;
    free(snapshot_sharing_permissions);
}

cJSON *snapshot_sharing_permissions_convertToJSON(snapshot_sharing_permissions_t *snapshot_sharing_permissions) {
    cJSON *item = cJSON_CreateObject();

    // snapshot_sharing_permissions->cloud_enabled
    if(snapshot_sharing_permissions->cloud_enabled) {
    if(cJSON_AddBoolToObject(item, "cloudEnabled", snapshot_sharing_permissions->cloud_enabled) == NULL) {
    goto fail; //Bool
    }
    }


    // snapshot_sharing_permissions->domain_enabled
    if(snapshot_sharing_permissions->domain_enabled) {
    if(cJSON_AddBoolToObject(item, "domainEnabled", snapshot_sharing_permissions->domain_enabled) == NULL) {
    goto fail; //Bool
    }
    }


    // snapshot_sharing_permissions->public_link
    if(snapshot_sharing_permissions->public_link) {
    if(cJSON_AddBoolToObject(item, "publicLink", snapshot_sharing_permissions->public_link) == NULL) {
    goto fail; //Bool
    }
    }


    // snapshot_sharing_permissions->domain_restricted_link
    if(snapshot_sharing_permissions->domain_restricted_link) {
    if(cJSON_AddBoolToObject(item, "domainRestrictedLink", snapshot_sharing_permissions->domain_restricted_link) == NULL) {
    goto fail; //Bool
    }
    }


    // snapshot_sharing_permissions->password_public_link
    if(snapshot_sharing_permissions->password_public_link) {
    if(cJSON_AddBoolToObject(item, "passwordPublicLink", snapshot_sharing_permissions->password_public_link) == NULL) {
    goto fail; //Bool
    }
    }


    // snapshot_sharing_permissions->email_invite
    if(snapshot_sharing_permissions->email_invite) {
    if(cJSON_AddBoolToObject(item, "emailInvite", snapshot_sharing_permissions->email_invite) == NULL) {
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

snapshot_sharing_permissions_t *snapshot_sharing_permissions_parseFromJSON(cJSON *snapshot_sharing_permissionsJSON){

    snapshot_sharing_permissions_t *snapshot_sharing_permissions_local_var = NULL;

    // snapshot_sharing_permissions->cloud_enabled
    cJSON *cloud_enabled = cJSON_GetObjectItemCaseSensitive(snapshot_sharing_permissionsJSON, "cloudEnabled");
    if (cJSON_IsNull(cloud_enabled)) {
        cloud_enabled = NULL;
    }
    if (cloud_enabled) { 
    if(!cJSON_IsBool(cloud_enabled))
    {
    goto end; //Bool
    }
    }

    // snapshot_sharing_permissions->domain_enabled
    cJSON *domain_enabled = cJSON_GetObjectItemCaseSensitive(snapshot_sharing_permissionsJSON, "domainEnabled");
    if (cJSON_IsNull(domain_enabled)) {
        domain_enabled = NULL;
    }
    if (domain_enabled) { 
    if(!cJSON_IsBool(domain_enabled))
    {
    goto end; //Bool
    }
    }

    // snapshot_sharing_permissions->public_link
    cJSON *public_link = cJSON_GetObjectItemCaseSensitive(snapshot_sharing_permissionsJSON, "publicLink");
    if (cJSON_IsNull(public_link)) {
        public_link = NULL;
    }
    if (public_link) { 
    if(!cJSON_IsBool(public_link))
    {
    goto end; //Bool
    }
    }

    // snapshot_sharing_permissions->domain_restricted_link
    cJSON *domain_restricted_link = cJSON_GetObjectItemCaseSensitive(snapshot_sharing_permissionsJSON, "domainRestrictedLink");
    if (cJSON_IsNull(domain_restricted_link)) {
        domain_restricted_link = NULL;
    }
    if (domain_restricted_link) { 
    if(!cJSON_IsBool(domain_restricted_link))
    {
    goto end; //Bool
    }
    }

    // snapshot_sharing_permissions->password_public_link
    cJSON *password_public_link = cJSON_GetObjectItemCaseSensitive(snapshot_sharing_permissionsJSON, "passwordPublicLink");
    if (cJSON_IsNull(password_public_link)) {
        password_public_link = NULL;
    }
    if (password_public_link) { 
    if(!cJSON_IsBool(password_public_link))
    {
    goto end; //Bool
    }
    }

    // snapshot_sharing_permissions->email_invite
    cJSON *email_invite = cJSON_GetObjectItemCaseSensitive(snapshot_sharing_permissionsJSON, "emailInvite");
    if (cJSON_IsNull(email_invite)) {
        email_invite = NULL;
    }
    if (email_invite) { 
    if(!cJSON_IsBool(email_invite))
    {
    goto end; //Bool
    }
    }


    snapshot_sharing_permissions_local_var = snapshot_sharing_permissions_create_internal (
        cloud_enabled ? cloud_enabled->valueint : 0,
        domain_enabled ? domain_enabled->valueint : 0,
        public_link ? public_link->valueint : 0,
        domain_restricted_link ? domain_restricted_link->valueint : 0,
        password_public_link ? password_public_link->valueint : 0,
        email_invite ? email_invite->valueint : 0
        );

    return snapshot_sharing_permissions_local_var;
end:
    return NULL;

}
