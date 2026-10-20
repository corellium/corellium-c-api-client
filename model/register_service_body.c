#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "register_service_body.h"



static register_service_body_t *register_service_body_create_internal(
    char *password,
    char *node_id,
    char *address,
    char *service_name,
    list_t *endpoints,
    char *identity_key,
    char *ca_cert,
    char *cert_fingerprint
    ) {
    register_service_body_t *register_service_body_local_var = malloc(sizeof(register_service_body_t));
    if (!register_service_body_local_var) {
        return NULL;
    }
    register_service_body_local_var->password = password;
    register_service_body_local_var->node_id = node_id;
    register_service_body_local_var->address = address;
    register_service_body_local_var->service_name = service_name;
    register_service_body_local_var->endpoints = endpoints;
    register_service_body_local_var->identity_key = identity_key;
    register_service_body_local_var->ca_cert = ca_cert;
    register_service_body_local_var->cert_fingerprint = cert_fingerprint;

    register_service_body_local_var->_library_owned = 1;
    return register_service_body_local_var;
}

__attribute__((deprecated)) register_service_body_t *register_service_body_create(
    char *password,
    char *node_id,
    char *address,
    char *service_name,
    list_t *endpoints,
    char *identity_key,
    char *ca_cert,
    char *cert_fingerprint
    ) {
    return register_service_body_create_internal (
        password,
        node_id,
        address,
        service_name,
        endpoints,
        identity_key,
        ca_cert,
        cert_fingerprint
        );
}

void register_service_body_free(register_service_body_t *register_service_body) {
    if(NULL == register_service_body){
        return ;
    }
    if(register_service_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "register_service_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (register_service_body->password) {
        free(register_service_body->password);
        register_service_body->password = NULL;
    }
    if (register_service_body->node_id) {
        free(register_service_body->node_id);
        register_service_body->node_id = NULL;
    }
    if (register_service_body->address) {
        free(register_service_body->address);
        register_service_body->address = NULL;
    }
    if (register_service_body->service_name) {
        free(register_service_body->service_name);
        register_service_body->service_name = NULL;
    }
    if (register_service_body->endpoints) {
        list_ForEach(listEntry, register_service_body->endpoints) {
            service_endpoint_schema_free(listEntry->data);
        }
        list_freeList(register_service_body->endpoints);
        register_service_body->endpoints = NULL;
    }
    if (register_service_body->identity_key) {
        free(register_service_body->identity_key);
        register_service_body->identity_key = NULL;
    }
    if (register_service_body->ca_cert) {
        free(register_service_body->ca_cert);
        register_service_body->ca_cert = NULL;
    }
    if (register_service_body->cert_fingerprint) {
        free(register_service_body->cert_fingerprint);
        register_service_body->cert_fingerprint = NULL;
    }
    free(register_service_body);
}

cJSON *register_service_body_convertToJSON(register_service_body_t *register_service_body) {
    cJSON *item = cJSON_CreateObject();

    // register_service_body->password
    if (!register_service_body->password) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "password", register_service_body->password) == NULL) {
    goto fail; //String
    }


    // register_service_body->node_id
    if (!register_service_body->node_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "nodeId", register_service_body->node_id) == NULL) {
    goto fail; //String
    }


    // register_service_body->address
    if (!register_service_body->address) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "address", register_service_body->address) == NULL) {
    goto fail; //String
    }


    // register_service_body->service_name
    if (!register_service_body->service_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "serviceName", register_service_body->service_name) == NULL) {
    goto fail; //String
    }


    // register_service_body->endpoints
    if(register_service_body->endpoints) {
    cJSON *endpoints = cJSON_AddArrayToObject(item, "endpoints");
    if(endpoints == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *endpointsListEntry;
    if (register_service_body->endpoints) {
    list_ForEach(endpointsListEntry, register_service_body->endpoints) {
    cJSON *itemLocal = service_endpoint_schema_convertToJSON(endpointsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(endpoints, itemLocal);
    }
    }
    }


    // register_service_body->identity_key
    if (!register_service_body->identity_key) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "identityKey", register_service_body->identity_key) == NULL) {
    goto fail; //String
    }


    // register_service_body->ca_cert
    if (!register_service_body->ca_cert) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "caCert", register_service_body->ca_cert) == NULL) {
    goto fail; //String
    }


    // register_service_body->cert_fingerprint
    if (!register_service_body->cert_fingerprint) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "certFingerprint", register_service_body->cert_fingerprint) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

