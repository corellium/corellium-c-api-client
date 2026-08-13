#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "snapshot_request.h"



static snapshot_request_t *snapshot_request_create_internal(
    double limit,
    double offset,
    int springboard,
    int live,
    int fresh,
    char *device_name,
    char *task,
    char *to,
    char *from,
    char *order_by,
    char *search
    ) {
    snapshot_request_t *snapshot_request_local_var = malloc(sizeof(snapshot_request_t));
    if (!snapshot_request_local_var) {
        return NULL;
    }
    snapshot_request_local_var->limit = limit;
    snapshot_request_local_var->offset = offset;
    snapshot_request_local_var->springboard = springboard;
    snapshot_request_local_var->live = live;
    snapshot_request_local_var->fresh = fresh;
    snapshot_request_local_var->device_name = device_name;
    snapshot_request_local_var->task = task;
    snapshot_request_local_var->to = to;
    snapshot_request_local_var->from = from;
    snapshot_request_local_var->order_by = order_by;
    snapshot_request_local_var->search = search;

    snapshot_request_local_var->_library_owned = 1;
    return snapshot_request_local_var;
}

__attribute__((deprecated)) snapshot_request_t *snapshot_request_create(
    double limit,
    double offset,
    int springboard,
    int live,
    int fresh,
    char *device_name,
    char *task,
    char *to,
    char *from,
    char *order_by,
    char *search
    ) {
    return snapshot_request_create_internal (
        limit,
        offset,
        springboard,
        live,
        fresh,
        device_name,
        task,
        to,
        from,
        order_by,
        search
        );
}

void snapshot_request_free(snapshot_request_t *snapshot_request) {
    if(NULL == snapshot_request){
        return ;
    }
    if(snapshot_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "snapshot_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (snapshot_request->device_name) {
        free(snapshot_request->device_name);
        snapshot_request->device_name = NULL;
    }
    if (snapshot_request->task) {
        free(snapshot_request->task);
        snapshot_request->task = NULL;
    }
    if (snapshot_request->to) {
        free(snapshot_request->to);
        snapshot_request->to = NULL;
    }
    if (snapshot_request->from) {
        free(snapshot_request->from);
        snapshot_request->from = NULL;
    }
    if (snapshot_request->order_by) {
        free(snapshot_request->order_by);
        snapshot_request->order_by = NULL;
    }
    if (snapshot_request->search) {
        free(snapshot_request->search);
        snapshot_request->search = NULL;
    }
    free(snapshot_request);
}

