#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "agent_system_get_prop_body_v1.h"



static agent_system_get_prop_body_v1_t *agent_system_get_prop_body_v1_create_internal(
    char *property
    ) {
    agent_system_get_prop_body_v1_t *agent_system_get_prop_body_v1_local_var = malloc(sizeof(agent_system_get_prop_body_v1_t));
    if (!agent_system_get_prop_body_v1_local_var) {
        return NULL;
    }
    agent_system_get_prop_body_v1_local_var->property = property;

    agent_system_get_prop_body_v1_local_var->_library_owned = 1;
    return agent_system_get_prop_body_v1_local_var;
}

__attribute__((deprecated)) agent_system_get_prop_body_v1_t *agent_system_get_prop_body_v1_create(
    char *property
    ) {
    return agent_system_get_prop_body_v1_create_internal (
        property
        );
}

void agent_system_get_prop_body_v1_free(agent_system_get_prop_body_v1_t *agent_system_get_prop_body_v1) {
    if(NULL == agent_system_get_prop_body_v1){
        return ;
    }
    if(agent_system_get_prop_body_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "agent_system_get_prop_body_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (agent_system_get_prop_body_v1->property) {
        free(agent_system_get_prop_body_v1->property);
        agent_system_get_prop_body_v1->property = NULL;
    }
    free(agent_system_get_prop_body_v1);
}

cJSON *agent_system_get_prop_body_v1_convertToJSON(agent_system_get_prop_body_v1_t *agent_system_get_prop_body_v1) {
    cJSON *item = cJSON_CreateObject();

    // agent_system_get_prop_body_v1->property
    if (!agent_system_get_prop_body_v1->property) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "property", agent_system_get_prop_body_v1->property) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

agent_system_get_prop_body_v1_t *agent_system_get_prop_body_v1_parseFromJSON(cJSON *agent_system_get_prop_body_v1JSON){

    agent_system_get_prop_body_v1_t *agent_system_get_prop_body_v1_local_var = NULL;

    // agent_system_get_prop_body_v1->property
    cJSON *property = cJSON_GetObjectItemCaseSensitive(agent_system_get_prop_body_v1JSON, "property");
    if (cJSON_IsNull(property)) {
        property = NULL;
    }
    if (!property) {
        goto end;
    }

    
    if(!cJSON_IsString(property))
    {
    goto end; //String
    }


    agent_system_get_prop_body_v1_local_var = agent_system_get_prop_body_v1_create_internal (
        strdup(property->valuestring)
        );

    return agent_system_get_prop_body_v1_local_var;
end:
    return NULL;

}
