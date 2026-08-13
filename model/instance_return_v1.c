#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "instance_return_v1.h"



static instance_return_v1_t *instance_return_v1_create_internal(
    char *id,
    corellium_api_instance_state_v1__e state
    ) {
    instance_return_v1_t *instance_return_v1_local_var = malloc(sizeof(instance_return_v1_t));
    if (!instance_return_v1_local_var) {
        return NULL;
    }
    instance_return_v1_local_var->id = id;
    instance_return_v1_local_var->state = state;

    instance_return_v1_local_var->_library_owned = 1;
    return instance_return_v1_local_var;
}

__attribute__((deprecated)) instance_return_v1_t *instance_return_v1_create(
    char *id,
    corellium_api_instance_state_v1__e state
    ) {
    return instance_return_v1_create_internal (
        id,
        state
        );
}

void instance_return_v1_free(instance_return_v1_t *instance_return_v1) {
    if(NULL == instance_return_v1){
        return ;
    }
    if(instance_return_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "instance_return_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (instance_return_v1->id) {
        free(instance_return_v1->id);
        instance_return_v1->id = NULL;
    }
    free(instance_return_v1);
}

cJSON *instance_return_v1_convertToJSON(instance_return_v1_t *instance_return_v1) {
    cJSON *item = cJSON_CreateObject();

    // instance_return_v1->id
    if (!instance_return_v1->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", instance_return_v1->id) == NULL) {
    goto fail; //String
    }


    // instance_return_v1->state
    if (corellium_api_instance_state_v1__NULL == instance_return_v1->state) {
        goto fail;
    }
    cJSON *state_local_JSON = instance_state_v1_convertToJSON(instance_return_v1->state);
    if(state_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "state", state_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

instance_return_v1_t *instance_return_v1_parseFromJSON(cJSON *instance_return_v1JSON){

    instance_return_v1_t *instance_return_v1_local_var = NULL;

    // define the local variable for instance_return_v1->state
    corellium_api_instance_state_v1__e state_local_nonprim = 0;

    // instance_return_v1->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(instance_return_v1JSON, "id");
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

    // instance_return_v1->state
    cJSON *state = cJSON_GetObjectItemCaseSensitive(instance_return_v1JSON, "state");
    if (cJSON_IsNull(state)) {
        state = NULL;
    }
    if (!state) {
        goto end;
    }

    
    state_local_nonprim = instance_state_v1_parseFromJSON(state); //custom


    instance_return_v1_local_var = instance_return_v1_create_internal (
        strdup(id->valuestring),
        state_local_nonprim
        );

    return instance_return_v1_local_var;
end:
    if (state_local_nonprim) {
        state_local_nonprim = 0;
    }
    return NULL;

}
