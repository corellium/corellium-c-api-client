#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "domain_list_item_projects_inner_instances_inner.h"



static domain_list_item_projects_inner_instances_inner_t *domain_list_item_projects_inner_instances_inner_create_internal(
    char *identifier,
    char *name,
    char *status,
    char *error,
    char *task_state,
    char *user_task,
    char *os_version,
    char *os_build,
    char *flavor_id,
    char *flavor,
    char *compute_node,
    char *service_ip,
    char *wifi_ip,
    list_t *images,
    domain_list_item_projects_inner_instances_inner_usage_t *usage
    ) {
    domain_list_item_projects_inner_instances_inner_t *domain_list_item_projects_inner_instances_inner_local_var = malloc(sizeof(domain_list_item_projects_inner_instances_inner_t));
    if (!domain_list_item_projects_inner_instances_inner_local_var) {
        return NULL;
    }
    domain_list_item_projects_inner_instances_inner_local_var->identifier = identifier;
    domain_list_item_projects_inner_instances_inner_local_var->name = name;
    domain_list_item_projects_inner_instances_inner_local_var->status = status;
    domain_list_item_projects_inner_instances_inner_local_var->error = error;
    domain_list_item_projects_inner_instances_inner_local_var->task_state = task_state;
    domain_list_item_projects_inner_instances_inner_local_var->user_task = user_task;
    domain_list_item_projects_inner_instances_inner_local_var->os_version = os_version;
    domain_list_item_projects_inner_instances_inner_local_var->os_build = os_build;
    domain_list_item_projects_inner_instances_inner_local_var->flavor_id = flavor_id;
    domain_list_item_projects_inner_instances_inner_local_var->flavor = flavor;
    domain_list_item_projects_inner_instances_inner_local_var->compute_node = compute_node;
    domain_list_item_projects_inner_instances_inner_local_var->service_ip = service_ip;
    domain_list_item_projects_inner_instances_inner_local_var->wifi_ip = wifi_ip;
    domain_list_item_projects_inner_instances_inner_local_var->images = images;
    domain_list_item_projects_inner_instances_inner_local_var->usage = usage;

    domain_list_item_projects_inner_instances_inner_local_var->_library_owned = 1;
    return domain_list_item_projects_inner_instances_inner_local_var;
}

__attribute__((deprecated)) domain_list_item_projects_inner_instances_inner_t *domain_list_item_projects_inner_instances_inner_create(
    char *identifier,
    char *name,
    char *status,
    char *error,
    char *task_state,
    char *user_task,
    char *os_version,
    char *os_build,
    char *flavor_id,
    char *flavor,
    char *compute_node,
    char *service_ip,
    char *wifi_ip,
    list_t *images,
    domain_list_item_projects_inner_instances_inner_usage_t *usage
    ) {
    return domain_list_item_projects_inner_instances_inner_create_internal (
        identifier,
        name,
        status,
        error,
        task_state,
        user_task,
        os_version,
        os_build,
        flavor_id,
        flavor,
        compute_node,
        service_ip,
        wifi_ip,
        images,
        usage
        );
}

