#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "enable_btrace_body.h"



static enable_btrace_body_t *enable_btrace_body_create_internal(
    list_t *ranges
    ) {
    enable_btrace_body_t *enable_btrace_body_local_var = malloc(sizeof(enable_btrace_body_t));
    if (!enable_btrace_body_local_var) {
        return NULL;
    }
    enable_btrace_body_local_var->ranges = ranges;

    enable_btrace_body_local_var->_library_owned = 1;
    return enable_btrace_body_local_var;
}

__attribute__((deprecated)) enable_btrace_body_t *enable_btrace_body_create(
    list_t *ranges
    ) {
    return enable_btrace_body_create_internal (
        ranges
        );
}

void enable_btrace_body_free(enable_btrace_body_t *enable_btrace_body) {
    if(NULL == enable_btrace_body){
        return ;
    }
    if(enable_btrace_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "enable_btrace_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (enable_btrace_body->ranges) {
        list_ForEach(listEntry, enable_btrace_body->ranges) {
            free(listEntry->data);
        }
        list_freeList(enable_btrace_body->ranges);
        enable_btrace_body->ranges = NULL;
    }
    free(enable_btrace_body);
}

cJSON *enable_btrace_body_convertToJSON(enable_btrace_body_t *enable_btrace_body) {
    cJSON *item = cJSON_CreateObject();

    // enable_btrace_body->ranges
    if(enable_btrace_body->ranges) {
    cJSON *ranges = cJSON_AddArrayToObject(item, "ranges");
    if(ranges == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *rangesListEntry;
    list_ForEach(rangesListEntry, enable_btrace_body->ranges) {
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

enable_btrace_body_t *enable_btrace_body_parseFromJSON(cJSON *enable_btrace_bodyJSON){

    enable_btrace_body_t *enable_btrace_body_local_var = NULL;

    // define the local list for enable_btrace_body->ranges
    list_t *rangesList = NULL;

    // enable_btrace_body->ranges
    cJSON *ranges = cJSON_GetObjectItemCaseSensitive(enable_btrace_bodyJSON, "ranges");
    if (cJSON_IsNull(ranges)) {
        ranges = NULL;
    }
    if (ranges) { 
    cJSON *ranges_local = NULL;
    if(!cJSON_IsArray(ranges)) {
        goto end;//primitive container
    }
    rangesList = list_createList();

    cJSON_ArrayForEach(ranges_local, ranges)
    {
    }
    }


    enable_btrace_body_local_var = enable_btrace_body_create_internal (
        ranges ? rangesList : NULL
        );

    return enable_btrace_body_local_var;
end:
    if (rangesList) {
        list_freeList(rangesList);
        rangesList = NULL;
    }
    return NULL;

}
