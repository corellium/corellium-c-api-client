#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "partial_update_interconnect_request.h"



static partial_update_interconnect_request_t *partial_update_interconnect_request_create_internal(
    char *name,
    list_t *interfaces
    ) {
    partial_update_interconnect_request_t *partial_update_interconnect_request_local_var = malloc(sizeof(partial_update_interconnect_request_t));
    if (!partial_update_interconnect_request_local_var) {
        return NULL;
    }
    partial_update_interconnect_request_local_var->name = name;
    partial_update_interconnect_request_local_var->interfaces = interfaces;

    partial_update_interconnect_request_local_var->_library_owned = 1;
    return partial_update_interconnect_request_local_var;
}

__attribute__((deprecated)) partial_update_interconnect_request_t *partial_update_interconnect_request_create(
    char *name,
    list_t *interfaces
    ) {
    return partial_update_interconnect_request_create_internal (
        name,
        interfaces
        );
}

void partial_update_interconnect_request_free(partial_update_interconnect_request_t *partial_update_interconnect_request) {
    if(NULL == partial_update_interconnect_request){
        return ;
    }
    if(partial_update_interconnect_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "partial_update_interconnect_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (partial_update_interconnect_request->name) {
        free(partial_update_interconnect_request->name);
        partial_update_interconnect_request->name = NULL;
    }
    if (partial_update_interconnect_request->interfaces) {
        list_ForEach(listEntry, partial_update_interconnect_request->interfaces) {
            object_free(listEntry->data);
        }
        list_freeList(partial_update_interconnect_request->interfaces);
        partial_update_interconnect_request->interfaces = NULL;
    }
    free(partial_update_interconnect_request);
}

cJSON *partial_update_interconnect_request_convertToJSON(partial_update_interconnect_request_t *partial_update_interconnect_request) {
    cJSON *item = cJSON_CreateObject();

    // partial_update_interconnect_request->name
    if(partial_update_interconnect_request->name) {
    if(cJSON_AddStringToObject(item, "name", partial_update_interconnect_request->name) == NULL) {
    goto fail; //String
    }
    }


    // partial_update_interconnect_request->interfaces
    if(partial_update_interconnect_request->interfaces) {
    cJSON *interfaces = cJSON_AddArrayToObject(item, "interfaces");
    if(interfaces == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *interfacesListEntry;
    if (partial_update_interconnect_request->interfaces) {
    list_ForEach(interfacesListEntry, partial_update_interconnect_request->interfaces) {
    cJSON *itemLocal = object_convertToJSON(interfacesListEntry->data);
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

partial_update_interconnect_request_t *partial_update_interconnect_request_parseFromJSON(cJSON *partial_update_interconnect_requestJSON){

    partial_update_interconnect_request_t *partial_update_interconnect_request_local_var = NULL;

    // define the local list for partial_update_interconnect_request->interfaces
    list_t *interfacesList = NULL;

    // partial_update_interconnect_request->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(partial_update_interconnect_requestJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // partial_update_interconnect_request->interfaces
    cJSON *interfaces = cJSON_GetObjectItemCaseSensitive(partial_update_interconnect_requestJSON, "interfaces");
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
        object_t *interfacesItem = object_parseFromJSON(interfaces_local_nonprimitive);

        list_addElement(interfacesList, interfacesItem);
    }
    }


    partial_update_interconnect_request_local_var = partial_update_interconnect_request_create_internal (
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        interfaces ? interfacesList : NULL
        );

    return partial_update_interconnect_request_local_var;
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
