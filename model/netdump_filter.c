#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "netdump_filter.h"



static netdump_filter_t *netdump_filter_create_internal(
    list_t *port_ranges,
    list_t *src_ports,
    list_t *dst_ports,
    list_t *ports,
    list_t *protocols,
    list_t *processes
    ) {
    netdump_filter_t *netdump_filter_local_var = malloc(sizeof(netdump_filter_t));
    if (!netdump_filter_local_var) {
        return NULL;
    }
    netdump_filter_local_var->port_ranges = port_ranges;
    netdump_filter_local_var->src_ports = src_ports;
    netdump_filter_local_var->dst_ports = dst_ports;
    netdump_filter_local_var->ports = ports;
    netdump_filter_local_var->protocols = protocols;
    netdump_filter_local_var->processes = processes;

    netdump_filter_local_var->_library_owned = 1;
    return netdump_filter_local_var;
}

__attribute__((deprecated)) netdump_filter_t *netdump_filter_create(
    list_t *port_ranges,
    list_t *src_ports,
    list_t *dst_ports,
    list_t *ports,
    list_t *protocols,
    list_t *processes
    ) {
    return netdump_filter_create_internal (
        port_ranges,
        src_ports,
        dst_ports,
        ports,
        protocols,
        processes
        );
}

void netdump_filter_free(netdump_filter_t *netdump_filter) {
    if(NULL == netdump_filter){
        return ;
    }
    if(netdump_filter->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "netdump_filter_free");
        return ;
    }
    listEntry_t *listEntry;
    if (netdump_filter->port_ranges) {
        list_ForEach(listEntry, netdump_filter->port_ranges) {
            free(listEntry->data);
        }
        list_freeList(netdump_filter->port_ranges);
        netdump_filter->port_ranges = NULL;
    }
    if (netdump_filter->src_ports) {
        list_ForEach(listEntry, netdump_filter->src_ports) {
            free(listEntry->data);
        }
        list_freeList(netdump_filter->src_ports);
        netdump_filter->src_ports = NULL;
    }
    if (netdump_filter->dst_ports) {
        list_ForEach(listEntry, netdump_filter->dst_ports) {
            free(listEntry->data);
        }
        list_freeList(netdump_filter->dst_ports);
        netdump_filter->dst_ports = NULL;
    }
    if (netdump_filter->ports) {
        list_ForEach(listEntry, netdump_filter->ports) {
            free(listEntry->data);
        }
        list_freeList(netdump_filter->ports);
        netdump_filter->ports = NULL;
    }
    if (netdump_filter->protocols) {
        list_ForEach(listEntry, netdump_filter->protocols) {
            free(listEntry->data);
        }
        list_freeList(netdump_filter->protocols);
        netdump_filter->protocols = NULL;
    }
    if (netdump_filter->processes) {
        list_ForEach(listEntry, netdump_filter->processes) {
            free(listEntry->data);
        }
        list_freeList(netdump_filter->processes);
        netdump_filter->processes = NULL;
    }
    free(netdump_filter);
}

