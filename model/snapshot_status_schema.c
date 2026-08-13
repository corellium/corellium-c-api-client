#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "snapshot_status_schema.h"



static snapshot_status_schema_t *snapshot_status_schema_create_internal(
    char *task,
    int created
    ) {
    snapshot_status_schema_t *snapshot_status_schema_local_var = malloc(sizeof(snapshot_status_schema_t));
    if (!snapshot_status_schema_local_var) {
        return NULL;
    }
    snapshot_status_schema_local_var->task = task;
    snapshot_status_schema_local_var->created = created;

    snapshot_status_schema_local_var->_library_owned = 1;
    return snapshot_status_schema_local_var;
}

__attribute__((deprecated)) snapshot_status_schema_t *snapshot_status_schema_create(
    char *task,
    int created
    ) {
    return snapshot_status_schema_create_internal (
        task,
        created
        );
}

void snapshot_status_schema_free(snapshot_status_schema_t *snapshot_status_schema) {
    if(NULL == snapshot_status_schema){
        return ;
    }
    if(snapshot_status_schema->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "snapshot_status_schema_free");
        return ;
    }
    listEntry_t *listEntry;
    if (snapshot_status_schema->task) {
        free(snapshot_status_schema->task);
        snapshot_status_schema->task = NULL;
    }
    free(snapshot_status_schema);
}

cJSON *snapshot_status_schema_convertToJSON(snapshot_status_schema_t *snapshot_status_schema) {
    cJSON *item = cJSON_CreateObject();

    // snapshot_status_schema->task
    if (!snapshot_status_schema->task) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "task", snapshot_status_schema->task) == NULL) {
    goto fail; //String
    }


    // snapshot_status_schema->created
    if(snapshot_status_schema->created) {
    if(cJSON_AddBoolToObject(item, "created", snapshot_status_schema->created) == NULL) {
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

snapshot_status_schema_t *snapshot_status_schema_parseFromJSON(cJSON *snapshot_status_schemaJSON){

    snapshot_status_schema_t *snapshot_status_schema_local_var = NULL;

    // snapshot_status_schema->task
    cJSON *task = cJSON_GetObjectItemCaseSensitive(snapshot_status_schemaJSON, "task");
    if (cJSON_IsNull(task)) {
        task = NULL;
    }
    if (!task) {
        goto end;
    }

    
    if(!cJSON_IsString(task))
    {
    goto end; //String
    }

    // snapshot_status_schema->created
    cJSON *created = cJSON_GetObjectItemCaseSensitive(snapshot_status_schemaJSON, "created");
    if (cJSON_IsNull(created)) {
        created = NULL;
    }
    if (created) { 
    if(!cJSON_IsBool(created))
    {
    goto end; //Bool
    }
    }


    snapshot_status_schema_local_var = snapshot_status_schema_create_internal (
        strdup(task->valuestring),
        created ? created->valueint : 0
        );

    return snapshot_status_schema_local_var;
end:
    return NULL;

}
