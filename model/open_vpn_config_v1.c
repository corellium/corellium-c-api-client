#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "open_vpn_config_v1.h"



static open_vpn_config_v1_t *open_vpn_config_v1_create_internal(
    char *username,
    char *password,
    char *config
    ) {
    open_vpn_config_v1_t *open_vpn_config_v1_local_var = malloc(sizeof(open_vpn_config_v1_t));
    if (!open_vpn_config_v1_local_var) {
        return NULL;
    }
    open_vpn_config_v1_local_var->username = username;
    open_vpn_config_v1_local_var->password = password;
    open_vpn_config_v1_local_var->config = config;

    open_vpn_config_v1_local_var->_library_owned = 1;
    return open_vpn_config_v1_local_var;
}

__attribute__((deprecated)) open_vpn_config_v1_t *open_vpn_config_v1_create(
    char *username,
    char *password,
    char *config
    ) {
    return open_vpn_config_v1_create_internal (
        username,
        password,
        config
        );
}

void open_vpn_config_v1_free(open_vpn_config_v1_t *open_vpn_config_v1) {
    if(NULL == open_vpn_config_v1){
        return ;
    }
    if(open_vpn_config_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "open_vpn_config_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (open_vpn_config_v1->username) {
        free(open_vpn_config_v1->username);
        open_vpn_config_v1->username = NULL;
    }
    if (open_vpn_config_v1->password) {
        free(open_vpn_config_v1->password);
        open_vpn_config_v1->password = NULL;
    }
    if (open_vpn_config_v1->config) {
        free(open_vpn_config_v1->config);
        open_vpn_config_v1->config = NULL;
    }
    free(open_vpn_config_v1);
}

cJSON *open_vpn_config_v1_convertToJSON(open_vpn_config_v1_t *open_vpn_config_v1) {
    cJSON *item = cJSON_CreateObject();

    // open_vpn_config_v1->username
    if(open_vpn_config_v1->username) {
    if(cJSON_AddStringToObject(item, "username", open_vpn_config_v1->username) == NULL) {
    goto fail; //String
    }
    }


    // open_vpn_config_v1->password
    if(open_vpn_config_v1->password) {
    if(cJSON_AddStringToObject(item, "password", open_vpn_config_v1->password) == NULL) {
    goto fail; //String
    }
    }


    // open_vpn_config_v1->config
    if (!open_vpn_config_v1->config) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "config", open_vpn_config_v1->config) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

open_vpn_config_v1_t *open_vpn_config_v1_parseFromJSON(cJSON *open_vpn_config_v1JSON){

    open_vpn_config_v1_t *open_vpn_config_v1_local_var = NULL;

    // open_vpn_config_v1->username
    cJSON *username = cJSON_GetObjectItemCaseSensitive(open_vpn_config_v1JSON, "username");
    if (cJSON_IsNull(username)) {
        username = NULL;
    }
    if (username) { 
    if(!cJSON_IsString(username) && !cJSON_IsNull(username))
    {
    goto end; //String
    }
    }

    // open_vpn_config_v1->password
    cJSON *password = cJSON_GetObjectItemCaseSensitive(open_vpn_config_v1JSON, "password");
    if (cJSON_IsNull(password)) {
        password = NULL;
    }
    if (password) { 
    if(!cJSON_IsString(password) && !cJSON_IsNull(password))
    {
    goto end; //String
    }
    }

    // open_vpn_config_v1->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(open_vpn_config_v1JSON, "config");
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


    open_vpn_config_v1_local_var = open_vpn_config_v1_create_internal (
        username && !cJSON_IsNull(username) ? strdup(username->valuestring) : NULL,
        password && !cJSON_IsNull(password) ? strdup(password->valuestring) : NULL,
        strdup(config->valuestring)
        );

    return open_vpn_config_v1_local_var;
end:
    return NULL;

}
