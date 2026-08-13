#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_interconnect_response_schema.h"


char* get_interconnect_response_schema_type_ToString(corellium_api_get_interconnect_response_schema_TYPE_e type) {
    char* typeArray[] =  { "NULL", "hub", "switch" };
    return typeArray[type];
}

corellium_api_get_interconnect_response_schema_TYPE_e get_interconnect_response_schema_type_FromString(char* type){
    int stringToReturn = 0;
    char *typeArray[] =  { "NULL", "hub", "switch" };
    size_t sizeofArray = sizeof(typeArray) / sizeof(typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(type, typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}
char* get_interconnect_response_schema_status_ToString(corellium_api_get_interconnect_response_schema_STATUS_e status) {
    char* statusArray[] =  { "NULL", "attached", "detached", "connected" };
    return statusArray[status];
}

corellium_api_get_interconnect_response_schema_STATUS_e get_interconnect_response_schema_status_FromString(char* status){
    int stringToReturn = 0;
    char *statusArray[] =  { "NULL", "attached", "detached", "connected" };
    size_t sizeofArray = sizeof(statusArray) / sizeof(statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(status, statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static get_interconnect_response_schema_t *get_interconnect_response_schema_create_internal(
    char *name,
    char *protocol,
    corellium_api_get_interconnect_response_schema_TYPE_e type,
    char *project,
    list_t *interfaces,
    char *id,
    corellium_api_get_interconnect_response_schema_STATUS_e status,
    char *created_at,
    char *updated_at,
    double instance_count
    ) {
    get_interconnect_response_schema_t *get_interconnect_response_schema_local_var = malloc(sizeof(get_interconnect_response_schema_t));
    if (!get_interconnect_response_schema_local_var) {
        return NULL;
    }
    get_interconnect_response_schema_local_var->name = name;
    get_interconnect_response_schema_local_var->protocol = protocol;
    get_interconnect_response_schema_local_var->type = type;
    get_interconnect_response_schema_local_var->project = project;
    get_interconnect_response_schema_local_var->interfaces = interfaces;
    get_interconnect_response_schema_local_var->id = id;
    get_interconnect_response_schema_local_var->status = status;
    get_interconnect_response_schema_local_var->created_at = created_at;
    get_interconnect_response_schema_local_var->updated_at = updated_at;
    get_interconnect_response_schema_local_var->instance_count = instance_count;

    get_interconnect_response_schema_local_var->_library_owned = 1;
    return get_interconnect_response_schema_local_var;
}

__attribute__((deprecated)) get_interconnect_response_schema_t *get_interconnect_response_schema_create(
    char *name,
    char *protocol,
    corellium_api_get_interconnect_response_schema_TYPE_e type,
    char *project,
    list_t *interfaces,
    char *id,
    corellium_api_get_interconnect_response_schema_STATUS_e status,
    char *created_at,
    char *updated_at,
    double instance_count
    ) {
    return get_interconnect_response_schema_create_internal (
        name,
        protocol,
        type,
        project,
        interfaces,
        id,
        status,
        created_at,
        updated_at,
        instance_count
        );
}

void get_interconnect_response_schema_free(get_interconnect_response_schema_t *get_interconnect_response_schema) {
    if(NULL == get_interconnect_response_schema){
        return ;
    }
    if(get_interconnect_response_schema->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "get_interconnect_response_schema_free");
        return ;
    }
    listEntry_t *listEntry;
    if (get_interconnect_response_schema->name) {
        free(get_interconnect_response_schema->name);
        get_interconnect_response_schema->name = NULL;
    }
    if (get_interconnect_response_schema->protocol) {
        free(get_interconnect_response_schema->protocol);
        get_interconnect_response_schema->protocol = NULL;
    }
    if (get_interconnect_response_schema->project) {
        free(get_interconnect_response_schema->project);
        get_interconnect_response_schema->project = NULL;
    }
    if (get_interconnect_response_schema->interfaces) {
        list_ForEach(listEntry, get_interconnect_response_schema->interfaces) {
            interfaces_schema_inner_free(listEntry->data);
        }
        list_freeList(get_interconnect_response_schema->interfaces);
        get_interconnect_response_schema->interfaces = NULL;
    }
    if (get_interconnect_response_schema->id) {
        free(get_interconnect_response_schema->id);
        get_interconnect_response_schema->id = NULL;
    }
    if (get_interconnect_response_schema->created_at) {
        free(get_interconnect_response_schema->created_at);
        get_interconnect_response_schema->created_at = NULL;
    }
    if (get_interconnect_response_schema->updated_at) {
        free(get_interconnect_response_schema->updated_at);
        get_interconnect_response_schema->updated_at = NULL;
    }
    free(get_interconnect_response_schema);
}

cJSON *get_interconnect_response_schema_convertToJSON(get_interconnect_response_schema_t *get_interconnect_response_schema) {
    cJSON *item = cJSON_CreateObject();

    // get_interconnect_response_schema->name
    if (!get_interconnect_response_schema->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", get_interconnect_response_schema->name) == NULL) {
    goto fail; //String
    }


    // get_interconnect_response_schema->protocol
    if (!get_interconnect_response_schema->protocol) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "protocol", get_interconnect_response_schema->protocol) == NULL) {
    goto fail; //String
    }


    // get_interconnect_response_schema->type
    if (corellium_api_get_interconnect_response_schema_TYPE_NULL == get_interconnect_response_schema->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", get_interconnect_response_schema_type_ToString(get_interconnect_response_schema->type)) == NULL)
    {
    goto fail; //Enum
    }


    // get_interconnect_response_schema->project
    if (!get_interconnect_response_schema->project) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "project", get_interconnect_response_schema->project) == NULL) {
    goto fail; //String
    }


    // get_interconnect_response_schema->interfaces
    if (!get_interconnect_response_schema->interfaces) {
        goto fail;
    }
    cJSON *interfaces = cJSON_AddArrayToObject(item, "interfaces");
    if(interfaces == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *interfacesListEntry;
    if (get_interconnect_response_schema->interfaces) {
    list_ForEach(interfacesListEntry, get_interconnect_response_schema->interfaces) {
    cJSON *itemLocal = interfaces_schema_inner_convertToJSON(interfacesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(interfaces, itemLocal);
    }
    }


    // get_interconnect_response_schema->id
    if (!get_interconnect_response_schema->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", get_interconnect_response_schema->id) == NULL) {
    goto fail; //String
    }


    // get_interconnect_response_schema->status
    if (corellium_api_get_interconnect_response_schema_STATUS_NULL == get_interconnect_response_schema->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", get_interconnect_response_schema_status_ToString(get_interconnect_response_schema->status)) == NULL)
    {
    goto fail; //Enum
    }


    // get_interconnect_response_schema->created_at
    if (!get_interconnect_response_schema->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "createdAt", get_interconnect_response_schema->created_at) == NULL) {
    goto fail; //Date-Time
    }


    // get_interconnect_response_schema->updated_at
    if (!get_interconnect_response_schema->updated_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "updatedAt", get_interconnect_response_schema->updated_at) == NULL) {
    goto fail; //Date-Time
    }


    // get_interconnect_response_schema->instance_count
    if (!get_interconnect_response_schema->instance_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "instanceCount", get_interconnect_response_schema->instance_count) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

get_interconnect_response_schema_t *get_interconnect_response_schema_parseFromJSON(cJSON *get_interconnect_response_schemaJSON){

    get_interconnect_response_schema_t *get_interconnect_response_schema_local_var = NULL;

    // define the local list for get_interconnect_response_schema->interfaces
    list_t *interfacesList = NULL;

    // get_interconnect_response_schema->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(get_interconnect_response_schemaJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // get_interconnect_response_schema->protocol
    cJSON *protocol = cJSON_GetObjectItemCaseSensitive(get_interconnect_response_schemaJSON, "protocol");
    if (cJSON_IsNull(protocol)) {
        protocol = NULL;
    }
    if (!protocol) {
        goto end;
    }

    
    if(!cJSON_IsString(protocol))
    {
    goto end; //String
    }

    // get_interconnect_response_schema->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(get_interconnect_response_schemaJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    corellium_api_get_interconnect_response_schema_TYPE_e typeVariable;
    
    if(!cJSON_IsString(type))
    {
    goto end; //Enum
    }
    typeVariable = get_interconnect_response_schema_type_FromString(type->valuestring);

    // get_interconnect_response_schema->project
    cJSON *project = cJSON_GetObjectItemCaseSensitive(get_interconnect_response_schemaJSON, "project");
    if (cJSON_IsNull(project)) {
        project = NULL;
    }
    if (!project) {
        goto end;
    }

    
    if(!cJSON_IsString(project))
    {
    goto end; //String
    }

    // get_interconnect_response_schema->interfaces
    cJSON *interfaces = cJSON_GetObjectItemCaseSensitive(get_interconnect_response_schemaJSON, "interfaces");
    if (cJSON_IsNull(interfaces)) {
        interfaces = NULL;
    }
    if (!interfaces) {
        goto end;
    }

    
    cJSON *interfaces_local_nonprimitive = NULL;
    if(!cJSON_IsArray(interfaces)){
        goto end; //nonprimitive container
    }

    interfacesList = list_createList();

    cJSON_ArrayForEach(interfaces_local_nonprimitive,interfaces )
    {
        if(!cJSON_IsObject(interfaces_local_nonprimitive)){
            goto end;
        }
        interfaces_schema_inner_t *interfacesItem = interfaces_schema_inner_parseFromJSON(interfaces_local_nonprimitive);

        list_addElement(interfacesList, interfacesItem);
    }

    // get_interconnect_response_schema->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(get_interconnect_response_schemaJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }

    // get_interconnect_response_schema->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(get_interconnect_response_schemaJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    corellium_api_get_interconnect_response_schema_STATUS_e statusVariable;
    
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = get_interconnect_response_schema_status_FromString(status->valuestring);

    // get_interconnect_response_schema->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(get_interconnect_response_schemaJSON, "createdAt");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (!created_at) {
        goto end;
    }

    
    if(!cJSON_IsString(created_at) && !cJSON_IsNull(created_at))
    {
    goto end; //DateTime
    }

    // get_interconnect_response_schema->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(get_interconnect_response_schemaJSON, "updatedAt");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (!updated_at) {
        goto end;
    }

    
    if(!cJSON_IsString(updated_at) && !cJSON_IsNull(updated_at))
    {
    goto end; //DateTime
    }

    // get_interconnect_response_schema->instance_count
    cJSON *instance_count = cJSON_GetObjectItemCaseSensitive(get_interconnect_response_schemaJSON, "instanceCount");
    if (cJSON_IsNull(instance_count)) {
        instance_count = NULL;
    }
    if (!instance_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(instance_count))
    {
    goto end; //Numeric
    }


    get_interconnect_response_schema_local_var = get_interconnect_response_schema_create_internal (
        strdup(name->valuestring),
        strdup(protocol->valuestring),
        typeVariable,
        strdup(project->valuestring),
        interfacesList,
        strdup(id->valuestring),
        statusVariable,
        strdup(created_at->valuestring),
        strdup(updated_at->valuestring),
        instance_count->valuedouble
        );

    return get_interconnect_response_schema_local_var;
end:
    if (interfacesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, interfacesList) {
            interfaces_schema_inner_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(interfacesList);
        interfacesList = NULL;
    }
    return NULL;

}
