#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_instance_body.h"



static create_instance_body_t *create_instance_body_create_internal(
    char *shared_snapshot,
    char *shared_snapshot_password,
    char *name,
    char *key,
    char *flavor,
    char *project_id,
    char *os_version,
    char *os_build,
    list_t *patches,
    object_t *fw_package,
    char *original_firmware_package_url,
    int encrypt,
    char *wifi_mac,
    int wan_access,
    volume_options_t *volume,
    char *snapshot,
    instance_boot_options_t *boot_options,
    int sbs,
    list_t *charm_boot_args
    ) {
    create_instance_body_t *create_instance_body_local_var = malloc(sizeof(create_instance_body_t));
    if (!create_instance_body_local_var) {
        return NULL;
    }
    create_instance_body_local_var->shared_snapshot = shared_snapshot;
    create_instance_body_local_var->shared_snapshot_password = shared_snapshot_password;
    create_instance_body_local_var->name = name;
    create_instance_body_local_var->key = key;
    create_instance_body_local_var->flavor = flavor;
    create_instance_body_local_var->project_id = project_id;
    create_instance_body_local_var->os_version = os_version;
    create_instance_body_local_var->os_build = os_build;
    create_instance_body_local_var->patches = patches;
    create_instance_body_local_var->fw_package = fw_package;
    create_instance_body_local_var->original_firmware_package_url = original_firmware_package_url;
    create_instance_body_local_var->encrypt = encrypt;
    create_instance_body_local_var->wifi_mac = wifi_mac;
    create_instance_body_local_var->wan_access = wan_access;
    create_instance_body_local_var->volume = volume;
    create_instance_body_local_var->snapshot = snapshot;
    create_instance_body_local_var->boot_options = boot_options;
    create_instance_body_local_var->sbs = sbs;
    create_instance_body_local_var->charm_boot_args = charm_boot_args;

    create_instance_body_local_var->_library_owned = 1;
    return create_instance_body_local_var;
}

__attribute__((deprecated)) create_instance_body_t *create_instance_body_create(
    char *shared_snapshot,
    char *shared_snapshot_password,
    char *name,
    char *key,
    char *flavor,
    char *project_id,
    char *os_version,
    char *os_build,
    list_t *patches,
    object_t *fw_package,
    char *original_firmware_package_url,
    int encrypt,
    char *wifi_mac,
    int wan_access,
    volume_options_t *volume,
    char *snapshot,
    instance_boot_options_t *boot_options,
    int sbs,
    list_t *charm_boot_args
    ) {
    return create_instance_body_create_internal (
        shared_snapshot,
        shared_snapshot_password,
        name,
        key,
        flavor,
        project_id,
        os_version,
        os_build,
        patches,
        fw_package,
        original_firmware_package_url,
        encrypt,
        wifi_mac,
        wan_access,
        volume,
        snapshot,
        boot_options,
        sbs,
        charm_boot_args
        );
}

