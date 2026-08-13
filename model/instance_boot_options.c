#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "instance_boot_options.h"



static instance_boot_options_t *instance_boot_options_create_internal(
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
    instance_boot_options_pongo_t *pongo
    ) {
    instance_boot_options_t *instance_boot_options_local_var = malloc(sizeof(instance_boot_options_t));
    if (!instance_boot_options_local_var) {
        return NULL;
    }
    instance_boot_options_local_var->boot_args = boot_args;
    instance_boot_options_local_var->restore_boot_args = restore_boot_args;
    instance_boot_options_local_var->udid = udid;
    instance_boot_options_local_var->ecid = ecid;
    instance_boot_options_local_var->random_seed = random_seed;
    instance_boot_options_local_var->pac = pac;
    instance_boot_options_local_var->aprr = aprr;
    instance_boot_options_local_var->cores = cores;
    instance_boot_options_local_var->ram = ram;
    instance_boot_options_local_var->additional_tags = additional_tags;
    instance_boot_options_local_var->kernel = kernel;
    instance_boot_options_local_var->pongo = pongo;

    instance_boot_options_local_var->_library_owned = 1;
    return instance_boot_options_local_var;
}

__attribute__((deprecated)) instance_boot_options_t *instance_boot_options_create(
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
    instance_boot_options_pongo_t *pongo
    ) {
    return instance_boot_options_create_internal (
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
        pongo
        );
}

void instance_boot_options_free(instance_boot_options_t *instance_boot_options) {
    if(NULL == instance_boot_options){
        return ;
    }
    if(instance_boot_options->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "instance_boot_options_free");
        return ;
    }
    listEntry_t *listEntry;
    if (instance_boot_options->boot_args) {
        free(instance_boot_options->boot_args);
        instance_boot_options->boot_args = NULL;
    }
    if (instance_boot_options->restore_boot_args) {
        free(instance_boot_options->restore_boot_args);
        instance_boot_options->restore_boot_args = NULL;
    }
    if (instance_boot_options->udid) {
        free(instance_boot_options->udid);
        instance_boot_options->udid = NULL;
    }
    if (instance_boot_options->ecid) {
        free(instance_boot_options->ecid);
        instance_boot_options->ecid = NULL;
    }
    if (instance_boot_options->random_seed) {
        free(instance_boot_options->random_seed);
        instance_boot_options->random_seed = NULL;
    }
    if (instance_boot_options->additional_tags) {
        list_ForEach(listEntry, instance_boot_options->additional_tags) {
            free(listEntry->data);
        }
        list_freeList(instance_boot_options->additional_tags);
        instance_boot_options->additional_tags = NULL;
    }
    if (instance_boot_options->kernel) {
        instance_boot_options_kernel_free(instance_boot_options->kernel);
        instance_boot_options->kernel = NULL;
    }
    if (instance_boot_options->pongo) {
        instance_boot_options_pongo_free(instance_boot_options->pongo);
        instance_boot_options->pongo = NULL;
    }
    free(instance_boot_options);
}

