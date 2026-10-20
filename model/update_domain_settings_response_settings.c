#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "update_domain_settings_response_settings.h"



static update_domain_settings_response_settings_t *update_domain_settings_response_settings_create_internal(
    int totp_required
    ) {
    update_domain_settings_response_settings_t *update_domain_settings_response_settings_local_var = malloc(sizeof(update_domain_settings_response_settings_t));
    if (!update_domain_settings_response_settings_local_var) {
        return NULL;
    }
    update_domain_settings_response_settings_local_var->totp_required = totp_required;

    update_domain_settings_response_settings_local_var->_library_owned = 1;
    return update_domain_settings_response_settings_local_var;
}

__attribute__((deprecated)) update_domain_settings_response_settings_t *update_domain_settings_response_settings_create(
    int totp_required
    ) {
    return update_domain_settings_response_settings_create_internal (
        totp_required
        );
}

void update_domain_settings_response_settings_free(update_domain_settings_response_settings_t *update_domain_settings_response_settings) {
    if(NULL == update_domain_settings_response_settings){
        return ;
    }
    if(update_domain_settings_response_settings->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "update_domain_settings_response_settings_free");
        return ;
    }
    listEntry_t *listEntry;
    free(update_domain_settings_response_settings);
}

cJSON *update_domain_settings_response_settings_convertToJSON(update_domain_settings_response_settings_t *update_domain_settings_response_settings) {
    cJSON *item = cJSON_CreateObject();

    // update_domain_settings_response_settings->totp_required
    if(update_domain_settings_response_settings->totp_required) {
    if(cJSON_AddBoolToObject(item, "totpRequired", update_domain_settings_response_settings->totp_required) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

update_domain_settings_response_settings_t *update_domain_settings_response_settings_parseFromJSON(cJSON *update_domain_settings_response_settingsJSON){

    update_domain_settings_response_settings_t *update_domain_settings_response_settings_local_var = NULL;

    // update_domain_settings_response_settings->totp_required
    cJSON *totp_required = cJSON_GetObjectItemCaseSensitive(update_domain_settings_response_settingsJSON, "totpRequired");
    if (cJSON_IsNull(totp_required)) {
        totp_required = NULL;
    }
    if (totp_required) { 
    if(!cJSON_IsBool(totp_required))
    {
    goto end; //Bool
    }
    }


    update_domain_settings_response_settings_local_var = update_domain_settings_response_settings_create_internal (
        totp_required ? totp_required->valueint : 0
        );

    return update_domain_settings_response_settings_local_var;
end:
    return NULL;

}