void create_instance_body_free(create_instance_body_t *create_instance_body) {
    if(NULL == create_instance_body){
        return ;
    }
    if(create_instance_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "create_instance_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (create_instance_body->shared_snapshot) {
        free(create_instance_body->shared_snapshot);
        create_instance_body->shared_snapshot = NULL;
    }
    if (create_instance_body->shared_snapshot_password) {
        free(create_instance_body->shared_snapshot_password);
        create_instance_body->shared_snapshot_password = NULL;
    }
    if (create_instance_body->name) {
        free(create_instance_body->name);
        create_instance_body->name = NULL;
    }
    if (create_instance_body->key) {
        free(create_instance_body->key);
        create_instance_body->key = NULL;
    }
    if (create_instance_body->flavor) {
        free(create_instance_body->flavor);
        create_instance_body->flavor = NULL;
    }
    if (create_instance_body->project_id) {
        free(create_instance_body->project_id);
        create_instance_body->project_id = NULL;
    }
    if (create_instance_body->os_version) {
        free(create_instance_body->os_version);
        create_instance_body->os_version = NULL;
    }
    if (create_instance_body->os_build) {
        free(create_instance_body->os_build);
        create_instance_body->os_build = NULL;
    }
    if (create_instance_body->patches) {
        list_ForEach(listEntry, create_instance_body->patches) {
            free(listEntry->data);
        }
        list_freeList(create_instance_body->patches);
        create_instance_body->patches = NULL;
    }
    if (create_instance_body->fw_package) {
        object_free(create_instance_body->fw_package);
        create_instance_body->fw_package = NULL;
    }
    if (create_instance_body->original_firmware_package_url) {
        free(create_instance_body->original_firmware_package_url);
        create_instance_body->original_firmware_package_url = NULL;
    }
    if (create_instance_body->wifi_mac) {
        free(create_instance_body->wifi_mac);
        create_instance_body->wifi_mac = NULL;
    }
    if (create_instance_body->volume) {
        volume_options_free(create_instance_body->volume);
        create_instance_body->volume = NULL;
    }
    if (create_instance_body->snapshot) {
        free(create_instance_body->snapshot);
        create_instance_body->snapshot = NULL;
    }
    if (create_instance_body->boot_options) {
        instance_boot_options_free(create_instance_body->boot_options);
        create_instance_body->boot_options = NULL;
    }
    if (create_instance_body->charm_boot_args) {
        list_ForEach(listEntry, create_instance_body->charm_boot_args) {
            object_free(listEntry->data);
        }
        list_freeList(create_instance_body->charm_boot_args);
        create_instance_body->charm_boot_args = NULL;
    }
    free(create_instance_body);
}

