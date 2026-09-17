#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "model_firmware_springboard_snapshot.h"



static model_firmware_springboard_snapshot_t *model_firmware_springboard_snapshot_create_internal(
    list_t *volumes
    ) {
    model_firmware_springboard_snapshot_t *model_firmware_springboard_snapshot_local_var = malloc(sizeof(model_firmware_springboard_snapshot_t));
    if (!model_firmware_springboard_snapshot_local_var) {
        return NULL;
    }
    model_firmware_springboard_snapshot_local_var->volumes = volumes;

    model_firmware_springboard_snapshot_local_var->_library_owned = 1;
    return model_firmware_springboard_snapshot_local_var;
}

__attribute__((deprecated)) model_firmware_springboard_snapshot_t *model_firmware_springboard_snapshot_create(
    list_t *volumes
    ) {
    return model_firmware_springboard_snapshot_create_internal (
        volumes
        );
}

void model_firmware_springboard_snapshot_free(model_firmware_springboard_snapshot_t *model_firmware_springboard_snapshot) {
    if(NULL == model_firmware_springboard_snapshot){
        return ;
    }
    if(model_firmware_springboard_snapshot->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "model_firmware_springboard_snapshot_free");
        return ;
    }
    listEntry_t *listEntry;
    if (model_firmware_springboard_snapshot->volumes) {
        list_ForEach(listEntry, model_firmware_springboard_snapshot->volumes) {
            model_firmware_springboard_snapshot_volumes_inner_free(listEntry->data);
        }
        list_freeList(model_firmware_springboard_snapshot->volumes);
        model_firmware_springboard_snapshot->volumes = NULL;
    }
    free(model_firmware_springboard_snapshot);
}

cJSON *model_firmware_springboard_snapshot_convertToJSON(model_firmware_springboard_snapshot_t *model_firmware_springboard_snapshot) {
    cJSON *item = cJSON_CreateObject();

    // model_firmware_springboard_snapshot->volumes
    if (!model_firmware_springboard_snapshot->volumes) {
        goto fail;
    }
    cJSON *volumes = cJSON_AddArrayToObject(item, "volumes");
    if(volumes == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *volumesListEntry;
    if (model_firmware_springboard_snapshot->volumes) {
    list_ForEach(volumesListEntry, model_firmware_springboard_snapshot->volumes) {
    cJSON *itemLocal = model_firmware_springboard_snapshot_volumes_inner_convertToJSON(volumesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(volumes, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

model_firmware_springboard_snapshot_t *model_firmware_springboard_snapshot_parseFromJSON(cJSON *model_firmware_springboard_snapshotJSON){

    model_firmware_springboard_snapshot_t *model_firmware_springboard_snapshot_local_var = NULL;

    // define the local list for model_firmware_springboard_snapshot->volumes
    list_t *volumesList = NULL;

    // model_firmware_springboard_snapshot->volumes
    cJSON *volumes = cJSON_GetObjectItemCaseSensitive(model_firmware_springboard_snapshotJSON, "volumes");
    if (cJSON_IsNull(volumes)) {
        volumes = NULL;
    }
    if (!volumes) {
        goto end;
    }

    
    cJSON *volumes_local_nonprimitive = NULL;
    if(!cJSON_IsArray(volumes)){
        goto end; //nonprimitive container
    }

    volumesList = list_createList();

    cJSON_ArrayForEach(volumes_local_nonprimitive,volumes )
    {
        if(!cJSON_IsObject(volumes_local_nonprimitive)){
            goto end;
        }
        model_firmware_springboard_snapshot_volumes_inner_t *volumesItem = model_firmware_springboard_snapshot_volumes_inner_parseFromJSON(volumes_local_nonprimitive);

        list_addElement(volumesList, volumesItem);
    }


    model_firmware_springboard_snapshot_local_var = model_firmware_springboard_snapshot_create_internal (
        volumesList
        );

    return model_firmware_springboard_snapshot_local_var;
end:
    if (volumesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, volumesList) {
            model_firmware_springboard_snapshot_volumes_inner_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(volumesList);
        volumesList = NULL;
    }
    return NULL;

}
