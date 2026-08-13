#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "instance_return.h"


char* instance_return_state_ToString(corellium_api_instance_return_STATE_e state) {
    char* stateArray[] =  { "NULL", "creating" };
    return stateArray[state];
}

corellium_api_instance_return_STATE_e instance_return_state_FromString(char* state){
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

static instance_return_t *instance_return_create_internal(
    char *id,
    corellium_api_instance_return_STATE_e state
    ) {
    instance_return_t *instance_return_local_var = malloc(sizeof(instance_return_t));
    if (!instance_return_local_var) {
        return NULL;
    }
    instance_return_local_var->id = id;
    instance_return_local_var->state = state;

    instance_return_local_var->_library_owned = 1;
    return instance_return_local_var;
}

__attribute__((deprecated)) instance_return_t *instance_return_create(
    char *id,
    corellium_api_instance_return_STATE_e state
    ) {
    return instance_return_create_internal (
        id,
        state
        );
}

void instance_return_free(instance_return_t *instance_return) {
    if(NULL == instance_return){
        return ;
    }
    if(instance_return->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "instance_return_free");
        return ;
    }
    listEntry_t *listEntry;
    if (instance_return->id) {
        free(instance_return->id);
        instance_return->id = NULL;
    }
    free(instance_return);
}

cJSON *instance_return_convertToJSON(instance_return_t *instance_return) {
    cJSON *item = cJSON_CreateObject();

    // instance_return->id
    if (!instance_return->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", instance_return->id) == NULL) {
    goto fail; //String
    }


    // instance_return->state
    if (corellium_api_instance_return_STATE_NULL == instance_return->state) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "state", instance_return_state_ToString(instance_return->state)) == NULL)
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

instance_return_t *instance_return_parseFromJSON(cJSON *instance_returnJSON){

    instance_return_t *instance_return_local_var = NULL;

    // instance_return->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(instance_returnJSON, "id");
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

    // instance_return->state
    cJSON *state = cJSON_GetObjectItemCaseSensitive(instance_returnJSON, "state");
    if (cJSON_IsNull(state)) {
        state = NULL;
    }
    if (!state) {
        goto end;
    }

    corellium_api_instance_return_STATE_e stateVariable;
    
    if(!cJSON_IsString(state))
    {
    goto end; //Enum
    }
    stateVariable = instance_return_state_FromString(state->valuestring);


    instance_return_local_var = instance_return_create_internal (
        strdup(id->valuestring),
        stateVariable
        );

    return instance_return_local_var;
end:
    return NULL;

}
