#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "patch_instance_body.h"



static patch_instance_body_t *patch_instance_body_create_internal(
    char *name,
    patch_instance_body_boot_options_t *boot_options,
    list_t *proxy,
    list_t *strace_filter
    ) {
    patch_instance_body_t *patch_instance_body_local_var = malloc(sizeof(patch_instance_body_t));
    if (!patch_instance_body_local_var) {
        return NULL;
    }
    patch_instance_body_local_var->name = name;
    patch_instance_body_local_var->boot_options = boot_options;
    patch_instance_body_local_var->proxy = proxy;
    patch_instance_body_local_var->strace_filter = strace_filter;

    patch_instance_body_local_var->_library_owned = 1;
    return patch_instance_body_local_var;
}

__attribute__((deprecated)) patch_instance_body_t *patch_instance_body_create(
    char *name,
    patch_instance_body_boot_options_t *boot_options,
    list_t *proxy,
    list_t *strace_filter
    ) {
    return patch_instance_body_create_internal (
        name,
        boot_options,
        proxy,
        strace_filter
        );
}

void patch_instance_body_free(patch_instance_body_t *patch_instance_body) {
    if(NULL == patch_instance_body){
        return ;
    }
    if(patch_instance_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "patch_instance_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (patch_instance_body->name) {
        free(patch_instance_body->name);
        patch_instance_body->name = NULL;
    }
    if (patch_instance_body->boot_options) {
        patch_instance_body_boot_options_free(patch_instance_body->boot_options);
        patch_instance_body->boot_options = NULL;
    }
    if (patch_instance_body->proxy) {
        list_ForEach(listEntry, patch_instance_body->proxy) {
            patch_instance_body_proxy_inner_free(listEntry->data);
        }
        list_freeList(patch_instance_body->proxy);
        patch_instance_body->proxy = NULL;
    }
    if (patch_instance_body->strace_filter) {
        list_ForEach(listEntry, patch_instance_body->strace_filter) {
            patch_instance_body_strace_filter_inner_free(listEntry->data);
        }
        list_freeList(patch_instance_body->strace_filter);
        patch_instance_body->strace_filter = NULL;
    }
    free(patch_instance_body);
}

cJSON *patch_instance_body_convertToJSON(patch_instance_body_t *patch_instance_body) {
    cJSON *item = cJSON_CreateObject();

    // patch_instance_body->name
    if(patch_instance_body->name) {
    if(cJSON_AddStringToObject(item, "name", patch_instance_body->name) == NULL) {
    goto fail; //String
    }
    }


    // patch_instance_body->boot_options
    if(patch_instance_body->boot_options) {
    cJSON *boot_options_local_JSON = patch_instance_body_boot_options_convertToJSON(patch_instance_body->boot_options);
    if(boot_options_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "bootOptions", boot_options_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // patch_instance_body->proxy
    if(patch_instance_body->proxy) {
    cJSON *proxy = cJSON_AddArrayToObject(item, "proxy");
    if(proxy == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *proxyListEntry;
    if (patch_instance_body->proxy) {
    list_ForEach(proxyListEntry, patch_instance_body->proxy) {
    cJSON *itemLocal = patch_instance_body_proxy_inner_convertToJSON(proxyListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(proxy, itemLocal);
    }
    }
    }


    // patch_instance_body->strace_filter
    if(patch_instance_body->strace_filter) {
    cJSON *strace_filter = cJSON_AddArrayToObject(item, "straceFilter");
    if(strace_filter == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *strace_filterListEntry;
    if (patch_instance_body->strace_filter) {
    list_ForEach(strace_filterListEntry, patch_instance_body->strace_filter) {
    cJSON *itemLocal = patch_instance_body_strace_filter_inner_convertToJSON(strace_filterListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(strace_filter, itemLocal);
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

patch_instance_body_t *patch_instance_body_parseFromJSON(cJSON *patch_instance_bodyJSON){

    patch_instance_body_t *patch_instance_body_local_var = NULL;

    // define the local variable for patch_instance_body->boot_options
    patch_instance_body_boot_options_t *boot_options_local_nonprim = NULL;

    // define the local list for patch_instance_body->proxy
    list_t *proxyList = NULL;

    // define the local list for patch_instance_body->strace_filter
    list_t *strace_filterList = NULL;

    // patch_instance_body->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(patch_instance_bodyJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // patch_instance_body->boot_options
    cJSON *boot_options = cJSON_GetObjectItemCaseSensitive(patch_instance_bodyJSON, "bootOptions");
    if (cJSON_IsNull(boot_options)) {
        boot_options = NULL;
    }
    if (boot_options) { 
    boot_options_local_nonprim = patch_instance_body_boot_options_parseFromJSON(boot_options); //nonprimitive
    }

    // patch_instance_body->proxy
    cJSON *proxy = cJSON_GetObjectItemCaseSensitive(patch_instance_bodyJSON, "proxy");
    if (cJSON_IsNull(proxy)) {
        proxy = NULL;
    }
    if (proxy) { 
    cJSON *proxy_local_nonprimitive = NULL;
    if(!cJSON_IsArray(proxy)){
        goto end; //nonprimitive container
    }

    proxyList = list_createList();

    cJSON_ArrayForEach(proxy_local_nonprimitive,proxy )
    {
        if(!cJSON_IsObject(proxy_local_nonprimitive)){
            goto end;
        }
        patch_instance_body_proxy_inner_t *proxyItem = patch_instance_body_proxy_inner_parseFromJSON(proxy_local_nonprimitive);

        list_addElement(proxyList, proxyItem);
    }
    }

    // patch_instance_body->strace_filter
    cJSON *strace_filter = cJSON_GetObjectItemCaseSensitive(patch_instance_bodyJSON, "straceFilter");
    if (cJSON_IsNull(strace_filter)) {
        strace_filter = NULL;
    }
    if (strace_filter) { 
    cJSON *strace_filter_local_nonprimitive = NULL;
    if(!cJSON_IsArray(strace_filter)){
        goto end; //nonprimitive container
    }

    strace_filterList = list_createList();

    cJSON_ArrayForEach(strace_filter_local_nonprimitive,strace_filter )
    {
        if(!cJSON_IsObject(strace_filter_local_nonprimitive)){
            goto end;
        }
        patch_instance_body_strace_filter_inner_t *strace_filterItem = patch_instance_body_strace_filter_inner_parseFromJSON(strace_filter_local_nonprimitive);

        list_addElement(strace_filterList, strace_filterItem);
    }
    }


    patch_instance_body_local_var = patch_instance_body_create_internal (
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        boot_options ? boot_options_local_nonprim : NULL,
        proxy ? proxyList : NULL,
        strace_filter ? strace_filterList : NULL
        );

    return patch_instance_body_local_var;
end:
    if (boot_options_local_nonprim) {
        patch_instance_body_boot_options_free(boot_options_local_nonprim);
        boot_options_local_nonprim = NULL;
    }
    if (proxyList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, proxyList) {
            patch_instance_body_proxy_inner_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(proxyList);
        proxyList = NULL;
    }
    if (strace_filterList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, strace_filterList) {
            patch_instance_body_strace_filter_inner_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(strace_filterList);
        strace_filterList = NULL;
    }
    return NULL;

}
