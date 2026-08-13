#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "network_schema.h"



static network_schema_t *network_schema_create_internal(
    list_t *physical_interfaces,
    list_t *vpns
    ) {
    network_schema_t *network_schema_local_var = malloc(sizeof(network_schema_t));
    if (!network_schema_local_var) {
        return NULL;
    }
    network_schema_local_var->physical_interfaces = physical_interfaces;
    network_schema_local_var->vpns = vpns;

    network_schema_local_var->_library_owned = 1;
    return network_schema_local_var;
}

__attribute__((deprecated)) network_schema_t *network_schema_create(
    list_t *physical_interfaces,
    list_t *vpns
    ) {
    return network_schema_create_internal (
        physical_interfaces,
        vpns
        );
}

void network_schema_free(network_schema_t *network_schema) {
    if(NULL == network_schema){
        return ;
    }
    if(network_schema->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "network_schema_free");
        return ;
    }
    listEntry_t *listEntry;
    if (network_schema->physical_interfaces) {
        list_ForEach(listEntry, network_schema->physical_interfaces) {
            free(listEntry->data);
        }
        list_freeList(network_schema->physical_interfaces);
        network_schema->physical_interfaces = NULL;
    }
    if (network_schema->vpns) {
        list_ForEach(listEntry, network_schema->vpns) {
            vpn_schema_free(listEntry->data);
        }
        list_freeList(network_schema->vpns);
        network_schema->vpns = NULL;
    }
    free(network_schema);
}

cJSON *network_schema_convertToJSON(network_schema_t *network_schema) {
    cJSON *item = cJSON_CreateObject();

    // network_schema->physical_interfaces
    if (!network_schema->physical_interfaces) {
        goto fail;
    }
    cJSON *physical_interfaces = cJSON_AddArrayToObject(item, "physicalInterfaces");
    if(physical_interfaces == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *physical_interfacesListEntry;
    list_ForEach(physical_interfacesListEntry, network_schema->physical_interfaces) {
    if(cJSON_AddStringToObject(physical_interfaces, "", physical_interfacesListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // network_schema->vpns
    if(network_schema->vpns) {
    cJSON *vpns = cJSON_AddArrayToObject(item, "vpns");
    if(vpns == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *vpnsListEntry;
    if (network_schema->vpns) {
    list_ForEach(vpnsListEntry, network_schema->vpns) {
    cJSON *itemLocal = vpn_schema_convertToJSON(vpnsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(vpns, itemLocal);
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

network_schema_t *network_schema_parseFromJSON(cJSON *network_schemaJSON){

    network_schema_t *network_schema_local_var = NULL;

    // define the local list for network_schema->physical_interfaces
    list_t *physical_interfacesList = NULL;

    // define the local list for network_schema->vpns
    list_t *vpnsList = NULL;

    // network_schema->physical_interfaces
    cJSON *physical_interfaces = cJSON_GetObjectItemCaseSensitive(network_schemaJSON, "physicalInterfaces");
    if (cJSON_IsNull(physical_interfaces)) {
        physical_interfaces = NULL;
    }
    if (!physical_interfaces) {
        goto end;
    }

    
    cJSON *physical_interfaces_local = NULL;
    if(!cJSON_IsArray(physical_interfaces)) {
        goto end;//primitive container
    }
    physical_interfacesList = list_createList();

    cJSON_ArrayForEach(physical_interfaces_local, physical_interfaces)
    {
        if(!cJSON_IsString(physical_interfaces_local))
        {
            goto end;
        }
        list_addElement(physical_interfacesList , strdup(physical_interfaces_local->valuestring));
    }

    // network_schema->vpns
    cJSON *vpns = cJSON_GetObjectItemCaseSensitive(network_schemaJSON, "vpns");
    if (cJSON_IsNull(vpns)) {
        vpns = NULL;
    }
    if (vpns) { 
    cJSON *vpns_local_nonprimitive = NULL;
    if(!cJSON_IsArray(vpns)){
        goto end; //nonprimitive container
    }

    vpnsList = list_createList();

    cJSON_ArrayForEach(vpns_local_nonprimitive,vpns )
    {
        if(!cJSON_IsObject(vpns_local_nonprimitive)){
            goto end;
        }
        vpn_schema_t *vpnsItem = vpn_schema_parseFromJSON(vpns_local_nonprimitive);

        list_addElement(vpnsList, vpnsItem);
    }
    }


    network_schema_local_var = network_schema_create_internal (
        physical_interfacesList,
        vpns ? vpnsList : NULL
        );

    return network_schema_local_var;
end:
    if (physical_interfacesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, physical_interfacesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(physical_interfacesList);
        physical_interfacesList = NULL;
    }
    if (vpnsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, vpnsList) {
            vpn_schema_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(vpnsList);
        vpnsList = NULL;
    }
    return NULL;

}
