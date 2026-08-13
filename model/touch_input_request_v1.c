#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "touch_input_request_v1.h"



static touch_input_request_v1_t *touch_input_request_v1_create_internal(
    object_t *position,
    list_t *buttons,
    int normalized,
    double wait
    ) {
    touch_input_request_v1_t *touch_input_request_v1_local_var = malloc(sizeof(touch_input_request_v1_t));
    if (!touch_input_request_v1_local_var) {
        return NULL;
    }
    touch_input_request_v1_local_var->position = position;
    touch_input_request_v1_local_var->buttons = buttons;
    touch_input_request_v1_local_var->normalized = normalized;
    touch_input_request_v1_local_var->wait = wait;

    touch_input_request_v1_local_var->_library_owned = 1;
    return touch_input_request_v1_local_var;
}

__attribute__((deprecated)) touch_input_request_v1_t *touch_input_request_v1_create(
    object_t *position,
    list_t *buttons,
    int normalized,
    double wait
    ) {
    return touch_input_request_v1_create_internal (
        position,
        buttons,
        normalized,
        wait
        );
}

void touch_input_request_v1_free(touch_input_request_v1_t *touch_input_request_v1) {
    if(NULL == touch_input_request_v1){
        return ;
    }
    if(touch_input_request_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "touch_input_request_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (touch_input_request_v1->position) {
        object_free(touch_input_request_v1->position);
        touch_input_request_v1->position = NULL;
    }
    if (touch_input_request_v1->buttons) {
        list_ForEach(listEntry, touch_input_request_v1->buttons) {
            object_free(listEntry->data);
        }
        list_freeList(touch_input_request_v1->buttons);
        touch_input_request_v1->buttons = NULL;
    }
    free(touch_input_request_v1);
}

cJSON *touch_input_request_v1_convertToJSON(touch_input_request_v1_t *touch_input_request_v1) {
    cJSON *item = cJSON_CreateObject();

    // touch_input_request_v1->position
    if (!touch_input_request_v1->position) {
        goto fail;
    }
    cJSON *position_object = object_convertToJSON(touch_input_request_v1->position);
    if(position_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "position", position_object);
    if(item->child == NULL) {
    goto fail;
    }


    // touch_input_request_v1->buttons
    if(touch_input_request_v1->buttons) {
    cJSON *buttons = cJSON_AddArrayToObject(item, "buttons");
    if(buttons == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *buttonsListEntry;
    if (touch_input_request_v1->buttons) {
    list_ForEach(buttonsListEntry, touch_input_request_v1->buttons) {
    cJSON *itemLocal = object_convertToJSON(buttonsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(buttons, itemLocal);
    }
    }
    }


    // touch_input_request_v1->normalized
    if(touch_input_request_v1->normalized) {
    if(cJSON_AddBoolToObject(item, "normalized", touch_input_request_v1->normalized) == NULL) {
    goto fail; //Bool
    }
    }


    // touch_input_request_v1->wait
    if(touch_input_request_v1->wait) {
    if(cJSON_AddNumberToObject(item, "wait", touch_input_request_v1->wait) == NULL) {
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

touch_input_request_v1_t *touch_input_request_v1_parseFromJSON(cJSON *touch_input_request_v1JSON){

    touch_input_request_v1_t *touch_input_request_v1_local_var = NULL;

    // define the local list for touch_input_request_v1->buttons
    list_t *buttonsList = NULL;

    // touch_input_request_v1->position
    cJSON *position = cJSON_GetObjectItemCaseSensitive(touch_input_request_v1JSON, "position");
    if (cJSON_IsNull(position)) {
        position = NULL;
    }
    if (!position) {
        goto end;
    }

    object_t *position_local_object = NULL;
    
    position_local_object = object_parseFromJSON(position); //object

    // touch_input_request_v1->buttons
    cJSON *buttons = cJSON_GetObjectItemCaseSensitive(touch_input_request_v1JSON, "buttons");
    if (cJSON_IsNull(buttons)) {
        buttons = NULL;
    }
    if (buttons) { 
    cJSON *buttons_local_nonprimitive = NULL;
    if(!cJSON_IsArray(buttons)){
        goto end; //nonprimitive container
    }

    buttonsList = list_createList();

    cJSON_ArrayForEach(buttons_local_nonprimitive,buttons )
    {
        if(!cJSON_IsObject(buttons_local_nonprimitive)){
            goto end;
        }
        object_t *buttonsItem = object_parseFromJSON(buttons_local_nonprimitive);

        list_addElement(buttonsList, buttonsItem);
    }
    }

    // touch_input_request_v1->normalized
    cJSON *normalized = cJSON_GetObjectItemCaseSensitive(touch_input_request_v1JSON, "normalized");
    if (cJSON_IsNull(normalized)) {
        normalized = NULL;
    }
    if (normalized) { 
    if(!cJSON_IsBool(normalized))
    {
    goto end; //Bool
    }
    }

    // touch_input_request_v1->wait
    cJSON *wait = cJSON_GetObjectItemCaseSensitive(touch_input_request_v1JSON, "wait");
    if (cJSON_IsNull(wait)) {
        wait = NULL;
    }
    if (wait) { 
    if(!cJSON_IsNumber(wait))
    {
    goto end; //Numeric
    }
    }


    touch_input_request_v1_local_var = touch_input_request_v1_create_internal (
        position_local_object,
        buttons ? buttonsList : NULL,
        normalized ? normalized->valueint : 0,
        wait ? wait->valuedouble : 0
        );

    return touch_input_request_v1_local_var;
end:
    if (buttonsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, buttonsList) {
            object_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(buttonsList);
        buttonsList = NULL;
    }
    return NULL;

}
