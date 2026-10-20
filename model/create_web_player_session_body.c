#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_web_player_session_body.h"



static create_web_player_session_body_t *create_web_player_session_body_create_internal(
    char *project_id,
    char *instance_id,
    double expires_in,
    web_player_features_t *features,
    char *client_id
    ) {
    create_web_player_session_body_t *create_web_player_session_body_local_var = malloc(sizeof(create_web_player_session_body_t));
    if (!create_web_player_session_body_local_var) {
        return NULL;
    }
    create_web_player_session_body_local_var->project_id = project_id;
    create_web_player_session_body_local_var->instance_id = instance_id;
    create_web_player_session_body_local_var->expires_in = expires_in;
    create_web_player_session_body_local_var->features = features;
    create_web_player_session_body_local_var->client_id = client_id;

    create_web_player_session_body_local_var->_library_owned = 1;
    return create_web_player_session_body_local_var;
}

__attribute__((deprecated)) create_web_player_session_body_t *create_web_player_session_body_create(
    char *project_id,
    char *instance_id,
    double expires_in,
    web_player_features_t *features,
    char *client_id
    ) {
    return create_web_player_session_body_create_internal (
        project_id,
        instance_id,
        expires_in,
        features,
        client_id
        );
}

void create_web_player_session_body_free(create_web_player_session_body_t *create_web_player_session_body) {
    if(NULL == create_web_player_session_body){
        return ;
    }
    if(create_web_player_session_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "create_web_player_session_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (create_web_player_session_body->project_id) {
        free(create_web_player_session_body->project_id);
        create_web_player_session_body->project_id = NULL;
    }
    if (create_web_player_session_body->instance_id) {
        free(create_web_player_session_body->instance_id);
        create_web_player_session_body->instance_id = NULL;
    }
    if (create_web_player_session_body->features) {
        web_player_features_free(create_web_player_session_body->features);
        create_web_player_session_body->features = NULL;
    }
    if (create_web_player_session_body->client_id) {
        free(create_web_player_session_body->client_id);
        create_web_player_session_body->client_id = NULL;
    }
    free(create_web_player_session_body);
}

cJSON *create_web_player_session_body_convertToJSON(create_web_player_session_body_t *create_web_player_session_body) {
    cJSON *item = cJSON_CreateObject();

    // create_web_player_session_body->project_id
    if (!create_web_player_session_body->project_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "projectId", create_web_player_session_body->project_id) == NULL) {
    goto fail; //String
    }


    // create_web_player_session_body->instance_id
    if (!create_web_player_session_body->instance_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "instanceId", create_web_player_session_body->instance_id) == NULL) {
    goto fail; //String
    }


    // create_web_player_session_body->expires_in
    if (!create_web_player_session_body->expires_in) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "expiresIn", create_web_player_session_body->expires_in) == NULL) {
    goto fail; //Numeric
    }


    // create_web_player_session_body->features
    if (!create_web_player_session_body->features) {
        goto fail;
    }
    cJSON *features_local_JSON = web_player_features_convertToJSON(create_web_player_session_body->features);
    if(features_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "features", features_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // create_web_player_session_body->client_id
    if(create_web_player_session_body->client_id) {
    if(cJSON_AddStringToObject(item, "clientId", create_web_player_session_body->client_id) == NULL) {
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

create_web_player_session_body_t *create_web_player_session_body_parseFromJSON(cJSON *create_web_player_session_bodyJSON){

    create_web_player_session_body_t *create_web_player_session_body_local_var = NULL;

    // define the local variable for create_web_player_session_body->features
    web_player_features_t *features_local_nonprim = NULL;

    // create_web_player_session_body->project_id
    cJSON *project_id = cJSON_GetObjectItemCaseSensitive(create_web_player_session_bodyJSON, "projectId");
    if (cJSON_IsNull(project_id)) {
        project_id = NULL;
    }
    if (!project_id) {
        goto end;
    }

    
    if(!cJSON_IsString(project_id))
    {
    goto end; //String
    }

    // create_web_player_session_body->instance_id
    cJSON *instance_id = cJSON_GetObjectItemCaseSensitive(create_web_player_session_bodyJSON, "instanceId");
    if (cJSON_IsNull(instance_id)) {
        instance_id = NULL;
    }
    if (!instance_id) {
        goto end;
    }

    
    if(!cJSON_IsString(instance_id))
    {
    goto end; //String
    }

    // create_web_player_session_body->expires_in
    cJSON *expires_in = cJSON_GetObjectItemCaseSensitive(create_web_player_session_bodyJSON, "expiresIn");
    if (cJSON_IsNull(expires_in)) {
        expires_in = NULL;
    }
    if (!expires_in) {
        goto end;
    }

    
    if(!cJSON_IsNumber(expires_in))
    {
    goto end; //Numeric
    }

    // create_web_player_session_body->features
    cJSON *features = cJSON_GetObjectItemCaseSensitive(create_web_player_session_bodyJSON, "features");
    if (cJSON_IsNull(features)) {
        features = NULL;
    }
    if (!features) {
        goto end;
    }

    
    features_local_nonprim = web_player_features_parseFromJSON(features); //nonprimitive

    // create_web_player_session_body->client_id
    cJSON *client_id = cJSON_GetObjectItemCaseSensitive(create_web_player_session_bodyJSON, "clientId");
    if (cJSON_IsNull(client_id)) {
        client_id = NULL;
    }
    if (client_id) { 
    if(!cJSON_IsString(client_id) && !cJSON_IsNull(client_id))
    {
    goto end; //String
    }
    }


    create_web_player_session_body_local_var = create_web_player_session_body_create_internal (
        strdup(project_id->valuestring),
        strdup(instance_id->valuestring),
        expires_in->valuedouble,
        features_local_nonprim,
        client_id && !cJSON_IsNull(client_id) ? strdup(client_id->valuestring) : NULL
        );

    return create_web_player_session_body_local_var;
end:
    if (features_local_nonprim) {
        web_player_features_free(features_local_nonprim);
        features_local_nonprim = NULL;
    }
    return NULL;

}
