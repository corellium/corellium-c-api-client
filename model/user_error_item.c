#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "user_error_item.h"


char* user_error_item_error_id_ToString(corellium_api_user_error_item_ERRORID_e error_id) {
    char* error_idArray[] =  { "NULL", "UserError" };
    return error_idArray[error_id];
}

corellium_api_user_error_item_ERRORID_e user_error_item_error_id_FromString(char* error_id){
    int stringToReturn = 0;
    char *error_idArray[] =  { "NULL", "UserError" };
    size_t sizeofArray = sizeof(error_idArray) / sizeof(error_idArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(error_id, error_idArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static user_error_item_t *user_error_item_create_internal(
    char *error,
    corellium_api_user_error_item_ERRORID_e error_id,
    char *field,
    char *validator,
    list_t *project_ids
    ) {
    user_error_item_t *user_error_item_local_var = malloc(sizeof(user_error_item_t));
    if (!user_error_item_local_var) {
        return NULL;
    }
    user_error_item_local_var->error = error;
    user_error_item_local_var->error_id = error_id;
    user_error_item_local_var->field = field;
    user_error_item_local_var->validator = validator;
    user_error_item_local_var->project_ids = project_ids;

    user_error_item_local_var->_library_owned = 1;
    return user_error_item_local_var;
}

__attribute__((deprecated)) user_error_item_t *user_error_item_create(
    char *error,
    corellium_api_user_error_item_ERRORID_e error_id,
    char *field,
    char *validator,
    list_t *project_ids
    ) {
    return user_error_item_create_internal (
        error,
        error_id,
        field,
        validator,
        project_ids
        );
}

void user_error_item_free(user_error_item_t *user_error_item) {
    if(NULL == user_error_item){
        return ;
    }
    if(user_error_item->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "user_error_item_free");
        return ;
    }
    listEntry_t *listEntry;
    if (user_error_item->error) {
        free(user_error_item->error);
        user_error_item->error = NULL;
    }
    if (user_error_item->field) {
        free(user_error_item->field);
        user_error_item->field = NULL;
    }
    if (user_error_item->validator) {
        free(user_error_item->validator);
        user_error_item->validator = NULL;
    }
    if (user_error_item->project_ids) {
        list_ForEach(listEntry, user_error_item->project_ids) {
            free(listEntry->data);
        }
        list_freeList(user_error_item->project_ids);
        user_error_item->project_ids = NULL;
    }
    free(user_error_item);
}

cJSON *user_error_item_convertToJSON(user_error_item_t *user_error_item) {
    cJSON *item = cJSON_CreateObject();

    // user_error_item->error
    if (!user_error_item->error) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "error", user_error_item->error) == NULL) {
    goto fail; //String
    }


    // user_error_item->error_id
    if (corellium_api_user_error_item_ERRORID_NULL == user_error_item->error_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "errorID", user_error_item_error_id_ToString(user_error_item->error_id)) == NULL)
    {
    goto fail; //Enum
    }


    // user_error_item->field
    if(user_error_item->field) {
    if(cJSON_AddStringToObject(item, "field", user_error_item->field) == NULL) {
    goto fail; //String
    }
    }


    // user_error_item->validator
    if(user_error_item->validator) {
    if(cJSON_AddStringToObject(item, "validator", user_error_item->validator) == NULL) {
    goto fail; //String
    }
    }


    // user_error_item->project_ids
    if(user_error_item->project_ids) {
    cJSON *project_ids = cJSON_AddArrayToObject(item, "projectIds");
    if(project_ids == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *project_idsListEntry;
    list_ForEach(project_idsListEntry, user_error_item->project_ids) {
    if(cJSON_AddStringToObject(project_ids, "", project_idsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

user_error_item_t *user_error_item_parseFromJSON(cJSON *user_error_itemJSON){

    user_error_item_t *user_error_item_local_var = NULL;

    // define the local list for user_error_item->project_ids
    list_t *project_idsList = NULL;

    // user_error_item->error
    cJSON *error = cJSON_GetObjectItemCaseSensitive(user_error_itemJSON, "error");
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

    // user_error_item->error_id
    cJSON *error_id = cJSON_GetObjectItemCaseSensitive(user_error_itemJSON, "errorID");
    if (cJSON_IsNull(error_id)) {
        error_id = NULL;
    }
    if (!error_id) {
        goto end;
    }

    corellium_api_user_error_item_ERRORID_e error_idVariable;
    
    if(!cJSON_IsString(error_id))
    {
    goto end; //Enum
    }
    error_idVariable = user_error_item_error_id_FromString(error_id->valuestring);

    // user_error_item->field
    cJSON *field = cJSON_GetObjectItemCaseSensitive(user_error_itemJSON, "field");
    if (cJSON_IsNull(field)) {
        field = NULL;
    }
    if (field) { 
    if(!cJSON_IsString(field) && !cJSON_IsNull(field))
    {
    goto end; //String
    }
    }

    // user_error_item->validator
    cJSON *validator = cJSON_GetObjectItemCaseSensitive(user_error_itemJSON, "validator");
    if (cJSON_IsNull(validator)) {
        validator = NULL;
    }
    if (validator) { 
    if(!cJSON_IsString(validator) && !cJSON_IsNull(validator))
    {
    goto end; //String
    }
    }

    // user_error_item->project_ids
    cJSON *project_ids = cJSON_GetObjectItemCaseSensitive(user_error_itemJSON, "projectIds");
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


    user_error_item_local_var = user_error_item_create_internal (
        strdup(error->valuestring),
        error_idVariable,
        field && !cJSON_IsNull(field) ? strdup(field->valuestring) : NULL,
        validator && !cJSON_IsNull(validator) ? strdup(validator->valuestring) : NULL,
        project_ids ? project_idsList : NULL
        );

    return user_error_item_local_var;
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
    return NULL;

}
