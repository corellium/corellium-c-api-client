#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "model_v1.h"



static model_v1_t *model_v1_create_internal(
    char *type,
    char *name,
    char *flavor,
    char *description,
    char *model,
    char *board_config,
    char *platform,
    double cpid,
    double bdid,
    int peripherals
    ) {
    model_v1_t *model_v1_local_var = malloc(sizeof(model_v1_t));
    if (!model_v1_local_var) {
        return NULL;
    }
    model_v1_local_var->type = type;
    model_v1_local_var->name = name;
    model_v1_local_var->flavor = flavor;
    model_v1_local_var->description = description;
    model_v1_local_var->model = model;
    model_v1_local_var->board_config = board_config;
    model_v1_local_var->platform = platform;
    model_v1_local_var->cpid = cpid;
    model_v1_local_var->bdid = bdid;
    model_v1_local_var->peripherals = peripherals;

    model_v1_local_var->_library_owned = 1;
    return model_v1_local_var;
}

__attribute__((deprecated)) model_v1_t *model_v1_create(
    char *type,
    char *name,
    char *flavor,
    char *description,
    char *model,
    char *board_config,
    char *platform,
    double cpid,
    double bdid,
    int peripherals
    ) {
    return model_v1_create_internal (
        type,
        name,
        flavor,
        description,
        model,
        board_config,
        platform,
        cpid,
        bdid,
        peripherals
        );
}

void model_v1_free(model_v1_t *model_v1) {
    if(NULL == model_v1){
        return ;
    }
    if(model_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "model_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (model_v1->type) {
        free(model_v1->type);
        model_v1->type = NULL;
    }
    if (model_v1->name) {
        free(model_v1->name);
        model_v1->name = NULL;
    }
    if (model_v1->flavor) {
        free(model_v1->flavor);
        model_v1->flavor = NULL;
    }
    if (model_v1->description) {
        free(model_v1->description);
        model_v1->description = NULL;
    }
    if (model_v1->model) {
        free(model_v1->model);
        model_v1->model = NULL;
    }
    if (model_v1->board_config) {
        free(model_v1->board_config);
        model_v1->board_config = NULL;
    }
    if (model_v1->platform) {
        free(model_v1->platform);
        model_v1->platform = NULL;
    }
    free(model_v1);
}

cJSON *model_v1_convertToJSON(model_v1_t *model_v1) {
    cJSON *item = cJSON_CreateObject();

    // model_v1->type
    if (!model_v1->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", model_v1->type) == NULL) {
    goto fail; //String
    }


    // model_v1->name
    if (!model_v1->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", model_v1->name) == NULL) {
    goto fail; //String
    }


    // model_v1->flavor
    if (!model_v1->flavor) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "flavor", model_v1->flavor) == NULL) {
    goto fail; //String
    }


    // model_v1->description
    if(model_v1->description) {
    if(cJSON_AddStringToObject(item, "description", model_v1->description) == NULL) {
    goto fail; //String
    }
    }


    // model_v1->model
    if (!model_v1->model) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "model", model_v1->model) == NULL) {
    goto fail; //String
    }


    // model_v1->board_config
    if(model_v1->board_config) {
    if(cJSON_AddStringToObject(item, "boardConfig", model_v1->board_config) == NULL) {
    goto fail; //String
    }
    }


    // model_v1->platform
    if(model_v1->platform) {
    if(cJSON_AddStringToObject(item, "platform", model_v1->platform) == NULL) {
    goto fail; //String
    }
    }


    // model_v1->cpid
    if(model_v1->cpid) {
    if(cJSON_AddNumberToObject(item, "cpid", model_v1->cpid) == NULL) {
    goto fail; //Numeric
    }
    }


    // model_v1->bdid
    if(model_v1->bdid) {
    if(cJSON_AddNumberToObject(item, "bdid", model_v1->bdid) == NULL) {
    goto fail; //Numeric
    }
    }


    // model_v1->peripherals
    if(model_v1->peripherals) {
    if(cJSON_AddBoolToObject(item, "peripherals", model_v1->peripherals) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

model_v1_t *model_v1_parseFromJSON(cJSON *model_v1JSON){

    model_v1_t *model_v1_local_var = NULL;

    // model_v1->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(model_v1JSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }

    // model_v1->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(model_v1JSON, "name");
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

    // model_v1->flavor
    cJSON *flavor = cJSON_GetObjectItemCaseSensitive(model_v1JSON, "flavor");
    if (cJSON_IsNull(flavor)) {
        flavor = NULL;
    }
    if (!flavor) {
        goto end;
    }

    
    if(!cJSON_IsString(flavor))
    {
    goto end; //String
    }

    // model_v1->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(model_v1JSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // model_v1->model
    cJSON *model = cJSON_GetObjectItemCaseSensitive(model_v1JSON, "model");
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

    // model_v1->board_config
    cJSON *board_config = cJSON_GetObjectItemCaseSensitive(model_v1JSON, "boardConfig");
    if (cJSON_IsNull(board_config)) {
        board_config = NULL;
    }
    if (board_config) { 
    if(!cJSON_IsString(board_config) && !cJSON_IsNull(board_config))
    {
    goto end; //String
    }
    }

    // model_v1->platform
    cJSON *platform = cJSON_GetObjectItemCaseSensitive(model_v1JSON, "platform");
    if (cJSON_IsNull(platform)) {
        platform = NULL;
    }
    if (platform) { 
    if(!cJSON_IsString(platform) && !cJSON_IsNull(platform))
    {
    goto end; //String
    }
    }

    // model_v1->cpid
    cJSON *cpid = cJSON_GetObjectItemCaseSensitive(model_v1JSON, "cpid");
    if (cJSON_IsNull(cpid)) {
        cpid = NULL;
    }
    if (cpid) { 
    if(!cJSON_IsNumber(cpid))
    {
    goto end; //Numeric
    }
    }

    // model_v1->bdid
    cJSON *bdid = cJSON_GetObjectItemCaseSensitive(model_v1JSON, "bdid");
    if (cJSON_IsNull(bdid)) {
        bdid = NULL;
    }
    if (bdid) { 
    if(!cJSON_IsNumber(bdid))
    {
    goto end; //Numeric
    }
    }

    // model_v1->peripherals
    cJSON *peripherals = cJSON_GetObjectItemCaseSensitive(model_v1JSON, "peripherals");
    if (cJSON_IsNull(peripherals)) {
        peripherals = NULL;
    }
    if (peripherals) { 
    if(!cJSON_IsBool(peripherals))
    {
    goto end; //Bool
    }
    }


    model_v1_local_var = model_v1_create_internal (
        strdup(type->valuestring),
        strdup(name->valuestring),
        strdup(flavor->valuestring),
        description && !cJSON_IsNull(description) ? strdup(description->valuestring) : NULL,
        strdup(model->valuestring),
        board_config && !cJSON_IsNull(board_config) ? strdup(board_config->valuestring) : NULL,
        platform && !cJSON_IsNull(platform) ? strdup(platform->valuestring) : NULL,
        cpid ? cpid->valuedouble : 0,
        bdid ? bdid->valuedouble : 0,
        peripherals ? peripherals->valueint : 0
        );

    return model_v1_local_var;
end:
    return NULL;

}
