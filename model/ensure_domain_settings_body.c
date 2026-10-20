#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ensure_domain_settings_body.h"



static ensure_domain_settings_body_t *ensure_domain_settings_body_create_internal(
    char *fqdn,
    char *name,
    double cores,
    char *password,
    char *password_if_empty,
    domain_config_input_t *config,
    ensure_domain_settings_body_admin_user_t *admin_user
    ) {
    ensure_domain_settings_body_t *ensure_domain_settings_body_local_var = malloc(sizeof(ensure_domain_settings_body_t));
    if (!ensure_domain_settings_body_local_var) {
        return NULL;
    }
    ensure_domain_settings_body_local_var->fqdn = fqdn;
    ensure_domain_settings_body_local_var->name = name;
    ensure_domain_settings_body_local_var->cores = cores;
    ensure_domain_settings_body_local_var->password = password;
    ensure_domain_settings_body_local_var->password_if_empty = password_if_empty;
    ensure_domain_settings_body_local_var->config = config;
    ensure_domain_settings_body_local_var->admin_user = admin_user;

    ensure_domain_settings_body_local_var->_library_owned = 1;
    return ensure_domain_settings_body_local_var;
}

__attribute__((deprecated)) ensure_domain_settings_body_t *ensure_domain_settings_body_create(
    char *fqdn,
    char *name,
    double cores,
    char *password,
    char *password_if_empty,
    domain_config_input_t *config,
    ensure_domain_settings_body_admin_user_t *admin_user
    ) {
    return ensure_domain_settings_body_create_internal (
        fqdn,
        name,
        cores,
        password,
        password_if_empty,
        config,
        admin_user
        );
}

void ensure_domain_settings_body_free(ensure_domain_settings_body_t *ensure_domain_settings_body) {
    if(NULL == ensure_domain_settings_body){
        return ;
    }
    if(ensure_domain_settings_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ensure_domain_settings_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ensure_domain_settings_body->fqdn) {
        free(ensure_domain_settings_body->fqdn);
        ensure_domain_settings_body->fqdn = NULL;
    }
    if (ensure_domain_settings_body->name) {
        free(ensure_domain_settings_body->name);
        ensure_domain_settings_body->name = NULL;
    }
    if (ensure_domain_settings_body->password) {
        free(ensure_domain_settings_body->password);
        ensure_domain_settings_body->password = NULL;
    }
    if (ensure_domain_settings_body->password_if_empty) {
        free(ensure_domain_settings_body->password_if_empty);
        ensure_domain_settings_body->password_if_empty = NULL;
    }
    if (ensure_domain_settings_body->config) {
        domain_config_input_free(ensure_domain_settings_body->config);
        ensure_domain_settings_body->config = NULL;
    }
    if (ensure_domain_settings_body->admin_user) {
        ensure_domain_settings_body_admin_user_free(ensure_domain_settings_body->admin_user);
        ensure_domain_settings_body->admin_user = NULL;
    }
    free(ensure_domain_settings_body);
}

