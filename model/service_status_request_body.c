#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "service_status_request_body.h"



static service_status_request_body_t *service_status_request_body_create_internal(
    int healthy,
    char *service_name,
    char *address,
    char *hostname,
    char *node_id,
    sys_info_schema_t *sys_info,
    layout_schema_t *layout,
    list_t *vms,
    pool_usage_schema_t *pool_usage,
    char *az,
    network_schema_t *network,
    char *ec2_instance_type,
    char *op
    ) {
    service_status_request_body_t *service_status_request_body_local_var = malloc(sizeof(service_status_request_body_t));
    if (!service_status_request_body_local_var) {
        return NULL;
    }
    service_status_request_body_local_var->healthy = healthy;
    service_status_request_body_local_var->service_name = service_name;
    service_status_request_body_local_var->address = address;
    service_status_request_body_local_var->hostname = hostname;
    service_status_request_body_local_var->node_id = node_id;
    service_status_request_body_local_var->sys_info = sys_info;
    service_status_request_body_local_var->layout = layout;
    service_status_request_body_local_var->vms = vms;
    service_status_request_body_local_var->pool_usage = pool_usage;
    service_status_request_body_local_var->az = az;
    service_status_request_body_local_var->network = network;
    service_status_request_body_local_var->ec2_instance_type = ec2_instance_type;
    service_status_request_body_local_var->op = op;

    service_status_request_body_local_var->_library_owned = 1;
    return service_status_request_body_local_var;
}

__attribute__((deprecated)) service_status_request_body_t *service_status_request_body_create(
    int healthy,
    char *service_name,
    char *address,
    char *hostname,
    char *node_id,
    sys_info_schema_t *sys_info,
    layout_schema_t *layout,
    list_t *vms,
    pool_usage_schema_t *pool_usage,
    char *az,
    network_schema_t *network,
    char *ec2_instance_type,
    char *op
    ) {
    return service_status_request_body_create_internal (
        healthy,
        service_name,
        address,
        hostname,
        node_id,
        sys_info,
        layout,
        vms,
        pool_usage,
        az,
        network,
        ec2_instance_type,
        op
        );
}

void service_status_request_body_free(service_status_request_body_t *service_status_request_body) {
    if(NULL == service_status_request_body){
        return ;
    }
    if(service_status_request_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "service_status_request_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (service_status_request_body->service_name) {
        free(service_status_request_body->service_name);
        service_status_request_body->service_name = NULL;
    }
    if (service_status_request_body->address) {
        free(service_status_request_body->address);
        service_status_request_body->address = NULL;
    }
    if (service_status_request_body->hostname) {
        free(service_status_request_body->hostname);
        service_status_request_body->hostname = NULL;
    }
    if (service_status_request_body->node_id) {
        free(service_status_request_body->node_id);
        service_status_request_body->node_id = NULL;
    }
    if (service_status_request_body->sys_info) {
        sys_info_schema_free(service_status_request_body->sys_info);
        service_status_request_body->sys_info = NULL;
    }
    if (service_status_request_body->layout) {
        layout_schema_free(service_status_request_body->layout);
        service_status_request_body->layout = NULL;
    }
    if (service_status_request_body->vms) {
        list_ForEach(listEntry, service_status_request_body->vms) {
            service_status_request_body_vms_inner_free(listEntry->data);
        }
        list_freeList(service_status_request_body->vms);
        service_status_request_body->vms = NULL;
    }
    if (service_status_request_body->pool_usage) {
        pool_usage_schema_free(service_status_request_body->pool_usage);
        service_status_request_body->pool_usage = NULL;
    }
    if (service_status_request_body->az) {
        free(service_status_request_body->az);
        service_status_request_body->az = NULL;
    }
    if (service_status_request_body->network) {
        network_schema_free(service_status_request_body->network);
        service_status_request_body->network = NULL;
    }
    if (service_status_request_body->ec2_instance_type) {
        free(service_status_request_body->ec2_instance_type);
        service_status_request_body->ec2_instance_type = NULL;
    }
    if (service_status_request_body->op) {
        free(service_status_request_body->op);
        service_status_request_body->op = NULL;
    }
    free(service_status_request_body);
}

