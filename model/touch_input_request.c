#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "touch_input_request.h"



static touch_input_request_t *touch_input_request_create_internal(
    list_t *position,
    list_t *buttons,
    int normalized,
    double wait
    ) {
    touch_input_request_t *touch_input_request_local_var = malloc(sizeof(touch_input_request_t));
    if (!touch_input_request_local_var) {
        return NULL;
    }
    touch_input_request_local_var->position = position;
    touch_input_request_local_var->buttons = buttons;
    touch_input_request_local_var->normalized = normalized;
    touch_input_request_local_var->wait = wait;

    touch_input_request_local_var->_library_owned = 1;
    return touch_input_request_local_var;
}

__attribute__((deprecated)) touch_input_request_t *touch_input_request_create(
    list_t *position,
    list_t *buttons,
    int normalized,
    double wait
    ) {
    return touch_input_request_create_internal (
        position,
        buttons,
        normalized,
        wait
        );
}

void touch_input_request_free(touch_input_request_t *touch_input_request) {
    if(NULL == touch_input_request){
        return ;
    }
    if(touch_input_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "touch_input_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (touch_input_request->position) {
        list_ForEach(listEntry, touch_input_request->position) {
            free(listEntry->data);
        }
        list_freeList(touch_input_request->position);
        touch_input_request->position = NULL;
    }
    if (touch_input_request->buttons) {
        list_ForEach(listEntry, touch_input_request->buttons) {
            free(listEntry->data);
        }
        list_freeList(touch_input_request->buttons);
        touch_input_request->buttons = NULL;
    }
    free(touch_input_request);
}

cJSON *touch_input_request_convertToJSON(touch_input_request_t *touch_input_request) {
    cJSON *item = cJSON_CreateObject();

    // touch_input_request->position
    if (!touch_input_request->position) {
        goto fail;
    }
    cJSON *position = cJSON_AddArrayToObject(item, "position");
    if(position == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *positionListEntry;
    list_ForEach(positionListEntry, touch_input_request->position) {
    }


    // touch_input_request->buttons
    if(touch_input_request->buttons) {
    cJSON *buttons = cJSON_AddArrayToObject(item, "buttons");
    if(buttons == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *buttonsListEntry;
    list_ForEach(buttonsListEntry, touch_input_request->buttons) {
    if(cJSON_AddStringToObject(buttons, "", buttonsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // touch_input_request->normalized
    if(touch_input_request->normalized) {
    if(cJSON_AddBoolToObject(item, "normalized", touch_input_request->normalized) == NULL) {
    goto fail; //Bool
    }
    }


    // touch_input_request->wait
    if(touch_input_request->wait) {
    if(cJSON_AddNumberToObject(item, "wait", touch_input_request->wait) == NULL) {
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

touch_input_request_t *touch_input_request_parseFromJSON(cJSON *touch_input_requestJSON){

    touch_input_request_t *touch_input_request_local_var = NULL;

    // define the local list for touch_input_request->position
    list_t *positionList = NULL;

    // define the local list for touch_input_request->buttons
    list_t *buttonsList = NULL;

    // touch_input_request->position
    cJSON *position = cJSON_GetObjectItemCaseSensitive(touch_input_requestJSON, "position");
    if (cJSON_IsNull(position)) {
        position = NULL;
    }
    if (!position) {
        goto end;
    }

    
    cJSON *position_local = NULL;
    if(!cJSON_IsArray(position)) {
        goto end;//primitive container
    }
    positionList = list_createList();

    cJSON_ArrayForEach(position_local, position)
    {
    }

    // touch_input_request->buttons
    cJSON *buttons = cJSON_GetObjectItemCaseSensitive(touch_input_requestJSON, "buttons");
    if (cJSON_IsNull(buttons)) {
        buttons = NULL;
    }
    if (buttons) { 
    cJSON *buttons_local = NULL;
    if(!cJSON_IsArray(buttons)) {
        goto end;//primitive container
    }
    buttonsList = list_createList();

    cJSON_ArrayForEach(buttons_local, buttons)
    {
        if(!cJSON_IsString(buttons_local))
        {
            goto end;
        }
        list_addElement(buttonsList , strdup(buttons_local->valuestring));
    }
    }

    // touch_input_request->normalized
    cJSON *normalized = cJSON_GetObjectItemCaseSensitive(touch_input_requestJSON, "normalized");
    if (cJSON_IsNull(normalized)) {
        normalized = NULL;
    }
    if (normalized) { 
    if(!cJSON_IsBool(normalized))
    {
    goto end; //Bool
    }
    }

    // touch_input_request->wait
    cJSON *wait = cJSON_GetObjectItemCaseSensitive(touch_input_requestJSON, "wait");
    if (cJSON_IsNull(wait)) {
        wait = NULL;
    }
    if (wait) { 
    if(!cJSON_IsNumber(wait))
    {
    goto end; //Numeric
    }
    }


    touch_input_request_local_var = touch_input_request_create_internal (
        positionList,
        buttons ? buttonsList : NULL,
        normalized ? normalized->valueint : 0,
        wait ? wait->valuedouble : 0
        );

    return touch_input_request_local_var;
end:
    if (positionList) {
        list_freeList(positionList);
        positionList = NULL;
    }
    if (buttonsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, buttonsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(buttonsList);
        buttonsList = NULL;
    }
    return NULL;

}
