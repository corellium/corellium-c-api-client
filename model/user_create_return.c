#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "user_create_return.h"



static user_create_return_t *user_create_return_create_internal(
    char *id
    ) {
    user_create_return_t *user_create_return_local_var = malloc(sizeof(user_create_return_t));
    if (!user_create_return_local_var) {
        return NULL;
    }
    user_create_return_local_var->id = id;

    user_create_return_local_var->_library_owned = 1;
    return user_create_return_local_var;
}

__attribute__((deprecated)) user_create_return_t *user_create_return_create(
    char *id
    ) {
    return user_create_return_create_internal (
        id
        );
}

void user_create_return_free(user_create_return_t *user_create_return) {
    if(NULL == user_create_return){
        return ;
    }
    if(user_create_return->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "user_create_return_free");
        return ;
    }
    listEntry_t *listEntry;
    if (user_create_return->id) {
        free(user_create_return->id);
        user_create_return->id = NULL;
    }
    free(user_create_return);
}

cJSON *user_create_return_convertToJSON(user_create_return_t *user_create_return) {
    cJSON *item = cJSON_CreateObject();

    // user_create_return->id
    if(user_create_return->id) {
    if(cJSON_AddStringToObject(item, "id", user_create_return->id) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

user_create_return_t *user_create_return_parseFromJSON(cJSON *user_create_returnJSON){

    user_create_return_t *user_create_return_local_var = NULL;

    // user_create_return->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(user_create_returnJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (id) { 
    if(!cJSON_IsString(id) && !cJSON_IsNull(id))
    {
    goto end; //String
    }
    }


    user_create_return_local_var = user_create_return_create_internal (
        id && !cJSON_IsNull(id) ? strdup(id->valuestring) : NULL
        );

    return user_create_return_local_var;
end:
    return NULL;

}
