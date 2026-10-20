#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "edit_invites_body_changes.h"



static edit_invites_body_changes_t *edit_invites_body_changes_create_internal(
    invite_settings_t *settings
    ) {
    edit_invites_body_changes_t *edit_invites_body_changes_local_var = malloc(sizeof(edit_invites_body_changes_t));
    if (!edit_invites_body_changes_local_var) {
        return NULL;
    }
    edit_invites_body_changes_local_var->settings = settings;

    edit_invites_body_changes_local_var->_library_owned = 1;
    return edit_invites_body_changes_local_var;
}

__attribute__((deprecated)) edit_invites_body_changes_t *edit_invites_body_changes_create(
    invite_settings_t *settings
    ) {
    return edit_invites_body_changes_create_internal (
        settings
        );
}

void edit_invites_body_changes_free(edit_invites_body_changes_t *edit_invites_body_changes) {
    if(NULL == edit_invites_body_changes){
        return ;
    }
    if(edit_invites_body_changes->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "edit_invites_body_changes_free");
        return ;
    }
    listEntry_t *listEntry;
    if (edit_invites_body_changes->settings) {
        invite_settings_free(edit_invites_body_changes->settings);
        edit_invites_body_changes->settings = NULL;
    }
    free(edit_invites_body_changes);
}

cJSON *edit_invites_body_changes_convertToJSON(edit_invites_body_changes_t *edit_invites_body_changes) {
    cJSON *item = cJSON_CreateObject();

    // edit_invites_body_changes->settings
    if(edit_invites_body_changes->settings) {
    cJSON *settings_local_JSON = invite_settings_convertToJSON(edit_invites_body_changes->settings);
    if(settings_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "settings", settings_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

edit_invites_body_changes_t *edit_invites_body_changes_parseFromJSON(cJSON *edit_invites_body_changesJSON){

    edit_invites_body_changes_t *edit_invites_body_changes_local_var = NULL;

    // define the local variable for edit_invites_body_changes->settings
    invite_settings_t *settings_local_nonprim = NULL;

    // edit_invites_body_changes->settings
    cJSON *settings = cJSON_GetObjectItemCaseSensitive(edit_invites_body_changesJSON, "settings");
    if (cJSON_IsNull(settings)) {
        settings = NULL;
    }
    if (settings) { 
    settings_local_nonprim = invite_settings_parseFromJSON(settings); //nonprimitive
    }


    edit_invites_body_changes_local_var = edit_invites_body_changes_create_internal (
        settings ? settings_local_nonprim : NULL
        );

    return edit_invites_body_changes_local_var;
end:
    if (settings_local_nonprim) {
        invite_settings_free(settings_local_nonprim);
        settings_local_nonprim = NULL;
    }
    return NULL;

}
