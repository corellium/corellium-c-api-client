#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "instance_console_v1.h"



static instance_console_v1_t *instance_console_v1_create_internal(
    char *name,
    char *id,
    double port,
    char *hash,
    char *info
    ) {
    instance_console_v1_t *instance_console_v1_local_var = malloc(sizeof(instance_console_v1_t));
    if (!instance_console_v1_local_var) {
        return NULL;
    }
    instance_console_v1_local_var->name = name;
    instance_console_v1_local_var->id = id;
    instance_console_v1_local_var->port = port;
    instance_console_v1_local_var->hash = hash;
    instance_console_v1_local_var->info = info;

    instance_console_v1_local_var->_library_owned = 1;
    return instance_console_v1_local_var;
}

__attribute__((deprecated)) instance_console_v1_t *instance_console_v1_create(
    char *name,
    char *id,
    double port,
    char *hash,
    char *info
    ) {
    return instance_console_v1_create_internal (
        name,
        id,
        port,
        hash,
        info
        );
}

void instance_console_v1_free(instance_console_v1_t *instance_console_v1) {
    if(NULL == instance_console_v1){
        return ;
    }
    if(instance_console_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "instance_console_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (instance_console_v1->name) {
        free(instance_console_v1->name);
        instance_console_v1->name = NULL;
    }
    if (instance_console_v1->id) {
        free(instance_console_v1->id);
        instance_console_v1->id = NULL;
    }
    if (instance_console_v1->hash) {
        free(instance_console_v1->hash);
        instance_console_v1->hash = NULL;
    }
    if (instance_console_v1->info) {
        free(instance_console_v1->info);
        instance_console_v1->info = NULL;
    }
    free(instance_console_v1);
}

cJSON *instance_console_v1_convertToJSON(instance_console_v1_t *instance_console_v1) {
    cJSON *item = cJSON_CreateObject();

    // instance_console_v1->name
    if(instance_console_v1->name) {
    if(cJSON_AddStringToObject(item, "name", instance_console_v1->name) == NULL) {
    goto fail; //String
    }
    }


    // instance_console_v1->id
    if(instance_console_v1->id) {
    if(cJSON_AddStringToObject(item, "id", instance_console_v1->id) == NULL) {
    goto fail; //String
    }
    }


    // instance_console_v1->port
    if(instance_console_v1->port) {
    if(cJSON_AddNumberToObject(item, "port", instance_console_v1->port) == NULL) {
    goto fail; //Numeric
    }
    }


    // instance_console_v1->hash
    if(instance_console_v1->hash) {
    if(cJSON_AddStringToObject(item, "hash", instance_console_v1->hash) == NULL) {
    goto fail; //String
    }
    }


    // instance_console_v1->info
    if(instance_console_v1->info) {
    if(cJSON_AddStringToObject(item, "info", instance_console_v1->info) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

instance_console_v1_t *instance_console_v1_parseFromJSON(cJSON *instance_console_v1JSON){

    instance_console_v1_t *instance_console_v1_local_var = NULL;

    // instance_console_v1->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(instance_console_v1JSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // instance_console_v1->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(instance_console_v1JSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (id) { 
    if(!cJSON_IsString(id) && !cJSON_IsNull(id))
    {
    goto end; //String
    }
    }

    // instance_console_v1->port
    cJSON *port = cJSON_GetObjectItemCaseSensitive(instance_console_v1JSON, "port");
    if (cJSON_IsNull(port)) {
        port = NULL;
    }
    if (port) { 
    if(!cJSON_IsNumber(port))
    {
    goto end; //Numeric
    }
    }

    // instance_console_v1->hash
    cJSON *hash = cJSON_GetObjectItemCaseSensitive(instance_console_v1JSON, "hash");
    if (cJSON_IsNull(hash)) {
        hash = NULL;
    }
    if (hash) { 
    if(!cJSON_IsString(hash) && !cJSON_IsNull(hash))
    {
    goto end; //String
    }
    }

    // instance_console_v1->info
    cJSON *info = cJSON_GetObjectItemCaseSensitive(instance_console_v1JSON, "info");
    if (cJSON_IsNull(info)) {
        info = NULL;
    }
    if (info) { 
    if(!cJSON_IsString(info) && !cJSON_IsNull(info))
    {
    goto end; //String
    }
    }


    instance_console_v1_local_var = instance_console_v1_create_internal (
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        id && !cJSON_IsNull(id) ? strdup(id->valuestring) : NULL,
        port ? port->valuedouble : 0,
        hash && !cJSON_IsNull(hash) ? strdup(hash->valuestring) : NULL,
        info && !cJSON_IsNull(info) ? strdup(info->valuestring) : NULL
        );

    return instance_console_v1_local_var;
end:
    return NULL;

}
