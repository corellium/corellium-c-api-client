#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "node_information_v1.h"



static node_information_v1_t *node_information_v1_create_internal(
    char *node_id,
    char *address,
    char *hostname,
    double ssh_port,
    list_t *node_types
    ) {
    node_information_v1_t *node_information_v1_local_var = malloc(sizeof(node_information_v1_t));
    if (!node_information_v1_local_var) {
        return NULL;
    }
    node_information_v1_local_var->node_id = node_id;
    node_information_v1_local_var->address = address;
    node_information_v1_local_var->hostname = hostname;
    node_information_v1_local_var->ssh_port = ssh_port;
    node_information_v1_local_var->node_types = node_types;

    node_information_v1_local_var->_library_owned = 1;
    return node_information_v1_local_var;
}

__attribute__((deprecated)) node_information_v1_t *node_information_v1_create(
    char *node_id,
    char *address,
    char *hostname,
    double ssh_port,
    list_t *node_types
    ) {
    return node_information_v1_create_internal (
        node_id,
        address,
        hostname,
        ssh_port,
        node_types
        );
}

void node_information_v1_free(node_information_v1_t *node_information_v1) {
    if(NULL == node_information_v1){
        return ;
    }
    if(node_information_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "node_information_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (node_information_v1->node_id) {
        free(node_information_v1->node_id);
        node_information_v1->node_id = NULL;
    }
    if (node_information_v1->address) {
        free(node_information_v1->address);
        node_information_v1->address = NULL;
    }
    if (node_information_v1->hostname) {
        free(node_information_v1->hostname);
        node_information_v1->hostname = NULL;
    }
    if (node_information_v1->node_types) {
        list_ForEach(listEntry, node_information_v1->node_types) {
            free(listEntry->data);
        }
        list_freeList(node_information_v1->node_types);
        node_information_v1->node_types = NULL;
    }
    free(node_information_v1);
}

cJSON *node_information_v1_convertToJSON(node_information_v1_t *node_information_v1) {
    cJSON *item = cJSON_CreateObject();

    // node_information_v1->node_id
    if (!node_information_v1->node_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "nodeId", node_information_v1->node_id) == NULL) {
    goto fail; //String
    }


    // node_information_v1->address
    if (!node_information_v1->address) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "address", node_information_v1->address) == NULL) {
    goto fail; //String
    }


    // node_information_v1->hostname
    if (!node_information_v1->hostname) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "hostname", node_information_v1->hostname) == NULL) {
    goto fail; //String
    }


    // node_information_v1->ssh_port
    if(node_information_v1->ssh_port) {
    if(cJSON_AddNumberToObject(item, "sshPort", node_information_v1->ssh_port) == NULL) {
    goto fail; //Numeric
    }
    }


    // node_information_v1->node_types
    if (!node_information_v1->node_types) {
        goto fail;
    }
    cJSON *node_types = cJSON_AddArrayToObject(item, "nodeTypes");
    if(node_types == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *node_typesListEntry;
    list_ForEach(node_typesListEntry, node_information_v1->node_types) {
    if(cJSON_AddStringToObject(node_types, "", node_typesListEntry->data) == NULL)
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

node_information_v1_t *node_information_v1_parseFromJSON(cJSON *node_information_v1JSON){

    node_information_v1_t *node_information_v1_local_var = NULL;

    // define the local list for node_information_v1->node_types
    list_t *node_typesList = NULL;

    // node_information_v1->node_id
    cJSON *node_id = cJSON_GetObjectItemCaseSensitive(node_information_v1JSON, "nodeId");
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

    // node_information_v1->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(node_information_v1JSON, "address");
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

    // node_information_v1->hostname
    cJSON *hostname = cJSON_GetObjectItemCaseSensitive(node_information_v1JSON, "hostname");
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

    // node_information_v1->ssh_port
    cJSON *ssh_port = cJSON_GetObjectItemCaseSensitive(node_information_v1JSON, "sshPort");
    if (cJSON_IsNull(ssh_port)) {
        ssh_port = NULL;
    }
    if (ssh_port) { 
    if(!cJSON_IsNumber(ssh_port))
    {
    goto end; //Numeric
    }
    }

    // node_information_v1->node_types
    cJSON *node_types = cJSON_GetObjectItemCaseSensitive(node_information_v1JSON, "nodeTypes");
    if (cJSON_IsNull(node_types)) {
        node_types = NULL;
    }
    if (!node_types) {
        goto end;
    }

    
    cJSON *node_types_local = NULL;
    if(!cJSON_IsArray(node_types)) {
        goto end;//primitive container
    }
    node_typesList = list_createList();

    cJSON_ArrayForEach(node_types_local, node_types)
    {
        if(!cJSON_IsString(node_types_local))
        {
            goto end;
        }
        list_addElement(node_typesList , strdup(node_types_local->valuestring));
    }


    node_information_v1_local_var = node_information_v1_create_internal (
        strdup(node_id->valuestring),
        strdup(address->valuestring),
        strdup(hostname->valuestring),
        ssh_port ? ssh_port->valuedouble : 0,
        node_typesList
        );

    return node_information_v1_local_var;
end:
    if (node_typesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, node_typesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(node_typesList);
        node_typesList = NULL;
    }
    return NULL;

}
