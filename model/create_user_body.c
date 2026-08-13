#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_user_body.h"



static create_user_body_t *create_user_body_create_internal(
    char *password,
    int administrator,
    char *name,
    char *label,
    char *email,
    int cluster_administrator
    ) {
    create_user_body_t *create_user_body_local_var = malloc(sizeof(create_user_body_t));
    if (!create_user_body_local_var) {
        return NULL;
    }
    create_user_body_local_var->password = password;
    create_user_body_local_var->administrator = administrator;
    create_user_body_local_var->name = name;
    create_user_body_local_var->label = label;
    create_user_body_local_var->email = email;
    create_user_body_local_var->cluster_administrator = cluster_administrator;

    create_user_body_local_var->_library_owned = 1;
    return create_user_body_local_var;
}

__attribute__((deprecated)) create_user_body_t *create_user_body_create(
    char *password,
    int administrator,
    char *name,
    char *label,
    char *email,
    int cluster_administrator
    ) {
    return create_user_body_create_internal (
        password,
        administrator,
        name,
        label,
        email,
        cluster_administrator
        );
}

void create_user_body_free(create_user_body_t *create_user_body) {
    if(NULL == create_user_body){
        return ;
    }
    if(create_user_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "create_user_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (create_user_body->password) {
        free(create_user_body->password);
        create_user_body->password = NULL;
    }
    if (create_user_body->name) {
        free(create_user_body->name);
        create_user_body->name = NULL;
    }
    if (create_user_body->label) {
        free(create_user_body->label);
        create_user_body->label = NULL;
    }
    if (create_user_body->email) {
        free(create_user_body->email);
        create_user_body->email = NULL;
    }
    free(create_user_body);
}

cJSON *create_user_body_convertToJSON(create_user_body_t *create_user_body) {
    cJSON *item = cJSON_CreateObject();

    // create_user_body->password
    if(create_user_body->password) {
    if(cJSON_AddStringToObject(item, "password", create_user_body->password) == NULL) {
    goto fail; //String
    }
    }


    // create_user_body->administrator
    if(create_user_body->administrator) {
    if(cJSON_AddBoolToObject(item, "administrator", create_user_body->administrator) == NULL) {
    goto fail; //Bool
    }
    }


    // create_user_body->name
    if (!create_user_body->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", create_user_body->name) == NULL) {
    goto fail; //String
    }


    // create_user_body->label
    if (!create_user_body->label) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "label", create_user_body->label) == NULL) {
    goto fail; //String
    }


    // create_user_body->email
    if(create_user_body->email) {
    if(cJSON_AddStringToObject(item, "email", create_user_body->email) == NULL) {
    goto fail; //String
    }
    }


    // create_user_body->cluster_administrator
    if(create_user_body->cluster_administrator) {
    if(cJSON_AddBoolToObject(item, "clusterAdministrator", create_user_body->cluster_administrator) == NULL) {
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

create_user_body_t *create_user_body_parseFromJSON(cJSON *create_user_bodyJSON){

    create_user_body_t *create_user_body_local_var = NULL;

    // create_user_body->password
    cJSON *password = cJSON_GetObjectItemCaseSensitive(create_user_bodyJSON, "password");
    if (cJSON_IsNull(password)) {
        password = NULL;
    }
    if (password) { 
    if(!cJSON_IsString(password) && !cJSON_IsNull(password))
    {
    goto end; //String
    }
    }

    // create_user_body->administrator
    cJSON *administrator = cJSON_GetObjectItemCaseSensitive(create_user_bodyJSON, "administrator");
    if (cJSON_IsNull(administrator)) {
        administrator = NULL;
    }
    if (administrator) { 
    if(!cJSON_IsBool(administrator))
    {
    goto end; //Bool
    }
    }

    // create_user_body->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(create_user_bodyJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // create_user_body->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(create_user_bodyJSON, "label");
    if (cJSON_IsNull(label)) {
        label = NULL;
    }
    if (!label) {
        goto end;
    }

    
    if(!cJSON_IsString(label))
    {
    goto end; //String
    }

    // create_user_body->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(create_user_bodyJSON, "email");
    if (cJSON_IsNull(email)) {
        email = NULL;
    }
    if (email) { 
    if(!cJSON_IsString(email) && !cJSON_IsNull(email))
    {
    goto end; //String
    }
    }

    // create_user_body->cluster_administrator
    cJSON *cluster_administrator = cJSON_GetObjectItemCaseSensitive(create_user_bodyJSON, "clusterAdministrator");
    if (cJSON_IsNull(cluster_administrator)) {
        cluster_administrator = NULL;
    }
    if (cluster_administrator) { 
    if(!cJSON_IsBool(cluster_administrator))
    {
    goto end; //Bool
    }
    }


    create_user_body_local_var = create_user_body_create_internal (
        password && !cJSON_IsNull(password) ? strdup(password->valuestring) : NULL,
        administrator ? administrator->valueint : 0,
        strdup(name->valuestring),
        strdup(label->valuestring),
        email && !cJSON_IsNull(email) ? strdup(email->valuestring) : NULL,
        cluster_administrator ? cluster_administrator->valueint : 0
        );

    return create_user_body_local_var;
end:
    return NULL;

}
