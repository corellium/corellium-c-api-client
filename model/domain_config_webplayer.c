#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "domain_config_webplayer.h"



static domain_config_webplayer_t *domain_config_webplayer_create_internal(
    int enabled,
    list_t *allowed_domains
    ) {
    domain_config_webplayer_t *domain_config_webplayer_local_var = malloc(sizeof(domain_config_webplayer_t));
    if (!domain_config_webplayer_local_var) {
        return NULL;
    }
    domain_config_webplayer_local_var->enabled = enabled;
    domain_config_webplayer_local_var->allowed_domains = allowed_domains;

    domain_config_webplayer_local_var->_library_owned = 1;
    return domain_config_webplayer_local_var;
}

__attribute__((deprecated)) domain_config_webplayer_t *domain_config_webplayer_create(
    int enabled,
    list_t *allowed_domains
    ) {
    return domain_config_webplayer_create_internal (
        enabled,
        allowed_domains
        );
}

void domain_config_webplayer_free(domain_config_webplayer_t *domain_config_webplayer) {
    if(NULL == domain_config_webplayer){
        return ;
    }
    if(domain_config_webplayer->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "domain_config_webplayer_free");
        return ;
    }
    listEntry_t *listEntry;
    if (domain_config_webplayer->allowed_domains) {
        list_ForEach(listEntry, domain_config_webplayer->allowed_domains) {
            free(listEntry->data);
        }
        list_freeList(domain_config_webplayer->allowed_domains);
        domain_config_webplayer->allowed_domains = NULL;
    }
    free(domain_config_webplayer);
}

cJSON *domain_config_webplayer_convertToJSON(domain_config_webplayer_t *domain_config_webplayer) {
    cJSON *item = cJSON_CreateObject();

    // domain_config_webplayer->enabled
    if (!domain_config_webplayer->enabled) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "enabled", domain_config_webplayer->enabled) == NULL) {
    goto fail; //Bool
    }


    // domain_config_webplayer->allowed_domains
    if(domain_config_webplayer->allowed_domains) {
    cJSON *allowed_domains = cJSON_AddArrayToObject(item, "allowedDomains");
    if(allowed_domains == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *allowed_domainsListEntry;
    list_ForEach(allowed_domainsListEntry, domain_config_webplayer->allowed_domains) {
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

domain_config_webplayer_t *domain_config_webplayer_parseFromJSON(cJSON *domain_config_webplayerJSON){

    domain_config_webplayer_t *domain_config_webplayer_local_var = NULL;

    // define the local list for domain_config_webplayer->allowed_domains
    list_t *allowed_domainsList = NULL;

    // domain_config_webplayer->enabled
    cJSON *enabled = cJSON_GetObjectItemCaseSensitive(domain_config_webplayerJSON, "enabled");
    if (cJSON_IsNull(enabled)) {
        enabled = NULL;
    }
    if (!enabled) {
        goto end;
    }

    
    if(!cJSON_IsBool(enabled))
    {
    goto end; //Bool
    }

    // domain_config_webplayer->allowed_domains
    cJSON *allowed_domains = cJSON_GetObjectItemCaseSensitive(domain_config_webplayerJSON, "allowedDomains");
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


    domain_config_webplayer_local_var = domain_config_webplayer_create_internal (
        enabled->valueint,
        allowed_domains ? allowed_domainsList : NULL
        );

    return domain_config_webplayer_local_var;
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
