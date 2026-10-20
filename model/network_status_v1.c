#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "network_status_v1.h"


char* network_status_v1_state_ToString(corellium_api_network_status_v1_STATE_e state) {
    char* stateArray[] =  { "NULL", "disconnected", "disconnecting", "connecting", "connected", "error" };
    return stateArray[state];
}

corellium_api_network_status_v1_STATE_e network_status_v1_state_FromString(char* state){
    int stringToReturn = 0;
    char *stateArray[] =  { "NULL", "disconnected", "disconnecting", "connecting", "connected", "error" };
    size_t sizeofArray = sizeof(stateArray) / sizeof(stateArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(state, stateArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static network_status_v1_t *network_status_v1_create_internal(
    char *type,
    char *name,
    corellium_api_network_status_v1_STATE_e state
    ) {
    network_status_v1_t *network_status_v1_local_var = malloc(sizeof(network_status_v1_t));
    if (!network_status_v1_local_var) {
        return NULL;
    }
    network_status_v1_local_var->type = type;
    network_status_v1_local_var->name = name;
    network_status_v1_local_var->state = state;

    network_status_v1_local_var->_library_owned = 1;
    return network_status_v1_local_var;
}

__attribute__((deprecated)) network_status_v1_t *network_status_v1_create(
    char *type,
    char *name,
    corellium_api_network_status_v1_STATE_e state
    ) {
    return network_status_v1_create_internal (
        type,
        name,
        state
        );
}

void network_status_v1_free(network_status_v1_t *network_status_v1) {
    if(NULL == network_status_v1){
        return ;
    }
    if(network_status_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "network_status_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (network_status_v1->type) {
        free(network_status_v1->type);
        network_status_v1->type = NULL;
    }
    if (network_status_v1->name) {
        free(network_status_v1->name);
        network_status_v1->name = NULL;
    }
    free(network_status_v1);
}

cJSON *network_status_v1_convertToJSON(network_status_v1_t *network_status_v1) {
    cJSON *item = cJSON_CreateObject();

    // network_status_v1->type
    if(network_status_v1->type) {
    if(cJSON_AddStringToObject(item, "type", network_status_v1->type) == NULL) {
    goto fail; //String
    }
    }


    // network_status_v1->name
    if(network_status_v1->name) {
    if(cJSON_AddStringToObject(item, "name", network_status_v1->name) == NULL) {
    goto fail; //String
    }
    }


    // network_status_v1->state
    if(network_status_v1->state != corellium_api_network_status_v1_STATE_NULL) {
    if(cJSON_AddStringToObject(item, "state", network_status_v1_state_ToString(network_status_v1->state)) == NULL)
    {
    goto fail; //Enum
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

network_status_v1_t *network_status_v1_parseFromJSON(cJSON *network_status_v1JSON){

    network_status_v1_t *network_status_v1_local_var = NULL;

    // network_status_v1->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(network_status_v1JSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (type) { 
    if(!cJSON_IsString(type) && !cJSON_IsNull(type))
    {
    goto end; //String
    }
    }

    // network_status_v1->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(network_status_v1JSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // network_status_v1->state
    cJSON *state = cJSON_GetObjectItemCaseSensitive(network_status_v1JSON, "state");
    if (cJSON_IsNull(state)) {
        state = NULL;
    }
    corellium_api_network_status_v1_STATE_e stateVariable;
    if (state) { 
    if(!cJSON_IsString(state))
    {
    goto end; //Enum
    }
    stateVariable = network_status_v1_state_FromString(state->valuestring);
    }


    network_status_v1_local_var = network_status_v1_create_internal (
        type && !cJSON_IsNull(type) ? strdup(type->valuestring) : NULL,
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        state ? stateVariable : corellium_api_network_status_v1_STATE_NULL
        );

    return network_status_v1_local_var;
end:
    return NULL;

}
