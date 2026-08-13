#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "user_update.h"



static user_update_t *user_update_create_internal(
    char *name,
    char *label
    ) {
    user_update_t *user_update_local_var = malloc(sizeof(user_update_t));
    if (!user_update_local_var) {
        return NULL;
    }
    user_update_local_var->name = name;
    user_update_local_var->label = label;

    user_update_local_var->_library_owned = 1;
    return user_update_local_var;
}

__attribute__((deprecated)) user_update_t *user_update_create(
    char *name,
    char *label
    ) {
    return user_update_create_internal (
        name,
        label
        );
}

void user_update_free(user_update_t *user_update) {
    if(NULL == user_update){
        return ;
    }
    if(user_update->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "user_update_free");
        return ;
    }
    listEntry_t *listEntry;
    if (user_update->name) {
        free(user_update->name);
        user_update->name = NULL;
    }
    if (user_update->label) {
        free(user_update->label);
        user_update->label = NULL;
    }
    free(user_update);
}

cJSON *user_update_convertToJSON(user_update_t *user_update) {
    cJSON *item = cJSON_CreateObject();

    // user_update->name
    if(user_update->name) {
    if(cJSON_AddStringToObject(item, "name", user_update->name) == NULL) {
    goto fail; //String
    }
    }


    // user_update->label
    if(user_update->label) {
    if(cJSON_AddStringToObject(item, "label", user_update->label) == NULL) {
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

user_update_t *user_update_parseFromJSON(cJSON *user_updateJSON){

    user_update_t *user_update_local_var = NULL;

    // user_update->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(user_updateJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // user_update->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(user_updateJSON, "label");
    if (cJSON_IsNull(label)) {
        label = NULL;
    }
    if (label) { 
    if(!cJSON_IsString(label) && !cJSON_IsNull(label))
    {
    goto end; //String
    }
    }


    user_update_local_var = user_update_create_internal (
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        label && !cJSON_IsNull(label) ? strdup(label->valuestring) : NULL
        );

    return user_update_local_var;
end:
    return NULL;

}
