#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "team_created.h"



static team_created_t *team_created_create_internal(
    char *id
    ) {
    team_created_t *team_created_local_var = malloc(sizeof(team_created_t));
    if (!team_created_local_var) {
        return NULL;
    }
    team_created_local_var->id = id;

    team_created_local_var->_library_owned = 1;
    return team_created_local_var;
}

__attribute__((deprecated)) team_created_t *team_created_create(
    char *id
    ) {
    return team_created_create_internal (
        id
        );
}

void team_created_free(team_created_t *team_created) {
    if(NULL == team_created){
        return ;
    }
    if(team_created->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "team_created_free");
        return ;
    }
    listEntry_t *listEntry;
    if (team_created->id) {
        free(team_created->id);
        team_created->id = NULL;
    }
    free(team_created);
}

cJSON *team_created_convertToJSON(team_created_t *team_created) {
    cJSON *item = cJSON_CreateObject();

    // team_created->id
    if (!team_created->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", team_created->id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

team_created_t *team_created_parseFromJSON(cJSON *team_createdJSON){

    team_created_t *team_created_local_var = NULL;

    // team_created->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(team_createdJSON, "id");
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


    team_created_local_var = team_created_create_internal (
        strdup(id->valuestring)
        );

    return team_created_local_var;
end:
    return NULL;

}
