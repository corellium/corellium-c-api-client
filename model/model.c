#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "model.h"



static model_t *model_create_internal(
    char *type,
    char *flavor,
    char *description,
    char *model,
    char *board_config,
    char *platform,
    double cpid,
    double bdid,
    int peripherals,
    model_quotas_t *quotas
    ) {
    model_t *model_local_var = malloc(sizeof(model_t));
    if (!model_local_var) {
        return NULL;
    }
    model_local_var->type = type;
    model_local_var->flavor = flavor;
    model_local_var->description = description;
    model_local_var->model = model;
    model_local_var->board_config = board_config;
    model_local_var->platform = platform;
    model_local_var->cpid = cpid;
    model_local_var->bdid = bdid;
    model_local_var->peripherals = peripherals;
    model_local_var->quotas = quotas;

    model_local_var->_library_owned = 1;
    return model_local_var;
}

__attribute__((deprecated)) model_t *model_create(
    char *type,
    char *flavor,
    char *description,
    char *model,
    char *board_config,
    char *platform,
    double cpid,
    double bdid,
    int peripherals,
    model_quotas_t *quotas
    ) {
    return model_create_internal (
        type,
        flavor,
        description,
        model,
        board_config,
        platform,
        cpid,
        bdid,
        peripherals,
        quotas
        );
}

void model_free(model_t *model) {
    if(NULL == model){
        return ;
    }
    if(model->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "model_free");
        return ;
    }
    listEntry_t *listEntry;
    if (model->type) {
        free(model->type);
        model->type = NULL;
    }
    if (model->flavor) {
        free(model->flavor);
        model->flavor = NULL;
    }
    if (model->description) {
        free(model->description);
        model->description = NULL;
    }
    if (model->model) {
        free(model->model);
        model->model = NULL;
    }
    if (model->board_config) {
        free(model->board_config);
        model->board_config = NULL;
    }
    if (model->platform) {
        free(model->platform);
        model->platform = NULL;
    }
    if (model->quotas) {
        model_quotas_free(model->quotas);
        model->quotas = NULL;
    }
    free(model);
}

cJSON *model_convertToJSON(model_t *model) {
    cJSON *item = cJSON_CreateObject();

    // model->type
    if (!model->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", model->type) == NULL) {
    goto fail; //String
    }


    // model->flavor
    if (!model->flavor) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "flavor", model->flavor) == NULL) {
    goto fail; //String
    }


    // model->description
    if(model->description) {
    if(cJSON_AddStringToObject(item, "description", model->description) == NULL) {
    goto fail; //String
    }
    }


    // model->model
    if (!model->model) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "model", model->model) == NULL) {
    goto fail; //String
    }


    // model->board_config
    if(model->board_config) {
    if(cJSON_AddStringToObject(item, "boardConfig", model->board_config) == NULL) {
    goto fail; //String
    }
    }


    // model->platform
    if(model->platform) {
    if(cJSON_AddStringToObject(item, "platform", model->platform) == NULL) {
    goto fail; //String
    }
    }


    // model->cpid
    if(model->cpid) {
    if(cJSON_AddNumberToObject(item, "cpid", model->cpid) == NULL) {
    goto fail; //Numeric
    }
    }


    // model->bdid
    if(model->bdid) {
    if(cJSON_AddNumberToObject(item, "bdid", model->bdid) == NULL) {
    goto fail; //Numeric
    }
    }


    // model->peripherals
    if (!model->peripherals) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "peripherals", model->peripherals) == NULL) {
    goto fail; //Bool
    }


    // model->quotas
    if (!model->quotas) {
        goto fail;
    }
    cJSON *quotas_local_JSON = model_quotas_convertToJSON(model->quotas);
    if(quotas_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "quotas", quotas_local_JSON);
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

model_t *model_parseFromJSON(cJSON *modelJSON){

    model_t *model_local_var = NULL;

    // define the local variable for model->quotas
    model_quotas_t *quotas_local_nonprim = NULL;

    // model->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(modelJSON, "type");
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

    // model->flavor
    cJSON *flavor = cJSON_GetObjectItemCaseSensitive(modelJSON, "flavor");
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

    // model->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(modelJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // model->model
    cJSON *model = cJSON_GetObjectItemCaseSensitive(modelJSON, "model");
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

    // model->board_config
    cJSON *board_config = cJSON_GetObjectItemCaseSensitive(modelJSON, "boardConfig");
    if (cJSON_IsNull(board_config)) {
        board_config = NULL;
    }
    if (board_config) { 
    if(!cJSON_IsString(board_config) && !cJSON_IsNull(board_config))
    {
    goto end; //String
    }
    }

    // model->platform
    cJSON *platform = cJSON_GetObjectItemCaseSensitive(modelJSON, "platform");
    if (cJSON_IsNull(platform)) {
        platform = NULL;
    }
    if (platform) { 
    if(!cJSON_IsString(platform) && !cJSON_IsNull(platform))
    {
    goto end; //String
    }
    }

    // model->cpid
    cJSON *cpid = cJSON_GetObjectItemCaseSensitive(modelJSON, "cpid");
    if (cJSON_IsNull(cpid)) {
        cpid = NULL;
    }
    if (cpid) { 
    if(!cJSON_IsNumber(cpid))
    {
    goto end; //Numeric
    }
    }

    // model->bdid
    cJSON *bdid = cJSON_GetObjectItemCaseSensitive(modelJSON, "bdid");
    if (cJSON_IsNull(bdid)) {
        bdid = NULL;
    }
    if (bdid) { 
    if(!cJSON_IsNumber(bdid))
    {
    goto end; //Numeric
    }
    }

    // model->peripherals
    cJSON *peripherals = cJSON_GetObjectItemCaseSensitive(modelJSON, "peripherals");
    if (cJSON_IsNull(peripherals)) {
        peripherals = NULL;
    }
    if (!peripherals) {
        goto end;
    }

    
    if(!cJSON_IsBool(peripherals))
    {
    goto end; //Bool
    }

    // model->quotas
    cJSON *quotas = cJSON_GetObjectItemCaseSensitive(modelJSON, "quotas");
    if (cJSON_IsNull(quotas)) {
        quotas = NULL;
    }
    if (!quotas) {
        goto end;
    }

    
    quotas_local_nonprim = model_quotas_parseFromJSON(quotas); //nonprimitive


    model_local_var = model_create_internal (
        strdup(type->valuestring),
        strdup(flavor->valuestring),
        description && !cJSON_IsNull(description) ? strdup(description->valuestring) : NULL,
        strdup(model->valuestring),
        board_config && !cJSON_IsNull(board_config) ? strdup(board_config->valuestring) : NULL,
        platform && !cJSON_IsNull(platform) ? strdup(platform->valuestring) : NULL,
        cpid ? cpid->valuedouble : 0,
        bdid ? bdid->valuedouble : 0,
        peripherals->valueint,
        quotas_local_nonprim
        );

    return model_local_var;
end:
    if (quotas_local_nonprim) {
        model_quotas_free(quotas_local_nonprim);
        quotas_local_nonprim = NULL;
    }
    return NULL;

}
