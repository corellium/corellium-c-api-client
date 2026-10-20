#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "user_error_response.h"


char* user_error_response_error_id_ToString(corellium_api_user_error_response_ERRORID_e error_id) {
    char* error_idArray[] =  { "NULL", "UserErrors" };
    return error_idArray[error_id];
}

corellium_api_user_error_response_ERRORID_e user_error_response_error_id_FromString(char* error_id){
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

static user_error_response_t *user_error_response_create_internal(
    char *error,
    corellium_api_user_error_response_ERRORID_e error_id,
    char *field,
    char *validator,
    list_t *project_ids,
    list_t *missing_fw_assets,
    list_t *errors
    ) {
    user_error_response_t *user_error_response_local_var = malloc(sizeof(user_error_response_t));
    if (!user_error_response_local_var) {
        return NULL;
    }
    user_error_response_local_var->error = error;
    user_error_response_local_var->error_id = error_id;
    user_error_response_local_var->field = field;
    user_error_response_local_var->validator = validator;
    user_error_response_local_var->project_ids = project_ids;
    user_error_response_local_var->missing_fw_assets = missing_fw_assets;
    user_error_response_local_var->errors = errors;

    user_error_response_local_var->_library_owned = 1;
    return user_error_response_local_var;
}

__attribute__((deprecated)) user_error_response_t *user_error_response_create(
    char *error,
    corellium_api_user_error_response_ERRORID_e error_id,
    char *field,
    char *validator,
    list_t *project_ids,
    list_t *missing_fw_assets,
    list_t *errors
    ) {
    return user_error_response_create_internal (
        error,
        error_id,
        field,
        validator,
        project_ids,
        missing_fw_assets,
        errors
        );
}

void user_error_response_free(user_error_response_t *user_error_response) {
    if(NULL == user_error_response){
        return ;
    }
    if(user_error_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "user_error_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (user_error_response->error) {
        free(user_error_response->error);
        user_error_response->error = NULL;
    }
    if (user_error_response->field) {
        free(user_error_response->field);
        user_error_response->field = NULL;
    }
    if (user_error_response->validator) {
        free(user_error_response->validator);
        user_error_response->validator = NULL;
    }
    if (user_error_response->project_ids) {
        list_ForEach(listEntry, user_error_response->project_ids) {
            free(listEntry->data);
        }
        list_freeList(user_error_response->project_ids);
        user_error_response->project_ids = NULL;
    }
    if (user_error_response->missing_fw_assets) {
        list_ForEach(listEntry, user_error_response->missing_fw_assets) {
            free(listEntry->data);
        }
        list_freeList(user_error_response->missing_fw_assets);
        user_error_response->missing_fw_assets = NULL;
    }
    if (user_error_response->errors) {
        list_ForEach(listEntry, user_error_response->errors) {
            user_error_free(listEntry->data);
        }
        list_freeList(user_error_response->errors);
        user_error_response->errors = NULL;
    }
    free(user_error_response);
}

cJSON *user_error_response_convertToJSON(user_error_response_t *user_error_response) {
    cJSON *item = cJSON_CreateObject();

    // user_error_response->error
    if (!user_error_response->error) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "error", user_error_response->error) == NULL) {
    goto fail; //String
    }


    // user_error_response->error_id
    if (corellium_api_user_error_response_ERRORID_NULL == user_error_response->error_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "errorID", user_error_response_error_id_ToString(user_error_response->error_id)) == NULL)
    {
    goto fail; //Enum
    }


    // user_error_response->field
    if(user_error_response->field) {
    if(cJSON_AddStringToObject(item, "field", user_error_response->field) == NULL) {
    goto fail; //String
    }
    }


    // user_error_response->validator
    if(user_error_response->validator) {
    if(cJSON_AddStringToObject(item, "validator", user_error_response->validator) == NULL) {
    goto fail; //String
    }
    }


    // user_error_response->project_ids
    if(user_error_response->project_ids) {
    cJSON *project_ids = cJSON_AddArrayToObject(item, "projectIds");
    if(project_ids == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *project_idsListEntry;
    list_ForEach(project_idsListEntry, user_error_response->project_ids) {
    if(cJSON_AddStringToObject(project_ids, "", project_idsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // user_error_response->missing_fw_assets
    if(user_error_response->missing_fw_assets) {
    cJSON *missing_fw_assets = cJSON_AddArrayToObject(item, "missingFwAssets");
    if(missing_fw_assets == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *missing_fw_assetsListEntry;
    list_ForEach(missing_fw_assetsListEntry, user_error_response->missing_fw_assets) {
    if(cJSON_AddStringToObject(missing_fw_assets, "", missing_fw_assetsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // user_error_response->errors
    if (!user_error_response->errors) {
        goto fail;
    }
    cJSON *errors = cJSON_AddArrayToObject(item, "errors");
    if(errors == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *errorsListEntry;
    if (user_error_response->errors) {
    list_ForEach(errorsListEntry, user_error_response->errors) {
    cJSON *itemLocal = user_error_convertToJSON(errorsListEntry->data);
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

user_error_response_t *user_error_response_parseFromJSON(cJSON *user_error_responseJSON){

    user_error_response_t *user_error_response_local_var = NULL;

    // define the local list for user_error_response->project_ids
    list_t *project_idsList = NULL;

    // define the local list for user_error_response->missing_fw_assets
    list_t *missing_fw_assetsList = NULL;

    // define the local list for user_error_response->errors
    list_t *errorsList = NULL;

    // user_error_response->error
    cJSON *error = cJSON_GetObjectItemCaseSensitive(user_error_responseJSON, "error");
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

    // user_error_response->error_id
    cJSON *error_id = cJSON_GetObjectItemCaseSensitive(user_error_responseJSON, "errorID");
    if (cJSON_IsNull(error_id)) {
        error_id = NULL;
    }
    if (!error_id) {
        goto end;
    }

    corellium_api_user_error_response_ERRORID_e error_idVariable;
    
    if(!cJSON_IsString(error_id))
    {
    goto end; //Enum
    }
    error_idVariable = user_error_response_error_id_FromString(error_id->valuestring);

    // user_error_response->field
    cJSON *field = cJSON_GetObjectItemCaseSensitive(user_error_responseJSON, "field");
    if (cJSON_IsNull(field)) {
        field = NULL;
    }
    if (field) { 
    if(!cJSON_IsString(field) && !cJSON_IsNull(field))
    {
    goto end; //String
    }
    }

    // user_error_response->validator
    cJSON *validator = cJSON_GetObjectItemCaseSensitive(user_error_responseJSON, "validator");
    if (cJSON_IsNull(validator)) {
        validator = NULL;
    }
    if (validator) { 
    if(!cJSON_IsString(validator) && !cJSON_IsNull(validator))
    {
    goto end; //String
    }
    }

    // user_error_response->project_ids
    cJSON *project_ids = cJSON_GetObjectItemCaseSensitive(user_error_responseJSON, "projectIds");
    if (cJSON_IsNull(project_ids)) {
        project_ids = NULL;
    }
    if (project_ids) { 
    cJSON *project_ids_local = NULL;
    if(!cJSON_IsArray(project_ids)) {
        goto end;//primitive container
    }
    project_idsList = list_createList();

    cJSON_ArrayForEach(project_ids_local, project_ids)
    {
        if(!cJSON_IsString(project_ids_local))
        {
            goto end;
        }
        list_addElement(project_idsList , strdup(project_ids_local->valuestring));
    }
    }

    // user_error_response->missing_fw_assets
    cJSON *missing_fw_assets = cJSON_GetObjectItemCaseSensitive(user_error_responseJSON, "missingFwAssets");
    if (cJSON_IsNull(missing_fw_assets)) {
        missing_fw_assets = NULL;
    }
    if (missing_fw_assets) { 
    cJSON *missing_fw_assets_local = NULL;
    if(!cJSON_IsArray(missing_fw_assets)) {
        goto end;//primitive container
    }
    missing_fw_assetsList = list_createList();

    cJSON_ArrayForEach(missing_fw_assets_local, missing_fw_assets)
    {
        if(!cJSON_IsString(missing_fw_assets_local))
        {
            goto end;
        }
        list_addElement(missing_fw_assetsList , strdup(missing_fw_assets_local->valuestring));
    }
    }

    // user_error_response->errors
    cJSON *errors = cJSON_GetObjectItemCaseSensitive(user_error_responseJSON, "errors");
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
        user_error_t *errorsItem = user_error_parseFromJSON(errors_local_nonprimitive);

        list_addElement(errorsList, errorsItem);
    }


    user_error_response_local_var = user_error_response_create_internal (
        strdup(error->valuestring),
        error_idVariable,
        field && !cJSON_IsNull(field) ? strdup(field->valuestring) : NULL,
        validator && !cJSON_IsNull(validator) ? strdup(validator->valuestring) : NULL,
        project_ids ? project_idsList : NULL,
        missing_fw_assets ? missing_fw_assetsList : NULL,
        errorsList
        );

    return user_error_response_local_var;
end:
    if (project_idsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, project_idsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(project_idsList);
        project_idsList = NULL;
    }
    if (missing_fw_assetsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, missing_fw_assetsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(missing_fw_assetsList);
        missing_fw_assetsList = NULL;
    }
    if (errorsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, errorsList) {
            user_error_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(errorsList);
        errorsList = NULL;
    }
    return NULL;

}
