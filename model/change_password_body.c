#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "change_password_body.h"



static change_password_body_t *change_password_body_create_internal(
    char *user,
    char *old_password,
    char *new_password
    ) {
    change_password_body_t *change_password_body_local_var = malloc(sizeof(change_password_body_t));
    if (!change_password_body_local_var) {
        return NULL;
    }
    change_password_body_local_var->user = user;
    change_password_body_local_var->old_password = old_password;
    change_password_body_local_var->new_password = new_password;

    change_password_body_local_var->_library_owned = 1;
    return change_password_body_local_var;
}

__attribute__((deprecated)) change_password_body_t *change_password_body_create(
    char *user,
    char *old_password,
    char *new_password
    ) {
    return change_password_body_create_internal (
        user,
        old_password,
        new_password
        );
}

void change_password_body_free(change_password_body_t *change_password_body) {
    if(NULL == change_password_body){
        return ;
    }
    if(change_password_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "change_password_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (change_password_body->user) {
        free(change_password_body->user);
        change_password_body->user = NULL;
    }
    if (change_password_body->old_password) {
        free(change_password_body->old_password);
        change_password_body->old_password = NULL;
    }
    if (change_password_body->new_password) {
        free(change_password_body->new_password);
        change_password_body->new_password = NULL;
    }
    free(change_password_body);
}

cJSON *change_password_body_convertToJSON(change_password_body_t *change_password_body) {
    cJSON *item = cJSON_CreateObject();

    // change_password_body->user
    if(change_password_body->user) {
    if(cJSON_AddStringToObject(item, "user", change_password_body->user) == NULL) {
    goto fail; //String
    }
    }


    // change_password_body->old_password
    if(change_password_body->old_password) {
    if(cJSON_AddStringToObject(item, "oldPassword", change_password_body->old_password) == NULL) {
    goto fail; //String
    }
    }


    // change_password_body->new_password
    if(change_password_body->new_password) {
    if(cJSON_AddStringToObject(item, "newPassword", change_password_body->new_password) == NULL) {
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

change_password_body_t *change_password_body_parseFromJSON(cJSON *change_password_bodyJSON){

    change_password_body_t *change_password_body_local_var = NULL;

    // change_password_body->user
    cJSON *user = cJSON_GetObjectItemCaseSensitive(change_password_bodyJSON, "user");
    if (cJSON_IsNull(user)) {
        user = NULL;
    }
    if (user) { 
    if(!cJSON_IsString(user) && !cJSON_IsNull(user))
    {
    goto end; //String
    }
    }

    // change_password_body->old_password
    cJSON *old_password = cJSON_GetObjectItemCaseSensitive(change_password_bodyJSON, "oldPassword");
    if (cJSON_IsNull(old_password)) {
        old_password = NULL;
    }
    if (old_password) { 
    if(!cJSON_IsString(old_password) && !cJSON_IsNull(old_password))
    {
    goto end; //String
    }
    }

    // change_password_body->new_password
    cJSON *new_password = cJSON_GetObjectItemCaseSensitive(change_password_bodyJSON, "newPassword");
    if (cJSON_IsNull(new_password)) {
        new_password = NULL;
    }
    if (new_password) { 
    if(!cJSON_IsString(new_password) && !cJSON_IsNull(new_password))
    {
    goto end; //String
    }
    }


    change_password_body_local_var = change_password_body_create_internal (
        user && !cJSON_IsNull(user) ? strdup(user->valuestring) : NULL,
        old_password && !cJSON_IsNull(old_password) ? strdup(old_password->valuestring) : NULL,
        new_password && !cJSON_IsNull(new_password) ? strdup(new_password->valuestring) : NULL
        );

    return change_password_body_local_var;
end:
    return NULL;

}
