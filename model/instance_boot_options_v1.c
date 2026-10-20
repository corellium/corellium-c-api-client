#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "instance_boot_options_v1.h"



static instance_boot_options_v1_t *instance_boot_options_v1_create_internal(
    char *boot_args,
    char *restore_boot_args,
    char *udid,
    char *ecid,
    char *random_seed,
    int pac,
    int aprr,
    list_t *additional_tags,
    instance_boot_options_kernel_v1_t *kernel,
    instance_boot_options_pongo_v1_t *pongo
    ) {
    instance_boot_options_v1_t *instance_boot_options_v1_local_var = malloc(sizeof(instance_boot_options_v1_t));
    if (!instance_boot_options_v1_local_var) {
        return NULL;
    }
    instance_boot_options_v1_local_var->boot_args = boot_args;
    instance_boot_options_v1_local_var->restore_boot_args = restore_boot_args;
    instance_boot_options_v1_local_var->udid = udid;
    instance_boot_options_v1_local_var->ecid = ecid;
    instance_boot_options_v1_local_var->random_seed = random_seed;
    instance_boot_options_v1_local_var->pac = pac;
    instance_boot_options_v1_local_var->aprr = aprr;
    instance_boot_options_v1_local_var->additional_tags = additional_tags;
    instance_boot_options_v1_local_var->kernel = kernel;
    instance_boot_options_v1_local_var->pongo = pongo;

    instance_boot_options_v1_local_var->_library_owned = 1;
    return instance_boot_options_v1_local_var;
}

__attribute__((deprecated)) instance_boot_options_v1_t *instance_boot_options_v1_create(
    char *boot_args,
    char *restore_boot_args,
    char *udid,
    char *ecid,
    char *random_seed,
    int pac,
    int aprr,
    list_t *additional_tags,
    instance_boot_options_kernel_v1_t *kernel,
    instance_boot_options_pongo_v1_t *pongo
    ) {
    return instance_boot_options_v1_create_internal (
        boot_args,
        restore_boot_args,
        udid,
        ecid,
        random_seed,
        pac,
        aprr,
        additional_tags,
        kernel,
        pongo
        );
}

void instance_boot_options_v1_free(instance_boot_options_v1_t *instance_boot_options_v1) {
    if(NULL == instance_boot_options_v1){
        return ;
    }
    if(instance_boot_options_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "instance_boot_options_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (instance_boot_options_v1->boot_args) {
        free(instance_boot_options_v1->boot_args);
        instance_boot_options_v1->boot_args = NULL;
    }
    if (instance_boot_options_v1->restore_boot_args) {
        free(instance_boot_options_v1->restore_boot_args);
        instance_boot_options_v1->restore_boot_args = NULL;
    }
    if (instance_boot_options_v1->udid) {
        free(instance_boot_options_v1->udid);
        instance_boot_options_v1->udid = NULL;
    }
    if (instance_boot_options_v1->ecid) {
        free(instance_boot_options_v1->ecid);
        instance_boot_options_v1->ecid = NULL;
    }
    if (instance_boot_options_v1->random_seed) {
        free(instance_boot_options_v1->random_seed);
        instance_boot_options_v1->random_seed = NULL;
    }
    if (instance_boot_options_v1->additional_tags) {
        list_ForEach(listEntry, instance_boot_options_v1->additional_tags) {
            free(listEntry->data);
        }
        list_freeList(instance_boot_options_v1->additional_tags);
        instance_boot_options_v1->additional_tags = NULL;
    }
    if (instance_boot_options_v1->kernel) {
        instance_boot_options_kernel_v1_free(instance_boot_options_v1->kernel);
        instance_boot_options_v1->kernel = NULL;
    }
    if (instance_boot_options_v1->pongo) {
        instance_boot_options_pongo_v1_free(instance_boot_options_v1->pongo);
        instance_boot_options_v1->pongo = NULL;
    }
    free(instance_boot_options_v1);
}

