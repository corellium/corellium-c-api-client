#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cluster_snapshot_v1.h"



static cluster_snapshot_v1_t *cluster_snapshot_v1_create_internal(
    char *identifier
    ) {
    cluster_snapshot_v1_t *cluster_snapshot_v1_local_var = malloc(sizeof(cluster_snapshot_v1_t));
    if (!cluster_snapshot_v1_local_var) {
        return NULL;
    }
    cluster_snapshot_v1_local_var->identifier = identifier;

    cluster_snapshot_v1_local_var->_library_owned = 1;
    return cluster_snapshot_v1_local_var;
}

__attribute__((deprecated)) cluster_snapshot_v1_t *cluster_snapshot_v1_create(
    char *identifier
    ) {
    return cluster_snapshot_v1_create_internal (
        identifier
        );
}

void cluster_snapshot_v1_free(cluster_snapshot_v1_t *cluster_snapshot_v1) {
    if(NULL == cluster_snapshot_v1){
        return ;
    }
    if(cluster_snapshot_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cluster_snapshot_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cluster_snapshot_v1->identifier) {
        free(cluster_snapshot_v1->identifier);
        cluster_snapshot_v1->identifier = NULL;
    }
    free(cluster_snapshot_v1);
}

cJSON *cluster_snapshot_v1_convertToJSON(cluster_snapshot_v1_t *cluster_snapshot_v1) {
    cJSON *item = cJSON_CreateObject();

    // cluster_snapshot_v1->identifier
    if(cluster_snapshot_v1->identifier) {
    if(cJSON_AddStringToObject(item, "identifier", cluster_snapshot_v1->identifier) == NULL) {
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

cluster_snapshot_v1_t *cluster_snapshot_v1_parseFromJSON(cJSON *cluster_snapshot_v1JSON){

    cluster_snapshot_v1_t *cluster_snapshot_v1_local_var = NULL;

    // cluster_snapshot_v1->identifier
    cJSON *identifier = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_v1JSON, "identifier");
    if (cJSON_IsNull(identifier)) {
        identifier = NULL;
    }
    if (identifier) { 
    if(!cJSON_IsString(identifier) && !cJSON_IsNull(identifier))
    {
    goto end; //String
    }
    }


    cluster_snapshot_v1_local_var = cluster_snapshot_v1_create_internal (
        identifier && !cJSON_IsNull(identifier) ? strdup(identifier->valuestring) : NULL
        );

    return cluster_snapshot_v1_local_var;
end:
    return NULL;

}
