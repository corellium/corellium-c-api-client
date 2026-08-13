#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "invite_created_entry.h"



static invite_created_entry_t *invite_created_entry_create_internal(
    invite_created_t *invite
    ) {
    invite_created_entry_t *invite_created_entry_local_var = malloc(sizeof(invite_created_entry_t));
    if (!invite_created_entry_local_var) {
        return NULL;
    }
    invite_created_entry_local_var->invite = invite;

    invite_created_entry_local_var->_library_owned = 1;
    return invite_created_entry_local_var;
}

__attribute__((deprecated)) invite_created_entry_t *invite_created_entry_create(
    invite_created_t *invite
    ) {
    return invite_created_entry_create_internal (
        invite
        );
}

void invite_created_entry_free(invite_created_entry_t *invite_created_entry) {
    if(NULL == invite_created_entry){
        return ;
    }
    if(invite_created_entry->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "invite_created_entry_free");
        return ;
    }
    listEntry_t *listEntry;
    if (invite_created_entry->invite) {
        invite_created_free(invite_created_entry->invite);
        invite_created_entry->invite = NULL;
    }
    free(invite_created_entry);
}

cJSON *invite_created_entry_convertToJSON(invite_created_entry_t *invite_created_entry) {
    cJSON *item = cJSON_CreateObject();

    // invite_created_entry->invite
    if(invite_created_entry->invite) {
    cJSON *invite_local_JSON = invite_created_convertToJSON(invite_created_entry->invite);
    if(invite_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "invite", invite_local_JSON);
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

invite_created_entry_t *invite_created_entry_parseFromJSON(cJSON *invite_created_entryJSON){

    invite_created_entry_t *invite_created_entry_local_var = NULL;

    // define the local variable for invite_created_entry->invite
    invite_created_t *invite_local_nonprim = NULL;

    // invite_created_entry->invite
    cJSON *invite = cJSON_GetObjectItemCaseSensitive(invite_created_entryJSON, "invite");
    if (cJSON_IsNull(invite)) {
        invite = NULL;
    }
    if (invite) { 
    invite_local_nonprim = invite_created_parseFromJSON(invite); //nonprimitive
    }


    invite_created_entry_local_var = invite_created_entry_create_internal (
        invite ? invite_local_nonprim : NULL
        );

    return invite_created_entry_local_var;
end:
    if (invite_local_nonprim) {
        invite_created_free(invite_local_nonprim);
        invite_local_nonprim = NULL;
    }
    return NULL;

}
