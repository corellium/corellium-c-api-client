#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "reset_unauthorized_response.h"


char* reset_unauthorized_response_error_id_ToString(corellium_api_reset_unauthorized_response_ERRORID_e error_id) {
    char* error_idArray[] =  { "NULL", "Unauthorized" };
    return error_idArray[error_id];
}

corellium_api_reset_unauthorized_response_ERRORID_e reset_unauthorized_response_error_id_FromString(char* error_id){
    int stringToReturn = 0;
    char *error_idArray[] =  { "NULL", "Unauthorized" };
    size_t sizeofArray = sizeof(error_idArray) / sizeof(error_idArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(error_id, error_idArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static reset_unauthorized_response_t *reset_unauthorized_response_create_internal(
    char *error,
    corellium_api_reset_unauthorized_response_ERRORID_e error_id
    ) {
    reset_unauthorized_response_t *reset_unauthorized_response_local_var = malloc(sizeof(reset_unauthorized_response_t));
    if (!reset_unauthorized_response_local_var) {
        return NULL;
    }
    reset_unauthorized_response_local_var->error = error;
    reset_unauthorized_response_local_var->error_id = error_id;

    reset_unauthorized_response_local_var->_library_owned = 1;
    return reset_unauthorized_response_local_var;
}

__attribute__((deprecated)) reset_unauthorized_response_t *reset_unauthorized_response_create(
    char *error,
    corellium_api_reset_unauthorized_response_ERRORID_e error_id
    ) {
    return reset_unauthorized_response_create_internal (
        error,
        error_id
        );
}

void reset_unauthorized_response_free(reset_unauthorized_response_t *reset_unauthorized_response) {
    if(NULL == reset_unauthorized_response){
        return ;
    }
    if(reset_unauthorized_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "reset_unauthorized_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (reset_unauthorized_response->error) {
        free(reset_unauthorized_response->error);
        reset_unauthorized_response->error = NULL;
    }
    free(reset_unauthorized_response);
}

cJSON *reset_unauthorized_response_convertToJSON(reset_unauthorized_response_t *reset_unauthorized_response) {
    cJSON *item = cJSON_CreateObject();

    // reset_unauthorized_response->error
    if (!reset_unauthorized_response->error) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "error", reset_unauthorized_response->error) == NULL) {
    goto fail; //String
    }


    // reset_unauthorized_response->error_id
    if (corellium_api_reset_unauthorized_response_ERRORID_NULL == reset_unauthorized_response->error_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "errorID", reset_unauthorized_response_error_id_ToString(reset_unauthorized_response->error_id)) == NULL)
    {
    goto fail; //Enum
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

reset_unauthorized_response_t *reset_unauthorized_response_parseFromJSON(cJSON *reset_unauthorized_responseJSON){

    reset_unauthorized_response_t *reset_unauthorized_response_local_var = NULL;

    // reset_unauthorized_response->error
    cJSON *error = cJSON_GetObjectItemCaseSensitive(reset_unauthorized_responseJSON, "error");
    if (cJSON_IsNull(error)) {
        error = NULL;
    }
    if (!error) {
        goto end;
    }

    
    if(!cJSON_IsString(error))
    {
    goto end; //String
    }

    // reset_unauthorized_response->error_id
    cJSON *error_id = cJSON_GetObjectItemCaseSensitive(reset_unauthorized_responseJSON, "errorID");
    if (cJSON_IsNull(error_id)) {
        error_id = NULL;
    }
    if (!error_id) {
        goto end;
    }

    corellium_api_reset_unauthorized_response_ERRORID_e error_idVariable;
    
    if(!cJSON_IsString(error_id))
    {
    goto end; //Enum
    }
    error_idVariable = reset_unauthorized_response_error_id_FromString(error_id->valuestring);


    reset_unauthorized_response_local_var = reset_unauthorized_response_create_internal (
        strdup(error->valuestring),
        error_idVariable
        );

    return reset_unauthorized_response_local_var;
end:
    return NULL;

}
