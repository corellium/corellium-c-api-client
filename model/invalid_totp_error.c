#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "invalid_totp_error.h"


char* invalid_totp_error_error_id_ToString(corellium_api_invalid_totp_error_ERRORID_e error_id) {
    char* error_idArray[] =  { "NULL", "InvalidTOTP" };
    return error_idArray[error_id];
}

corellium_api_invalid_totp_error_ERRORID_e invalid_totp_error_error_id_FromString(char* error_id){
    int stringToReturn = 0;
    char *error_idArray[] =  { "NULL", "InvalidTOTP" };
    size_t sizeofArray = sizeof(error_idArray) / sizeof(error_idArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(error_id, error_idArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static invalid_totp_error_t *invalid_totp_error_create_internal(
    char *error,
    corellium_api_invalid_totp_error_ERRORID_e error_id
    ) {
    invalid_totp_error_t *invalid_totp_error_local_var = malloc(sizeof(invalid_totp_error_t));
    if (!invalid_totp_error_local_var) {
        return NULL;
    }
    invalid_totp_error_local_var->error = error;
    invalid_totp_error_local_var->error_id = error_id;

    invalid_totp_error_local_var->_library_owned = 1;
    return invalid_totp_error_local_var;
}

__attribute__((deprecated)) invalid_totp_error_t *invalid_totp_error_create(
    char *error,
    corellium_api_invalid_totp_error_ERRORID_e error_id
    ) {
    return invalid_totp_error_create_internal (
        error,
        error_id
        );
}

void invalid_totp_error_free(invalid_totp_error_t *invalid_totp_error) {
    if(NULL == invalid_totp_error){
        return ;
    }
    if(invalid_totp_error->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "invalid_totp_error_free");
        return ;
    }
    listEntry_t *listEntry;
    if (invalid_totp_error->error) {
        free(invalid_totp_error->error);
        invalid_totp_error->error = NULL;
    }
    free(invalid_totp_error);
}

cJSON *invalid_totp_error_convertToJSON(invalid_totp_error_t *invalid_totp_error) {
    cJSON *item = cJSON_CreateObject();

    // invalid_totp_error->error
    if (!invalid_totp_error->error) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "error", invalid_totp_error->error) == NULL) {
    goto fail; //String
    }


    // invalid_totp_error->error_id
    if (corellium_api_invalid_totp_error_ERRORID_NULL == invalid_totp_error->error_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "errorID", invalid_totp_error_error_id_ToString(invalid_totp_error->error_id)) == NULL)
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

invalid_totp_error_t *invalid_totp_error_parseFromJSON(cJSON *invalid_totp_errorJSON){

    invalid_totp_error_t *invalid_totp_error_local_var = NULL;

    // invalid_totp_error->error
    cJSON *error = cJSON_GetObjectItemCaseSensitive(invalid_totp_errorJSON, "error");
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

    // invalid_totp_error->error_id
    cJSON *error_id = cJSON_GetObjectItemCaseSensitive(invalid_totp_errorJSON, "errorID");
    if (cJSON_IsNull(error_id)) {
        error_id = NULL;
    }
    if (!error_id) {
        goto end;
    }

    corellium_api_invalid_totp_error_ERRORID_e error_idVariable;
    
    if(!cJSON_IsString(error_id))
    {
    goto end; //Enum
    }
    error_idVariable = invalid_totp_error_error_id_FromString(error_id->valuestring);


    invalid_totp_error_local_var = invalid_totp_error_create_internal (
        strdup(error->valuestring),
        error_idVariable
        );

    return invalid_totp_error_local_var;
end:
    return NULL;

}
