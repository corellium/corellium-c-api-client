#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "instance_upgrade_response.h"


char* instance_upgrade_response_state_ToString(corellium_api_instance_upgrade_response_STATE_e state) {
    char* stateArray[] =  { "NULL", "updating" };
    return stateArray[state];
}

corellium_api_instance_upgrade_response_STATE_e instance_upgrade_response_state_FromString(char* state){
    int stringToReturn = 0;
    char *stateArray[] =  { "NULL", "updating" };
    size_t sizeofArray = sizeof(stateArray) / sizeof(stateArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(state, stateArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static instance_upgrade_response_t *instance_upgrade_response_create_internal(
    char *id,
    corellium_api_instance_upgrade_response_STATE_e state
    ) {
    instance_upgrade_response_t *instance_upgrade_response_local_var = malloc(sizeof(instance_upgrade_response_t));
    if (!instance_upgrade_response_local_var) {
        return NULL;
    }
    instance_upgrade_response_local_var->id = id;
    instance_upgrade_response_local_var->state = state;

    instance_upgrade_response_local_var->_library_owned = 1;
    return instance_upgrade_response_local_var;
}

__attribute__((deprecated)) instance_upgrade_response_t *instance_upgrade_response_create(
    char *id,
    corellium_api_instance_upgrade_response_STATE_e state
    ) {
    return instance_upgrade_response_create_internal (
        id,
        state
        );
}

void instance_upgrade_response_free(instance_upgrade_response_t *instance_upgrade_response) {
    if(NULL == instance_upgrade_response){
        return ;
    }
    if(instance_upgrade_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "instance_upgrade_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (instance_upgrade_response->id) {
        free(instance_upgrade_response->id);
        instance_upgrade_response->id = NULL;
    }
    free(instance_upgrade_response);
}

cJSON *instance_upgrade_response_convertToJSON(instance_upgrade_response_t *instance_upgrade_response) {
    cJSON *item = cJSON_CreateObject();

    // instance_upgrade_response->id
    if (!instance_upgrade_response->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", instance_upgrade_response->id) == NULL) {
    goto fail; //String
    }


    // instance_upgrade_response->state
    if (corellium_api_instance_upgrade_response_STATE_NULL == instance_upgrade_response->state) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "state", instance_upgrade_response_state_ToString(instance_upgrade_response->state)) == NULL)
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

instance_upgrade_response_t *instance_upgrade_response_parseFromJSON(cJSON *instance_upgrade_responseJSON){

    instance_upgrade_response_t *instance_upgrade_response_local_var = NULL;

    // instance_upgrade_response->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(instance_upgrade_responseJSON, "id");
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

    // instance_upgrade_response->state
    cJSON *state = cJSON_GetObjectItemCaseSensitive(instance_upgrade_responseJSON, "state");
    if (cJSON_IsNull(state)) {
        state = NULL;
    }
    if (!state) {
        goto end;
    }

    corellium_api_instance_upgrade_response_STATE_e stateVariable;
    
    if(!cJSON_IsString(state))
    {
    goto end; //Enum
    }
    stateVariable = instance_upgrade_response_state_FromString(state->valuestring);


    instance_upgrade_response_local_var = instance_upgrade_response_create_internal (
        strdup(id->valuestring),
        stateVariable
        );

    return instance_upgrade_response_local_var;
end:
    return NULL;

}
