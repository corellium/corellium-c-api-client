#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "snapshot_v1.h"



static snapshot_v1_t *snapshot_v1_create_internal(
    char *id,
    char *name,
    char *instance,
    snapshot_status_t *status,
    double date,
    int fresh,
    int live,
    int local,
    char *model,
    snapshot_sharing_v1_t *sharing
    ) {
    snapshot_v1_t *snapshot_v1_local_var = malloc(sizeof(snapshot_v1_t));
    if (!snapshot_v1_local_var) {
        return NULL;
    }
    snapshot_v1_local_var->id = id;
    snapshot_v1_local_var->name = name;
    snapshot_v1_local_var->instance = instance;
    snapshot_v1_local_var->status = status;
    snapshot_v1_local_var->date = date;
    snapshot_v1_local_var->fresh = fresh;
    snapshot_v1_local_var->live = live;
    snapshot_v1_local_var->local = local;
    snapshot_v1_local_var->model = model;
    snapshot_v1_local_var->sharing = sharing;

    snapshot_v1_local_var->_library_owned = 1;
    return snapshot_v1_local_var;
}

__attribute__((deprecated)) snapshot_v1_t *snapshot_v1_create(
    char *id,
    char *name,
    char *instance,
    snapshot_status_t *status,
    double date,
    int fresh,
    int live,
    int local,
    char *model,
    snapshot_sharing_v1_t *sharing
    ) {
    return snapshot_v1_create_internal (
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

void snapshot_v1_free(snapshot_v1_t *snapshot_v1) {
    if(NULL == snapshot_v1){
        return ;
    }
    if(snapshot_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "snapshot_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (snapshot_v1->id) {
        free(snapshot_v1->id);
        snapshot_v1->id = NULL;
    }
    if (snapshot_v1->name) {
        free(snapshot_v1->name);
        snapshot_v1->name = NULL;
    }
    if (snapshot_v1->instance) {
        free(snapshot_v1->instance);
        snapshot_v1->instance = NULL;
    }
    if (snapshot_v1->status) {
        snapshot_status_free(snapshot_v1->status);
        snapshot_v1->status = NULL;
    }
    if (snapshot_v1->model) {
        free(snapshot_v1->model);
        snapshot_v1->model = NULL;
    }
    if (snapshot_v1->sharing) {
        snapshot_sharing_v1_free(snapshot_v1->sharing);
        snapshot_v1->sharing = NULL;
    }
    free(snapshot_v1);
}

cJSON *snapshot_v1_convertToJSON(snapshot_v1_t *snapshot_v1) {
    cJSON *item = cJSON_CreateObject();

    // snapshot_v1->id
    if (!snapshot_v1->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", snapshot_v1->id) == NULL) {
    goto fail; //String
    }


    // snapshot_v1->name
    if (!snapshot_v1->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", snapshot_v1->name) == NULL) {
    goto fail; //String
    }


    // snapshot_v1->instance
    if (!snapshot_v1->instance) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "instance", snapshot_v1->instance) == NULL) {
    goto fail; //String
    }


    // snapshot_v1->status
    if (!snapshot_v1->status) {
        goto fail;
    }
    cJSON *status_local_JSON = snapshot_status_convertToJSON(snapshot_v1->status);
    if(status_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // snapshot_v1->date
    if (!snapshot_v1->date) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "date", snapshot_v1->date) == NULL) {
    goto fail; //Numeric
    }


    // snapshot_v1->fresh
    if (!snapshot_v1->fresh) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "fresh", snapshot_v1->fresh) == NULL) {
    goto fail; //Bool
    }


    // snapshot_v1->live
    if (!snapshot_v1->live) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "live", snapshot_v1->live) == NULL) {
    goto fail; //Bool
    }


    // snapshot_v1->local
    if (!snapshot_v1->local) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "local", snapshot_v1->local) == NULL) {
    goto fail; //Bool
    }


    // snapshot_v1->model
    if(snapshot_v1->model) {
    if(cJSON_AddStringToObject(item, "model", snapshot_v1->model) == NULL) {
    goto fail; //String
    }
    }


    // snapshot_v1->sharing
    if(snapshot_v1->sharing) {
    cJSON *sharing_local_JSON = snapshot_sharing_v1_convertToJSON(snapshot_v1->sharing);
    if(sharing_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "sharing", sharing_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

snapshot_v1_t *snapshot_v1_parseFromJSON(cJSON *snapshot_v1JSON){

    snapshot_v1_t *snapshot_v1_local_var = NULL;

    // define the local variable for snapshot_v1->status
    snapshot_status_t *status_local_nonprim = NULL;

    // define the local variable for snapshot_v1->sharing
    snapshot_sharing_v1_t *sharing_local_nonprim = NULL;

    // snapshot_v1->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(snapshot_v1JSON, "id");
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

    // snapshot_v1->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(snapshot_v1JSON, "name");
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

    // snapshot_v1->instance
    cJSON *instance = cJSON_GetObjectItemCaseSensitive(snapshot_v1JSON, "instance");
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

    // snapshot_v1->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(snapshot_v1JSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    status_local_nonprim = snapshot_status_parseFromJSON(status); //nonprimitive

    // snapshot_v1->date
    cJSON *date = cJSON_GetObjectItemCaseSensitive(snapshot_v1JSON, "date");
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

    // snapshot_v1->fresh
    cJSON *fresh = cJSON_GetObjectItemCaseSensitive(snapshot_v1JSON, "fresh");
    if (cJSON_IsNull(fresh)) {
        fresh = NULL;
    }
    if (!fresh) {
        goto end;
    }

    
    if(!cJSON_IsBool(fresh))
    {
    goto end; //Bool
    }

    // snapshot_v1->live
    cJSON *live = cJSON_GetObjectItemCaseSensitive(snapshot_v1JSON, "live");
    if (cJSON_IsNull(live)) {
        live = NULL;
    }
    if (!live) {
        goto end;
    }

    
    if(!cJSON_IsBool(live))
    {
    goto end; //Bool
    }

    // snapshot_v1->local
    cJSON *local = cJSON_GetObjectItemCaseSensitive(snapshot_v1JSON, "local");
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

    // snapshot_v1->model
    cJSON *model = cJSON_GetObjectItemCaseSensitive(snapshot_v1JSON, "model");
    if (cJSON_IsNull(model)) {
        model = NULL;
    }
    if (model) { 
    if(!cJSON_IsString(model) && !cJSON_IsNull(model))
    {
    goto end; //String
    }
    }

    // snapshot_v1->sharing
    cJSON *sharing = cJSON_GetObjectItemCaseSensitive(snapshot_v1JSON, "sharing");
    if (cJSON_IsNull(sharing)) {
        sharing = NULL;
    }
    if (sharing) { 
    sharing_local_nonprim = snapshot_sharing_v1_parseFromJSON(sharing); //nonprimitive
    }


    snapshot_v1_local_var = snapshot_v1_create_internal (
        strdup(id->valuestring),
        strdup(name->valuestring),
        strdup(instance->valuestring),
        status_local_nonprim,
        date->valuedouble,
        fresh->valueint,
        live->valueint,
        local->valueint,
        model && !cJSON_IsNull(model) ? strdup(model->valuestring) : NULL,
        sharing ? sharing_local_nonprim : NULL
        );

    return snapshot_v1_local_var;
end:
    if (status_local_nonprim) {
        snapshot_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    if (sharing_local_nonprim) {
        snapshot_sharing_v1_free(sharing_local_nonprim);
        sharing_local_nonprim = NULL;
    }
    return NULL;

}
