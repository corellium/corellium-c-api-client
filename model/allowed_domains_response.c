#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "allowed_domains_response.h"



static allowed_domains_response_t *allowed_domains_response_create_internal(
    list_t *allowed_domains
    ) {
    allowed_domains_response_t *allowed_domains_response_local_var = malloc(sizeof(allowed_domains_response_t));
    if (!allowed_domains_response_local_var) {
        return NULL;
    }
    allowed_domains_response_local_var->allowed_domains = allowed_domains;

    allowed_domains_response_local_var->_library_owned = 1;
    return allowed_domains_response_local_var;
}

__attribute__((deprecated)) allowed_domains_response_t *allowed_domains_response_create(
    list_t *allowed_domains
    ) {
    return allowed_domains_response_create_internal (
        allowed_domains
        );
}

void allowed_domains_response_free(allowed_domains_response_t *allowed_domains_response) {
    if(NULL == allowed_domains_response){
        return ;
    }
    if(allowed_domains_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "allowed_domains_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (allowed_domains_response->allowed_domains) {
        list_ForEach(listEntry, allowed_domains_response->allowed_domains) {
            free(listEntry->data);
        }
        list_freeList(allowed_domains_response->allowed_domains);
        allowed_domains_response->allowed_domains = NULL;
    }
    free(allowed_domains_response);
}

cJSON *allowed_domains_response_convertToJSON(allowed_domains_response_t *allowed_domains_response) {
    cJSON *item = cJSON_CreateObject();

    // allowed_domains_response->allowed_domains
    if(allowed_domains_response->allowed_domains) {
    cJSON *allowed_domains = cJSON_AddArrayToObject(item, "allowedDomains");
    if(allowed_domains == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *allowed_domainsListEntry;
    list_ForEach(allowed_domainsListEntry, allowed_domains_response->allowed_domains) {
    if(cJSON_AddStringToObject(allowed_domains, "", allowed_domainsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

allowed_domains_response_t *allowed_domains_response_parseFromJSON(cJSON *allowed_domains_responseJSON){

    allowed_domains_response_t *allowed_domains_response_local_var = NULL;

    // define the local list for allowed_domains_response->allowed_domains
    list_t *allowed_domainsList = NULL;

    // allowed_domains_response->allowed_domains
    cJSON *allowed_domains = cJSON_GetObjectItemCaseSensitive(allowed_domains_responseJSON, "allowedDomains");
    if (cJSON_IsNull(allowed_domains)) {
        allowed_domains = NULL;
    }
    if (allowed_domains) { 
    cJSON *allowed_domains_local = NULL;
    if(!cJSON_IsArray(allowed_domains)) {
        goto end;//primitive container
    }
    allowed_domainsList = list_createList();

    cJSON_ArrayForEach(allowed_domains_local, allowed_domains)
    {
        if(!cJSON_IsString(allowed_domains_local))
        {
            goto end;
        }
        list_addElement(allowed_domainsList , strdup(allowed_domains_local->valuestring));
    }
    }


    allowed_domains_response_local_var = allowed_domains_response_create_internal (
        allowed_domains ? allowed_domainsList : NULL
        );

    return allowed_domains_response_local_var;
end:
    if (allowed_domainsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, allowed_domainsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(allowed_domainsList);
        allowed_domainsList = NULL;
    }
    return NULL;

}
