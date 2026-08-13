#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "patch_domain_body_webplayer.h"



static patch_domain_body_webplayer_t *patch_domain_body_webplayer_create_internal(
    list_t *allowed_domains
    ) {
    patch_domain_body_webplayer_t *patch_domain_body_webplayer_local_var = malloc(sizeof(patch_domain_body_webplayer_t));
    if (!patch_domain_body_webplayer_local_var) {
        return NULL;
    }
    patch_domain_body_webplayer_local_var->allowed_domains = allowed_domains;

    patch_domain_body_webplayer_local_var->_library_owned = 1;
    return patch_domain_body_webplayer_local_var;
}

__attribute__((deprecated)) patch_domain_body_webplayer_t *patch_domain_body_webplayer_create(
    list_t *allowed_domains
    ) {
    return patch_domain_body_webplayer_create_internal (
        allowed_domains
        );
}

void patch_domain_body_webplayer_free(patch_domain_body_webplayer_t *patch_domain_body_webplayer) {
    if(NULL == patch_domain_body_webplayer){
        return ;
    }
    if(patch_domain_body_webplayer->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "patch_domain_body_webplayer_free");
        return ;
    }
    listEntry_t *listEntry;
    if (patch_domain_body_webplayer->allowed_domains) {
        list_ForEach(listEntry, patch_domain_body_webplayer->allowed_domains) {
            free(listEntry->data);
        }
        list_freeList(patch_domain_body_webplayer->allowed_domains);
        patch_domain_body_webplayer->allowed_domains = NULL;
    }
    free(patch_domain_body_webplayer);
}

cJSON *patch_domain_body_webplayer_convertToJSON(patch_domain_body_webplayer_t *patch_domain_body_webplayer) {
    cJSON *item = cJSON_CreateObject();

    // patch_domain_body_webplayer->allowed_domains
    if(patch_domain_body_webplayer->allowed_domains) {
    cJSON *allowed_domains = cJSON_AddArrayToObject(item, "allowedDomains");
    if(allowed_domains == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *allowed_domainsListEntry;
    list_ForEach(allowed_domainsListEntry, patch_domain_body_webplayer->allowed_domains) {
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

patch_domain_body_webplayer_t *patch_domain_body_webplayer_parseFromJSON(cJSON *patch_domain_body_webplayerJSON){

    patch_domain_body_webplayer_t *patch_domain_body_webplayer_local_var = NULL;

    // define the local list for patch_domain_body_webplayer->allowed_domains
    list_t *allowed_domainsList = NULL;

    // patch_domain_body_webplayer->allowed_domains
    cJSON *allowed_domains = cJSON_GetObjectItemCaseSensitive(patch_domain_body_webplayerJSON, "allowedDomains");
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


    patch_domain_body_webplayer_local_var = patch_domain_body_webplayer_create_internal (
        allowed_domains ? allowed_domainsList : NULL
        );

    return patch_domain_body_webplayer_local_var;
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
