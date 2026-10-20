#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cluster_snapshot.h"


char* cluster_snapshot_type_ToString(corellium_api_cluster_snapshot_TYPE_e type) {
    char* typeArray[] =  { "NULL", "iscsi", "local", "s3" };
    return typeArray[type];
}

corellium_api_cluster_snapshot_TYPE_e cluster_snapshot_type_FromString(char* type){
    int stringToReturn = 0;
    char *typeArray[] =  { "NULL", "iscsi", "local", "s3" };
    size_t sizeofArray = sizeof(typeArray) / sizeof(typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(type, typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static cluster_snapshot_t *cluster_snapshot_create_internal(
    char *id,
    char *name,
    char *volume,
    char *instance,
    cluster_snapshot_status_t *status,
    corellium_api_cluster_snapshot_TYPE_e type,
    char *compute_node,
    cluster_snapshot_metadata_t *metadata,
    char *created_at,
    char *updated_at
    ) {
    cluster_snapshot_t *cluster_snapshot_local_var = malloc(sizeof(cluster_snapshot_t));
    if (!cluster_snapshot_local_var) {
        return NULL;
    }
    cluster_snapshot_local_var->id = id;
    cluster_snapshot_local_var->name = name;
    cluster_snapshot_local_var->volume = volume;
    cluster_snapshot_local_var->instance = instance;
    cluster_snapshot_local_var->status = status;
    cluster_snapshot_local_var->type = type;
    cluster_snapshot_local_var->compute_node = compute_node;
    cluster_snapshot_local_var->metadata = metadata;
    cluster_snapshot_local_var->created_at = created_at;
    cluster_snapshot_local_var->updated_at = updated_at;

    cluster_snapshot_local_var->_library_owned = 1;
    return cluster_snapshot_local_var;
}

__attribute__((deprecated)) cluster_snapshot_t *cluster_snapshot_create(
    char *id,
    char *name,
    char *volume,
    char *instance,
    cluster_snapshot_status_t *status,
    corellium_api_cluster_snapshot_TYPE_e type,
    char *compute_node,
    cluster_snapshot_metadata_t *metadata,
    char *created_at,
    char *updated_at
    ) {
    return cluster_snapshot_create_internal (
        id,
        name,
        volume,
        instance,
        status,
        type,
        compute_node,
        metadata,
        created_at,
        updated_at
        );
}

void cluster_snapshot_free(cluster_snapshot_t *cluster_snapshot) {
    if(NULL == cluster_snapshot){
        return ;
    }
    if(cluster_snapshot->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cluster_snapshot_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cluster_snapshot->id) {
        free(cluster_snapshot->id);
        cluster_snapshot->id = NULL;
    }
    if (cluster_snapshot->name) {
        free(cluster_snapshot->name);
        cluster_snapshot->name = NULL;
    }
    if (cluster_snapshot->volume) {
        free(cluster_snapshot->volume);
        cluster_snapshot->volume = NULL;
    }
    if (cluster_snapshot->instance) {
        free(cluster_snapshot->instance);
        cluster_snapshot->instance = NULL;
    }
    if (cluster_snapshot->status) {
        cluster_snapshot_status_free(cluster_snapshot->status);
        cluster_snapshot->status = NULL;
    }
    if (cluster_snapshot->compute_node) {
        free(cluster_snapshot->compute_node);
        cluster_snapshot->compute_node = NULL;
    }
    if (cluster_snapshot->metadata) {
        cluster_snapshot_metadata_free(cluster_snapshot->metadata);
        cluster_snapshot->metadata = NULL;
    }
    if (cluster_snapshot->created_at) {
        free(cluster_snapshot->created_at);
        cluster_snapshot->created_at = NULL;
    }
    if (cluster_snapshot->updated_at) {
        free(cluster_snapshot->updated_at);
        cluster_snapshot->updated_at = NULL;
    }
    free(cluster_snapshot);
}

cJSON *cluster_snapshot_convertToJSON(cluster_snapshot_t *cluster_snapshot) {
    cJSON *item = cJSON_CreateObject();

    // cluster_snapshot->id
    if (!cluster_snapshot->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", cluster_snapshot->id) == NULL) {
    goto fail; //String
    }


    // cluster_snapshot->name
    if(cluster_snapshot->name) {
    if(cJSON_AddStringToObject(item, "name", cluster_snapshot->name) == NULL) {
    goto fail; //String
    }
    }


    // cluster_snapshot->volume
    if(cluster_snapshot->volume) {
    if(cJSON_AddStringToObject(item, "volume", cluster_snapshot->volume) == NULL) {
    goto fail; //String
    }
    }


    // cluster_snapshot->instance
    if(cluster_snapshot->instance) {
    if(cJSON_AddStringToObject(item, "instance", cluster_snapshot->instance) == NULL) {
    goto fail; //String
    }
    }


    // cluster_snapshot->status
    if (!cluster_snapshot->status) {
        goto fail;
    }
    cJSON *status_local_JSON = cluster_snapshot_status_convertToJSON(cluster_snapshot->status);
    if(status_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // cluster_snapshot->type
    if (corellium_api_cluster_snapshot_TYPE_NULL == cluster_snapshot->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", cluster_snapshot_type_ToString(cluster_snapshot->type)) == NULL)
    {
    goto fail; //Enum
    }


    // cluster_snapshot->compute_node
    if(cluster_snapshot->compute_node) {
    if(cJSON_AddStringToObject(item, "computeNode", cluster_snapshot->compute_node) == NULL) {
    goto fail; //String
    }
    }


    // cluster_snapshot->metadata
    if (!cluster_snapshot->metadata) {
        goto fail;
    }
    cJSON *metadata_local_JSON = cluster_snapshot_metadata_convertToJSON(cluster_snapshot->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // cluster_snapshot->created_at
    if (!cluster_snapshot->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "createdAt", cluster_snapshot->created_at) == NULL) {
    goto fail; //Date-Time
    }


    // cluster_snapshot->updated_at
    if (!cluster_snapshot->updated_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "updatedAt", cluster_snapshot->updated_at) == NULL) {
    goto fail; //Date-Time
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

cluster_snapshot_t *cluster_snapshot_parseFromJSON(cJSON *cluster_snapshotJSON){

    cluster_snapshot_t *cluster_snapshot_local_var = NULL;

    // define the local variable for cluster_snapshot->status
    cluster_snapshot_status_t *status_local_nonprim = NULL;

    // define the local variable for cluster_snapshot->metadata
    cluster_snapshot_metadata_t *metadata_local_nonprim = NULL;

    // cluster_snapshot->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(cluster_snapshotJSON, "id");
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

    // cluster_snapshot->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(cluster_snapshotJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // cluster_snapshot->volume
    cJSON *volume = cJSON_GetObjectItemCaseSensitive(cluster_snapshotJSON, "volume");
    if (cJSON_IsNull(volume)) {
        volume = NULL;
    }
    if (volume) { 
    if(!cJSON_IsString(volume) && !cJSON_IsNull(volume))
    {
    goto end; //String
    }
    }

    // cluster_snapshot->instance
    cJSON *instance = cJSON_GetObjectItemCaseSensitive(cluster_snapshotJSON, "instance");
    if (cJSON_IsNull(instance)) {
        instance = NULL;
    }
    if (instance) { 
    if(!cJSON_IsString(instance) && !cJSON_IsNull(instance))
    {
    goto end; //String
    }
    }

    // cluster_snapshot->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(cluster_snapshotJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    status_local_nonprim = cluster_snapshot_status_parseFromJSON(status); //nonprimitive

    // cluster_snapshot->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(cluster_snapshotJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    corellium_api_cluster_snapshot_TYPE_e typeVariable;
    
    if(!cJSON_IsString(type))
    {
    goto end; //Enum
    }
    typeVariable = cluster_snapshot_type_FromString(type->valuestring);

    // cluster_snapshot->compute_node
    cJSON *compute_node = cJSON_GetObjectItemCaseSensitive(cluster_snapshotJSON, "computeNode");
    if (cJSON_IsNull(compute_node)) {
        compute_node = NULL;
    }
    if (compute_node) { 
    if(!cJSON_IsString(compute_node) && !cJSON_IsNull(compute_node))
    {
    goto end; //String
    }
    }

    // cluster_snapshot->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(cluster_snapshotJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (!metadata) {
        goto end;
    }

    
    metadata_local_nonprim = cluster_snapshot_metadata_parseFromJSON(metadata); //nonprimitive

    // cluster_snapshot->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(cluster_snapshotJSON, "createdAt");
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

    // cluster_snapshot->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(cluster_snapshotJSON, "updatedAt");
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


    cluster_snapshot_local_var = cluster_snapshot_create_internal (
        strdup(id->valuestring),
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        volume && !cJSON_IsNull(volume) ? strdup(volume->valuestring) : NULL,
        instance && !cJSON_IsNull(instance) ? strdup(instance->valuestring) : NULL,
        status_local_nonprim,
        typeVariable,
        compute_node && !cJSON_IsNull(compute_node) ? strdup(compute_node->valuestring) : NULL,
        metadata_local_nonprim,
        strdup(created_at->valuestring),
        strdup(updated_at->valuestring)
        );

    return cluster_snapshot_local_var;
end:
    if (status_local_nonprim) {
        cluster_snapshot_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    if (metadata_local_nonprim) {
        cluster_snapshot_metadata_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    return NULL;

}