cJSON *instance_boot_options_convertToJSON(instance_boot_options_t *instance_boot_options) {
    cJSON *item = cJSON_CreateObject();

    // instance_boot_options->boot_args
    if(instance_boot_options->boot_args) {
    if(cJSON_AddStringToObject(item, "bootArgs", instance_boot_options->boot_args) == NULL) {
    goto fail; //String
    }
    }


    // instance_boot_options->restore_boot_args
    if(instance_boot_options->restore_boot_args) {
    if(cJSON_AddStringToObject(item, "restoreBootArgs", instance_boot_options->restore_boot_args) == NULL) {
    goto fail; //String
    }
    }


    // instance_boot_options->udid
    if(instance_boot_options->udid) {
    if(cJSON_AddStringToObject(item, "udid", instance_boot_options->udid) == NULL) {
    goto fail; //String
    }
    }


    // instance_boot_options->ecid
    if(instance_boot_options->ecid) {
    if(cJSON_AddStringToObject(item, "ecid", instance_boot_options->ecid) == NULL) {
    goto fail; //String
    }
    }


    // instance_boot_options->random_seed
    if(instance_boot_options->random_seed) {
    if(cJSON_AddStringToObject(item, "randomSeed", instance_boot_options->random_seed) == NULL) {
    goto fail; //String
    }
    }


    // instance_boot_options->pac
    if(instance_boot_options->pac) {
    if(cJSON_AddBoolToObject(item, "pac", instance_boot_options->pac) == NULL) {
    goto fail; //Bool
    }
    }


    // instance_boot_options->aprr
    if(instance_boot_options->aprr) {
    if(cJSON_AddBoolToObject(item, "aprr", instance_boot_options->aprr) == NULL) {
    goto fail; //Bool
    }
    }


    // instance_boot_options->cores
    if(instance_boot_options->cores) {
    if(cJSON_AddNumberToObject(item, "cores", instance_boot_options->cores) == NULL) {
    goto fail; //Numeric
    }
    }


    // instance_boot_options->ram
    if(instance_boot_options->ram) {
    if(cJSON_AddNumberToObject(item, "ram", instance_boot_options->ram) == NULL) {
    goto fail; //Numeric
    }
    }


    // instance_boot_options->additional_tags
    if(instance_boot_options->additional_tags) {
    cJSON *additional_tags = cJSON_AddArrayToObject(item, "additionalTags");
    if(additional_tags == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *additional_tagsListEntry;
    list_ForEach(additional_tagsListEntry, instance_boot_options->additional_tags) {
    if(cJSON_AddStringToObject(additional_tags, "", additional_tagsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // instance_boot_options->kernel
    if(instance_boot_options->kernel) {
    cJSON *kernel_local_JSON = instance_boot_options_kernel_convertToJSON(instance_boot_options->kernel);
    if(kernel_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "kernel", kernel_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // instance_boot_options->pongo
    if(instance_boot_options->pongo) {
    cJSON *pongo_local_JSON = instance_boot_options_pongo_convertToJSON(instance_boot_options->pongo);
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

instance_boot_options_t *instance_boot_options_parseFromJSON(cJSON *instance_boot_optionsJSON){

    instance_boot_options_t *instance_boot_options_local_var = NULL;

    // define the local list for instance_boot_options->additional_tags
    list_t *additional_tagsList = NULL;

    // define the local variable for instance_boot_options->kernel
    instance_boot_options_kernel_t *kernel_local_nonprim = NULL;

    // define the local variable for instance_boot_options->pongo
    instance_boot_options_pongo_t *pongo_local_nonprim = NULL;

    // instance_boot_options->boot_args
    cJSON *boot_args = cJSON_GetObjectItemCaseSensitive(instance_boot_optionsJSON, "bootArgs");
    if (cJSON_IsNull(boot_args)) {
        boot_args = NULL;
    }
    if (boot_args) { 
    if(!cJSON_IsString(boot_args) && !cJSON_IsNull(boot_args))
    {
    goto end; //String
    }
    }

    // instance_boot_options->restore_boot_args
    cJSON *restore_boot_args = cJSON_GetObjectItemCaseSensitive(instance_boot_optionsJSON, "restoreBootArgs");
    if (cJSON_IsNull(restore_boot_args)) {
        restore_boot_args = NULL;
    }
    if (restore_boot_args) { 
    if(!cJSON_IsString(restore_boot_args) && !cJSON_IsNull(restore_boot_args))
    {
    goto end; //String
    }
    }

    // instance_boot_options->udid
    cJSON *udid = cJSON_GetObjectItemCaseSensitive(instance_boot_optionsJSON, "udid");
    if (cJSON_IsNull(udid)) {
        udid = NULL;
    }
    if (udid) { 
    if(!cJSON_IsString(udid) && !cJSON_IsNull(udid))
    {
    goto end; //String
    }
    }

    // instance_boot_options->ecid
    cJSON *ecid = cJSON_GetObjectItemCaseSensitive(instance_boot_optionsJSON, "ecid");
    if (cJSON_IsNull(ecid)) {
        ecid = NULL;
    }
    if (ecid) { 
    if(!cJSON_IsString(ecid) && !cJSON_IsNull(ecid))
    {
    goto end; //String
    }
    }

    // instance_boot_options->random_seed
    cJSON *random_seed = cJSON_GetObjectItemCaseSensitive(instance_boot_optionsJSON, "randomSeed");
    if (cJSON_IsNull(random_seed)) {
        random_seed = NULL;
    }
    if (random_seed) { 
    if(!cJSON_IsString(random_seed) && !cJSON_IsNull(random_seed))
    {
    goto end; //String
    }
    }

    // instance_boot_options->pac
    cJSON *pac = cJSON_GetObjectItemCaseSensitive(instance_boot_optionsJSON, "pac");
    if (cJSON_IsNull(pac)) {
        pac = NULL;
    }
    if (pac) { 
    if(!cJSON_IsBool(pac))
    {
    goto end; //Bool
    }
    }

    // instance_boot_options->aprr
    cJSON *aprr = cJSON_GetObjectItemCaseSensitive(instance_boot_optionsJSON, "aprr");
    if (cJSON_IsNull(aprr)) {
        aprr = NULL;
    }
    if (aprr) { 
    if(!cJSON_IsBool(aprr))
    {
    goto end; //Bool
    }
    }

    // instance_boot_options->cores
    cJSON *cores = cJSON_GetObjectItemCaseSensitive(instance_boot_optionsJSON, "cores");
    if (cJSON_IsNull(cores)) {
        cores = NULL;
    }
    if (cores) { 
    if(!cJSON_IsNumber(cores))
    {
    goto end; //Numeric
    }
    }

    // instance_boot_options->ram
    cJSON *ram = cJSON_GetObjectItemCaseSensitive(instance_boot_optionsJSON, "ram");
    if (cJSON_IsNull(ram)) {
        ram = NULL;
    }
    if (ram) { 
    if(!cJSON_IsNumber(ram))
    {
    goto end; //Numeric
    }
    }

    // instance_boot_options->additional_tags
    cJSON *additional_tags = cJSON_GetObjectItemCaseSensitive(instance_boot_optionsJSON, "additionalTags");
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

    // instance_boot_options->kernel
    cJSON *kernel = cJSON_GetObjectItemCaseSensitive(instance_boot_optionsJSON, "kernel");
    if (cJSON_IsNull(kernel)) {
        kernel = NULL;
    }
    if (kernel) { 
    kernel_local_nonprim = instance_boot_options_kernel_parseFromJSON(kernel); //nonprimitive
    }

    // instance_boot_options->pongo
    cJSON *pongo = cJSON_GetObjectItemCaseSensitive(instance_boot_optionsJSON, "pongo");
    if (cJSON_IsNull(pongo)) {
        pongo = NULL;
    }
    if (pongo) { 
    pongo_local_nonprim = instance_boot_options_pongo_parseFromJSON(pongo); //nonprimitive
    }


    instance_boot_options_local_var = instance_boot_options_create_internal (
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
        pongo ? pongo_local_nonprim : NULL
        );

    return instance_boot_options_local_var;
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
    return NULL;

}
