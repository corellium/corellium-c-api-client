#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "domain_list_item_projects_inner.h"



static domain_list_item_projects_inner_t *domain_list_item_projects_inner_create_internal(
    char *identifier,
    char *name,
    domain_list_item_projects_inner_quotas_t *quotas,
    domain_list_item_projects_inner_usage_t *usage,
    list_t *instances,
    list_t *images
    ) {
    domain_list_item_projects_inner_t *domain_list_item_projects_inner_local_var = malloc(sizeof(domain_list_item_projects_inner_t));
    if (!domain_list_item_projects_inner_local_var) {
        return NULL;
    }
    domain_list_item_projects_inner_local_var->identifier = identifier;
    domain_list_item_projects_inner_local_var->name = name;
    domain_list_item_projects_inner_local_var->quotas = quotas;
    domain_list_item_projects_inner_local_var->usage = usage;
    domain_list_item_projects_inner_local_var->instances = instances;
    domain_list_item_projects_inner_local_var->images = images;

    domain_list_item_projects_inner_local_var->_library_owned = 1;
    return domain_list_item_projects_inner_local_var;
}

__attribute__((deprecated)) domain_list_item_projects_inner_t *domain_list_item_projects_inner_create(
    char *identifier,
    char *name,
    domain_list_item_projects_inner_quotas_t *quotas,
    domain_list_item_projects_inner_usage_t *usage,
    list_t *instances,
    list_t *images
    ) {
    return domain_list_item_projects_inner_create_internal (
        identifier,
        name,
        quotas,
        usage,
        instances,
        images
        );
}

void domain_list_item_projects_inner_free(domain_list_item_projects_inner_t *domain_list_item_projects_inner) {
    if(NULL == domain_list_item_projects_inner){
        return ;
    }
    if(domain_list_item_projects_inner->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "domain_list_item_projects_inner_free");
        return ;
    }
    listEntry_t *listEntry;
    if (domain_list_item_projects_inner->identifier) {
        free(domain_list_item_projects_inner->identifier);
        domain_list_item_projects_inner->identifier = NULL;
    }
    if (domain_list_item_projects_inner->name) {
        free(domain_list_item_projects_inner->name);
        domain_list_item_projects_inner->name = NULL;
    }
    if (domain_list_item_projects_inner->quotas) {
        domain_list_item_projects_inner_quotas_free(domain_list_item_projects_inner->quotas);
        domain_list_item_projects_inner->quotas = NULL;
    }
    if (domain_list_item_projects_inner->usage) {
        domain_list_item_projects_inner_usage_free(domain_list_item_projects_inner->usage);
        domain_list_item_projects_inner->usage = NULL;
    }
    if (domain_list_item_projects_inner->instances) {
        list_ForEach(listEntry, domain_list_item_projects_inner->instances) {
            domain_list_item_projects_inner_instances_inner_free(listEntry->data);
        }
        list_freeList(domain_list_item_projects_inner->instances);
        domain_list_item_projects_inner->instances = NULL;
    }
    if (domain_list_item_projects_inner->images) {
        list_ForEach(listEntry, domain_list_item_projects_inner->images) {
            domain_list_item_projects_inner_instances_inner_images_inner_free(listEntry->data);
        }
        list_freeList(domain_list_item_projects_inner->images);
        domain_list_item_projects_inner->images = NULL;
    }
    free(domain_list_item_projects_inner);
}

