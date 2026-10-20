#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "touch_curve_input_request_v1.h"



static touch_curve_input_request_v1_t *touch_curve_input_request_v1_create_internal(
    object_t *start,
    object_t *end,
    list_t *bezier_points,
    list_t *start_buttons,
    list_t *end_buttons,
    int normalized,
    double wait,
    double duration
    ) {
    touch_curve_input_request_v1_t *touch_curve_input_request_v1_local_var = malloc(sizeof(touch_curve_input_request_v1_t));
    if (!touch_curve_input_request_v1_local_var) {
        return NULL;
    }
    touch_curve_input_request_v1_local_var->start = start;
    touch_curve_input_request_v1_local_var->end = end;
    touch_curve_input_request_v1_local_var->bezier_points = bezier_points;
    touch_curve_input_request_v1_local_var->start_buttons = start_buttons;
    touch_curve_input_request_v1_local_var->end_buttons = end_buttons;
    touch_curve_input_request_v1_local_var->normalized = normalized;
    touch_curve_input_request_v1_local_var->wait = wait;
    touch_curve_input_request_v1_local_var->duration = duration;

    touch_curve_input_request_v1_local_var->_library_owned = 1;
    return touch_curve_input_request_v1_local_var;
}

__attribute__((deprecated)) touch_curve_input_request_v1_t *touch_curve_input_request_v1_create(
    object_t *start,
    object_t *end,
    list_t *bezier_points,
    list_t *start_buttons,
    list_t *end_buttons,
    int normalized,
    double wait,
    double duration
    ) {
    return touch_curve_input_request_v1_create_internal (
        start,
        end,
        bezier_points,
        start_buttons,
        end_buttons,
        normalized,
        wait,
        duration
        );
}

void touch_curve_input_request_v1_free(touch_curve_input_request_v1_t *touch_curve_input_request_v1) {
    if(NULL == touch_curve_input_request_v1){
        return ;
    }
    if(touch_curve_input_request_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "touch_curve_input_request_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (touch_curve_input_request_v1->start) {
        object_free(touch_curve_input_request_v1->start);
        touch_curve_input_request_v1->start = NULL;
    }
    if (touch_curve_input_request_v1->end) {
        object_free(touch_curve_input_request_v1->end);
        touch_curve_input_request_v1->end = NULL;
    }
    if (touch_curve_input_request_v1->bezier_points) {
        list_ForEach(listEntry, touch_curve_input_request_v1->bezier_points) {
            object_free(listEntry->data);
        }
        list_freeList(touch_curve_input_request_v1->bezier_points);
        touch_curve_input_request_v1->bezier_points = NULL;
    }
    if (touch_curve_input_request_v1->start_buttons) {
        list_ForEach(listEntry, touch_curve_input_request_v1->start_buttons) {
            object_free(listEntry->data);
        }
        list_freeList(touch_curve_input_request_v1->start_buttons);
        touch_curve_input_request_v1->start_buttons = NULL;
    }
    if (touch_curve_input_request_v1->end_buttons) {
        list_ForEach(listEntry, touch_curve_input_request_v1->end_buttons) {
            object_free(listEntry->data);
        }
        list_freeList(touch_curve_input_request_v1->end_buttons);
        touch_curve_input_request_v1->end_buttons = NULL;
    }
    free(touch_curve_input_request_v1);
}

