#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "instance_input_body.h"



static instance_input_body_t *instance_input_body_create_internal(
    list_t *position,
    list_t *buttons,
    int normalized,
    double wait,
    list_t *start,
    list_t *end,
    list_t *bezier_points,
    list_t *start_buttons,
    list_t *end_buttons,
    double duration,
    char *text,
    double key_duration
    ) {
    instance_input_body_t *instance_input_body_local_var = malloc(sizeof(instance_input_body_t));
    if (!instance_input_body_local_var) {
        return NULL;
    }
    instance_input_body_local_var->position = position;
    instance_input_body_local_var->buttons = buttons;
    instance_input_body_local_var->normalized = normalized;
    instance_input_body_local_var->wait = wait;
    instance_input_body_local_var->start = start;
    instance_input_body_local_var->end = end;
    instance_input_body_local_var->bezier_points = bezier_points;
    instance_input_body_local_var->start_buttons = start_buttons;
    instance_input_body_local_var->end_buttons = end_buttons;
    instance_input_body_local_var->duration = duration;
    instance_input_body_local_var->text = text;
    instance_input_body_local_var->key_duration = key_duration;

    instance_input_body_local_var->_library_owned = 1;
    return instance_input_body_local_var;
}

__attribute__((deprecated)) instance_input_body_t *instance_input_body_create(
    list_t *position,
    list_t *buttons,
    int normalized,
    double wait,
    list_t *start,
    list_t *end,
    list_t *bezier_points,
    list_t *start_buttons,
    list_t *end_buttons,
    double duration,
    char *text,
    double key_duration
    ) {
    return instance_input_body_create_internal (
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
        text,
        key_duration
        );
}

void instance_input_body_free(instance_input_body_t *instance_input_body) {
    if(NULL == instance_input_body){
        return ;
    }
    if(instance_input_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "instance_input_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (instance_input_body->position) {
        list_ForEach(listEntry, instance_input_body->position) {
            free(listEntry->data);
        }
        list_freeList(instance_input_body->position);
        instance_input_body->position = NULL;
    }
    if (instance_input_body->buttons) {
        list_ForEach(listEntry, instance_input_body->buttons) {
            free(listEntry->data);
        }
        list_freeList(instance_input_body->buttons);
        instance_input_body->buttons = NULL;
    }
    if (instance_input_body->start) {
        list_ForEach(listEntry, instance_input_body->start) {
            free(listEntry->data);
        }
        list_freeList(instance_input_body->start);
        instance_input_body->start = NULL;
    }
    if (instance_input_body->end) {
        list_ForEach(listEntry, instance_input_body->end) {
            free(listEntry->data);
        }
        list_freeList(instance_input_body->end);
        instance_input_body->end = NULL;
    }
    if (instance_input_body->bezier_points) {
        list_ForEach(listEntry, instance_input_body->bezier_points) {
            free(listEntry->data);
        }
        list_freeList(instance_input_body->bezier_points);
        instance_input_body->bezier_points = NULL;
    }
    if (instance_input_body->start_buttons) {
        list_ForEach(listEntry, instance_input_body->start_buttons) {
            free(listEntry->data);
        }
        list_freeList(instance_input_body->start_buttons);
        instance_input_body->start_buttons = NULL;
    }
    if (instance_input_body->end_buttons) {
        list_ForEach(listEntry, instance_input_body->end_buttons) {
            free(listEntry->data);
        }
        list_freeList(instance_input_body->end_buttons);
        instance_input_body->end_buttons = NULL;
    }
    if (instance_input_body->text) {
        free(instance_input_body->text);
        instance_input_body->text = NULL;
    }
    free(instance_input_body);
}

