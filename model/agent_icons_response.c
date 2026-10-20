#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "agent_icons_response.h"



static agent_icons_response_t *agent_icons_response_create_internal(
    int success,
    double id,
    object_t *icons
    ) {
    agent_icons_response_t *agent_icons_response_local_var = malloc(sizeof(agent_icons_response_t));
    if (!agent_icons_response_local_var) {
        return NULL;
    }
    agent_icons_response_local_var->success = success;
    agent_icons_response_local_var->id = id;
    agent_icons_response_local_var->icons = icons;

    agent_icons_response_local_var->_library_owned = 1;
    return agent_icons_response_local_var;
}

__attribute__((deprecated)) agent_icons_response_t *agent_icons_response_create(
    int success,
    double id,
    object_t *icons
    ) {
    return agent_icons_response_create_internal (
        success,
        id,
        icons
        );
}

void agent_icons_response_free(agent_icons_response_t *agent_icons_response) {
    if(NULL == agent_icons_response){
        return ;
    }
    if(agent_icons_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "agent_icons_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (agent_icons_response->icons) {
        object_free(agent_icons_response->icons);
        agent_icons_response->icons = NULL;
    }
    free(agent_icons_response);
}

cJSON *agent_icons_response_convertToJSON(agent_icons_response_t *agent_icons_response) {
    cJSON *item = cJSON_CreateObject();

    // agent_icons_response->success
    if (!agent_icons_response->success) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "success", agent_icons_response->success) == NULL) {
    goto fail; //Bool
    }


    // agent_icons_response->id
    if (!agent_icons_response->id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "id", agent_icons_response->id) == NULL) {
    goto fail; //Numeric
    }


    // agent_icons_response->icons
    if (!agent_icons_response->icons) {
        goto fail;
    }
    cJSON *icons_object = object_convertToJSON(agent_icons_response->icons);
    if(icons_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "icons", icons_object);
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

agent_icons_response_t *agent_icons_response_parseFromJSON(cJSON *agent_icons_responseJSON){

    agent_icons_response_t *agent_icons_response_local_var = NULL;

    // agent_icons_response->success
    cJSON *success = cJSON_GetObjectItemCaseSensitive(agent_icons_responseJSON, "success");
    if (cJSON_IsNull(success)) {
        success = NULL;
    }
    if (!success) {
        goto end;
    }

    
    if(!cJSON_IsBool(success))
    {
    goto end; //Bool
    }

    // agent_icons_response->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(agent_icons_responseJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(id))
    {
    goto end; //Numeric
    }

    // agent_icons_response->icons
    cJSON *icons = cJSON_GetObjectItemCaseSensitive(agent_icons_responseJSON, "icons");
    if (cJSON_IsNull(icons)) {
        icons = NULL;
    }
    if (!icons) {
        goto end;
    }

    object_t *icons_local_object = NULL;
    
    icons_local_object = object_parseFromJSON(icons); //object


    agent_icons_response_local_var = agent_icons_response_create_internal (
        success->valueint,
        id->valuedouble,
        icons_local_object
        );

    return agent_icons_response_local_var;
end:
    return NULL;

}
