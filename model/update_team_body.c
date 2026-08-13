#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "update_team_body.h"



static update_team_body_t *update_team_body_create_internal(
    char *name
    ) {
    update_team_body_t *update_team_body_local_var = malloc(sizeof(update_team_body_t));
    if (!update_team_body_local_var) {
        return NULL;
    }
    update_team_body_local_var->name = name;

    update_team_body_local_var->_library_owned = 1;
    return update_team_body_local_var;
}

__attribute__((deprecated)) update_team_body_t *update_team_body_create(
    char *name
    ) {
    return update_team_body_create_internal (
        name
        );
}

void update_team_body_free(update_team_body_t *update_team_body) {
    if(NULL == update_team_body){
        return ;
    }
    if(update_team_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "update_team_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (update_team_body->name) {
        free(update_team_body->name);
        update_team_body->name = NULL;
    }
    free(update_team_body);
}

cJSON *update_team_body_convertToJSON(update_team_body_t *update_team_body) {
    cJSON *item = cJSON_CreateObject();

    // update_team_body->name
    if(update_team_body->name) {
    if(cJSON_AddStringToObject(item, "name", update_team_body->name) == NULL) {
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

update_team_body_t *update_team_body_parseFromJSON(cJSON *update_team_bodyJSON){

    update_team_body_t *update_team_body_local_var = NULL;

    // update_team_body->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(update_team_bodyJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }


    update_team_body_local_var = update_team_body_create_internal (
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL
        );

    return update_team_body_local_var;
end:
    return NULL;

}
