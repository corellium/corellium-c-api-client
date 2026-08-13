#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "snapshot.h"



static snapshot_t *snapshot_create_internal(
    char *id,
    char *name,
    char *instance,
    snapshot_status_schema_t *status,
    double date,
    int fresh,
    int live,
    int local,
    char *model,
    snapshot_sharing_t *sharing
    ) {
    snapshot_t *snapshot_local_var = malloc(sizeof(snapshot_t));
    if (!snapshot_local_var) {
        return NULL;
    }
    snapshot_local_var->id = id;
    snapshot_local_var->name = name;
    snapshot_local_var->instance = instance;
    snapshot_local_var->status = status;
    snapshot_local_var->date = date;
    snapshot_local_var->fresh = fresh;
    snapshot_local_var->live = live;
    snapshot_local_var->local = local;
    snapshot_local_var->model = model;
    snapshot_local_var->sharing = sharing;

    snapshot_local_var->_library_owned = 1;
    return snapshot_local_var;
}

__attribute__((deprecated)) snapshot_t *snapshot_create(
    char *id,
    char *name,
    char *instance,
    snapshot_status_schema_t *status,
    double date,
    int fresh,
    int live,
    int local,
    char *model,
    snapshot_sharing_t *sharing
    ) {
    return snapshot_create_internal (
        id,
        name,
        instance,
        status,
        date,
        fresh,
        live,
        local,
        model,
        sharing
        );
}

void snapshot_free(snapshot_t *snapshot) {
    if(NULL == snapshot){
        return ;
    }
    if(snapshot->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "snapshot_free");
        return ;
    }
    listEntry_t *listEntry;
    if (snapshot->id) {
        free(snapshot->id);
        snapshot->id = NULL;
    }
    if (snapshot->name) {
        free(snapshot->name);
        snapshot->name = NULL;
    }
    if (snapshot->instance) {
        free(snapshot->instance);
        snapshot->instance = NULL;
    }
    if (snapshot->status) {
        snapshot_status_schema_free(snapshot->status);
        snapshot->status = NULL;
    }
    if (snapshot->model) {
        free(snapshot->model);
        snapshot->model = NULL;
    }
    if (snapshot->sharing) {
        snapshot_sharing_free(snapshot->sharing);
        snapshot->sharing = NULL;
    }
    free(snapshot);
}

