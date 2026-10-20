#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "unauthorized_error.h"


char* unauthorized_error_error_id_ToString(corellium_api_unauthorized_error_ERRORID_e error_id) {
    char* error_idArray[] =  { "NULL", "Unauthorized" };
    return error_idArray[error_id];
}

corellium_api_unauthorized_error_ERRORID_e unauthorized_error_error_id_FromString(char* error_id){
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

static unauthorized_error_t *unauthorized_error_create_internal(
    char *error,
    corellium_api_unauthorized_error_ERRORID_e error_id
    ) {
    unauthorized_error_t *unauthorized_error_local_var = malloc(sizeof(unauthorized_error_t));
    if (!unauthorized_error_local_var) {
        return NULL;
    }
    unauthorized_error_local_var->error = error;
    unauthorized_error_local_var->error_id = error_id;

    unauthorized_error_local_var->_library_owned = 1;
    return unauthorized_error_local_var;
}

__attribute__((deprecated)) unauthorized_error_t *unauthorized_error_create(
    char *error,
    corellium_api_unauthorized_error_ERRORID_e error_id
    ) {
    return unauthorized_error_create_internal (
        error,
        error_id
        );
}

void unauthorized_error_free(unauthorized_error_t *unauthorized_error) {
    if(NULL == unauthorized_error){
        return ;
    }
    if(unauthorized_error->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "unauthorized_error_free");
        return ;
    }
    listEntry_t *listEntry;
    if (unauthorized_error->error) {
        free(unauthorized_error->error);
        unauthorized_error->error = NULL;
    }
    free(unauthorized_error);
}

cJSON *unauthorized_error_convertToJSON(unauthorized_error_t *unauthorized_error) {
    cJSON *item = cJSON_CreateObject();

    // unauthorized_error->error
    if (!unauthorized_error->error) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "error", unauthorized_error->error) == NULL) {
    goto fail; //String
    }


    // unauthorized_error->error_id
    if (corellium_api_unauthorized_error_ERRORID_NULL == unauthorized_error->error_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "errorID", unauthorized_error_error_id_ToString(unauthorized_error->error_id)) == NULL)
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

unauthorized_error_t *unauthorized_error_parseFromJSON(cJSON *unauthorized_errorJSON){

    unauthorized_error_t *unauthorized_error_local_var = NULL;

    // unauthorized_error->error
    cJSON *error = cJSON_GetObjectItemCaseSensitive(unauthorized_errorJSON, "error");
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

    // unauthorized_error->error_id
    cJSON *error_id = cJSON_GetObjectItemCaseSensitive(unauthorized_errorJSON, "errorID");
    if (cJSON_IsNull(error_id)) {
        error_id = NULL;
    }
    if (!error_id) {
        goto end;
    }

    corellium_api_unauthorized_error_ERRORID_e error_idVariable;
    
    if(!cJSON_IsString(error_id))
    {
    goto end; //Enum
    }
    error_idVariable = unauthorized_error_error_id_FromString(error_id->valuestring);


    unauthorized_error_local_var = unauthorized_error_create_internal (
        strdup(error->valuestring),
        error_idVariable
        );

    return unauthorized_error_local_var;
end:
    return NULL;

}
