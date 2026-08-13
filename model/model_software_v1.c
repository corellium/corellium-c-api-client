#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "model_software_v1.h"



static model_software_v1_t *model_software_v1_create_internal(
    char *name,
    char *board_config,
    char *platform,
    double cpid,
    double bdid,
    list_t *firmwares
    ) {
    model_software_v1_t *model_software_v1_local_var = malloc(sizeof(model_software_v1_t));
    if (!model_software_v1_local_var) {
        return NULL;
    }
    model_software_v1_local_var->name = name;
    model_software_v1_local_var->board_config = board_config;
    model_software_v1_local_var->platform = platform;
    model_software_v1_local_var->cpid = cpid;
    model_software_v1_local_var->bdid = bdid;
    model_software_v1_local_var->firmwares = firmwares;

    model_software_v1_local_var->_library_owned = 1;
    return model_software_v1_local_var;
}

__attribute__((deprecated)) model_software_v1_t *model_software_v1_create(
    char *name,
    char *board_config,
    char *platform,
    double cpid,
    double bdid,
    list_t *firmwares
    ) {
    return model_software_v1_create_internal (
        name,
        board_config,
        platform,
        cpid,
        bdid,
        firmwares
        );
}

void model_software_v1_free(model_software_v1_t *model_software_v1) {
    if(NULL == model_software_v1){
        return ;
    }
    if(model_software_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "model_software_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (model_software_v1->name) {
        free(model_software_v1->name);
        model_software_v1->name = NULL;
    }
    if (model_software_v1->board_config) {
        free(model_software_v1->board_config);
        model_software_v1->board_config = NULL;
    }
    if (model_software_v1->platform) {
        free(model_software_v1->platform);
        model_software_v1->platform = NULL;
    }
    if (model_software_v1->firmwares) {
        list_ForEach(listEntry, model_software_v1->firmwares) {
            firmware_v1_free(listEntry->data);
        }
        list_freeList(model_software_v1->firmwares);
        model_software_v1->firmwares = NULL;
    }
    free(model_software_v1);
}

cJSON *model_software_v1_convertToJSON(model_software_v1_t *model_software_v1) {
    cJSON *item = cJSON_CreateObject();

    // model_software_v1->name
    if(model_software_v1->name) {
    if(cJSON_AddStringToObject(item, "name", model_software_v1->name) == NULL) {
    goto fail; //String
    }
    }


    // model_software_v1->board_config
    if(model_software_v1->board_config) {
    if(cJSON_AddStringToObject(item, "boardConfig", model_software_v1->board_config) == NULL) {
    goto fail; //String
    }
    }


    // model_software_v1->platform
    if(model_software_v1->platform) {
    if(cJSON_AddStringToObject(item, "platform", model_software_v1->platform) == NULL) {
    goto fail; //String
    }
    }


    // model_software_v1->cpid
    if(model_software_v1->cpid) {
    if(cJSON_AddNumberToObject(item, "cpid", model_software_v1->cpid) == NULL) {
    goto fail; //Numeric
    }
    }


    // model_software_v1->bdid
    if(model_software_v1->bdid) {
    if(cJSON_AddNumberToObject(item, "bdid", model_software_v1->bdid) == NULL) {
    goto fail; //Numeric
    }
    }


    // model_software_v1->firmwares
    if(model_software_v1->firmwares) {
    cJSON *firmwares = cJSON_AddArrayToObject(item, "firmwares");
    if(firmwares == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *firmwaresListEntry;
    if (model_software_v1->firmwares) {
    list_ForEach(firmwaresListEntry, model_software_v1->firmwares) {
    cJSON *itemLocal = firmware_v1_convertToJSON(firmwaresListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(firmwares, itemLocal);
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

model_software_v1_t *model_software_v1_parseFromJSON(cJSON *model_software_v1JSON){

    model_software_v1_t *model_software_v1_local_var = NULL;

    // define the local list for model_software_v1->firmwares
    list_t *firmwaresList = NULL;

    // model_software_v1->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(model_software_v1JSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // model_software_v1->board_config
    cJSON *board_config = cJSON_GetObjectItemCaseSensitive(model_software_v1JSON, "boardConfig");
    if (cJSON_IsNull(board_config)) {
        board_config = NULL;
    }
    if (board_config) { 
    if(!cJSON_IsString(board_config) && !cJSON_IsNull(board_config))
    {
    goto end; //String
    }
    }

    // model_software_v1->platform
    cJSON *platform = cJSON_GetObjectItemCaseSensitive(model_software_v1JSON, "platform");
    if (cJSON_IsNull(platform)) {
        platform = NULL;
    }
    if (platform) { 
    if(!cJSON_IsString(platform) && !cJSON_IsNull(platform))
    {
    goto end; //String
    }
    }

    // model_software_v1->cpid
    cJSON *cpid = cJSON_GetObjectItemCaseSensitive(model_software_v1JSON, "cpid");
    if (cJSON_IsNull(cpid)) {
        cpid = NULL;
    }
    if (cpid) { 
    if(!cJSON_IsNumber(cpid))
    {
    goto end; //Numeric
    }
    }

    // model_software_v1->bdid
    cJSON *bdid = cJSON_GetObjectItemCaseSensitive(model_software_v1JSON, "bdid");
    if (cJSON_IsNull(bdid)) {
        bdid = NULL;
    }
    if (bdid) { 
    if(!cJSON_IsNumber(bdid))
    {
    goto end; //Numeric
    }
    }

    // model_software_v1->firmwares
    cJSON *firmwares = cJSON_GetObjectItemCaseSensitive(model_software_v1JSON, "firmwares");
    if (cJSON_IsNull(firmwares)) {
        firmwares = NULL;
    }
    if (firmwares) { 
    cJSON *firmwares_local_nonprimitive = NULL;
    if(!cJSON_IsArray(firmwares)){
        goto end; //nonprimitive container
    }

    firmwaresList = list_createList();

    cJSON_ArrayForEach(firmwares_local_nonprimitive,firmwares )
    {
        if(!cJSON_IsObject(firmwares_local_nonprimitive)){
            goto end;
        }
        firmware_v1_t *firmwaresItem = firmware_v1_parseFromJSON(firmwares_local_nonprimitive);

        list_addElement(firmwaresList, firmwaresItem);
    }
    }


    model_software_v1_local_var = model_software_v1_create_internal (
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        board_config && !cJSON_IsNull(board_config) ? strdup(board_config->valuestring) : NULL,
        platform && !cJSON_IsNull(platform) ? strdup(platform->valuestring) : NULL,
        cpid ? cpid->valuedouble : 0,
        bdid ? bdid->valuedouble : 0,
        firmwares ? firmwaresList : NULL
        );

    return model_software_v1_local_var;
end:
    if (firmwaresList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, firmwaresList) {
            firmware_v1_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(firmwaresList);
        firmwaresList = NULL;
    }
    return NULL;

}
