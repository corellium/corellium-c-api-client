#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "model_firmware_springboard_snapshot_volumes_inner.h"



static model_firmware_springboard_snapshot_volumes_inner_t *model_firmware_springboard_snapshot_volumes_inner_create_internal(
    double nand
    ) {
    model_firmware_springboard_snapshot_volumes_inner_t *model_firmware_springboard_snapshot_volumes_inner_local_var = malloc(sizeof(model_firmware_springboard_snapshot_volumes_inner_t));
    if (!model_firmware_springboard_snapshot_volumes_inner_local_var) {
        return NULL;
    }
    model_firmware_springboard_snapshot_volumes_inner_local_var->nand = nand;

    model_firmware_springboard_snapshot_volumes_inner_local_var->_library_owned = 1;
    return model_firmware_springboard_snapshot_volumes_inner_local_var;
}

__attribute__((deprecated)) model_firmware_springboard_snapshot_volumes_inner_t *model_firmware_springboard_snapshot_volumes_inner_create(
    double nand
    ) {
    return model_firmware_springboard_snapshot_volumes_inner_create_internal (
        nand
        );
}

void model_firmware_springboard_snapshot_volumes_inner_free(model_firmware_springboard_snapshot_volumes_inner_t *model_firmware_springboard_snapshot_volumes_inner) {
    if(NULL == model_firmware_springboard_snapshot_volumes_inner){
        return ;
    }
    if(model_firmware_springboard_snapshot_volumes_inner->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "model_firmware_springboard_snapshot_volumes_inner_free");
        return ;
    }
    listEntry_t *listEntry;
    free(model_firmware_springboard_snapshot_volumes_inner);
}

cJSON *model_firmware_springboard_snapshot_volumes_inner_convertToJSON(model_firmware_springboard_snapshot_volumes_inner_t *model_firmware_springboard_snapshot_volumes_inner) {
    cJSON *item = cJSON_CreateObject();

    // model_firmware_springboard_snapshot_volumes_inner->nand
    if (!model_firmware_springboard_snapshot_volumes_inner->nand) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "nand", model_firmware_springboard_snapshot_volumes_inner->nand) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

model_firmware_springboard_snapshot_volumes_inner_t *model_firmware_springboard_snapshot_volumes_inner_parseFromJSON(cJSON *model_firmware_springboard_snapshot_volumes_innerJSON){

    model_firmware_springboard_snapshot_volumes_inner_t *model_firmware_springboard_snapshot_volumes_inner_local_var = NULL;

    // model_firmware_springboard_snapshot_volumes_inner->nand
    cJSON *nand = cJSON_GetObjectItemCaseSensitive(model_firmware_springboard_snapshot_volumes_innerJSON, "nand");
    if (cJSON_IsNull(nand)) {
        nand = NULL;
    }
    if (!nand) {
        goto end;
    }

    
    if(!cJSON_IsNumber(nand))
    {
    goto end; //Numeric
    }


    model_firmware_springboard_snapshot_volumes_inner_local_var = model_firmware_springboard_snapshot_volumes_inner_create_internal (
        nand->valuedouble
        );

    return model_firmware_springboard_snapshot_volumes_inner_local_var;
end:
    return NULL;

}
