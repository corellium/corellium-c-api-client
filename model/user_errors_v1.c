#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "user_errors_v1.h"


char* user_errors_v1_error_id_ToString(corellium_api_user_errors_v1_ERRORID_e error_id) {
    char* error_idArray[] =  { "NULL", "UserErrors" };
    return error_idArray[error_id];
}

corellium_api_user_errors_v1_ERRORID_e user_errors_v1_error_id_FromString(char* error_id){
    int stringToReturn = 0;
    char *error_idArray[] =  { "NULL", "UserErrors" };
    size_t sizeofArray = sizeof(error_idArray) / sizeof(error_idArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(error_id, error_idArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static user_errors_v1_t *user_errors_v1_create_internal(
    char *error,
    corellium_api_user_errors_v1_ERRORID_e error_id,
    list_t *errors
    ) {
    user_errors_v1_t *user_errors_v1_local_var = malloc(sizeof(user_errors_v1_t));
    if (!user_errors_v1_local_var) {
        return NULL;
    }
    user_errors_v1_local_var->error = error;
    user_errors_v1_local_var->error_id = error_id;
    user_errors_v1_local_var->errors = errors;

    user_errors_v1_local_var->_library_owned = 1;
    return user_errors_v1_local_var;
}

__attribute__((deprecated)) user_errors_v1_t *user_errors_v1_create(
    char *error,
    corellium_api_user_errors_v1_ERRORID_e error_id,
    list_t *errors
    ) {
    return user_errors_v1_create_internal (
        error,
        error_id,
        errors
        );
}

void user_errors_v1_free(user_errors_v1_t *user_errors_v1) {
    if(NULL == user_errors_v1){
        return ;
    }
    if(user_errors_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "user_errors_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (user_errors_v1->error) {
        free(user_errors_v1->error);
        user_errors_v1->error = NULL;
    }
    if (user_errors_v1->errors) {
        list_ForEach(listEntry, user_errors_v1->errors) {
            user_error_item_free(listEntry->data);
        }
        list_freeList(user_errors_v1->errors);
        user_errors_v1->errors = NULL;
    }
    free(user_errors_v1);
}

cJSON *user_errors_v1_convertToJSON(user_errors_v1_t *user_errors_v1) {
    cJSON *item = cJSON_CreateObject();

    // user_errors_v1->error
    if (!user_errors_v1->error) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "error", user_errors_v1->error) == NULL) {
    goto fail; //String
    }


    // user_errors_v1->error_id
    if (corellium_api_user_errors_v1_ERRORID_NULL == user_errors_v1->error_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "errorID", user_errors_v1_error_id_ToString(user_errors_v1->error_id)) == NULL)
    {
    goto fail; //Enum
    }


    // user_errors_v1->errors
    if (!user_errors_v1->errors) {
        goto fail;
    }
    cJSON *errors = cJSON_AddArrayToObject(item, "errors");
    if(errors == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *errorsListEntry;
    if (user_errors_v1->errors) {
    list_ForEach(errorsListEntry, user_errors_v1->errors) {
    cJSON *itemLocal = user_error_item_convertToJSON(errorsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(errors, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

user_errors_v1_t *user_errors_v1_parseFromJSON(cJSON *user_errors_v1JSON){

    user_errors_v1_t *user_errors_v1_local_var = NULL;

    // define the local list for user_errors_v1->errors
    list_t *errorsList = NULL;

    // user_errors_v1->error
    cJSON *error = cJSON_GetObjectItemCaseSensitive(user_errors_v1JSON, "error");
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

    // user_errors_v1->error_id
    cJSON *error_id = cJSON_GetObjectItemCaseSensitive(user_errors_v1JSON, "errorID");
    if (cJSON_IsNull(error_id)) {
        error_id = NULL;
    }
    if (!error_id) {
        goto end;
    }

    corellium_api_user_errors_v1_ERRORID_e error_idVariable;
    
    if(!cJSON_IsString(error_id))
    {
    goto end; //Enum
    }
    error_idVariable = user_errors_v1_error_id_FromString(error_id->valuestring);

    // user_errors_v1->errors
    cJSON *errors = cJSON_GetObjectItemCaseSensitive(user_errors_v1JSON, "errors");
    if (cJSON_IsNull(errors)) {
        errors = NULL;
    }
    if (!errors) {
        goto end;
    }

    
    cJSON *errors_local_nonprimitive = NULL;
    if(!cJSON_IsArray(errors)){
        goto end; //nonprimitive container
    }

    errorsList = list_createList();

    cJSON_ArrayForEach(errors_local_nonprimitive,errors )
    {
        if(!cJSON_IsObject(errors_local_nonprimitive)){
            goto end;
        }
        user_error_item_t *errorsItem = user_error_item_parseFromJSON(errors_local_nonprimitive);

        list_addElement(errorsList, errorsItem);
    }


    user_errors_v1_local_var = user_errors_v1_create_internal (
        strdup(error->valuestring),
        error_idVariable,
        errorsList
        );

    return user_errors_v1_local_var;
end:
    if (errorsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, errorsList) {
            user_error_item_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(errorsList);
        errorsList = NULL;
    }
    return NULL;

}
