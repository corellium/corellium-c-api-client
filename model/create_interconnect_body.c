#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_interconnect_body.h"


char* create_interconnect_body_type_ToString(corellium_api_create_interconnect_body_TYPE_e type) {
    char* typeArray[] =  { "NULL", "hub", "switch" };
    return typeArray[type];
}

corellium_api_create_interconnect_body_TYPE_e create_interconnect_body_type_FromString(char* type){
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

static create_interconnect_body_t *create_interconnect_body_create_internal(
    char *name,
    char *protocol,
    corellium_api_create_interconnect_body_TYPE_e type,
    char *project,
    list_t *interfaces
    ) {
    create_interconnect_body_t *create_interconnect_body_local_var = malloc(sizeof(create_interconnect_body_t));
    if (!create_interconnect_body_local_var) {
        return NULL;
    }
    create_interconnect_body_local_var->name = name;
    create_interconnect_body_local_var->protocol = protocol;
    create_interconnect_body_local_var->type = type;
    create_interconnect_body_local_var->project = project;
    create_interconnect_body_local_var->interfaces = interfaces;

    create_interconnect_body_local_var->_library_owned = 1;
    return create_interconnect_body_local_var;
}

__attribute__((deprecated)) create_interconnect_body_t *create_interconnect_body_create(
    char *name,
    char *protocol,
    corellium_api_create_interconnect_body_TYPE_e type,
    char *project,
    list_t *interfaces
    ) {
    return create_interconnect_body_create_internal (
        name,
        protocol,
        type,
        project,
        interfaces
        );
}

void create_interconnect_body_free(create_interconnect_body_t *create_interconnect_body) {
    if(NULL == create_interconnect_body){
        return ;
    }
    if(create_interconnect_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "create_interconnect_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (create_interconnect_body->name) {
        free(create_interconnect_body->name);
        create_interconnect_body->name = NULL;
    }
    if (create_interconnect_body->protocol) {
        free(create_interconnect_body->protocol);
        create_interconnect_body->protocol = NULL;
    }
    if (create_interconnect_body->project) {
        free(create_interconnect_body->project);
        create_interconnect_body->project = NULL;
    }
    if (create_interconnect_body->interfaces) {
        list_ForEach(listEntry, create_interconnect_body->interfaces) {
            free(listEntry->data);
        }
        list_freeList(create_interconnect_body->interfaces);
        create_interconnect_body->interfaces = NULL;
    }
    free(create_interconnect_body);
}

cJSON *create_interconnect_body_convertToJSON(create_interconnect_body_t *create_interconnect_body) {
    cJSON *item = cJSON_CreateObject();

    // create_interconnect_body->name
    if (!create_interconnect_body->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", create_interconnect_body->name) == NULL) {
    goto fail; //String
    }


    // create_interconnect_body->protocol
    if (!create_interconnect_body->protocol) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "protocol", create_interconnect_body->protocol) == NULL) {
    goto fail; //String
    }


    // create_interconnect_body->type
    if (corellium_api_create_interconnect_body_TYPE_NULL == create_interconnect_body->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", create_interconnect_body_type_ToString(create_interconnect_body->type)) == NULL)
    {
    goto fail; //Enum
    }


    // create_interconnect_body->project
    if (!create_interconnect_body->project) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "project", create_interconnect_body->project) == NULL) {
    goto fail; //String
    }


    // create_interconnect_body->interfaces
    if (!create_interconnect_body->interfaces) {
        goto fail;
    }
    cJSON *interfaces = cJSON_AddArrayToObject(item, "interfaces");
    if(interfaces == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *interfacesListEntry;
    list_ForEach(interfacesListEntry, create_interconnect_body->interfaces) {
    if(cJSON_AddStringToObject(interfaces, "", interfacesListEntry->data) == NULL)
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

create_interconnect_body_t *create_interconnect_body_parseFromJSON(cJSON *create_interconnect_bodyJSON){

    create_interconnect_body_t *create_interconnect_body_local_var = NULL;

    // define the local list for create_interconnect_body->interfaces
    list_t *interfacesList = NULL;

    // create_interconnect_body->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(create_interconnect_bodyJSON, "name");
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

    // create_interconnect_body->protocol
    cJSON *protocol = cJSON_GetObjectItemCaseSensitive(create_interconnect_bodyJSON, "protocol");
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

    // create_interconnect_body->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(create_interconnect_bodyJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    corellium_api_create_interconnect_body_TYPE_e typeVariable;
    
    if(!cJSON_IsString(type))
    {
    goto end; //Enum
    }
    typeVariable = create_interconnect_body_type_FromString(type->valuestring);

    // create_interconnect_body->project
    cJSON *project = cJSON_GetObjectItemCaseSensitive(create_interconnect_bodyJSON, "project");
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

    // create_interconnect_body->interfaces
    cJSON *interfaces = cJSON_GetObjectItemCaseSensitive(create_interconnect_bodyJSON, "interfaces");
    if (cJSON_IsNull(interfaces)) {
        interfaces = NULL;
    }
    if (!interfaces) {
        goto end;
    }

    
    cJSON *interfaces_local = NULL;
    if(!cJSON_IsArray(interfaces)) {
        goto end;//primitive container
    }
    interfacesList = list_createList();

    cJSON_ArrayForEach(interfaces_local, interfaces)
    {
        if(!cJSON_IsString(interfaces_local))
        {
            goto end;
        }
        list_addElement(interfacesList , strdup(interfaces_local->valuestring));
    }


    create_interconnect_body_local_var = create_interconnect_body_create_internal (
        strdup(name->valuestring),
        strdup(protocol->valuestring),
        typeVariable,
        strdup(project->valuestring),
        interfacesList
        );

    return create_interconnect_body_local_var;
end:
    if (interfacesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, interfacesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(interfacesList);
        interfacesList = NULL;
    }
    return NULL;

}
