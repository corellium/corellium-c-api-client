#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "user_create.h"



static user_create_t *user_create_create_internal(
    char *name,
    char *label,
    char *password,
    char *email,
    int administrator,
    int cluster_administrator
    ) {
    user_create_t *user_create_local_var = malloc(sizeof(user_create_t));
    if (!user_create_local_var) {
        return NULL;
    }
    user_create_local_var->name = name;
    user_create_local_var->label = label;
    user_create_local_var->password = password;
    user_create_local_var->email = email;
    user_create_local_var->administrator = administrator;
    user_create_local_var->cluster_administrator = cluster_administrator;

    user_create_local_var->_library_owned = 1;
    return user_create_local_var;
}

__attribute__((deprecated)) user_create_t *user_create_create(
    char *name,
    char *label,
    char *password,
    char *email,
    int administrator,
    int cluster_administrator
    ) {
    return user_create_create_internal (
        name,
        label,
        password,
        email,
        administrator,
        cluster_administrator
        );
}

void user_create_free(user_create_t *user_create) {
    if(NULL == user_create){
        return ;
    }
    if(user_create->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "user_create_free");
        return ;
    }
    listEntry_t *listEntry;
    if (user_create->name) {
        free(user_create->name);
        user_create->name = NULL;
    }
    if (user_create->label) {
        free(user_create->label);
        user_create->label = NULL;
    }
    if (user_create->password) {
        free(user_create->password);
        user_create->password = NULL;
    }
    if (user_create->email) {
        free(user_create->email);
        user_create->email = NULL;
    }
    free(user_create);
}

cJSON *user_create_convertToJSON(user_create_t *user_create) {
    cJSON *item = cJSON_CreateObject();

    // user_create->name
    if(user_create->name) {
    if(cJSON_AddStringToObject(item, "name", user_create->name) == NULL) {
    goto fail; //String
    }
    }


    // user_create->label
    if(user_create->label) {
    if(cJSON_AddStringToObject(item, "label", user_create->label) == NULL) {
    goto fail; //String
    }
    }


    // user_create->password
    if(user_create->password) {
    if(cJSON_AddStringToObject(item, "password", user_create->password) == NULL) {
    goto fail; //String
    }
    }


    // user_create->email
    if(user_create->email) {
    if(cJSON_AddStringToObject(item, "email", user_create->email) == NULL) {
    goto fail; //String
    }
    }


    // user_create->administrator
    if(user_create->administrator) {
    if(cJSON_AddBoolToObject(item, "administrator", user_create->administrator) == NULL) {
    goto fail; //Bool
    }
    }


    // user_create->cluster_administrator
    if(user_create->cluster_administrator) {
    if(cJSON_AddBoolToObject(item, "clusterAdministrator", user_create->cluster_administrator) == NULL) {
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

user_create_t *user_create_parseFromJSON(cJSON *user_createJSON){

    user_create_t *user_create_local_var = NULL;

    // user_create->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(user_createJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // user_create->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(user_createJSON, "label");
    if (cJSON_IsNull(label)) {
        label = NULL;
    }
    if (label) { 
    if(!cJSON_IsString(label) && !cJSON_IsNull(label))
    {
    goto end; //String
    }
    }

    // user_create->password
    cJSON *password = cJSON_GetObjectItemCaseSensitive(user_createJSON, "password");
    if (cJSON_IsNull(password)) {
        password = NULL;
    }
    if (password) { 
    if(!cJSON_IsString(password) && !cJSON_IsNull(password))
    {
    goto end; //String
    }
    }

    // user_create->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(user_createJSON, "email");
    if (cJSON_IsNull(email)) {
        email = NULL;
    }
    if (email) { 
    if(!cJSON_IsString(email) && !cJSON_IsNull(email))
    {
    goto end; //String
    }
    }

    // user_create->administrator
    cJSON *administrator = cJSON_GetObjectItemCaseSensitive(user_createJSON, "administrator");
    if (cJSON_IsNull(administrator)) {
        administrator = NULL;
    }
    if (administrator) { 
    if(!cJSON_IsBool(administrator))
    {
    goto end; //Bool
    }
    }

    // user_create->cluster_administrator
    cJSON *cluster_administrator = cJSON_GetObjectItemCaseSensitive(user_createJSON, "clusterAdministrator");
    if (cJSON_IsNull(cluster_administrator)) {
        cluster_administrator = NULL;
    }
    if (cluster_administrator) { 
    if(!cJSON_IsBool(cluster_administrator))
    {
    goto end; //Bool
    }
    }


    user_create_local_var = user_create_create_internal (
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        label && !cJSON_IsNull(label) ? strdup(label->valuestring) : NULL,
        password && !cJSON_IsNull(password) ? strdup(password->valuestring) : NULL,
        email && !cJSON_IsNull(email) ? strdup(email->valuestring) : NULL,
        administrator ? administrator->valueint : 0,
        cluster_administrator ? cluster_administrator->valueint : 0
        );

    return user_create_local_var;
end:
    return NULL;

}