cJSON *service_status_request_body_convertToJSON(service_status_request_body_t *service_status_request_body) {
    cJSON *item = cJSON_CreateObject();

    // service_status_request_body->healthy
    if (!service_status_request_body->healthy) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "healthy", service_status_request_body->healthy) == NULL) {
    goto fail; //Bool
    }


    // service_status_request_body->service_name
    if (!service_status_request_body->service_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "serviceName", service_status_request_body->service_name) == NULL) {
    goto fail; //String
    }


    // service_status_request_body->address
    if (!service_status_request_body->address) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "address", service_status_request_body->address) == NULL) {
    goto fail; //String
    }


    // service_status_request_body->hostname
    if (!service_status_request_body->hostname) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "hostname", service_status_request_body->hostname) == NULL) {
    goto fail; //String
    }


    // service_status_request_body->node_id
    if (!service_status_request_body->node_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "nodeId", service_status_request_body->node_id) == NULL) {
    goto fail; //String
    }


    // service_status_request_body->sys_info
    if(service_status_request_body->sys_info) {
    cJSON *sys_info_local_JSON = sys_info_schema_convertToJSON(service_status_request_body->sys_info);
    if(sys_info_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "sysInfo", sys_info_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // service_status_request_body->layout
    if(service_status_request_body->layout) {
    cJSON *layout_local_JSON = layout_schema_convertToJSON(service_status_request_body->layout);
    if(layout_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "layout", layout_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // service_status_request_body->vms
    if(service_status_request_body->vms) {
    cJSON *vms = cJSON_AddArrayToObject(item, "vms");
    if(vms == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *vmsListEntry;
    if (service_status_request_body->vms) {
    list_ForEach(vmsListEntry, service_status_request_body->vms) {
    cJSON *itemLocal = service_status_request_body_vms_inner_convertToJSON(vmsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(vms, itemLocal);
    }
    }
    }


    // service_status_request_body->pool_usage
    if(service_status_request_body->pool_usage) {
    cJSON *pool_usage_local_JSON = pool_usage_schema_convertToJSON(service_status_request_body->pool_usage);
    if(pool_usage_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "poolUsage", pool_usage_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // service_status_request_body->az
    if(service_status_request_body->az) {
    if(cJSON_AddStringToObject(item, "az", service_status_request_body->az) == NULL) {
    goto fail; //String
    }
    }


    // service_status_request_body->network
    if(service_status_request_body->network) {
    cJSON *network_local_JSON = network_schema_convertToJSON(service_status_request_body->network);
    if(network_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "network", network_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // service_status_request_body->ec2_instance_type
    if(service_status_request_body->ec2_instance_type) {
    if(cJSON_AddStringToObject(item, "ec2InstanceType", service_status_request_body->ec2_instance_type) == NULL) {
    goto fail; //String
    }
    }


    // service_status_request_body->op
    if(service_status_request_body->op) {
    if(cJSON_AddStringToObject(item, "op", service_status_request_body->op) == NULL) {
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

service_status_request_body_t *service_status_request_body_parseFromJSON(cJSON *service_status_request_bodyJSON){

    service_status_request_body_t *service_status_request_body_local_var = NULL;

    // define the local variable for service_status_request_body->sys_info
    sys_info_schema_t *sys_info_local_nonprim = NULL;

    // define the local variable for service_status_request_body->layout
    layout_schema_t *layout_local_nonprim = NULL;

    // define the local list for service_status_request_body->vms
    list_t *vmsList = NULL;

    // define the local variable for service_status_request_body->pool_usage
    pool_usage_schema_t *pool_usage_local_nonprim = NULL;

    // define the local variable for service_status_request_body->network
    network_schema_t *network_local_nonprim = NULL;

    // service_status_request_body->healthy
    cJSON *healthy = cJSON_GetObjectItemCaseSensitive(service_status_request_bodyJSON, "healthy");
    if (cJSON_IsNull(healthy)) {
        healthy = NULL;
    }
    if (!healthy) {
        goto end;
    }

    
    if(!cJSON_IsBool(healthy))
    {
    goto end; //Bool
    }

    // service_status_request_body->service_name
    cJSON *service_name = cJSON_GetObjectItemCaseSensitive(service_status_request_bodyJSON, "serviceName");
    if (cJSON_IsNull(service_name)) {
        service_name = NULL;
    }
    if (!service_name) {
        goto end;
    }

    
    if(!cJSON_IsString(service_name))
    {
    goto end; //String
    }

    // service_status_request_body->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(service_status_request_bodyJSON, "address");
    if (cJSON_IsNull(address)) {
        address = NULL;
    }
    if (!address) {
        goto end;
    }

    
    if(!cJSON_IsString(address))
    {
    goto end; //String
    }

    // service_status_request_body->hostname
    cJSON *hostname = cJSON_GetObjectItemCaseSensitive(service_status_request_bodyJSON, "hostname");
    if (cJSON_IsNull(hostname)) {
        hostname = NULL;
    }
    if (!hostname) {
        goto end;
    }

    
    if(!cJSON_IsString(hostname))
    {
    goto end; //String
    }

    // service_status_request_body->node_id
    cJSON *node_id = cJSON_GetObjectItemCaseSensitive(service_status_request_bodyJSON, "nodeId");
    if (cJSON_IsNull(node_id)) {
        node_id = NULL;
    }
    if (!node_id) {
        goto end;
    }

    
    if(!cJSON_IsString(node_id))
    {
    goto end; //String
    }

    // service_status_request_body->sys_info
    cJSON *sys_info = cJSON_GetObjectItemCaseSensitive(service_status_request_bodyJSON, "sysInfo");
    if (cJSON_IsNull(sys_info)) {
        sys_info = NULL;
    }
    if (sys_info) { 
    sys_info_local_nonprim = sys_info_schema_parseFromJSON(sys_info); //nonprimitive
    }

    // service_status_request_body->layout
    cJSON *layout = cJSON_GetObjectItemCaseSensitive(service_status_request_bodyJSON, "layout");
    if (cJSON_IsNull(layout)) {
        layout = NULL;
    }
    if (layout) { 
    layout_local_nonprim = layout_schema_parseFromJSON(layout); //nonprimitive
    }

    // service_status_request_body->vms
    cJSON *vms = cJSON_GetObjectItemCaseSensitive(service_status_request_bodyJSON, "vms");
    if (cJSON_IsNull(vms)) {
        vms = NULL;
    }
    if (vms) { 
    cJSON *vms_local_nonprimitive = NULL;
    if(!cJSON_IsArray(vms)){
        goto end; //nonprimitive container
    }

    vmsList = list_createList();

    cJSON_ArrayForEach(vms_local_nonprimitive,vms )
    {
        if(!cJSON_IsObject(vms_local_nonprimitive)){
            goto end;
        }
        service_status_request_body_vms_inner_t *vmsItem = service_status_request_body_vms_inner_parseFromJSON(vms_local_nonprimitive);

        list_addElement(vmsList, vmsItem);
    }
    }

    // service_status_request_body->pool_usage
    cJSON *pool_usage = cJSON_GetObjectItemCaseSensitive(service_status_request_bodyJSON, "poolUsage");
    if (cJSON_IsNull(pool_usage)) {
        pool_usage = NULL;
    }
    if (pool_usage) { 
    pool_usage_local_nonprim = pool_usage_schema_parseFromJSON(pool_usage); //nonprimitive
    }

    // service_status_request_body->az
    cJSON *az = cJSON_GetObjectItemCaseSensitive(service_status_request_bodyJSON, "az");
    if (cJSON_IsNull(az)) {
        az = NULL;
    }
    if (az) { 
    if(!cJSON_IsString(az) && !cJSON_IsNull(az))
    {
    goto end; //String
    }
    }

    // service_status_request_body->network
    cJSON *network = cJSON_GetObjectItemCaseSensitive(service_status_request_bodyJSON, "network");
    if (cJSON_IsNull(network)) {
        network = NULL;
    }
    if (network) { 
    network_local_nonprim = network_schema_parseFromJSON(network); //nonprimitive
    }

    // service_status_request_body->ec2_instance_type
    cJSON *ec2_instance_type = cJSON_GetObjectItemCaseSensitive(service_status_request_bodyJSON, "ec2InstanceType");
    if (cJSON_IsNull(ec2_instance_type)) {
        ec2_instance_type = NULL;
    }
    if (ec2_instance_type) { 
    if(!cJSON_IsString(ec2_instance_type) && !cJSON_IsNull(ec2_instance_type))
    {
    goto end; //String
    }
    }

    // service_status_request_body->op
    cJSON *op = cJSON_GetObjectItemCaseSensitive(service_status_request_bodyJSON, "op");
    if (cJSON_IsNull(op)) {
        op = NULL;
    }
    if (op) { 
    if(!cJSON_IsString(op) && !cJSON_IsNull(op))
    {
    goto end; //String
    }
    }


    service_status_request_body_local_var = service_status_request_body_create_internal (
        healthy->valueint,
        strdup(service_name->valuestring),
        strdup(address->valuestring),
        strdup(hostname->valuestring),
        strdup(node_id->valuestring),
        sys_info ? sys_info_local_nonprim : NULL,
        layout ? layout_local_nonprim : NULL,
        vms ? vmsList : NULL,
        pool_usage ? pool_usage_local_nonprim : NULL,
        az && !cJSON_IsNull(az) ? strdup(az->valuestring) : NULL,
        network ? network_local_nonprim : NULL,
        ec2_instance_type && !cJSON_IsNull(ec2_instance_type) ? strdup(ec2_instance_type->valuestring) : NULL,
        op && !cJSON_IsNull(op) ? strdup(op->valuestring) : NULL
        );

    return service_status_request_body_local_var;
end:
    if (sys_info_local_nonprim) {
        sys_info_schema_free(sys_info_local_nonprim);
        sys_info_local_nonprim = NULL;
    }
    if (layout_local_nonprim) {
        layout_schema_free(layout_local_nonprim);
        layout_local_nonprim = NULL;
    }
    if (vmsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, vmsList) {
            service_status_request_body_vms_inner_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(vmsList);
        vmsList = NULL;
    }
    if (pool_usage_local_nonprim) {
        pool_usage_schema_free(pool_usage_local_nonprim);
        pool_usage_local_nonprim = NULL;
    }
    if (network_local_nonprim) {
        network_schema_free(network_local_nonprim);
        network_local_nonprim = NULL;
    }
    return NULL;

}
