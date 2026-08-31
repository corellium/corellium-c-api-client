#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cluster_snapshot_metadata_boot_options.h"



static cluster_snapshot_metadata_boot_options_t *cluster_snapshot_metadata_boot_options_create_internal(
    char *boot_args,
    char *restore_boot_args,
    char *udid,
    char *ecid,
    char *random_seed,
    int pac,
    int aprr,
    double cores,
    double ram,
    list_t *additional_tags,
    instance_boot_options_kernel_t *kernel,
    instance_boot_options_pongo_t *pongo,
    char *serial,
    int no_snapshot_mount,
    char *kernel_slide,
    list_t *cd_hashes,
    char *imei,
    char *imsi,
    char *ssid0,
    char *ssid1,
    char *wifi_mac,
    char *model_id,
    char *manufacturer_id,
    char *kernel_patches,
    int stop_on_fault,
    char *boot_addr,
    int tzen,
    char *authorized_keys,
    list_t *v_mmio,
    instance_boot_options_fvp_t *fvp
    ) {
    cluster_snapshot_metadata_boot_options_t *cluster_snapshot_metadata_boot_options_local_var = malloc(sizeof(cluster_snapshot_metadata_boot_options_t));
    if (!cluster_snapshot_metadata_boot_options_local_var) {
        return NULL;
    }
    cluster_snapshot_metadata_boot_options_local_var->boot_args = boot_args;
    cluster_snapshot_metadata_boot_options_local_var->restore_boot_args = restore_boot_args;
    cluster_snapshot_metadata_boot_options_local_var->udid = udid;
    cluster_snapshot_metadata_boot_options_local_var->ecid = ecid;
    cluster_snapshot_metadata_boot_options_local_var->random_seed = random_seed;
    cluster_snapshot_metadata_boot_options_local_var->pac = pac;
    cluster_snapshot_metadata_boot_options_local_var->aprr = aprr;
    cluster_snapshot_metadata_boot_options_local_var->cores = cores;
    cluster_snapshot_metadata_boot_options_local_var->ram = ram;
    cluster_snapshot_metadata_boot_options_local_var->additional_tags = additional_tags;
    cluster_snapshot_metadata_boot_options_local_var->kernel = kernel;
    cluster_snapshot_metadata_boot_options_local_var->pongo = pongo;
    cluster_snapshot_metadata_boot_options_local_var->serial = serial;
    cluster_snapshot_metadata_boot_options_local_var->no_snapshot_mount = no_snapshot_mount;
    cluster_snapshot_metadata_boot_options_local_var->kernel_slide = kernel_slide;
    cluster_snapshot_metadata_boot_options_local_var->cd_hashes = cd_hashes;
    cluster_snapshot_metadata_boot_options_local_var->imei = imei;
    cluster_snapshot_metadata_boot_options_local_var->imsi = imsi;
    cluster_snapshot_metadata_boot_options_local_var->ssid0 = ssid0;
    cluster_snapshot_metadata_boot_options_local_var->ssid1 = ssid1;
    cluster_snapshot_metadata_boot_options_local_var->wifi_mac = wifi_mac;
    cluster_snapshot_metadata_boot_options_local_var->model_id = model_id;
    cluster_snapshot_metadata_boot_options_local_var->manufacturer_id = manufacturer_id;
    cluster_snapshot_metadata_boot_options_local_var->kernel_patches = kernel_patches;
    cluster_snapshot_metadata_boot_options_local_var->stop_on_fault = stop_on_fault;
    cluster_snapshot_metadata_boot_options_local_var->boot_addr = boot_addr;
    cluster_snapshot_metadata_boot_options_local_var->tzen = tzen;
    cluster_snapshot_metadata_boot_options_local_var->authorized_keys = authorized_keys;
    cluster_snapshot_metadata_boot_options_local_var->v_mmio = v_mmio;
    cluster_snapshot_metadata_boot_options_local_var->fvp = fvp;

    cluster_snapshot_metadata_boot_options_local_var->_library_owned = 1;
    return cluster_snapshot_metadata_boot_options_local_var;
}

__attribute__((deprecated)) cluster_snapshot_metadata_boot_options_t *cluster_snapshot_metadata_boot_options_create(
    char *boot_args,
    char *restore_boot_args,
    char *udid,
    char *ecid,
    char *random_seed,
    int pac,
    int aprr,
    double cores,
    double ram,
    list_t *additional_tags,
    instance_boot_options_kernel_t *kernel,
    instance_boot_options_pongo_t *pongo,
    char *serial,
    int no_snapshot_mount,
    char *kernel_slide,
    list_t *cd_hashes,
    char *imei,
    char *imsi,
    char *ssid0,
    char *ssid1,
    char *wifi_mac,
    char *model_id,
    char *manufacturer_id,
    char *kernel_patches,
    int stop_on_fault,
    char *boot_addr,
    int tzen,
    char *authorized_keys,
    list_t *v_mmio,
    instance_boot_options_fvp_t *fvp
    ) {
    return cluster_snapshot_metadata_boot_options_create_internal (
        boot_args,
        restore_boot_args,
        udid,
        ecid,
        random_seed,
        pac,
        aprr,
        cores,
        ram,
        additional_tags,
        kernel,
        pongo,
        serial,
        no_snapshot_mount,
        kernel_slide,
        cd_hashes,
        imei,
        imsi,
        ssid0,
        ssid1,
        wifi_mac,
        model_id,
        manufacturer_id,
        kernel_patches,
        stop_on_fault,
        boot_addr,
        tzen,
        authorized_keys,
        v_mmio,
        fvp
        );
}