cJSON *domain_list_item_projects_inner_convertToJSON(domain_list_item_projects_inner_t *domain_list_item_projects_inner) {
    cJSON *item = cJSON_CreateObject();

    // domain_list_item_projects_inner->identifier
    if (!domain_list_item_projects_inner->identifier) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "identifier", domain_list_item_projects_inner->identifier) == NULL) {
    goto fail; //String
    }


    // domain_list_item_projects_inner->name
    if (!domain_list_item_projects_inner->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", domain_list_item_projects_inner->name) == NULL) {
    goto fail; //String
    }


    // domain_list_item_projects_inner->quotas
    if (!domain_list_item_projects_inner->quotas) {
        goto fail;
    }
    cJSON *quotas_local_JSON = domain_list_item_projects_inner_quotas_convertToJSON(domain_list_item_projects_inner->quotas);
    if(quotas_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "quotas", quotas_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // domain_list_item_projects_inner->usage
    if (!domain_list_item_projects_inner->usage) {
        goto fail;
    }
    cJSON *usage_local_JSON = domain_list_item_projects_inner_usage_convertToJSON(domain_list_item_projects_inner->usage);
    if(usage_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "usage", usage_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // domain_list_item_projects_inner->instances
    if (!domain_list_item_projects_inner->instances) {
        goto fail;
    }
    cJSON *instances = cJSON_AddArrayToObject(item, "instances");
    if(instances == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *instancesListEntry;
    if (domain_list_item_projects_inner->instances) {
    list_ForEach(instancesListEntry, domain_list_item_projects_inner->instances) {
    cJSON *itemLocal = domain_list_item_projects_inner_instances_inner_convertToJSON(instancesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(instances, itemLocal);
    }
    }


    // domain_list_item_projects_inner->images
    if(domain_list_item_projects_inner->images) {
    cJSON *images = cJSON_AddArrayToObject(item, "images");
    if(images == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *imagesListEntry;
    if (domain_list_item_projects_inner->images) {
    list_ForEach(imagesListEntry, domain_list_item_projects_inner->images) {
    cJSON *itemLocal = domain_list_item_projects_inner_instances_inner_images_inner_convertToJSON(imagesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(images, itemLocal);
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

domain_list_item_projects_inner_t *domain_list_item_projects_inner_parseFromJSON(cJSON *domain_list_item_projects_innerJSON){

    domain_list_item_projects_inner_t *domain_list_item_projects_inner_local_var = NULL;

    // define the local variable for domain_list_item_projects_inner->quotas
    domain_list_item_projects_inner_quotas_t *quotas_local_nonprim = NULL;

    // define the local variable for domain_list_item_projects_inner->usage
    domain_list_item_projects_inner_usage_t *usage_local_nonprim = NULL;

    // define the local list for domain_list_item_projects_inner->instances
    list_t *instancesList = NULL;

    // define the local list for domain_list_item_projects_inner->images
    list_t *imagesList = NULL;

    // domain_list_item_projects_inner->identifier
    cJSON *identifier = cJSON_GetObjectItemCaseSensitive(domain_list_item_projects_innerJSON, "identifier");
    if (cJSON_IsNull(identifier)) {
        identifier = NULL;
    }
    if (!identifier) {
        goto end;
    }

    
    if(!cJSON_IsString(identifier))
    {
    goto end; //String
    }

    // domain_list_item_projects_inner->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(domain_list_item_projects_innerJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // domain_list_item_projects_inner->quotas
    cJSON *quotas = cJSON_GetObjectItemCaseSensitive(domain_list_item_projects_innerJSON, "quotas");
    if (cJSON_IsNull(quotas)) {
        quotas = NULL;
    }
    if (!quotas) {
        goto end;
    }

    
    quotas_local_nonprim = domain_list_item_projects_inner_quotas_parseFromJSON(quotas); //nonprimitive

    // domain_list_item_projects_inner->usage
    cJSON *usage = cJSON_GetObjectItemCaseSensitive(domain_list_item_projects_innerJSON, "usage");
    if (cJSON_IsNull(usage)) {
        usage = NULL;
    }
    if (!usage) {
        goto end;
    }

    
    usage_local_nonprim = domain_list_item_projects_inner_usage_parseFromJSON(usage); //nonprimitive

    // domain_list_item_projects_inner->instances
    cJSON *instances = cJSON_GetObjectItemCaseSensitive(domain_list_item_projects_innerJSON, "instances");
    if (cJSON_IsNull(instances)) {
        instances = NULL;
    }
    if (!instances) {
        goto end;
    }

    
    cJSON *instances_local_nonprimitive = NULL;
    if(!cJSON_IsArray(instances)){
        goto end; //nonprimitive container
    }

    instancesList = list_createList();

    cJSON_ArrayForEach(instances_local_nonprimitive,instances )
    {
        if(!cJSON_IsObject(instances_local_nonprimitive)){
            goto end;
        }
        domain_list_item_projects_inner_instances_inner_t *instancesItem = domain_list_item_projects_inner_instances_inner_parseFromJSON(instances_local_nonprimitive);

        list_addElement(instancesList, instancesItem);
    }

    // domain_list_item_projects_inner->images
    cJSON *images = cJSON_GetObjectItemCaseSensitive(domain_list_item_projects_innerJSON, "images");
    if (cJSON_IsNull(images)) {
        images = NULL;
    }
    if (images) { 
    cJSON *images_local_nonprimitive = NULL;
    if(!cJSON_IsArray(images)){
        goto end; //nonprimitive container
    }

    imagesList = list_createList();

    cJSON_ArrayForEach(images_local_nonprimitive,images )
    {
        if(!cJSON_IsObject(images_local_nonprimitive)){
            goto end;
        }
        domain_list_item_projects_inner_instances_inner_images_inner_t *imagesItem = domain_list_item_projects_inner_instances_inner_images_inner_parseFromJSON(images_local_nonprimitive);

        list_addElement(imagesList, imagesItem);
    }
    }


    domain_list_item_projects_inner_local_var = domain_list_item_projects_inner_create_internal (
        strdup(identifier->valuestring),
        strdup(name->valuestring),
        quotas_local_nonprim,
        usage_local_nonprim,
        instancesList,
        images ? imagesList : NULL
        );

    return domain_list_item_projects_inner_local_var;
end:
    if (quotas_local_nonprim) {
        domain_list_item_projects_inner_quotas_free(quotas_local_nonprim);
        quotas_local_nonprim = NULL;
    }
    if (usage_local_nonprim) {
        domain_list_item_projects_inner_usage_free(usage_local_nonprim);
        usage_local_nonprim = NULL;
    }
    if (instancesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, instancesList) {
            domain_list_item_projects_inner_instances_inner_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(instancesList);
        instancesList = NULL;
    }
    if (imagesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, imagesList) {
            domain_list_item_projects_inner_instances_inner_images_inner_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(imagesList);
        imagesList = NULL;
    }
    return NULL;

}
