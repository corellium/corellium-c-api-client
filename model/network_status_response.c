#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "network_status_response.h"


char* network_status_response_state_ToString(corellium_api_network_status_response_STATE_e state) {
    char* stateArray[] =  { "NULL", "inactive", "disconnected", "disconnecting", "connecting", "connected", "error" };
    return stateArray[state];
}

corellium_api_network_status_response_STATE_e network_status_response_state_FromString(char* state){
    int stringToReturn = 0;
    char *stateArray[] =  { "NULL", "inactive", "disconnected", "disconnecting", "connecting", "connected", "error" };
    size_t sizeofArray = sizeof(stateArray) / sizeof(stateArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(state, stateArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static network_status_response_t *network_status_response_create_internal(
    char *type,
    char *name,
    corellium_api_network_status_response_STATE_e state,
    object_t *params
    ) {
    network_status_response_t *network_status_response_local_var = malloc(sizeof(network_status_response_t));
    if (!network_status_response_local_var) {
        return NULL;
    }
    network_status_response_local_var->type = type;
    network_status_response_local_var->name = name;
    network_status_response_local_var->state = state;
    network_status_response_local_var->params = params;

    network_status_response_local_var->_library_owned = 1;
    return network_status_response_local_var;
}

__attribute__((deprecated)) network_status_response_t *network_status_response_create(
    char *type,
    char *name,
    corellium_api_network_status_response_STATE_e state,
    object_t *params
    ) {
    return network_status_response_create_internal (
        type,
        name,
        state,
        params
        );
}

void network_status_response_free(network_status_response_t *network_status_response) {
    if(NULL == network_status_response){
        return ;
    }
    if(network_status_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "network_status_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (network_status_response->type) {
        free(network_status_response->type);
        network_status_response->type = NULL;
    }
    if (network_status_response->name) {
        free(network_status_response->name);
        network_status_response->name = NULL;
    }
    if (network_status_response->params) {
        object_free(network_status_response->params);
        network_status_response->params = NULL;
    }
    free(network_status_response);
}

cJSON *network_status_response_convertToJSON(network_status_response_t *network_status_response) {
    cJSON *item = cJSON_CreateObject();

    // network_status_response->type
    if(network_status_response->type) {
    if(cJSON_AddStringToObject(item, "type", network_status_response->type) == NULL) {
    goto fail; //String
    }
    }


    // network_status_response->name
    if(network_status_response->name) {
    if(cJSON_AddStringToObject(item, "name", network_status_response->name) == NULL) {
    goto fail; //String
    }
    }


    // network_status_response->state
    if (corellium_api_network_status_response_STATE_NULL == network_status_response->state) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "state", network_status_response_state_ToString(network_status_response->state)) == NULL)
    {
    goto fail; //Enum
    }


    // network_status_response->params
    if(network_status_response->params) {
    cJSON *params_object = object_convertToJSON(network_status_response->params);
    if(params_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "params", params_object);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

network_status_response_t *network_status_response_parseFromJSON(cJSON *network_status_responseJSON){

    network_status_response_t *network_status_response_local_var = NULL;

    // network_status_response->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(network_status_responseJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (type) { 
    if(!cJSON_IsString(type) && !cJSON_IsNull(type))
    {
    goto end; //String
    }
    }

    // network_status_response->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(network_status_responseJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // network_status_response->state
    cJSON *state = cJSON_GetObjectItemCaseSensitive(network_status_responseJSON, "state");
    if (cJSON_IsNull(state)) {
        state = NULL;
    }
    if (!state) {
        goto end;
    }

    corellium_api_network_status_response_STATE_e stateVariable;
    
    if(!cJSON_IsString(state))
    {
    goto end; //Enum
    }
    stateVariable = network_status_response_state_FromString(state->valuestring);

    // network_status_response->params
    cJSON *params = cJSON_GetObjectItemCaseSensitive(network_status_responseJSON, "params");
    if (cJSON_IsNull(params)) {
        params = NULL;
    }
    object_t *params_local_object = NULL;
    if (params) { 
    params_local_object = object_parseFromJSON(params); //object
    }


    network_status_response_local_var = network_status_response_create_internal (
        type && !cJSON_IsNull(type) ? strdup(type->valuestring) : NULL,
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        stateVariable,
        params ? params_local_object : NULL
        );

    return network_status_response_local_var;
end:
    return NULL;

}