void domain_list_item_projects_inner_instances_inner_free(domain_list_item_projects_inner_instances_inner_t *domain_list_item_projects_inner_instances_inner) {
    if(NULL == domain_list_item_projects_inner_instances_inner){
        return ;
    }
    if(domain_list_item_projects_inner_instances_inner->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "domain_list_item_projects_inner_instances_inner_free");
        return ;
    }
    listEntry_t *listEntry;
    if (domain_list_item_projects_inner_instances_inner->identifier) {
        free(domain_list_item_projects_inner_instances_inner->identifier);
        domain_list_item_projects_inner_instances_inner->identifier = NULL;
    }
    if (domain_list_item_projects_inner_instances_inner->name) {
        free(domain_list_item_projects_inner_instances_inner->name);
        domain_list_item_projects_inner_instances_inner->name = NULL;
    }
    if (domain_list_item_projects_inner_instances_inner->status) {
        free(domain_list_item_projects_inner_instances_inner->status);
        domain_list_item_projects_inner_instances_inner->status = NULL;
    }
    if (domain_list_item_projects_inner_instances_inner->error) {
        free(domain_list_item_projects_inner_instances_inner->error);
        domain_list_item_projects_inner_instances_inner->error = NULL;
    }
    if (domain_list_item_projects_inner_instances_inner->task_state) {
        free(domain_list_item_projects_inner_instances_inner->task_state);
        domain_list_item_projects_inner_instances_inner->task_state = NULL;
    }
    if (domain_list_item_projects_inner_instances_inner->user_task) {
        free(domain_list_item_projects_inner_instances_inner->user_task);
        domain_list_item_projects_inner_instances_inner->user_task = NULL;
    }
    if (domain_list_item_projects_inner_instances_inner->os_version) {
        free(domain_list_item_projects_inner_instances_inner->os_version);
        domain_list_item_projects_inner_instances_inner->os_version = NULL;
    }
    if (domain_list_item_projects_inner_instances_inner->os_build) {
        free(domain_list_item_projects_inner_instances_inner->os_build);
        domain_list_item_projects_inner_instances_inner->os_build = NULL;
    }
    if (domain_list_item_projects_inner_instances_inner->flavor_id) {
        free(domain_list_item_projects_inner_instances_inner->flavor_id);
        domain_list_item_projects_inner_instances_inner->flavor_id = NULL;
    }
    if (domain_list_item_projects_inner_instances_inner->flavor) {
        free(domain_list_item_projects_inner_instances_inner->flavor);
        domain_list_item_projects_inner_instances_inner->flavor = NULL;
    }
    if (domain_list_item_projects_inner_instances_inner->compute_node) {
        free(domain_list_item_projects_inner_instances_inner->compute_node);
        domain_list_item_projects_inner_instances_inner->compute_node = NULL;
    }
    if (domain_list_item_projects_inner_instances_inner->service_ip) {
        free(domain_list_item_projects_inner_instances_inner->service_ip);
        domain_list_item_projects_inner_instances_inner->service_ip = NULL;
    }
    if (domain_list_item_projects_inner_instances_inner->wifi_ip) {
        free(domain_list_item_projects_inner_instances_inner->wifi_ip);
        domain_list_item_projects_inner_instances_inner->wifi_ip = NULL;
    }
    if (domain_list_item_projects_inner_instances_inner->images) {
        list_ForEach(listEntry, domain_list_item_projects_inner_instances_inner->images) {
            domain_list_item_projects_inner_instances_inner_images_inner_free(listEntry->data);
        }
        list_freeList(domain_list_item_projects_inner_instances_inner->images);
        domain_list_item_projects_inner_instances_inner->images = NULL;
    }
    if (domain_list_item_projects_inner_instances_inner->usage) {
        domain_list_item_projects_inner_instances_inner_usage_free(domain_list_item_projects_inner_instances_inner->usage);
        domain_list_item_projects_inner_instances_inner->usage = NULL;
    }
    free(domain_list_item_projects_inner_instances_inner);
}

