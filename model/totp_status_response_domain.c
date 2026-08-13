#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "totp_status_response_domain.h"



static totp_status_response_domain_t *totp_status_response_domain_create_internal(
    char *name,
    char *label
    ) {
    totp_status_response_domain_t *totp_status_response_domain_local_var = malloc(sizeof(totp_status_response_domain_t));
    if (!totp_status_response_domain_local_var) {
        return NULL;
    }
    totp_status_response_domain_local_var->name = name;
    totp_status_response_domain_local_var->label = label;

    totp_status_response_domain_local_var->_library_owned = 1;
    return totp_status_response_domain_local_var;
}

__attribute__((deprecated)) totp_status_response_domain_t *totp_status_response_domain_create(
    char *name,
    char *label
    ) {
    return totp_status_response_domain_create_internal (
        name,
        label
        );
}

void totp_status_response_domain_free(totp_status_response_domain_t *totp_status_response_domain) {
    if(NULL == totp_status_response_domain){
        return ;
    }
    if(totp_status_response_domain->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "totp_status_response_domain_free");
        return ;
    }
    listEntry_t *listEntry;
    if (totp_status_response_domain->name) {
        free(totp_status_response_domain->name);
        totp_status_response_domain->name = NULL;
    }
    if (totp_status_response_domain->label) {
        free(totp_status_response_domain->label);
        totp_status_response_domain->label = NULL;
    }
    free(totp_status_response_domain);
}

cJSON *totp_status_response_domain_convertToJSON(totp_status_response_domain_t *totp_status_response_domain) {
    cJSON *item = cJSON_CreateObject();

    // totp_status_response_domain->name
    if (!totp_status_response_domain->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", totp_status_response_domain->name) == NULL) {
    goto fail; //String
    }


    // totp_status_response_domain->label
    if(totp_status_response_domain->label) {
    if(cJSON_AddStringToObject(item, "label", totp_status_response_domain->label) == NULL) {
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

totp_status_response_domain_t *totp_status_response_domain_parseFromJSON(cJSON *totp_status_response_domainJSON){

    totp_status_response_domain_t *totp_status_response_domain_local_var = NULL;

    // totp_status_response_domain->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(totp_status_response_domainJSON, "name");
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

    // totp_status_response_domain->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(totp_status_response_domainJSON, "label");
    if (cJSON_IsNull(label)) {
        label = NULL;
    }
    if (label) { 
    if(!cJSON_IsString(label) && !cJSON_IsNull(label))
    {
    goto end; //String
    }
    }


    totp_status_response_domain_local_var = totp_status_response_domain_create_internal (
        strdup(name->valuestring),
        label && !cJSON_IsNull(label) ? strdup(label->valuestring) : NULL
        );

    return totp_status_response_domain_local_var;
end:
    return NULL;

}
