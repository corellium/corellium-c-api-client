#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "instance_input_request.h"



static instance_input_request_t *instance_input_request_create_internal(
    object_t *position,
    list_t *buttons,
    int normalized,
    double wait,
    object_t *start,
    object_t *end,
    list_t *bezier_points,
    list_t *start_buttons,
    list_t *end_buttons,
    double duration,
    char *required,
    double key_duration
    ) {
    instance_input_request_t *instance_input_request_local_var = malloc(sizeof(instance_input_request_t));
    if (!instance_input_request_local_var) {
        return NULL;
    }
    instance_input_request_local_var->position = position;
    instance_input_request_local_var->buttons = buttons;
    instance_input_request_local_var->normalized = normalized;
    instance_input_request_local_var->wait = wait;
    instance_input_request_local_var->start = start;
    instance_input_request_local_var->end = end;
    instance_input_request_local_var->bezier_points = bezier_points;
    instance_input_request_local_var->start_buttons = start_buttons;
    instance_input_request_local_var->end_buttons = end_buttons;
    instance_input_request_local_var->duration = duration;
    instance_input_request_local_var->required = required;
    instance_input_request_local_var->key_duration = key_duration;

    instance_input_request_local_var->_library_owned = 1;
    return instance_input_request_local_var;
}

__attribute__((deprecated)) instance_input_request_t *instance_input_request_create(
    object_t *position,
    list_t *buttons,
    int normalized,
    double wait,
    object_t *start,
    object_t *end,
    list_t *bezier_points,
    list_t *start_buttons,
    list_t *end_buttons,
    double duration,
    char *required,
    double key_duration
    ) {
    return instance_input_request_create_internal (
        position,
        buttons,
        normalized,
        wait,
        start,
        end,
        bezier_points,
        start_buttons,
        end_buttons,
        duration,
        required,
        key_duration
        );
}

void instance_input_request_free(instance_input_request_t *instance_input_request) {
    if(NULL == instance_input_request){
        return ;
    }
    if(instance_input_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "instance_input_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (instance_input_request->position) {
        object_free(instance_input_request->position);
        instance_input_request->position = NULL;
    }
    if (instance_input_request->buttons) {
        list_ForEach(listEntry, instance_input_request->buttons) {
            object_free(listEntry->data);
        }
        list_freeList(instance_input_request->buttons);
        instance_input_request->buttons = NULL;
    }
    if (instance_input_request->start) {
        object_free(instance_input_request->start);
        instance_input_request->start = NULL;
    }
    if (instance_input_request->end) {
        object_free(instance_input_request->end);
        instance_input_request->end = NULL;
    }
    if (instance_input_request->bezier_points) {
        list_ForEach(listEntry, instance_input_request->bezier_points) {
            object_free(listEntry->data);
        }
        list_freeList(instance_input_request->bezier_points);
        instance_input_request->bezier_points = NULL;
    }
    if (instance_input_request->start_buttons) {
        list_ForEach(listEntry, instance_input_request->start_buttons) {
            object_free(listEntry->data);
        }
        list_freeList(instance_input_request->start_buttons);
        instance_input_request->start_buttons = NULL;
    }
    if (instance_input_request->end_buttons) {
        list_ForEach(listEntry, instance_input_request->end_buttons) {
            object_free(listEntry->data);
        }
        list_freeList(instance_input_request->end_buttons);
        instance_input_request->end_buttons = NULL;
    }
    if (instance_input_request->required) {
        free(instance_input_request->required);
        instance_input_request->required = NULL;
    }
    free(instance_input_request);
}