cJSON *netdump_filter_convertToJSON(netdump_filter_t *netdump_filter) {
    cJSON *item = cJSON_CreateObject();

    // netdump_filter->port_ranges
    if(netdump_filter->port_ranges) {
    cJSON *port_ranges = cJSON_AddArrayToObject(item, "portRanges");
    if(port_ranges == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *port_rangesListEntry;
    list_ForEach(port_rangesListEntry, netdump_filter->port_ranges) {
    if(cJSON_AddStringToObject(port_ranges, "", port_rangesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // netdump_filter->src_ports
    if(netdump_filter->src_ports) {
    cJSON *src_ports = cJSON_AddArrayToObject(item, "srcPorts");
    if(src_ports == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *src_portsListEntry;
    list_ForEach(src_portsListEntry, netdump_filter->src_ports) {
    if(cJSON_AddStringToObject(src_ports, "", src_portsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // netdump_filter->dst_ports
    if(netdump_filter->dst_ports) {
    cJSON *dst_ports = cJSON_AddArrayToObject(item, "dstPorts");
    if(dst_ports == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *dst_portsListEntry;
    list_ForEach(dst_portsListEntry, netdump_filter->dst_ports) {
    if(cJSON_AddStringToObject(dst_ports, "", dst_portsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // netdump_filter->ports
    if(netdump_filter->ports) {
    cJSON *ports = cJSON_AddArrayToObject(item, "ports");
    if(ports == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *portsListEntry;
    list_ForEach(portsListEntry, netdump_filter->ports) {
    if(cJSON_AddStringToObject(ports, "", portsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // netdump_filter->protocols
    if(netdump_filter->protocols) {
    cJSON *protocols = cJSON_AddArrayToObject(item, "protocols");
    if(protocols == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *protocolsListEntry;
    list_ForEach(protocolsListEntry, netdump_filter->protocols) {
    if(cJSON_AddStringToObject(protocols, "", protocolsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // netdump_filter->processes
    if(netdump_filter->processes) {
    cJSON *processes = cJSON_AddArrayToObject(item, "processes");
    if(processes == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *processesListEntry;
    list_ForEach(processesListEntry, netdump_filter->processes) {
    if(cJSON_AddStringToObject(processes, "", processesListEntry->data) == NULL)
    {
        goto fail;
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

netdump_filter_t *netdump_filter_parseFromJSON(cJSON *netdump_filterJSON){

    netdump_filter_t *netdump_filter_local_var = NULL;

    // define the local list for netdump_filter->port_ranges
    list_t *port_rangesList = NULL;

    // define the local list for netdump_filter->src_ports
    list_t *src_portsList = NULL;

    // define the local list for netdump_filter->dst_ports
    list_t *dst_portsList = NULL;

    // define the local list for netdump_filter->ports
    list_t *portsList = NULL;

    // define the local list for netdump_filter->protocols
    list_t *protocolsList = NULL;

    // define the local list for netdump_filter->processes
    list_t *processesList = NULL;

    // netdump_filter->port_ranges
    cJSON *port_ranges = cJSON_GetObjectItemCaseSensitive(netdump_filterJSON, "portRanges");
    if (cJSON_IsNull(port_ranges)) {
        port_ranges = NULL;
    }
    if (port_ranges) { 
    cJSON *port_ranges_local = NULL;
    if(!cJSON_IsArray(port_ranges)) {
        goto end;//primitive container
    }
    port_rangesList = list_createList();

    cJSON_ArrayForEach(port_ranges_local, port_ranges)
    {
        if(!cJSON_IsString(port_ranges_local))
        {
            goto end;
        }
        list_addElement(port_rangesList , strdup(port_ranges_local->valuestring));
    }
    }

    // netdump_filter->src_ports
    cJSON *src_ports = cJSON_GetObjectItemCaseSensitive(netdump_filterJSON, "srcPorts");
    if (cJSON_IsNull(src_ports)) {
        src_ports = NULL;
    }
    if (src_ports) { 
    cJSON *src_ports_local = NULL;
    if(!cJSON_IsArray(src_ports)) {
        goto end;//primitive container
    }
    src_portsList = list_createList();

    cJSON_ArrayForEach(src_ports_local, src_ports)
    {
        if(!cJSON_IsString(src_ports_local))
        {
            goto end;
        }
        list_addElement(src_portsList , strdup(src_ports_local->valuestring));
    }
    }

    // netdump_filter->dst_ports
    cJSON *dst_ports = cJSON_GetObjectItemCaseSensitive(netdump_filterJSON, "dstPorts");
    if (cJSON_IsNull(dst_ports)) {
        dst_ports = NULL;
    }
    if (dst_ports) { 
    cJSON *dst_ports_local = NULL;
    if(!cJSON_IsArray(dst_ports)) {
        goto end;//primitive container
    }
    dst_portsList = list_createList();

    cJSON_ArrayForEach(dst_ports_local, dst_ports)
    {
        if(!cJSON_IsString(dst_ports_local))
        {
            goto end;
        }
        list_addElement(dst_portsList , strdup(dst_ports_local->valuestring));
    }
    }

    // netdump_filter->ports
    cJSON *ports = cJSON_GetObjectItemCaseSensitive(netdump_filterJSON, "ports");
    if (cJSON_IsNull(ports)) {
        ports = NULL;
    }
    if (ports) { 
    cJSON *ports_local = NULL;
    if(!cJSON_IsArray(ports)) {
        goto end;//primitive container
    }
    portsList = list_createList();

    cJSON_ArrayForEach(ports_local, ports)
    {
        if(!cJSON_IsString(ports_local))
        {
            goto end;
        }
        list_addElement(portsList , strdup(ports_local->valuestring));
    }
    }

    // netdump_filter->protocols
    cJSON *protocols = cJSON_GetObjectItemCaseSensitive(netdump_filterJSON, "protocols");
    if (cJSON_IsNull(protocols)) {
        protocols = NULL;
    }
    if (protocols) { 
    cJSON *protocols_local = NULL;
    if(!cJSON_IsArray(protocols)) {
        goto end;//primitive container
    }
    protocolsList = list_createList();

    cJSON_ArrayForEach(protocols_local, protocols)
    {
        if(!cJSON_IsString(protocols_local))
        {
            goto end;
        }
        list_addElement(protocolsList , strdup(protocols_local->valuestring));
    }
    }

    // netdump_filter->processes
    cJSON *processes = cJSON_GetObjectItemCaseSensitive(netdump_filterJSON, "processes");
    if (cJSON_IsNull(processes)) {
        processes = NULL;
    }
    if (processes) { 
    cJSON *processes_local = NULL;
    if(!cJSON_IsArray(processes)) {
        goto end;//primitive container
    }
    processesList = list_createList();

    cJSON_ArrayForEach(processes_local, processes)
    {
        if(!cJSON_IsString(processes_local))
        {
            goto end;
        }
        list_addElement(processesList , strdup(processes_local->valuestring));
    }
    }


    netdump_filter_local_var = netdump_filter_create_internal (
        port_ranges ? port_rangesList : NULL,
        src_ports ? src_portsList : NULL,
        dst_ports ? dst_portsList : NULL,
        ports ? portsList : NULL,
        protocols ? protocolsList : NULL,
        processes ? processesList : NULL
        );

    return netdump_filter_local_var;
end:
    if (port_rangesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, port_rangesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(port_rangesList);
        port_rangesList = NULL;
    }
    if (src_portsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, src_portsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(src_portsList);
        src_portsList = NULL;
    }
    if (dst_portsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, dst_portsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(dst_portsList);
        dst_portsList = NULL;
    }
    if (portsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, portsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(portsList);
        portsList = NULL;
    }
    if (protocolsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, protocolsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(protocolsList);
        protocolsList = NULL;
    }
    if (processesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, processesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(processesList);
        processesList = NULL;
    }
    return NULL;

}
