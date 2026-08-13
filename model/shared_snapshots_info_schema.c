#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "shared_snapshots_info_schema.h"


char* shared_snapshots_info_schema_sharing_type_ToString(corellium_api_shared_snapshots_info_schema_SHARINGTYPE_e sharing_type) {
    char* sharing_typeArray[] =  { "NULL", "publicLink", "domainRestrictedLink", "passwordPublicLink", "emailInvite", "notShared" };
    return sharing_typeArray[sharing_type];
}

corellium_api_shared_snapshots_info_schema_SHARINGTYPE_e shared_snapshots_info_schema_sharing_type_FromString(char* sharing_type){
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

static shared_snapshots_info_schema_t *shared_snapshots_info_schema_create_internal(
    char *shared_on,
    char *shared_with_member,
    corellium_api_shared_snapshots_info_schema_SHARINGTYPE_e sharing_type,
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
    shared_snapshots_info_schema_t *shared_snapshots_info_schema_local_var = malloc(sizeof(shared_snapshots_info_schema_t));
    if (!shared_snapshots_info_schema_local_var) {
        return NULL;
    }
    shared_snapshots_info_schema_local_var->shared_on = shared_on;
    shared_snapshots_info_schema_local_var->shared_with_member = shared_with_member;
    shared_snapshots_info_schema_local_var->sharing_type = sharing_type;
    shared_snapshots_info_schema_local_var->shared_by = shared_by;
    shared_snapshots_info_schema_local_var->id = id;
    shared_snapshots_info_schema_local_var->date = date;
    shared_snapshots_info_schema_local_var->hw_pac = hw_pac;
    shared_snapshots_info_schema_local_var->instance = instance;
    shared_snapshots_info_schema_local_var->live = live;
    shared_snapshots_info_schema_local_var->local = local;
    shared_snapshots_info_schema_local_var->model = model;
    shared_snapshots_info_schema_local_var->type = type;
    shared_snapshots_info_schema_local_var->name = name;
    shared_snapshots_info_schema_local_var->status = status;
    shared_snapshots_info_schema_local_var->fresh = fresh;
    shared_snapshots_info_schema_local_var->sharing = sharing;

    shared_snapshots_info_schema_local_var->_library_owned = 1;
    return shared_snapshots_info_schema_local_var;
}

__attribute__((deprecated)) shared_snapshots_info_schema_t *shared_snapshots_info_schema_create(
    char *shared_on,
    char *shared_with_member,
    corellium_api_shared_snapshots_info_schema_SHARINGTYPE_e sharing_type,
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
    return shared_snapshots_info_schema_create_internal (
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

void shared_snapshots_info_schema_free(shared_snapshots_info_schema_t *shared_snapshots_info_schema) {
    if(NULL == shared_snapshots_info_schema){
        return ;
    }
    if(shared_snapshots_info_schema->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "shared_snapshots_info_schema_free");
        return ;
    }
    listEntry_t *listEntry;
    if (shared_snapshots_info_schema->shared_on) {
        free(shared_snapshots_info_schema->shared_on);
        shared_snapshots_info_schema->shared_on = NULL;
    }
    if (shared_snapshots_info_schema->shared_with_member) {
        free(shared_snapshots_info_schema->shared_with_member);
        shared_snapshots_info_schema->shared_with_member = NULL;
    }
    if (shared_snapshots_info_schema->shared_by) {
        snapshot_owner_schema_free(shared_snapshots_info_schema->shared_by);
        shared_snapshots_info_schema->shared_by = NULL;
    }
    if (shared_snapshots_info_schema->id) {
        free(shared_snapshots_info_schema->id);
        shared_snapshots_info_schema->id = NULL;
    }
    if (shared_snapshots_info_schema->instance) {
        free(shared_snapshots_info_schema->instance);
        shared_snapshots_info_schema->instance = NULL;
    }
    if (shared_snapshots_info_schema->model) {
        free(shared_snapshots_info_schema->model);
        shared_snapshots_info_schema->model = NULL;
    }
    if (shared_snapshots_info_schema->type) {
        free(shared_snapshots_info_schema->type);
        shared_snapshots_info_schema->type = NULL;
    }
    if (shared_snapshots_info_schema->name) {
        free(shared_snapshots_info_schema->name);
        shared_snapshots_info_schema->name = NULL;
    }
    if (shared_snapshots_info_schema->status) {
        snapshot_status_schema_free(shared_snapshots_info_schema->status);
        shared_snapshots_info_schema->status = NULL;
    }
    if (shared_snapshots_info_schema->sharing) {
        snapshot_sharing_free(shared_snapshots_info_schema->sharing);
        shared_snapshots_info_schema->sharing = NULL;
    }
    free(shared_snapshots_info_schema);
}

cJSON *shared_snapshots_info_schema_convertToJSON(shared_snapshots_info_schema_t *shared_snapshots_info_schema) {
    cJSON *item = cJSON_CreateObject();

    // shared_snapshots_info_schema->shared_on
    if(shared_snapshots_info_schema->shared_on) {
    if(cJSON_AddStringToObject(item, "sharedOn", shared_snapshots_info_schema->shared_on) == NULL) {
    goto fail; //Date-Time
    }
    }


    // shared_snapshots_info_schema->shared_with_member
    if(shared_snapshots_info_schema->shared_with_member) {
    if(cJSON_AddStringToObject(item, "sharedWithMember", shared_snapshots_info_schema->shared_with_member) == NULL) {
    goto fail; //String
    }
    }


    // shared_snapshots_info_schema->sharing_type
    if (corellium_api_shared_snapshots_info_schema_SHARINGTYPE_NULL == shared_snapshots_info_schema->sharing_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sharingType", shared_snapshots_info_schema_sharing_type_ToString(shared_snapshots_info_schema->sharing_type)) == NULL)
    {
    goto fail; //Enum
    }


    // shared_snapshots_info_schema->shared_by
    if(shared_snapshots_info_schema->shared_by) {
    cJSON *shared_by_local_JSON = snapshot_owner_schema_convertToJSON(shared_snapshots_info_schema->shared_by);
    if(shared_by_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "sharedBy", shared_by_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // shared_snapshots_info_schema->id
    if (!shared_snapshots_info_schema->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", shared_snapshots_info_schema->id) == NULL) {
    goto fail; //String
    }


    // shared_snapshots_info_schema->date
    if (!shared_snapshots_info_schema->date) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "date", shared_snapshots_info_schema->date) == NULL) {
    goto fail; //Numeric
    }


    // shared_snapshots_info_schema->hw_pac
    if (!shared_snapshots_info_schema->hw_pac) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "hwPac", shared_snapshots_info_schema->hw_pac) == NULL) {
    goto fail; //Numeric
    }


    // shared_snapshots_info_schema->instance
    if (!shared_snapshots_info_schema->instance) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "instance", shared_snapshots_info_schema->instance) == NULL) {
    goto fail; //String
    }


    // shared_snapshots_info_schema->live
    if(shared_snapshots_info_schema->live) {
    if(cJSON_AddBoolToObject(item, "live", shared_snapshots_info_schema->live) == NULL) {
    goto fail; //Bool
    }
    }


    // shared_snapshots_info_schema->local
    if (!shared_snapshots_info_schema->local) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "local", shared_snapshots_info_schema->local) == NULL) {
    goto fail; //Bool
    }


    // shared_snapshots_info_schema->model
    if(shared_snapshots_info_schema->model) {
    if(cJSON_AddStringToObject(item, "model", shared_snapshots_info_schema->model) == NULL) {
    goto fail; //String
    }
    }


    // shared_snapshots_info_schema->type
    if(shared_snapshots_info_schema->type) {
    if(cJSON_AddStringToObject(item, "type", shared_snapshots_info_schema->type) == NULL) {
    goto fail; //String
    }
    }


    // shared_snapshots_info_schema->name
    if (!shared_snapshots_info_schema->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", shared_snapshots_info_schema->name) == NULL) {
    goto fail; //String
    }


    // shared_snapshots_info_schema->status
    if (!shared_snapshots_info_schema->status) {
        goto fail;
    }
    cJSON *status_local_JSON = snapshot_status_schema_convertToJSON(shared_snapshots_info_schema->status);
    if(status_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // shared_snapshots_info_schema->fresh
    if(shared_snapshots_info_schema->fresh) {
    if(cJSON_AddBoolToObject(item, "fresh", shared_snapshots_info_schema->fresh) == NULL) {
    goto fail; //Bool
    }
    }


    // shared_snapshots_info_schema->sharing
    if(shared_snapshots_info_schema->sharing) {
    cJSON *sharing_local_JSON = snapshot_sharing_convertToJSON(shared_snapshots_info_schema->sharing);
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

shared_snapshots_info_schema_t *shared_snapshots_info_schema_parseFromJSON(cJSON *shared_snapshots_info_schemaJSON){

    shared_snapshots_info_schema_t *shared_snapshots_info_schema_local_var = NULL;

    // define the local variable for shared_snapshots_info_schema->shared_by
    snapshot_owner_schema_t *shared_by_local_nonprim = NULL;

    // define the local variable for shared_snapshots_info_schema->status
    snapshot_status_schema_t *status_local_nonprim = NULL;

    // define the local variable for shared_snapshots_info_schema->sharing
    snapshot_sharing_t *sharing_local_nonprim = NULL;

    // shared_snapshots_info_schema->shared_on
    cJSON *shared_on = cJSON_GetObjectItemCaseSensitive(shared_snapshots_info_schemaJSON, "sharedOn");
    if (cJSON_IsNull(shared_on)) {
        shared_on = NULL;
    }
    if (shared_on) { 
    if(!cJSON_IsString(shared_on) && !cJSON_IsNull(shared_on))
    {
    goto end; //DateTime
    }
    }

    // shared_snapshots_info_schema->shared_with_member
    cJSON *shared_with_member = cJSON_GetObjectItemCaseSensitive(shared_snapshots_info_schemaJSON, "sharedWithMember");
    if (cJSON_IsNull(shared_with_member)) {
        shared_with_member = NULL;
    }
    if (shared_with_member) { 
    if(!cJSON_IsString(shared_with_member) && !cJSON_IsNull(shared_with_member))
    {
    goto end; //String
    }
    }

    // shared_snapshots_info_schema->sharing_type
    cJSON *sharing_type = cJSON_GetObjectItemCaseSensitive(shared_snapshots_info_schemaJSON, "sharingType");
    if (cJSON_IsNull(sharing_type)) {
        sharing_type = NULL;
    }
    if (!sharing_type) {
        goto end;
    }

    corellium_api_shared_snapshots_info_schema_SHARINGTYPE_e sharing_typeVariable;
    
    if(!cJSON_IsString(sharing_type))
    {
    goto end; //Enum
    }
    sharing_typeVariable = shared_snapshots_info_schema_sharing_type_FromString(sharing_type->valuestring);

    // shared_snapshots_info_schema->shared_by
    cJSON *shared_by = cJSON_GetObjectItemCaseSensitive(shared_snapshots_info_schemaJSON, "sharedBy");
    if (cJSON_IsNull(shared_by)) {
        shared_by = NULL;
    }
    if (shared_by) { 
    shared_by_local_nonprim = snapshot_owner_schema_parseFromJSON(shared_by); //nonprimitive
    }

    // shared_snapshots_info_schema->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(shared_snapshots_info_schemaJSON, "id");
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

    // shared_snapshots_info_schema->date
    cJSON *date = cJSON_GetObjectItemCaseSensitive(shared_snapshots_info_schemaJSON, "date");
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

    // shared_snapshots_info_schema->hw_pac
    cJSON *hw_pac = cJSON_GetObjectItemCaseSensitive(shared_snapshots_info_schemaJSON, "hwPac");
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

    // shared_snapshots_info_schema->instance
    cJSON *instance = cJSON_GetObjectItemCaseSensitive(shared_snapshots_info_schemaJSON, "instance");
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

    // shared_snapshots_info_schema->live
    cJSON *live = cJSON_GetObjectItemCaseSensitive(shared_snapshots_info_schemaJSON, "live");
    if (cJSON_IsNull(live)) {
        live = NULL;
    }
    if (live) { 
    if(!cJSON_IsBool(live))
    {
    goto end; //Bool
    }
    }

    // shared_snapshots_info_schema->local
    cJSON *local = cJSON_GetObjectItemCaseSensitive(shared_snapshots_info_schemaJSON, "local");
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

    // shared_snapshots_info_schema->model
    cJSON *model = cJSON_GetObjectItemCaseSensitive(shared_snapshots_info_schemaJSON, "model");
    if (cJSON_IsNull(model)) {
        model = NULL;
    }
    if (model) { 
    if(!cJSON_IsString(model) && !cJSON_IsNull(model))
    {
    goto end; //String
    }
    }

    // shared_snapshots_info_schema->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(shared_snapshots_info_schemaJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (type) { 
    if(!cJSON_IsString(type) && !cJSON_IsNull(type))
    {
    goto end; //String
    }
    }

    // shared_snapshots_info_schema->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(shared_snapshots_info_schemaJSON, "name");
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

    // shared_snapshots_info_schema->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(shared_snapshots_info_schemaJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    status_local_nonprim = snapshot_status_schema_parseFromJSON(status); //nonprimitive

    // shared_snapshots_info_schema->fresh
    cJSON *fresh = cJSON_GetObjectItemCaseSensitive(shared_snapshots_info_schemaJSON, "fresh");
    if (cJSON_IsNull(fresh)) {
        fresh = NULL;
    }
    if (fresh) { 
    if(!cJSON_IsBool(fresh))
    {
    goto end; //Bool
    }
    }

    // shared_snapshots_info_schema->sharing
    cJSON *sharing = cJSON_GetObjectItemCaseSensitive(shared_snapshots_info_schemaJSON, "sharing");
    if (cJSON_IsNull(sharing)) {
        sharing = NULL;
    }
    if (sharing) { 
    sharing_local_nonprim = snapshot_sharing_parseFromJSON(sharing); //nonprimitive
    }


    shared_snapshots_info_schema_local_var = shared_snapshots_info_schema_create_internal (
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

    return shared_snapshots_info_schema_local_var;
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
