#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "login_result_domain_webplayer.h"



static login_result_domain_webplayer_t *login_result_domain_webplayer_create_internal(
    int enabled,
    list_t *allowed_domains
    ) {
    login_result_domain_webplayer_t *login_result_domain_webplayer_local_var = malloc(sizeof(login_result_domain_webplayer_t));
    if (!login_result_domain_webplayer_local_var) {
        return NULL;
    }
    login_result_domain_webplayer_local_var->enabled = enabled;
    login_result_domain_webplayer_local_var->allowed_domains = allowed_domains;

    login_result_domain_webplayer_local_var->_library_owned = 1;
    return login_result_domain_webplayer_local_var;
}

__attribute__((deprecated)) login_result_domain_webplayer_t *login_result_domain_webplayer_create(
    int enabled,
    list_t *allowed_domains
    ) {
    return login_result_domain_webplayer_create_internal (
        enabled,
        allowed_domains
        );
}

void login_result_domain_webplayer_free(login_result_domain_webplayer_t *login_result_domain_webplayer) {
    if(NULL == login_result_domain_webplayer){
        return ;
    }
    if(login_result_domain_webplayer->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "login_result_domain_webplayer_free");
        return ;
    }
    listEntry_t *listEntry;
    if (login_result_domain_webplayer->allowed_domains) {
        list_ForEach(listEntry, login_result_domain_webplayer->allowed_domains) {
            free(listEntry->data);
        }
        list_freeList(login_result_domain_webplayer->allowed_domains);
        login_result_domain_webplayer->allowed_domains = NULL;
    }
    free(login_result_domain_webplayer);
}

cJSON *login_result_domain_webplayer_convertToJSON(login_result_domain_webplayer_t *login_result_domain_webplayer) {
    cJSON *item = cJSON_CreateObject();

    // login_result_domain_webplayer->enabled
    if(login_result_domain_webplayer->enabled) {
    if(cJSON_AddBoolToObject(item, "enabled", login_result_domain_webplayer->enabled) == NULL) {
    goto fail; //Bool
    }
    }


    // login_result_domain_webplayer->allowed_domains
    if(login_result_domain_webplayer->allowed_domains) {
    cJSON *allowed_domains = cJSON_AddArrayToObject(item, "allowedDomains");
    if(allowed_domains == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *allowed_domainsListEntry;
    list_ForEach(allowed_domainsListEntry, login_result_domain_webplayer->allowed_domains) {
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

login_result_domain_webplayer_t *login_result_domain_webplayer_parseFromJSON(cJSON *login_result_domain_webplayerJSON){

    login_result_domain_webplayer_t *login_result_domain_webplayer_local_var = NULL;

    // define the local list for login_result_domain_webplayer->allowed_domains
    list_t *allowed_domainsList = NULL;

    // login_result_domain_webplayer->enabled
    cJSON *enabled = cJSON_GetObjectItemCaseSensitive(login_result_domain_webplayerJSON, "enabled");
    if (cJSON_IsNull(enabled)) {
        enabled = NULL;
    }
    if (enabled) { 
    if(!cJSON_IsBool(enabled))
    {
    goto end; //Bool
    }
    }

    // login_result_domain_webplayer->allowed_domains
    cJSON *allowed_domains = cJSON_GetObjectItemCaseSensitive(login_result_domain_webplayerJSON, "allowedDomains");
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


    login_result_domain_webplayer_local_var = login_result_domain_webplayer_create_internal (
        enabled ? enabled->valueint : 0,
        allowed_domains ? allowed_domainsList : NULL
        );

    return login_result_domain_webplayer_local_var;
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
