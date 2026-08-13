#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "patch_instance_options.h"


char* patch_instance_options_state_ToString(corellium_api_patch_instance_options_STATE_e state) {
    char* stateArray[] =  { "NULL", "on", "off", "paused", "deleting" };
    return stateArray[state];
}

corellium_api_patch_instance_options_STATE_e patch_instance_options_state_FromString(char* state){
    int stringToReturn = 0;
    char *stateArray[] =  { "NULL", "on", "off", "paused", "deleting" };
    size_t sizeofArray = sizeof(stateArray) / sizeof(stateArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(state, stateArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static patch_instance_options_t *patch_instance_options_create_internal(
    char *name,
    corellium_api_patch_instance_options_STATE_e state,
    instance_boot_options_v1_t *boot_options,
    list_t *proxy
    ) {
    patch_instance_options_t *patch_instance_options_local_var = malloc(sizeof(patch_instance_options_t));
    if (!patch_instance_options_local_var) {
        return NULL;
    }
    patch_instance_options_local_var->name = name;
    patch_instance_options_local_var->state = state;
    patch_instance_options_local_var->boot_options = boot_options;
    patch_instance_options_local_var->proxy = proxy;

    patch_instance_options_local_var->_library_owned = 1;
    return patch_instance_options_local_var;
}

__attribute__((deprecated)) patch_instance_options_t *patch_instance_options_create(
    char *name,
    corellium_api_patch_instance_options_STATE_e state,
    instance_boot_options_v1_t *boot_options,
    list_t *proxy
    ) {
    return patch_instance_options_create_internal (
        name,
        state,
        boot_options,
        proxy
        );
}

void patch_instance_options_free(patch_instance_options_t *patch_instance_options) {
    if(NULL == patch_instance_options){
        return ;
    }
    if(patch_instance_options->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "patch_instance_options_free");
        return ;
    }
    listEntry_t *listEntry;
    if (patch_instance_options->name) {
        free(patch_instance_options->name);
        patch_instance_options->name = NULL;
    }
    if (patch_instance_options->boot_options) {
        instance_boot_options_v1_free(patch_instance_options->boot_options);
        patch_instance_options->boot_options = NULL;
    }
    if (patch_instance_options->proxy) {
        list_ForEach(listEntry, patch_instance_options->proxy) {
            proxy_config_free(listEntry->data);
        }
        list_freeList(patch_instance_options->proxy);
        patch_instance_options->proxy = NULL;
    }
    free(patch_instance_options);
}

cJSON *patch_instance_options_convertToJSON(patch_instance_options_t *patch_instance_options) {
    cJSON *item = cJSON_CreateObject();

    // patch_instance_options->name
    if(patch_instance_options->name) {
    if(cJSON_AddStringToObject(item, "name", patch_instance_options->name) == NULL) {
    goto fail; //String
    }
    }


    // patch_instance_options->state
    if(patch_instance_options->state != corellium_api_patch_instance_options_STATE_NULL) {
    if(cJSON_AddStringToObject(item, "state", patch_instance_options_state_ToString(patch_instance_options->state)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // patch_instance_options->boot_options
    if(patch_instance_options->boot_options) {
    cJSON *boot_options_local_JSON = instance_boot_options_v1_convertToJSON(patch_instance_options->boot_options);
    if(boot_options_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "bootOptions", boot_options_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // patch_instance_options->proxy
    if(patch_instance_options->proxy) {
    cJSON *proxy = cJSON_AddArrayToObject(item, "proxy");
    if(proxy == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *proxyListEntry;
    if (patch_instance_options->proxy) {
    list_ForEach(proxyListEntry, patch_instance_options->proxy) {
    cJSON *itemLocal = proxy_config_convertToJSON(proxyListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(proxy, itemLocal);
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

patch_instance_options_t *patch_instance_options_parseFromJSON(cJSON *patch_instance_optionsJSON){

    patch_instance_options_t *patch_instance_options_local_var = NULL;

    // define the local variable for patch_instance_options->boot_options
    instance_boot_options_v1_t *boot_options_local_nonprim = NULL;

    // define the local list for patch_instance_options->proxy
    list_t *proxyList = NULL;

    // patch_instance_options->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(patch_instance_optionsJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // patch_instance_options->state
    cJSON *state = cJSON_GetObjectItemCaseSensitive(patch_instance_optionsJSON, "state");
    if (cJSON_IsNull(state)) {
        state = NULL;
    }
    corellium_api_patch_instance_options_STATE_e stateVariable;
    if (state) { 
    if(!cJSON_IsString(state))
    {
    goto end; //Enum
    }
    stateVariable = patch_instance_options_state_FromString(state->valuestring);
    }

    // patch_instance_options->boot_options
    cJSON *boot_options = cJSON_GetObjectItemCaseSensitive(patch_instance_optionsJSON, "bootOptions");
    if (cJSON_IsNull(boot_options)) {
        boot_options = NULL;
    }
    if (boot_options) { 
    boot_options_local_nonprim = instance_boot_options_v1_parseFromJSON(boot_options); //nonprimitive
    }

    // patch_instance_options->proxy
    cJSON *proxy = cJSON_GetObjectItemCaseSensitive(patch_instance_optionsJSON, "proxy");
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
        proxy_config_t *proxyItem = proxy_config_parseFromJSON(proxy_local_nonprimitive);

        list_addElement(proxyList, proxyItem);
    }
    }


    patch_instance_options_local_var = patch_instance_options_create_internal (
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        state ? stateVariable : corellium_api_patch_instance_options_STATE_NULL,
        boot_options ? boot_options_local_nonprim : NULL,
        proxy ? proxyList : NULL
        );

    return patch_instance_options_local_var;
end:
    if (boot_options_local_nonprim) {
        instance_boot_options_v1_free(boot_options_local_nonprim);
        boot_options_local_nonprim = NULL;
    }
    if (proxyList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, proxyList) {
            proxy_config_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(proxyList);
        proxyList = NULL;
    }
    return NULL;

}
