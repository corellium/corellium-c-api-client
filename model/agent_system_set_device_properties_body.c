#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "agent_system_set_device_properties_body.h"



static agent_system_set_device_properties_body_t *agent_system_set_device_properties_body_create_internal(
    char *model_id,
    char *manufacturer_id
    ) {
    agent_system_set_device_properties_body_t *agent_system_set_device_properties_body_local_var = malloc(sizeof(agent_system_set_device_properties_body_t));
    if (!agent_system_set_device_properties_body_local_var) {
        return NULL;
    }
    agent_system_set_device_properties_body_local_var->model_id = model_id;
    agent_system_set_device_properties_body_local_var->manufacturer_id = manufacturer_id;

    agent_system_set_device_properties_body_local_var->_library_owned = 1;
    return agent_system_set_device_properties_body_local_var;
}

__attribute__((deprecated)) agent_system_set_device_properties_body_t *agent_system_set_device_properties_body_create(
    char *model_id,
    char *manufacturer_id
    ) {
    return agent_system_set_device_properties_body_create_internal (
        model_id,
        manufacturer_id
        );
}

void agent_system_set_device_properties_body_free(agent_system_set_device_properties_body_t *agent_system_set_device_properties_body) {
    if(NULL == agent_system_set_device_properties_body){
        return ;
    }
    if(agent_system_set_device_properties_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "agent_system_set_device_properties_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (agent_system_set_device_properties_body->model_id) {
        free(agent_system_set_device_properties_body->model_id);
        agent_system_set_device_properties_body->model_id = NULL;
    }
    if (agent_system_set_device_properties_body->manufacturer_id) {
        free(agent_system_set_device_properties_body->manufacturer_id);
        agent_system_set_device_properties_body->manufacturer_id = NULL;
    }
    free(agent_system_set_device_properties_body);
}

cJSON *agent_system_set_device_properties_body_convertToJSON(agent_system_set_device_properties_body_t *agent_system_set_device_properties_body) {
    cJSON *item = cJSON_CreateObject();

    // agent_system_set_device_properties_body->model_id
    if(agent_system_set_device_properties_body->model_id) {
    if(cJSON_AddStringToObject(item, "modelId", agent_system_set_device_properties_body->model_id) == NULL) {
    goto fail; //String
    }
    }


    // agent_system_set_device_properties_body->manufacturer_id
    if(agent_system_set_device_properties_body->manufacturer_id) {
    if(cJSON_AddStringToObject(item, "manufacturerId", agent_system_set_device_properties_body->manufacturer_id) == NULL) {
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

agent_system_set_device_properties_body_t *agent_system_set_device_properties_body_parseFromJSON(cJSON *agent_system_set_device_properties_bodyJSON){

    agent_system_set_device_properties_body_t *agent_system_set_device_properties_body_local_var = NULL;

    // agent_system_set_device_properties_body->model_id
    cJSON *model_id = cJSON_GetObjectItemCaseSensitive(agent_system_set_device_properties_bodyJSON, "modelId");
    if (cJSON_IsNull(model_id)) {
        model_id = NULL;
    }
    if (model_id) { 
    if(!cJSON_IsString(model_id) && !cJSON_IsNull(model_id))
    {
    goto end; //String
    }
    }

    // agent_system_set_device_properties_body->manufacturer_id
    cJSON *manufacturer_id = cJSON_GetObjectItemCaseSensitive(agent_system_set_device_properties_bodyJSON, "manufacturerId");
    if (cJSON_IsNull(manufacturer_id)) {
        manufacturer_id = NULL;
    }
    if (manufacturer_id) { 
    if(!cJSON_IsString(manufacturer_id) && !cJSON_IsNull(manufacturer_id))
    {
    goto end; //String
    }
    }


    agent_system_set_device_properties_body_local_var = agent_system_set_device_properties_body_create_internal (
        model_id && !cJSON_IsNull(model_id) ? strdup(model_id->valuestring) : NULL,
        manufacturer_id && !cJSON_IsNull(manufacturer_id) ? strdup(manufacturer_id->valuestring) : NULL
        );

    return agent_system_set_device_properties_body_local_var;
end:
    return NULL;

}