void cluster_snapshot_metadata_boot_options_free(cluster_snapshot_metadata_boot_options_t *cluster_snapshot_metadata_boot_options) {
    if(NULL == cluster_snapshot_metadata_boot_options){
        return ;
    }
    if(cluster_snapshot_metadata_boot_options->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cluster_snapshot_metadata_boot_options_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cluster_snapshot_metadata_boot_options->boot_args) {
        free(cluster_snapshot_metadata_boot_options->boot_args);
        cluster_snapshot_metadata_boot_options->boot_args = NULL;
    }
    if (cluster_snapshot_metadata_boot_options->restore_boot_args) {
        free(cluster_snapshot_metadata_boot_options->restore_boot_args);
        cluster_snapshot_metadata_boot_options->restore_boot_args = NULL;
    }
    if (cluster_snapshot_metadata_boot_options->udid) {
        free(cluster_snapshot_metadata_boot_options->udid);
        cluster_snapshot_metadata_boot_options->udid = NULL;
    }
    if (cluster_snapshot_metadata_boot_options->ecid) {
        free(cluster_snapshot_metadata_boot_options->ecid);
        cluster_snapshot_metadata_boot_options->ecid = NULL;
    }
    if (cluster_snapshot_metadata_boot_options->random_seed) {
        free(cluster_snapshot_metadata_boot_options->random_seed);
        cluster_snapshot_metadata_boot_options->random_seed = NULL;
    }
    if (cluster_snapshot_metadata_boot_options->additional_tags) {
        list_ForEach(listEntry, cluster_snapshot_metadata_boot_options->additional_tags) {
            free(listEntry->data);
        }
        list_freeList(cluster_snapshot_metadata_boot_options->additional_tags);
        cluster_snapshot_metadata_boot_options->additional_tags = NULL;
    }
    if (cluster_snapshot_metadata_boot_options->kernel) {
        instance_boot_options_kernel_free(cluster_snapshot_metadata_boot_options->kernel);
        cluster_snapshot_metadata_boot_options->kernel = NULL;
    }
    if (cluster_snapshot_metadata_boot_options->pongo) {
        instance_boot_options_pongo_free(cluster_snapshot_metadata_boot_options->pongo);
        cluster_snapshot_metadata_boot_options->pongo = NULL;
    }
    if (cluster_snapshot_metadata_boot_options->serial) {
        free(cluster_snapshot_metadata_boot_options->serial);
        cluster_snapshot_metadata_boot_options->serial = NULL;
    }
    if (cluster_snapshot_metadata_boot_options->kernel_slide) {
        free(cluster_snapshot_metadata_boot_options->kernel_slide);
        cluster_snapshot_metadata_boot_options->kernel_slide = NULL;
    }
    if (cluster_snapshot_metadata_boot_options->cd_hashes) {
        list_ForEach(listEntry, cluster_snapshot_metadata_boot_options->cd_hashes) {
            free(listEntry->data);
        }
        list_freeList(cluster_snapshot_metadata_boot_options->cd_hashes);
        cluster_snapshot_metadata_boot_options->cd_hashes = NULL;
    }
    if (cluster_snapshot_metadata_boot_options->imei) {
        free(cluster_snapshot_metadata_boot_options->imei);
        cluster_snapshot_metadata_boot_options->imei = NULL;
    }
    if (cluster_snapshot_metadata_boot_options->imsi) {
        free(cluster_snapshot_metadata_boot_options->imsi);
        cluster_snapshot_metadata_boot_options->imsi = NULL;
    }
    if (cluster_snapshot_metadata_boot_options->ssid0) {
        free(cluster_snapshot_metadata_boot_options->ssid0);
        cluster_snapshot_metadata_boot_options->ssid0 = NULL;
    }
    if (cluster_snapshot_metadata_boot_options->ssid1) {
        free(cluster_snapshot_metadata_boot_options->ssid1);
        cluster_snapshot_metadata_boot_options->ssid1 = NULL;
    }
    if (cluster_snapshot_metadata_boot_options->wifi_mac) {
        free(cluster_snapshot_metadata_boot_options->wifi_mac);
        cluster_snapshot_metadata_boot_options->wifi_mac = NULL;
    }
    if (cluster_snapshot_metadata_boot_options->model_id) {
        free(cluster_snapshot_metadata_boot_options->model_id);
        cluster_snapshot_metadata_boot_options->model_id = NULL;
    }
    if (cluster_snapshot_metadata_boot_options->manufacturer_id) {
        free(cluster_snapshot_metadata_boot_options->manufacturer_id);
        cluster_snapshot_metadata_boot_options->manufacturer_id = NULL;
    }
    if (cluster_snapshot_metadata_boot_options->kernel_patches) {
        free(cluster_snapshot_metadata_boot_options->kernel_patches);
        cluster_snapshot_metadata_boot_options->kernel_patches = NULL;
    }
    if (cluster_snapshot_metadata_boot_options->boot_addr) {
        free(cluster_snapshot_metadata_boot_options->boot_addr);
        cluster_snapshot_metadata_boot_options->boot_addr = NULL;
    }
    if (cluster_snapshot_metadata_boot_options->authorized_keys) {
        free(cluster_snapshot_metadata_boot_options->authorized_keys);
        cluster_snapshot_metadata_boot_options->authorized_keys = NULL;
    }
    if (cluster_snapshot_metadata_boot_options->v_mmio) {
        list_ForEach(listEntry, cluster_snapshot_metadata_boot_options->v_mmio) {
            instance_boot_options_v_mmio_inner_free(listEntry->data);
        }
        list_freeList(cluster_snapshot_metadata_boot_options->v_mmio);
        cluster_snapshot_metadata_boot_options->v_mmio = NULL;
    }
    if (cluster_snapshot_metadata_boot_options->fvp) {
        instance_boot_options_fvp_free(cluster_snapshot_metadata_boot_options->fvp);
        cluster_snapshot_metadata_boot_options->fvp = NULL;
    }
    free(cluster_snapshot_metadata_boot_options);
}

