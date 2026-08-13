#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "account_setup_response.h"



static account_setup_response_t *account_setup_response_create_internal(
    int success
    ) {
    account_setup_response_t *account_setup_response_local_var = malloc(sizeof(account_setup_response_t));
    if (!account_setup_response_local_var) {
        return NULL;
    }
    account_setup_response_local_var->success = success;

    account_setup_response_local_var->_library_owned = 1;
    return account_setup_response_local_var;
}

__attribute__((deprecated)) account_setup_response_t *account_setup_response_create(
    int success
    ) {
    return account_setup_response_create_internal (
        success
        );
}

void account_setup_response_free(account_setup_response_t *account_setup_response) {
    if(NULL == account_setup_response){
        return ;
    }
    if(account_setup_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "account_setup_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(account_setup_response);
}

cJSON *account_setup_response_convertToJSON(account_setup_response_t *account_setup_response) {
    cJSON *item = cJSON_CreateObject();

    // account_setup_response->success
    if (!account_setup_response->success) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "success", account_setup_response->success) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

account_setup_response_t *account_setup_response_parseFromJSON(cJSON *account_setup_responseJSON){

    account_setup_response_t *account_setup_response_local_var = NULL;

    // account_setup_response->success
    cJSON *success = cJSON_GetObjectItemCaseSensitive(account_setup_responseJSON, "success");
    if (cJSON_IsNull(success)) {
        success = NULL;
    }
    if (!success) {
        goto end;
    }

    
    if(!cJSON_IsBool(success))
    {
    goto end; //Bool
    }


    account_setup_response_local_var = account_setup_response_create_internal (
        success->valueint
        );

    return account_setup_response_local_var;
end:
    return NULL;

}
