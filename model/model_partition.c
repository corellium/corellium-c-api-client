#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "model_partition.h"



static model_partition_t *model_partition_create_internal(
    char *name,
    double block_size,
    double blocks,
    double blocks_min,
    double blocks_max,
    double blocks_step,
    list_t *block_values,
    int user_uploaded
    ) {
    model_partition_t *model_partition_local_var = malloc(sizeof(model_partition_t));
    if (!model_partition_local_var) {
        return NULL;
    }
    model_partition_local_var->name = name;
    model_partition_local_var->block_size = block_size;
    model_partition_local_var->blocks = blocks;
    model_partition_local_var->blocks_min = blocks_min;
    model_partition_local_var->blocks_max = blocks_max;
    model_partition_local_var->blocks_step = blocks_step;
    model_partition_local_var->block_values = block_values;
    model_partition_local_var->user_uploaded = user_uploaded;

    model_partition_local_var->_library_owned = 1;
    return model_partition_local_var;
}

__attribute__((deprecated)) model_partition_t *model_partition_create(
    char *name,
    double block_size,
    double blocks,
    double blocks_min,
    double blocks_max,
    double blocks_step,
    list_t *block_values,
    int user_uploaded
    ) {
    return model_partition_create_internal (
        name,
        block_size,
        blocks,
        blocks_min,
        blocks_max,
        blocks_step,
        block_values,
        user_uploaded
        );
}

void model_partition_free(model_partition_t *model_partition) {
    if(NULL == model_partition){
        return ;
    }
    if(model_partition->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "model_partition_free");
        return ;
    }
    listEntry_t *listEntry;
    if (model_partition->name) {
        free(model_partition->name);
        model_partition->name = NULL;
    }
    if (model_partition->block_values) {
        list_ForEach(listEntry, model_partition->block_values) {
            free(listEntry->data);
        }
        list_freeList(model_partition->block_values);
        model_partition->block_values = NULL;
    }
    free(model_partition);
}

