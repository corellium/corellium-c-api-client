#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "enable_netdump_body.h"



static enable_netdump_body_t *enable_netdump_body_create_internal(
    list_t *port_ranges,
    list_t *src_ports,
    list_t *dst_ports,
    list_t *ports,
    list_t *protocols,
    list_t *processes,
    list_t *hosts
    ) {
    enable_netdump_body_t *enable_netdump_body_local_var = malloc(sizeof(enable_netdump_body_t));
    if (!enable_netdump_body_local_var) {
        return NULL;
    }
    enable_netdump_body_local_var->port_ranges = port_ranges;
    enable_netdump_body_local_var->src_ports = src_ports;
    enable_netdump_body_local_var->dst_ports = dst_ports;
    enable_netdump_body_local_var->ports = ports;
    enable_netdump_body_local_var->protocols = protocols;
    enable_netdump_body_local_var->processes = processes;
    enable_netdump_body_local_var->hosts = hosts;

    enable_netdump_body_local_var->_library_owned = 1;
    return enable_netdump_body_local_var;
}

__attribute__((deprecated)) enable_netdump_body_t *enable_netdump_body_create(
    list_t *port_ranges,
    list_t *src_ports,
    list_t *dst_ports,
    list_t *ports,
    list_t *protocols,
    list_t *processes,
    list_t *hosts
    ) {
    return enable_netdump_body_create_internal (
        port_ranges,
        src_ports,
        dst_ports,
        ports,
        protocols,
        processes,
        hosts
        );
}

void enable_netdump_body_free(enable_netdump_body_t *enable_netdump_body) {
    if(NULL == enable_netdump_body){
        return ;
    }
    if(enable_netdump_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "enable_netdump_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (enable_netdump_body->port_ranges) {
        list_ForEach(listEntry, enable_netdump_body->port_ranges) {
            free(listEntry->data);
        }
        list_freeList(enable_netdump_body->port_ranges);
        enable_netdump_body->port_ranges = NULL;
    }
    if (enable_netdump_body->src_ports) {
        list_ForEach(listEntry, enable_netdump_body->src_ports) {
            free(listEntry->data);
        }
        list_freeList(enable_netdump_body->src_ports);
        enable_netdump_body->src_ports = NULL;
    }
    if (enable_netdump_body->dst_ports) {
        list_ForEach(listEntry, enable_netdump_body->dst_ports) {
            free(listEntry->data);
        }
        list_freeList(enable_netdump_body->dst_ports);
        enable_netdump_body->dst_ports = NULL;
    }
    if (enable_netdump_body->ports) {
        list_ForEach(listEntry, enable_netdump_body->ports) {
            free(listEntry->data);
        }
        list_freeList(enable_netdump_body->ports);
        enable_netdump_body->ports = NULL;
    }
    if (enable_netdump_body->protocols) {
        list_ForEach(listEntry, enable_netdump_body->protocols) {
            free(listEntry->data);
        }
        list_freeList(enable_netdump_body->protocols);
        enable_netdump_body->protocols = NULL;
    }
    if (enable_netdump_body->processes) {
        list_ForEach(listEntry, enable_netdump_body->processes) {
            free(listEntry->data);
        }
        list_freeList(enable_netdump_body->processes);
        enable_netdump_body->processes = NULL;
    }
    if (enable_netdump_body->hosts) {
        list_ForEach(listEntry, enable_netdump_body->hosts) {
            free(listEntry->data);
        }
        list_freeList(enable_netdump_body->hosts);
        enable_netdump_body->hosts = NULL;
    }
    free(enable_netdump_body);
}

