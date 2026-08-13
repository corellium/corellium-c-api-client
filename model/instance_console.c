#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "instance_console.h"



static instance_console_t *instance_console_create_internal(
    char *name,
    char *id,
    char *port,
    char *hash,
    char *info
    ) {
    instance_console_t *instance_console_local_var = malloc(sizeof(instance_console_t));
    if (!instance_console_local_var) {
        return NULL;
    }
    instance_console_local_var->name = name;
    instance_console_local_var->id = id;
    instance_console_local_var->port = port;
    instance_console_local_var->hash = hash;
    instance_console_local_var->info = info;

    instance_console_local_var->_library_owned = 1;
    return instance_console_local_var;
}

__attribute__((deprecated)) instance_console_t *instance_console_create(
    char *name,
    char *id,
    char *port,
    char *hash,
    char *info
    ) {
    return instance_console_create_internal (
        name,
        id,
        port,
        hash,
        info
        );
}

void instance_console_free(instance_console_t *instance_console) {
    if(NULL == instance_console){
        return ;
    }
    if(instance_console->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "instance_console_free");
        return ;
    }
    listEntry_t *listEntry;
    if (instance_console->name) {
        free(instance_console->name);
        instance_console->name = NULL;
    }
    if (instance_console->id) {
        free(instance_console->id);
        instance_console->id = NULL;
    }
    if (instance_console->port) {
        free(instance_console->port);
        instance_console->port = NULL;
    }
    if (instance_console->hash) {
        free(instance_console->hash);
        instance_console->hash = NULL;
    }
    if (instance_console->info) {
        free(instance_console->info);
        instance_console->info = NULL;
    }
    free(instance_console);
}

cJSON *instance_console_convertToJSON(instance_console_t *instance_console) {
    cJSON *item = cJSON_CreateObject();

    // instance_console->name
    if (!instance_console->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", instance_console->name) == NULL) {
    goto fail; //String
    }


    // instance_console->id
    if (!instance_console->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", instance_console->id) == NULL) {
    goto fail; //String
    }


    // instance_console->port
    if (!instance_console->port) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "port", instance_console->port) == NULL) {
    goto fail; //String
    }


    // instance_console->hash
    if (!instance_console->hash) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "hash", instance_console->hash) == NULL) {
    goto fail; //String
    }


    // instance_console->info
    if (!instance_console->info) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "info", instance_console->info) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

instance_console_t *instance_console_parseFromJSON(cJSON *instance_consoleJSON){

    instance_console_t *instance_console_local_var = NULL;

    // instance_console->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(instance_consoleJSON, "name");
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

    // instance_console->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(instance_consoleJSON, "id");
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

    // instance_console->port
    cJSON *port = cJSON_GetObjectItemCaseSensitive(instance_consoleJSON, "port");
    if (cJSON_IsNull(port)) {
        port = NULL;
    }
    if (!port) {
        goto end;
    }

    
    if(!cJSON_IsString(port))
    {
    goto end; //String
    }

    // instance_console->hash
    cJSON *hash = cJSON_GetObjectItemCaseSensitive(instance_consoleJSON, "hash");
    if (cJSON_IsNull(hash)) {
        hash = NULL;
    }
    if (!hash) {
        goto end;
    }

    
    if(!cJSON_IsString(hash))
    {
    goto end; //String
    }

    // instance_console->info
    cJSON *info = cJSON_GetObjectItemCaseSensitive(instance_consoleJSON, "info");
    if (cJSON_IsNull(info)) {
        info = NULL;
    }
    if (!info) {
        goto end;
    }

    
    if(!cJSON_IsString(info))
    {
    goto end; //String
    }


    instance_console_local_var = instance_console_create_internal (
        strdup(name->valuestring),
        strdup(id->valuestring),
        strdup(port->valuestring),
        strdup(hash->valuestring),
        strdup(info->valuestring)
        );

    return instance_console_local_var;
end:
    return NULL;

}
