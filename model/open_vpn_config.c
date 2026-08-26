#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "open_vpn_config.h"



static open_vpn_config_t *open_vpn_config_create_internal(
    char *username,
    char *password,
    char *config
    ) {
    open_vpn_config_t *open_vpn_config_local_var = malloc(sizeof(open_vpn_config_t));
    if (!open_vpn_config_local_var) {
        return NULL;
    }
    open_vpn_config_local_var->username = username;
    open_vpn_config_local_var->password = password;
    open_vpn_config_local_var->config = config;

    open_vpn_config_local_var->_library_owned = 1;
    return open_vpn_config_local_var;
}

__attribute__((deprecated)) open_vpn_config_t *open_vpn_config_create(
    char *username,
    char *password,
    char *config
    ) {
    return open_vpn_config_create_internal (
        username,
        password,
        config
        );
}

void open_vpn_config_free(open_vpn_config_t *open_vpn_config) {
    if(NULL == open_vpn_config){
        return ;
    }
    if(open_vpn_config->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "open_vpn_config_free");
        return ;
    }
    listEntry_t *listEntry;
    if (open_vpn_config->username) {
        free(open_vpn_config->username);
        open_vpn_config->username = NULL;
    }
    if (open_vpn_config->password) {
        free(open_vpn_config->password);
        open_vpn_config->password = NULL;
    }
    if (open_vpn_config->config) {
        free(open_vpn_config->config);
        open_vpn_config->config = NULL;
    }
    free(open_vpn_config);
}

cJSON *open_vpn_config_convertToJSON(open_vpn_config_t *open_vpn_config) {
    cJSON *item = cJSON_CreateObject();

    // open_vpn_config->username
    if(open_vpn_config->username) {
    if(cJSON_AddStringToObject(item, "username", open_vpn_config->username) == NULL) {
    goto fail; //String
    }
    }


    // open_vpn_config->password
    if(open_vpn_config->password) {
    if(cJSON_AddStringToObject(item, "password", open_vpn_config->password) == NULL) {
    goto fail; //String
    }
    }


    // open_vpn_config->config
    if (!open_vpn_config->config) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "config", open_vpn_config->config) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

open_vpn_config_t *open_vpn_config_parseFromJSON(cJSON *open_vpn_configJSON){

    open_vpn_config_t *open_vpn_config_local_var = NULL;

    // open_vpn_config->username
    cJSON *username = cJSON_GetObjectItemCaseSensitive(open_vpn_configJSON, "username");
    if (cJSON_IsNull(username)) {
        username = NULL;
    }
    if (username) { 
    if(!cJSON_IsString(username) && !cJSON_IsNull(username))
    {
    goto end; //String
    }
    }

    // open_vpn_config->password
    cJSON *password = cJSON_GetObjectItemCaseSensitive(open_vpn_configJSON, "password");
    if (cJSON_IsNull(password)) {
        password = NULL;
    }
    if (password) { 
    if(!cJSON_IsString(password) && !cJSON_IsNull(password))
    {
    goto end; //String
    }
    }

    // open_vpn_config->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(open_vpn_configJSON, "config");
    if (cJSON_IsNull(config)) {
        config = NULL;
    }
    if (!config) {
        goto end;
    }

    
    if(!cJSON_IsString(config))
    {
    goto end; //String
    }


    open_vpn_config_local_var = open_vpn_config_create_internal (
        username && !cJSON_IsNull(username) ? strdup(username->valuestring) : NULL,
        password && !cJSON_IsNull(password) ? strdup(password->valuestring) : NULL,
        strdup(config->valuestring)
        );

    return open_vpn_config_local_var;
end:
    return NULL;

}
