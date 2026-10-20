#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "input_response.h"



static input_response_t *input_response_create_internal(
    double eta
    ) {
    input_response_t *input_response_local_var = malloc(sizeof(input_response_t));
    if (!input_response_local_var) {
        return NULL;
    }
    input_response_local_var->eta = eta;

    input_response_local_var->_library_owned = 1;
    return input_response_local_var;
}

__attribute__((deprecated)) input_response_t *input_response_create(
    double eta
    ) {
    return input_response_create_internal (
        eta
        );
}

void input_response_free(input_response_t *input_response) {
    if(NULL == input_response){
        return ;
    }
    if(input_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "input_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(input_response);
}

cJSON *input_response_convertToJSON(input_response_t *input_response) {
    cJSON *item = cJSON_CreateObject();

    // input_response->eta
    if (!input_response->eta) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "eta", input_response->eta) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

input_response_t *input_response_parseFromJSON(cJSON *input_responseJSON){

    input_response_t *input_response_local_var = NULL;

    // input_response->eta
    cJSON *eta = cJSON_GetObjectItemCaseSensitive(input_responseJSON, "eta");
    if (cJSON_IsNull(eta)) {
        eta = NULL;
    }
    if (!eta) {
        goto end;
    }

    
    if(!cJSON_IsNumber(eta))
    {
    goto end; //Numeric
    }


    input_response_local_var = input_response_create_internal (
        eta->valuedouble
        );

    return input_response_local_var;
end:
    return NULL;

}