cJSON *touch_curve_input_request_v1_convertToJSON(touch_curve_input_request_v1_t *touch_curve_input_request_v1) {
    cJSON *item = cJSON_CreateObject();

    // touch_curve_input_request_v1->start
    if (!touch_curve_input_request_v1->start) {
        goto fail;
    }
    cJSON *start_object = object_convertToJSON(touch_curve_input_request_v1->start);
    if(start_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "start", start_object);
    if(item->child == NULL) {
    goto fail;
    }


    // touch_curve_input_request_v1->end
    if (!touch_curve_input_request_v1->end) {
        goto fail;
    }
    cJSON *end_object = object_convertToJSON(touch_curve_input_request_v1->end);
    if(end_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "end", end_object);
    if(item->child == NULL) {
    goto fail;
    }


    // touch_curve_input_request_v1->bezier_points
    if(touch_curve_input_request_v1->bezier_points) {
    cJSON *bezier_points = cJSON_AddArrayToObject(item, "bezierPoints");
    if(bezier_points == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *bezier_pointsListEntry;
    if (touch_curve_input_request_v1->bezier_points) {
    list_ForEach(bezier_pointsListEntry, touch_curve_input_request_v1->bezier_points) {
    cJSON *itemLocal = object_convertToJSON(bezier_pointsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(bezier_points, itemLocal);
    }
    }
    }


    // touch_curve_input_request_v1->start_buttons
    if (!touch_curve_input_request_v1->start_buttons) {
        goto fail;
    }
    cJSON *start_buttons = cJSON_AddArrayToObject(item, "startButtons");
    if(start_buttons == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *start_buttonsListEntry;
    if (touch_curve_input_request_v1->start_buttons) {
    list_ForEach(start_buttonsListEntry, touch_curve_input_request_v1->start_buttons) {
    cJSON *itemLocal = object_convertToJSON(start_buttonsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(start_buttons, itemLocal);
    }
    }


    // touch_curve_input_request_v1->end_buttons
    if(touch_curve_input_request_v1->end_buttons) {
    cJSON *end_buttons = cJSON_AddArrayToObject(item, "endButtons");
    if(end_buttons == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *end_buttonsListEntry;
    if (touch_curve_input_request_v1->end_buttons) {
    list_ForEach(end_buttonsListEntry, touch_curve_input_request_v1->end_buttons) {
    cJSON *itemLocal = object_convertToJSON(end_buttonsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(end_buttons, itemLocal);
    }
    }
    }


    // touch_curve_input_request_v1->normalized
    if(touch_curve_input_request_v1->normalized) {
    if(cJSON_AddBoolToObject(item, "normalized", touch_curve_input_request_v1->normalized) == NULL) {
    goto fail; //Bool
    }
    }


    // touch_curve_input_request_v1->wait
    if(touch_curve_input_request_v1->wait) {
    if(cJSON_AddNumberToObject(item, "wait", touch_curve_input_request_v1->wait) == NULL) {
    goto fail; //Numeric
    }
    }


    // touch_curve_input_request_v1->duration
    if (!touch_curve_input_request_v1->duration) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "duration", touch_curve_input_request_v1->duration) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

touch_curve_input_request_v1_t *touch_curve_input_request_v1_parseFromJSON(cJSON *touch_curve_input_request_v1JSON){

    touch_curve_input_request_v1_t *touch_curve_input_request_v1_local_var = NULL;

    // define the local list for touch_curve_input_request_v1->bezier_points
    list_t *bezier_pointsList = NULL;

    // define the local list for touch_curve_input_request_v1->start_buttons
    list_t *start_buttonsList = NULL;

    // define the local list for touch_curve_input_request_v1->end_buttons
    list_t *end_buttonsList = NULL;

    // touch_curve_input_request_v1->start
    cJSON *start = cJSON_GetObjectItemCaseSensitive(touch_curve_input_request_v1JSON, "start");
    if (cJSON_IsNull(start)) {
        start = NULL;
    }
    if (!start) {
        goto end;
    }

    object_t *start_local_object = NULL;
    
    start_local_object = object_parseFromJSON(start); //object

    // touch_curve_input_request_v1->end
    cJSON *end = cJSON_GetObjectItemCaseSensitive(touch_curve_input_request_v1JSON, "end");
    if (cJSON_IsNull(end)) {
        end = NULL;
    }
    if (!end) {
        goto end;
    }

    object_t *end_local_object = NULL;
    
    end_local_object = object_parseFromJSON(end); //object

    // touch_curve_input_request_v1->bezier_points
    cJSON *bezier_points = cJSON_GetObjectItemCaseSensitive(touch_curve_input_request_v1JSON, "bezierPoints");
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

    // touch_curve_input_request_v1->start_buttons
    cJSON *start_buttons = cJSON_GetObjectItemCaseSensitive(touch_curve_input_request_v1JSON, "startButtons");
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

    // touch_curve_input_request_v1->end_buttons
    cJSON *end_buttons = cJSON_GetObjectItemCaseSensitive(touch_curve_input_request_v1JSON, "endButtons");
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

    // touch_curve_input_request_v1->normalized
    cJSON *normalized = cJSON_GetObjectItemCaseSensitive(touch_curve_input_request_v1JSON, "normalized");
    if (cJSON_IsNull(normalized)) {
        normalized = NULL;
    }
    if (normalized) { 
    if(!cJSON_IsBool(normalized))
    {
    goto end; //Bool
    }
    }

    // touch_curve_input_request_v1->wait
    cJSON *wait = cJSON_GetObjectItemCaseSensitive(touch_curve_input_request_v1JSON, "wait");
    if (cJSON_IsNull(wait)) {
        wait = NULL;
    }
    if (wait) { 
    if(!cJSON_IsNumber(wait))
    {
    goto end; //Numeric
    }
    }

    // touch_curve_input_request_v1->duration
    cJSON *duration = cJSON_GetObjectItemCaseSensitive(touch_curve_input_request_v1JSON, "duration");
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


    touch_curve_input_request_v1_local_var = touch_curve_input_request_v1_create_internal (
        start_local_object,
        end_local_object,
        bezier_points ? bezier_pointsList : NULL,
        start_buttonsList,
        end_buttons ? end_buttonsList : NULL,
        normalized ? normalized->valueint : 0,
        wait ? wait->valuedouble : 0,
        duration->valuedouble
        );

    return touch_curve_input_request_v1_local_var;
end:
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
