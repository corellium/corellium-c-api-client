#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "update_interconnect_v3_body.h"


char* update_interconnect_v3_body_type_ToString(corellium_api_update_interconnect_v3_body_TYPE_e type) {
    char* typeArray[] =  { "NULL", "hub", "switch" };
    return typeArray[type];
}

corellium_api_update_interconnect_v3_body_TYPE_e update_interconnect_v3_body_type_FromString(char* type){
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

static update_interconnect_v3_body_t *update_interconnect_v3_body_create_internal(
    char *name,
    list_t *interfaces,
    corellium_api_update_interconnect_v3_body_TYPE_e type,
    char *project_id,
    corellium_api_interconnect_protocol__e protocol
    ) {
    update_interconnect_v3_body_t *update_interconnect_v3_body_local_var = malloc(sizeof(update_interconnect_v3_body_t));
    if (!update_interconnect_v3_body_local_var) {
        return NULL;
    }
    update_interconnect_v3_body_local_var->name = name;
    update_interconnect_v3_body_local_var->interfaces = interfaces;
    update_interconnect_v3_body_local_var->type = type;
    update_interconnect_v3_body_local_var->project_id = project_id;
    update_interconnect_v3_body_local_var->protocol = protocol;

    update_interconnect_v3_body_local_var->_library_owned = 1;
    return update_interconnect_v3_body_local_var;
}

__attribute__((deprecated)) update_interconnect_v3_body_t *update_interconnect_v3_body_create(
    char *name,
    list_t *interfaces,
    corellium_api_update_interconnect_v3_body_TYPE_e type,
    char *project_id,
    corellium_api_interconnect_protocol__e protocol
    ) {
    return update_interconnect_v3_body_create_internal (
        name,
        interfaces,
        type,
        project_id,
        protocol
        );
}

void update_interconnect_v3_body_free(update_interconnect_v3_body_t *update_interconnect_v3_body) {
    if(NULL == update_interconnect_v3_body){
        return ;
    }
    if(update_interconnect_v3_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "update_interconnect_v3_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (update_interconnect_v3_body->name) {
        free(update_interconnect_v3_body->name);
        update_interconnect_v3_body->name = NULL;
    }
    if (update_interconnect_v3_body->interfaces) {
        list_ForEach(listEntry, update_interconnect_v3_body->interfaces) {
            interfaces_schema_inner_free(listEntry->data);
        }
        list_freeList(update_interconnect_v3_body->interfaces);
        update_interconnect_v3_body->interfaces = NULL;
    }
    if (update_interconnect_v3_body->project_id) {
        free(update_interconnect_v3_body->project_id);
        update_interconnect_v3_body->project_id = NULL;
    }
    free(update_interconnect_v3_body);
}

cJSON *update_interconnect_v3_body_convertToJSON(update_interconnect_v3_body_t *update_interconnect_v3_body) {
    cJSON *item = cJSON_CreateObject();

    // update_interconnect_v3_body->name
    if (!update_interconnect_v3_body->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", update_interconnect_v3_body->name) == NULL) {
    goto fail; //String
    }


    // update_interconnect_v3_body->interfaces
    if (!update_interconnect_v3_body->interfaces) {
        goto fail;
    }
    cJSON *interfaces = cJSON_AddArrayToObject(item, "interfaces");
    if(interfaces == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *interfacesListEntry;
    if (update_interconnect_v3_body->interfaces) {
    list_ForEach(interfacesListEntry, update_interconnect_v3_body->interfaces) {
    cJSON *itemLocal = interfaces_schema_inner_convertToJSON(interfacesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(interfaces, itemLocal);
    }
    }


    // update_interconnect_v3_body->type
    if(update_interconnect_v3_body->type != corellium_api_update_interconnect_v3_body_TYPE_NULL) {
    if(cJSON_AddStringToObject(item, "type", update_interconnect_v3_body_type_ToString(update_interconnect_v3_body->type)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // update_interconnect_v3_body->project_id
    if(update_interconnect_v3_body->project_id) {
    if(cJSON_AddStringToObject(item, "projectId", update_interconnect_v3_body->project_id) == NULL) {
    goto fail; //String
    }
    }


    // update_interconnect_v3_body->protocol
    if(update_interconnect_v3_body->protocol != corellium_api_interconnect_protocol__NULL) {
    cJSON *protocol_local_JSON = interconnect_protocol_convertToJSON(update_interconnect_v3_body->protocol);
    if(protocol_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "protocol", protocol_local_JSON);
    if(item->child == NULL) {
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

update_interconnect_v3_body_t *update_interconnect_v3_body_parseFromJSON(cJSON *update_interconnect_v3_bodyJSON){

    update_interconnect_v3_body_t *update_interconnect_v3_body_local_var = NULL;

    // define the local list for update_interconnect_v3_body->interfaces
    list_t *interfacesList = NULL;

    // define the local variable for update_interconnect_v3_body->protocol
    corellium_api_interconnect_protocol__e protocol_local_nonprim = 0;

    // update_interconnect_v3_body->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(update_interconnect_v3_bodyJSON, "name");
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

    // update_interconnect_v3_body->interfaces
    cJSON *interfaces = cJSON_GetObjectItemCaseSensitive(update_interconnect_v3_bodyJSON, "interfaces");
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

    // update_interconnect_v3_body->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(update_interconnect_v3_bodyJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    corellium_api_update_interconnect_v3_body_TYPE_e typeVariable;
    if (type) { 
    if(!cJSON_IsString(type))
    {
    goto end; //Enum
    }
    typeVariable = update_interconnect_v3_body_type_FromString(type->valuestring);
    }

    // update_interconnect_v3_body->project_id
    cJSON *project_id = cJSON_GetObjectItemCaseSensitive(update_interconnect_v3_bodyJSON, "projectId");
    if (cJSON_IsNull(project_id)) {
        project_id = NULL;
    }
    if (project_id) { 
    if(!cJSON_IsString(project_id) && !cJSON_IsNull(project_id))
    {
    goto end; //String
    }
    }

    // update_interconnect_v3_body->protocol
    cJSON *protocol = cJSON_GetObjectItemCaseSensitive(update_interconnect_v3_bodyJSON, "protocol");
    if (cJSON_IsNull(protocol)) {
        protocol = NULL;
    }
    if (protocol) { 
    protocol_local_nonprim = interconnect_protocol_parseFromJSON(protocol); //custom
    }


    update_interconnect_v3_body_local_var = update_interconnect_v3_body_create_internal (
        strdup(name->valuestring),
        interfacesList,
        type ? typeVariable : corellium_api_update_interconnect_v3_body_TYPE_NULL,
        project_id && !cJSON_IsNull(project_id) ? strdup(project_id->valuestring) : NULL,
        protocol ? protocol_local_nonprim : 0
        );

    return update_interconnect_v3_body_local_var;
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
    if (protocol_local_nonprim) {
        protocol_local_nonprim = 0;
    }
    return NULL;

}
