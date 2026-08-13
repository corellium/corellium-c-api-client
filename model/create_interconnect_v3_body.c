#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_interconnect_v3_body.h"


char* create_interconnect_v3_body_type_ToString(corellium_api_create_interconnect_v3_body_TYPE_e type) {
    char* typeArray[] =  { "NULL", "hub", "switch" };
    return typeArray[type];
}

corellium_api_create_interconnect_v3_body_TYPE_e create_interconnect_v3_body_type_FromString(char* type){
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

static create_interconnect_v3_body_t *create_interconnect_v3_body_create_internal(
    char *name,
    char *protocol,
    corellium_api_create_interconnect_v3_body_TYPE_e type,
    list_t *interfaces,
    char *project_id
    ) {
    create_interconnect_v3_body_t *create_interconnect_v3_body_local_var = malloc(sizeof(create_interconnect_v3_body_t));
    if (!create_interconnect_v3_body_local_var) {
        return NULL;
    }
    create_interconnect_v3_body_local_var->name = name;
    create_interconnect_v3_body_local_var->protocol = protocol;
    create_interconnect_v3_body_local_var->type = type;
    create_interconnect_v3_body_local_var->interfaces = interfaces;
    create_interconnect_v3_body_local_var->project_id = project_id;

    create_interconnect_v3_body_local_var->_library_owned = 1;
    return create_interconnect_v3_body_local_var;
}

__attribute__((deprecated)) create_interconnect_v3_body_t *create_interconnect_v3_body_create(
    char *name,
    char *protocol,
    corellium_api_create_interconnect_v3_body_TYPE_e type,
    list_t *interfaces,
    char *project_id
    ) {
    return create_interconnect_v3_body_create_internal (
        name,
        protocol,
        type,
        interfaces,
        project_id
        );
}

void create_interconnect_v3_body_free(create_interconnect_v3_body_t *create_interconnect_v3_body) {
    if(NULL == create_interconnect_v3_body){
        return ;
    }
    if(create_interconnect_v3_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "create_interconnect_v3_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (create_interconnect_v3_body->name) {
        free(create_interconnect_v3_body->name);
        create_interconnect_v3_body->name = NULL;
    }
    if (create_interconnect_v3_body->protocol) {
        free(create_interconnect_v3_body->protocol);
        create_interconnect_v3_body->protocol = NULL;
    }
    if (create_interconnect_v3_body->interfaces) {
        list_ForEach(listEntry, create_interconnect_v3_body->interfaces) {
            interfaces_schema_inner_free(listEntry->data);
        }
        list_freeList(create_interconnect_v3_body->interfaces);
        create_interconnect_v3_body->interfaces = NULL;
    }
    if (create_interconnect_v3_body->project_id) {
        free(create_interconnect_v3_body->project_id);
        create_interconnect_v3_body->project_id = NULL;
    }
    free(create_interconnect_v3_body);
}

cJSON *create_interconnect_v3_body_convertToJSON(create_interconnect_v3_body_t *create_interconnect_v3_body) {
    cJSON *item = cJSON_CreateObject();

    // create_interconnect_v3_body->name
    if (!create_interconnect_v3_body->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", create_interconnect_v3_body->name) == NULL) {
    goto fail; //String
    }


    // create_interconnect_v3_body->protocol
    if (!create_interconnect_v3_body->protocol) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "protocol", create_interconnect_v3_body->protocol) == NULL) {
    goto fail; //String
    }


    // create_interconnect_v3_body->type
    if (corellium_api_create_interconnect_v3_body_TYPE_NULL == create_interconnect_v3_body->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", create_interconnect_v3_body_type_ToString(create_interconnect_v3_body->type)) == NULL)
    {
    goto fail; //Enum
    }


    // create_interconnect_v3_body->interfaces
    if (!create_interconnect_v3_body->interfaces) {
        goto fail;
    }
    cJSON *interfaces = cJSON_AddArrayToObject(item, "interfaces");
    if(interfaces == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *interfacesListEntry;
    if (create_interconnect_v3_body->interfaces) {
    list_ForEach(interfacesListEntry, create_interconnect_v3_body->interfaces) {
    cJSON *itemLocal = interfaces_schema_inner_convertToJSON(interfacesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(interfaces, itemLocal);
    }
    }


    // create_interconnect_v3_body->project_id
    if (!create_interconnect_v3_body->project_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "projectId", create_interconnect_v3_body->project_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

create_interconnect_v3_body_t *create_interconnect_v3_body_parseFromJSON(cJSON *create_interconnect_v3_bodyJSON){

    create_interconnect_v3_body_t *create_interconnect_v3_body_local_var = NULL;

    // define the local list for create_interconnect_v3_body->interfaces
    list_t *interfacesList = NULL;

    // create_interconnect_v3_body->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(create_interconnect_v3_bodyJSON, "name");
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

    // create_interconnect_v3_body->protocol
    cJSON *protocol = cJSON_GetObjectItemCaseSensitive(create_interconnect_v3_bodyJSON, "protocol");
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

    // create_interconnect_v3_body->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(create_interconnect_v3_bodyJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    corellium_api_create_interconnect_v3_body_TYPE_e typeVariable;
    
    if(!cJSON_IsString(type))
    {
    goto end; //Enum
    }
    typeVariable = create_interconnect_v3_body_type_FromString(type->valuestring);

    // create_interconnect_v3_body->interfaces
    cJSON *interfaces = cJSON_GetObjectItemCaseSensitive(create_interconnect_v3_bodyJSON, "interfaces");
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

    // create_interconnect_v3_body->project_id
    cJSON *project_id = cJSON_GetObjectItemCaseSensitive(create_interconnect_v3_bodyJSON, "projectId");
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


    create_interconnect_v3_body_local_var = create_interconnect_v3_body_create_internal (
        strdup(name->valuestring),
        strdup(protocol->valuestring),
        typeVariable,
        interfacesList,
        strdup(project_id->valuestring)
        );

    return create_interconnect_v3_body_local_var;
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
