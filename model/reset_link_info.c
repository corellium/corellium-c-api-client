#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "reset_link_info.h"



static reset_link_info_t *reset_link_info_create_internal(
    char *user_id,
    char *username,
    char *domain
    ) {
    reset_link_info_t *reset_link_info_local_var = malloc(sizeof(reset_link_info_t));
    if (!reset_link_info_local_var) {
        return NULL;
    }
    reset_link_info_local_var->user_id = user_id;
    reset_link_info_local_var->username = username;
    reset_link_info_local_var->domain = domain;

    reset_link_info_local_var->_library_owned = 1;
    return reset_link_info_local_var;
}

__attribute__((deprecated)) reset_link_info_t *reset_link_info_create(
    char *user_id,
    char *username,
    char *domain
    ) {
    return reset_link_info_create_internal (
        user_id,
        username,
        domain
        );
}

void reset_link_info_free(reset_link_info_t *reset_link_info) {
    if(NULL == reset_link_info){
        return ;
    }
    if(reset_link_info->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "reset_link_info_free");
        return ;
    }
    listEntry_t *listEntry;
    if (reset_link_info->user_id) {
        free(reset_link_info->user_id);
        reset_link_info->user_id = NULL;
    }
    if (reset_link_info->username) {
        free(reset_link_info->username);
        reset_link_info->username = NULL;
    }
    if (reset_link_info->domain) {
        free(reset_link_info->domain);
        reset_link_info->domain = NULL;
    }
    free(reset_link_info);
}

cJSON *reset_link_info_convertToJSON(reset_link_info_t *reset_link_info) {
    cJSON *item = cJSON_CreateObject();

    // reset_link_info->user_id
    if (!reset_link_info->user_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "userId", reset_link_info->user_id) == NULL) {
    goto fail; //String
    }


    // reset_link_info->username
    if (!reset_link_info->username) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "username", reset_link_info->username) == NULL) {
    goto fail; //String
    }


    // reset_link_info->domain
    if (!reset_link_info->domain) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "domain", reset_link_info->domain) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

reset_link_info_t *reset_link_info_parseFromJSON(cJSON *reset_link_infoJSON){

    reset_link_info_t *reset_link_info_local_var = NULL;

    // reset_link_info->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(reset_link_infoJSON, "userId");
    if (cJSON_IsNull(user_id)) {
        user_id = NULL;
    }
    if (!user_id) {
        goto end;
    }

    
    if(!cJSON_IsString(user_id))
    {
    goto end; //String
    }

    // reset_link_info->username
    cJSON *username = cJSON_GetObjectItemCaseSensitive(reset_link_infoJSON, "username");
    if (cJSON_IsNull(username)) {
        username = NULL;
    }
    if (!username) {
        goto end;
    }

    
    if(!cJSON_IsString(username))
    {
    goto end; //String
    }

    // reset_link_info->domain
    cJSON *domain = cJSON_GetObjectItemCaseSensitive(reset_link_infoJSON, "domain");
    if (cJSON_IsNull(domain)) {
        domain = NULL;
    }
    if (!domain) {
        goto end;
    }

    
    if(!cJSON_IsString(domain))
    {
    goto end; //String
    }


    reset_link_info_local_var = reset_link_info_create_internal (
        strdup(user_id->valuestring),
        strdup(username->valuestring),
        strdup(domain->valuestring)
        );

    return reset_link_info_local_var;
end:
    return NULL;

}
