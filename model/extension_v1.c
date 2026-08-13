#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "extension_v1.h"



static extension_v1_t *extension_v1_create_internal(
    char *identifier,
    int enabled,
    char *created_at,
    char *updated_at,
    char *image_id,
    char *state,
    list_t *flavors
    ) {
    extension_v1_t *extension_v1_local_var = malloc(sizeof(extension_v1_t));
    if (!extension_v1_local_var) {
        return NULL;
    }
    extension_v1_local_var->identifier = identifier;
    extension_v1_local_var->enabled = enabled;
    extension_v1_local_var->created_at = created_at;
    extension_v1_local_var->updated_at = updated_at;
    extension_v1_local_var->image_id = image_id;
    extension_v1_local_var->state = state;
    extension_v1_local_var->flavors = flavors;

    extension_v1_local_var->_library_owned = 1;
    return extension_v1_local_var;
}

__attribute__((deprecated)) extension_v1_t *extension_v1_create(
    char *identifier,
    int enabled,
    char *created_at,
    char *updated_at,
    char *image_id,
    char *state,
    list_t *flavors
    ) {
    return extension_v1_create_internal (
        identifier,
        enabled,
        created_at,
        updated_at,
        image_id,
        state,
        flavors
        );
}

void extension_v1_free(extension_v1_t *extension_v1) {
    if(NULL == extension_v1){
        return ;
    }
    if(extension_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "extension_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (extension_v1->identifier) {
        free(extension_v1->identifier);
        extension_v1->identifier = NULL;
    }
    if (extension_v1->created_at) {
        free(extension_v1->created_at);
        extension_v1->created_at = NULL;
    }
    if (extension_v1->updated_at) {
        free(extension_v1->updated_at);
        extension_v1->updated_at = NULL;
    }
    if (extension_v1->image_id) {
        free(extension_v1->image_id);
        extension_v1->image_id = NULL;
    }
    if (extension_v1->state) {
        free(extension_v1->state);
        extension_v1->state = NULL;
    }
    if (extension_v1->flavors) {
        list_ForEach(listEntry, extension_v1->flavors) {
            object_free(listEntry->data);
        }
        list_freeList(extension_v1->flavors);
        extension_v1->flavors = NULL;
    }
    free(extension_v1);
}

