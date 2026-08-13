#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "agent_install_body_v1.h"



static agent_install_body_v1_t *agent_install_body_v1_create_internal(
    char *path
    ) {
    agent_install_body_v1_t *agent_install_body_v1_local_var = malloc(sizeof(agent_install_body_v1_t));
    if (!agent_install_body_v1_local_var) {
        return NULL;
    }
    agent_install_body_v1_local_var->path = path;

    agent_install_body_v1_local_var->_library_owned = 1;
    return agent_install_body_v1_local_var;
}

__attribute__((deprecated)) agent_install_body_v1_t *agent_install_body_v1_create(
    char *path
    ) {
    return agent_install_body_v1_create_internal (
        path
        );
}

void agent_install_body_v1_free(agent_install_body_v1_t *agent_install_body_v1) {
    if(NULL == agent_install_body_v1){
        return ;
    }
    if(agent_install_body_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "agent_install_body_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (agent_install_body_v1->path) {
        free(agent_install_body_v1->path);
        agent_install_body_v1->path = NULL;
    }
    free(agent_install_body_v1);
}

cJSON *agent_install_body_v1_convertToJSON(agent_install_body_v1_t *agent_install_body_v1) {
    cJSON *item = cJSON_CreateObject();

    // agent_install_body_v1->path
    if(agent_install_body_v1->path) {
    if(cJSON_AddStringToObject(item, "path", agent_install_body_v1->path) == NULL) {
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

agent_install_body_v1_t *agent_install_body_v1_parseFromJSON(cJSON *agent_install_body_v1JSON){

    agent_install_body_v1_t *agent_install_body_v1_local_var = NULL;

    // agent_install_body_v1->path
    cJSON *path = cJSON_GetObjectItemCaseSensitive(agent_install_body_v1JSON, "path");
    if (cJSON_IsNull(path)) {
        path = NULL;
    }
    if (path) { 
    if(!cJSON_IsString(path) && !cJSON_IsNull(path))
    {
    goto end; //String
    }
    }


    agent_install_body_v1_local_var = agent_install_body_v1_create_internal (
        path && !cJSON_IsNull(path) ? strdup(path->valuestring) : NULL
        );

    return agent_install_body_v1_local_var;
end:
    return NULL;

}
