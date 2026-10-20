#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "instance_create_options.h"



static instance_create_options_t *instance_create_options_create_internal(
    char *shared_snapshot,
    char *shared_snapshot_password,
    char *name,
    char *key,
    char *flavor,
    char *project,
    char *os,
    char *osbuild,
    list_t *patches,
    char *fwpackage,
    char *orig_fw_package_url,
    int encrypt,
    char *wifi_mac,
    int wan_access
    ) {
    instance_create_options_t *instance_create_options_local_var = malloc(sizeof(instance_create_options_t));
    if (!instance_create_options_local_var) {
        return NULL;
    }
    instance_create_options_local_var->shared_snapshot = shared_snapshot;
    instance_create_options_local_var->shared_snapshot_password = shared_snapshot_password;
    instance_create_options_local_var->name = name;
    instance_create_options_local_var->key = key;
    instance_create_options_local_var->flavor = flavor;
    instance_create_options_local_var->project = project;
    instance_create_options_local_var->os = os;
    instance_create_options_local_var->osbuild = osbuild;
    instance_create_options_local_var->patches = patches;
    instance_create_options_local_var->fwpackage = fwpackage;
    instance_create_options_local_var->orig_fw_package_url = orig_fw_package_url;
    instance_create_options_local_var->encrypt = encrypt;
    instance_create_options_local_var->wifi_mac = wifi_mac;
    instance_create_options_local_var->wan_access = wan_access;

    instance_create_options_local_var->_library_owned = 1;
    return instance_create_options_local_var;
}

__attribute__((deprecated)) instance_create_options_t *instance_create_options_create(
    char *shared_snapshot,
    char *shared_snapshot_password,
    char *name,
    char *key,
    char *flavor,
    char *project,
    char *os,
    char *osbuild,
    list_t *patches,
    char *fwpackage,
    char *orig_fw_package_url,
    int encrypt,
    char *wifi_mac,
    int wan_access
    ) {
    return instance_create_options_create_internal (
        shared_snapshot,
        shared_snapshot_password,
        name,
        key,
        flavor,
        project,
        os,
        osbuild,
        patches,
        fwpackage,
        orig_fw_package_url,
        encrypt,
        wifi_mac,
        wan_access
        );
}

void instance_create_options_free(instance_create_options_t *instance_create_options) {
    if(NULL == instance_create_options){
        return ;
    }
    if(instance_create_options->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "instance_create_options_free");
        return ;
    }
    listEntry_t *listEntry;
    if (instance_create_options->shared_snapshot) {
        free(instance_create_options->shared_snapshot);
        instance_create_options->shared_snapshot = NULL;
    }
    if (instance_create_options->shared_snapshot_password) {
        free(instance_create_options->shared_snapshot_password);
        instance_create_options->shared_snapshot_password = NULL;
    }
    if (instance_create_options->name) {
        free(instance_create_options->name);
        instance_create_options->name = NULL;
    }
    if (instance_create_options->key) {
        free(instance_create_options->key);
        instance_create_options->key = NULL;
    }
    if (instance_create_options->flavor) {
        free(instance_create_options->flavor);
        instance_create_options->flavor = NULL;
    }
    if (instance_create_options->project) {
        free(instance_create_options->project);
        instance_create_options->project = NULL;
    }
    if (instance_create_options->os) {
        free(instance_create_options->os);
        instance_create_options->os = NULL;
    }
    if (instance_create_options->osbuild) {
        free(instance_create_options->osbuild);
        instance_create_options->osbuild = NULL;
    }
    if (instance_create_options->patches) {
        list_ForEach(listEntry, instance_create_options->patches) {
            free(listEntry->data);
        }
        list_freeList(instance_create_options->patches);
        instance_create_options->patches = NULL;
    }
    if (instance_create_options->fwpackage) {
        free(instance_create_options->fwpackage);
        instance_create_options->fwpackage = NULL;
    }
    if (instance_create_options->orig_fw_package_url) {
        free(instance_create_options->orig_fw_package_url);
        instance_create_options->orig_fw_package_url = NULL;
    }
    if (instance_create_options->wifi_mac) {
        free(instance_create_options->wifi_mac);
        instance_create_options->wifi_mac = NULL;
    }
    free(instance_create_options);
}

