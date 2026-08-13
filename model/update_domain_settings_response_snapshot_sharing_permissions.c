#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "update_domain_settings_response_snapshot_sharing_permissions.h"



static update_domain_settings_response_snapshot_sharing_permissions_t *update_domain_settings_response_snapshot_sharing_permissions_create_internal(
    int domain_enabled
    ) {
    update_domain_settings_response_snapshot_sharing_permissions_t *update_domain_settings_response_snapshot_sharing_permissions_local_var = malloc(sizeof(update_domain_settings_response_snapshot_sharing_permissions_t));
    if (!update_domain_settings_response_snapshot_sharing_permissions_local_var) {
        return NULL;
    }
    update_domain_settings_response_snapshot_sharing_permissions_local_var->domain_enabled = domain_enabled;

    update_domain_settings_response_snapshot_sharing_permissions_local_var->_library_owned = 1;
    return update_domain_settings_response_snapshot_sharing_permissions_local_var;
}

__attribute__((deprecated)) update_domain_settings_response_snapshot_sharing_permissions_t *update_domain_settings_response_snapshot_sharing_permissions_create(
    int domain_enabled
    ) {
    return update_domain_settings_response_snapshot_sharing_permissions_create_internal (
        domain_enabled
        );
}

void update_domain_settings_response_snapshot_sharing_permissions_free(update_domain_settings_response_snapshot_sharing_permissions_t *update_domain_settings_response_snapshot_sharing_permissions) {
    if(NULL == update_domain_settings_response_snapshot_sharing_permissions){
        return ;
    }
    if(update_domain_settings_response_snapshot_sharing_permissions->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "update_domain_settings_response_snapshot_sharing_permissions_free");
        return ;
    }
    listEntry_t *listEntry;
    free(update_domain_settings_response_snapshot_sharing_permissions);
}

cJSON *update_domain_settings_response_snapshot_sharing_permissions_convertToJSON(update_domain_settings_response_snapshot_sharing_permissions_t *update_domain_settings_response_snapshot_sharing_permissions) {
    cJSON *item = cJSON_CreateObject();

    // update_domain_settings_response_snapshot_sharing_permissions->domain_enabled
    if (!update_domain_settings_response_snapshot_sharing_permissions->domain_enabled) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "domainEnabled", update_domain_settings_response_snapshot_sharing_permissions->domain_enabled) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

update_domain_settings_response_snapshot_sharing_permissions_t *update_domain_settings_response_snapshot_sharing_permissions_parseFromJSON(cJSON *update_domain_settings_response_snapshot_sharing_permissionsJSON){

    update_domain_settings_response_snapshot_sharing_permissions_t *update_domain_settings_response_snapshot_sharing_permissions_local_var = NULL;

    // update_domain_settings_response_snapshot_sharing_permissions->domain_enabled
    cJSON *domain_enabled = cJSON_GetObjectItemCaseSensitive(update_domain_settings_response_snapshot_sharing_permissionsJSON, "domainEnabled");
    if (cJSON_IsNull(domain_enabled)) {
        domain_enabled = NULL;
    }
    if (!domain_enabled) {
        goto end;
    }

    
    if(!cJSON_IsBool(domain_enabled))
    {
    goto end; //Bool
    }


    update_domain_settings_response_snapshot_sharing_permissions_local_var = update_domain_settings_response_snapshot_sharing_permissions_create_internal (
        domain_enabled->valueint
        );

    return update_domain_settings_response_snapshot_sharing_permissions_local_var;
end:
    return NULL;

}
