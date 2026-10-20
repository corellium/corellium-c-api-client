#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "activity_resource_not_starts_with_filter.h"



static activity_resource_not_starts_with_filter_t *activity_resource_not_starts_with_filter_create_internal(
    object_t *starts_with
    ) {
    activity_resource_not_starts_with_filter_t *activity_resource_not_starts_with_filter_local_var = malloc(sizeof(activity_resource_not_starts_with_filter_t));
    if (!activity_resource_not_starts_with_filter_local_var) {
        return NULL;
    }
    activity_resource_not_starts_with_filter_local_var->starts_with = starts_with;

    activity_resource_not_starts_with_filter_local_var->_library_owned = 1;
    return activity_resource_not_starts_with_filter_local_var;
}

__attribute__((deprecated)) activity_resource_not_starts_with_filter_t *activity_resource_not_starts_with_filter_create(
    object_t *starts_with
    ) {
    return activity_resource_not_starts_with_filter_create_internal (
        starts_with
        );
}

void activity_resource_not_starts_with_filter_free(activity_resource_not_starts_with_filter_t *activity_resource_not_starts_with_filter) {
    if(NULL == activity_resource_not_starts_with_filter){
        return ;
    }
    if(activity_resource_not_starts_with_filter->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "activity_resource_not_starts_with_filter_free");
        return ;
    }
    listEntry_t *listEntry;
    if (activity_resource_not_starts_with_filter->starts_with) {
        object_free(activity_resource_not_starts_with_filter->starts_with);
        activity_resource_not_starts_with_filter->starts_with = NULL;
    }
    free(activity_resource_not_starts_with_filter);
}

cJSON *activity_resource_not_starts_with_filter_convertToJSON(activity_resource_not_starts_with_filter_t *activity_resource_not_starts_with_filter) {
    cJSON *item = cJSON_CreateObject();

    // activity_resource_not_starts_with_filter->starts_with
    if (!activity_resource_not_starts_with_filter->starts_with) {
        goto fail;
    }
    cJSON *starts_with_object = object_convertToJSON(activity_resource_not_starts_with_filter->starts_with);
    if(starts_with_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "!startsWith", starts_with_object);
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

activity_resource_not_starts_with_filter_t *activity_resource_not_starts_with_filter_parseFromJSON(cJSON *activity_resource_not_starts_with_filterJSON){

    activity_resource_not_starts_with_filter_t *activity_resource_not_starts_with_filter_local_var = NULL;

    // activity_resource_not_starts_with_filter->starts_with
    cJSON *starts_with = cJSON_GetObjectItemCaseSensitive(activity_resource_not_starts_with_filterJSON, "!startsWith");
    if (cJSON_IsNull(starts_with)) {
        starts_with = NULL;
    }
    if (!starts_with) {
        goto end;
    }

    object_t *starts_with_local_object = NULL;
    
    starts_with_local_object = object_parseFromJSON(starts_with); //object


    activity_resource_not_starts_with_filter_local_var = activity_resource_not_starts_with_filter_create_internal (
        starts_with_local_object
        );

    return activity_resource_not_starts_with_filter_local_var;
end:
    return NULL;

}
