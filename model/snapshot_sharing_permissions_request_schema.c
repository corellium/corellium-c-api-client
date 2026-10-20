#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "snapshot_sharing_permissions_request_schema.h"



static snapshot_sharing_permissions_request_schema_t *snapshot_sharing_permissions_request_schema_create_internal(
    int enabled,
    int public_link,
    int domain_restricted_link,
    int password_public_link,
    int email_invite
    ) {
    snapshot_sharing_permissions_request_schema_t *snapshot_sharing_permissions_request_schema_local_var = malloc(sizeof(snapshot_sharing_permissions_request_schema_t));
    if (!snapshot_sharing_permissions_request_schema_local_var) {
        return NULL;
    }
    snapshot_sharing_permissions_request_schema_local_var->enabled = enabled;
    snapshot_sharing_permissions_request_schema_local_var->public_link = public_link;
    snapshot_sharing_permissions_request_schema_local_var->domain_restricted_link = domain_restricted_link;
    snapshot_sharing_permissions_request_schema_local_var->password_public_link = password_public_link;
    snapshot_sharing_permissions_request_schema_local_var->email_invite = email_invite;

    snapshot_sharing_permissions_request_schema_local_var->_library_owned = 1;
    return snapshot_sharing_permissions_request_schema_local_var;
}

__attribute__((deprecated)) snapshot_sharing_permissions_request_schema_t *snapshot_sharing_permissions_request_schema_create(
    int enabled,
    int public_link,
    int domain_restricted_link,
    int password_public_link,
    int email_invite
    ) {
    return snapshot_sharing_permissions_request_schema_create_internal (
        enabled,
        public_link,
        domain_restricted_link,
        password_public_link,
        email_invite
        );
}

void snapshot_sharing_permissions_request_schema_free(snapshot_sharing_permissions_request_schema_t *snapshot_sharing_permissions_request_schema) {
    if(NULL == snapshot_sharing_permissions_request_schema){
        return ;
    }
    if(snapshot_sharing_permissions_request_schema->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "snapshot_sharing_permissions_request_schema_free");
        return ;
    }
    listEntry_t *listEntry;
    free(snapshot_sharing_permissions_request_schema);
}

cJSON *snapshot_sharing_permissions_request_schema_convertToJSON(snapshot_sharing_permissions_request_schema_t *snapshot_sharing_permissions_request_schema) {
    cJSON *item = cJSON_CreateObject();

    // snapshot_sharing_permissions_request_schema->enabled
    if(snapshot_sharing_permissions_request_schema->enabled) {
    if(cJSON_AddBoolToObject(item, "enabled", snapshot_sharing_permissions_request_schema->enabled) == NULL) {
    goto fail; //Bool
    }
    }


    // snapshot_sharing_permissions_request_schema->public_link
    if(snapshot_sharing_permissions_request_schema->public_link) {
    if(cJSON_AddBoolToObject(item, "publicLink", snapshot_sharing_permissions_request_schema->public_link) == NULL) {
    goto fail; //Bool
    }
    }


    // snapshot_sharing_permissions_request_schema->domain_restricted_link
    if(snapshot_sharing_permissions_request_schema->domain_restricted_link) {
    if(cJSON_AddBoolToObject(item, "domainRestrictedLink", snapshot_sharing_permissions_request_schema->domain_restricted_link) == NULL) {
    goto fail; //Bool
    }
    }


    // snapshot_sharing_permissions_request_schema->password_public_link
    if(snapshot_sharing_permissions_request_schema->password_public_link) {
    if(cJSON_AddBoolToObject(item, "passwordPublicLink", snapshot_sharing_permissions_request_schema->password_public_link) == NULL) {
    goto fail; //Bool
    }
    }


    // snapshot_sharing_permissions_request_schema->email_invite
    if(snapshot_sharing_permissions_request_schema->email_invite) {
    if(cJSON_AddBoolToObject(item, "emailInvite", snapshot_sharing_permissions_request_schema->email_invite) == NULL) {
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

snapshot_sharing_permissions_request_schema_t *snapshot_sharing_permissions_request_schema_parseFromJSON(cJSON *snapshot_sharing_permissions_request_schemaJSON){

    snapshot_sharing_permissions_request_schema_t *snapshot_sharing_permissions_request_schema_local_var = NULL;

    // snapshot_sharing_permissions_request_schema->enabled
    cJSON *enabled = cJSON_GetObjectItemCaseSensitive(snapshot_sharing_permissions_request_schemaJSON, "enabled");
    if (cJSON_IsNull(enabled)) {
        enabled = NULL;
    }
    if (enabled) { 
    if(!cJSON_IsBool(enabled))
    {
    goto end; //Bool
    }
    }

    // snapshot_sharing_permissions_request_schema->public_link
    cJSON *public_link = cJSON_GetObjectItemCaseSensitive(snapshot_sharing_permissions_request_schemaJSON, "publicLink");
    if (cJSON_IsNull(public_link)) {
        public_link = NULL;
    }
    if (public_link) { 
    if(!cJSON_IsBool(public_link))
    {
    goto end; //Bool
    }
    }

    // snapshot_sharing_permissions_request_schema->domain_restricted_link
    cJSON *domain_restricted_link = cJSON_GetObjectItemCaseSensitive(snapshot_sharing_permissions_request_schemaJSON, "domainRestrictedLink");
    if (cJSON_IsNull(domain_restricted_link)) {
        domain_restricted_link = NULL;
    }
    if (domain_restricted_link) { 
    if(!cJSON_IsBool(domain_restricted_link))
    {
    goto end; //Bool
    }
    }

    // snapshot_sharing_permissions_request_schema->password_public_link
    cJSON *password_public_link = cJSON_GetObjectItemCaseSensitive(snapshot_sharing_permissions_request_schemaJSON, "passwordPublicLink");
    if (cJSON_IsNull(password_public_link)) {
        password_public_link = NULL;
    }
    if (password_public_link) { 
    if(!cJSON_IsBool(password_public_link))
    {
    goto end; //Bool
    }
    }

    // snapshot_sharing_permissions_request_schema->email_invite
    cJSON *email_invite = cJSON_GetObjectItemCaseSensitive(snapshot_sharing_permissions_request_schemaJSON, "emailInvite");
    if (cJSON_IsNull(email_invite)) {
        email_invite = NULL;
    }
    if (email_invite) { 
    if(!cJSON_IsBool(email_invite))
    {
    goto end; //Bool
    }
    }


    snapshot_sharing_permissions_request_schema_local_var = snapshot_sharing_permissions_request_schema_create_internal (
        enabled ? enabled->valueint : 0,
        public_link ? public_link->valueint : 0,
        domain_restricted_link ? domain_restricted_link->valueint : 0,
        password_public_link ? password_public_link->valueint : 0,
        email_invite ? email_invite->valueint : 0
        );

    return snapshot_sharing_permissions_request_schema_local_var;
end:
    return NULL;

}