cJSON *instance_input_body_convertToJSON(instance_input_body_t *instance_input_body) {
    cJSON *item = cJSON_CreateObject();

    // instance_input_body->position
    if (!instance_input_body->position) {
        goto fail;
    }
    cJSON *position = cJSON_AddArrayToObject(item, "position");
    if(position == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *positionListEntry;
    list_ForEach(positionListEntry, instance_input_body->position) {
    }


    // instance_input_body->buttons
    if(instance_input_body->buttons) {
    cJSON *buttons = cJSON_AddArrayToObject(item, "buttons");
    if(buttons == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *buttonsListEntry;
    list_ForEach(buttonsListEntry, instance_input_body->buttons) {
    if(cJSON_AddStringToObject(buttons, "", buttonsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // instance_input_body->normalized
    if(instance_input_body->normalized) {
    if(cJSON_AddBoolToObject(item, "normalized", instance_input_body->normalized) == NULL) {
    goto fail; //Bool
    }
    }


    // instance_input_body->wait
    if(instance_input_body->wait) {
    if(cJSON_AddNumberToObject(item, "wait", instance_input_body->wait) == NULL) {
    goto fail; //Numeric
    }
    }


    // instance_input_body->start
    if (!instance_input_body->start) {
        goto fail;
    }
    cJSON *start = cJSON_AddArrayToObject(item, "start");
    if(start == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *startListEntry;
    list_ForEach(startListEntry, instance_input_body->start) {
    }


    // instance_input_body->end
    if (!instance_input_body->end) {
        goto fail;
    }
    cJSON *end = cJSON_AddArrayToObject(item, "end");
    if(end == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *endListEntry;
    list_ForEach(endListEntry, instance_input_body->end) {
    }


    // instance_input_body->bezier_points
    if(instance_input_body->bezier_points) {
    cJSON *bezier_points = cJSON_AddArrayToObject(item, "bezierPoints");
    if(bezier_points == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *bezier_pointsListEntry;
    list_ForEach(bezier_pointsListEntry, instance_input_body->bezier_points) {
    }
    }


    // instance_input_body->start_buttons
    if (!instance_input_body->start_buttons) {
        goto fail;
    }
    cJSON *start_buttons = cJSON_AddArrayToObject(item, "startButtons");
    if(start_buttons == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *start_buttonsListEntry;
    list_ForEach(start_buttonsListEntry, instance_input_body->start_buttons) {
    if(cJSON_AddStringToObject(start_buttons, "", start_buttonsListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // instance_input_body->end_buttons
    if(instance_input_body->end_buttons) {
    cJSON *end_buttons = cJSON_AddArrayToObject(item, "endButtons");
    if(end_buttons == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *end_buttonsListEntry;
    list_ForEach(end_buttonsListEntry, instance_input_body->end_buttons) {
    if(cJSON_AddStringToObject(end_buttons, "", end_buttonsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // instance_input_body->duration
    if (!instance_input_body->duration) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "duration", instance_input_body->duration) == NULL) {
    goto fail; //Numeric
    }


    // instance_input_body->text
    if (!instance_input_body->text) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "text", instance_input_body->text) == NULL) {
    goto fail; //String
    }


    // instance_input_body->key_duration
    if(instance_input_body->key_duration) {
    if(cJSON_AddNumberToObject(item, "keyDuration", instance_input_body->key_duration) == NULL) {
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

instance_input_body_t *instance_input_body_parseFromJSON(cJSON *instance_input_bodyJSON){

    instance_input_body_t *instance_input_body_local_var = NULL;

    // define the local list for instance_input_body->position
    list_t *positionList = NULL;

    // define the local list for instance_input_body->buttons
    list_t *buttonsList = NULL;

    // define the local list for instance_input_body->start
    list_t *startList = NULL;

    // define the local list for instance_input_body->end
    list_t *endList = NULL;

    // define the local list for instance_input_body->bezier_points
    list_t *bezier_pointsList = NULL;

    // define the local list for instance_input_body->start_buttons
    list_t *start_buttonsList = NULL;

    // define the local list for instance_input_body->end_buttons
    list_t *end_buttonsList = NULL;

    // instance_input_body->position
    cJSON *position = cJSON_GetObjectItemCaseSensitive(instance_input_bodyJSON, "position");
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

    // instance_input_body->buttons
    cJSON *buttons = cJSON_GetObjectItemCaseSensitive(instance_input_bodyJSON, "buttons");
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

    // instance_input_body->normalized
    cJSON *normalized = cJSON_GetObjectItemCaseSensitive(instance_input_bodyJSON, "normalized");
    if (cJSON_IsNull(normalized)) {
        normalized = NULL;
    }
    if (normalized) { 
    if(!cJSON_IsBool(normalized))
    {
    goto end; //Bool
    }
    }

    // instance_input_body->wait
    cJSON *wait = cJSON_GetObjectItemCaseSensitive(instance_input_bodyJSON, "wait");
    if (cJSON_IsNull(wait)) {
        wait = NULL;
    }
    if (wait) { 
    if(!cJSON_IsNumber(wait))
    {
    goto end; //Numeric
    }
    }

    // instance_input_body->start
    cJSON *start = cJSON_GetObjectItemCaseSensitive(instance_input_bodyJSON, "start");
    if (cJSON_IsNull(start)) {
        start = NULL;
    }
    if (!start) {
        goto end;
    }

    
    cJSON *start_local = NULL;
    if(!cJSON_IsArray(start)) {
        goto end;//primitive container
    }
    startList = list_createList();

    cJSON_ArrayForEach(start_local, start)
    {
    }

    // instance_input_body->end
    cJSON *end = cJSON_GetObjectItemCaseSensitive(instance_input_bodyJSON, "end");
    if (cJSON_IsNull(end)) {
        end = NULL;
    }
    if (!end) {
        goto end;
    }

    
    cJSON *end_local = NULL;
    if(!cJSON_IsArray(end)) {
        goto end;//primitive container
    }
    endList = list_createList();

    cJSON_ArrayForEach(end_local, end)
    {
    }

    // instance_input_body->bezier_points
    cJSON *bezier_points = cJSON_GetObjectItemCaseSensitive(instance_input_bodyJSON, "bezierPoints");
    if (cJSON_IsNull(bezier_points)) {
        bezier_points = NULL;
    }
    if (bezier_points) { 
    cJSON *bezier_points_local = NULL;
    if(!cJSON_IsArray(bezier_points)) {
        goto end;//primitive container
    }
    bezier_pointsList = list_createList();

    cJSON_ArrayForEach(bezier_points_local, bezier_points)
    {
    }
    }

    // instance_input_body->start_buttons
    cJSON *start_buttons = cJSON_GetObjectItemCaseSensitive(instance_input_bodyJSON, "startButtons");
    if (cJSON_IsNull(start_buttons)) {
        start_buttons = NULL;
    }
    if (!start_buttons) {
        goto end;
    }

    
    cJSON *start_buttons_local = NULL;
    if(!cJSON_IsArray(start_buttons)) {
        goto end;//primitive container
    }
    start_buttonsList = list_createList();

    cJSON_ArrayForEach(start_buttons_local, start_buttons)
    {
        if(!cJSON_IsString(start_buttons_local))
        {
            goto end;
        }
        list_addElement(start_buttonsList , strdup(start_buttons_local->valuestring));
    }

    // instance_input_body->end_buttons
    cJSON *end_buttons = cJSON_GetObjectItemCaseSensitive(instance_input_bodyJSON, "endButtons");
    if (cJSON_IsNull(end_buttons)) {
        end_buttons = NULL;
    }
    if (end_buttons) { 
    cJSON *end_buttons_local = NULL;
    if(!cJSON_IsArray(end_buttons)) {
        goto end;//primitive container
    }
    end_buttonsList = list_createList();

    cJSON_ArrayForEach(end_buttons_local, end_buttons)
    {
        if(!cJSON_IsString(end_buttons_local))
        {
            goto end;
        }
        list_addElement(end_buttonsList , strdup(end_buttons_local->valuestring));
    }
    }

    // instance_input_body->duration
    cJSON *duration = cJSON_GetObjectItemCaseSensitive(instance_input_bodyJSON, "duration");
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

    // instance_input_body->text
    cJSON *text = cJSON_GetObjectItemCaseSensitive(instance_input_bodyJSON, "text");
    if (cJSON_IsNull(text)) {
        text = NULL;
    }
    if (!text) {
        goto end;
    }

    
    if(!cJSON_IsString(text))
    {
    goto end; //String
    }

    // instance_input_body->key_duration
    cJSON *key_duration = cJSON_GetObjectItemCaseSensitive(instance_input_bodyJSON, "keyDuration");
    if (cJSON_IsNull(key_duration)) {
        key_duration = NULL;
    }
    if (key_duration) { 
    if(!cJSON_IsNumber(key_duration))
    {
    goto end; //Numeric
    }
    }


    instance_input_body_local_var = instance_input_body_create_internal (
        positionList,
        buttons ? buttonsList : NULL,
        normalized ? normalized->valueint : 0,
        wait ? wait->valuedouble : 0,
        startList,
        endList,
        bezier_points ? bezier_pointsList : NULL,
        start_buttonsList,
        end_buttons ? end_buttonsList : NULL,
        duration->valuedouble,
        strdup(text->valuestring),
        key_duration ? key_duration->valuedouble : 0
        );

    return instance_input_body_local_var;
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
    if (startList) {
        list_freeList(startList);
        startList = NULL;
    }
    if (endList) {
        list_freeList(endList);
        endList = NULL;
    }
    if (bezier_pointsList) {
        list_freeList(bezier_pointsList);
        bezier_pointsList = NULL;
    }
    if (start_buttonsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, start_buttonsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(start_buttonsList);
        start_buttonsList = NULL;
    }
    if (end_buttonsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, end_buttonsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(end_buttonsList);
        end_buttonsList = NULL;
    }
    return NULL;

}
