#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "service_endpoint_schema.h"



static service_endpoint_schema_t *service_endpoint_schema_create_internal(
    char *service_name,
    char *path,
    char *method,
    list_t *permissions
    ) {
    service_endpoint_schema_t *service_endpoint_schema_local_var = malloc(sizeof(service_endpoint_schema_t));
    if (!service_endpoint_schema_local_var) {
        return NULL;
    }
    service_endpoint_schema_local_var->service_name = service_name;
    service_endpoint_schema_local_var->path = path;
    service_endpoint_schema_local_var->method = method;
    service_endpoint_schema_local_var->permissions = permissions;

    service_endpoint_schema_local_var->_library_owned = 1;
    return service_endpoint_schema_local_var;
}

__attribute__((deprecated)) service_endpoint_schema_t *service_endpoint_schema_create(
    char *service_name,
    char *path,
    char *method,
    list_t *permissions
    ) {
    return service_endpoint_schema_create_internal (
        service_name,
        path,
        method,
        permissions
        );
}

void service_endpoint_schema_free(service_endpoint_schema_t *service_endpoint_schema) {
    if(NULL == service_endpoint_schema){
        return ;
    }
    if(service_endpoint_schema->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "service_endpoint_schema_free");
        return ;
    }
    listEntry_t *listEntry;
    if (service_endpoint_schema->service_name) {
        free(service_endpoint_schema->service_name);
        service_endpoint_schema->service_name = NULL;
    }
    if (service_endpoint_schema->path) {
        free(service_endpoint_schema->path);
        service_endpoint_schema->path = NULL;
    }
    if (service_endpoint_schema->method) {
        free(service_endpoint_schema->method);
        service_endpoint_schema->method = NULL;
    }
    if (service_endpoint_schema->permissions) {
        list_ForEach(listEntry, service_endpoint_schema->permissions) {
            free(listEntry->data);
        }
        list_freeList(service_endpoint_schema->permissions);
        service_endpoint_schema->permissions = NULL;
    }
    free(service_endpoint_schema);
}

cJSON *service_endpoint_schema_convertToJSON(service_endpoint_schema_t *service_endpoint_schema) {
    cJSON *item = cJSON_CreateObject();

    // service_endpoint_schema->service_name
    if(service_endpoint_schema->service_name) {
    if(cJSON_AddStringToObject(item, "serviceName", service_endpoint_schema->service_name) == NULL) {
    goto fail; //String
    }
    }


    // service_endpoint_schema->path
    if (!service_endpoint_schema->path) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "path", service_endpoint_schema->path) == NULL) {
    goto fail; //String
    }


    // service_endpoint_schema->method
    if (!service_endpoint_schema->method) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "method", service_endpoint_schema->method) == NULL) {
    goto fail; //String
    }


    // service_endpoint_schema->permissions
    if (!service_endpoint_schema->permissions) {
        goto fail;
    }
    cJSON *permissions = cJSON_AddArrayToObject(item, "permissions");
    if(permissions == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *permissionsListEntry;
    list_ForEach(permissionsListEntry, service_endpoint_schema->permissions) {
    if(cJSON_AddStringToObject(permissions, "", permissionsListEntry->data) == NULL)
    {
        goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

service_endpoint_schema_t *service_endpoint_schema_parseFromJSON(cJSON *service_endpoint_schemaJSON){

    service_endpoint_schema_t *service_endpoint_schema_local_var = NULL;

    // define the local list for service_endpoint_schema->permissions
    list_t *permissionsList = NULL;

    // service_endpoint_schema->service_name
    cJSON *service_name = cJSON_GetObjectItemCaseSensitive(service_endpoint_schemaJSON, "serviceName");
    if (cJSON_IsNull(service_name)) {
        service_name = NULL;
    }
    if (service_name) { 
    if(!cJSON_IsString(service_name) && !cJSON_IsNull(service_name))
    {
    goto end; //String
    }
    }

    // service_endpoint_schema->path
    cJSON *path = cJSON_GetObjectItemCaseSensitive(service_endpoint_schemaJSON, "path");
    if (cJSON_IsNull(path)) {
        path = NULL;
    }
    if (!path) {
        goto end;
    }

    
    if(!cJSON_IsString(path))
    {
    goto end; //String
    }

    // service_endpoint_schema->method
    cJSON *method = cJSON_GetObjectItemCaseSensitive(service_endpoint_schemaJSON, "method");
    if (cJSON_IsNull(method)) {
        method = NULL;
    }
    if (!method) {
        goto end;
    }

    
    if(!cJSON_IsString(method))
    {
    goto end; //String
    }

    // service_endpoint_schema->permissions
    cJSON *permissions = cJSON_GetObjectItemCaseSensitive(service_endpoint_schemaJSON, "permissions");
    if (cJSON_IsNull(permissions)) {
        permissions = NULL;
    }
    if (!permissions) {
        goto end;
    }

    
    cJSON *permissions_local = NULL;
    if(!cJSON_IsArray(permissions)) {
        goto end;//primitive container
    }
    permissionsList = list_createList();

    cJSON_ArrayForEach(permissions_local, permissions)
    {
        if(!cJSON_IsString(permissions_local))
        {
            goto end;
        }
        list_addElement(permissionsList , strdup(permissions_local->valuestring));
    }


    service_endpoint_schema_local_var = service_endpoint_schema_create_internal (
        service_name && !cJSON_IsNull(service_name) ? strdup(service_name->valuestring) : NULL,
        strdup(path->valuestring),
        strdup(method->valuestring),
        permissionsList
        );

    return service_endpoint_schema_local_var;
end:
    if (permissionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, permissionsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(permissionsList);
        permissionsList = NULL;
    }
    return NULL;

}