cJSON *instance_input_request_convertToJSON(instance_input_request_t *instance_input_request) {
    cJSON *item = cJSON_CreateObject();

    // instance_input_request->position
    if (!instance_input_request->position) {
        goto fail;
    }
    cJSON *position_object = object_convertToJSON(instance_input_request->position);
    if(position_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "position", position_object);
    if(item->child == NULL) {
    goto fail;
    }


    // instance_input_request->buttons
    if(instance_input_request->buttons) {
    cJSON *buttons = cJSON_AddArrayToObject(item, "buttons");
    if(buttons == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *buttonsListEntry;
    if (instance_input_request->buttons) {
    list_ForEach(buttonsListEntry, instance_input_request->buttons) {
    cJSON *itemLocal = object_convertToJSON(buttonsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(buttons, itemLocal);
    }
    }
    }


    // instance_input_request->normalized
    if(instance_input_request->normalized) {
    if(cJSON_AddBoolToObject(item, "normalized", instance_input_request->normalized) == NULL) {
    goto fail; //Bool
    }
    }


    // instance_input_request->wait
    if(instance_input_request->wait) {
    if(cJSON_AddNumberToObject(item, "wait", instance_input_request->wait) == NULL) {
    goto fail; //Numeric
    }
    }


    // instance_input_request->start
    if (!instance_input_request->start) {
        goto fail;
    }
    cJSON *start_object = object_convertToJSON(instance_input_request->start);
    if(start_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "start", start_object);
    if(item->child == NULL) {
    goto fail;
    }


    // instance_input_request->end
    if (!instance_input_request->end) {
        goto fail;
    }
    cJSON *end_object = object_convertToJSON(instance_input_request->end);
    if(end_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "end", end_object);
    if(item->child == NULL) {
    goto fail;
    }


    // instance_input_request->bezier_points
    if(instance_input_request->bezier_points) {
    cJSON *bezier_points = cJSON_AddArrayToObject(item, "bezierPoints");
    if(bezier_points == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *bezier_pointsListEntry;
    if (instance_input_request->bezier_points) {
    list_ForEach(bezier_pointsListEntry, instance_input_request->bezier_points) {
    cJSON *itemLocal = object_convertToJSON(bezier_pointsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(bezier_points, itemLocal);
    }
    }
    }


    // instance_input_request->start_buttons
    if (!instance_input_request->start_buttons) {
        goto fail;
    }
    cJSON *start_buttons = cJSON_AddArrayToObject(item, "startButtons");
    if(start_buttons == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *start_buttonsListEntry;
    if (instance_input_request->start_buttons) {
    list_ForEach(start_buttonsListEntry, instance_input_request->start_buttons) {
    cJSON *itemLocal = object_convertToJSON(start_buttonsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(start_buttons, itemLocal);
    }
    }


    // instance_input_request->end_buttons
    if(instance_input_request->end_buttons) {
    cJSON *end_buttons = cJSON_AddArrayToObject(item, "endButtons");
    if(end_buttons == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *end_buttonsListEntry;
    if (instance_input_request->end_buttons) {
    list_ForEach(end_buttonsListEntry, instance_input_request->end_buttons) {
    cJSON *itemLocal = object_convertToJSON(end_buttonsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(end_buttons, itemLocal);
    }
    }
    }


    // instance_input_request->duration
    if (!instance_input_request->duration) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "duration", instance_input_request->duration) == NULL) {
    goto fail; //Numeric
    }


    // instance_input_request->required
    if (!instance_input_request->required) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "required", instance_input_request->required) == NULL) {
    goto fail; //String
    }


    // instance_input_request->key_duration
    if(instance_input_request->key_duration) {
    if(cJSON_AddNumberToObject(item, "keyDuration", instance_input_request->key_duration) == NULL) {
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

instance_input_request_t *instance_input_request_parseFromJSON(cJSON *instance_input_requestJSON){

    instance_input_request_t *instance_input_request_local_var = NULL;

    // define the local list for instance_input_request->buttons
    list_t *buttonsList = NULL;

    // define the local list for instance_input_request->bezier_points
    list_t *bezier_pointsList = NULL;

    // define the local list for instance_input_request->start_buttons
    list_t *start_buttonsList = NULL;

    // define the local list for instance_input_request->end_buttons
    list_t *end_buttonsList = NULL;

    // instance_input_request->position
    cJSON *position = cJSON_GetObjectItemCaseSensitive(instance_input_requestJSON, "position");
    if (cJSON_IsNull(position)) {
        position = NULL;
    }
    if (!position) {
        goto end;
    }

    object_t *position_local_object = NULL;
    
    position_local_object = object_parseFromJSON(position); //object

    // instance_input_request->buttons
    cJSON *buttons = cJSON_GetObjectItemCaseSensitive(instance_input_requestJSON, "buttons");
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

    // instance_input_request->normalized
    cJSON *normalized = cJSON_GetObjectItemCaseSensitive(instance_input_requestJSON, "normalized");
    if (cJSON_IsNull(normalized)) {
        normalized = NULL;
    }
    if (normalized) { 
    if(!cJSON_IsBool(normalized))
    {
    goto end; //Bool
    }
    }

    // instance_input_request->wait
    cJSON *wait = cJSON_GetObjectItemCaseSensitive(instance_input_requestJSON, "wait");
    if (cJSON_IsNull(wait)) {
        wait = NULL;
    }
    if (wait) { 
    if(!cJSON_IsNumber(wait))
    {
    goto end; //Numeric
    }
    }

    // instance_input_request->start
    cJSON *start = cJSON_GetObjectItemCaseSensitive(instance_input_requestJSON, "start");
    if (cJSON_IsNull(start)) {
        start = NULL;
    }
    if (!start) {
        goto end;
    }

    object_t *start_local_object = NULL;
    
    start_local_object = object_parseFromJSON(start); //object

    // instance_input_request->end
    cJSON *end = cJSON_GetObjectItemCaseSensitive(instance_input_requestJSON, "end");
    if (cJSON_IsNull(end)) {
        end = NULL;
    }
    if (!end) {
        goto end;
    }

    object_t *end_local_object = NULL;
    
    end_local_object = object_parseFromJSON(end); //object

    // instance_input_request->bezier_points
    cJSON *bezier_points = cJSON_GetObjectItemCaseSensitive(instance_input_requestJSON, "bezierPoints");
    if (cJSON_IsNull(bezier_points)) {
        bezier_points = NULL;
    }
    if (bezier_points) { 
    cJSON *bezier_points_local_nonprimitive = NULL;
    if(!cJSON_IsArray(bezier_points)){
        goto end; //nonprimitive container
    }

    bezier_pointsList = list_createList();

    cJSON_ArrayForEach(bezier_points_local_nonprimitive,bezier_points )
    {
        if(!cJSON_IsObject(bezier_points_local_nonprimitive)){
            goto end;
        }
        object_t *bezier_pointsItem = object_parseFromJSON(bezier_points_local_nonprimitive);

        list_addElement(bezier_pointsList, bezier_pointsItem);
    }
    }

    // instance_input_request->start_buttons
    cJSON *start_buttons = cJSON_GetObjectItemCaseSensitive(instance_input_requestJSON, "startButtons");
    if (cJSON_IsNull(start_buttons)) {
        start_buttons = NULL;
    }
    if (!start_buttons) {
        goto end;
    }

    
    cJSON *start_buttons_local_nonprimitive = NULL;
    if(!cJSON_IsArray(start_buttons)){
        goto end; //nonprimitive container
    }

    start_buttonsList = list_createList();

    cJSON_ArrayForEach(start_buttons_local_nonprimitive,start_buttons )
    {
        if(!cJSON_IsObject(start_buttons_local_nonprimitive)){
            goto end;
        }
        object_t *start_buttonsItem = object_parseFromJSON(start_buttons_local_nonprimitive);

        list_addElement(start_buttonsList, start_buttonsItem);
    }

    // instance_input_request->end_buttons
    cJSON *end_buttons = cJSON_GetObjectItemCaseSensitive(instance_input_requestJSON, "endButtons");
    if (cJSON_IsNull(end_buttons)) {
        end_buttons = NULL;
    }
    if (end_buttons) { 
    cJSON *end_buttons_local_nonprimitive = NULL;
    if(!cJSON_IsArray(end_buttons)){
        goto end; //nonprimitive container
    }

    end_buttonsList = list_createList();

    cJSON_ArrayForEach(end_buttons_local_nonprimitive,end_buttons )
    {
        if(!cJSON_IsObject(end_buttons_local_nonprimitive)){
            goto end;
        }
        object_t *end_buttonsItem = object_parseFromJSON(end_buttons_local_nonprimitive);

        list_addElement(end_buttonsList, end_buttonsItem);
    }
    }

    // instance_input_request->duration
    cJSON *duration = cJSON_GetObjectItemCaseSensitive(instance_input_requestJSON, "duration");
    if (cJSON_IsNull(duration)) {
        duration = NULL;
    }
    if (!duration) {
        goto end;
    }

    
    if(!cJSON_IsNumber(duration))
    {
    goto end; //Numeric
    }

    // instance_input_request->required
    cJSON *required = cJSON_GetObjectItemCaseSensitive(instance_input_requestJSON, "required");
    if (cJSON_IsNull(required)) {
        required = NULL;
    }
    if (!required) {
        goto end;
    }

    
    if(!cJSON_IsString(required))
    {
    goto end; //String
    }

    // instance_input_request->key_duration
    cJSON *key_duration = cJSON_GetObjectItemCaseSensitive(instance_input_requestJSON, "keyDuration");
    if (cJSON_IsNull(key_duration)) {
        key_duration = NULL;
    }
    if (key_duration) { 
    if(!cJSON_IsNumber(key_duration))
    {
    goto end; //Numeric
    }
    }


    instance_input_request_local_var = instance_input_request_create_internal (
        position_local_object,
        buttons ? buttonsList : NULL,
        normalized ? normalized->valueint : 0,
        wait ? wait->valuedouble : 0,
        start_local_object,
        end_local_object,
        bezier_points ? bezier_pointsList : NULL,
        start_buttonsList,
        end_buttons ? end_buttonsList : NULL,
        duration->valuedouble,
        strdup(required->valuestring),
        key_duration ? key_duration->valuedouble : 0
        );

    return instance_input_request_local_var;
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
    if (bezier_pointsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, bezier_pointsList) {
            object_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(bezier_pointsList);
        bezier_pointsList = NULL;
    }
    if (start_buttonsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, start_buttonsList) {
            object_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(start_buttonsList);
        start_buttonsList = NULL;
    }
    if (end_buttonsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, end_buttonsList) {
            object_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(end_buttonsList);
        end_buttonsList = NULL;
    }
    return NULL;

}
