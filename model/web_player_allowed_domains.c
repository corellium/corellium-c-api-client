#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "web_player_allowed_domains.h"



static web_player_allowed_domains_t *web_player_allowed_domains_create_internal(
    list_t *allowed_domains
    ) {
    web_player_allowed_domains_t *web_player_allowed_domains_local_var = malloc(sizeof(web_player_allowed_domains_t));
    if (!web_player_allowed_domains_local_var) {
        return NULL;
    }
    web_player_allowed_domains_local_var->allowed_domains = allowed_domains;

    web_player_allowed_domains_local_var->_library_owned = 1;
    return web_player_allowed_domains_local_var;
}

__attribute__((deprecated)) web_player_allowed_domains_t *web_player_allowed_domains_create(
    list_t *allowed_domains
    ) {
    return web_player_allowed_domains_create_internal (
        allowed_domains
        );
}

void web_player_allowed_domains_free(web_player_allowed_domains_t *web_player_allowed_domains) {
    if(NULL == web_player_allowed_domains){
        return ;
    }
    if(web_player_allowed_domains->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "web_player_allowed_domains_free");
        return ;
    }
    listEntry_t *listEntry;
    if (web_player_allowed_domains->allowed_domains) {
        list_ForEach(listEntry, web_player_allowed_domains->allowed_domains) {
            free(listEntry->data);
        }
        list_freeList(web_player_allowed_domains->allowed_domains);
        web_player_allowed_domains->allowed_domains = NULL;
    }
    free(web_player_allowed_domains);
}

cJSON *web_player_allowed_domains_convertToJSON(web_player_allowed_domains_t *web_player_allowed_domains) {
    cJSON *item = cJSON_CreateObject();

    // web_player_allowed_domains->allowed_domains
    if (!web_player_allowed_domains->allowed_domains) {
        goto fail;
    }
    cJSON *allowed_domains = cJSON_AddArrayToObject(item, "allowedDomains");
    if(allowed_domains == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *allowed_domainsListEntry;
    list_ForEach(allowed_domainsListEntry, web_player_allowed_domains->allowed_domains) {
    if(cJSON_AddStringToObject(allowed_domains, "", allowed_domainsListEntry->data) == NULL)
    {
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

web_player_allowed_domains_t *web_player_allowed_domains_parseFromJSON(cJSON *web_player_allowed_domainsJSON){

    web_player_allowed_domains_t *web_player_allowed_domains_local_var = NULL;

    // define the local list for web_player_allowed_domains->allowed_domains
    list_t *allowed_domainsList = NULL;

    // web_player_allowed_domains->allowed_domains
    cJSON *allowed_domains = cJSON_GetObjectItemCaseSensitive(web_player_allowed_domainsJSON, "allowedDomains");
    if (cJSON_IsNull(allowed_domains)) {
        allowed_domains = NULL;
    }
    if (!allowed_domains) {
        goto end;
    }

    
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


    web_player_allowed_domains_local_var = web_player_allowed_domains_create_internal (
        allowed_domainsList
        );

    return web_player_allowed_domains_local_var;
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