cJSON *ensure_domain_settings_body_convertToJSON(ensure_domain_settings_body_t *ensure_domain_settings_body) {
    cJSON *item = cJSON_CreateObject();

    // ensure_domain_settings_body->fqdn
    if(ensure_domain_settings_body->fqdn) {
    if(cJSON_AddStringToObject(item, "fqdn", ensure_domain_settings_body->fqdn) == NULL) {
    goto fail; //String
    }
    }


    // ensure_domain_settings_body->name
    if(ensure_domain_settings_body->name) {
    if(cJSON_AddStringToObject(item, "name", ensure_domain_settings_body->name) == NULL) {
    goto fail; //String
    }
    }


    // ensure_domain_settings_body->cores
    if(ensure_domain_settings_body->cores) {
    if(cJSON_AddNumberToObject(item, "cores", ensure_domain_settings_body->cores) == NULL) {
    goto fail; //Numeric
    }
    }


    // ensure_domain_settings_body->password
    if(ensure_domain_settings_body->password) {
    if(cJSON_AddStringToObject(item, "password", ensure_domain_settings_body->password) == NULL) {
    goto fail; //String
    }
    }


    // ensure_domain_settings_body->password_if_empty
    if(ensure_domain_settings_body->password_if_empty) {
    if(cJSON_AddStringToObject(item, "passwordIfEmpty", ensure_domain_settings_body->password_if_empty) == NULL) {
    goto fail; //String
    }
    }


    // ensure_domain_settings_body->config
    if(ensure_domain_settings_body->config) {
    cJSON *config_local_JSON = domain_config_input_convertToJSON(ensure_domain_settings_body->config);
    if(config_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "config", config_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // ensure_domain_settings_body->admin_user
    if(ensure_domain_settings_body->admin_user) {
    cJSON *admin_user_local_JSON = ensure_domain_settings_body_admin_user_convertToJSON(ensure_domain_settings_body->admin_user);
    if(admin_user_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "adminUser", admin_user_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ensure_domain_settings_body_t *ensure_domain_settings_body_parseFromJSON(cJSON *ensure_domain_settings_bodyJSON){

    ensure_domain_settings_body_t *ensure_domain_settings_body_local_var = NULL;

    // define the local variable for ensure_domain_settings_body->config
    domain_config_input_t *config_local_nonprim = NULL;

    // define the local variable for ensure_domain_settings_body->admin_user
    ensure_domain_settings_body_admin_user_t *admin_user_local_nonprim = NULL;

    // ensure_domain_settings_body->fqdn
    cJSON *fqdn = cJSON_GetObjectItemCaseSensitive(ensure_domain_settings_bodyJSON, "fqdn");
    if (cJSON_IsNull(fqdn)) {
        fqdn = NULL;
    }
    if (fqdn) { 
    if(!cJSON_IsString(fqdn) && !cJSON_IsNull(fqdn))
    {
    goto end; //String
    }
    }

    // ensure_domain_settings_body->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(ensure_domain_settings_bodyJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // ensure_domain_settings_body->cores
    cJSON *cores = cJSON_GetObjectItemCaseSensitive(ensure_domain_settings_bodyJSON, "cores");
    if (cJSON_IsNull(cores)) {
        cores = NULL;
    }
    if (cores) { 
    if(!cJSON_IsNumber(cores))
    {
    goto end; //Numeric
    }
    }

    // ensure_domain_settings_body->password
    cJSON *password = cJSON_GetObjectItemCaseSensitive(ensure_domain_settings_bodyJSON, "password");
    if (cJSON_IsNull(password)) {
        password = NULL;
    }
    if (password) { 
    if(!cJSON_IsString(password) && !cJSON_IsNull(password))
    {
    goto end; //String
    }
    }

    // ensure_domain_settings_body->password_if_empty
    cJSON *password_if_empty = cJSON_GetObjectItemCaseSensitive(ensure_domain_settings_bodyJSON, "passwordIfEmpty");
    if (cJSON_IsNull(password_if_empty)) {
        password_if_empty = NULL;
    }
    if (password_if_empty) { 
    if(!cJSON_IsString(password_if_empty) && !cJSON_IsNull(password_if_empty))
    {
    goto end; //String
    }
    }

    // ensure_domain_settings_body->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(ensure_domain_settings_bodyJSON, "config");
    if (cJSON_IsNull(config)) {
        config = NULL;
    }
    if (config) { 
    config_local_nonprim = domain_config_input_parseFromJSON(config); //nonprimitive
    }

    // ensure_domain_settings_body->admin_user
    cJSON *admin_user = cJSON_GetObjectItemCaseSensitive(ensure_domain_settings_bodyJSON, "adminUser");
    if (cJSON_IsNull(admin_user)) {
        admin_user = NULL;
    }
    if (admin_user) { 
    admin_user_local_nonprim = ensure_domain_settings_body_admin_user_parseFromJSON(admin_user); //nonprimitive
    }


    ensure_domain_settings_body_local_var = ensure_domain_settings_body_create_internal (
        fqdn && !cJSON_IsNull(fqdn) ? strdup(fqdn->valuestring) : NULL,
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        cores ? cores->valuedouble : 0,
        password && !cJSON_IsNull(password) ? strdup(password->valuestring) : NULL,
        password_if_empty && !cJSON_IsNull(password_if_empty) ? strdup(password_if_empty->valuestring) : NULL,
        config ? config_local_nonprim : NULL,
        admin_user ? admin_user_local_nonprim : NULL
        );

    return ensure_domain_settings_body_local_var;
end:
    if (config_local_nonprim) {
        domain_config_input_free(config_local_nonprim);
        config_local_nonprim = NULL;
    }
    if (admin_user_local_nonprim) {
        ensure_domain_settings_body_admin_user_free(admin_user_local_nonprim);
        admin_user_local_nonprim = NULL;
    }
    return NULL;

}
