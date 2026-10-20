#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "login_result_domain_disabled.h"



static login_result_domain_disabled_t *login_result_domain_disabled_create_internal(
    char *type,
    char *cancel_date
    ) {
    login_result_domain_disabled_t *login_result_domain_disabled_local_var = malloc(sizeof(login_result_domain_disabled_t));
    if (!login_result_domain_disabled_local_var) {
        return NULL;
    }
    login_result_domain_disabled_local_var->type = type;
    login_result_domain_disabled_local_var->cancel_date = cancel_date;

    login_result_domain_disabled_local_var->_library_owned = 1;
    return login_result_domain_disabled_local_var;
}

__attribute__((deprecated)) login_result_domain_disabled_t *login_result_domain_disabled_create(
    char *type,
    char *cancel_date
    ) {
    return login_result_domain_disabled_create_internal (
        type,
        cancel_date
        );
}

void login_result_domain_disabled_free(login_result_domain_disabled_t *login_result_domain_disabled) {
    if(NULL == login_result_domain_disabled){
        return ;
    }
    if(login_result_domain_disabled->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "login_result_domain_disabled_free");
        return ;
    }
    listEntry_t *listEntry;
    if (login_result_domain_disabled->type) {
        free(login_result_domain_disabled->type);
        login_result_domain_disabled->type = NULL;
    }
    if (login_result_domain_disabled->cancel_date) {
        free(login_result_domain_disabled->cancel_date);
        login_result_domain_disabled->cancel_date = NULL;
    }
    free(login_result_domain_disabled);
}

cJSON *login_result_domain_disabled_convertToJSON(login_result_domain_disabled_t *login_result_domain_disabled) {
    cJSON *item = cJSON_CreateObject();

    // login_result_domain_disabled->type
    if(login_result_domain_disabled->type) {
    if(cJSON_AddStringToObject(item, "type", login_result_domain_disabled->type) == NULL) {
    goto fail; //String
    }
    }


    // login_result_domain_disabled->cancel_date
    if(login_result_domain_disabled->cancel_date) {
    if(cJSON_AddStringToObject(item, "cancelDate", login_result_domain_disabled->cancel_date) == NULL) {
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

login_result_domain_disabled_t *login_result_domain_disabled_parseFromJSON(cJSON *login_result_domain_disabledJSON){

    login_result_domain_disabled_t *login_result_domain_disabled_local_var = NULL;

    // login_result_domain_disabled->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(login_result_domain_disabledJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (type) { 
    if(!cJSON_IsString(type) && !cJSON_IsNull(type))
    {
    goto end; //String
    }
    }

    // login_result_domain_disabled->cancel_date
    cJSON *cancel_date = cJSON_GetObjectItemCaseSensitive(login_result_domain_disabledJSON, "cancelDate");
    if (cJSON_IsNull(cancel_date)) {
        cancel_date = NULL;
    }
    if (cancel_date) { 
    if(!cJSON_IsString(cancel_date) && !cJSON_IsNull(cancel_date))
    {
    goto end; //DateTime
    }
    }


    login_result_domain_disabled_local_var = login_result_domain_disabled_create_internal (
        type && !cJSON_IsNull(type) ? strdup(type->valuestring) : NULL,
        cancel_date && !cJSON_IsNull(cancel_date) ? strdup(cancel_date->valuestring) : NULL
        );

    return login_result_domain_disabled_local_var;
end:
    return NULL;

}
