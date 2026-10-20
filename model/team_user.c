#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "team_user.h"



static team_user_t *team_user_create_internal(
    char *id,
    char *label,
    char *name,
    char *email,
    int administrator,
    int can_edit_user_attributes,
    int cluster_administrator,
    int is_federated_user
    ) {
    team_user_t *team_user_local_var = malloc(sizeof(team_user_t));
    if (!team_user_local_var) {
        return NULL;
    }
    team_user_local_var->id = id;
    team_user_local_var->label = label;
    team_user_local_var->name = name;
    team_user_local_var->email = email;
    team_user_local_var->administrator = administrator;
    team_user_local_var->can_edit_user_attributes = can_edit_user_attributes;
    team_user_local_var->cluster_administrator = cluster_administrator;
    team_user_local_var->is_federated_user = is_federated_user;

    team_user_local_var->_library_owned = 1;
    return team_user_local_var;
}

__attribute__((deprecated)) team_user_t *team_user_create(
    char *id,
    char *label,
    char *name,
    char *email,
    int administrator,
    int can_edit_user_attributes,
    int cluster_administrator,
    int is_federated_user
    ) {
    return team_user_create_internal (
        id,
        label,
        name,
        email,
        administrator,
        can_edit_user_attributes,
        cluster_administrator,
        is_federated_user
        );
}

void team_user_free(team_user_t *team_user) {
    if(NULL == team_user){
        return ;
    }
    if(team_user->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "team_user_free");
        return ;
    }
    listEntry_t *listEntry;
    if (team_user->id) {
        free(team_user->id);
        team_user->id = NULL;
    }
    if (team_user->label) {
        free(team_user->label);
        team_user->label = NULL;
    }
    if (team_user->name) {
        free(team_user->name);
        team_user->name = NULL;
    }
    if (team_user->email) {
        free(team_user->email);
        team_user->email = NULL;
    }
    free(team_user);
}

cJSON *team_user_convertToJSON(team_user_t *team_user) {
    cJSON *item = cJSON_CreateObject();

    // team_user->id
    if (!team_user->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", team_user->id) == NULL) {
    goto fail; //String
    }


    // team_user->label
    if (!team_user->label) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "label", team_user->label) == NULL) {
    goto fail; //String
    }


    // team_user->name
    if(team_user->name) {
    if(cJSON_AddStringToObject(item, "name", team_user->name) == NULL) {
    goto fail; //String
    }
    }


    // team_user->email
    if(team_user->email) {
    if(cJSON_AddStringToObject(item, "email", team_user->email) == NULL) {
    goto fail; //String
    }
    }


    // team_user->administrator
    if(team_user->administrator) {
    if(cJSON_AddBoolToObject(item, "administrator", team_user->administrator) == NULL) {
    goto fail; //Bool
    }
    }


    // team_user->can_edit_user_attributes
    if(team_user->can_edit_user_attributes) {
    if(cJSON_AddBoolToObject(item, "canEditUserAttributes", team_user->can_edit_user_attributes) == NULL) {
    goto fail; //Bool
    }
    }


    // team_user->cluster_administrator
    if(team_user->cluster_administrator) {
    if(cJSON_AddBoolToObject(item, "clusterAdministrator", team_user->cluster_administrator) == NULL) {
    goto fail; //Bool
    }
    }


    // team_user->is_federated_user
    if(team_user->is_federated_user) {
    if(cJSON_AddBoolToObject(item, "isFederatedUser", team_user->is_federated_user) == NULL) {
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

team_user_t *team_user_parseFromJSON(cJSON *team_userJSON){

    team_user_t *team_user_local_var = NULL;

    // team_user->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(team_userJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }

    // team_user->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(team_userJSON, "label");
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

    // team_user->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(team_userJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // team_user->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(team_userJSON, "email");
    if (cJSON_IsNull(email)) {
        email = NULL;
    }
    if (email) { 
    if(!cJSON_IsString(email) && !cJSON_IsNull(email))
    {
    goto end; //String
    }
    }

    // team_user->administrator
    cJSON *administrator = cJSON_GetObjectItemCaseSensitive(team_userJSON, "administrator");
    if (cJSON_IsNull(administrator)) {
        administrator = NULL;
    }
    if (administrator) { 
    if(!cJSON_IsBool(administrator))
    {
    goto end; //Bool
    }
    }

    // team_user->can_edit_user_attributes
    cJSON *can_edit_user_attributes = cJSON_GetObjectItemCaseSensitive(team_userJSON, "canEditUserAttributes");
    if (cJSON_IsNull(can_edit_user_attributes)) {
        can_edit_user_attributes = NULL;
    }
    if (can_edit_user_attributes) { 
    if(!cJSON_IsBool(can_edit_user_attributes))
    {
    goto end; //Bool
    }
    }

    // team_user->cluster_administrator
    cJSON *cluster_administrator = cJSON_GetObjectItemCaseSensitive(team_userJSON, "clusterAdministrator");
    if (cJSON_IsNull(cluster_administrator)) {
        cluster_administrator = NULL;
    }
    if (cluster_administrator) { 
    if(!cJSON_IsBool(cluster_administrator))
    {
    goto end; //Bool
    }
    }

    // team_user->is_federated_user
    cJSON *is_federated_user = cJSON_GetObjectItemCaseSensitive(team_userJSON, "isFederatedUser");
    if (cJSON_IsNull(is_federated_user)) {
        is_federated_user = NULL;
    }
    if (is_federated_user) { 
    if(!cJSON_IsBool(is_federated_user))
    {
    goto end; //Bool
    }
    }


    team_user_local_var = team_user_create_internal (
        strdup(id->valuestring),
        strdup(label->valuestring),
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        email && !cJSON_IsNull(email) ? strdup(email->valuestring) : NULL,
        administrator ? administrator->valueint : 0,
        can_edit_user_attributes ? can_edit_user_attributes->valueint : 0,
        cluster_administrator ? cluster_administrator->valueint : 0,
        is_federated_user ? is_federated_user->valueint : 0
        );

    return team_user_local_var;
end:
    return NULL;

}