cJSON *model_partition_convertToJSON(model_partition_t *model_partition) {
    cJSON *item = cJSON_CreateObject();

    // model_partition->name
    if (!model_partition->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", model_partition->name) == NULL) {
    goto fail; //String
    }


    // model_partition->block_size
    if (!model_partition->block_size) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "blockSize", model_partition->block_size) == NULL) {
    goto fail; //Numeric
    }


    // model_partition->blocks
    if(model_partition->blocks) {
    if(cJSON_AddNumberToObject(item, "blocks", model_partition->blocks) == NULL) {
    goto fail; //Numeric
    }
    }


    // model_partition->blocks_min
    if(model_partition->blocks_min) {
    if(cJSON_AddNumberToObject(item, "blocksMin", model_partition->blocks_min) == NULL) {
    goto fail; //Numeric
    }
    }


    // model_partition->blocks_max
    if(model_partition->blocks_max) {
    if(cJSON_AddNumberToObject(item, "blocksMax", model_partition->blocks_max) == NULL) {
    goto fail; //Numeric
    }
    }


    // model_partition->blocks_step
    if(model_partition->blocks_step) {
    if(cJSON_AddNumberToObject(item, "blocksStep", model_partition->blocks_step) == NULL) {
    goto fail; //Numeric
    }
    }


    // model_partition->block_values
    if(model_partition->block_values) {
    cJSON *block_values = cJSON_AddArrayToObject(item, "blockValues");
    if(block_values == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *block_valuesListEntry;
    list_ForEach(block_valuesListEntry, model_partition->block_values) {
    if(cJSON_AddNumberToObject(block_values, "", *(double *)block_valuesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // model_partition->user_uploaded
    if(model_partition->user_uploaded) {
    if(cJSON_AddBoolToObject(item, "userUploaded", model_partition->user_uploaded) == NULL) {
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

model_partition_t *model_partition_parseFromJSON(cJSON *model_partitionJSON){

    model_partition_t *model_partition_local_var = NULL;

    // define the local list for model_partition->block_values
    list_t *block_valuesList = NULL;

    // model_partition->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(model_partitionJSON, "name");
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

    // model_partition->block_size
    cJSON *block_size = cJSON_GetObjectItemCaseSensitive(model_partitionJSON, "blockSize");
    if (cJSON_IsNull(block_size)) {
        block_size = NULL;
    }
    if (!block_size) {
        goto end;
    }

    
    if(!cJSON_IsNumber(block_size))
    {
    goto end; //Numeric
    }

    // model_partition->blocks
    cJSON *blocks = cJSON_GetObjectItemCaseSensitive(model_partitionJSON, "blocks");
    if (cJSON_IsNull(blocks)) {
        blocks = NULL;
    }
    if (blocks) { 
    if(!cJSON_IsNumber(blocks))
    {
    goto end; //Numeric
    }
    }

    // model_partition->blocks_min
    cJSON *blocks_min = cJSON_GetObjectItemCaseSensitive(model_partitionJSON, "blocksMin");
    if (cJSON_IsNull(blocks_min)) {
        blocks_min = NULL;
    }
    if (blocks_min) { 
    if(!cJSON_IsNumber(blocks_min))
    {
    goto end; //Numeric
    }
    }

    // model_partition->blocks_max
    cJSON *blocks_max = cJSON_GetObjectItemCaseSensitive(model_partitionJSON, "blocksMax");
    if (cJSON_IsNull(blocks_max)) {
        blocks_max = NULL;
    }
    if (blocks_max) { 
    if(!cJSON_IsNumber(blocks_max))
    {
    goto end; //Numeric
    }
    }

    // model_partition->blocks_step
    cJSON *blocks_step = cJSON_GetObjectItemCaseSensitive(model_partitionJSON, "blocksStep");
    if (cJSON_IsNull(blocks_step)) {
        blocks_step = NULL;
    }
    if (blocks_step) { 
    if(!cJSON_IsNumber(blocks_step))
    {
    goto end; //Numeric
    }
    }

    // model_partition->block_values
    cJSON *block_values = cJSON_GetObjectItemCaseSensitive(model_partitionJSON, "blockValues");
    if (cJSON_IsNull(block_values)) {
        block_values = NULL;
    }
    if (block_values) { 
    cJSON *block_values_local = NULL;
    if(!cJSON_IsArray(block_values)) {
        goto end;//primitive container
    }
    block_valuesList = list_createList();

    cJSON_ArrayForEach(block_values_local, block_values)
    {
        if(!cJSON_IsNumber(block_values_local))
        {
            goto end;
        }
        double *block_values_local_value = calloc(1, sizeof(double));
        if(!block_values_local_value)
        {
            goto end;
        }
        *block_values_local_value = block_values_local->valuedouble;
        list_addElement(block_valuesList , block_values_local_value);
    }
    }

    // model_partition->user_uploaded
    cJSON *user_uploaded = cJSON_GetObjectItemCaseSensitive(model_partitionJSON, "userUploaded");
    if (cJSON_IsNull(user_uploaded)) {
        user_uploaded = NULL;
    }
    if (user_uploaded) { 
    if(!cJSON_IsBool(user_uploaded))
    {
    goto end; //Bool
    }
    }


    model_partition_local_var = model_partition_create_internal (
        strdup(name->valuestring),
        block_size->valuedouble,
        blocks ? blocks->valuedouble : 0,
        blocks_min ? blocks_min->valuedouble : 0,
        blocks_max ? blocks_max->valuedouble : 0,
        blocks_step ? blocks_step->valuedouble : 0,
        block_values ? block_valuesList : NULL,
        user_uploaded ? user_uploaded->valueint : 0
        );

    return model_partition_local_var;
end:
    if (block_valuesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, block_valuesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(block_valuesList);
        block_valuesList = NULL;
    }
    return NULL;

}
