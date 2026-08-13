#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "patch_interconnect_body.h"



static patch_interconnect_body_t *patch_interconnect_body_create_internal(
    char *name,
    list_t *interfaces
    ) {
    patch_interconnect_body_t *patch_interconnect_body_local_var = malloc(sizeof(patch_interconnect_body_t));
    if (!patch_interconnect_body_local_var) {
        return NULL;
    }
    patch_interconnect_body_local_var->name = name;
    patch_interconnect_body_local_var->interfaces = interfaces;

    patch_interconnect_body_local_var->_library_owned = 1;
    return patch_interconnect_body_local_var;
}

__attribute__((deprecated)) patch_interconnect_body_t *patch_interconnect_body_create(
    char *name,
    list_t *interfaces
    ) {
    return patch_interconnect_body_create_internal (
        name,
        interfaces
        );
}

void patch_interconnect_body_free(patch_interconnect_body_t *patch_interconnect_body) {
    if(NULL == patch_interconnect_body){
        return ;
    }
    if(patch_interconnect_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "patch_interconnect_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (patch_interconnect_body->name) {
        free(patch_interconnect_body->name);
        patch_interconnect_body->name = NULL;
    }
    if (patch_interconnect_body->interfaces) {
        list_ForEach(listEntry, patch_interconnect_body->interfaces) {
            interfaces_schema_inner_free(listEntry->data);
        }
        list_freeList(patch_interconnect_body->interfaces);
        patch_interconnect_body->interfaces = NULL;
    }
    free(patch_interconnect_body);
}

cJSON *patch_interconnect_body_convertToJSON(patch_interconnect_body_t *patch_interconnect_body) {
    cJSON *item = cJSON_CreateObject();

    // patch_interconnect_body->name
    if(patch_interconnect_body->name) {
    if(cJSON_AddStringToObject(item, "name", patch_interconnect_body->name) == NULL) {
    goto fail; //String
    }
    }


    // patch_interconnect_body->interfaces
    if(patch_interconnect_body->interfaces) {
    cJSON *interfaces = cJSON_AddArrayToObject(item, "interfaces");
    if(interfaces == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *interfacesListEntry;
    if (patch_interconnect_body->interfaces) {
    list_ForEach(interfacesListEntry, patch_interconnect_body->interfaces) {
    cJSON *itemLocal = interfaces_schema_inner_convertToJSON(interfacesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(interfaces, itemLocal);
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

patch_interconnect_body_t *patch_interconnect_body_parseFromJSON(cJSON *patch_interconnect_bodyJSON){

    patch_interconnect_body_t *patch_interconnect_body_local_var = NULL;

    // define the local list for patch_interconnect_body->interfaces
    list_t *interfacesList = NULL;

    // patch_interconnect_body->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(patch_interconnect_bodyJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // patch_interconnect_body->interfaces
    cJSON *interfaces = cJSON_GetObjectItemCaseSensitive(patch_interconnect_bodyJSON, "interfaces");
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
        interfaces_schema_inner_t *interfacesItem = interfaces_schema_inner_parseFromJSON(interfaces_local_nonprimitive);

        list_addElement(interfacesList, interfacesItem);
    }
    }


    patch_interconnect_body_local_var = patch_interconnect_body_create_internal (
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        interfaces ? interfacesList : NULL
        );

    return patch_interconnect_body_local_var;
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
