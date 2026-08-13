#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "network_status.h"


char* network_status_state_ToString(corellium_api_network_status_STATE_e state) {
    char* stateArray[] =  { "NULL", "disconnected", "disconnecting", "connecting", "connected", "error" };
    return stateArray[state];
}

corellium_api_network_status_STATE_e network_status_state_FromString(char* state){
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

static network_status_t *network_status_create_internal(
    char *type,
    char *name,
    corellium_api_network_status_STATE_e state,
    object_t *details
    ) {
    network_status_t *network_status_local_var = malloc(sizeof(network_status_t));
    if (!network_status_local_var) {
        return NULL;
    }
    network_status_local_var->type = type;
    network_status_local_var->name = name;
    network_status_local_var->state = state;
    network_status_local_var->details = details;

    network_status_local_var->_library_owned = 1;
    return network_status_local_var;
}

__attribute__((deprecated)) network_status_t *network_status_create(
    char *type,
    char *name,
    corellium_api_network_status_STATE_e state,
    object_t *details
    ) {
    return network_status_create_internal (
        type,
        name,
        state,
        details
        );
}

void network_status_free(network_status_t *network_status) {
    if(NULL == network_status){
        return ;
    }
    if(network_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "network_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (network_status->type) {
        free(network_status->type);
        network_status->type = NULL;
    }
    if (network_status->name) {
        free(network_status->name);
        network_status->name = NULL;
    }
    if (network_status->details) {
        object_free(network_status->details);
        network_status->details = NULL;
    }
    free(network_status);
}

cJSON *network_status_convertToJSON(network_status_t *network_status) {
    cJSON *item = cJSON_CreateObject();

    // network_status->type
    if(network_status->type) {
    if(cJSON_AddStringToObject(item, "type", network_status->type) == NULL) {
    goto fail; //String
    }
    }


    // network_status->name
    if(network_status->name) {
    if(cJSON_AddStringToObject(item, "name", network_status->name) == NULL) {
    goto fail; //String
    }
    }


    // network_status->state
    if (corellium_api_network_status_STATE_NULL == network_status->state) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "state", network_status_state_ToString(network_status->state)) == NULL)
    {
    goto fail; //Enum
    }


    // network_status->details
    if(network_status->details) {
    cJSON *details_object = object_convertToJSON(network_status->details);
    if(details_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "details", details_object);
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

network_status_t *network_status_parseFromJSON(cJSON *network_statusJSON){

    network_status_t *network_status_local_var = NULL;

    // network_status->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(network_statusJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (type) { 
    if(!cJSON_IsString(type) && !cJSON_IsNull(type))
    {
    goto end; //String
    }
    }

    // network_status->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(network_statusJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // network_status->state
    cJSON *state = cJSON_GetObjectItemCaseSensitive(network_statusJSON, "state");
    if (cJSON_IsNull(state)) {
        state = NULL;
    }
    if (!state) {
        goto end;
    }

    corellium_api_network_status_STATE_e stateVariable;
    
    if(!cJSON_IsString(state))
    {
    goto end; //Enum
    }
    stateVariable = network_status_state_FromString(state->valuestring);

    // network_status->details
    cJSON *details = cJSON_GetObjectItemCaseSensitive(network_statusJSON, "details");
    if (cJSON_IsNull(details)) {
        details = NULL;
    }
    object_t *details_local_object = NULL;
    if (details) { 
    details_local_object = object_parseFromJSON(details); //object
    }


    network_status_local_var = network_status_create_internal (
        type && !cJSON_IsNull(type) ? strdup(type->valuestring) : NULL,
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        stateVariable,
        details ? details_local_object : NULL
        );

    return network_status_local_var;
end:
    return NULL;

}
