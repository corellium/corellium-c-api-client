#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "shared_snapshots_info.h"



static shared_snapshots_info_t *shared_snapshots_info_create_internal(
    char *id,
    char *name,
    char *model,
    double shared_on,
    char *shared_with_member,
    snapshot_owner_v1_t *shared_by
    ) {
    shared_snapshots_info_t *shared_snapshots_info_local_var = malloc(sizeof(shared_snapshots_info_t));
    if (!shared_snapshots_info_local_var) {
        return NULL;
    }
    shared_snapshots_info_local_var->id = id;
    shared_snapshots_info_local_var->name = name;
    shared_snapshots_info_local_var->model = model;
    shared_snapshots_info_local_var->shared_on = shared_on;
    shared_snapshots_info_local_var->shared_with_member = shared_with_member;
    shared_snapshots_info_local_var->shared_by = shared_by;

    shared_snapshots_info_local_var->_library_owned = 1;
    return shared_snapshots_info_local_var;
}

__attribute__((deprecated)) shared_snapshots_info_t *shared_snapshots_info_create(
    char *id,
    char *name,
    char *model,
    double shared_on,
    char *shared_with_member,
    snapshot_owner_v1_t *shared_by
    ) {
    return shared_snapshots_info_create_internal (
        id,
        name,
        model,
        shared_on,
        shared_with_member,
        shared_by
        );
}

void shared_snapshots_info_free(shared_snapshots_info_t *shared_snapshots_info) {
    if(NULL == shared_snapshots_info){
        return ;
    }
    if(shared_snapshots_info->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "shared_snapshots_info_free");
        return ;
    }
    listEntry_t *listEntry;
    if (shared_snapshots_info->id) {
        free(shared_snapshots_info->id);
        shared_snapshots_info->id = NULL;
    }
    if (shared_snapshots_info->name) {
        free(shared_snapshots_info->name);
        shared_snapshots_info->name = NULL;
    }
    if (shared_snapshots_info->model) {
        free(shared_snapshots_info->model);
        shared_snapshots_info->model = NULL;
    }
    if (shared_snapshots_info->shared_with_member) {
        free(shared_snapshots_info->shared_with_member);
        shared_snapshots_info->shared_with_member = NULL;
    }
    if (shared_snapshots_info->shared_by) {
        snapshot_owner_v1_free(shared_snapshots_info->shared_by);
        shared_snapshots_info->shared_by = NULL;
    }
    free(shared_snapshots_info);
}

cJSON *shared_snapshots_info_convertToJSON(shared_snapshots_info_t *shared_snapshots_info) {
    cJSON *item = cJSON_CreateObject();

    // shared_snapshots_info->id
    if (!shared_snapshots_info->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", shared_snapshots_info->id) == NULL) {
    goto fail; //String
    }


    // shared_snapshots_info->name
    if (!shared_snapshots_info->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", shared_snapshots_info->name) == NULL) {
    goto fail; //String
    }


    // shared_snapshots_info->model
    if (!shared_snapshots_info->model) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "model", shared_snapshots_info->model) == NULL) {
    goto fail; //String
    }


    // shared_snapshots_info->shared_on
    if (!shared_snapshots_info->shared_on) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "sharedOn", shared_snapshots_info->shared_on) == NULL) {
    goto fail; //Numeric
    }


    // shared_snapshots_info->shared_with_member
    if(shared_snapshots_info->shared_with_member) {
    if(cJSON_AddStringToObject(item, "sharedWithMember", shared_snapshots_info->shared_with_member) == NULL) {
    goto fail; //String
    }
    }


    // shared_snapshots_info->shared_by
    if(shared_snapshots_info->shared_by) {
    cJSON *shared_by_local_JSON = snapshot_owner_v1_convertToJSON(shared_snapshots_info->shared_by);
    if(shared_by_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "sharedBy", shared_by_local_JSON);
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

shared_snapshots_info_t *shared_snapshots_info_parseFromJSON(cJSON *shared_snapshots_infoJSON){

    shared_snapshots_info_t *shared_snapshots_info_local_var = NULL;

    // define the local variable for shared_snapshots_info->shared_by
    snapshot_owner_v1_t *shared_by_local_nonprim = NULL;

    // shared_snapshots_info->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(shared_snapshots_infoJSON, "id");
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

    // shared_snapshots_info->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(shared_snapshots_infoJSON, "name");
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

    // shared_snapshots_info->model
    cJSON *model = cJSON_GetObjectItemCaseSensitive(shared_snapshots_infoJSON, "model");
    if (cJSON_IsNull(model)) {
        model = NULL;
    }
    if (!model) {
        goto end;
    }

    
    if(!cJSON_IsString(model))
    {
    goto end; //String
    }

    // shared_snapshots_info->shared_on
    cJSON *shared_on = cJSON_GetObjectItemCaseSensitive(shared_snapshots_infoJSON, "sharedOn");
    if (cJSON_IsNull(shared_on)) {
        shared_on = NULL;
    }
    if (!shared_on) {
        goto end;
    }

    
    if(!cJSON_IsNumber(shared_on))
    {
    goto end; //Numeric
    }

    // shared_snapshots_info->shared_with_member
    cJSON *shared_with_member = cJSON_GetObjectItemCaseSensitive(shared_snapshots_infoJSON, "sharedWithMember");
    if (cJSON_IsNull(shared_with_member)) {
        shared_with_member = NULL;
    }
    if (shared_with_member) { 
    if(!cJSON_IsString(shared_with_member) && !cJSON_IsNull(shared_with_member))
    {
    goto end; //String
    }
    }

    // shared_snapshots_info->shared_by
    cJSON *shared_by = cJSON_GetObjectItemCaseSensitive(shared_snapshots_infoJSON, "sharedBy");
    if (cJSON_IsNull(shared_by)) {
        shared_by = NULL;
    }
    if (shared_by) { 
    shared_by_local_nonprim = snapshot_owner_v1_parseFromJSON(shared_by); //nonprimitive
    }


    shared_snapshots_info_local_var = shared_snapshots_info_create_internal (
        strdup(id->valuestring),
        strdup(name->valuestring),
        strdup(model->valuestring),
        shared_on->valuedouble,
        shared_with_member && !cJSON_IsNull(shared_with_member) ? strdup(shared_with_member->valuestring) : NULL,
        shared_by ? shared_by_local_nonprim : NULL
        );

    return shared_snapshots_info_local_var;
end:
    if (shared_by_local_nonprim) {
        snapshot_owner_v1_free(shared_by_local_nonprim);
        shared_by_local_nonprim = NULL;
    }
    return NULL;

}