cJSON *extension_v1_convertToJSON(extension_v1_t *extension_v1) {
    cJSON *item = cJSON_CreateObject();

    // extension_v1->identifier
    if(extension_v1->identifier) {
    if(cJSON_AddStringToObject(item, "identifier", extension_v1->identifier) == NULL) {
    goto fail; //String
    }
    }


    // extension_v1->enabled
    if(extension_v1->enabled) {
    if(cJSON_AddBoolToObject(item, "enabled", extension_v1->enabled) == NULL) {
    goto fail; //Bool
    }
    }


    // extension_v1->created_at
    if(extension_v1->created_at) {
    if(cJSON_AddStringToObject(item, "createdAt", extension_v1->created_at) == NULL) {
    goto fail; //String
    }
    }


    // extension_v1->updated_at
    if(extension_v1->updated_at) {
    if(cJSON_AddStringToObject(item, "updatedAt", extension_v1->updated_at) == NULL) {
    goto fail; //String
    }
    }


    // extension_v1->image_id
    if(extension_v1->image_id) {
    if(cJSON_AddStringToObject(item, "imageId", extension_v1->image_id) == NULL) {
    goto fail; //String
    }
    }


    // extension_v1->state
    if(extension_v1->state) {
    if(cJSON_AddStringToObject(item, "state", extension_v1->state) == NULL) {
    goto fail; //String
    }
    }


    // extension_v1->flavors
    if(extension_v1->flavors) {
    cJSON *flavors = cJSON_AddArrayToObject(item, "flavors");
    if(flavors == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *flavorsListEntry;
    if (extension_v1->flavors) {
    list_ForEach(flavorsListEntry, extension_v1->flavors) {
    cJSON *itemLocal = object_convertToJSON(flavorsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(flavors, itemLocal);
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

extension_v1_t *extension_v1_parseFromJSON(cJSON *extension_v1JSON){

    extension_v1_t *extension_v1_local_var = NULL;

    // define the local list for extension_v1->flavors
    list_t *flavorsList = NULL;

    // extension_v1->identifier
    cJSON *identifier = cJSON_GetObjectItemCaseSensitive(extension_v1JSON, "identifier");
    if (cJSON_IsNull(identifier)) {
        identifier = NULL;
    }
    if (identifier) { 
    if(!cJSON_IsString(identifier) && !cJSON_IsNull(identifier))
    {
    goto end; //String
    }
    }

    // extension_v1->enabled
    cJSON *enabled = cJSON_GetObjectItemCaseSensitive(extension_v1JSON, "enabled");
    if (cJSON_IsNull(enabled)) {
        enabled = NULL;
    }
    if (enabled) { 
    if(!cJSON_IsBool(enabled))
    {
    goto end; //Bool
    }
    }

    // extension_v1->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(extension_v1JSON, "createdAt");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (created_at) { 
    if(!cJSON_IsString(created_at) && !cJSON_IsNull(created_at))
    {
    goto end; //String
    }
    }

    // extension_v1->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(extension_v1JSON, "updatedAt");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (updated_at) { 
    if(!cJSON_IsString(updated_at) && !cJSON_IsNull(updated_at))
    {
    goto end; //String
    }
    }

    // extension_v1->image_id
    cJSON *image_id = cJSON_GetObjectItemCaseSensitive(extension_v1JSON, "imageId");
    if (cJSON_IsNull(image_id)) {
        image_id = NULL;
    }
    if (image_id) { 
    if(!cJSON_IsString(image_id) && !cJSON_IsNull(image_id))
    {
    goto end; //String
    }
    }

    // extension_v1->state
    cJSON *state = cJSON_GetObjectItemCaseSensitive(extension_v1JSON, "state");
    if (cJSON_IsNull(state)) {
        state = NULL;
    }
    if (state) { 
    if(!cJSON_IsString(state) && !cJSON_IsNull(state))
    {
    goto end; //String
    }
    }

    // extension_v1->flavors
    cJSON *flavors = cJSON_GetObjectItemCaseSensitive(extension_v1JSON, "flavors");
    if (cJSON_IsNull(flavors)) {
        flavors = NULL;
    }
    if (flavors) { 
    cJSON *flavors_local_nonprimitive = NULL;
    if(!cJSON_IsArray(flavors)){
        goto end; //nonprimitive container
    }

    flavorsList = list_createList();

    cJSON_ArrayForEach(flavors_local_nonprimitive,flavors )
    {
        if(!cJSON_IsObject(flavors_local_nonprimitive)){
            goto end;
        }
        object_t *flavorsItem = object_parseFromJSON(flavors_local_nonprimitive);

        list_addElement(flavorsList, flavorsItem);
    }
    }


    extension_v1_local_var = extension_v1_create_internal (
        identifier && !cJSON_IsNull(identifier) ? strdup(identifier->valuestring) : NULL,
        enabled ? enabled->valueint : 0,
        created_at && !cJSON_IsNull(created_at) ? strdup(created_at->valuestring) : NULL,
        updated_at && !cJSON_IsNull(updated_at) ? strdup(updated_at->valuestring) : NULL,
        image_id && !cJSON_IsNull(image_id) ? strdup(image_id->valuestring) : NULL,
        state && !cJSON_IsNull(state) ? strdup(state->valuestring) : NULL,
        flavors ? flavorsList : NULL
        );

    return extension_v1_local_var;
end:
    if (flavorsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, flavorsList) {
            object_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(flavorsList);
        flavorsList = NULL;
    }
    return NULL;

}
