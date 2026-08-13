#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_trial_request_response.h"



static create_trial_request_response_t *create_trial_request_response_create_internal(
    create_trial_request_response_trial_request_t *trial_request
    ) {
    create_trial_request_response_t *create_trial_request_response_local_var = malloc(sizeof(create_trial_request_response_t));
    if (!create_trial_request_response_local_var) {
        return NULL;
    }
    create_trial_request_response_local_var->trial_request = trial_request;

    create_trial_request_response_local_var->_library_owned = 1;
    return create_trial_request_response_local_var;
}

__attribute__((deprecated)) create_trial_request_response_t *create_trial_request_response_create(
    create_trial_request_response_trial_request_t *trial_request
    ) {
    return create_trial_request_response_create_internal (
        trial_request
        );
}

void create_trial_request_response_free(create_trial_request_response_t *create_trial_request_response) {
    if(NULL == create_trial_request_response){
        return ;
    }
    if(create_trial_request_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "create_trial_request_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (create_trial_request_response->trial_request) {
        create_trial_request_response_trial_request_free(create_trial_request_response->trial_request);
        create_trial_request_response->trial_request = NULL;
    }
    free(create_trial_request_response);
}

cJSON *create_trial_request_response_convertToJSON(create_trial_request_response_t *create_trial_request_response) {
    cJSON *item = cJSON_CreateObject();

    // create_trial_request_response->trial_request
    if (!create_trial_request_response->trial_request) {
        goto fail;
    }
    cJSON *trial_request_local_JSON = create_trial_request_response_trial_request_convertToJSON(create_trial_request_response->trial_request);
    if(trial_request_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "trialRequest", trial_request_local_JSON);
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

create_trial_request_response_t *create_trial_request_response_parseFromJSON(cJSON *create_trial_request_responseJSON){

    create_trial_request_response_t *create_trial_request_response_local_var = NULL;

    // define the local variable for create_trial_request_response->trial_request
    create_trial_request_response_trial_request_t *trial_request_local_nonprim = NULL;

    // create_trial_request_response->trial_request
    cJSON *trial_request = cJSON_GetObjectItemCaseSensitive(create_trial_request_responseJSON, "trialRequest");
    if (cJSON_IsNull(trial_request)) {
        trial_request = NULL;
    }
    if (!trial_request) {
        goto end;
    }

    
    trial_request_local_nonprim = create_trial_request_response_trial_request_parseFromJSON(trial_request); //nonprimitive


    create_trial_request_response_local_var = create_trial_request_response_create_internal (
        trial_request_local_nonprim
        );

    return create_trial_request_response_local_var;
end:
    if (trial_request_local_nonprim) {
        create_trial_request_response_trial_request_free(trial_request_local_nonprim);
        trial_request_local_nonprim = NULL;
    }
    return NULL;

}
