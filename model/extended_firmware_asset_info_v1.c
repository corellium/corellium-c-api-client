#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "extended_firmware_asset_info_v1.h"



static extended_firmware_asset_info_v1_t *extended_firmware_asset_info_v1_create_internal(
    list_t *firmwares,
    list_t *instances
    ) {
    extended_firmware_asset_info_v1_t *extended_firmware_asset_info_v1_local_var = malloc(sizeof(extended_firmware_asset_info_v1_t));
    if (!extended_firmware_asset_info_v1_local_var) {
        return NULL;
    }
    extended_firmware_asset_info_v1_local_var->firmwares = firmwares;
    extended_firmware_asset_info_v1_local_var->instances = instances;

    extended_firmware_asset_info_v1_local_var->_library_owned = 1;
    return extended_firmware_asset_info_v1_local_var;
}

__attribute__((deprecated)) extended_firmware_asset_info_v1_t *extended_firmware_asset_info_v1_create(
    list_t *firmwares,
    list_t *instances
    ) {
    return extended_firmware_asset_info_v1_create_internal (
        firmwares,
        instances
        );
}

void extended_firmware_asset_info_v1_free(extended_firmware_asset_info_v1_t *extended_firmware_asset_info_v1) {
    if(NULL == extended_firmware_asset_info_v1){
        return ;
    }
    if(extended_firmware_asset_info_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "extended_firmware_asset_info_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (extended_firmware_asset_info_v1->firmwares) {
        list_ForEach(listEntry, extended_firmware_asset_info_v1->firmwares) {
            free(listEntry->data);
        }
        list_freeList(extended_firmware_asset_info_v1->firmwares);
        extended_firmware_asset_info_v1->firmwares = NULL;
    }
    if (extended_firmware_asset_info_v1->instances) {
        list_ForEach(listEntry, extended_firmware_asset_info_v1->instances) {
            free(listEntry->data);
        }
        list_freeList(extended_firmware_asset_info_v1->instances);
        extended_firmware_asset_info_v1->instances = NULL;
    }
    free(extended_firmware_asset_info_v1);
}

cJSON *extended_firmware_asset_info_v1_convertToJSON(extended_firmware_asset_info_v1_t *extended_firmware_asset_info_v1) {
    cJSON *item = cJSON_CreateObject();

    // extended_firmware_asset_info_v1->firmwares
    if (!extended_firmware_asset_info_v1->firmwares) {
        goto fail;
    }
    cJSON *firmwares = cJSON_AddArrayToObject(item, "firmwares");
    if(firmwares == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *firmwaresListEntry;
    list_ForEach(firmwaresListEntry, extended_firmware_asset_info_v1->firmwares) {
    if(cJSON_AddStringToObject(firmwares, "", firmwaresListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // extended_firmware_asset_info_v1->instances
    if (!extended_firmware_asset_info_v1->instances) {
        goto fail;
    }
    cJSON *instances = cJSON_AddArrayToObject(item, "instances");
    if(instances == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *instancesListEntry;
    list_ForEach(instancesListEntry, extended_firmware_asset_info_v1->instances) {
    if(cJSON_AddStringToObject(instances, "", instancesListEntry->data) == NULL)
    {
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

extended_firmware_asset_info_v1_t *extended_firmware_asset_info_v1_parseFromJSON(cJSON *extended_firmware_asset_info_v1JSON){

    extended_firmware_asset_info_v1_t *extended_firmware_asset_info_v1_local_var = NULL;

    // define the local list for extended_firmware_asset_info_v1->firmwares
    list_t *firmwaresList = NULL;

    // define the local list for extended_firmware_asset_info_v1->instances
    list_t *instancesList = NULL;

    // extended_firmware_asset_info_v1->firmwares
    cJSON *firmwares = cJSON_GetObjectItemCaseSensitive(extended_firmware_asset_info_v1JSON, "firmwares");
    if (cJSON_IsNull(firmwares)) {
        firmwares = NULL;
    }
    if (!firmwares) {
        goto end;
    }

    
    cJSON *firmwares_local = NULL;
    if(!cJSON_IsArray(firmwares)) {
        goto end;//primitive container
    }
    firmwaresList = list_createList();

    cJSON_ArrayForEach(firmwares_local, firmwares)
    {
        if(!cJSON_IsString(firmwares_local))
        {
            goto end;
        }
        list_addElement(firmwaresList , strdup(firmwares_local->valuestring));
    }

    // extended_firmware_asset_info_v1->instances
    cJSON *instances = cJSON_GetObjectItemCaseSensitive(extended_firmware_asset_info_v1JSON, "instances");
    if (cJSON_IsNull(instances)) {
        instances = NULL;
    }
    if (!instances) {
        goto end;
    }

    
    cJSON *instances_local = NULL;
    if(!cJSON_IsArray(instances)) {
        goto end;//primitive container
    }
    instancesList = list_createList();

    cJSON_ArrayForEach(instances_local, instances)
    {
        if(!cJSON_IsString(instances_local))
        {
            goto end;
        }
        list_addElement(instancesList , strdup(instances_local->valuestring));
    }


    extended_firmware_asset_info_v1_local_var = extended_firmware_asset_info_v1_create_internal (
        firmwaresList,
        instancesList
        );

    return extended_firmware_asset_info_v1_local_var;
end:
    if (firmwaresList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, firmwaresList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(firmwaresList);
        firmwaresList = NULL;
    }
    if (instancesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, instancesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(instancesList);
        instancesList = NULL;
    }
    return NULL;

}
