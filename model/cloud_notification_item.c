#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cloud_notification_item.h"



static cloud_notification_item_t *cloud_notification_item_create_internal(
    char *identifier,
    int admin_only,
    int quiet,
    char *scope,
    double level,
    char *title,
    char *message,
    object_t *metadata,
    char *created_at,
    char *updated_at
    ) {
    cloud_notification_item_t *cloud_notification_item_local_var = malloc(sizeof(cloud_notification_item_t));
    if (!cloud_notification_item_local_var) {
        return NULL;
    }
    cloud_notification_item_local_var->identifier = identifier;
    cloud_notification_item_local_var->admin_only = admin_only;
    cloud_notification_item_local_var->quiet = quiet;
    cloud_notification_item_local_var->scope = scope;
    cloud_notification_item_local_var->level = level;
    cloud_notification_item_local_var->title = title;
    cloud_notification_item_local_var->message = message;
    cloud_notification_item_local_var->metadata = metadata;
    cloud_notification_item_local_var->created_at = created_at;
    cloud_notification_item_local_var->updated_at = updated_at;

    cloud_notification_item_local_var->_library_owned = 1;
    return cloud_notification_item_local_var;
}

__attribute__((deprecated)) cloud_notification_item_t *cloud_notification_item_create(
    char *identifier,
    int admin_only,
    int quiet,
    char *scope,
    double level,
    char *title,
    char *message,
    object_t *metadata,
    char *created_at,
    char *updated_at
    ) {
    return cloud_notification_item_create_internal (
        identifier,
        admin_only,
        quiet,
        scope,
        level,
        title,
        message,
        metadata,
        created_at,
        updated_at
        );
}

void cloud_notification_item_free(cloud_notification_item_t *cloud_notification_item) {
    if(NULL == cloud_notification_item){
        return ;
    }
    if(cloud_notification_item->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cloud_notification_item_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cloud_notification_item->identifier) {
        free(cloud_notification_item->identifier);
        cloud_notification_item->identifier = NULL;
    }
    if (cloud_notification_item->scope) {
        free(cloud_notification_item->scope);
        cloud_notification_item->scope = NULL;
    }
    if (cloud_notification_item->title) {
        free(cloud_notification_item->title);
        cloud_notification_item->title = NULL;
    }
    if (cloud_notification_item->message) {
        free(cloud_notification_item->message);
        cloud_notification_item->message = NULL;
    }
    if (cloud_notification_item->metadata) {
        object_free(cloud_notification_item->metadata);
        cloud_notification_item->metadata = NULL;
    }
    if (cloud_notification_item->created_at) {
        free(cloud_notification_item->created_at);
        cloud_notification_item->created_at = NULL;
    }
    if (cloud_notification_item->updated_at) {
        free(cloud_notification_item->updated_at);
        cloud_notification_item->updated_at = NULL;
    }
    free(cloud_notification_item);
}

