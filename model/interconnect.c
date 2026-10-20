#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "interconnect.h"


char* interconnect_type_ToString(corellium_api_interconnect_TYPE_e type) {
    char* typeArray[] =  { "NULL", "hub", "switch" };
    return typeArray[type];
}

corellium_api_interconnect_TYPE_e interconnect_type_FromString(char* type){
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
char* interconnect_status_ToString(corellium_api_interconnect_STATUS_e status) {
    char* statusArray[] =  { "NULL", "attached", "detached", "connected" };
    return statusArray[status];
}

corellium_api_interconnect_STATUS_e interconnect_status_FromString(char* status){
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

static interconnect_t *interconnect_create_internal(
    char *name,
    corellium_api_interconnect_TYPE_e type,
    char *project_id,
    list_t *interfaces,
    char *id,
    char *protocol,
    corellium_api_interconnect_STATUS_e status,
    double instance_count,
    char *created_at,
    char *updated_at
    ) {
    interconnect_t *interconnect_local_var = malloc(sizeof(interconnect_t));
    if (!interconnect_local_var) {
        return NULL;
    }
    interconnect_local_var->name = name;
    interconnect_local_var->type = type;
    interconnect_local_var->project_id = project_id;
    interconnect_local_var->interfaces = interfaces;
    interconnect_local_var->id = id;
    interconnect_local_var->protocol = protocol;
    interconnect_local_var->status = status;
    interconnect_local_var->instance_count = instance_count;
    interconnect_local_var->created_at = created_at;
    interconnect_local_var->updated_at = updated_at;

    interconnect_local_var->_library_owned = 1;
    return interconnect_local_var;
}

__attribute__((deprecated)) interconnect_t *interconnect_create(
    char *name,
    corellium_api_interconnect_TYPE_e type,
    char *project_id,
    list_t *interfaces,
    char *id,
    char *protocol,
    corellium_api_interconnect_STATUS_e status,
    double instance_count,
    char *created_at,
    char *updated_at
    ) {
    return interconnect_create_internal (
        name,
        type,
        project_id,
        interfaces,
        id,
        protocol,
        status,
        instance_count,
        created_at,
        updated_at
        );
}

void interconnect_free(interconnect_t *interconnect) {
    if(NULL == interconnect){
        return ;
    }
    if(interconnect->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "interconnect_free");
        return ;
    }
    listEntry_t *listEntry;
    if (interconnect->name) {
        free(interconnect->name);
        interconnect->name = NULL;
    }
    if (interconnect->project_id) {
        free(interconnect->project_id);
        interconnect->project_id = NULL;
    }
    if (interconnect->interfaces) {
        list_ForEach(listEntry, interconnect->interfaces) {
            interfaces_schema_inner_free(listEntry->data);
        }
        list_freeList(interconnect->interfaces);
        interconnect->interfaces = NULL;
    }
    if (interconnect->id) {
        free(interconnect->id);
        interconnect->id = NULL;
    }
    if (interconnect->protocol) {
        free(interconnect->protocol);
        interconnect->protocol = NULL;
    }
    if (interconnect->created_at) {
        free(interconnect->created_at);
        interconnect->created_at = NULL;
    }
    if (interconnect->updated_at) {
        free(interconnect->updated_at);
        interconnect->updated_at = NULL;
    }
    free(interconnect);
}

cJSON *interconnect_convertToJSON(interconnect_t *interconnect) {
    cJSON *item = cJSON_CreateObject();

    // interconnect->name
    if (!interconnect->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", interconnect->name) == NULL) {
    goto fail; //String
    }


    // interconnect->type
    if (corellium_api_interconnect_TYPE_NULL == interconnect->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", interconnect_type_ToString(interconnect->type)) == NULL)
    {
    goto fail; //Enum
    }


    // interconnect->project_id
    if (!interconnect->project_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "projectId", interconnect->project_id) == NULL) {
    goto fail; //String
    }


    // interconnect->interfaces
    if (!interconnect->interfaces) {
        goto fail;
    }
    cJSON *interfaces = cJSON_AddArrayToObject(item, "interfaces");
    if(interfaces == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *interfacesListEntry;
    if (interconnect->interfaces) {
    list_ForEach(interfacesListEntry, interconnect->interfaces) {
    cJSON *itemLocal = interfaces_schema_inner_convertToJSON(interfacesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(interfaces, itemLocal);
    }
    }


    // interconnect->id
    if (!interconnect->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", interconnect->id) == NULL) {
    goto fail; //String
    }


    // interconnect->protocol
    if (!interconnect->protocol) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "protocol", interconnect->protocol) == NULL) {
    goto fail; //String
    }


    // interconnect->status
    if (corellium_api_interconnect_STATUS_NULL == interconnect->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", interconnect_status_ToString(interconnect->status)) == NULL)
    {
    goto fail; //Enum
    }


    // interconnect->instance_count
    if (!interconnect->instance_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "instanceCount", interconnect->instance_count) == NULL) {
    goto fail; //Numeric
    }


    // interconnect->created_at
    if (!interconnect->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "createdAt", interconnect->created_at) == NULL) {
    goto fail; //Date-Time
    }


    // interconnect->updated_at
    if (!interconnect->updated_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "updatedAt", interconnect->updated_at) == NULL) {
    goto fail; //Date-Time
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

interconnect_t *interconnect_parseFromJSON(cJSON *interconnectJSON){

    interconnect_t *interconnect_local_var = NULL;

    // define the local list for interconnect->interfaces
    list_t *interfacesList = NULL;

    // interconnect->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(interconnectJSON, "name");
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

    // interconnect->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(interconnectJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    corellium_api_interconnect_TYPE_e typeVariable;
    
    if(!cJSON_IsString(type))
    {
    goto end; //Enum
    }
    typeVariable = interconnect_type_FromString(type->valuestring);

    // interconnect->project_id
    cJSON *project_id = cJSON_GetObjectItemCaseSensitive(interconnectJSON, "projectId");
    if (cJSON_IsNull(project_id)) {
        project_id = NULL;
    }
    if (!project_id) {
        goto end;
    }

    
    if(!cJSON_IsString(project_id))
    {
    goto end; //String
    }

    // interconnect->interfaces
    cJSON *interfaces = cJSON_GetObjectItemCaseSensitive(interconnectJSON, "interfaces");
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

    // interconnect->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(interconnectJSON, "id");
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

    // interconnect->protocol
    cJSON *protocol = cJSON_GetObjectItemCaseSensitive(interconnectJSON, "protocol");
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

    // interconnect->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(interconnectJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    corellium_api_interconnect_STATUS_e statusVariable;
    
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = interconnect_status_FromString(status->valuestring);

    // interconnect->instance_count
    cJSON *instance_count = cJSON_GetObjectItemCaseSensitive(interconnectJSON, "instanceCount");
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

    // interconnect->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(interconnectJSON, "createdAt");
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

    // interconnect->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(interconnectJSON, "updatedAt");
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


    interconnect_local_var = interconnect_create_internal (
        strdup(name->valuestring),
        typeVariable,
        strdup(project_id->valuestring),
        interfacesList,
        strdup(id->valuestring),
        strdup(protocol->valuestring),
        statusVariable,
        instance_count->valuedouble,
        strdup(created_at->valuestring),
        strdup(updated_at->valuestring)
        );

    return interconnect_local_var;
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
