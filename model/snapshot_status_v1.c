#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "snapshot_status_v1.h"



static snapshot_status_v1_t *snapshot_status_v1_create_internal(
    char *task,
    int created
    ) {
    snapshot_status_v1_t *snapshot_status_v1_local_var = malloc(sizeof(snapshot_status_v1_t));
    if (!snapshot_status_v1_local_var) {
        return NULL;
    }
    snapshot_status_v1_local_var->task = task;
    snapshot_status_v1_local_var->created = created;

    snapshot_status_v1_local_var->_library_owned = 1;
    return snapshot_status_v1_local_var;
}

__attribute__((deprecated)) snapshot_status_v1_t *snapshot_status_v1_create(
    char *task,
    int created
    ) {
    return snapshot_status_v1_create_internal (
        task,
        created
        );
}

void snapshot_status_v1_free(snapshot_status_v1_t *snapshot_status_v1) {
    if(NULL == snapshot_status_v1){
        return ;
    }
    if(snapshot_status_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "snapshot_status_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (snapshot_status_v1->task) {
        free(snapshot_status_v1->task);
        snapshot_status_v1->task = NULL;
    }
    free(snapshot_status_v1);
}

cJSON *snapshot_status_v1_convertToJSON(snapshot_status_v1_t *snapshot_status_v1) {
    cJSON *item = cJSON_CreateObject();

    // snapshot_status_v1->task
    if(snapshot_status_v1->task) {
    if(cJSON_AddStringToObject(item, "task", snapshot_status_v1->task) == NULL) {
    goto fail; //String
    }
    }


    // snapshot_status_v1->created
    if(snapshot_status_v1->created) {
    if(cJSON_AddBoolToObject(item, "created", snapshot_status_v1->created) == NULL) {
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

snapshot_status_v1_t *snapshot_status_v1_parseFromJSON(cJSON *snapshot_status_v1JSON){

    snapshot_status_v1_t *snapshot_status_v1_local_var = NULL;

    // snapshot_status_v1->task
    cJSON *task = cJSON_GetObjectItemCaseSensitive(snapshot_status_v1JSON, "task");
    if (cJSON_IsNull(task)) {
        task = NULL;
    }
    if (task) { 
    if(!cJSON_IsString(task) && !cJSON_IsNull(task))
    {
    goto end; //String
    }
    }

    // snapshot_status_v1->created
    cJSON *created = cJSON_GetObjectItemCaseSensitive(snapshot_status_v1JSON, "created");
    if (cJSON_IsNull(created)) {
        created = NULL;
    }
    if (created) { 
    if(!cJSON_IsBool(created))
    {
    goto end; //Bool
    }
    }


    snapshot_status_v1_local_var = snapshot_status_v1_create_internal (
        task && !cJSON_IsNull(task) ? strdup(task->valuestring) : NULL,
        created ? created->valueint : 0
        );

    return snapshot_status_v1_local_var;
end:
    return NULL;

}
