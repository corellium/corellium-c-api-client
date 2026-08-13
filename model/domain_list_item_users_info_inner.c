#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "domain_list_item_users_info_inner.h"



static domain_list_item_users_info_inner_t *domain_list_item_users_info_inner_create_internal(
    char *id,
    char *label,
    char *name,
    char *email,
    int administrator,
    int cluster_administrator,
    char *last_login,
    double teams
    ) {
    domain_list_item_users_info_inner_t *domain_list_item_users_info_inner_local_var = malloc(sizeof(domain_list_item_users_info_inner_t));
    if (!domain_list_item_users_info_inner_local_var) {
        return NULL;
    }
    domain_list_item_users_info_inner_local_var->id = id;
    domain_list_item_users_info_inner_local_var->label = label;
    domain_list_item_users_info_inner_local_var->name = name;
    domain_list_item_users_info_inner_local_var->email = email;
    domain_list_item_users_info_inner_local_var->administrator = administrator;
    domain_list_item_users_info_inner_local_var->cluster_administrator = cluster_administrator;
    domain_list_item_users_info_inner_local_var->last_login = last_login;
    domain_list_item_users_info_inner_local_var->teams = teams;

    domain_list_item_users_info_inner_local_var->_library_owned = 1;
    return domain_list_item_users_info_inner_local_var;
}

__attribute__((deprecated)) domain_list_item_users_info_inner_t *domain_list_item_users_info_inner_create(
    char *id,
    char *label,
    char *name,
    char *email,
    int administrator,
    int cluster_administrator,
    char *last_login,
    double teams
    ) {
    return domain_list_item_users_info_inner_create_internal (
        id,
        label,
        name,
        email,
        administrator,
        cluster_administrator,
        last_login,
        teams
        );
}

void domain_list_item_users_info_inner_free(domain_list_item_users_info_inner_t *domain_list_item_users_info_inner) {
    if(NULL == domain_list_item_users_info_inner){
        return ;
    }
    if(domain_list_item_users_info_inner->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "domain_list_item_users_info_inner_free");
        return ;
    }
    listEntry_t *listEntry;
    if (domain_list_item_users_info_inner->id) {
        free(domain_list_item_users_info_inner->id);
        domain_list_item_users_info_inner->id = NULL;
    }
    if (domain_list_item_users_info_inner->label) {
        free(domain_list_item_users_info_inner->label);
        domain_list_item_users_info_inner->label = NULL;
    }
    if (domain_list_item_users_info_inner->name) {
        free(domain_list_item_users_info_inner->name);
        domain_list_item_users_info_inner->name = NULL;
    }
    if (domain_list_item_users_info_inner->email) {
        free(domain_list_item_users_info_inner->email);
        domain_list_item_users_info_inner->email = NULL;
    }
    if (domain_list_item_users_info_inner->last_login) {
        free(domain_list_item_users_info_inner->last_login);
        domain_list_item_users_info_inner->last_login = NULL;
    }
    free(domain_list_item_users_info_inner);
}

cJSON *domain_list_item_users_info_inner_convertToJSON(domain_list_item_users_info_inner_t *domain_list_item_users_info_inner) {
    cJSON *item = cJSON_CreateObject();

    // domain_list_item_users_info_inner->id
    if (!domain_list_item_users_info_inner->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", domain_list_item_users_info_inner->id) == NULL) {
    goto fail; //String
    }


    // domain_list_item_users_info_inner->label
    if (!domain_list_item_users_info_inner->label) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "label", domain_list_item_users_info_inner->label) == NULL) {
    goto fail; //String
    }


    // domain_list_item_users_info_inner->name
    if (!domain_list_item_users_info_inner->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", domain_list_item_users_info_inner->name) == NULL) {
    goto fail; //String
    }


    // domain_list_item_users_info_inner->email
    if (!domain_list_item_users_info_inner->email) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "email", domain_list_item_users_info_inner->email) == NULL) {
    goto fail; //String
    }


    // domain_list_item_users_info_inner->administrator
    if (!domain_list_item_users_info_inner->administrator) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "administrator", domain_list_item_users_info_inner->administrator) == NULL) {
    goto fail; //Bool
    }


    // domain_list_item_users_info_inner->cluster_administrator
    if (!domain_list_item_users_info_inner->cluster_administrator) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "clusterAdministrator", domain_list_item_users_info_inner->cluster_administrator) == NULL) {
    goto fail; //Bool
    }


    // domain_list_item_users_info_inner->last_login
    if(domain_list_item_users_info_inner->last_login) {
    if(cJSON_AddStringToObject(item, "lastLogin", domain_list_item_users_info_inner->last_login) == NULL) {
    goto fail; //Date-Time
    }
    }


    // domain_list_item_users_info_inner->teams
    if (!domain_list_item_users_info_inner->teams) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "teams", domain_list_item_users_info_inner->teams) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