cJSON *snapshot_request_convertToJSON(snapshot_request_t *snapshot_request) {
    cJSON *item = cJSON_CreateObject();

    // snapshot_request->limit
    if(snapshot_request->limit) {
    if(cJSON_AddNumberToObject(item, "limit", snapshot_request->limit) == NULL) {
    goto fail; //Numeric
    }
    }


    // snapshot_request->offset
    if(snapshot_request->offset) {
    if(cJSON_AddNumberToObject(item, "offset", snapshot_request->offset) == NULL) {
    goto fail; //Numeric
    }
    }


    // snapshot_request->springboard
    if(snapshot_request->springboard) {
    if(cJSON_AddBoolToObject(item, "springboard", snapshot_request->springboard) == NULL) {
    goto fail; //Bool
    }
    }


    // snapshot_request->live
    if(snapshot_request->live) {
    if(cJSON_AddBoolToObject(item, "live", snapshot_request->live) == NULL) {
    goto fail; //Bool
    }
    }


    // snapshot_request->fresh
    if(snapshot_request->fresh) {
    if(cJSON_AddBoolToObject(item, "fresh", snapshot_request->fresh) == NULL) {
    goto fail; //Bool
    }
    }


    // snapshot_request->device_name
    if(snapshot_request->device_name) {
    if(cJSON_AddStringToObject(item, "deviceName", snapshot_request->device_name) == NULL) {
    goto fail; //String
    }
    }


    // snapshot_request->task
    if(snapshot_request->task) {
    if(cJSON_AddStringToObject(item, "task", snapshot_request->task) == NULL) {
    goto fail; //String
    }
    }


    // snapshot_request->to
    if(snapshot_request->to) {
    if(cJSON_AddStringToObject(item, "to", snapshot_request->to) == NULL) {
    goto fail; //String
    }
    }


    // snapshot_request->from
    if(snapshot_request->from) {
    if(cJSON_AddStringToObject(item, "from", snapshot_request->from) == NULL) {
    goto fail; //String
    }
    }


    // snapshot_request->order_by
    if(snapshot_request->order_by) {
    if(cJSON_AddStringToObject(item, "orderBy", snapshot_request->order_by) == NULL) {
    goto fail; //String
    }
    }


    // snapshot_request->search
    if(snapshot_request->search) {
    if(cJSON_AddStringToObject(item, "search", snapshot_request->search) == NULL) {
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

snapshot_request_t *snapshot_request_parseFromJSON(cJSON *snapshot_requestJSON){

    snapshot_request_t *snapshot_request_local_var = NULL;

    // snapshot_request->limit
    cJSON *limit = cJSON_GetObjectItemCaseSensitive(snapshot_requestJSON, "limit");
    if (cJSON_IsNull(limit)) {
        limit = NULL;
    }
    if (limit) { 
    if(!cJSON_IsNumber(limit))
    {
    goto end; //Numeric
    }
    }

    // snapshot_request->offset
    cJSON *offset = cJSON_GetObjectItemCaseSensitive(snapshot_requestJSON, "offset");
    if (cJSON_IsNull(offset)) {
        offset = NULL;
    }
    if (offset) { 
    if(!cJSON_IsNumber(offset))
    {
    goto end; //Numeric
    }
    }

    // snapshot_request->springboard
    cJSON *springboard = cJSON_GetObjectItemCaseSensitive(snapshot_requestJSON, "springboard");
    if (cJSON_IsNull(springboard)) {
        springboard = NULL;
    }
    if (springboard) { 
    if(!cJSON_IsBool(springboard))
    {
    goto end; //Bool
    }
    }

    // snapshot_request->live
    cJSON *live = cJSON_GetObjectItemCaseSensitive(snapshot_requestJSON, "live");
    if (cJSON_IsNull(live)) {
        live = NULL;
    }
    if (live) { 
    if(!cJSON_IsBool(live))
    {
    goto end; //Bool
    }
    }

    // snapshot_request->fresh
    cJSON *fresh = cJSON_GetObjectItemCaseSensitive(snapshot_requestJSON, "fresh");
    if (cJSON_IsNull(fresh)) {
        fresh = NULL;
    }
    if (fresh) { 
    if(!cJSON_IsBool(fresh))
    {
    goto end; //Bool
    }
    }

    // snapshot_request->device_name
    cJSON *device_name = cJSON_GetObjectItemCaseSensitive(snapshot_requestJSON, "deviceName");
    if (cJSON_IsNull(device_name)) {
        device_name = NULL;
    }
    if (device_name) { 
    if(!cJSON_IsString(device_name) && !cJSON_IsNull(device_name))
    {
    goto end; //String
    }
    }

    // snapshot_request->task
    cJSON *task = cJSON_GetObjectItemCaseSensitive(snapshot_requestJSON, "task");
    if (cJSON_IsNull(task)) {
        task = NULL;
    }
    if (task) { 
    if(!cJSON_IsString(task) && !cJSON_IsNull(task))
    {
    goto end; //String
    }
    }

    // snapshot_request->to
    cJSON *to = cJSON_GetObjectItemCaseSensitive(snapshot_requestJSON, "to");
    if (cJSON_IsNull(to)) {
        to = NULL;
    }
    if (to) { 
    if(!cJSON_IsString(to) && !cJSON_IsNull(to))
    {
    goto end; //String
    }
    }

    // snapshot_request->from
    cJSON *from = cJSON_GetObjectItemCaseSensitive(snapshot_requestJSON, "from");
    if (cJSON_IsNull(from)) {
        from = NULL;
    }
    if (from) { 
    if(!cJSON_IsString(from) && !cJSON_IsNull(from))
    {
    goto end; //String
    }
    }

    // snapshot_request->order_by
    cJSON *order_by = cJSON_GetObjectItemCaseSensitive(snapshot_requestJSON, "orderBy");
    if (cJSON_IsNull(order_by)) {
        order_by = NULL;
    }
    if (order_by) { 
    if(!cJSON_IsString(order_by) && !cJSON_IsNull(order_by))
    {
    goto end; //String
    }
    }

    // snapshot_request->search
    cJSON *search = cJSON_GetObjectItemCaseSensitive(snapshot_requestJSON, "search");
    if (cJSON_IsNull(search)) {
        search = NULL;
    }
    if (search) { 
    if(!cJSON_IsString(search) && !cJSON_IsNull(search))
    {
    goto end; //String
    }
    }


    snapshot_request_local_var = snapshot_request_create_internal (
        limit ? limit->valuedouble : 0,
        offset ? offset->valuedouble : 0,
        springboard ? springboard->valueint : 0,
        live ? live->valueint : 0,
        fresh ? fresh->valueint : 0,
        device_name && !cJSON_IsNull(device_name) ? strdup(device_name->valuestring) : NULL,
        task && !cJSON_IsNull(task) ? strdup(task->valuestring) : NULL,
        to && !cJSON_IsNull(to) ? strdup(to->valuestring) : NULL,
        from && !cJSON_IsNull(from) ? strdup(from->valuestring) : NULL,
        order_by && !cJSON_IsNull(order_by) ? strdup(order_by->valuestring) : NULL,
        search && !cJSON_IsNull(search) ? strdup(search->valuestring) : NULL
        );

    return snapshot_request_local_var;
end:
    return NULL;

}