cJSON *cluster_snapshot_metadata_boot_options_convertToJSON(cluster_snapshot_metadata_boot_options_t *cluster_snapshot_metadata_boot_options) {
    cJSON *item = cJSON_CreateObject();

    // cluster_snapshot_metadata_boot_options->boot_args
    if(cluster_snapshot_metadata_boot_options->boot_args) {
    if(cJSON_AddStringToObject(item, "bootArgs", cluster_snapshot_metadata_boot_options->boot_args) == NULL) {
    goto fail; //String
    }
    }


    // cluster_snapshot_metadata_boot_options->restore_boot_args
    if(cluster_snapshot_metadata_boot_options->restore_boot_args) {
    if(cJSON_AddStringToObject(item, "restoreBootArgs", cluster_snapshot_metadata_boot_options->restore_boot_args) == NULL) {
    goto fail; //String
    }
    }


    // cluster_snapshot_metadata_boot_options->udid
    if(cluster_snapshot_metadata_boot_options->udid) {
    if(cJSON_AddStringToObject(item, "udid", cluster_snapshot_metadata_boot_options->udid) == NULL) {
    goto fail; //String
    }
    }


    // cluster_snapshot_metadata_boot_options->ecid
    if(cluster_snapshot_metadata_boot_options->ecid) {
    if(cJSON_AddStringToObject(item, "ecid", cluster_snapshot_metadata_boot_options->ecid) == NULL) {
    goto fail; //String
    }
    }


    // cluster_snapshot_metadata_boot_options->random_seed
    if(cluster_snapshot_metadata_boot_options->random_seed) {
    if(cJSON_AddStringToObject(item, "randomSeed", cluster_snapshot_metadata_boot_options->random_seed) == NULL) {
    goto fail; //String
    }
    }


    // cluster_snapshot_metadata_boot_options->pac
    if(cluster_snapshot_metadata_boot_options->pac) {
    if(cJSON_AddBoolToObject(item, "pac", cluster_snapshot_metadata_boot_options->pac) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_snapshot_metadata_boot_options->aprr
    if(cluster_snapshot_metadata_boot_options->aprr) {
    if(cJSON_AddBoolToObject(item, "aprr", cluster_snapshot_metadata_boot_options->aprr) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_snapshot_metadata_boot_options->cores
    if(cluster_snapshot_metadata_boot_options->cores) {
    if(cJSON_AddNumberToObject(item, "cores", cluster_snapshot_metadata_boot_options->cores) == NULL) {
    goto fail; //Numeric
    }
    }


    // cluster_snapshot_metadata_boot_options->ram
    if(cluster_snapshot_metadata_boot_options->ram) {
    if(cJSON_AddNumberToObject(item, "ram", cluster_snapshot_metadata_boot_options->ram) == NULL) {
    goto fail; //Numeric
    }
    }


    // cluster_snapshot_metadata_boot_options->additional_tags
    if(cluster_snapshot_metadata_boot_options->additional_tags) {
    cJSON *additional_tags = cJSON_AddArrayToObject(item, "additionalTags");
    if(additional_tags == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *additional_tagsListEntry;
    list_ForEach(additional_tagsListEntry, cluster_snapshot_metadata_boot_options->additional_tags) {
    if(cJSON_AddStringToObject(additional_tags, "", additional_tagsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // cluster_snapshot_metadata_boot_options->kernel
    if(cluster_snapshot_metadata_boot_options->kernel) {
    cJSON *kernel_local_JSON = instance_boot_options_kernel_convertToJSON(cluster_snapshot_metadata_boot_options->kernel);
    if(kernel_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "kernel", kernel_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // cluster_snapshot_metadata_boot_options->pongo
    if(cluster_snapshot_metadata_boot_options->pongo) {
    cJSON *pongo_local_JSON = instance_boot_options_pongo_convertToJSON(cluster_snapshot_metadata_boot_options->pongo);
    if(pongo_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "pongo", pongo_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // cluster_snapshot_metadata_boot_options->serial
    if(cluster_snapshot_metadata_boot_options->serial) {
    if(cJSON_AddStringToObject(item, "serial", cluster_snapshot_metadata_boot_options->serial) == NULL) {
    goto fail; //String
    }
    }


    // cluster_snapshot_metadata_boot_options->no_snapshot_mount
    if(cluster_snapshot_metadata_boot_options->no_snapshot_mount) {
    if(cJSON_AddBoolToObject(item, "noSnapshotMount", cluster_snapshot_metadata_boot_options->no_snapshot_mount) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_snapshot_metadata_boot_options->kernel_slide
    if(cluster_snapshot_metadata_boot_options->kernel_slide) {
    if(cJSON_AddStringToObject(item, "kernelSlide", cluster_snapshot_metadata_boot_options->kernel_slide) == NULL) {
    goto fail; //String
    }
    }


    // cluster_snapshot_metadata_boot_options->cd_hashes
    if(cluster_snapshot_metadata_boot_options->cd_hashes) {
    cJSON *cd_hashes = cJSON_AddArrayToObject(item, "cdHashes");
    if(cd_hashes == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *cd_hashesListEntry;
    list_ForEach(cd_hashesListEntry, cluster_snapshot_metadata_boot_options->cd_hashes) {
    if(cJSON_AddStringToObject(cd_hashes, "", cd_hashesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // cluster_snapshot_metadata_boot_options->imei
    if(cluster_snapshot_metadata_boot_options->imei) {
    if(cJSON_AddStringToObject(item, "imei", cluster_snapshot_metadata_boot_options->imei) == NULL) {
    goto fail; //String
    }
    }


    // cluster_snapshot_metadata_boot_options->imsi
    if(cluster_snapshot_metadata_boot_options->imsi) {
    if(cJSON_AddStringToObject(item, "imsi", cluster_snapshot_metadata_boot_options->imsi) == NULL) {
    goto fail; //String
    }
    }


    // cluster_snapshot_metadata_boot_options->ssid0
    if(cluster_snapshot_metadata_boot_options->ssid0) {
    if(cJSON_AddStringToObject(item, "ssid0", cluster_snapshot_metadata_boot_options->ssid0) == NULL) {
    goto fail; //String
    }
    }


    // cluster_snapshot_metadata_boot_options->ssid1
    if(cluster_snapshot_metadata_boot_options->ssid1) {
    if(cJSON_AddStringToObject(item, "ssid1", cluster_snapshot_metadata_boot_options->ssid1) == NULL) {
    goto fail; //String
    }
    }


    // cluster_snapshot_metadata_boot_options->wifi_mac
    if(cluster_snapshot_metadata_boot_options->wifi_mac) {
    if(cJSON_AddStringToObject(item, "wifiMac", cluster_snapshot_metadata_boot_options->wifi_mac) == NULL) {
    goto fail; //String
    }
    }


    // cluster_snapshot_metadata_boot_options->model_id
    if(cluster_snapshot_metadata_boot_options->model_id) {
    if(cJSON_AddStringToObject(item, "modelId", cluster_snapshot_metadata_boot_options->model_id) == NULL) {
    goto fail; //String
    }
    }


    // cluster_snapshot_metadata_boot_options->manufacturer_id
    if(cluster_snapshot_metadata_boot_options->manufacturer_id) {
    if(cJSON_AddStringToObject(item, "manufacturerId", cluster_snapshot_metadata_boot_options->manufacturer_id) == NULL) {
    goto fail; //String
    }
    }


    // cluster_snapshot_metadata_boot_options->kernel_patches
    if(cluster_snapshot_metadata_boot_options->kernel_patches) {
    if(cJSON_AddStringToObject(item, "kernelPatches", cluster_snapshot_metadata_boot_options->kernel_patches) == NULL) {
    goto fail; //String
    }
    }


    // cluster_snapshot_metadata_boot_options->stop_on_fault
    if(cluster_snapshot_metadata_boot_options->stop_on_fault) {
    if(cJSON_AddBoolToObject(item, "stopOnFault", cluster_snapshot_metadata_boot_options->stop_on_fault) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_snapshot_metadata_boot_options->boot_addr
    if(cluster_snapshot_metadata_boot_options->boot_addr) {
    if(cJSON_AddStringToObject(item, "bootAddr", cluster_snapshot_metadata_boot_options->boot_addr) == NULL) {
    goto fail; //String
    }
    }


    // cluster_snapshot_metadata_boot_options->tzen
    if(cluster_snapshot_metadata_boot_options->tzen) {
    if(cJSON_AddBoolToObject(item, "tzen", cluster_snapshot_metadata_boot_options->tzen) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_snapshot_metadata_boot_options->authorized_keys
    if(cluster_snapshot_metadata_boot_options->authorized_keys) {
    if(cJSON_AddStringToObject(item, "authorizedKeys", cluster_snapshot_metadata_boot_options->authorized_keys) == NULL) {
    goto fail; //String
    }
    }


    // cluster_snapshot_metadata_boot_options->v_mmio
    if(cluster_snapshot_metadata_boot_options->v_mmio) {
    cJSON *v_mmio = cJSON_AddArrayToObject(item, "vMMIO");
    if(v_mmio == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *v_mmioListEntry;
    if (cluster_snapshot_metadata_boot_options->v_mmio) {
    list_ForEach(v_mmioListEntry, cluster_snapshot_metadata_boot_options->v_mmio) {
    cJSON *itemLocal = instance_boot_options_v_mmio_inner_convertToJSON(v_mmioListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(v_mmio, itemLocal);
    }
    }
    }


    // cluster_snapshot_metadata_boot_options->fvp
    if(cluster_snapshot_metadata_boot_options->fvp) {
    cJSON *fvp_local_JSON = instance_boot_options_fvp_convertToJSON(cluster_snapshot_metadata_boot_options->fvp);
    if(fvp_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "fvp", fvp_local_JSON);
    if(item->child == NULL) {
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

cluster_snapshot_metadata_boot_options_t *cluster_snapshot_metadata_boot_options_parseFromJSON(cJSON *cluster_snapshot_metadata_boot_optionsJSON){

    cluster_snapshot_metadata_boot_options_t *cluster_snapshot_metadata_boot_options_local_var = NULL;

    // define the local list for cluster_snapshot_metadata_boot_options->additional_tags
    list_t *additional_tagsList = NULL;

    // define the local variable for cluster_snapshot_metadata_boot_options->kernel
    instance_boot_options_kernel_t *kernel_local_nonprim = NULL;

    // define the local variable for cluster_snapshot_metadata_boot_options->pongo
    instance_boot_options_pongo_t *pongo_local_nonprim = NULL;

    // define the local list for cluster_snapshot_metadata_boot_options->cd_hashes
    list_t *cd_hashesList = NULL;

    // define the local list for cluster_snapshot_metadata_boot_options->v_mmio
    list_t *v_mmioList = NULL;

    // define the local variable for cluster_snapshot_metadata_boot_options->fvp
    instance_boot_options_fvp_t *fvp_local_nonprim = NULL;

    // cluster_snapshot_metadata_boot_options->boot_args
    cJSON *boot_args = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_metadata_boot_optionsJSON, "bootArgs");
    if (cJSON_IsNull(boot_args)) {
        boot_args = NULL;
    }
    if (boot_args) { 
    if(!cJSON_IsString(boot_args) && !cJSON_IsNull(boot_args))
    {
    goto end; //String
    }
    }

    // cluster_snapshot_metadata_boot_options->restore_boot_args
    cJSON *restore_boot_args = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_metadata_boot_optionsJSON, "restoreBootArgs");
    if (cJSON_IsNull(restore_boot_args)) {
        restore_boot_args = NULL;
    }
    if (restore_boot_args) { 
    if(!cJSON_IsString(restore_boot_args) && !cJSON_IsNull(restore_boot_args))
    {
    goto end; //String
    }
    }

    // cluster_snapshot_metadata_boot_options->udid
    cJSON *udid = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_metadata_boot_optionsJSON, "udid");
    if (cJSON_IsNull(udid)) {
        udid = NULL;
    }
    if (udid) { 
    if(!cJSON_IsString(udid) && !cJSON_IsNull(udid))
    {
    goto end; //String
    }
    }

    // cluster_snapshot_metadata_boot_options->ecid
    cJSON *ecid = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_metadata_boot_optionsJSON, "ecid");
    if (cJSON_IsNull(ecid)) {
        ecid = NULL;
    }
    if (ecid) { 
    if(!cJSON_IsString(ecid) && !cJSON_IsNull(ecid))
    {
    goto end; //String
    }
    }

    // cluster_snapshot_metadata_boot_options->random_seed
    cJSON *random_seed = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_metadata_boot_optionsJSON, "randomSeed");
    if (cJSON_IsNull(random_seed)) {
        random_seed = NULL;
    }
    if (random_seed) { 
    if(!cJSON_IsString(random_seed) && !cJSON_IsNull(random_seed))
    {
    goto end; //String
    }
    }

    // cluster_snapshot_metadata_boot_options->pac
    cJSON *pac = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_metadata_boot_optionsJSON, "pac");
    if (cJSON_IsNull(pac)) {
        pac = NULL;
    }
    if (pac) { 
    if(!cJSON_IsBool(pac))
    {
    goto end; //Bool
    }
    }

    // cluster_snapshot_metadata_boot_options->aprr
    cJSON *aprr = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_metadata_boot_optionsJSON, "aprr");
    if (cJSON_IsNull(aprr)) {
        aprr = NULL;
    }
    if (aprr) { 
    if(!cJSON_IsBool(aprr))
    {
    goto end; //Bool
    }
    }

    // cluster_snapshot_metadata_boot_options->cores
    cJSON *cores = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_metadata_boot_optionsJSON, "cores");
    if (cJSON_IsNull(cores)) {
        cores = NULL;
    }
    if (cores) { 
    if(!cJSON_IsNumber(cores))
    {
    goto end; //Numeric
    }
    }

    // cluster_snapshot_metadata_boot_options->ram
    cJSON *ram = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_metadata_boot_optionsJSON, "ram");
    if (cJSON_IsNull(ram)) {
        ram = NULL;
    }
    if (ram) { 
    if(!cJSON_IsNumber(ram))
    {
    goto end; //Numeric
    }
    }

    // cluster_snapshot_metadata_boot_options->additional_tags
    cJSON *additional_tags = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_metadata_boot_optionsJSON, "additionalTags");
    if (cJSON_IsNull(additional_tags)) {
        additional_tags = NULL;
    }
    if (additional_tags) { 
    cJSON *additional_tags_local = NULL;
    if(!cJSON_IsArray(additional_tags)) {
        goto end;//primitive container
    }
    additional_tagsList = list_createList();

    cJSON_ArrayForEach(additional_tags_local, additional_tags)
    {
        if(!cJSON_IsString(additional_tags_local))
        {
            goto end;
        }
        list_addElement(additional_tagsList , strdup(additional_tags_local->valuestring));
    }
    }

    // cluster_snapshot_metadata_boot_options->kernel
    cJSON *kernel = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_metadata_boot_optionsJSON, "kernel");
    if (cJSON_IsNull(kernel)) {
        kernel = NULL;
    }
    if (kernel) { 
    kernel_local_nonprim = instance_boot_options_kernel_parseFromJSON(kernel); //nonprimitive
    }

    // cluster_snapshot_metadata_boot_options->pongo
    cJSON *pongo = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_metadata_boot_optionsJSON, "pongo");
    if (cJSON_IsNull(pongo)) {
        pongo = NULL;
    }
    if (pongo) { 
    pongo_local_nonprim = instance_boot_options_pongo_parseFromJSON(pongo); //nonprimitive
    }

    // cluster_snapshot_metadata_boot_options->serial
    cJSON *serial = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_metadata_boot_optionsJSON, "serial");
    if (cJSON_IsNull(serial)) {
        serial = NULL;
    }
    if (serial) { 
    if(!cJSON_IsString(serial) && !cJSON_IsNull(serial))
    {
    goto end; //String
    }
    }

    // cluster_snapshot_metadata_boot_options->no_snapshot_mount
    cJSON *no_snapshot_mount = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_metadata_boot_optionsJSON, "noSnapshotMount");
    if (cJSON_IsNull(no_snapshot_mount)) {
        no_snapshot_mount = NULL;
    }
    if (no_snapshot_mount) { 
    if(!cJSON_IsBool(no_snapshot_mount))
    {
    goto end; //Bool
    }
    }

    // cluster_snapshot_metadata_boot_options->kernel_slide
    cJSON *kernel_slide = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_metadata_boot_optionsJSON, "kernelSlide");
    if (cJSON_IsNull(kernel_slide)) {
        kernel_slide = NULL;
    }
    if (kernel_slide) { 
    if(!cJSON_IsString(kernel_slide) && !cJSON_IsNull(kernel_slide))
    {
    goto end; //String
    }
    }

    // cluster_snapshot_metadata_boot_options->cd_hashes
    cJSON *cd_hashes = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_metadata_boot_optionsJSON, "cdHashes");
    if (cJSON_IsNull(cd_hashes)) {
        cd_hashes = NULL;
    }
    if (cd_hashes) { 
    cJSON *cd_hashes_local = NULL;
    if(!cJSON_IsArray(cd_hashes)) {
        goto end;//primitive container
    }
    cd_hashesList = list_createList();

    cJSON_ArrayForEach(cd_hashes_local, cd_hashes)
    {
        if(!cJSON_IsString(cd_hashes_local))
        {
            goto end;
        }
        list_addElement(cd_hashesList , strdup(cd_hashes_local->valuestring));
    }
    }

    // cluster_snapshot_metadata_boot_options->imei
    cJSON *imei = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_metadata_boot_optionsJSON, "imei");
    if (cJSON_IsNull(imei)) {
        imei = NULL;
    }
    if (imei) { 
    if(!cJSON_IsString(imei) && !cJSON_IsNull(imei))
    {
    goto end; //String
    }
    }

    // cluster_snapshot_metadata_boot_options->imsi
    cJSON *imsi = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_metadata_boot_optionsJSON, "imsi");
    if (cJSON_IsNull(imsi)) {
        imsi = NULL;
    }
    if (imsi) { 
    if(!cJSON_IsString(imsi) && !cJSON_IsNull(imsi))
    {
    goto end; //String
    }
    }

    // cluster_snapshot_metadata_boot_options->ssid0
    cJSON *ssid0 = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_metadata_boot_optionsJSON, "ssid0");
    if (cJSON_IsNull(ssid0)) {
        ssid0 = NULL;
    }
    if (ssid0) { 
    if(!cJSON_IsString(ssid0) && !cJSON_IsNull(ssid0))
    {
    goto end; //String
    }
    }

    // cluster_snapshot_metadata_boot_options->ssid1
    cJSON *ssid1 = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_metadata_boot_optionsJSON, "ssid1");
    if (cJSON_IsNull(ssid1)) {
        ssid1 = NULL;
    }
    if (ssid1) { 
    if(!cJSON_IsString(ssid1) && !cJSON_IsNull(ssid1))
    {
    goto end; //String
    }
    }

    // cluster_snapshot_metadata_boot_options->wifi_mac
    cJSON *wifi_mac = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_metadata_boot_optionsJSON, "wifiMac");
    if (cJSON_IsNull(wifi_mac)) {
        wifi_mac = NULL;
    }
    if (wifi_mac) { 
    if(!cJSON_IsString(wifi_mac) && !cJSON_IsNull(wifi_mac))
    {
    goto end; //String
    }
    }

    // cluster_snapshot_metadata_boot_options->model_id
    cJSON *model_id = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_metadata_boot_optionsJSON, "modelId");
    if (cJSON_IsNull(model_id)) {
        model_id = NULL;
    }
    if (model_id) { 
    if(!cJSON_IsString(model_id) && !cJSON_IsNull(model_id))
    {
    goto end; //String
    }
    }

    // cluster_snapshot_metadata_boot_options->manufacturer_id
    cJSON *manufacturer_id = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_metadata_boot_optionsJSON, "manufacturerId");
    if (cJSON_IsNull(manufacturer_id)) {
        manufacturer_id = NULL;
    }
    if (manufacturer_id) { 
    if(!cJSON_IsString(manufacturer_id) && !cJSON_IsNull(manufacturer_id))
    {
    goto end; //String
    }
    }

    // cluster_snapshot_metadata_boot_options->kernel_patches
    cJSON *kernel_patches = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_metadata_boot_optionsJSON, "kernelPatches");
    if (cJSON_IsNull(kernel_patches)) {
        kernel_patches = NULL;
    }
    if (kernel_patches) { 
    if(!cJSON_IsString(kernel_patches) && !cJSON_IsNull(kernel_patches))
    {
    goto end; //String
    }
    }

    // cluster_snapshot_metadata_boot_options->stop_on_fault
    cJSON *stop_on_fault = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_metadata_boot_optionsJSON, "stopOnFault");
    if (cJSON_IsNull(stop_on_fault)) {
        stop_on_fault = NULL;
    }
    if (stop_on_fault) { 
    if(!cJSON_IsBool(stop_on_fault))
    {
    goto end; //Bool
    }
    }

    // cluster_snapshot_metadata_boot_options->boot_addr
    cJSON *boot_addr = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_metadata_boot_optionsJSON, "bootAddr");
    if (cJSON_IsNull(boot_addr)) {
        boot_addr = NULL;
    }
    if (boot_addr) { 
    if(!cJSON_IsString(boot_addr) && !cJSON_IsNull(boot_addr))
    {
    goto end; //String
    }
    }

    // cluster_snapshot_metadata_boot_options->tzen
    cJSON *tzen = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_metadata_boot_optionsJSON, "tzen");
    if (cJSON_IsNull(tzen)) {
        tzen = NULL;
    }
    if (tzen) { 
    if(!cJSON_IsBool(tzen))
    {
    goto end; //Bool
    }
    }

    // cluster_snapshot_metadata_boot_options->authorized_keys
    cJSON *authorized_keys = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_metadata_boot_optionsJSON, "authorizedKeys");
    if (cJSON_IsNull(authorized_keys)) {
        authorized_keys = NULL;
    }
    if (authorized_keys) { 
    if(!cJSON_IsString(authorized_keys) && !cJSON_IsNull(authorized_keys))
    {
    goto end; //String
    }
    }

    // cluster_snapshot_metadata_boot_options->v_mmio
    cJSON *v_mmio = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_metadata_boot_optionsJSON, "vMMIO");
    if (cJSON_IsNull(v_mmio)) {
        v_mmio = NULL;
    }
    if (v_mmio) { 
    cJSON *v_mmio_local_nonprimitive = NULL;
    if(!cJSON_IsArray(v_mmio)){
        goto end; //nonprimitive container
    }

    v_mmioList = list_createList();

    cJSON_ArrayForEach(v_mmio_local_nonprimitive,v_mmio )
    {
        if(!cJSON_IsObject(v_mmio_local_nonprimitive)){
            goto end;
        }
        instance_boot_options_v_mmio_inner_t *v_mmioItem = instance_boot_options_v_mmio_inner_parseFromJSON(v_mmio_local_nonprimitive);

        list_addElement(v_mmioList, v_mmioItem);
    }
    }

    // cluster_snapshot_metadata_boot_options->fvp
    cJSON *fvp = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_metadata_boot_optionsJSON, "fvp");
    if (cJSON_IsNull(fvp)) {
        fvp = NULL;
    }
    if (fvp) { 
    fvp_local_nonprim = instance_boot_options_fvp_parseFromJSON(fvp); //nonprimitive
    }


    cluster_snapshot_metadata_boot_options_local_var = cluster_snapshot_metadata_boot_options_create_internal (
        boot_args && !cJSON_IsNull(boot_args) ? strdup(boot_args->valuestring) : NULL,
        restore_boot_args && !cJSON_IsNull(restore_boot_args) ? strdup(restore_boot_args->valuestring) : NULL,
        udid && !cJSON_IsNull(udid) ? strdup(udid->valuestring) : NULL,
        ecid && !cJSON_IsNull(ecid) ? strdup(ecid->valuestring) : NULL,
        random_seed && !cJSON_IsNull(random_seed) ? strdup(random_seed->valuestring) : NULL,
        pac ? pac->valueint : 0,
        aprr ? aprr->valueint : 0,
        cores ? cores->valuedouble : 0,
        ram ? ram->valuedouble : 0,
        additional_tags ? additional_tagsList : NULL,
        kernel ? kernel_local_nonprim : NULL,
        pongo ? pongo_local_nonprim : NULL,
        serial && !cJSON_IsNull(serial) ? strdup(serial->valuestring) : NULL,
        no_snapshot_mount ? no_snapshot_mount->valueint : 0,
        kernel_slide && !cJSON_IsNull(kernel_slide) ? strdup(kernel_slide->valuestring) : NULL,
        cd_hashes ? cd_hashesList : NULL,
        imei && !cJSON_IsNull(imei) ? strdup(imei->valuestring) : NULL,
        imsi && !cJSON_IsNull(imsi) ? strdup(imsi->valuestring) : NULL,
        ssid0 && !cJSON_IsNull(ssid0) ? strdup(ssid0->valuestring) : NULL,
        ssid1 && !cJSON_IsNull(ssid1) ? strdup(ssid1->valuestring) : NULL,
        wifi_mac && !cJSON_IsNull(wifi_mac) ? strdup(wifi_mac->valuestring) : NULL,
        model_id && !cJSON_IsNull(model_id) ? strdup(model_id->valuestring) : NULL,
        manufacturer_id && !cJSON_IsNull(manufacturer_id) ? strdup(manufacturer_id->valuestring) : NULL,
        kernel_patches && !cJSON_IsNull(kernel_patches) ? strdup(kernel_patches->valuestring) : NULL,
        stop_on_fault ? stop_on_fault->valueint : 0,
        boot_addr && !cJSON_IsNull(boot_addr) ? strdup(boot_addr->valuestring) : NULL,
        tzen ? tzen->valueint : 0,
        authorized_keys && !cJSON_IsNull(authorized_keys) ? strdup(authorized_keys->valuestring) : NULL,
        v_mmio ? v_mmioList : NULL,
        fvp ? fvp_local_nonprim : NULL
        );

    return cluster_snapshot_metadata_boot_options_local_var;
end:
    if (additional_tagsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, additional_tagsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(additional_tagsList);
        additional_tagsList = NULL;
    }
    if (kernel_local_nonprim) {
        instance_boot_options_kernel_free(kernel_local_nonprim);
        kernel_local_nonprim = NULL;
    }
    if (pongo_local_nonprim) {
        instance_boot_options_pongo_free(pongo_local_nonprim);
        pongo_local_nonprim = NULL;
    }
    if (cd_hashesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, cd_hashesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(cd_hashesList);
        cd_hashesList = NULL;
    }
    if (v_mmioList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, v_mmioList) {
            instance_boot_options_v_mmio_inner_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(v_mmioList);
        v_mmioList = NULL;
    }
    if (fvp_local_nonprim) {
        instance_boot_options_fvp_free(fvp_local_nonprim);
        fvp_local_nonprim = NULL;
    }
    return NULL;

}