cJSON *instance_create_options_convertToJSON(instance_create_options_t *instance_create_options) {
    cJSON *item = cJSON_CreateObject();

    // instance_create_options->shared_snapshot
    if(instance_create_options->shared_snapshot) {
    if(cJSON_AddStringToObject(item, "sharedSnapshot", instance_create_options->shared_snapshot) == NULL) {
    goto fail; //String
    }
    }


    // instance_create_options->shared_snapshot_password
    if(instance_create_options->shared_snapshot_password) {
    if(cJSON_AddStringToObject(item, "sharedSnapshotPassword", instance_create_options->shared_snapshot_password) == NULL) {
    goto fail; //String
    }
    }


    // instance_create_options->name
    if(instance_create_options->name) {
    if(cJSON_AddStringToObject(item, "name", instance_create_options->name) == NULL) {
    goto fail; //String
    }
    }


    // instance_create_options->key
    if(instance_create_options->key) {
    if(cJSON_AddStringToObject(item, "key", instance_create_options->key) == NULL) {
    goto fail; //String
    }
    }


    // instance_create_options->flavor
    if (!instance_create_options->flavor) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "flavor", instance_create_options->flavor) == NULL) {
    goto fail; //String
    }


    // instance_create_options->project
    if (!instance_create_options->project) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "project", instance_create_options->project) == NULL) {
    goto fail; //String
    }


    // instance_create_options->os
    if (!instance_create_options->os) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "os", instance_create_options->os) == NULL) {
    goto fail; //String
    }


    // instance_create_options->osbuild
    if(instance_create_options->osbuild) {
    if(cJSON_AddStringToObject(item, "osbuild", instance_create_options->osbuild) == NULL) {
    goto fail; //String
    }
    }


    // instance_create_options->patches
    if(instance_create_options->patches) {
    cJSON *patches = cJSON_AddArrayToObject(item, "patches");
    if(patches == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *patchesListEntry;
    list_ForEach(patchesListEntry, instance_create_options->patches) {
    if(cJSON_AddStringToObject(patches, "", patchesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // instance_create_options->fwpackage
    if(instance_create_options->fwpackage) {
    if(cJSON_AddStringToObject(item, "fwpackage", instance_create_options->fwpackage) == NULL) {
    goto fail; //String
    }
    }


    // instance_create_options->orig_fw_package_url
    if(instance_create_options->orig_fw_package_url) {
    if(cJSON_AddStringToObject(item, "origFwPackageUrl", instance_create_options->orig_fw_package_url) == NULL) {
    goto fail; //String
    }
    }


    // instance_create_options->encrypt
    if(instance_create_options->encrypt) {
    if(cJSON_AddBoolToObject(item, "encrypt", instance_create_options->encrypt) == NULL) {
    goto fail; //Bool
    }
    }


    // instance_create_options->wifi_mac
    if(instance_create_options->wifi_mac) {
    if(cJSON_AddStringToObject(item, "wifiMac", instance_create_options->wifi_mac) == NULL) {
    goto fail; //String
    }
    }


    // instance_create_options->wan_access
    if(instance_create_options->wan_access) {
    if(cJSON_AddBoolToObject(item, "wanAccess", instance_create_options->wan_access) == NULL) {
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

instance_create_options_t *instance_create_options_parseFromJSON(cJSON *instance_create_optionsJSON){

    instance_create_options_t *instance_create_options_local_var = NULL;

    // define the local list for instance_create_options->patches
    list_t *patchesList = NULL;

    // instance_create_options->shared_snapshot
    cJSON *shared_snapshot = cJSON_GetObjectItemCaseSensitive(instance_create_optionsJSON, "sharedSnapshot");
    if (cJSON_IsNull(shared_snapshot)) {
        shared_snapshot = NULL;
    }
    if (shared_snapshot) { 
    if(!cJSON_IsString(shared_snapshot) && !cJSON_IsNull(shared_snapshot))
    {
    goto end; //String
    }
    }

    // instance_create_options->shared_snapshot_password
    cJSON *shared_snapshot_password = cJSON_GetObjectItemCaseSensitive(instance_create_optionsJSON, "sharedSnapshotPassword");
    if (cJSON_IsNull(shared_snapshot_password)) {
        shared_snapshot_password = NULL;
    }
    if (shared_snapshot_password) { 
    if(!cJSON_IsString(shared_snapshot_password) && !cJSON_IsNull(shared_snapshot_password))
    {
    goto end; //String
    }
    }

    // instance_create_options->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(instance_create_optionsJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // instance_create_options->key
    cJSON *key = cJSON_GetObjectItemCaseSensitive(instance_create_optionsJSON, "key");
    if (cJSON_IsNull(key)) {
        key = NULL;
    }
    if (key) { 
    if(!cJSON_IsString(key) && !cJSON_IsNull(key))
    {
    goto end; //String
    }
    }

    // instance_create_options->flavor
    cJSON *flavor = cJSON_GetObjectItemCaseSensitive(instance_create_optionsJSON, "flavor");
    if (cJSON_IsNull(flavor)) {
        flavor = NULL;
    }
    if (!flavor) {
        goto end;
    }

    
    if(!cJSON_IsString(flavor))
    {
    goto end; //String
    }

    // instance_create_options->project
    cJSON *project = cJSON_GetObjectItemCaseSensitive(instance_create_optionsJSON, "project");
    if (cJSON_IsNull(project)) {
        project = NULL;
    }
    if (!project) {
        goto end;
    }

    
    if(!cJSON_IsString(project))
    {
    goto end; //String
    }

    // instance_create_options->os
    cJSON *os = cJSON_GetObjectItemCaseSensitive(instance_create_optionsJSON, "os");
    if (cJSON_IsNull(os)) {
        os = NULL;
    }
    if (!os) {
        goto end;
    }

    
    if(!cJSON_IsString(os))
    {
    goto end; //String
    }

    // instance_create_options->osbuild
    cJSON *osbuild = cJSON_GetObjectItemCaseSensitive(instance_create_optionsJSON, "osbuild");
    if (cJSON_IsNull(osbuild)) {
        osbuild = NULL;
    }
    if (osbuild) { 
    if(!cJSON_IsString(osbuild) && !cJSON_IsNull(osbuild))
    {
    goto end; //String
    }
    }

    // instance_create_options->patches
    cJSON *patches = cJSON_GetObjectItemCaseSensitive(instance_create_optionsJSON, "patches");
    if (cJSON_IsNull(patches)) {
        patches = NULL;
    }
    if (patches) { 
    cJSON *patches_local = NULL;
    if(!cJSON_IsArray(patches)) {
        goto end;//primitive container
    }
    patchesList = list_createList();

    cJSON_ArrayForEach(patches_local, patches)
    {
        if(!cJSON_IsString(patches_local))
        {
            goto end;
        }
        list_addElement(patchesList , strdup(patches_local->valuestring));
    }
    }

    // instance_create_options->fwpackage
    cJSON *fwpackage = cJSON_GetObjectItemCaseSensitive(instance_create_optionsJSON, "fwpackage");
    if (cJSON_IsNull(fwpackage)) {
        fwpackage = NULL;
    }
    if (fwpackage) { 
    if(!cJSON_IsString(fwpackage) && !cJSON_IsNull(fwpackage))
    {
    goto end; //String
    }
    }

    // instance_create_options->orig_fw_package_url
    cJSON *orig_fw_package_url = cJSON_GetObjectItemCaseSensitive(instance_create_optionsJSON, "origFwPackageUrl");
    if (cJSON_IsNull(orig_fw_package_url)) {
        orig_fw_package_url = NULL;
    }
    if (orig_fw_package_url) { 
    if(!cJSON_IsString(orig_fw_package_url) && !cJSON_IsNull(orig_fw_package_url))
    {
    goto end; //String
    }
    }

    // instance_create_options->encrypt
    cJSON *encrypt = cJSON_GetObjectItemCaseSensitive(instance_create_optionsJSON, "encrypt");
    if (cJSON_IsNull(encrypt)) {
        encrypt = NULL;
    }
    if (encrypt) { 
    if(!cJSON_IsBool(encrypt))
    {
    goto end; //Bool
    }
    }

    // instance_create_options->wifi_mac
    cJSON *wifi_mac = cJSON_GetObjectItemCaseSensitive(instance_create_optionsJSON, "wifiMac");
    if (cJSON_IsNull(wifi_mac)) {
        wifi_mac = NULL;
    }
    if (wifi_mac) { 
    if(!cJSON_IsString(wifi_mac) && !cJSON_IsNull(wifi_mac))
    {
    goto end; //String
    }
    }

    // instance_create_options->wan_access
    cJSON *wan_access = cJSON_GetObjectItemCaseSensitive(instance_create_optionsJSON, "wanAccess");
    if (cJSON_IsNull(wan_access)) {
        wan_access = NULL;
    }
    if (wan_access) { 
    if(!cJSON_IsBool(wan_access))
    {
    goto end; //Bool
    }
    }


    instance_create_options_local_var = instance_create_options_create_internal (
        shared_snapshot && !cJSON_IsNull(shared_snapshot) ? strdup(shared_snapshot->valuestring) : NULL,
        shared_snapshot_password && !cJSON_IsNull(shared_snapshot_password) ? strdup(shared_snapshot_password->valuestring) : NULL,
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        key && !cJSON_IsNull(key) ? strdup(key->valuestring) : NULL,
        strdup(flavor->valuestring),
        strdup(project->valuestring),
        strdup(os->valuestring),
        osbuild && !cJSON_IsNull(osbuild) ? strdup(osbuild->valuestring) : NULL,
        patches ? patchesList : NULL,
        fwpackage && !cJSON_IsNull(fwpackage) ? strdup(fwpackage->valuestring) : NULL,
        orig_fw_package_url && !cJSON_IsNull(orig_fw_package_url) ? strdup(orig_fw_package_url->valuestring) : NULL,
        encrypt ? encrypt->valueint : 0,
        wifi_mac && !cJSON_IsNull(wifi_mac) ? strdup(wifi_mac->valuestring) : NULL,
        wan_access ? wan_access->valueint : 0
        );

    return instance_create_options_local_var;
end:
    if (patchesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, patchesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(patchesList);
        patchesList = NULL;
    }
    return NULL;

}
