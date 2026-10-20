#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_instance_response.h"


char* create_instance_response_state_ToString(corellium_api_create_instance_response_STATE_e state) {
    char* stateArray[] =  { "NULL", "creating" };
    return stateArray[state];
}

corellium_api_create_instance_response_STATE_e create_instance_response_state_FromString(char* state){
    int stringToReturn = 0;
    char *stateArray[] =  { "NULL", "creating" };
    size_t sizeofArray = sizeof(stateArray) / sizeof(stateArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(state, stateArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static create_instance_response_t *create_instance_response_create_internal(
    char *id,
    corellium_api_create_instance_response_STATE_e state
    ) {
    create_instance_response_t *create_instance_response_local_var = malloc(sizeof(create_instance_response_t));
    if (!create_instance_response_local_var) {
        return NULL;
    }
    create_instance_response_local_var->id = id;
    create_instance_response_local_var->state = state;

    create_instance_response_local_var->_library_owned = 1;
    return create_instance_response_local_var;
}

__attribute__((deprecated)) create_instance_response_t *create_instance_response_create(
    char *id,
    corellium_api_create_instance_response_STATE_e state
    ) {
    return create_instance_response_create_internal (
        id,
        state
        );
}

void create_instance_response_free(create_instance_response_t *create_instance_response) {
    if(NULL == create_instance_response){
        return ;
    }
    if(create_instance_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "create_instance_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (create_instance_response->id) {
        free(create_instance_response->id);
        create_instance_response->id = NULL;
    }
    free(create_instance_response);
}

cJSON *create_instance_response_convertToJSON(create_instance_response_t *create_instance_response) {
    cJSON *item = cJSON_CreateObject();

    // create_instance_response->id
    if (!create_instance_response->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", create_instance_response->id) == NULL) {
    goto fail; //String
    }


    // create_instance_response->state
    if (corellium_api_create_instance_response_STATE_NULL == create_instance_response->state) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "state", create_instance_response_state_ToString(create_instance_response->state)) == NULL)
    {
    goto fail; //Enum
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

create_instance_response_t *create_instance_response_parseFromJSON(cJSON *create_instance_responseJSON){

    create_instance_response_t *create_instance_response_local_var = NULL;

    // create_instance_response->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(create_instance_responseJSON, "id");
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

    // create_instance_response->state
    cJSON *state = cJSON_GetObjectItemCaseSensitive(create_instance_responseJSON, "state");
    if (cJSON_IsNull(state)) {
        state = NULL;
    }
    if (!state) {
        goto end;
    }

    corellium_api_create_instance_response_STATE_e stateVariable;
    
    if(!cJSON_IsString(state))
    {
    goto end; //Enum
    }
    stateVariable = create_instance_response_state_FromString(state->valuestring);


    create_instance_response_local_var = create_instance_response_create_internal (
        strdup(id->valuestring),
        stateVariable
        );

    return create_instance_response_local_var;
end:
    return NULL;

}
