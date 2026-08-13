#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "update_interconnect_body.h"



static update_interconnect_body_t *update_interconnect_body_create_internal(
    char *name,
    list_t *interfaces
    ) {
    update_interconnect_body_t *update_interconnect_body_local_var = malloc(sizeof(update_interconnect_body_t));
    if (!update_interconnect_body_local_var) {
        return NULL;
    }
    update_interconnect_body_local_var->name = name;
    update_interconnect_body_local_var->interfaces = interfaces;

    update_interconnect_body_local_var->_library_owned = 1;
    return update_interconnect_body_local_var;
}

__attribute__((deprecated)) update_interconnect_body_t *update_interconnect_body_create(
    char *name,
    list_t *interfaces
    ) {
    return update_interconnect_body_create_internal (
        name,
        interfaces
        );
}

void update_interconnect_body_free(update_interconnect_body_t *update_interconnect_body) {
    if(NULL == update_interconnect_body){
        return ;
    }
    if(update_interconnect_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "update_interconnect_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (update_interconnect_body->name) {
        free(update_interconnect_body->name);
        update_interconnect_body->name = NULL;
    }
    if (update_interconnect_body->interfaces) {
        list_ForEach(listEntry, update_interconnect_body->interfaces) {
            object_free(listEntry->data);
        }
        list_freeList(update_interconnect_body->interfaces);
        update_interconnect_body->interfaces = NULL;
    }
    free(update_interconnect_body);
}

cJSON *update_interconnect_body_convertToJSON(update_interconnect_body_t *update_interconnect_body) {
    cJSON *item = cJSON_CreateObject();

    // update_interconnect_body->name
    if (!update_interconnect_body->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", update_interconnect_body->name) == NULL) {
    goto fail; //String
    }


    // update_interconnect_body->interfaces
    if (!update_interconnect_body->interfaces) {
        goto fail;
    }
    cJSON *interfaces = cJSON_AddArrayToObject(item, "interfaces");
    if(interfaces == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *interfacesListEntry;
    if (update_interconnect_body->interfaces) {
    list_ForEach(interfacesListEntry, update_interconnect_body->interfaces) {
    cJSON *itemLocal = object_convertToJSON(interfacesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(interfaces, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

update_interconnect_body_t *update_interconnect_body_parseFromJSON(cJSON *update_interconnect_bodyJSON){

    update_interconnect_body_t *update_interconnect_body_local_var = NULL;

    // define the local list for update_interconnect_body->interfaces
    list_t *interfacesList = NULL;

    // update_interconnect_body->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(update_interconnect_bodyJSON, "name");
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

    // update_interconnect_body->interfaces
    cJSON *interfaces = cJSON_GetObjectItemCaseSensitive(update_interconnect_bodyJSON, "interfaces");
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
        object_t *interfacesItem = object_parseFromJSON(interfaces_local_nonprimitive);

        list_addElement(interfacesList, interfacesItem);
    }


    update_interconnect_body_local_var = update_interconnect_body_create_internal (
        strdup(name->valuestring),
        interfacesList
        );

    return update_interconnect_body_local_var;
end:
    if (interfacesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, interfacesList) {
            object_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(interfacesList);
        interfacesList = NULL;
    }
    return NULL;

}
