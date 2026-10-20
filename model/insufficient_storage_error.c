#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "insufficient_storage_error.h"


char* insufficient_storage_error_error_id_ToString(corellium_api_insufficient_storage_error_ERRORID_e error_id) {
    char* error_idArray[] =  { "NULL", "InsufficientStorage" };
    return error_idArray[error_id];
}

corellium_api_insufficient_storage_error_ERRORID_e insufficient_storage_error_error_id_FromString(char* error_id){
    int stringToReturn = 0;
    char *error_idArray[] =  { "NULL", "InsufficientStorage" };
    size_t sizeofArray = sizeof(error_idArray) / sizeof(error_idArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(error_id, error_idArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static insufficient_storage_error_t *insufficient_storage_error_create_internal(
    char *error,
    corellium_api_insufficient_storage_error_ERRORID_e error_id,
    double total,
    double available,
    double required
    ) {
    insufficient_storage_error_t *insufficient_storage_error_local_var = malloc(sizeof(insufficient_storage_error_t));
    if (!insufficient_storage_error_local_var) {
        return NULL;
    }
    insufficient_storage_error_local_var->error = error;
    insufficient_storage_error_local_var->error_id = error_id;
    insufficient_storage_error_local_var->total = total;
    insufficient_storage_error_local_var->available = available;
    insufficient_storage_error_local_var->required = required;

    insufficient_storage_error_local_var->_library_owned = 1;
    return insufficient_storage_error_local_var;
}

__attribute__((deprecated)) insufficient_storage_error_t *insufficient_storage_error_create(
    char *error,
    corellium_api_insufficient_storage_error_ERRORID_e error_id,
    double total,
    double available,
    double required
    ) {
    return insufficient_storage_error_create_internal (
        error,
        error_id,
        total,
        available,
        required
        );
}

void insufficient_storage_error_free(insufficient_storage_error_t *insufficient_storage_error) {
    if(NULL == insufficient_storage_error){
        return ;
    }
    if(insufficient_storage_error->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "insufficient_storage_error_free");
        return ;
    }
    listEntry_t *listEntry;
    if (insufficient_storage_error->error) {
        free(insufficient_storage_error->error);
        insufficient_storage_error->error = NULL;
    }
    free(insufficient_storage_error);
}

cJSON *insufficient_storage_error_convertToJSON(insufficient_storage_error_t *insufficient_storage_error) {
    cJSON *item = cJSON_CreateObject();

    // insufficient_storage_error->error
    if (!insufficient_storage_error->error) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "error", insufficient_storage_error->error) == NULL) {
    goto fail; //String
    }


    // insufficient_storage_error->error_id
    if (corellium_api_insufficient_storage_error_ERRORID_NULL == insufficient_storage_error->error_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "errorID", insufficient_storage_error_error_id_ToString(insufficient_storage_error->error_id)) == NULL)
    {
    goto fail; //Enum
    }


    // insufficient_storage_error->total
    if (!insufficient_storage_error->total) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "total", insufficient_storage_error->total) == NULL) {
    goto fail; //Numeric
    }


    // insufficient_storage_error->available
    if (!insufficient_storage_error->available) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "available", insufficient_storage_error->available) == NULL) {
    goto fail; //Numeric
    }


    // insufficient_storage_error->required
    if (!insufficient_storage_error->required) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "required", insufficient_storage_error->required) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

insufficient_storage_error_t *insufficient_storage_error_parseFromJSON(cJSON *insufficient_storage_errorJSON){

    insufficient_storage_error_t *insufficient_storage_error_local_var = NULL;

    // insufficient_storage_error->error
    cJSON *error = cJSON_GetObjectItemCaseSensitive(insufficient_storage_errorJSON, "error");
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

    // insufficient_storage_error->error_id
    cJSON *error_id = cJSON_GetObjectItemCaseSensitive(insufficient_storage_errorJSON, "errorID");
    if (cJSON_IsNull(error_id)) {
        error_id = NULL;
    }
    if (!error_id) {
        goto end;
    }

    corellium_api_insufficient_storage_error_ERRORID_e error_idVariable;
    
    if(!cJSON_IsString(error_id))
    {
    goto end; //Enum
    }
    error_idVariable = insufficient_storage_error_error_id_FromString(error_id->valuestring);

    // insufficient_storage_error->total
    cJSON *total = cJSON_GetObjectItemCaseSensitive(insufficient_storage_errorJSON, "total");
    if (cJSON_IsNull(total)) {
        total = NULL;
    }
    if (!total) {
        goto end;
    }

    
    if(!cJSON_IsNumber(total))
    {
    goto end; //Numeric
    }

    // insufficient_storage_error->available
    cJSON *available = cJSON_GetObjectItemCaseSensitive(insufficient_storage_errorJSON, "available");
    if (cJSON_IsNull(available)) {
        available = NULL;
    }
    if (!available) {
        goto end;
    }

    
    if(!cJSON_IsNumber(available))
    {
    goto end; //Numeric
    }

    // insufficient_storage_error->required
    cJSON *required = cJSON_GetObjectItemCaseSensitive(insufficient_storage_errorJSON, "required");
    if (cJSON_IsNull(required)) {
        required = NULL;
    }
    if (!required) {
        goto end;
    }

    
    if(!cJSON_IsNumber(required))
    {
    goto end; //Numeric
    }


    insufficient_storage_error_local_var = insufficient_storage_error_create_internal (
        strdup(error->valuestring),
        error_idVariable,
        total->valuedouble,
        available->valuedouble,
        required->valuedouble
        );

    return insufficient_storage_error_local_var;
end:
    return NULL;

}
