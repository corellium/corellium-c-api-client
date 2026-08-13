#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_interconnect_response_schema.h"


char* create_interconnect_response_schema_type_ToString(corellium_api_create_interconnect_response_schema_TYPE_e type) {
    char* typeArray[] =  { "NULL", "hub", "switch" };
    return typeArray[type];
}

corellium_api_create_interconnect_response_schema_TYPE_e create_interconnect_response_schema_type_FromString(char* type){
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
char* create_interconnect_response_schema_status_ToString(corellium_api_create_interconnect_response_schema_STATUS_e status) {
    char* statusArray[] =  { "NULL", "attached", "detached", "connected" };
    return statusArray[status];
}

corellium_api_create_interconnect_response_schema_STATUS_e create_interconnect_response_schema_status_FromString(char* status){
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

static create_interconnect_response_schema_t *create_interconnect_response_schema_create_internal(
    char *name,
    char *protocol,
    corellium_api_create_interconnect_response_schema_TYPE_e type,
    char *project,
    list_t *interfaces,
    char *id,
    corellium_api_create_interconnect_response_schema_STATUS_e status,
    char *created_at,
    char *updated_at
    ) {
    create_interconnect_response_schema_t *create_interconnect_response_schema_local_var = malloc(sizeof(create_interconnect_response_schema_t));
    if (!create_interconnect_response_schema_local_var) {
        return NULL;
    }
    create_interconnect_response_schema_local_var->name = name;
    create_interconnect_response_schema_local_var->protocol = protocol;
    create_interconnect_response_schema_local_var->type = type;
    create_interconnect_response_schema_local_var->project = project;
    create_interconnect_response_schema_local_var->interfaces = interfaces;
    create_interconnect_response_schema_local_var->id = id;
    create_interconnect_response_schema_local_var->status = status;
    create_interconnect_response_schema_local_var->created_at = created_at;
    create_interconnect_response_schema_local_var->updated_at = updated_at;

    create_interconnect_response_schema_local_var->_library_owned = 1;
    return create_interconnect_response_schema_local_var;
}

__attribute__((deprecated)) create_interconnect_response_schema_t *create_interconnect_response_schema_create(
    char *name,
    char *protocol,
    corellium_api_create_interconnect_response_schema_TYPE_e type,
    char *project,
    list_t *interfaces,
    char *id,
    corellium_api_create_interconnect_response_schema_STATUS_e status,
    char *created_at,
    char *updated_at
    ) {
    return create_interconnect_response_schema_create_internal (
        name,
        protocol,
        type,
        project,
        interfaces,
        id,
        status,
        created_at,
        updated_at
        );
}

void create_interconnect_response_schema_free(create_interconnect_response_schema_t *create_interconnect_response_schema) {
    if(NULL == create_interconnect_response_schema){
        return ;
    }
    if(create_interconnect_response_schema->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "create_interconnect_response_schema_free");
        return ;
    }
    listEntry_t *listEntry;
    if (create_interconnect_response_schema->name) {
        free(create_interconnect_response_schema->name);
        create_interconnect_response_schema->name = NULL;
    }
    if (create_interconnect_response_schema->protocol) {
        free(create_interconnect_response_schema->protocol);
        create_interconnect_response_schema->protocol = NULL;
    }
    if (create_interconnect_response_schema->project) {
        free(create_interconnect_response_schema->project);
        create_interconnect_response_schema->project = NULL;
    }
    if (create_interconnect_response_schema->interfaces) {
        list_ForEach(listEntry, create_interconnect_response_schema->interfaces) {
            interfaces_schema_inner_free(listEntry->data);
        }
        list_freeList(create_interconnect_response_schema->interfaces);
        create_interconnect_response_schema->interfaces = NULL;
    }
    if (create_interconnect_response_schema->id) {
        free(create_interconnect_response_schema->id);
        create_interconnect_response_schema->id = NULL;
    }
    if (create_interconnect_response_schema->created_at) {
        free(create_interconnect_response_schema->created_at);
        create_interconnect_response_schema->created_at = NULL;
    }
    if (create_interconnect_response_schema->updated_at) {
        free(create_interconnect_response_schema->updated_at);
        create_interconnect_response_schema->updated_at = NULL;
    }
    free(create_interconnect_response_schema);
}

cJSON *create_interconnect_response_schema_convertToJSON(create_interconnect_response_schema_t *create_interconnect_response_schema) {
    cJSON *item = cJSON_CreateObject();

    // create_interconnect_response_schema->name
    if (!create_interconnect_response_schema->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", create_interconnect_response_schema->name) == NULL) {
    goto fail; //String
    }


    // create_interconnect_response_schema->protocol
    if (!create_interconnect_response_schema->protocol) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "protocol", create_interconnect_response_schema->protocol) == NULL) {
    goto fail; //String
    }


    // create_interconnect_response_schema->type
    if (corellium_api_create_interconnect_response_schema_TYPE_NULL == create_interconnect_response_schema->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", create_interconnect_response_schema_type_ToString(create_interconnect_response_schema->type)) == NULL)
    {
    goto fail; //Enum
    }


    // create_interconnect_response_schema->project
    if (!create_interconnect_response_schema->project) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "project", create_interconnect_response_schema->project) == NULL) {
    goto fail; //String
    }


    // create_interconnect_response_schema->interfaces
    if (!create_interconnect_response_schema->interfaces) {
        goto fail;
    }
    cJSON *interfaces = cJSON_AddArrayToObject(item, "interfaces");
    if(interfaces == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *interfacesListEntry;
    if (create_interconnect_response_schema->interfaces) {
    list_ForEach(interfacesListEntry, create_interconnect_response_schema->interfaces) {
    cJSON *itemLocal = interfaces_schema_inner_convertToJSON(interfacesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(interfaces, itemLocal);
    }
    }


    // create_interconnect_response_schema->id
    if (!create_interconnect_response_schema->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", create_interconnect_response_schema->id) == NULL) {
    goto fail; //String
    }


    // create_interconnect_response_schema->status
    if (corellium_api_create_interconnect_response_schema_STATUS_NULL == create_interconnect_response_schema->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", create_interconnect_response_schema_status_ToString(create_interconnect_response_schema->status)) == NULL)
    {
    goto fail; //Enum
    }


    // create_interconnect_response_schema->created_at
    if (!create_interconnect_response_schema->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "createdAt", create_interconnect_response_schema->created_at) == NULL) {
    goto fail; //Date-Time
    }


    // create_interconnect_response_schema->updated_at
    if (!create_interconnect_response_schema->updated_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "updatedAt", create_interconnect_response_schema->updated_at) == NULL) {
    goto fail; //Date-Time
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

create_interconnect_response_schema_t *create_interconnect_response_schema_parseFromJSON(cJSON *create_interconnect_response_schemaJSON){

    create_interconnect_response_schema_t *create_interconnect_response_schema_local_var = NULL;

    // define the local list for create_interconnect_response_schema->interfaces
    list_t *interfacesList = NULL;

    // create_interconnect_response_schema->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(create_interconnect_response_schemaJSON, "name");
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

    // create_interconnect_response_schema->protocol
    cJSON *protocol = cJSON_GetObjectItemCaseSensitive(create_interconnect_response_schemaJSON, "protocol");
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

    // create_interconnect_response_schema->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(create_interconnect_response_schemaJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    corellium_api_create_interconnect_response_schema_TYPE_e typeVariable;
    
    if(!cJSON_IsString(type))
    {
    goto end; //Enum
    }
    typeVariable = create_interconnect_response_schema_type_FromString(type->valuestring);

    // create_interconnect_response_schema->project
    cJSON *project = cJSON_GetObjectItemCaseSensitive(create_interconnect_response_schemaJSON, "project");
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

    // create_interconnect_response_schema->interfaces
    cJSON *interfaces = cJSON_GetObjectItemCaseSensitive(create_interconnect_response_schemaJSON, "interfaces");
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

    // create_interconnect_response_schema->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(create_interconnect_response_schemaJSON, "id");
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

    // create_interconnect_response_schema->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(create_interconnect_response_schemaJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    corellium_api_create_interconnect_response_schema_STATUS_e statusVariable;
    
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = create_interconnect_response_schema_status_FromString(status->valuestring);

    // create_interconnect_response_schema->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(create_interconnect_response_schemaJSON, "createdAt");
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

    // create_interconnect_response_schema->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(create_interconnect_response_schemaJSON, "updatedAt");
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


    create_interconnect_response_schema_local_var = create_interconnect_response_schema_create_internal (
        strdup(name->valuestring),
        strdup(protocol->valuestring),
        typeVariable,
        strdup(project->valuestring),
        interfacesList,
        strdup(id->valuestring),
        statusVariable,
        strdup(created_at->valuestring),
        strdup(updated_at->valuestring)
        );

    return create_interconnect_response_schema_local_var;
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
