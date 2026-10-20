#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_project_body_settings.h"



static create_project_body_settings_t *create_project_body_settings_create_internal(
    double version,
    int internet_access,
    int dhcp,
    char *connection
    ) {
    create_project_body_settings_t *create_project_body_settings_local_var = malloc(sizeof(create_project_body_settings_t));
    if (!create_project_body_settings_local_var) {
        return NULL;
    }
    create_project_body_settings_local_var->version = version;
    create_project_body_settings_local_var->internet_access = internet_access;
    create_project_body_settings_local_var->dhcp = dhcp;
    create_project_body_settings_local_var->connection = connection;

    create_project_body_settings_local_var->_library_owned = 1;
    return create_project_body_settings_local_var;
}

__attribute__((deprecated)) create_project_body_settings_t *create_project_body_settings_create(
    double version,
    int internet_access,
    int dhcp,
    char *connection
    ) {
    return create_project_body_settings_create_internal (
        version,
        internet_access,
        dhcp,
        connection
        );
}

void create_project_body_settings_free(create_project_body_settings_t *create_project_body_settings) {
    if(NULL == create_project_body_settings){
        return ;
    }
    if(create_project_body_settings->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "create_project_body_settings_free");
        return ;
    }
    listEntry_t *listEntry;
    if (create_project_body_settings->connection) {
        free(create_project_body_settings->connection);
        create_project_body_settings->connection = NULL;
    }
    free(create_project_body_settings);
}

cJSON *create_project_body_settings_convertToJSON(create_project_body_settings_t *create_project_body_settings) {
    cJSON *item = cJSON_CreateObject();

    // create_project_body_settings->version
    if(create_project_body_settings->version) {
    if(cJSON_AddNumberToObject(item, "version", create_project_body_settings->version) == NULL) {
    goto fail; //Numeric
    }
    }


    // create_project_body_settings->internet_access
    if(create_project_body_settings->internet_access) {
    if(cJSON_AddBoolToObject(item, "internetAccess", create_project_body_settings->internet_access) == NULL) {
    goto fail; //Bool
    }
    }


    // create_project_body_settings->dhcp
    if(create_project_body_settings->dhcp) {
    if(cJSON_AddBoolToObject(item, "dhcp", create_project_body_settings->dhcp) == NULL) {
    goto fail; //Bool
    }
    }


    // create_project_body_settings->connection
    if(create_project_body_settings->connection) {
    if(cJSON_AddStringToObject(item, "connection", create_project_body_settings->connection) == NULL) {
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

create_project_body_settings_t *create_project_body_settings_parseFromJSON(cJSON *create_project_body_settingsJSON){

    create_project_body_settings_t *create_project_body_settings_local_var = NULL;

    // create_project_body_settings->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(create_project_body_settingsJSON, "version");
    if (cJSON_IsNull(version)) {
        version = NULL;
    }
    if (version) { 
    if(!cJSON_IsNumber(version))
    {
    goto end; //Numeric
    }
    }

    // create_project_body_settings->internet_access
    cJSON *internet_access = cJSON_GetObjectItemCaseSensitive(create_project_body_settingsJSON, "internetAccess");
    if (cJSON_IsNull(internet_access)) {
        internet_access = NULL;
    }
    if (internet_access) { 
    if(!cJSON_IsBool(internet_access))
    {
    goto end; //Bool
    }
    }

    // create_project_body_settings->dhcp
    cJSON *dhcp = cJSON_GetObjectItemCaseSensitive(create_project_body_settingsJSON, "dhcp");
    if (cJSON_IsNull(dhcp)) {
        dhcp = NULL;
    }
    if (dhcp) { 
    if(!cJSON_IsBool(dhcp))
    {
    goto end; //Bool
    }
    }

    // create_project_body_settings->connection
    cJSON *connection = cJSON_GetObjectItemCaseSensitive(create_project_body_settingsJSON, "connection");
    if (cJSON_IsNull(connection)) {
        connection = NULL;
    }
    if (connection) { 
    if(!cJSON_IsString(connection) && !cJSON_IsNull(connection))
    {
    goto end; //String
    }
    }


    create_project_body_settings_local_var = create_project_body_settings_create_internal (
        version ? version->valuedouble : 0,
        internet_access ? internet_access->valueint : 0,
        dhcp ? dhcp->valueint : 0,
        connection && !cJSON_IsNull(connection) ? strdup(connection->valuestring) : NULL
        );

    return create_project_body_settings_local_var;
end:
    return NULL;

}
