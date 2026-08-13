#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "user_created.h"



static user_created_t *user_created_create_internal(
    char *id
    ) {
    user_created_t *user_created_local_var = malloc(sizeof(user_created_t));
    if (!user_created_local_var) {
        return NULL;
    }
    user_created_local_var->id = id;

    user_created_local_var->_library_owned = 1;
    return user_created_local_var;
}

__attribute__((deprecated)) user_created_t *user_created_create(
    char *id
    ) {
    return user_created_create_internal (
        id
        );
}

void user_created_free(user_created_t *user_created) {
    if(NULL == user_created){
        return ;
    }
    if(user_created->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "user_created_free");
        return ;
    }
    listEntry_t *listEntry;
    if (user_created->id) {
        free(user_created->id);
        user_created->id = NULL;
    }
    free(user_created);
}

cJSON *user_created_convertToJSON(user_created_t *user_created) {
    cJSON *item = cJSON_CreateObject();

    // user_created->id
    if (!user_created->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", user_created->id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

user_created_t *user_created_parseFromJSON(cJSON *user_createdJSON){

    user_created_t *user_created_local_var = NULL;

    // user_created->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(user_createdJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }


    user_created_local_var = user_created_create_internal (
        strdup(id->valuestring)
        );

    return user_created_local_var;
end:
    return NULL;

}
