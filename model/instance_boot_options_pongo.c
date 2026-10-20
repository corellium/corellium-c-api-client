#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "instance_boot_options_pongo.h"



static instance_boot_options_pongo_t *instance_boot_options_pongo_create_internal(
    char *id,
    char *name,
    double size
    ) {
    instance_boot_options_pongo_t *instance_boot_options_pongo_local_var = malloc(sizeof(instance_boot_options_pongo_t));
    if (!instance_boot_options_pongo_local_var) {
        return NULL;
    }
    instance_boot_options_pongo_local_var->id = id;
    instance_boot_options_pongo_local_var->name = name;
    instance_boot_options_pongo_local_var->size = size;

    instance_boot_options_pongo_local_var->_library_owned = 1;
    return instance_boot_options_pongo_local_var;
}

__attribute__((deprecated)) instance_boot_options_pongo_t *instance_boot_options_pongo_create(
    char *id,
    char *name,
    double size
    ) {
    return instance_boot_options_pongo_create_internal (
        id,
        name,
        size
        );
}

void instance_boot_options_pongo_free(instance_boot_options_pongo_t *instance_boot_options_pongo) {
    if(NULL == instance_boot_options_pongo){
        return ;
    }
    if(instance_boot_options_pongo->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "instance_boot_options_pongo_free");
        return ;
    }
    listEntry_t *listEntry;
    if (instance_boot_options_pongo->id) {
        free(instance_boot_options_pongo->id);
        instance_boot_options_pongo->id = NULL;
    }
    if (instance_boot_options_pongo->name) {
        free(instance_boot_options_pongo->name);
        instance_boot_options_pongo->name = NULL;
    }
    free(instance_boot_options_pongo);
}

cJSON *instance_boot_options_pongo_convertToJSON(instance_boot_options_pongo_t *instance_boot_options_pongo) {
    cJSON *item = cJSON_CreateObject();

    // instance_boot_options_pongo->id
    if (!instance_boot_options_pongo->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", instance_boot_options_pongo->id) == NULL) {
    goto fail; //String
    }


    // instance_boot_options_pongo->name
    if (!instance_boot_options_pongo->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", instance_boot_options_pongo->name) == NULL) {
    goto fail; //String
    }


    // instance_boot_options_pongo->size
    if (!instance_boot_options_pongo->size) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "size", instance_boot_options_pongo->size) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

instance_boot_options_pongo_t *instance_boot_options_pongo_parseFromJSON(cJSON *instance_boot_options_pongoJSON){

    instance_boot_options_pongo_t *instance_boot_options_pongo_local_var = NULL;

    // instance_boot_options_pongo->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(instance_boot_options_pongoJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }

    // instance_boot_options_pongo->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(instance_boot_options_pongoJSON, "name");
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

    // instance_boot_options_pongo->size
    cJSON *size = cJSON_GetObjectItemCaseSensitive(instance_boot_options_pongoJSON, "size");
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


    instance_boot_options_pongo_local_var = instance_boot_options_pongo_create_internal (
        strdup(id->valuestring),
        strdup(name->valuestring),
        size->valuedouble
        );

    return instance_boot_options_pongo_local_var;
end:
    return NULL;

}
