#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ldap_server_connection_details.h"



static ldap_server_connection_details_t *ldap_server_connection_details_create_internal(
    char *server_url,
    char *port,
    char *connection_timeout,
    int enable_ldaps,
    char *ca_cert,
    int ca_verify
    ) {
    ldap_server_connection_details_t *ldap_server_connection_details_local_var = malloc(sizeof(ldap_server_connection_details_t));
    if (!ldap_server_connection_details_local_var) {
        return NULL;
    }
    ldap_server_connection_details_local_var->server_url = server_url;
    ldap_server_connection_details_local_var->port = port;
    ldap_server_connection_details_local_var->connection_timeout = connection_timeout;
    ldap_server_connection_details_local_var->enable_ldaps = enable_ldaps;
    ldap_server_connection_details_local_var->ca_cert = ca_cert;
    ldap_server_connection_details_local_var->ca_verify = ca_verify;

    ldap_server_connection_details_local_var->_library_owned = 1;
    return ldap_server_connection_details_local_var;
}

__attribute__((deprecated)) ldap_server_connection_details_t *ldap_server_connection_details_create(
    char *server_url,
    char *port,
    char *connection_timeout,
    int enable_ldaps,
    char *ca_cert,
    int ca_verify
    ) {
    return ldap_server_connection_details_create_internal (
        server_url,
        port,
        connection_timeout,
        enable_ldaps,
        ca_cert,
        ca_verify
        );
}

void ldap_server_connection_details_free(ldap_server_connection_details_t *ldap_server_connection_details) {
    if(NULL == ldap_server_connection_details){
        return ;
    }
    if(ldap_server_connection_details->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ldap_server_connection_details_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ldap_server_connection_details->server_url) {
        free(ldap_server_connection_details->server_url);
        ldap_server_connection_details->server_url = NULL;
    }
    if (ldap_server_connection_details->port) {
        free(ldap_server_connection_details->port);
        ldap_server_connection_details->port = NULL;
    }
    if (ldap_server_connection_details->connection_timeout) {
        free(ldap_server_connection_details->connection_timeout);
        ldap_server_connection_details->connection_timeout = NULL;
    }
    if (ldap_server_connection_details->ca_cert) {
        free(ldap_server_connection_details->ca_cert);
        ldap_server_connection_details->ca_cert = NULL;
    }
    free(ldap_server_connection_details);
}

cJSON *ldap_server_connection_details_convertToJSON(ldap_server_connection_details_t *ldap_server_connection_details) {
    cJSON *item = cJSON_CreateObject();

    // ldap_server_connection_details->server_url
    if (!ldap_server_connection_details->server_url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "serverUrl", ldap_server_connection_details->server_url) == NULL) {
    goto fail; //String
    }


    // ldap_server_connection_details->port
    if(ldap_server_connection_details->port) {
    if(cJSON_AddStringToObject(item, "port", ldap_server_connection_details->port) == NULL) {
    goto fail; //String
    }
    }


    // ldap_server_connection_details->connection_timeout
    if(ldap_server_connection_details->connection_timeout) {
    if(cJSON_AddStringToObject(item, "connectionTimeout", ldap_server_connection_details->connection_timeout) == NULL) {
    goto fail; //String
    }
    }


    // ldap_server_connection_details->enable_ldaps
    if(ldap_server_connection_details->enable_ldaps) {
    if(cJSON_AddBoolToObject(item, "enableLdaps", ldap_server_connection_details->enable_ldaps) == NULL) {
    goto fail; //Bool
    }
    }


    // ldap_server_connection_details->ca_cert
    if(ldap_server_connection_details->ca_cert) {
    if(cJSON_AddStringToObject(item, "caCert", ldap_server_connection_details->ca_cert) == NULL) {
    goto fail; //String
    }
    }


    // ldap_server_connection_details->ca_verify
    if(ldap_server_connection_details->ca_verify) {
    if(cJSON_AddBoolToObject(item, "caVerify", ldap_server_connection_details->ca_verify) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ldap_server_connection_details_t *ldap_server_connection_details_parseFromJSON(cJSON *ldap_server_connection_detailsJSON){

    ldap_server_connection_details_t *ldap_server_connection_details_local_var = NULL;

    // ldap_server_connection_details->server_url
    cJSON *server_url = cJSON_GetObjectItemCaseSensitive(ldap_server_connection_detailsJSON, "serverUrl");
    if (cJSON_IsNull(server_url)) {
        server_url = NULL;
    }
    if (!server_url) {
        goto end;
    }

    
    if(!cJSON_IsString(server_url))
    {
    goto end; //String
    }

    // ldap_server_connection_details->port
    cJSON *port = cJSON_GetObjectItemCaseSensitive(ldap_server_connection_detailsJSON, "port");
    if (cJSON_IsNull(port)) {
        port = NULL;
    }
    if (port) { 
    if(!cJSON_IsString(port) && !cJSON_IsNull(port))
    {
    goto end; //String
    }
    }

    // ldap_server_connection_details->connection_timeout
    cJSON *connection_timeout = cJSON_GetObjectItemCaseSensitive(ldap_server_connection_detailsJSON, "connectionTimeout");
    if (cJSON_IsNull(connection_timeout)) {
        connection_timeout = NULL;
    }
    if (connection_timeout) { 
    if(!cJSON_IsString(connection_timeout) && !cJSON_IsNull(connection_timeout))
    {
    goto end; //String
    }
    }

    // ldap_server_connection_details->enable_ldaps
    cJSON *enable_ldaps = cJSON_GetObjectItemCaseSensitive(ldap_server_connection_detailsJSON, "enableLdaps");
    if (cJSON_IsNull(enable_ldaps)) {
        enable_ldaps = NULL;
    }
    if (enable_ldaps) { 
    if(!cJSON_IsBool(enable_ldaps))
    {
    goto end; //Bool
    }
    }

    // ldap_server_connection_details->ca_cert
    cJSON *ca_cert = cJSON_GetObjectItemCaseSensitive(ldap_server_connection_detailsJSON, "caCert");
    if (cJSON_IsNull(ca_cert)) {
        ca_cert = NULL;
    }
    if (ca_cert) { 
    if(!cJSON_IsString(ca_cert) && !cJSON_IsNull(ca_cert))
    {
    goto end; //String
    }
    }

    // ldap_server_connection_details->ca_verify
    cJSON *ca_verify = cJSON_GetObjectItemCaseSensitive(ldap_server_connection_detailsJSON, "caVerify");
    if (cJSON_IsNull(ca_verify)) {
        ca_verify = NULL;
    }
    if (ca_verify) { 
    if(!cJSON_IsBool(ca_verify))
    {
    goto end; //Bool
    }
    }


    ldap_server_connection_details_local_var = ldap_server_connection_details_create_internal (
        strdup(server_url->valuestring),
        port && !cJSON_IsNull(port) ? strdup(port->valuestring) : NULL,
        connection_timeout && !cJSON_IsNull(connection_timeout) ? strdup(connection_timeout->valuestring) : NULL,
        enable_ldaps ? enable_ldaps->valueint : 0,
        ca_cert && !cJSON_IsNull(ca_cert) ? strdup(ca_cert->valuestring) : NULL,
        ca_verify ? ca_verify->valueint : 0
        );

    return ldap_server_connection_details_local_var;
end:
    return NULL;

}
