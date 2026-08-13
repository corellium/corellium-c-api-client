#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_trial_request_response_trial_request.h"



static create_trial_request_response_trial_request_t *create_trial_request_response_trial_request_create_internal(
    char *identifier,
    char *email,
    char *name
    ) {
    create_trial_request_response_trial_request_t *create_trial_request_response_trial_request_local_var = malloc(sizeof(create_trial_request_response_trial_request_t));
    if (!create_trial_request_response_trial_request_local_var) {
        return NULL;
    }
    create_trial_request_response_trial_request_local_var->identifier = identifier;
    create_trial_request_response_trial_request_local_var->email = email;
    create_trial_request_response_trial_request_local_var->name = name;

    create_trial_request_response_trial_request_local_var->_library_owned = 1;
    return create_trial_request_response_trial_request_local_var;
}

__attribute__((deprecated)) create_trial_request_response_trial_request_t *create_trial_request_response_trial_request_create(
    char *identifier,
    char *email,
    char *name
    ) {
    return create_trial_request_response_trial_request_create_internal (
        identifier,
        email,
        name
        );
}

void create_trial_request_response_trial_request_free(create_trial_request_response_trial_request_t *create_trial_request_response_trial_request) {
    if(NULL == create_trial_request_response_trial_request){
        return ;
    }
    if(create_trial_request_response_trial_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "create_trial_request_response_trial_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (create_trial_request_response_trial_request->identifier) {
        free(create_trial_request_response_trial_request->identifier);
        create_trial_request_response_trial_request->identifier = NULL;
    }
    if (create_trial_request_response_trial_request->email) {
        free(create_trial_request_response_trial_request->email);
        create_trial_request_response_trial_request->email = NULL;
    }
    if (create_trial_request_response_trial_request->name) {
        free(create_trial_request_response_trial_request->name);
        create_trial_request_response_trial_request->name = NULL;
    }
    free(create_trial_request_response_trial_request);
}

cJSON *create_trial_request_response_trial_request_convertToJSON(create_trial_request_response_trial_request_t *create_trial_request_response_trial_request) {
    cJSON *item = cJSON_CreateObject();

    // create_trial_request_response_trial_request->identifier
    if (!create_trial_request_response_trial_request->identifier) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "identifier", create_trial_request_response_trial_request->identifier) == NULL) {
    goto fail; //String
    }


    // create_trial_request_response_trial_request->email
    if (!create_trial_request_response_trial_request->email) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "email", create_trial_request_response_trial_request->email) == NULL) {
    goto fail; //String
    }


    // create_trial_request_response_trial_request->name
    if (!create_trial_request_response_trial_request->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", create_trial_request_response_trial_request->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

create_trial_request_response_trial_request_t *create_trial_request_response_trial_request_parseFromJSON(cJSON *create_trial_request_response_trial_requestJSON){

    create_trial_request_response_trial_request_t *create_trial_request_response_trial_request_local_var = NULL;

    // create_trial_request_response_trial_request->identifier
    cJSON *identifier = cJSON_GetObjectItemCaseSensitive(create_trial_request_response_trial_requestJSON, "identifier");
    if (cJSON_IsNull(identifier)) {
        identifier = NULL;
    }
    if (!identifier) {
        goto end;
    }

    
    if(!cJSON_IsString(identifier))
    {
    goto end; //String
    }

    // create_trial_request_response_trial_request->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(create_trial_request_response_trial_requestJSON, "email");
    if (cJSON_IsNull(email)) {
        email = NULL;
    }
    if (!email) {
        goto end;
    }

    
    if(!cJSON_IsString(email))
    {
    goto end; //String
    }

    // create_trial_request_response_trial_request->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(create_trial_request_response_trial_requestJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }


    create_trial_request_response_trial_request_local_var = create_trial_request_response_trial_request_create_internal (
        strdup(identifier->valuestring),
        strdup(email->valuestring),
        strdup(name->valuestring)
        );

    return create_trial_request_response_trial_request_local_var;
end:
    return NULL;

}
