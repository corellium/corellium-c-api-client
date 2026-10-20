#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "agent_file_attributes_body.h"



static agent_file_attributes_body_t *agent_file_attributes_body_create_internal(
    char *path,
    double mode,
    double uid,
    double gid
    ) {
    agent_file_attributes_body_t *agent_file_attributes_body_local_var = malloc(sizeof(agent_file_attributes_body_t));
    if (!agent_file_attributes_body_local_var) {
        return NULL;
    }
    agent_file_attributes_body_local_var->path = path;
    agent_file_attributes_body_local_var->mode = mode;
    agent_file_attributes_body_local_var->uid = uid;
    agent_file_attributes_body_local_var->gid = gid;

    agent_file_attributes_body_local_var->_library_owned = 1;
    return agent_file_attributes_body_local_var;
}

__attribute__((deprecated)) agent_file_attributes_body_t *agent_file_attributes_body_create(
    char *path,
    double mode,
    double uid,
    double gid
    ) {
    return agent_file_attributes_body_create_internal (
        path,
        mode,
        uid,
        gid
        );
}

void agent_file_attributes_body_free(agent_file_attributes_body_t *agent_file_attributes_body) {
    if(NULL == agent_file_attributes_body){
        return ;
    }
    if(agent_file_attributes_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "agent_file_attributes_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (agent_file_attributes_body->path) {
        free(agent_file_attributes_body->path);
        agent_file_attributes_body->path = NULL;
    }
    free(agent_file_attributes_body);
}

cJSON *agent_file_attributes_body_convertToJSON(agent_file_attributes_body_t *agent_file_attributes_body) {
    cJSON *item = cJSON_CreateObject();

    // agent_file_attributes_body->path
    if(agent_file_attributes_body->path) {
    if(cJSON_AddStringToObject(item, "path", agent_file_attributes_body->path) == NULL) {
    goto fail; //String
    }
    }


    // agent_file_attributes_body->mode
    if(agent_file_attributes_body->mode) {
    if(cJSON_AddNumberToObject(item, "mode", agent_file_attributes_body->mode) == NULL) {
    goto fail; //Numeric
    }
    }


    // agent_file_attributes_body->uid
    if(agent_file_attributes_body->uid) {
    if(cJSON_AddNumberToObject(item, "uid", agent_file_attributes_body->uid) == NULL) {
    goto fail; //Numeric
    }
    }


    // agent_file_attributes_body->gid
    if(agent_file_attributes_body->gid) {
    if(cJSON_AddNumberToObject(item, "gid", agent_file_attributes_body->gid) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

agent_file_attributes_body_t *agent_file_attributes_body_parseFromJSON(cJSON *agent_file_attributes_bodyJSON){

    agent_file_attributes_body_t *agent_file_attributes_body_local_var = NULL;

    // agent_file_attributes_body->path
    cJSON *path = cJSON_GetObjectItemCaseSensitive(agent_file_attributes_bodyJSON, "path");
    if (cJSON_IsNull(path)) {
        path = NULL;
    }
    if (path) { 
    if(!cJSON_IsString(path) && !cJSON_IsNull(path))
    {
    goto end; //String
    }
    }

    // agent_file_attributes_body->mode
    cJSON *mode = cJSON_GetObjectItemCaseSensitive(agent_file_attributes_bodyJSON, "mode");
    if (cJSON_IsNull(mode)) {
        mode = NULL;
    }
    if (mode) { 
    if(!cJSON_IsNumber(mode))
    {
    goto end; //Numeric
    }
    }

    // agent_file_attributes_body->uid
    cJSON *uid = cJSON_GetObjectItemCaseSensitive(agent_file_attributes_bodyJSON, "uid");
    if (cJSON_IsNull(uid)) {
        uid = NULL;
    }
    if (uid) { 
    if(!cJSON_IsNumber(uid))
    {
    goto end; //Numeric
    }
    }

    // agent_file_attributes_body->gid
    cJSON *gid = cJSON_GetObjectItemCaseSensitive(agent_file_attributes_bodyJSON, "gid");
    if (cJSON_IsNull(gid)) {
        gid = NULL;
    }
    if (gid) { 
    if(!cJSON_IsNumber(gid))
    {
    goto end; //Numeric
    }
    }


    agent_file_attributes_body_local_var = agent_file_attributes_body_create_internal (
        path && !cJSON_IsNull(path) ? strdup(path->valuestring) : NULL,
        mode ? mode->valuedouble : 0,
        uid ? uid->valuedouble : 0,
        gid ? gid->valuedouble : 0
        );

    return agent_file_attributes_body_local_var;
end:
    return NULL;

}
