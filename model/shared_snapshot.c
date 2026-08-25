#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "shared_snapshot.h"


char* shared_snapshot_sharing_type_ToString(corellium_api_shared_snapshot_SHARINGTYPE_e sharing_type) {
    char* sharing_typeArray[] =  { "NULL", "publicLink", "domainRestrictedLink", "passwordPublicLink", "emailInvite", "notShared" };
    return sharing_typeArray[sharing_type];
}

corellium_api_shared_snapshot_SHARINGTYPE_e shared_snapshot_sharing_type_FromString(char* sharing_type){
    int stringToReturn = 0;
    char *sharing_typeArray[] =  { "NULL", "publicLink", "domainRestrictedLink", "passwordPublicLink", "emailInvite", "notShared" };
    size_t sizeofArray = sizeof(sharing_typeArray) / sizeof(sharing_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(sharing_type, sharing_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static shared_snapshot_t *shared_snapshot_create_internal(
    char *shared_on,
    char *shared_with_member,
    corellium_api_shared_snapshot_SHARINGTYPE_e sharing_type,
    snapshot_owner_schema_t *shared_by,
    char *id,
    double date,
    double hw_pac,
    char *instance,
    int live,
    int local,
    char *model,
    char *type,
    char *name,
    snapshot_status_schema_t *status,
    int fresh,
    snapshot_sharing_t *sharing
    ) {
    shared_snapshot_t *shared_snapshot_local_var = malloc(sizeof(shared_snapshot_t));
    if (!shared_snapshot_local_var) {
        return NULL;
    }
    shared_snapshot_local_var->shared_on = shared_on;
    shared_snapshot_local_var->shared_with_member = shared_with_member;
    shared_snapshot_local_var->sharing_type = sharing_type;
    shared_snapshot_local_var->shared_by = shared_by;
    shared_snapshot_local_var->id = id;
    shared_snapshot_local_var->date = date;
    shared_snapshot_local_var->hw_pac = hw_pac;
    shared_snapshot_local_var->instance = instance;
    shared_snapshot_local_var->live = live;
    shared_snapshot_local_var->local = local;
    shared_snapshot_local_var->model = model;
    shared_snapshot_local_var->type = type;
    shared_snapshot_local_var->name = name;
    shared_snapshot_local_var->status = status;
    shared_snapshot_local_var->fresh = fresh;
    shared_snapshot_local_var->sharing = sharing;

    shared_snapshot_local_var->_library_owned = 1;
    return shared_snapshot_local_var;
}

__attribute__((deprecated)) shared_snapshot_t *shared_snapshot_create(
    char *shared_on,
    char *shared_with_member,
    corellium_api_shared_snapshot_SHARINGTYPE_e sharing_type,
    snapshot_owner_schema_t *shared_by,
    char *id,
    double date,
    double hw_pac,
    char *instance,
    int live,
    int local,
    char *model,
    char *type,
    char *name,
    snapshot_status_schema_t *status,
    int fresh,
    snapshot_sharing_t *sharing
    ) {
    return shared_snapshot_create_internal (
        shared_on,
        shared_with_member,
        sharing_type,
        shared_by,
        id,
        date,
        hw_pac,
        instance,
        live,
        local,
        model,
        type,
        name,
        status,
        fresh,
        sharing
        );
}

void shared_snapshot_free(shared_snapshot_t *shared_snapshot) {
    if(NULL == shared_snapshot){
        return ;
    }
    if(shared_snapshot->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "shared_snapshot_free");
        return ;
    }
    listEntry_t *listEntry;
    if (shared_snapshot->shared_on) {
        free(shared_snapshot->shared_on);
        shared_snapshot->shared_on = NULL;
    }
    if (shared_snapshot->shared_with_member) {
        free(shared_snapshot->shared_with_member);
        shared_snapshot->shared_with_member = NULL;
    }
    if (shared_snapshot->shared_by) {
        snapshot_owner_schema_free(shared_snapshot->shared_by);
        shared_snapshot->shared_by = NULL;
    }
    if (shared_snapshot->id) {
        free(shared_snapshot->id);
        shared_snapshot->id = NULL;
    }
    if (shared_snapshot->instance) {
        free(shared_snapshot->instance);
        shared_snapshot->instance = NULL;
    }
    if (shared_snapshot->model) {
        free(shared_snapshot->model);
        shared_snapshot->model = NULL;
    }
    if (shared_snapshot->type) {
        free(shared_snapshot->type);
        shared_snapshot->type = NULL;
    }
    if (shared_snapshot->name) {
        free(shared_snapshot->name);
        shared_snapshot->name = NULL;
    }
    if (shared_snapshot->status) {
        snapshot_status_schema_free(shared_snapshot->status);
        shared_snapshot->status = NULL;
    }
    if (shared_snapshot->sharing) {
        snapshot_sharing_free(shared_snapshot->sharing);
        shared_snapshot->sharing = NULL;
    }
    free(shared_snapshot);
}

cJSON *shared_snapshot_convertToJSON(shared_snapshot_t *shared_snapshot) {
    cJSON *item = cJSON_CreateObject();

    // shared_snapshot->shared_on
    if(shared_snapshot->shared_on) {
    if(cJSON_AddStringToObject(item, "sharedOn", shared_snapshot->shared_on) == NULL) {
    goto fail; //Date-Time
    }
    }


    // shared_snapshot->shared_with_member
    if(shared_snapshot->shared_with_member) {
    if(cJSON_AddStringToObject(item, "sharedWithMember", shared_snapshot->shared_with_member) == NULL) {
    goto fail; //String
    }
    }


    // shared_snapshot->sharing_type
    if (corellium_api_shared_snapshot_SHARINGTYPE_NULL == shared_snapshot->sharing_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sharingType", shared_snapshot_sharing_type_ToString(shared_snapshot->sharing_type)) == NULL)
    {
    goto fail; //Enum
    }


    // shared_snapshot->shared_by
    if(shared_snapshot->shared_by) {
    cJSON *shared_by_local_JSON = snapshot_owner_schema_convertToJSON(shared_snapshot->shared_by);
    if(shared_by_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "sharedBy", shared_by_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // shared_snapshot->id
    if (!shared_snapshot->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", shared_snapshot->id) == NULL) {
    goto fail; //String
    }


    // shared_snapshot->date
    if (!shared_snapshot->date) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "date", shared_snapshot->date) == NULL) {
    goto fail; //Numeric
    }


    // shared_snapshot->hw_pac
    if (!shared_snapshot->hw_pac) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "hwPac", shared_snapshot->hw_pac) == NULL) {
    goto fail; //Numeric
    }


    // shared_snapshot->instance
    if (!shared_snapshot->instance) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "instance", shared_snapshot->instance) == NULL) {
    goto fail; //String
    }


    // shared_snapshot->live
    if(shared_snapshot->live) {
    if(cJSON_AddBoolToObject(item, "live", shared_snapshot->live) == NULL) {
    goto fail; //Bool
    }
    }


    // shared_snapshot->local
    if (!shared_snapshot->local) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "local", shared_snapshot->local) == NULL) {
    goto fail; //Bool
    }


    // shared_snapshot->model
    if(shared_snapshot->model) {
    if(cJSON_AddStringToObject(item, "model", shared_snapshot->model) == NULL) {
    goto fail; //String
    }
    }


    // shared_snapshot->type
    if(shared_snapshot->type) {
    if(cJSON_AddStringToObject(item, "type", shared_snapshot->type) == NULL) {
    goto fail; //String
    }
    }


    // shared_snapshot->name
    if (!shared_snapshot->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", shared_snapshot->name) == NULL) {
    goto fail; //String
    }


    // shared_snapshot->status
    if (!shared_snapshot->status) {
        goto fail;
    }
    cJSON *status_local_JSON = snapshot_status_schema_convertToJSON(shared_snapshot->status);
    if(status_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // shared_snapshot->fresh
    if(shared_snapshot->fresh) {
    if(cJSON_AddBoolToObject(item, "fresh", shared_snapshot->fresh) == NULL) {
    goto fail; //Bool
    }
    }


    // shared_snapshot->sharing
    if(shared_snapshot->sharing) {
    cJSON *sharing_local_JSON = snapshot_sharing_convertToJSON(shared_snapshot->sharing);
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

shared_snapshot_t *shared_snapshot_parseFromJSON(cJSON *shared_snapshotJSON){

    shared_snapshot_t *shared_snapshot_local_var = NULL;

    // define the local variable for shared_snapshot->shared_by
    snapshot_owner_schema_t *shared_by_local_nonprim = NULL;

    // define the local variable for shared_snapshot->status
    snapshot_status_schema_t *status_local_nonprim = NULL;

    // define the local variable for shared_snapshot->sharing
    snapshot_sharing_t *sharing_local_nonprim = NULL;

    // shared_snapshot->shared_on
    cJSON *shared_on = cJSON_GetObjectItemCaseSensitive(shared_snapshotJSON, "sharedOn");
    if (cJSON_IsNull(shared_on)) {
        shared_on = NULL;
    }
    if (shared_on) { 
    if(!cJSON_IsString(shared_on) && !cJSON_IsNull(shared_on))
    {
    goto end; //DateTime
    }
    }

    // shared_snapshot->shared_with_member
    cJSON *shared_with_member = cJSON_GetObjectItemCaseSensitive(shared_snapshotJSON, "sharedWithMember");
    if (cJSON_IsNull(shared_with_member)) {
        shared_with_member = NULL;
    }
    if (shared_with_member) { 
    if(!cJSON_IsString(shared_with_member) && !cJSON_IsNull(shared_with_member))
    {
    goto end; //String
    }
    }

    // shared_snapshot->sharing_type
    cJSON *sharing_type = cJSON_GetObjectItemCaseSensitive(shared_snapshotJSON, "sharingType");
    if (cJSON_IsNull(sharing_type)) {
        sharing_type = NULL;
    }
    if (!sharing_type) {
        goto end;
    }

    corellium_api_shared_snapshot_SHARINGTYPE_e sharing_typeVariable;
    
    if(!cJSON_IsString(sharing_type))
    {
    goto end; //Enum
    }
    sharing_typeVariable = shared_snapshot_sharing_type_FromString(sharing_type->valuestring);

    // shared_snapshot->shared_by
    cJSON *shared_by = cJSON_GetObjectItemCaseSensitive(shared_snapshotJSON, "sharedBy");
    if (cJSON_IsNull(shared_by)) {
        shared_by = NULL;
    }
    if (shared_by) { 
    shared_by_local_nonprim = snapshot_owner_schema_parseFromJSON(shared_by); //nonprimitive
    }

    // shared_snapshot->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(shared_snapshotJSON, "id");
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

    // shared_snapshot->date
    cJSON *date = cJSON_GetObjectItemCaseSensitive(shared_snapshotJSON, "date");
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

    // shared_snapshot->hw_pac
    cJSON *hw_pac = cJSON_GetObjectItemCaseSensitive(shared_snapshotJSON, "hwPac");
    if (cJSON_IsNull(hw_pac)) {
        hw_pac = NULL;
    }
    if (!hw_pac) {
        goto end;
    }

    
    if(!cJSON_IsNumber(hw_pac))
    {
    goto end; //Numeric
    }

    // shared_snapshot->instance
    cJSON *instance = cJSON_GetObjectItemCaseSensitive(shared_snapshotJSON, "instance");
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

    // shared_snapshot->live
    cJSON *live = cJSON_GetObjectItemCaseSensitive(shared_snapshotJSON, "live");
    if (cJSON_IsNull(live)) {
        live = NULL;
    }
    if (live) { 
    if(!cJSON_IsBool(live))
    {
    goto end; //Bool
    }
    }

    // shared_snapshot->local
    cJSON *local = cJSON_GetObjectItemCaseSensitive(shared_snapshotJSON, "local");
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

    // shared_snapshot->model
    cJSON *model = cJSON_GetObjectItemCaseSensitive(shared_snapshotJSON, "model");
    if (cJSON_IsNull(model)) {
        model = NULL;
    }
    if (model) { 
    if(!cJSON_IsString(model) && !cJSON_IsNull(model))
    {
    goto end; //String
    }
    }

    // shared_snapshot->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(shared_snapshotJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (type) { 
    if(!cJSON_IsString(type) && !cJSON_IsNull(type))
    {
    goto end; //String
    }
    }

    // shared_snapshot->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(shared_snapshotJSON, "name");
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

    // shared_snapshot->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(shared_snapshotJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    status_local_nonprim = snapshot_status_schema_parseFromJSON(status); //nonprimitive

    // shared_snapshot->fresh
    cJSON *fresh = cJSON_GetObjectItemCaseSensitive(shared_snapshotJSON, "fresh");
    if (cJSON_IsNull(fresh)) {
        fresh = NULL;
    }
    if (fresh) { 
    if(!cJSON_IsBool(fresh))
    {
    goto end; //Bool
    }
    }

    // shared_snapshot->sharing
    cJSON *sharing = cJSON_GetObjectItemCaseSensitive(shared_snapshotJSON, "sharing");
    if (cJSON_IsNull(sharing)) {
        sharing = NULL;
    }
    if (sharing) { 
    sharing_local_nonprim = snapshot_sharing_parseFromJSON(sharing); //nonprimitive
    }


    shared_snapshot_local_var = shared_snapshot_create_internal (
        shared_on && !cJSON_IsNull(shared_on) ? strdup(shared_on->valuestring) : NULL,
        shared_with_member && !cJSON_IsNull(shared_with_member) ? strdup(shared_with_member->valuestring) : NULL,
        sharing_typeVariable,
        shared_by ? shared_by_local_nonprim : NULL,
        strdup(id->valuestring),
        date->valuedouble,
        hw_pac->valuedouble,
        strdup(instance->valuestring),
        live ? live->valueint : 0,
        local->valueint,
        model && !cJSON_IsNull(model) ? strdup(model->valuestring) : NULL,
        type && !cJSON_IsNull(type) ? strdup(type->valuestring) : NULL,
        strdup(name->valuestring),
        status_local_nonprim,
        fresh ? fresh->valueint : 0,
        sharing ? sharing_local_nonprim : NULL
        );

    return shared_snapshot_local_var;
end:
    if (shared_by_local_nonprim) {
        snapshot_owner_schema_free(shared_by_local_nonprim);
        shared_by_local_nonprim = NULL;
    }
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
