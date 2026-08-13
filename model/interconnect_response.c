#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "interconnect_response.h"


char* interconnect_response_type_ToString(corellium_api_interconnect_response_TYPE_e type) {
    char* typeArray[] =  { "NULL", "hub", "switch" };
    return typeArray[type];
}

corellium_api_interconnect_response_TYPE_e interconnect_response_type_FromString(char* type){
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

static interconnect_response_t *interconnect_response_create_internal(
    char *id,
    char *name,
    char *protocol,
    corellium_api_interconnect_response_TYPE_e type,
    char *project,
    char *status,
    list_t *interfaces,
    char *created_at,
    char *updated_at
    ) {
    interconnect_response_t *interconnect_response_local_var = malloc(sizeof(interconnect_response_t));
    if (!interconnect_response_local_var) {
        return NULL;
    }
    interconnect_response_local_var->id = id;
    interconnect_response_local_var->name = name;
    interconnect_response_local_var->protocol = protocol;
    interconnect_response_local_var->type = type;
    interconnect_response_local_var->project = project;
    interconnect_response_local_var->status = status;
    interconnect_response_local_var->interfaces = interfaces;
    interconnect_response_local_var->created_at = created_at;
    interconnect_response_local_var->updated_at = updated_at;

    interconnect_response_local_var->_library_owned = 1;
    return interconnect_response_local_var;
}

__attribute__((deprecated)) interconnect_response_t *interconnect_response_create(
    char *id,
    char *name,
    char *protocol,
    corellium_api_interconnect_response_TYPE_e type,
    char *project,
    char *status,
    list_t *interfaces,
    char *created_at,
    char *updated_at
    ) {
    return interconnect_response_create_internal (
        id,
        name,
        protocol,
        type,
        project,
        status,
        interfaces,
        created_at,
        updated_at
        );
}

void interconnect_response_free(interconnect_response_t *interconnect_response) {
    if(NULL == interconnect_response){
        return ;
    }
    if(interconnect_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "interconnect_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (interconnect_response->id) {
        free(interconnect_response->id);
        interconnect_response->id = NULL;
    }
    if (interconnect_response->name) {
        free(interconnect_response->name);
        interconnect_response->name = NULL;
    }
    if (interconnect_response->protocol) {
        free(interconnect_response->protocol);
        interconnect_response->protocol = NULL;
    }
    if (interconnect_response->project) {
        free(interconnect_response->project);
        interconnect_response->project = NULL;
    }
    if (interconnect_response->status) {
        free(interconnect_response->status);
        interconnect_response->status = NULL;
    }
    if (interconnect_response->interfaces) {
        list_ForEach(listEntry, interconnect_response->interfaces) {
            instance_interface_free(listEntry->data);
        }
        list_freeList(interconnect_response->interfaces);
        interconnect_response->interfaces = NULL;
    }
    if (interconnect_response->created_at) {
        free(interconnect_response->created_at);
        interconnect_response->created_at = NULL;
    }
    if (interconnect_response->updated_at) {
        free(interconnect_response->updated_at);
        interconnect_response->updated_at = NULL;
    }
    free(interconnect_response);
}

cJSON *interconnect_response_convertToJSON(interconnect_response_t *interconnect_response) {
    cJSON *item = cJSON_CreateObject();

    // interconnect_response->id
    if(interconnect_response->id) {
    if(cJSON_AddStringToObject(item, "id", interconnect_response->id) == NULL) {
    goto fail; //String
    }
    }


    // interconnect_response->name
    if(interconnect_response->name) {
    if(cJSON_AddStringToObject(item, "name", interconnect_response->name) == NULL) {
    goto fail; //String
    }
    }


    // interconnect_response->protocol
    if(interconnect_response->protocol) {
    if(cJSON_AddStringToObject(item, "protocol", interconnect_response->protocol) == NULL) {
    goto fail; //String
    }
    }


    // interconnect_response->type
    if(interconnect_response->type != corellium_api_interconnect_response_TYPE_NULL) {
    if(cJSON_AddStringToObject(item, "type", interconnect_response_type_ToString(interconnect_response->type)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // interconnect_response->project
    if(interconnect_response->project) {
    if(cJSON_AddStringToObject(item, "project", interconnect_response->project) == NULL) {
    goto fail; //String
    }
    }


    // interconnect_response->status
    if(interconnect_response->status) {
    if(cJSON_AddStringToObject(item, "status", interconnect_response->status) == NULL) {
    goto fail; //String
    }
    }


    // interconnect_response->interfaces
    if(interconnect_response->interfaces) {
    cJSON *interfaces = cJSON_AddArrayToObject(item, "interfaces");
    if(interfaces == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *interfacesListEntry;
    if (interconnect_response->interfaces) {
    list_ForEach(interfacesListEntry, interconnect_response->interfaces) {
    cJSON *itemLocal = instance_interface_convertToJSON(interfacesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(interfaces, itemLocal);
    }
    }
    }


    // interconnect_response->created_at
    if(interconnect_response->created_at) {
    if(cJSON_AddStringToObject(item, "createdAt", interconnect_response->created_at) == NULL) {
    goto fail; //String
    }
    }


    // interconnect_response->updated_at
    if(interconnect_response->updated_at) {
    if(cJSON_AddStringToObject(item, "updatedAt", interconnect_response->updated_at) == NULL) {
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

interconnect_response_t *interconnect_response_parseFromJSON(cJSON *interconnect_responseJSON){

    interconnect_response_t *interconnect_response_local_var = NULL;

    // define the local list for interconnect_response->interfaces
    list_t *interfacesList = NULL;

    // interconnect_response->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(interconnect_responseJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (id) { 
    if(!cJSON_IsString(id) && !cJSON_IsNull(id))
    {
    goto end; //String
    }
    }

    // interconnect_response->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(interconnect_responseJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // interconnect_response->protocol
    cJSON *protocol = cJSON_GetObjectItemCaseSensitive(interconnect_responseJSON, "protocol");
    if (cJSON_IsNull(protocol)) {
        protocol = NULL;
    }
    if (protocol) { 
    if(!cJSON_IsString(protocol) && !cJSON_IsNull(protocol))
    {
    goto end; //String
    }
    }

    // interconnect_response->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(interconnect_responseJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    corellium_api_interconnect_response_TYPE_e typeVariable;
    if (type) { 
    if(!cJSON_IsString(type))
    {
    goto end; //Enum
    }
    typeVariable = interconnect_response_type_FromString(type->valuestring);
    }

    // interconnect_response->project
    cJSON *project = cJSON_GetObjectItemCaseSensitive(interconnect_responseJSON, "project");
    if (cJSON_IsNull(project)) {
        project = NULL;
    }
    if (project) { 
    if(!cJSON_IsString(project) && !cJSON_IsNull(project))
    {
    goto end; //String
    }
    }

    // interconnect_response->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(interconnect_responseJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    if(!cJSON_IsString(status) && !cJSON_IsNull(status))
    {
    goto end; //String
    }
    }

    // interconnect_response->interfaces
    cJSON *interfaces = cJSON_GetObjectItemCaseSensitive(interconnect_responseJSON, "interfaces");
    if (cJSON_IsNull(interfaces)) {
        interfaces = NULL;
    }
    if (interfaces) { 
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
        instance_interface_t *interfacesItem = instance_interface_parseFromJSON(interfaces_local_nonprimitive);

        list_addElement(interfacesList, interfacesItem);
    }
    }

    // interconnect_response->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(interconnect_responseJSON, "createdAt");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (created_at) { 
    if(!cJSON_IsString(created_at) && !cJSON_IsNull(created_at))
    {
    goto end; //String
    }
    }

    // interconnect_response->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(interconnect_responseJSON, "updatedAt");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (updated_at) { 
    if(!cJSON_IsString(updated_at) && !cJSON_IsNull(updated_at))
    {
    goto end; //String
    }
    }


    interconnect_response_local_var = interconnect_response_create_internal (
        id && !cJSON_IsNull(id) ? strdup(id->valuestring) : NULL,
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        protocol && !cJSON_IsNull(protocol) ? strdup(protocol->valuestring) : NULL,
        type ? typeVariable : corellium_api_interconnect_response_TYPE_NULL,
        project && !cJSON_IsNull(project) ? strdup(project->valuestring) : NULL,
        status && !cJSON_IsNull(status) ? strdup(status->valuestring) : NULL,
        interfaces ? interfacesList : NULL,
        created_at && !cJSON_IsNull(created_at) ? strdup(created_at->valuestring) : NULL,
        updated_at && !cJSON_IsNull(updated_at) ? strdup(updated_at->valuestring) : NULL
        );

    return interconnect_response_local_var;
end:
    if (interfacesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, interfacesList) {
            instance_interface_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(interfacesList);
        interfacesList = NULL;
    }
    return NULL;

}
