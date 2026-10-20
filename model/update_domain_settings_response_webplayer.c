#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "update_domain_settings_response_webplayer.h"



static update_domain_settings_response_webplayer_t *update_domain_settings_response_webplayer_create_internal(
    list_t *allowed_domains
    ) {
    update_domain_settings_response_webplayer_t *update_domain_settings_response_webplayer_local_var = malloc(sizeof(update_domain_settings_response_webplayer_t));
    if (!update_domain_settings_response_webplayer_local_var) {
        return NULL;
    }
    update_domain_settings_response_webplayer_local_var->allowed_domains = allowed_domains;

    update_domain_settings_response_webplayer_local_var->_library_owned = 1;
    return update_domain_settings_response_webplayer_local_var;
}

__attribute__((deprecated)) update_domain_settings_response_webplayer_t *update_domain_settings_response_webplayer_create(
    list_t *allowed_domains
    ) {
    return update_domain_settings_response_webplayer_create_internal (
        allowed_domains
        );
}

void update_domain_settings_response_webplayer_free(update_domain_settings_response_webplayer_t *update_domain_settings_response_webplayer) {
    if(NULL == update_domain_settings_response_webplayer){
        return ;
    }
    if(update_domain_settings_response_webplayer->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "update_domain_settings_response_webplayer_free");
        return ;
    }
    listEntry_t *listEntry;
    if (update_domain_settings_response_webplayer->allowed_domains) {
        list_ForEach(listEntry, update_domain_settings_response_webplayer->allowed_domains) {
            free(listEntry->data);
        }
        list_freeList(update_domain_settings_response_webplayer->allowed_domains);
        update_domain_settings_response_webplayer->allowed_domains = NULL;
    }
    free(update_domain_settings_response_webplayer);
}

cJSON *update_domain_settings_response_webplayer_convertToJSON(update_domain_settings_response_webplayer_t *update_domain_settings_response_webplayer) {
    cJSON *item = cJSON_CreateObject();

    // update_domain_settings_response_webplayer->allowed_domains
    if(update_domain_settings_response_webplayer->allowed_domains) {
    cJSON *allowed_domains = cJSON_AddArrayToObject(item, "allowedDomains");
    if(allowed_domains == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *allowed_domainsListEntry;
    list_ForEach(allowed_domainsListEntry, update_domain_settings_response_webplayer->allowed_domains) {
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

update_domain_settings_response_webplayer_t *update_domain_settings_response_webplayer_parseFromJSON(cJSON *update_domain_settings_response_webplayerJSON){

    update_domain_settings_response_webplayer_t *update_domain_settings_response_webplayer_local_var = NULL;

    // define the local list for update_domain_settings_response_webplayer->allowed_domains
    list_t *allowed_domainsList = NULL;

    // update_domain_settings_response_webplayer->allowed_domains
    cJSON *allowed_domains = cJSON_GetObjectItemCaseSensitive(update_domain_settings_response_webplayerJSON, "allowedDomains");
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


    update_domain_settings_response_webplayer_local_var = update_domain_settings_response_webplayer_create_internal (
        allowed_domains ? allowed_domainsList : NULL
        );

    return update_domain_settings_response_webplayer_local_var;
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