domain_list_item_users_info_inner_t *domain_list_item_users_info_inner_parseFromJSON(cJSON *domain_list_item_users_info_innerJSON){

    domain_list_item_users_info_inner_t *domain_list_item_users_info_inner_local_var = NULL;

    // domain_list_item_users_info_inner->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(domain_list_item_users_info_innerJSON, "id");
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

    // domain_list_item_users_info_inner->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(domain_list_item_users_info_innerJSON, "label");
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

    // domain_list_item_users_info_inner->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(domain_list_item_users_info_innerJSON, "name");
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

    // domain_list_item_users_info_inner->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(domain_list_item_users_info_innerJSON, "email");
    if (cJSON_IsNull(email)) {
        email = NULL;
    }
    if (!email) {
        goto end;
    }

    
    if(!cJSON_IsString(email))
    {
    goto end; //String
    }

    // domain_list_item_users_info_inner->administrator
    cJSON *administrator = cJSON_GetObjectItemCaseSensitive(domain_list_item_users_info_innerJSON, "administrator");
    if (cJSON_IsNull(administrator)) {
        administrator = NULL;
    }
    if (!administrator) {
        goto end;
    }

    
    if(!cJSON_IsBool(administrator))
    {
    goto end; //Bool
    }

    // domain_list_item_users_info_inner->cluster_administrator
    cJSON *cluster_administrator = cJSON_GetObjectItemCaseSensitive(domain_list_item_users_info_innerJSON, "clusterAdministrator");
    if (cJSON_IsNull(cluster_administrator)) {
        cluster_administrator = NULL;
    }
    if (!cluster_administrator) {
        goto end;
    }

    
    if(!cJSON_IsBool(cluster_administrator))
    {
    goto end; //Bool
    }

    // domain_list_item_users_info_inner->last_login
    cJSON *last_login = cJSON_GetObjectItemCaseSensitive(domain_list_item_users_info_innerJSON, "lastLogin");
    if (cJSON_IsNull(last_login)) {
        last_login = NULL;
    }
    if (last_login) { 
    if(!cJSON_IsString(last_login) && !cJSON_IsNull(last_login))
    {
    goto end; //DateTime
    }
    }

    // domain_list_item_users_info_inner->teams
    cJSON *teams = cJSON_GetObjectItemCaseSensitive(domain_list_item_users_info_innerJSON, "teams");
    if (cJSON_IsNull(teams)) {
        teams = NULL;
    }
    if (!teams) {
        goto end;
    }

    
    if(!cJSON_IsNumber(teams))
    {
    goto end; //Numeric
    }


    domain_list_item_users_info_inner_local_var = domain_list_item_users_info_inner_create_internal (
        strdup(id->valuestring),
        strdup(label->valuestring),
        strdup(name->valuestring),
        strdup(email->valuestring),
        administrator->valueint,
        cluster_administrator->valueint,
        last_login && !cJSON_IsNull(last_login) ? strdup(last_login->valuestring) : NULL,
        teams->valuedouble
        );

    return domain_list_item_users_info_inner_local_var;
end:
    return NULL;

}
