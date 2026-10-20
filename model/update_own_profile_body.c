#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "update_own_profile_body.h"



static update_own_profile_body_t *update_own_profile_body_create_internal(
    char *label
    ) {
    update_own_profile_body_t *update_own_profile_body_local_var = malloc(sizeof(update_own_profile_body_t));
    if (!update_own_profile_body_local_var) {
        return NULL;
    }
    update_own_profile_body_local_var->label = label;

    update_own_profile_body_local_var->_library_owned = 1;
    return update_own_profile_body_local_var;
}

__attribute__((deprecated)) update_own_profile_body_t *update_own_profile_body_create(
    char *label
    ) {
    return update_own_profile_body_create_internal (
        label
        );
}

void update_own_profile_body_free(update_own_profile_body_t *update_own_profile_body) {
    if(NULL == update_own_profile_body){
        return ;
    }
    if(update_own_profile_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "update_own_profile_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (update_own_profile_body->label) {
        free(update_own_profile_body->label);
        update_own_profile_body->label = NULL;
    }
    free(update_own_profile_body);
}

cJSON *update_own_profile_body_convertToJSON(update_own_profile_body_t *update_own_profile_body) {
    cJSON *item = cJSON_CreateObject();

    // update_own_profile_body->label
    if (!update_own_profile_body->label) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "label", update_own_profile_body->label) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

update_own_profile_body_t *update_own_profile_body_parseFromJSON(cJSON *update_own_profile_bodyJSON){

    update_own_profile_body_t *update_own_profile_body_local_var = NULL;

    // update_own_profile_body->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(update_own_profile_bodyJSON, "label");
    if (cJSON_IsNull(label)) {
        label = NULL;
    }
    if (!label) {
        goto end;
    }

    
    if(!cJSON_IsString(label))
    {
    goto end; //String
    }


    update_own_profile_body_local_var = update_own_profile_body_create_internal (
        strdup(label->valuestring)
        );

    return update_own_profile_body_local_var;
end:
    return NULL;

}
