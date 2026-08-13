#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "patch_cluster_config_body.h"



static patch_cluster_config_body_t *patch_cluster_config_body_create_internal(
    double snapshot_limit,
    coordinator_config_t *coordinator_config,
    char *originating_node
    ) {
    patch_cluster_config_body_t *patch_cluster_config_body_local_var = malloc(sizeof(patch_cluster_config_body_t));
    if (!patch_cluster_config_body_local_var) {
        return NULL;
    }
    patch_cluster_config_body_local_var->snapshot_limit = snapshot_limit;
    patch_cluster_config_body_local_var->coordinator_config = coordinator_config;
    patch_cluster_config_body_local_var->originating_node = originating_node;

    patch_cluster_config_body_local_var->_library_owned = 1;
    return patch_cluster_config_body_local_var;
}

__attribute__((deprecated)) patch_cluster_config_body_t *patch_cluster_config_body_create(
    double snapshot_limit,
    coordinator_config_t *coordinator_config,
    char *originating_node
    ) {
    return patch_cluster_config_body_create_internal (
        snapshot_limit,
        coordinator_config,
        originating_node
        );
}

void patch_cluster_config_body_free(patch_cluster_config_body_t *patch_cluster_config_body) {
    if(NULL == patch_cluster_config_body){
        return ;
    }
    if(patch_cluster_config_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "patch_cluster_config_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (patch_cluster_config_body->coordinator_config) {
        coordinator_config_free(patch_cluster_config_body->coordinator_config);
        patch_cluster_config_body->coordinator_config = NULL;
    }
    if (patch_cluster_config_body->originating_node) {
        free(patch_cluster_config_body->originating_node);
        patch_cluster_config_body->originating_node = NULL;
    }
    free(patch_cluster_config_body);
}

cJSON *patch_cluster_config_body_convertToJSON(patch_cluster_config_body_t *patch_cluster_config_body) {
    cJSON *item = cJSON_CreateObject();

    // patch_cluster_config_body->snapshot_limit
    if(patch_cluster_config_body->snapshot_limit) {
    if(cJSON_AddNumberToObject(item, "snapshotLimit", patch_cluster_config_body->snapshot_limit) == NULL) {
    goto fail; //Numeric
    }
    }


    // patch_cluster_config_body->coordinator_config
    if(patch_cluster_config_body->coordinator_config) {
    cJSON *coordinator_config_local_JSON = coordinator_config_convertToJSON(patch_cluster_config_body->coordinator_config);
    if(coordinator_config_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "coordinatorConfig", coordinator_config_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // patch_cluster_config_body->originating_node
    if(patch_cluster_config_body->originating_node) {
    if(cJSON_AddStringToObject(item, "originatingNode", patch_cluster_config_body->originating_node) == NULL) {
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

patch_cluster_config_body_t *patch_cluster_config_body_parseFromJSON(cJSON *patch_cluster_config_bodyJSON){

    patch_cluster_config_body_t *patch_cluster_config_body_local_var = NULL;

    // define the local variable for patch_cluster_config_body->coordinator_config
    coordinator_config_t *coordinator_config_local_nonprim = NULL;

    // patch_cluster_config_body->snapshot_limit
    cJSON *snapshot_limit = cJSON_GetObjectItemCaseSensitive(patch_cluster_config_bodyJSON, "snapshotLimit");
    if (cJSON_IsNull(snapshot_limit)) {
        snapshot_limit = NULL;
    }
    if (snapshot_limit) { 
    if(!cJSON_IsNumber(snapshot_limit))
    {
    goto end; //Numeric
    }
    }

    // patch_cluster_config_body->coordinator_config
    cJSON *coordinator_config = cJSON_GetObjectItemCaseSensitive(patch_cluster_config_bodyJSON, "coordinatorConfig");
    if (cJSON_IsNull(coordinator_config)) {
        coordinator_config = NULL;
    }
    if (coordinator_config) { 
    coordinator_config_local_nonprim = coordinator_config_parseFromJSON(coordinator_config); //nonprimitive
    }

    // patch_cluster_config_body->originating_node
    cJSON *originating_node = cJSON_GetObjectItemCaseSensitive(patch_cluster_config_bodyJSON, "originatingNode");
    if (cJSON_IsNull(originating_node)) {
        originating_node = NULL;
    }
    if (originating_node) { 
    if(!cJSON_IsString(originating_node) && !cJSON_IsNull(originating_node))
    {
    goto end; //String
    }
    }


    patch_cluster_config_body_local_var = patch_cluster_config_body_create_internal (
        snapshot_limit ? snapshot_limit->valuedouble : 0,
        coordinator_config ? coordinator_config_local_nonprim : NULL,
        originating_node && !cJSON_IsNull(originating_node) ? strdup(originating_node->valuestring) : NULL
        );

    return patch_cluster_config_body_local_var;
end:
    if (coordinator_config_local_nonprim) {
        coordinator_config_free(coordinator_config_local_nonprim);
        coordinator_config_local_nonprim = NULL;
    }
    return NULL;

}