cJSON *cloud_notification_item_convertToJSON(cloud_notification_item_t *cloud_notification_item) {
    cJSON *item = cJSON_CreateObject();

    // cloud_notification_item->identifier
    if (!cloud_notification_item->identifier) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "identifier", cloud_notification_item->identifier) == NULL) {
    goto fail; //String
    }


    // cloud_notification_item->admin_only
    if (!cloud_notification_item->admin_only) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "adminOnly", cloud_notification_item->admin_only) == NULL) {
    goto fail; //Bool
    }


    // cloud_notification_item->quiet
    if (!cloud_notification_item->quiet) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "quiet", cloud_notification_item->quiet) == NULL) {
    goto fail; //Bool
    }


    // cloud_notification_item->scope
    if (!cloud_notification_item->scope) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "scope", cloud_notification_item->scope) == NULL) {
    goto fail; //String
    }


    // cloud_notification_item->level
    if (!cloud_notification_item->level) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "level", cloud_notification_item->level) == NULL) {
    goto fail; //Numeric
    }


    // cloud_notification_item->title
    if (!cloud_notification_item->title) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "title", cloud_notification_item->title) == NULL) {
    goto fail; //String
    }


    // cloud_notification_item->message
    if (!cloud_notification_item->message) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message", cloud_notification_item->message) == NULL) {
    goto fail; //String
    }


    // cloud_notification_item->metadata
    if(cloud_notification_item->metadata) {
    cJSON *metadata_object = object_convertToJSON(cloud_notification_item->metadata);
    if(metadata_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // cloud_notification_item->created_at
    if (!cloud_notification_item->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "createdAt", cloud_notification_item->created_at) == NULL) {
    goto fail; //Date-Time
    }


    // cloud_notification_item->updated_at
    if (!cloud_notification_item->updated_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "updatedAt", cloud_notification_item->updated_at) == NULL) {
    goto fail; //Date-Time
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

cloud_notification_item_t *cloud_notification_item_parseFromJSON(cJSON *cloud_notification_itemJSON){

    cloud_notification_item_t *cloud_notification_item_local_var = NULL;

    // cloud_notification_item->identifier
    cJSON *identifier = cJSON_GetObjectItemCaseSensitive(cloud_notification_itemJSON, "identifier");
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

    // cloud_notification_item->admin_only
    cJSON *admin_only = cJSON_GetObjectItemCaseSensitive(cloud_notification_itemJSON, "adminOnly");
    if (cJSON_IsNull(admin_only)) {
        admin_only = NULL;
    }
    if (!admin_only) {
        goto end;
    }

    
    if(!cJSON_IsBool(admin_only))
    {
    goto end; //Bool
    }

    // cloud_notification_item->quiet
    cJSON *quiet = cJSON_GetObjectItemCaseSensitive(cloud_notification_itemJSON, "quiet");
    if (cJSON_IsNull(quiet)) {
        quiet = NULL;
    }
    if (!quiet) {
        goto end;
    }

    
    if(!cJSON_IsBool(quiet))
    {
    goto end; //Bool
    }

    // cloud_notification_item->scope
    cJSON *scope = cJSON_GetObjectItemCaseSensitive(cloud_notification_itemJSON, "scope");
    if (cJSON_IsNull(scope)) {
        scope = NULL;
    }
    if (!scope) {
        goto end;
    }

    
    if(!cJSON_IsString(scope))
    {
    goto end; //String
    }

    // cloud_notification_item->level
    cJSON *level = cJSON_GetObjectItemCaseSensitive(cloud_notification_itemJSON, "level");
    if (cJSON_IsNull(level)) {
        level = NULL;
    }
    if (!level) {
        goto end;
    }

    
    if(!cJSON_IsNumber(level))
    {
    goto end; //Numeric
    }

    // cloud_notification_item->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(cloud_notification_itemJSON, "title");
    if (cJSON_IsNull(title)) {
        title = NULL;
    }
    if (!title) {
        goto end;
    }

    
    if(!cJSON_IsString(title))
    {
    goto end; //String
    }

    // cloud_notification_item->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(cloud_notification_itemJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (!message) {
        goto end;
    }

    
    if(!cJSON_IsString(message))
    {
    goto end; //String
    }

    // cloud_notification_item->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(cloud_notification_itemJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    object_t *metadata_local_object = NULL;
    if (metadata) { 
    metadata_local_object = object_parseFromJSON(metadata); //object
    }

    // cloud_notification_item->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(cloud_notification_itemJSON, "createdAt");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (!created_at) {
        goto end;
    }

    
    if(!cJSON_IsString(created_at) && !cJSON_IsNull(created_at))
    {
    goto end; //DateTime
    }

    // cloud_notification_item->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(cloud_notification_itemJSON, "updatedAt");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (!updated_at) {
        goto end;
    }

    
    if(!cJSON_IsString(updated_at) && !cJSON_IsNull(updated_at))
    {
    goto end; //DateTime
    }


    cloud_notification_item_local_var = cloud_notification_item_create_internal (
        strdup(identifier->valuestring),
        admin_only->valueint,
        quiet->valueint,
        strdup(scope->valuestring),
        level->valuedouble,
        strdup(title->valuestring),
        strdup(message->valuestring),
        metadata ? metadata_local_object : NULL,
        strdup(created_at->valuestring),
        strdup(updated_at->valuestring)
        );

    return cloud_notification_item_local_var;
end:
    return NULL;

}
