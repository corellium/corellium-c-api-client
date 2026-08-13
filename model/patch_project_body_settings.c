#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "patch_project_body_settings.h"



static patch_project_body_settings_t *patch_project_body_settings_create_internal(
    double version,
    int internet_access,
    int dhcp,
    char *connection
    ) {
    patch_project_body_settings_t *patch_project_body_settings_local_var = malloc(sizeof(patch_project_body_settings_t));
    if (!patch_project_body_settings_local_var) {
        return NULL;
    }
    patch_project_body_settings_local_var->version = version;
    patch_project_body_settings_local_var->internet_access = internet_access;
    patch_project_body_settings_local_var->dhcp = dhcp;
    patch_project_body_settings_local_var->connection = connection;

    patch_project_body_settings_local_var->_library_owned = 1;
    return patch_project_body_settings_local_var;
}

__attribute__((deprecated)) patch_project_body_settings_t *patch_project_body_settings_create(
    double version,
    int internet_access,
    int dhcp,
    char *connection
    ) {
    return patch_project_body_settings_create_internal (
        version,
        internet_access,
        dhcp,
        connection
        );
}

void patch_project_body_settings_free(patch_project_body_settings_t *patch_project_body_settings) {
    if(NULL == patch_project_body_settings){
        return ;
    }
    if(patch_project_body_settings->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "patch_project_body_settings_free");
        return ;
    }
    listEntry_t *listEntry;
    if (patch_project_body_settings->connection) {
        free(patch_project_body_settings->connection);
        patch_project_body_settings->connection = NULL;
    }
    free(patch_project_body_settings);
}

cJSON *patch_project_body_settings_convertToJSON(patch_project_body_settings_t *patch_project_body_settings) {
    cJSON *item = cJSON_CreateObject();

    // patch_project_body_settings->version
    if(patch_project_body_settings->version) {
    if(cJSON_AddNumberToObject(item, "version", patch_project_body_settings->version) == NULL) {
    goto fail; //Numeric
    }
    }


    // patch_project_body_settings->internet_access
    if(patch_project_body_settings->internet_access) {
    if(cJSON_AddBoolToObject(item, "internetAccess", patch_project_body_settings->internet_access) == NULL) {
    goto fail; //Bool
    }
    }


    // patch_project_body_settings->dhcp
    if(patch_project_body_settings->dhcp) {
    if(cJSON_AddBoolToObject(item, "dhcp", patch_project_body_settings->dhcp) == NULL) {
    goto fail; //Bool
    }
    }


    // patch_project_body_settings->connection
    if(patch_project_body_settings->connection) {
    if(cJSON_AddStringToObject(item, "connection", patch_project_body_settings->connection) == NULL) {
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

patch_project_body_settings_t *patch_project_body_settings_parseFromJSON(cJSON *patch_project_body_settingsJSON){

    patch_project_body_settings_t *patch_project_body_settings_local_var = NULL;

    // patch_project_body_settings->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(patch_project_body_settingsJSON, "version");
    if (cJSON_IsNull(version)) {
        version = NULL;
    }
    if (version) { 
    if(!cJSON_IsNumber(version))
    {
    goto end; //Numeric
    }
    }

    // patch_project_body_settings->internet_access
    cJSON *internet_access = cJSON_GetObjectItemCaseSensitive(patch_project_body_settingsJSON, "internetAccess");
    if (cJSON_IsNull(internet_access)) {
        internet_access = NULL;
    }
    if (internet_access) { 
    if(!cJSON_IsBool(internet_access))
    {
    goto end; //Bool
    }
    }

    // patch_project_body_settings->dhcp
    cJSON *dhcp = cJSON_GetObjectItemCaseSensitive(patch_project_body_settingsJSON, "dhcp");
    if (cJSON_IsNull(dhcp)) {
        dhcp = NULL;
    }
    if (dhcp) { 
    if(!cJSON_IsBool(dhcp))
    {
    goto end; //Bool
    }
    }

    // patch_project_body_settings->connection
    cJSON *connection = cJSON_GetObjectItemCaseSensitive(patch_project_body_settingsJSON, "connection");
    if (cJSON_IsNull(connection)) {
        connection = NULL;
    }
    if (connection) { 
    if(!cJSON_IsString(connection) && !cJSON_IsNull(connection))
    {
    goto end; //String
    }
    }


    patch_project_body_settings_local_var = patch_project_body_settings_create_internal (
        version ? version->valuedouble : 0,
        internet_access ? internet_access->valueint : 0,
        dhcp ? dhcp->valueint : 0,
        connection && !cJSON_IsNull(connection) ? strdup(connection->valuestring) : NULL
        );

    return patch_project_body_settings_local_var;
end:
    return NULL;

}
