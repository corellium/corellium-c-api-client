#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "user_snapshots.h"



static user_snapshots_t *user_snapshots_create_internal(
    shared_snapshots_info_t *shared_with_user,
    shared_snapshots_info_t *shared_by_user
    ) {
    user_snapshots_t *user_snapshots_local_var = malloc(sizeof(user_snapshots_t));
    if (!user_snapshots_local_var) {
        return NULL;
    }
    user_snapshots_local_var->shared_with_user = shared_with_user;
    user_snapshots_local_var->shared_by_user = shared_by_user;

    user_snapshots_local_var->_library_owned = 1;
    return user_snapshots_local_var;
}

__attribute__((deprecated)) user_snapshots_t *user_snapshots_create(
    shared_snapshots_info_t *shared_with_user,
    shared_snapshots_info_t *shared_by_user
    ) {
    return user_snapshots_create_internal (
        shared_with_user,
        shared_by_user
        );
}

void user_snapshots_free(user_snapshots_t *user_snapshots) {
    if(NULL == user_snapshots){
        return ;
    }
    if(user_snapshots->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "user_snapshots_free");
        return ;
    }
    listEntry_t *listEntry;
    if (user_snapshots->shared_with_user) {
        shared_snapshots_info_free(user_snapshots->shared_with_user);
        user_snapshots->shared_with_user = NULL;
    }
    if (user_snapshots->shared_by_user) {
        shared_snapshots_info_free(user_snapshots->shared_by_user);
        user_snapshots->shared_by_user = NULL;
    }
    free(user_snapshots);
}

cJSON *user_snapshots_convertToJSON(user_snapshots_t *user_snapshots) {
    cJSON *item = cJSON_CreateObject();

    // user_snapshots->shared_with_user
    if (!user_snapshots->shared_with_user) {
        goto fail;
    }
    cJSON *shared_with_user_local_JSON = shared_snapshots_info_convertToJSON(user_snapshots->shared_with_user);
    if(shared_with_user_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "sharedWithUser", shared_with_user_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // user_snapshots->shared_by_user
    if (!user_snapshots->shared_by_user) {
        goto fail;
    }
    cJSON *shared_by_user_local_JSON = shared_snapshots_info_convertToJSON(user_snapshots->shared_by_user);
    if(shared_by_user_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "sharedByUser", shared_by_user_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

user_snapshots_t *user_snapshots_parseFromJSON(cJSON *user_snapshotsJSON){

    user_snapshots_t *user_snapshots_local_var = NULL;

    // define the local variable for user_snapshots->shared_with_user
    shared_snapshots_info_t *shared_with_user_local_nonprim = NULL;

    // define the local variable for user_snapshots->shared_by_user
    shared_snapshots_info_t *shared_by_user_local_nonprim = NULL;

    // user_snapshots->shared_with_user
    cJSON *shared_with_user = cJSON_GetObjectItemCaseSensitive(user_snapshotsJSON, "sharedWithUser");
    if (cJSON_IsNull(shared_with_user)) {
        shared_with_user = NULL;
    }
    if (!shared_with_user) {
        goto end;
    }

    
    shared_with_user_local_nonprim = shared_snapshots_info_parseFromJSON(shared_with_user); //nonprimitive

    // user_snapshots->shared_by_user
    cJSON *shared_by_user = cJSON_GetObjectItemCaseSensitive(user_snapshotsJSON, "sharedByUser");
    if (cJSON_IsNull(shared_by_user)) {
        shared_by_user = NULL;
    }
    if (!shared_by_user) {
        goto end;
    }

    
    shared_by_user_local_nonprim = shared_snapshots_info_parseFromJSON(shared_by_user); //nonprimitive


    user_snapshots_local_var = user_snapshots_create_internal (
        shared_with_user_local_nonprim,
        shared_by_user_local_nonprim
        );

    return user_snapshots_local_var;
end:
    if (shared_with_user_local_nonprim) {
        shared_snapshots_info_free(shared_with_user_local_nonprim);
        shared_with_user_local_nonprim = NULL;
    }
    if (shared_by_user_local_nonprim) {
        shared_snapshots_info_free(shared_by_user_local_nonprim);
        shared_by_user_local_nonprim = NULL;
    }
    return NULL;

}