cJSON *instance_boot_options_v1_convertToJSON(instance_boot_options_v1_t *instance_boot_options_v1) {
    cJSON *item = cJSON_CreateObject();

    // instance_boot_options_v1->boot_args
    if(instance_boot_options_v1->boot_args) {
    if(cJSON_AddStringToObject(item, "bootArgs", instance_boot_options_v1->boot_args) == NULL) {
    goto fail; //String
    }
    }


    // instance_boot_options_v1->restore_boot_args
    if(instance_boot_options_v1->restore_boot_args) {
    if(cJSON_AddStringToObject(item, "restoreBootArgs", instance_boot_options_v1->restore_boot_args) == NULL) {
    goto fail; //String
    }
    }


    // instance_boot_options_v1->udid
    if(instance_boot_options_v1->udid) {
    if(cJSON_AddStringToObject(item, "udid", instance_boot_options_v1->udid) == NULL) {
    goto fail; //String
    }
    }


    // instance_boot_options_v1->ecid
    if(instance_boot_options_v1->ecid) {
    if(cJSON_AddStringToObject(item, "ecid", instance_boot_options_v1->ecid) == NULL) {
    goto fail; //String
    }
    }


    // instance_boot_options_v1->random_seed
    if(instance_boot_options_v1->random_seed) {
    if(cJSON_AddStringToObject(item, "randomSeed", instance_boot_options_v1->random_seed) == NULL) {
    goto fail; //String
    }
    }


    // instance_boot_options_v1->pac
    if(instance_boot_options_v1->pac) {
    if(cJSON_AddBoolToObject(item, "pac", instance_boot_options_v1->pac) == NULL) {
    goto fail; //Bool
    }
    }


    // instance_boot_options_v1->aprr
    if(instance_boot_options_v1->aprr) {
    if(cJSON_AddBoolToObject(item, "aprr", instance_boot_options_v1->aprr) == NULL) {
    goto fail; //Bool
    }
    }


    // instance_boot_options_v1->additional_tags
    if(instance_boot_options_v1->additional_tags) {
    cJSON *additional_tags = cJSON_AddArrayToObject(item, "additionalTags");
    if(additional_tags == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *additional_tagsListEntry;
    list_ForEach(additional_tagsListEntry, instance_boot_options_v1->additional_tags) {
    if(cJSON_AddStringToObject(additional_tags, "", additional_tagsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // instance_boot_options_v1->kernel
    if(instance_boot_options_v1->kernel) {
    cJSON *kernel_local_JSON = instance_boot_options_kernel_v1_convertToJSON(instance_boot_options_v1->kernel);
    if(kernel_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "kernel", kernel_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // instance_boot_options_v1->pongo
    if(instance_boot_options_v1->pongo) {
    cJSON *pongo_local_JSON = instance_boot_options_pongo_v1_convertToJSON(instance_boot_options_v1->pongo);
    if(pongo_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "pongo", pongo_local_JSON);
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

instance_boot_options_v1_t *instance_boot_options_v1_parseFromJSON(cJSON *instance_boot_options_v1JSON){

    instance_boot_options_v1_t *instance_boot_options_v1_local_var = NULL;

    // define the local list for instance_boot_options_v1->additional_tags
    list_t *additional_tagsList = NULL;

    // define the local variable for instance_boot_options_v1->kernel
    instance_boot_options_kernel_v1_t *kernel_local_nonprim = NULL;

    // define the local variable for instance_boot_options_v1->pongo
    instance_boot_options_pongo_v1_t *pongo_local_nonprim = NULL;

    // instance_boot_options_v1->boot_args
    cJSON *boot_args = cJSON_GetObjectItemCaseSensitive(instance_boot_options_v1JSON, "bootArgs");
    if (cJSON_IsNull(boot_args)) {
        boot_args = NULL;
    }
    if (boot_args) { 
    if(!cJSON_IsString(boot_args) && !cJSON_IsNull(boot_args))
    {
    goto end; //String
    }
    }

    // instance_boot_options_v1->restore_boot_args
    cJSON *restore_boot_args = cJSON_GetObjectItemCaseSensitive(instance_boot_options_v1JSON, "restoreBootArgs");
    if (cJSON_IsNull(restore_boot_args)) {
        restore_boot_args = NULL;
    }
    if (restore_boot_args) { 
    if(!cJSON_IsString(restore_boot_args) && !cJSON_IsNull(restore_boot_args))
    {
    goto end; //String
    }
    }

    // instance_boot_options_v1->udid
    cJSON *udid = cJSON_GetObjectItemCaseSensitive(instance_boot_options_v1JSON, "udid");
    if (cJSON_IsNull(udid)) {
        udid = NULL;
    }
    if (udid) { 
    if(!cJSON_IsString(udid) && !cJSON_IsNull(udid))
    {
    goto end; //String
    }
    }

    // instance_boot_options_v1->ecid
    cJSON *ecid = cJSON_GetObjectItemCaseSensitive(instance_boot_options_v1JSON, "ecid");
    if (cJSON_IsNull(ecid)) {
        ecid = NULL;
    }
    if (ecid) { 
    if(!cJSON_IsString(ecid) && !cJSON_IsNull(ecid))
    {
    goto end; //String
    }
    }

    // instance_boot_options_v1->random_seed
    cJSON *random_seed = cJSON_GetObjectItemCaseSensitive(instance_boot_options_v1JSON, "randomSeed");
    if (cJSON_IsNull(random_seed)) {
        random_seed = NULL;
    }
    if (random_seed) { 
    if(!cJSON_IsString(random_seed) && !cJSON_IsNull(random_seed))
    {
    goto end; //String
    }
    }

    // instance_boot_options_v1->pac
    cJSON *pac = cJSON_GetObjectItemCaseSensitive(instance_boot_options_v1JSON, "pac");
    if (cJSON_IsNull(pac)) {
        pac = NULL;
    }
    if (pac) { 
    if(!cJSON_IsBool(pac))
    {
    goto end; //Bool
    }
    }

    // instance_boot_options_v1->aprr
    cJSON *aprr = cJSON_GetObjectItemCaseSensitive(instance_boot_options_v1JSON, "aprr");
    if (cJSON_IsNull(aprr)) {
        aprr = NULL;
    }
    if (aprr) { 
    if(!cJSON_IsBool(aprr))
    {
    goto end; //Bool
    }
    }

    // instance_boot_options_v1->additional_tags
    cJSON *additional_tags = cJSON_GetObjectItemCaseSensitive(instance_boot_options_v1JSON, "additionalTags");
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

    // instance_boot_options_v1->kernel
    cJSON *kernel = cJSON_GetObjectItemCaseSensitive(instance_boot_options_v1JSON, "kernel");
    if (cJSON_IsNull(kernel)) {
        kernel = NULL;
    }
    if (kernel) { 
    kernel_local_nonprim = instance_boot_options_kernel_v1_parseFromJSON(kernel); //nonprimitive
    }

    // instance_boot_options_v1->pongo
    cJSON *pongo = cJSON_GetObjectItemCaseSensitive(instance_boot_options_v1JSON, "pongo");
    if (cJSON_IsNull(pongo)) {
        pongo = NULL;
    }
    if (pongo) { 
    pongo_local_nonprim = instance_boot_options_pongo_v1_parseFromJSON(pongo); //nonprimitive
    }


    instance_boot_options_v1_local_var = instance_boot_options_v1_create_internal (
        boot_args && !cJSON_IsNull(boot_args) ? strdup(boot_args->valuestring) : NULL,
        restore_boot_args && !cJSON_IsNull(restore_boot_args) ? strdup(restore_boot_args->valuestring) : NULL,
        udid && !cJSON_IsNull(udid) ? strdup(udid->valuestring) : NULL,
        ecid && !cJSON_IsNull(ecid) ? strdup(ecid->valuestring) : NULL,
        random_seed && !cJSON_IsNull(random_seed) ? strdup(random_seed->valuestring) : NULL,
        pac ? pac->valueint : 0,
        aprr ? aprr->valueint : 0,
        additional_tags ? additional_tagsList : NULL,
        kernel ? kernel_local_nonprim : NULL,
        pongo ? pongo_local_nonprim : NULL
        );

    return instance_boot_options_v1_local_var;
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
        instance_boot_options_kernel_v1_free(kernel_local_nonprim);
        kernel_local_nonprim = NULL;
    }
    if (pongo_local_nonprim) {
        instance_boot_options_pongo_v1_free(pongo_local_nonprim);
        pongo_local_nonprim = NULL;
    }
    return NULL;

}
