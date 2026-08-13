#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "instance_boot_options_pongo_v1.h"



static instance_boot_options_pongo_v1_t *instance_boot_options_pongo_v1_create_internal(
    char *id,
    char *name,
    double size
    ) {
    instance_boot_options_pongo_v1_t *instance_boot_options_pongo_v1_local_var = malloc(sizeof(instance_boot_options_pongo_v1_t));
    if (!instance_boot_options_pongo_v1_local_var) {
        return NULL;
    }
    instance_boot_options_pongo_v1_local_var->id = id;
    instance_boot_options_pongo_v1_local_var->name = name;
    instance_boot_options_pongo_v1_local_var->size = size;

    instance_boot_options_pongo_v1_local_var->_library_owned = 1;
    return instance_boot_options_pongo_v1_local_var;
}

__attribute__((deprecated)) instance_boot_options_pongo_v1_t *instance_boot_options_pongo_v1_create(
    char *id,
    char *name,
    double size
    ) {
    return instance_boot_options_pongo_v1_create_internal (
        id,
        name,
        size
        );
}

void instance_boot_options_pongo_v1_free(instance_boot_options_pongo_v1_t *instance_boot_options_pongo_v1) {
    if(NULL == instance_boot_options_pongo_v1){
        return ;
    }
    if(instance_boot_options_pongo_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "instance_boot_options_pongo_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (instance_boot_options_pongo_v1->id) {
        free(instance_boot_options_pongo_v1->id);
        instance_boot_options_pongo_v1->id = NULL;
    }
    if (instance_boot_options_pongo_v1->name) {
        free(instance_boot_options_pongo_v1->name);
        instance_boot_options_pongo_v1->name = NULL;
    }
    free(instance_boot_options_pongo_v1);
}

cJSON *instance_boot_options_pongo_v1_convertToJSON(instance_boot_options_pongo_v1_t *instance_boot_options_pongo_v1) {
    cJSON *item = cJSON_CreateObject();

    // instance_boot_options_pongo_v1->id
    if(instance_boot_options_pongo_v1->id) {
    if(cJSON_AddStringToObject(item, "id", instance_boot_options_pongo_v1->id) == NULL) {
    goto fail; //String
    }
    }


    // instance_boot_options_pongo_v1->name
    if(instance_boot_options_pongo_v1->name) {
    if(cJSON_AddStringToObject(item, "name", instance_boot_options_pongo_v1->name) == NULL) {
    goto fail; //String
    }
    }


    // instance_boot_options_pongo_v1->size
    if(instance_boot_options_pongo_v1->size) {
    if(cJSON_AddNumberToObject(item, "size", instance_boot_options_pongo_v1->size) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

instance_boot_options_pongo_v1_t *instance_boot_options_pongo_v1_parseFromJSON(cJSON *instance_boot_options_pongo_v1JSON){

    instance_boot_options_pongo_v1_t *instance_boot_options_pongo_v1_local_var = NULL;

    // instance_boot_options_pongo_v1->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(instance_boot_options_pongo_v1JSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (id) { 
    if(!cJSON_IsString(id) && !cJSON_IsNull(id))
    {
    goto end; //String
    }
    }

    // instance_boot_options_pongo_v1->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(instance_boot_options_pongo_v1JSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // instance_boot_options_pongo_v1->size
    cJSON *size = cJSON_GetObjectItemCaseSensitive(instance_boot_options_pongo_v1JSON, "size");
    if (cJSON_IsNull(size)) {
        size = NULL;
    }
    if (size) { 
    if(!cJSON_IsNumber(size))
    {
    goto end; //Numeric
    }
    }


    instance_boot_options_pongo_v1_local_var = instance_boot_options_pongo_v1_create_internal (
        id && !cJSON_IsNull(id) ? strdup(id->valuestring) : NULL,
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        size ? size->valuedouble : 0
        );

    return instance_boot_options_pongo_v1_local_var;
end:
    return NULL;

}
