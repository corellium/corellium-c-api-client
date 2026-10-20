#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "reset_link_info_return.h"



static reset_link_info_return_t *reset_link_info_return_create_internal(
    char *user_id,
    char *username,
    char *domain
    ) {
    reset_link_info_return_t *reset_link_info_return_local_var = malloc(sizeof(reset_link_info_return_t));
    if (!reset_link_info_return_local_var) {
        return NULL;
    }
    reset_link_info_return_local_var->user_id = user_id;
    reset_link_info_return_local_var->username = username;
    reset_link_info_return_local_var->domain = domain;

    reset_link_info_return_local_var->_library_owned = 1;
    return reset_link_info_return_local_var;
}

__attribute__((deprecated)) reset_link_info_return_t *reset_link_info_return_create(
    char *user_id,
    char *username,
    char *domain
    ) {
    return reset_link_info_return_create_internal (
        user_id,
        username,
        domain
        );
}

void reset_link_info_return_free(reset_link_info_return_t *reset_link_info_return) {
    if(NULL == reset_link_info_return){
        return ;
    }
    if(reset_link_info_return->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "reset_link_info_return_free");
        return ;
    }
    listEntry_t *listEntry;
    if (reset_link_info_return->user_id) {
        free(reset_link_info_return->user_id);
        reset_link_info_return->user_id = NULL;
    }
    if (reset_link_info_return->username) {
        free(reset_link_info_return->username);
        reset_link_info_return->username = NULL;
    }
    if (reset_link_info_return->domain) {
        free(reset_link_info_return->domain);
        reset_link_info_return->domain = NULL;
    }
    free(reset_link_info_return);
}

cJSON *reset_link_info_return_convertToJSON(reset_link_info_return_t *reset_link_info_return) {
    cJSON *item = cJSON_CreateObject();

    // reset_link_info_return->user_id
    if(reset_link_info_return->user_id) {
    if(cJSON_AddStringToObject(item, "userId", reset_link_info_return->user_id) == NULL) {
    goto fail; //String
    }
    }


    // reset_link_info_return->username
    if(reset_link_info_return->username) {
    if(cJSON_AddStringToObject(item, "username", reset_link_info_return->username) == NULL) {
    goto fail; //String
    }
    }


    // reset_link_info_return->domain
    if(reset_link_info_return->domain) {
    if(cJSON_AddStringToObject(item, "domain", reset_link_info_return->domain) == NULL) {
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

reset_link_info_return_t *reset_link_info_return_parseFromJSON(cJSON *reset_link_info_returnJSON){

    reset_link_info_return_t *reset_link_info_return_local_var = NULL;

    // reset_link_info_return->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(reset_link_info_returnJSON, "userId");
    if (cJSON_IsNull(user_id)) {
        user_id = NULL;
    }
    if (user_id) { 
    if(!cJSON_IsString(user_id) && !cJSON_IsNull(user_id))
    {
    goto end; //String
    }
    }

    // reset_link_info_return->username
    cJSON *username = cJSON_GetObjectItemCaseSensitive(reset_link_info_returnJSON, "username");
    if (cJSON_IsNull(username)) {
        username = NULL;
    }
    if (username) { 
    if(!cJSON_IsString(username) && !cJSON_IsNull(username))
    {
    goto end; //String
    }
    }

    // reset_link_info_return->domain
    cJSON *domain = cJSON_GetObjectItemCaseSensitive(reset_link_info_returnJSON, "domain");
    if (cJSON_IsNull(domain)) {
        domain = NULL;
    }
    if (domain) { 
    if(!cJSON_IsString(domain) && !cJSON_IsNull(domain))
    {
    goto end; //String
    }
    }


    reset_link_info_return_local_var = reset_link_info_return_create_internal (
        user_id && !cJSON_IsNull(user_id) ? strdup(user_id->valuestring) : NULL,
        username && !cJSON_IsNull(username) ? strdup(username->valuestring) : NULL,
        domain && !cJSON_IsNull(domain) ? strdup(domain->valuestring) : NULL
        );

    return reset_link_info_return_local_var;
end:
    return NULL;

}
