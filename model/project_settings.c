#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "project_settings.h"



static project_settings_t *project_settings_create_internal(
    double version,
    int internet_access,
    int dhcp,
    char *connection
    ) {
    project_settings_t *project_settings_local_var = malloc(sizeof(project_settings_t));
    if (!project_settings_local_var) {
        return NULL;
    }
    project_settings_local_var->version = version;
    project_settings_local_var->internet_access = internet_access;
    project_settings_local_var->dhcp = dhcp;
    project_settings_local_var->connection = connection;

    project_settings_local_var->_library_owned = 1;
    return project_settings_local_var;
}

__attribute__((deprecated)) project_settings_t *project_settings_create(
    double version,
    int internet_access,
    int dhcp,
    char *connection
    ) {
    return project_settings_create_internal (
        version,
        internet_access,
        dhcp,
        connection
        );
}

void project_settings_free(project_settings_t *project_settings) {
    if(NULL == project_settings){
        return ;
    }
    if(project_settings->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "project_settings_free");
        return ;
    }
    listEntry_t *listEntry;
    if (project_settings->connection) {
        free(project_settings->connection);
        project_settings->connection = NULL;
    }
    free(project_settings);
}

cJSON *project_settings_convertToJSON(project_settings_t *project_settings) {
    cJSON *item = cJSON_CreateObject();

    // project_settings->version
    if(project_settings->version) {
    if(cJSON_AddNumberToObject(item, "version", project_settings->version) == NULL) {
    goto fail; //Numeric
    }
    }


    // project_settings->internet_access
    if(project_settings->internet_access) {
    if(cJSON_AddBoolToObject(item, "internetAccess", project_settings->internet_access) == NULL) {
    goto fail; //Bool
    }
    }


    // project_settings->dhcp
    if(project_settings->dhcp) {
    if(cJSON_AddBoolToObject(item, "dhcp", project_settings->dhcp) == NULL) {
    goto fail; //Bool
    }
    }


    // project_settings->connection
    if(project_settings->connection) {
    if(cJSON_AddStringToObject(item, "connection", project_settings->connection) == NULL) {
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

project_settings_t *project_settings_parseFromJSON(cJSON *project_settingsJSON){

    project_settings_t *project_settings_local_var = NULL;

    // project_settings->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(project_settingsJSON, "version");
    if (cJSON_IsNull(version)) {
        version = NULL;
    }
    if (version) { 
    if(!cJSON_IsNumber(version))
    {
    goto end; //Numeric
    }
    }

    // project_settings->internet_access
    cJSON *internet_access = cJSON_GetObjectItemCaseSensitive(project_settingsJSON, "internetAccess");
    if (cJSON_IsNull(internet_access)) {
        internet_access = NULL;
    }
    if (internet_access) { 
    if(!cJSON_IsBool(internet_access))
    {
    goto end; //Bool
    }
    }

    // project_settings->dhcp
    cJSON *dhcp = cJSON_GetObjectItemCaseSensitive(project_settingsJSON, "dhcp");
    if (cJSON_IsNull(dhcp)) {
        dhcp = NULL;
    }
    if (dhcp) { 
    if(!cJSON_IsBool(dhcp))
    {
    goto end; //Bool
    }
    }

    // project_settings->connection
    cJSON *connection = cJSON_GetObjectItemCaseSensitive(project_settingsJSON, "connection");
    if (cJSON_IsNull(connection)) {
        connection = NULL;
    }
    if (connection) { 
    if(!cJSON_IsString(connection) && !cJSON_IsNull(connection))
    {
    goto end; //String
    }
    }


    project_settings_local_var = project_settings_create_internal (
        version ? version->valuedouble : 0,
        internet_access ? internet_access->valueint : 0,
        dhcp ? dhcp->valueint : 0,
        connection && !cJSON_IsNull(connection) ? strdup(connection->valuestring) : NULL
        );

    return project_settings_local_var;
end:
    return NULL;

}
