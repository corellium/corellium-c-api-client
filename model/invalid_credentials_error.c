#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "invalid_credentials_error.h"


char* invalid_credentials_error_error_id_ToString(corellium_api_invalid_credentials_error_ERRORID_e error_id) {
    char* error_idArray[] =  { "NULL", "InvalidUsernameorPassword" };
    return error_idArray[error_id];
}

corellium_api_invalid_credentials_error_ERRORID_e invalid_credentials_error_error_id_FromString(char* error_id){
    int stringToReturn = 0;
    char *error_idArray[] =  { "NULL", "InvalidUsernameorPassword" };
    size_t sizeofArray = sizeof(error_idArray) / sizeof(error_idArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(error_id, error_idArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static invalid_credentials_error_t *invalid_credentials_error_create_internal(
    char *error,
    corellium_api_invalid_credentials_error_ERRORID_e error_id
    ) {
    invalid_credentials_error_t *invalid_credentials_error_local_var = malloc(sizeof(invalid_credentials_error_t));
    if (!invalid_credentials_error_local_var) {
        return NULL;
    }
    invalid_credentials_error_local_var->error = error;
    invalid_credentials_error_local_var->error_id = error_id;

    invalid_credentials_error_local_var->_library_owned = 1;
    return invalid_credentials_error_local_var;
}

__attribute__((deprecated)) invalid_credentials_error_t *invalid_credentials_error_create(
    char *error,
    corellium_api_invalid_credentials_error_ERRORID_e error_id
    ) {
    return invalid_credentials_error_create_internal (
        error,
        error_id
        );
}

void invalid_credentials_error_free(invalid_credentials_error_t *invalid_credentials_error) {
    if(NULL == invalid_credentials_error){
        return ;
    }
    if(invalid_credentials_error->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "invalid_credentials_error_free");
        return ;
    }
    listEntry_t *listEntry;
    if (invalid_credentials_error->error) {
        free(invalid_credentials_error->error);
        invalid_credentials_error->error = NULL;
    }
    free(invalid_credentials_error);
}

cJSON *invalid_credentials_error_convertToJSON(invalid_credentials_error_t *invalid_credentials_error) {
    cJSON *item = cJSON_CreateObject();

    // invalid_credentials_error->error
    if (!invalid_credentials_error->error) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "error", invalid_credentials_error->error) == NULL) {
    goto fail; //String
    }


    // invalid_credentials_error->error_id
    if (corellium_api_invalid_credentials_error_ERRORID_NULL == invalid_credentials_error->error_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "errorID", invalid_credentials_error_error_id_ToString(invalid_credentials_error->error_id)) == NULL)
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

invalid_credentials_error_t *invalid_credentials_error_parseFromJSON(cJSON *invalid_credentials_errorJSON){

    invalid_credentials_error_t *invalid_credentials_error_local_var = NULL;

    // invalid_credentials_error->error
    cJSON *error = cJSON_GetObjectItemCaseSensitive(invalid_credentials_errorJSON, "error");
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

    // invalid_credentials_error->error_id
    cJSON *error_id = cJSON_GetObjectItemCaseSensitive(invalid_credentials_errorJSON, "errorID");
    if (cJSON_IsNull(error_id)) {
        error_id = NULL;
    }
    if (!error_id) {
        goto end;
    }

    corellium_api_invalid_credentials_error_ERRORID_e error_idVariable;
    
    if(!cJSON_IsString(error_id))
    {
    goto end; //Enum
    }
    error_idVariable = invalid_credentials_error_error_id_FromString(error_id->valuestring);


    invalid_credentials_error_local_var = invalid_credentials_error_create_internal (
        strdup(error->valuestring),
        error_idVariable
        );

    return invalid_credentials_error_local_var;
end:
    return NULL;

}
