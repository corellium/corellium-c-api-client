#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "input_response_v1.h"



static input_response_v1_t *input_response_v1_create_internal(
    double eta
    ) {
    input_response_v1_t *input_response_v1_local_var = malloc(sizeof(input_response_v1_t));
    if (!input_response_v1_local_var) {
        return NULL;
    }
    input_response_v1_local_var->eta = eta;

    input_response_v1_local_var->_library_owned = 1;
    return input_response_v1_local_var;
}

__attribute__((deprecated)) input_response_v1_t *input_response_v1_create(
    double eta
    ) {
    return input_response_v1_create_internal (
        eta
        );
}

void input_response_v1_free(input_response_v1_t *input_response_v1) {
    if(NULL == input_response_v1){
        return ;
    }
    if(input_response_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "input_response_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    free(input_response_v1);
}

cJSON *input_response_v1_convertToJSON(input_response_v1_t *input_response_v1) {
    cJSON *item = cJSON_CreateObject();

    // input_response_v1->eta
    if(input_response_v1->eta) {
    if(cJSON_AddNumberToObject(item, "eta", input_response_v1->eta) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

input_response_v1_t *input_response_v1_parseFromJSON(cJSON *input_response_v1JSON){

    input_response_v1_t *input_response_v1_local_var = NULL;

    // input_response_v1->eta
    cJSON *eta = cJSON_GetObjectItemCaseSensitive(input_response_v1JSON, "eta");
    if (cJSON_IsNull(eta)) {
        eta = NULL;
    }
    if (eta) { 
    if(!cJSON_IsNumber(eta))
    {
    goto end; //Numeric
    }
    }


    input_response_v1_local_var = input_response_v1_create_internal (
        eta ? eta->valuedouble : 0
        );

    return input_response_v1_local_var;
end:
    return NULL;

}