cJSON *enable_netdump_body_convertToJSON(enable_netdump_body_t *enable_netdump_body) {
    cJSON *item = cJSON_CreateObject();

    // enable_netdump_body->port_ranges
    if(enable_netdump_body->port_ranges) {
    cJSON *port_ranges = cJSON_AddArrayToObject(item, "portRanges");
    if(port_ranges == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *port_rangesListEntry;
    list_ForEach(port_rangesListEntry, enable_netdump_body->port_ranges) {
    if(cJSON_AddStringToObject(port_ranges, "", port_rangesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // enable_netdump_body->src_ports
    if(enable_netdump_body->src_ports) {
    cJSON *src_ports = cJSON_AddArrayToObject(item, "srcPorts");
    if(src_ports == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *src_portsListEntry;
    list_ForEach(src_portsListEntry, enable_netdump_body->src_ports) {
    if(cJSON_AddStringToObject(src_ports, "", src_portsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // enable_netdump_body->dst_ports
    if(enable_netdump_body->dst_ports) {
    cJSON *dst_ports = cJSON_AddArrayToObject(item, "dstPorts");
    if(dst_ports == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *dst_portsListEntry;
    list_ForEach(dst_portsListEntry, enable_netdump_body->dst_ports) {
    if(cJSON_AddStringToObject(dst_ports, "", dst_portsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // enable_netdump_body->ports
    if(enable_netdump_body->ports) {
    cJSON *ports = cJSON_AddArrayToObject(item, "ports");
    if(ports == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *portsListEntry;
    list_ForEach(portsListEntry, enable_netdump_body->ports) {
    if(cJSON_AddStringToObject(ports, "", portsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // enable_netdump_body->protocols
    if(enable_netdump_body->protocols) {
    cJSON *protocols = cJSON_AddArrayToObject(item, "protocols");
    if(protocols == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *protocolsListEntry;
    list_ForEach(protocolsListEntry, enable_netdump_body->protocols) {
    if(cJSON_AddStringToObject(protocols, "", protocolsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // enable_netdump_body->processes
    if(enable_netdump_body->processes) {
    cJSON *processes = cJSON_AddArrayToObject(item, "processes");
    if(processes == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *processesListEntry;
    list_ForEach(processesListEntry, enable_netdump_body->processes) {
    if(cJSON_AddStringToObject(processes, "", processesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // enable_netdump_body->hosts
    if(enable_netdump_body->hosts) {
    cJSON *hosts = cJSON_AddArrayToObject(item, "hosts");
    if(hosts == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *hostsListEntry;
    list_ForEach(hostsListEntry, enable_netdump_body->hosts) {
    if(cJSON_AddStringToObject(hosts, "", hostsListEntry->data) == NULL)
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

enable_netdump_body_t *enable_netdump_body_parseFromJSON(cJSON *enable_netdump_bodyJSON){

    enable_netdump_body_t *enable_netdump_body_local_var = NULL;

    // define the local list for enable_netdump_body->port_ranges
    list_t *port_rangesList = NULL;

    // define the local list for enable_netdump_body->src_ports
    list_t *src_portsList = NULL;

    // define the local list for enable_netdump_body->dst_ports
    list_t *dst_portsList = NULL;

    // define the local list for enable_netdump_body->ports
    list_t *portsList = NULL;

    // define the local list for enable_netdump_body->protocols
    list_t *protocolsList = NULL;

    // define the local list for enable_netdump_body->processes
    list_t *processesList = NULL;

    // define the local list for enable_netdump_body->hosts
    list_t *hostsList = NULL;

    // enable_netdump_body->port_ranges
    cJSON *port_ranges = cJSON_GetObjectItemCaseSensitive(enable_netdump_bodyJSON, "portRanges");
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

    // enable_netdump_body->src_ports
    cJSON *src_ports = cJSON_GetObjectItemCaseSensitive(enable_netdump_bodyJSON, "srcPorts");
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

    // enable_netdump_body->dst_ports
    cJSON *dst_ports = cJSON_GetObjectItemCaseSensitive(enable_netdump_bodyJSON, "dstPorts");
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

    // enable_netdump_body->ports
    cJSON *ports = cJSON_GetObjectItemCaseSensitive(enable_netdump_bodyJSON, "ports");
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

    // enable_netdump_body->protocols
    cJSON *protocols = cJSON_GetObjectItemCaseSensitive(enable_netdump_bodyJSON, "protocols");
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

    // enable_netdump_body->processes
    cJSON *processes = cJSON_GetObjectItemCaseSensitive(enable_netdump_bodyJSON, "processes");
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

    // enable_netdump_body->hosts
    cJSON *hosts = cJSON_GetObjectItemCaseSensitive(enable_netdump_bodyJSON, "hosts");
    if (cJSON_IsNull(hosts)) {
        hosts = NULL;
    }
    if (hosts) { 
    cJSON *hosts_local = NULL;
    if(!cJSON_IsArray(hosts)) {
        goto end;//primitive container
    }
    hostsList = list_createList();

    cJSON_ArrayForEach(hosts_local, hosts)
    {
        if(!cJSON_IsString(hosts_local))
        {
            goto end;
        }
        list_addElement(hostsList , strdup(hosts_local->valuestring));
    }
    }


    enable_netdump_body_local_var = enable_netdump_body_create_internal (
        port_ranges ? port_rangesList : NULL,
        src_ports ? src_portsList : NULL,
        dst_ports ? dst_portsList : NULL,
        ports ? portsList : NULL,
        protocols ? protocolsList : NULL,
        processes ? processesList : NULL,
        hosts ? hostsList : NULL
        );

    return enable_netdump_body_local_var;
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
    if (hostsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, hostsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(hostsList);
        hostsList = NULL;
    }
    return NULL;

}
