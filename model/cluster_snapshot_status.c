#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cluster_snapshot_status.h"



static cluster_snapshot_status_t *cluster_snapshot_status_create_internal(
    char *task,
    int created
    ) {
    cluster_snapshot_status_t *cluster_snapshot_status_local_var = malloc(sizeof(cluster_snapshot_status_t));
    if (!cluster_snapshot_status_local_var) {
        return NULL;
    }
    cluster_snapshot_status_local_var->task = task;
    cluster_snapshot_status_local_var->created = created;

    cluster_snapshot_status_local_var->_library_owned = 1;
    return cluster_snapshot_status_local_var;
}

__attribute__((deprecated)) cluster_snapshot_status_t *cluster_snapshot_status_create(
    char *task,
    int created
    ) {
    return cluster_snapshot_status_create_internal (
        task,
        created
        );
}

void cluster_snapshot_status_free(cluster_snapshot_status_t *cluster_snapshot_status) {
    if(NULL == cluster_snapshot_status){
        return ;
    }
    if(cluster_snapshot_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cluster_snapshot_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cluster_snapshot_status->task) {
        free(cluster_snapshot_status->task);
        cluster_snapshot_status->task = NULL;
    }
    free(cluster_snapshot_status);
}

cJSON *cluster_snapshot_status_convertToJSON(cluster_snapshot_status_t *cluster_snapshot_status) {
    cJSON *item = cJSON_CreateObject();

    // cluster_snapshot_status->task
    if(cluster_snapshot_status->task) {
    if(cJSON_AddStringToObject(item, "task", cluster_snapshot_status->task) == NULL) {
    goto fail; //String
    }
    }


    // cluster_snapshot_status->created
    if(cluster_snapshot_status->created) {
    if(cJSON_AddBoolToObject(item, "created", cluster_snapshot_status->created) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

cluster_snapshot_status_t *cluster_snapshot_status_parseFromJSON(cJSON *cluster_snapshot_statusJSON){

    cluster_snapshot_status_t *cluster_snapshot_status_local_var = NULL;

    // cluster_snapshot_status->task
    cJSON *task = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_statusJSON, "task");
    if (cJSON_IsNull(task)) {
        task = NULL;
    }
    if (task) { 
    if(!cJSON_IsString(task) && !cJSON_IsNull(task))
    {
    goto end; //String
    }
    }

    // cluster_snapshot_status->created
    cJSON *created = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_statusJSON, "created");
    if (cJSON_IsNull(created)) {
        created = NULL;
    }
    if (created) { 
    if(!cJSON_IsBool(created))
    {
    goto end; //Bool
    }
    }


    cluster_snapshot_status_local_var = cluster_snapshot_status_create_internal (
        task && !cJSON_IsNull(task) ? strdup(task->valuestring) : NULL,
        created ? created->valueint : 0
        );

    return cluster_snapshot_status_local_var;
end:
    return NULL;

}