cJSON *snapshot_convertToJSON(snapshot_t *snapshot) {
    cJSON *item = cJSON_CreateObject();

    // snapshot->id
    if (!snapshot->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", snapshot->id) == NULL) {
    goto fail; //String
    }


    // snapshot->name
    if (!snapshot->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", snapshot->name) == NULL) {
    goto fail; //String
    }


    // snapshot->instance
    if (!snapshot->instance) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "instance", snapshot->instance) == NULL) {
    goto fail; //String
    }


    // snapshot->status
    if (!snapshot->status) {
        goto fail;
    }
    cJSON *status_local_JSON = snapshot_status_schema_convertToJSON(snapshot->status);
    if(status_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // snapshot->date
    if (!snapshot->date) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "date", snapshot->date) == NULL) {
    goto fail; //Numeric
    }


    // snapshot->fresh
    if(snapshot->fresh) {
    if(cJSON_AddBoolToObject(item, "fresh", snapshot->fresh) == NULL) {
    goto fail; //Bool
    }
    }


    // snapshot->live
    if(snapshot->live) {
    if(cJSON_AddBoolToObject(item, "live", snapshot->live) == NULL) {
    goto fail; //Bool
    }
    }


    // snapshot->local
    if (!snapshot->local) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "local", snapshot->local) == NULL) {
    goto fail; //Bool
    }


    // snapshot->model
    if(snapshot->model) {
    if(cJSON_AddStringToObject(item, "model", snapshot->model) == NULL) {
    goto fail; //String
    }
    }


    // snapshot->sharing
    if (!snapshot->sharing) {
        goto fail;
    }
    cJSON *sharing_local_JSON = snapshot_sharing_convertToJSON(snapshot->sharing);
    if(sharing_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "sharing", sharing_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

snapshot_t *snapshot_parseFromJSON(cJSON *snapshotJSON){

    snapshot_t *snapshot_local_var = NULL;

    // define the local variable for snapshot->status
    snapshot_status_schema_t *status_local_nonprim = NULL;

    // define the local variable for snapshot->sharing
    snapshot_sharing_t *sharing_local_nonprim = NULL;

    // snapshot->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(snapshotJSON, "id");
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

    // snapshot->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(snapshotJSON, "name");
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

    // snapshot->instance
    cJSON *instance = cJSON_GetObjectItemCaseSensitive(snapshotJSON, "instance");
    if (cJSON_IsNull(instance)) {
        instance = NULL;
    }
    if (!instance) {
        goto end;
    }

    
    if(!cJSON_IsString(instance))
    {
    goto end; //String
    }

    // snapshot->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(snapshotJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    status_local_nonprim = snapshot_status_schema_parseFromJSON(status); //nonprimitive

    // snapshot->date
    cJSON *date = cJSON_GetObjectItemCaseSensitive(snapshotJSON, "date");
    if (cJSON_IsNull(date)) {
        date = NULL;
    }
    if (!date) {
        goto end;
    }

    
    if(!cJSON_IsNumber(date))
    {
    goto end; //Numeric
    }

    // snapshot->fresh
    cJSON *fresh = cJSON_GetObjectItemCaseSensitive(snapshotJSON, "fresh");
    if (cJSON_IsNull(fresh)) {
        fresh = NULL;
    }
    if (fresh) { 
    if(!cJSON_IsBool(fresh))
    {
    goto end; //Bool
    }
    }

    // snapshot->live
    cJSON *live = cJSON_GetObjectItemCaseSensitive(snapshotJSON, "live");
    if (cJSON_IsNull(live)) {
        live = NULL;
    }
    if (live) { 
    if(!cJSON_IsBool(live))
    {
    goto end; //Bool
    }
    }

    // snapshot->local
    cJSON *local = cJSON_GetObjectItemCaseSensitive(snapshotJSON, "local");
    if (cJSON_IsNull(local)) {
        local = NULL;
    }
    if (!local) {
        goto end;
    }

    
    if(!cJSON_IsBool(local))
    {
    goto end; //Bool
    }

    // snapshot->model
    cJSON *model = cJSON_GetObjectItemCaseSensitive(snapshotJSON, "model");
    if (cJSON_IsNull(model)) {
        model = NULL;
    }
    if (model) { 
    if(!cJSON_IsString(model) && !cJSON_IsNull(model))
    {
    goto end; //String
    }
    }

    // snapshot->sharing
    cJSON *sharing = cJSON_GetObjectItemCaseSensitive(snapshotJSON, "sharing");
    if (cJSON_IsNull(sharing)) {
        sharing = NULL;
    }
    if (!sharing) {
        goto end;
    }

    
    sharing_local_nonprim = snapshot_sharing_parseFromJSON(sharing); //nonprimitive


    snapshot_local_var = snapshot_create_internal (
        strdup(id->valuestring),
        strdup(name->valuestring),
        strdup(instance->valuestring),
        status_local_nonprim,
        date->valuedouble,
        fresh ? fresh->valueint : 0,
        live ? live->valueint : 0,
        local->valueint,
        model && !cJSON_IsNull(model) ? strdup(model->valuestring) : NULL,
        sharing_local_nonprim
        );

    return snapshot_local_var;
end:
    if (status_local_nonprim) {
        snapshot_status_schema_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    if (sharing_local_nonprim) {
        snapshot_sharing_free(sharing_local_nonprim);
        sharing_local_nonprim = NULL;
    }
    return NULL;

}
