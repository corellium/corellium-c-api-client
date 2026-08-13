#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "web_player_session_domain.h"



static web_player_session_domain_t *web_player_session_domain_create_internal(
    char *name,
    char *label,
    char *terms_policy,
    double cores,
    int individual,
    int totp_required
    ) {
    web_player_session_domain_t *web_player_session_domain_local_var = malloc(sizeof(web_player_session_domain_t));
    if (!web_player_session_domain_local_var) {
        return NULL;
    }
    web_player_session_domain_local_var->name = name;
    web_player_session_domain_local_var->label = label;
    web_player_session_domain_local_var->terms_policy = terms_policy;
    web_player_session_domain_local_var->cores = cores;
    web_player_session_domain_local_var->individual = individual;
    web_player_session_domain_local_var->totp_required = totp_required;

    web_player_session_domain_local_var->_library_owned = 1;
    return web_player_session_domain_local_var;
}

__attribute__((deprecated)) web_player_session_domain_t *web_player_session_domain_create(
    char *name,
    char *label,
    char *terms_policy,
    double cores,
    int individual,
    int totp_required
    ) {
    return web_player_session_domain_create_internal (
        name,
        label,
        terms_policy,
        cores,
        individual,
        totp_required
        );
}

void web_player_session_domain_free(web_player_session_domain_t *web_player_session_domain) {
    if(NULL == web_player_session_domain){
        return ;
    }
    if(web_player_session_domain->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "web_player_session_domain_free");
        return ;
    }
    listEntry_t *listEntry;
    if (web_player_session_domain->name) {
        free(web_player_session_domain->name);
        web_player_session_domain->name = NULL;
    }
    if (web_player_session_domain->label) {
        free(web_player_session_domain->label);
        web_player_session_domain->label = NULL;
    }
    if (web_player_session_domain->terms_policy) {
        free(web_player_session_domain->terms_policy);
        web_player_session_domain->terms_policy = NULL;
    }
    free(web_player_session_domain);
}

cJSON *web_player_session_domain_convertToJSON(web_player_session_domain_t *web_player_session_domain) {
    cJSON *item = cJSON_CreateObject();

    // web_player_session_domain->name
    if (!web_player_session_domain->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", web_player_session_domain->name) == NULL) {
    goto fail; //String
    }


    // web_player_session_domain->label
    if(web_player_session_domain->label) {
    if(cJSON_AddStringToObject(item, "label", web_player_session_domain->label) == NULL) {
    goto fail; //String
    }
    }


    // web_player_session_domain->terms_policy
    if(web_player_session_domain->terms_policy) {
    if(cJSON_AddStringToObject(item, "termsPolicy", web_player_session_domain->terms_policy) == NULL) {
    goto fail; //String
    }
    }


    // web_player_session_domain->cores
    if(web_player_session_domain->cores) {
    if(cJSON_AddNumberToObject(item, "cores", web_player_session_domain->cores) == NULL) {
    goto fail; //Numeric
    }
    }


    // web_player_session_domain->individual
    if(web_player_session_domain->individual) {
    if(cJSON_AddBoolToObject(item, "individual", web_player_session_domain->individual) == NULL) {
    goto fail; //Bool
    }
    }


    // web_player_session_domain->totp_required
    if(web_player_session_domain->totp_required) {
    if(cJSON_AddBoolToObject(item, "totpRequired", web_player_session_domain->totp_required) == NULL) {
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

web_player_session_domain_t *web_player_session_domain_parseFromJSON(cJSON *web_player_session_domainJSON){

    web_player_session_domain_t *web_player_session_domain_local_var = NULL;

    // web_player_session_domain->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(web_player_session_domainJSON, "name");
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

    // web_player_session_domain->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(web_player_session_domainJSON, "label");
    if (cJSON_IsNull(label)) {
        label = NULL;
    }
    if (label) { 
    if(!cJSON_IsString(label) && !cJSON_IsNull(label))
    {
    goto end; //String
    }
    }

    // web_player_session_domain->terms_policy
    cJSON *terms_policy = cJSON_GetObjectItemCaseSensitive(web_player_session_domainJSON, "termsPolicy");
    if (cJSON_IsNull(terms_policy)) {
        terms_policy = NULL;
    }
    if (terms_policy) { 
    if(!cJSON_IsString(terms_policy) && !cJSON_IsNull(terms_policy))
    {
    goto end; //String
    }
    }

    // web_player_session_domain->cores
    cJSON *cores = cJSON_GetObjectItemCaseSensitive(web_player_session_domainJSON, "cores");
    if (cJSON_IsNull(cores)) {
        cores = NULL;
    }
    if (cores) { 
    if(!cJSON_IsNumber(cores))
    {
    goto end; //Numeric
    }
    }

    // web_player_session_domain->individual
    cJSON *individual = cJSON_GetObjectItemCaseSensitive(web_player_session_domainJSON, "individual");
    if (cJSON_IsNull(individual)) {
        individual = NULL;
    }
    if (individual) { 
    if(!cJSON_IsBool(individual))
    {
    goto end; //Bool
    }
    }

    // web_player_session_domain->totp_required
    cJSON *totp_required = cJSON_GetObjectItemCaseSensitive(web_player_session_domainJSON, "totpRequired");
    if (cJSON_IsNull(totp_required)) {
        totp_required = NULL;
    }
    if (totp_required) { 
    if(!cJSON_IsBool(totp_required))
    {
    goto end; //Bool
    }
    }


    web_player_session_domain_local_var = web_player_session_domain_create_internal (
        strdup(name->valuestring),
        label && !cJSON_IsNull(label) ? strdup(label->valuestring) : NULL,
        terms_policy && !cJSON_IsNull(terms_policy) ? strdup(terms_policy->valuestring) : NULL,
        cores ? cores->valuedouble : 0,
        individual ? individual->valueint : 0,
        totp_required ? totp_required->valueint : 0
        );

    return web_player_session_domain_local_var;
end:
    return NULL;

}
