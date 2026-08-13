#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "model_quotas.h"



static model_quotas_t *model_quotas_create_internal(
    double cores
    ) {
    model_quotas_t *model_quotas_local_var = malloc(sizeof(model_quotas_t));
    if (!model_quotas_local_var) {
        return NULL;
    }
    model_quotas_local_var->cores = cores;

    model_quotas_local_var->_library_owned = 1;
    return model_quotas_local_var;
}

__attribute__((deprecated)) model_quotas_t *model_quotas_create(
    double cores
    ) {
    return model_quotas_create_internal (
        cores
        );
}

void model_quotas_free(model_quotas_t *model_quotas) {
    if(NULL == model_quotas){
        return ;
    }
    if(model_quotas->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "model_quotas_free");
        return ;
    }
    listEntry_t *listEntry;
    free(model_quotas);
}

cJSON *model_quotas_convertToJSON(model_quotas_t *model_quotas) {
    cJSON *item = cJSON_CreateObject();

    // model_quotas->cores
    if (!model_quotas->cores) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "cores", model_quotas->cores) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

model_quotas_t *model_quotas_parseFromJSON(cJSON *model_quotasJSON){

    model_quotas_t *model_quotas_local_var = NULL;

    // model_quotas->cores
    cJSON *cores = cJSON_GetObjectItemCaseSensitive(model_quotasJSON, "cores");
    if (cJSON_IsNull(cores)) {
        cores = NULL;
    }
    if (!cores) {
        goto end;
    }

    
    if(!cJSON_IsNumber(cores))
    {
    goto end; //Numeric
    }


    model_quotas_local_var = model_quotas_create_internal (
        cores->valuedouble
        );

    return model_quotas_local_var;
end:
    return NULL;

}