cJSON *domain_list_item_projects_inner_instances_inner_convertToJSON(domain_list_item_projects_inner_instances_inner_t *domain_list_item_projects_inner_instances_inner) {
    cJSON *item = cJSON_CreateObject();

    // domain_list_item_projects_inner_instances_inner->identifier
    if (!domain_list_item_projects_inner_instances_inner->identifier) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "identifier", domain_list_item_projects_inner_instances_inner->identifier) == NULL) {
    goto fail; //String
    }


    // domain_list_item_projects_inner_instances_inner->name
    if(domain_list_item_projects_inner_instances_inner->name) {
    if(cJSON_AddStringToObject(item, "name", domain_list_item_projects_inner_instances_inner->name) == NULL) {
    goto fail; //String
    }
    }


    // domain_list_item_projects_inner_instances_inner->status
    if (!domain_list_item_projects_inner_instances_inner->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", domain_list_item_projects_inner_instances_inner->status) == NULL) {
    goto fail; //String
    }


    // domain_list_item_projects_inner_instances_inner->error
    if(domain_list_item_projects_inner_instances_inner->error) {
    if(cJSON_AddStringToObject(item, "error", domain_list_item_projects_inner_instances_inner->error) == NULL) {
    goto fail; //String
    }
    }


    // domain_list_item_projects_inner_instances_inner->task_state
    if (!domain_list_item_projects_inner_instances_inner->task_state) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "taskState", domain_list_item_projects_inner_instances_inner->task_state) == NULL) {
    goto fail; //String
    }


    // domain_list_item_projects_inner_instances_inner->user_task
    if(domain_list_item_projects_inner_instances_inner->user_task) {
    if(cJSON_AddStringToObject(item, "userTask", domain_list_item_projects_inner_instances_inner->user_task) == NULL) {
    goto fail; //String
    }
    }


    // domain_list_item_projects_inner_instances_inner->os_version
    if (!domain_list_item_projects_inner_instances_inner->os_version) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "osVersion", domain_list_item_projects_inner_instances_inner->os_version) == NULL) {
    goto fail; //String
    }


    // domain_list_item_projects_inner_instances_inner->os_build
    if (!domain_list_item_projects_inner_instances_inner->os_build) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "osBuild", domain_list_item_projects_inner_instances_inner->os_build) == NULL) {
    goto fail; //String
    }


    // domain_list_item_projects_inner_instances_inner->flavor_id
    if (!domain_list_item_projects_inner_instances_inner->flavor_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "flavorId", domain_list_item_projects_inner_instances_inner->flavor_id) == NULL) {
    goto fail; //String
    }


    // domain_list_item_projects_inner_instances_inner->flavor
    if(domain_list_item_projects_inner_instances_inner->flavor) {
    if(cJSON_AddStringToObject(item, "flavor", domain_list_item_projects_inner_instances_inner->flavor) == NULL) {
    goto fail; //String
    }
    }


    // domain_list_item_projects_inner_instances_inner->compute_node
    if(domain_list_item_projects_inner_instances_inner->compute_node) {
    if(cJSON_AddStringToObject(item, "computeNode", domain_list_item_projects_inner_instances_inner->compute_node) == NULL) {
    goto fail; //String
    }
    }


    // domain_list_item_projects_inner_instances_inner->service_ip
    if(domain_list_item_projects_inner_instances_inner->service_ip) {
    if(cJSON_AddStringToObject(item, "serviceIp", domain_list_item_projects_inner_instances_inner->service_ip) == NULL) {
    goto fail; //String
    }
    }


    // domain_list_item_projects_inner_instances_inner->wifi_ip
    if(domain_list_item_projects_inner_instances_inner->wifi_ip) {
    if(cJSON_AddStringToObject(item, "wifiIp", domain_list_item_projects_inner_instances_inner->wifi_ip) == NULL) {
    goto fail; //String
    }
    }


    // domain_list_item_projects_inner_instances_inner->images
    if (!domain_list_item_projects_inner_instances_inner->images) {
        goto fail;
    }
    cJSON *images = cJSON_AddArrayToObject(item, "images");
    if(images == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *imagesListEntry;
    if (domain_list_item_projects_inner_instances_inner->images) {
    list_ForEach(imagesListEntry, domain_list_item_projects_inner_instances_inner->images) {
    cJSON *itemLocal = domain_list_item_projects_inner_instances_inner_images_inner_convertToJSON(imagesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(images, itemLocal);
    }
    }


    // domain_list_item_projects_inner_instances_inner->usage
    if (!domain_list_item_projects_inner_instances_inner->usage) {
        goto fail;
    }
    cJSON *usage_local_JSON = domain_list_item_projects_inner_instances_inner_usage_convertToJSON(domain_list_item_projects_inner_instances_inner->usage);
    if(usage_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "usage", usage_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

domain_list_item_projects_inner_instances_inner_t *domain_list_item_projects_inner_instances_inner_parseFromJSON(cJSON *domain_list_item_projects_inner_instances_innerJSON){

    domain_list_item_projects_inner_instances_inner_t *domain_list_item_projects_inner_instances_inner_local_var = NULL;

    // define the local list for domain_list_item_projects_inner_instances_inner->images
    list_t *imagesList = NULL;

    // define the local variable for domain_list_item_projects_inner_instances_inner->usage
    domain_list_item_projects_inner_instances_inner_usage_t *usage_local_nonprim = NULL;

    // domain_list_item_projects_inner_instances_inner->identifier
    cJSON *identifier = cJSON_GetObjectItemCaseSensitive(domain_list_item_projects_inner_instances_innerJSON, "identifier");
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

    // domain_list_item_projects_inner_instances_inner->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(domain_list_item_projects_inner_instances_innerJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // domain_list_item_projects_inner_instances_inner->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(domain_list_item_projects_inner_instances_innerJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    if(!cJSON_IsString(status))
    {
    goto end; //String
    }

    // domain_list_item_projects_inner_instances_inner->error
    cJSON *error = cJSON_GetObjectItemCaseSensitive(domain_list_item_projects_inner_instances_innerJSON, "error");
    if (cJSON_IsNull(error)) {
        error = NULL;
    }
    if (error) { 
    if(!cJSON_IsString(error) && !cJSON_IsNull(error))
    {
    goto end; //String
    }
    }

    // domain_list_item_projects_inner_instances_inner->task_state
    cJSON *task_state = cJSON_GetObjectItemCaseSensitive(domain_list_item_projects_inner_instances_innerJSON, "taskState");
    if (cJSON_IsNull(task_state)) {
        task_state = NULL;
    }
    if (!task_state) {
        goto end;
    }

    
    if(!cJSON_IsString(task_state))
    {
    goto end; //String
    }

    // domain_list_item_projects_inner_instances_inner->user_task
    cJSON *user_task = cJSON_GetObjectItemCaseSensitive(domain_list_item_projects_inner_instances_innerJSON, "userTask");
    if (cJSON_IsNull(user_task)) {
        user_task = NULL;
    }
    if (user_task) { 
    if(!cJSON_IsString(user_task) && !cJSON_IsNull(user_task))
    {
    goto end; //String
    }
    }

    // domain_list_item_projects_inner_instances_inner->os_version
    cJSON *os_version = cJSON_GetObjectItemCaseSensitive(domain_list_item_projects_inner_instances_innerJSON, "osVersion");
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

    // domain_list_item_projects_inner_instances_inner->os_build
    cJSON *os_build = cJSON_GetObjectItemCaseSensitive(domain_list_item_projects_inner_instances_innerJSON, "osBuild");
    if (cJSON_IsNull(os_build)) {
        os_build = NULL;
    }
    if (!os_build) {
        goto end;
    }

    
    if(!cJSON_IsString(os_build))
    {
    goto end; //String
    }

    // domain_list_item_projects_inner_instances_inner->flavor_id
    cJSON *flavor_id = cJSON_GetObjectItemCaseSensitive(domain_list_item_projects_inner_instances_innerJSON, "flavorId");
    if (cJSON_IsNull(flavor_id)) {
        flavor_id = NULL;
    }
    if (!flavor_id) {
        goto end;
    }

    
    if(!cJSON_IsString(flavor_id))
    {
    goto end; //String
    }

    // domain_list_item_projects_inner_instances_inner->flavor
    cJSON *flavor = cJSON_GetObjectItemCaseSensitive(domain_list_item_projects_inner_instances_innerJSON, "flavor");
    if (cJSON_IsNull(flavor)) {
        flavor = NULL;
    }
    if (flavor) { 
    if(!cJSON_IsString(flavor) && !cJSON_IsNull(flavor))
    {
    goto end; //String
    }
    }

    // domain_list_item_projects_inner_instances_inner->compute_node
    cJSON *compute_node = cJSON_GetObjectItemCaseSensitive(domain_list_item_projects_inner_instances_innerJSON, "computeNode");
    if (cJSON_IsNull(compute_node)) {
        compute_node = NULL;
    }
    if (compute_node) { 
    if(!cJSON_IsString(compute_node) && !cJSON_IsNull(compute_node))
    {
    goto end; //String
    }
    }

    // domain_list_item_projects_inner_instances_inner->service_ip
    cJSON *service_ip = cJSON_GetObjectItemCaseSensitive(domain_list_item_projects_inner_instances_innerJSON, "serviceIp");
    if (cJSON_IsNull(service_ip)) {
        service_ip = NULL;
    }
    if (service_ip) { 
    if(!cJSON_IsString(service_ip) && !cJSON_IsNull(service_ip))
    {
    goto end; //String
    }
    }

    // domain_list_item_projects_inner_instances_inner->wifi_ip
    cJSON *wifi_ip = cJSON_GetObjectItemCaseSensitive(domain_list_item_projects_inner_instances_innerJSON, "wifiIp");
    if (cJSON_IsNull(wifi_ip)) {
        wifi_ip = NULL;
    }
    if (wifi_ip) { 
    if(!cJSON_IsString(wifi_ip) && !cJSON_IsNull(wifi_ip))
    {
    goto end; //String
    }
    }

    // domain_list_item_projects_inner_instances_inner->images
    cJSON *images = cJSON_GetObjectItemCaseSensitive(domain_list_item_projects_inner_instances_innerJSON, "images");
    if (cJSON_IsNull(images)) {
        images = NULL;
    }
    if (!images) {
        goto end;
    }

    
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

    // domain_list_item_projects_inner_instances_inner->usage
    cJSON *usage = cJSON_GetObjectItemCaseSensitive(domain_list_item_projects_inner_instances_innerJSON, "usage");
    if (cJSON_IsNull(usage)) {
        usage = NULL;
    }
    if (!usage) {
        goto end;
    }

    
    usage_local_nonprim = domain_list_item_projects_inner_instances_inner_usage_parseFromJSON(usage); //nonprimitive


    domain_list_item_projects_inner_instances_inner_local_var = domain_list_item_projects_inner_instances_inner_create_internal (
        strdup(identifier->valuestring),
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        strdup(status->valuestring),
        error && !cJSON_IsNull(error) ? strdup(error->valuestring) : NULL,
        strdup(task_state->valuestring),
        user_task && !cJSON_IsNull(user_task) ? strdup(user_task->valuestring) : NULL,
        strdup(os_version->valuestring),
        strdup(os_build->valuestring),
        strdup(flavor_id->valuestring),
        flavor && !cJSON_IsNull(flavor) ? strdup(flavor->valuestring) : NULL,
        compute_node && !cJSON_IsNull(compute_node) ? strdup(compute_node->valuestring) : NULL,
        service_ip && !cJSON_IsNull(service_ip) ? strdup(service_ip->valuestring) : NULL,
        wifi_ip && !cJSON_IsNull(wifi_ip) ? strdup(wifi_ip->valuestring) : NULL,
        imagesList,
        usage_local_nonprim
        );

    return domain_list_item_projects_inner_instances_inner_local_var;
end:
    if (imagesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, imagesList) {
            domain_list_item_projects_inner_instances_inner_images_inner_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(imagesList);
        imagesList = NULL;
    }
    if (usage_local_nonprim) {
        domain_list_item_projects_inner_instances_inner_usage_free(usage_local_nonprim);
        usage_local_nonprim = NULL;
    }
    return NULL;

}
