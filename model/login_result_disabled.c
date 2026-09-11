#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "login_result_disabled.h"



static login_result_disabled_t *login_result_disabled_create_internal(
    char *type,
    char *disabled_at,
    char *delete_instances_at,
    char *cancel_date
    ) {
    login_result_disabled_t *login_result_disabled_local_var = malloc(sizeof(login_result_disabled_t));
    if (!login_result_disabled_local_var) {
        return NULL;
    }
    login_result_disabled_local_var->type = type;
    login_result_disabled_local_var->disabled_at = disabled_at;
    login_result_disabled_local_var->delete_instances_at = delete_instances_at;
    login_result_disabled_local_var->cancel_date = cancel_date;

    login_result_disabled_local_var->_library_owned = 1;
    return login_result_disabled_local_var;
}

__attribute__((deprecated)) login_result_disabled_t *login_result_disabled_create(
    char *type,
    char *disabled_at,
    char *delete_instances_at,
    char *cancel_date
    ) {
    return login_result_disabled_create_internal (
        type,
        disabled_at,
        delete_instances_at,
        cancel_date
        );
}

void login_result_disabled_free(login_result_disabled_t *login_result_disabled) {
    if(NULL == login_result_disabled){
        return ;
    }
    if(login_result_disabled->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "login_result_disabled_free");
        return ;
    }
    listEntry_t *listEntry;
    if (login_result_disabled->type) {
        free(login_result_disabled->type);
        login_result_disabled->type = NULL;
    }
    if (login_result_disabled->disabled_at) {
        free(login_result_disabled->disabled_at);
        login_result_disabled->disabled_at = NULL;
    }
    if (login_result_disabled->delete_instances_at) {
        free(login_result_disabled->delete_instances_at);
        login_result_disabled->delete_instances_at = NULL;
    }
    if (login_result_disabled->cancel_date) {
        free(login_result_disabled->cancel_date);
        login_result_disabled->cancel_date = NULL;
    }
    free(login_result_disabled);
}

cJSON *login_result_disabled_convertToJSON(login_result_disabled_t *login_result_disabled) {
    cJSON *item = cJSON_CreateObject();

    // login_result_disabled->type
    if (!login_result_disabled->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", login_result_disabled->type) == NULL) {
    goto fail; //String
    }


    // login_result_disabled->disabled_at
    if(login_result_disabled->disabled_at) {
    if(cJSON_AddStringToObject(item, "disabledAt", login_result_disabled->disabled_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // login_result_disabled->delete_instances_at
    if(login_result_disabled->delete_instances_at) {
    if(cJSON_AddStringToObject(item, "deleteInstancesAt", login_result_disabled->delete_instances_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // login_result_disabled->cancel_date
    if(login_result_disabled->cancel_date) {
    if(cJSON_AddStringToObject(item, "cancelDate", login_result_disabled->cancel_date) == NULL) {
    goto fail; //Date-Time
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

login_result_disabled_t *login_result_disabled_parseFromJSON(cJSON *login_result_disabledJSON){

    login_result_disabled_t *login_result_disabled_local_var = NULL;

    // login_result_disabled->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(login_result_disabledJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }

    // login_result_disabled->disabled_at
    cJSON *disabled_at = cJSON_GetObjectItemCaseSensitive(login_result_disabledJSON, "disabledAt");
    if (cJSON_IsNull(disabled_at)) {
        disabled_at = NULL;
    }
    if (disabled_at) { 
    if(!cJSON_IsString(disabled_at) && !cJSON_IsNull(disabled_at))
    {
    goto end; //DateTime
    }
    }

    // login_result_disabled->delete_instances_at
    cJSON *delete_instances_at = cJSON_GetObjectItemCaseSensitive(login_result_disabledJSON, "deleteInstancesAt");
    if (cJSON_IsNull(delete_instances_at)) {
        delete_instances_at = NULL;
    }
    if (delete_instances_at) { 
    if(!cJSON_IsString(delete_instances_at) && !cJSON_IsNull(delete_instances_at))
    {
    goto end; //DateTime
    }
    }

    // login_result_disabled->cancel_date
    cJSON *cancel_date = cJSON_GetObjectItemCaseSensitive(login_result_disabledJSON, "cancelDate");
    if (cJSON_IsNull(cancel_date)) {
        cancel_date = NULL;
    }
    if (cancel_date) { 
    if(!cJSON_IsString(cancel_date) && !cJSON_IsNull(cancel_date))
    {
    goto end; //DateTime
    }
    }


    login_result_disabled_local_var = login_result_disabled_create_internal (
        strdup(type->valuestring),
        disabled_at && !cJSON_IsNull(disabled_at) ? strdup(disabled_at->valuestring) : NULL,
        delete_instances_at && !cJSON_IsNull(delete_instances_at) ? strdup(delete_instances_at->valuestring) : NULL,
        cancel_date && !cJSON_IsNull(cancel_date) ? strdup(cancel_date->valuestring) : NULL
        );

    return login_result_disabled_local_var;
end:
    return NULL;

}
