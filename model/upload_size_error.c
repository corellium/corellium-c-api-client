#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "upload_size_error.h"


char* upload_size_error_error_id_ToString(corellium_api_upload_size_error_ERRORID_e error_id) {
    char* error_idArray[] =  { "NULL", "UploadSizeError" };
    return error_idArray[error_id];
}

corellium_api_upload_size_error_ERRORID_e upload_size_error_error_id_FromString(char* error_id){
    int stringToReturn = 0;
    char *error_idArray[] =  { "NULL", "UploadSizeError" };
    size_t sizeofArray = sizeof(error_idArray) / sizeof(error_idArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(error_id, error_idArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static upload_size_error_t *upload_size_error_create_internal(
    char *error,
    corellium_api_upload_size_error_ERRORID_e error_id,
    char *field
    ) {
    upload_size_error_t *upload_size_error_local_var = malloc(sizeof(upload_size_error_t));
    if (!upload_size_error_local_var) {
        return NULL;
    }
    upload_size_error_local_var->error = error;
    upload_size_error_local_var->error_id = error_id;
    upload_size_error_local_var->field = field;

    upload_size_error_local_var->_library_owned = 1;
    return upload_size_error_local_var;
}

__attribute__((deprecated)) upload_size_error_t *upload_size_error_create(
    char *error,
    corellium_api_upload_size_error_ERRORID_e error_id,
    char *field
    ) {
    return upload_size_error_create_internal (
        error,
        error_id,
        field
        );
}

void upload_size_error_free(upload_size_error_t *upload_size_error) {
    if(NULL == upload_size_error){
        return ;
    }
    if(upload_size_error->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "upload_size_error_free");
        return ;
    }
    listEntry_t *listEntry;
    if (upload_size_error->error) {
        free(upload_size_error->error);
        upload_size_error->error = NULL;
    }
    if (upload_size_error->field) {
        free(upload_size_error->field);
        upload_size_error->field = NULL;
    }
    free(upload_size_error);
}

cJSON *upload_size_error_convertToJSON(upload_size_error_t *upload_size_error) {
    cJSON *item = cJSON_CreateObject();

    // upload_size_error->error
    if (!upload_size_error->error) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "error", upload_size_error->error) == NULL) {
    goto fail; //String
    }


    // upload_size_error->error_id
    if (corellium_api_upload_size_error_ERRORID_NULL == upload_size_error->error_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "errorID", upload_size_error_error_id_ToString(upload_size_error->error_id)) == NULL)
    {
    goto fail; //Enum
    }


    // upload_size_error->field
    if(upload_size_error->field) {
    if(cJSON_AddStringToObject(item, "field", upload_size_error->field) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

upload_size_error_t *upload_size_error_parseFromJSON(cJSON *upload_size_errorJSON){

    upload_size_error_t *upload_size_error_local_var = NULL;

    // upload_size_error->error
    cJSON *error = cJSON_GetObjectItemCaseSensitive(upload_size_errorJSON, "error");
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

    // upload_size_error->error_id
    cJSON *error_id = cJSON_GetObjectItemCaseSensitive(upload_size_errorJSON, "errorID");
    if (cJSON_IsNull(error_id)) {
        error_id = NULL;
    }
    if (!error_id) {
        goto end;
    }

    corellium_api_upload_size_error_ERRORID_e error_idVariable;
    
    if(!cJSON_IsString(error_id))
    {
    goto end; //Enum
    }
    error_idVariable = upload_size_error_error_id_FromString(error_id->valuestring);

    // upload_size_error->field
    cJSON *field = cJSON_GetObjectItemCaseSensitive(upload_size_errorJSON, "field");
    if (cJSON_IsNull(field)) {
        field = NULL;
    }
    if (field) { 
    if(!cJSON_IsString(field) && !cJSON_IsNull(field))
    {
    goto end; //String
    }
    }


    upload_size_error_local_var = upload_size_error_create_internal (
        strdup(error->valuestring),
        error_idVariable,
        field && !cJSON_IsNull(field) ? strdup(field->valuestring) : NULL
        );

    return upload_size_error_local_var;
end:
    return NULL;

}
