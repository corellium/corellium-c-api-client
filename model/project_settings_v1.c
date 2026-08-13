#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "project_settings_v1.h"



static project_settings_v1_t *project_settings_v1_create_internal(
    double version,
    int internet_access,
    char *connection,
    int dhcp
    ) {
    project_settings_v1_t *project_settings_v1_local_var = malloc(sizeof(project_settings_v1_t));
    if (!project_settings_v1_local_var) {
        return NULL;
    }
    project_settings_v1_local_var->version = version;
    project_settings_v1_local_var->internet_access = internet_access;
    project_settings_v1_local_var->connection = connection;
    project_settings_v1_local_var->dhcp = dhcp;

    project_settings_v1_local_var->_library_owned = 1;
    return project_settings_v1_local_var;
}

__attribute__((deprecated)) project_settings_v1_t *project_settings_v1_create(
    double version,
    int internet_access,
    char *connection,
    int dhcp
    ) {
    return project_settings_v1_create_internal (
        version,
        internet_access,
        connection,
        dhcp
        );
}

void project_settings_v1_free(project_settings_v1_t *project_settings_v1) {
    if(NULL == project_settings_v1){
        return ;
    }
    if(project_settings_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "project_settings_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (project_settings_v1->connection) {
        free(project_settings_v1->connection);
        project_settings_v1->connection = NULL;
    }
    free(project_settings_v1);
}

cJSON *project_settings_v1_convertToJSON(project_settings_v1_t *project_settings_v1) {
    cJSON *item = cJSON_CreateObject();

    // project_settings_v1->version
    if(project_settings_v1->version) {
    if(cJSON_AddNumberToObject(item, "version", project_settings_v1->version) == NULL) {
    goto fail; //Numeric
    }
    }


    // project_settings_v1->internet_access
    if(project_settings_v1->internet_access) {
    if(cJSON_AddBoolToObject(item, "internet-access", project_settings_v1->internet_access) == NULL) {
    goto fail; //Bool
    }
    }


    // project_settings_v1->connection
    if(project_settings_v1->connection) {
    if(cJSON_AddStringToObject(item, "connection", project_settings_v1->connection) == NULL) {
    goto fail; //String
    }
    }


    // project_settings_v1->dhcp
    if(project_settings_v1->dhcp) {
    if(cJSON_AddBoolToObject(item, "dhcp", project_settings_v1->dhcp) == NULL) {
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

project_settings_v1_t *project_settings_v1_parseFromJSON(cJSON *project_settings_v1JSON){

    project_settings_v1_t *project_settings_v1_local_var = NULL;

    // project_settings_v1->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(project_settings_v1JSON, "version");
    if (cJSON_IsNull(version)) {
        version = NULL;
    }
    if (version) { 
    if(!cJSON_IsNumber(version))
    {
    goto end; //Numeric
    }
    }

    // project_settings_v1->internet_access
    cJSON *internet_access = cJSON_GetObjectItemCaseSensitive(project_settings_v1JSON, "internet-access");
    if (cJSON_IsNull(internet_access)) {
        internet_access = NULL;
    }
    if (internet_access) { 
    if(!cJSON_IsBool(internet_access))
    {
    goto end; //Bool
    }
    }

    // project_settings_v1->connection
    cJSON *connection = cJSON_GetObjectItemCaseSensitive(project_settings_v1JSON, "connection");
    if (cJSON_IsNull(connection)) {
        connection = NULL;
    }
    if (connection) { 
    if(!cJSON_IsString(connection) && !cJSON_IsNull(connection))
    {
    goto end; //String
    }
    }

    // project_settings_v1->dhcp
    cJSON *dhcp = cJSON_GetObjectItemCaseSensitive(project_settings_v1JSON, "dhcp");
    if (cJSON_IsNull(dhcp)) {
        dhcp = NULL;
    }
    if (dhcp) { 
    if(!cJSON_IsBool(dhcp))
    {
    goto end; //Bool
    }
    }


    project_settings_v1_local_var = project_settings_v1_create_internal (
        version ? version->valuedouble : 0,
        internet_access ? internet_access->valueint : 0,
        connection && !cJSON_IsNull(connection) ? strdup(connection->valuestring) : NULL,
        dhcp ? dhcp->valueint : 0
        );

    return project_settings_v1_local_var;
end:
    return NULL;

}