cJSON *create_instance_body_convertToJSON(create_instance_body_t *create_instance_body) {
    cJSON *item = cJSON_CreateObject();

    // create_instance_body->shared_snapshot
    if(create_instance_body->shared_snapshot) {
    if(cJSON_AddStringToObject(item, "sharedSnapshot", create_instance_body->shared_snapshot) == NULL) {
    goto fail; //String
    }
    }


    // create_instance_body->shared_snapshot_password
    if(create_instance_body->shared_snapshot_password) {
    if(cJSON_AddStringToObject(item, "sharedSnapshotPassword", create_instance_body->shared_snapshot_password) == NULL) {
    goto fail; //String
    }
    }


    // create_instance_body->name
    if(create_instance_body->name) {
    if(cJSON_AddStringToObject(item, "name", create_instance_body->name) == NULL) {
    goto fail; //String
    }
    }


    // create_instance_body->key
    if(create_instance_body->key) {
    if(cJSON_AddStringToObject(item, "key", create_instance_body->key) == NULL) {
    goto fail; //String
    }
    }


    // create_instance_body->flavor
    if (!create_instance_body->flavor) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "flavor", create_instance_body->flavor) == NULL) {
    goto fail; //String
    }


    // create_instance_body->project_id
    if (!create_instance_body->project_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "projectId", create_instance_body->project_id) == NULL) {
    goto fail; //String
    }


    // create_instance_body->os_version
    if (!create_instance_body->os_version) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "osVersion", create_instance_body->os_version) == NULL) {
    goto fail; //String
    }


    // create_instance_body->os_build
    if(create_instance_body->os_build) {
    if(cJSON_AddStringToObject(item, "osBuild", create_instance_body->os_build) == NULL) {
    goto fail; //String
    }
    }


    // create_instance_body->patches
    if(create_instance_body->patches) {
    cJSON *patches = cJSON_AddArrayToObject(item, "patches");
    if(patches == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *patchesListEntry;
    list_ForEach(patchesListEntry, create_instance_body->patches) {
    if(cJSON_AddStringToObject(patches, "", patchesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // create_instance_body->fw_package
    if(create_instance_body->fw_package) {
    cJSON *fw_package_object = object_convertToJSON(create_instance_body->fw_package);
    if(fw_package_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "fwPackage", fw_package_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // create_instance_body->original_firmware_package_url
    if(create_instance_body->original_firmware_package_url) {
    if(cJSON_AddStringToObject(item, "originalFirmwarePackageUrl", create_instance_body->original_firmware_package_url) == NULL) {
    goto fail; //String
    }
    }


    // create_instance_body->encrypt
    if(create_instance_body->encrypt) {
    if(cJSON_AddBoolToObject(item, "encrypt", create_instance_body->encrypt) == NULL) {
    goto fail; //Bool
    }
    }


    // create_instance_body->wifi_mac
    if(create_instance_body->wifi_mac) {
    if(cJSON_AddStringToObject(item, "wifiMac", create_instance_body->wifi_mac) == NULL) {
    goto fail; //String
    }
    }


    // create_instance_body->wan_access
    if(create_instance_body->wan_access) {
    if(cJSON_AddBoolToObject(item, "wanAccess", create_instance_body->wan_access) == NULL) {
    goto fail; //Bool
    }
    }


    // create_instance_body->volume
    if(create_instance_body->volume) {
    cJSON *volume_local_JSON = volume_options_convertToJSON(create_instance_body->volume);
    if(volume_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "volume", volume_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // create_instance_body->snapshot
    if(create_instance_body->snapshot) {
    if(cJSON_AddStringToObject(item, "snapshot", create_instance_body->snapshot) == NULL) {
    goto fail; //String
    }
    }


    // create_instance_body->boot_options
    if(create_instance_body->boot_options) {
    cJSON *boot_options_local_JSON = instance_boot_options_convertToJSON(create_instance_body->boot_options);
    if(boot_options_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "bootOptions", boot_options_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // create_instance_body->sbs
    if(create_instance_body->sbs) {
    if(cJSON_AddBoolToObject(item, "sbs", create_instance_body->sbs) == NULL) {
    goto fail; //Bool
    }
    }


    // create_instance_body->charm_boot_args
    if(create_instance_body->charm_boot_args) {
    cJSON *charm_boot_args = cJSON_AddArrayToObject(item, "charmBootArgs");
    if(charm_boot_args == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *charm_boot_argsListEntry;
    if (create_instance_body->charm_boot_args) {
    list_ForEach(charm_boot_argsListEntry, create_instance_body->charm_boot_args) {
    cJSON *itemLocal = object_convertToJSON(charm_boot_argsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(charm_boot_args, itemLocal);
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

create_instance_body_t *create_instance_body_parseFromJSON(cJSON *create_instance_bodyJSON){

    create_instance_body_t *create_instance_body_local_var = NULL;

    // define the local list for create_instance_body->patches
    list_t *patchesList = NULL;

    // define the local variable for create_instance_body->volume
    volume_options_t *volume_local_nonprim = NULL;

    // define the local variable for create_instance_body->boot_options
    instance_boot_options_t *boot_options_local_nonprim = NULL;

    // define the local list for create_instance_body->charm_boot_args
    list_t *charm_boot_argsList = NULL;

    // create_instance_body->shared_snapshot
    cJSON *shared_snapshot = cJSON_GetObjectItemCaseSensitive(create_instance_bodyJSON, "sharedSnapshot");
    if (cJSON_IsNull(shared_snapshot)) {
        shared_snapshot = NULL;
    }
    if (shared_snapshot) { 
    if(!cJSON_IsString(shared_snapshot) && !cJSON_IsNull(shared_snapshot))
    {
    goto end; //String
    }
    }

    // create_instance_body->shared_snapshot_password
    cJSON *shared_snapshot_password = cJSON_GetObjectItemCaseSensitive(create_instance_bodyJSON, "sharedSnapshotPassword");
    if (cJSON_IsNull(shared_snapshot_password)) {
        shared_snapshot_password = NULL;
    }
    if (shared_snapshot_password) { 
    if(!cJSON_IsString(shared_snapshot_password) && !cJSON_IsNull(shared_snapshot_password))
    {
    goto end; //String
    }
    }

    // create_instance_body->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(create_instance_bodyJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // create_instance_body->key
    cJSON *key = cJSON_GetObjectItemCaseSensitive(create_instance_bodyJSON, "key");
    if (cJSON_IsNull(key)) {
        key = NULL;
    }
    if (key) { 
    if(!cJSON_IsString(key) && !cJSON_IsNull(key))
    {
    goto end; //String
    }
    }

    // create_instance_body->flavor
    cJSON *flavor = cJSON_GetObjectItemCaseSensitive(create_instance_bodyJSON, "flavor");
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

    // create_instance_body->project_id
    cJSON *project_id = cJSON_GetObjectItemCaseSensitive(create_instance_bodyJSON, "projectId");
    if (cJSON_IsNull(project_id)) {
        project_id = NULL;
    }
    if (!project_id) {
        goto end;
    }

    
    if(!cJSON_IsString(project_id))
    {
    goto end; //String
    }

    // create_instance_body->os_version
    cJSON *os_version = cJSON_GetObjectItemCaseSensitive(create_instance_bodyJSON, "osVersion");
    if (cJSON_IsNull(os_version)) {
        os_version = NULL;
    }
    if (!os_version) {
        goto end;
    }

    
    if(!cJSON_IsString(os_version))
    {
    goto end; //String
    }

    // create_instance_body->os_build
    cJSON *os_build = cJSON_GetObjectItemCaseSensitive(create_instance_bodyJSON, "osBuild");
    if (cJSON_IsNull(os_build)) {
        os_build = NULL;
    }
    if (os_build) { 
    if(!cJSON_IsString(os_build) && !cJSON_IsNull(os_build))
    {
    goto end; //String
    }
    }

    // create_instance_body->patches
    cJSON *patches = cJSON_GetObjectItemCaseSensitive(create_instance_bodyJSON, "patches");
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

    // create_instance_body->fw_package
    cJSON *fw_package = cJSON_GetObjectItemCaseSensitive(create_instance_bodyJSON, "fwPackage");
    if (cJSON_IsNull(fw_package)) {
        fw_package = NULL;
    }
    object_t *fw_package_local_object = NULL;
    if (fw_package) { 
    fw_package_local_object = object_parseFromJSON(fw_package); //object
    }

    // create_instance_body->original_firmware_package_url
    cJSON *original_firmware_package_url = cJSON_GetObjectItemCaseSensitive(create_instance_bodyJSON, "originalFirmwarePackageUrl");
    if (cJSON_IsNull(original_firmware_package_url)) {
        original_firmware_package_url = NULL;
    }
    if (original_firmware_package_url) { 
    if(!cJSON_IsString(original_firmware_package_url) && !cJSON_IsNull(original_firmware_package_url))
    {
    goto end; //String
    }
    }

    // create_instance_body->encrypt
    cJSON *encrypt = cJSON_GetObjectItemCaseSensitive(create_instance_bodyJSON, "encrypt");
    if (cJSON_IsNull(encrypt)) {
        encrypt = NULL;
    }
    if (encrypt) { 
    if(!cJSON_IsBool(encrypt))
    {
    goto end; //Bool
    }
    }

    // create_instance_body->wifi_mac
    cJSON *wifi_mac = cJSON_GetObjectItemCaseSensitive(create_instance_bodyJSON, "wifiMac");
    if (cJSON_IsNull(wifi_mac)) {
        wifi_mac = NULL;
    }
    if (wifi_mac) { 
    if(!cJSON_IsString(wifi_mac) && !cJSON_IsNull(wifi_mac))
    {
    goto end; //String
    }
    }

    // create_instance_body->wan_access
    cJSON *wan_access = cJSON_GetObjectItemCaseSensitive(create_instance_bodyJSON, "wanAccess");
    if (cJSON_IsNull(wan_access)) {
        wan_access = NULL;
    }
    if (wan_access) { 
    if(!cJSON_IsBool(wan_access))
    {
    goto end; //Bool
    }
    }

    // create_instance_body->volume
    cJSON *volume = cJSON_GetObjectItemCaseSensitive(create_instance_bodyJSON, "volume");
    if (cJSON_IsNull(volume)) {
        volume = NULL;
    }
    if (volume) { 
    volume_local_nonprim = volume_options_parseFromJSON(volume); //nonprimitive
    }

    // create_instance_body->snapshot
    cJSON *snapshot = cJSON_GetObjectItemCaseSensitive(create_instance_bodyJSON, "snapshot");
    if (cJSON_IsNull(snapshot)) {
        snapshot = NULL;
    }
    if (snapshot) { 
    if(!cJSON_IsString(snapshot) && !cJSON_IsNull(snapshot))
    {
    goto end; //String
    }
    }

    // create_instance_body->boot_options
    cJSON *boot_options = cJSON_GetObjectItemCaseSensitive(create_instance_bodyJSON, "bootOptions");
    if (cJSON_IsNull(boot_options)) {
        boot_options = NULL;
    }
    if (boot_options) { 
    boot_options_local_nonprim = instance_boot_options_parseFromJSON(boot_options); //nonprimitive
    }

    // create_instance_body->sbs
    cJSON *sbs = cJSON_GetObjectItemCaseSensitive(create_instance_bodyJSON, "sbs");
    if (cJSON_IsNull(sbs)) {
        sbs = NULL;
    }
    if (sbs) { 
    if(!cJSON_IsBool(sbs))
    {
    goto end; //Bool
    }
    }

    // create_instance_body->charm_boot_args
    cJSON *charm_boot_args = cJSON_GetObjectItemCaseSensitive(create_instance_bodyJSON, "charmBootArgs");
    if (cJSON_IsNull(charm_boot_args)) {
        charm_boot_args = NULL;
    }
    if (charm_boot_args) { 
    cJSON *charm_boot_args_local_nonprimitive = NULL;
    if(!cJSON_IsArray(charm_boot_args)){
        goto end; //nonprimitive container
    }

    charm_boot_argsList = list_createList();

    cJSON_ArrayForEach(charm_boot_args_local_nonprimitive,charm_boot_args )
    {
        if(!cJSON_IsObject(charm_boot_args_local_nonprimitive)){
            goto end;
        }
        object_t *charm_boot_argsItem = object_parseFromJSON(charm_boot_args_local_nonprimitive);

        list_addElement(charm_boot_argsList, charm_boot_argsItem);
    }
    }


    create_instance_body_local_var = create_instance_body_create_internal (
        shared_snapshot && !cJSON_IsNull(shared_snapshot) ? strdup(shared_snapshot->valuestring) : NULL,
        shared_snapshot_password && !cJSON_IsNull(shared_snapshot_password) ? strdup(shared_snapshot_password->valuestring) : NULL,
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        key && !cJSON_IsNull(key) ? strdup(key->valuestring) : NULL,
        strdup(flavor->valuestring),
        strdup(project_id->valuestring),
        strdup(os_version->valuestring),
        os_build && !cJSON_IsNull(os_build) ? strdup(os_build->valuestring) : NULL,
        patches ? patchesList : NULL,
        fw_package ? fw_package_local_object : NULL,
        original_firmware_package_url && !cJSON_IsNull(original_firmware_package_url) ? strdup(original_firmware_package_url->valuestring) : NULL,
        encrypt ? encrypt->valueint : 0,
        wifi_mac && !cJSON_IsNull(wifi_mac) ? strdup(wifi_mac->valuestring) : NULL,
        wan_access ? wan_access->valueint : 0,
        volume ? volume_local_nonprim : NULL,
        snapshot && !cJSON_IsNull(snapshot) ? strdup(snapshot->valuestring) : NULL,
        boot_options ? boot_options_local_nonprim : NULL,
        sbs ? sbs->valueint : 0,
        charm_boot_args ? charm_boot_argsList : NULL
        );

    return create_instance_body_local_var;
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
    if (volume_local_nonprim) {
        volume_options_free(volume_local_nonprim);
        volume_local_nonprim = NULL;
    }
    if (boot_options_local_nonprim) {
        instance_boot_options_free(boot_options_local_nonprim);
        boot_options_local_nonprim = NULL;
    }
    if (charm_boot_argsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, charm_boot_argsList) {
            object_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(charm_boot_argsList);
        charm_boot_argsList = NULL;
    }
    return NULL;

}