register_service_body_t *register_service_body_parseFromJSON(cJSON *register_service_bodyJSON){

    register_service_body_t *register_service_body_local_var = NULL;

    // define the local list for register_service_body->endpoints
    list_t *endpointsList = NULL;

    // register_service_body->password
    cJSON *password = cJSON_GetObjectItemCaseSensitive(register_service_bodyJSON, "password");
    if (cJSON_IsNull(password)) {
        password = NULL;
    }
    if (!password) {
        goto end;
    }

    
    if(!cJSON_IsString(password))
    {
    goto end; //String
    }

    // register_service_body->node_id
    cJSON *node_id = cJSON_GetObjectItemCaseSensitive(register_service_bodyJSON, "nodeId");
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

    // register_service_body->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(register_service_bodyJSON, "address");
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

    // register_service_body->service_name
    cJSON *service_name = cJSON_GetObjectItemCaseSensitive(register_service_bodyJSON, "serviceName");
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

    // register_service_body->endpoints
    cJSON *endpoints = cJSON_GetObjectItemCaseSensitive(register_service_bodyJSON, "endpoints");
    if (cJSON_IsNull(endpoints)) {
        endpoints = NULL;
    }
    if (endpoints) { 
    cJSON *endpoints_local_nonprimitive = NULL;
    if(!cJSON_IsArray(endpoints)){
        goto end; //nonprimitive container
    }

    endpointsList = list_createList();

    cJSON_ArrayForEach(endpoints_local_nonprimitive,endpoints )
    {
        if(!cJSON_IsObject(endpoints_local_nonprimitive)){
            goto end;
        }
        service_endpoint_schema_t *endpointsItem = service_endpoint_schema_parseFromJSON(endpoints_local_nonprimitive);

        list_addElement(endpointsList, endpointsItem);
    }
    }

    // register_service_body->identity_key
    cJSON *identity_key = cJSON_GetObjectItemCaseSensitive(register_service_bodyJSON, "identityKey");
    if (cJSON_IsNull(identity_key)) {
        identity_key = NULL;
    }
    if (!identity_key) {
        goto end;
    }

    
    if(!cJSON_IsString(identity_key))
    {
    goto end; //String
    }

    // register_service_body->ca_cert
    cJSON *ca_cert = cJSON_GetObjectItemCaseSensitive(register_service_bodyJSON, "caCert");
    if (cJSON_IsNull(ca_cert)) {
        ca_cert = NULL;
    }
    if (!ca_cert) {
        goto end;
    }

    
    if(!cJSON_IsString(ca_cert))
    {
    goto end; //String
    }

    // register_service_body->cert_fingerprint
    cJSON *cert_fingerprint = cJSON_GetObjectItemCaseSensitive(register_service_bodyJSON, "certFingerprint");
    if (cJSON_IsNull(cert_fingerprint)) {
        cert_fingerprint = NULL;
    }
    if (!cert_fingerprint) {
        goto end;
    }

    
    if(!cJSON_IsString(cert_fingerprint))
    {
    goto end; //String
    }


    register_service_body_local_var = register_service_body_create_internal (
        strdup(password->valuestring),
        strdup(node_id->valuestring),
        strdup(address->valuestring),
        strdup(service_name->valuestring),
        endpoints ? endpointsList : NULL,
        strdup(identity_key->valuestring),
        strdup(ca_cert->valuestring),
        strdup(cert_fingerprint->valuestring)
        );

    return register_service_body_local_var;
end:
    if (endpointsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, endpointsList) {
            service_endpoint_schema_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(endpointsList);
        endpointsList = NULL;
    }
    return NULL;

}
