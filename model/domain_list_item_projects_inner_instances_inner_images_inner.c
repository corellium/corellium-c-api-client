#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "domain_list_item_projects_inner_instances_inner_images_inner.h"



static domain_list_item_projects_inner_instances_inner_images_inner_t *domain_list_item_projects_inner_instances_inner_images_inner_create_internal(
    char *identifier,
    char *type,
    char *name,
    double size
    ) {
    domain_list_item_projects_inner_instances_inner_images_inner_t *domain_list_item_projects_inner_instances_inner_images_inner_local_var = malloc(sizeof(domain_list_item_projects_inner_instances_inner_images_inner_t));
    if (!domain_list_item_projects_inner_instances_inner_images_inner_local_var) {
        return NULL;
    }
    domain_list_item_projects_inner_instances_inner_images_inner_local_var->identifier = identifier;
    domain_list_item_projects_inner_instances_inner_images_inner_local_var->type = type;
    domain_list_item_projects_inner_instances_inner_images_inner_local_var->name = name;
    domain_list_item_projects_inner_instances_inner_images_inner_local_var->size = size;

    domain_list_item_projects_inner_instances_inner_images_inner_local_var->_library_owned = 1;
    return domain_list_item_projects_inner_instances_inner_images_inner_local_var;
}

__attribute__((deprecated)) domain_list_item_projects_inner_instances_inner_images_inner_t *domain_list_item_projects_inner_instances_inner_images_inner_create(
    char *identifier,
    char *type,
    char *name,
    double size
    ) {
    return domain_list_item_projects_inner_instances_inner_images_inner_create_internal (
        identifier,
        type,
        name,
        size
        );
}

void domain_list_item_projects_inner_instances_inner_images_inner_free(domain_list_item_projects_inner_instances_inner_images_inner_t *domain_list_item_projects_inner_instances_inner_images_inner) {
    if(NULL == domain_list_item_projects_inner_instances_inner_images_inner){
        return ;
    }
    if(domain_list_item_projects_inner_instances_inner_images_inner->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "domain_list_item_projects_inner_instances_inner_images_inner_free");
        return ;
    }
    listEntry_t *listEntry;
    if (domain_list_item_projects_inner_instances_inner_images_inner->identifier) {
        free(domain_list_item_projects_inner_instances_inner_images_inner->identifier);
        domain_list_item_projects_inner_instances_inner_images_inner->identifier = NULL;
    }
    if (domain_list_item_projects_inner_instances_inner_images_inner->type) {
        free(domain_list_item_projects_inner_instances_inner_images_inner->type);
        domain_list_item_projects_inner_instances_inner_images_inner->type = NULL;
    }
    if (domain_list_item_projects_inner_instances_inner_images_inner->name) {
        free(domain_list_item_projects_inner_instances_inner_images_inner->name);
        domain_list_item_projects_inner_instances_inner_images_inner->name = NULL;
    }
    free(domain_list_item_projects_inner_instances_inner_images_inner);
}

cJSON *domain_list_item_projects_inner_instances_inner_images_inner_convertToJSON(domain_list_item_projects_inner_instances_inner_images_inner_t *domain_list_item_projects_inner_instances_inner_images_inner) {
    cJSON *item = cJSON_CreateObject();

    // domain_list_item_projects_inner_instances_inner_images_inner->identifier
    if (!domain_list_item_projects_inner_instances_inner_images_inner->identifier) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "identifier", domain_list_item_projects_inner_instances_inner_images_inner->identifier) == NULL) {
    goto fail; //String
    }


    // domain_list_item_projects_inner_instances_inner_images_inner->type
    if (!domain_list_item_projects_inner_instances_inner_images_inner->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", domain_list_item_projects_inner_instances_inner_images_inner->type) == NULL) {
    goto fail; //String
    }


    // domain_list_item_projects_inner_instances_inner_images_inner->name
    if (!domain_list_item_projects_inner_instances_inner_images_inner->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", domain_list_item_projects_inner_instances_inner_images_inner->name) == NULL) {
    goto fail; //String
    }


    // domain_list_item_projects_inner_instances_inner_images_inner->size
    if (!domain_list_item_projects_inner_instances_inner_images_inner->size) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "size", domain_list_item_projects_inner_instances_inner_images_inner->size) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

domain_list_item_projects_inner_instances_inner_images_inner_t *domain_list_item_projects_inner_instances_inner_images_inner_parseFromJSON(cJSON *domain_list_item_projects_inner_instances_inner_images_innerJSON){

    domain_list_item_projects_inner_instances_inner_images_inner_t *domain_list_item_projects_inner_instances_inner_images_inner_local_var = NULL;

    // domain_list_item_projects_inner_instances_inner_images_inner->identifier
    cJSON *identifier = cJSON_GetObjectItemCaseSensitive(domain_list_item_projects_inner_instances_inner_images_innerJSON, "identifier");
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

    // domain_list_item_projects_inner_instances_inner_images_inner->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(domain_list_item_projects_inner_instances_inner_images_innerJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }

    // domain_list_item_projects_inner_instances_inner_images_inner->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(domain_list_item_projects_inner_instances_inner_images_innerJSON, "name");
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

    // domain_list_item_projects_inner_instances_inner_images_inner->size
    cJSON *size = cJSON_GetObjectItemCaseSensitive(domain_list_item_projects_inner_instances_inner_images_innerJSON, "size");
    if (cJSON_IsNull(size)) {
        size = NULL;
    }
    if (!size) {
        goto end;
    }

    
    if(!cJSON_IsNumber(size))
    {
    goto end; //Numeric
    }


    domain_list_item_projects_inner_instances_inner_images_inner_local_var = domain_list_item_projects_inner_instances_inner_images_inner_create_internal (
        strdup(identifier->valuestring),
        strdup(type->valuestring),
        strdup(name->valuestring),
        size->valuedouble
        );

    return domain_list_item_projects_inner_instances_inner_images_inner_local_var;
end:
    return NULL;

}
