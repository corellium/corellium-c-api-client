#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "touch_curve_input_request.h"



static touch_curve_input_request_t *touch_curve_input_request_create_internal(
    list_t *start,
    list_t *end,
    list_t *bezier_points,
    list_t *start_buttons,
    list_t *end_buttons,
    int normalized,
    double wait,
    double duration
    ) {
    touch_curve_input_request_t *touch_curve_input_request_local_var = malloc(sizeof(touch_curve_input_request_t));
    if (!touch_curve_input_request_local_var) {
        return NULL;
    }
    touch_curve_input_request_local_var->start = start;
    touch_curve_input_request_local_var->end = end;
    touch_curve_input_request_local_var->bezier_points = bezier_points;
    touch_curve_input_request_local_var->start_buttons = start_buttons;
    touch_curve_input_request_local_var->end_buttons = end_buttons;
    touch_curve_input_request_local_var->normalized = normalized;
    touch_curve_input_request_local_var->wait = wait;
    touch_curve_input_request_local_var->duration = duration;

    touch_curve_input_request_local_var->_library_owned = 1;
    return touch_curve_input_request_local_var;
}

__attribute__((deprecated)) touch_curve_input_request_t *touch_curve_input_request_create(
    list_t *start,
    list_t *end,
    list_t *bezier_points,
    list_t *start_buttons,
    list_t *end_buttons,
    int normalized,
    double wait,
    double duration
    ) {
    return touch_curve_input_request_create_internal (
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

void touch_curve_input_request_free(touch_curve_input_request_t *touch_curve_input_request) {
    if(NULL == touch_curve_input_request){
        return ;
    }
    if(touch_curve_input_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "touch_curve_input_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (touch_curve_input_request->start) {
        list_ForEach(listEntry, touch_curve_input_request->start) {
            free(listEntry->data);
        }
        list_freeList(touch_curve_input_request->start);
        touch_curve_input_request->start = NULL;
    }
    if (touch_curve_input_request->end) {
        list_ForEach(listEntry, touch_curve_input_request->end) {
            free(listEntry->data);
        }
        list_freeList(touch_curve_input_request->end);
        touch_curve_input_request->end = NULL;
    }
    if (touch_curve_input_request->bezier_points) {
        list_ForEach(listEntry, touch_curve_input_request->bezier_points) {
            free(listEntry->data);
        }
        list_freeList(touch_curve_input_request->bezier_points);
        touch_curve_input_request->bezier_points = NULL;
    }
    if (touch_curve_input_request->start_buttons) {
        list_ForEach(listEntry, touch_curve_input_request->start_buttons) {
            free(listEntry->data);
        }
        list_freeList(touch_curve_input_request->start_buttons);
        touch_curve_input_request->start_buttons = NULL;
    }
    if (touch_curve_input_request->end_buttons) {
        list_ForEach(listEntry, touch_curve_input_request->end_buttons) {
            free(listEntry->data);
        }
        list_freeList(touch_curve_input_request->end_buttons);
        touch_curve_input_request->end_buttons = NULL;
    }
    free(touch_curve_input_request);
}

cJSON *touch_curve_input_request_convertToJSON(touch_curve_input_request_t *touch_curve_input_request) {
    cJSON *item = cJSON_CreateObject();

    // touch_curve_input_request->start
    if (!touch_curve_input_request->start) {
        goto fail;
    }
    cJSON *start = cJSON_AddArrayToObject(item, "start");
    if(start == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *startListEntry;
    list_ForEach(startListEntry, touch_curve_input_request->start) {
    }


    // touch_curve_input_request->end
    if (!touch_curve_input_request->end) {
        goto fail;
    }
    cJSON *end = cJSON_AddArrayToObject(item, "end");
    if(end == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *endListEntry;
    list_ForEach(endListEntry, touch_curve_input_request->end) {
    }


    // touch_curve_input_request->bezier_points
    if(touch_curve_input_request->bezier_points) {
    cJSON *bezier_points = cJSON_AddArrayToObject(item, "bezierPoints");
    if(bezier_points == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *bezier_pointsListEntry;
    list_ForEach(bezier_pointsListEntry, touch_curve_input_request->bezier_points) {
    }
    }


    // touch_curve_input_request->start_buttons
    if (!touch_curve_input_request->start_buttons) {
        goto fail;
    }
    cJSON *start_buttons = cJSON_AddArrayToObject(item, "startButtons");
    if(start_buttons == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *start_buttonsListEntry;
    list_ForEach(start_buttonsListEntry, touch_curve_input_request->start_buttons) {
    if(cJSON_AddStringToObject(start_buttons, "", start_buttonsListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // touch_curve_input_request->end_buttons
    if(touch_curve_input_request->end_buttons) {
    cJSON *end_buttons = cJSON_AddArrayToObject(item, "endButtons");
    if(end_buttons == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *end_buttonsListEntry;
    list_ForEach(end_buttonsListEntry, touch_curve_input_request->end_buttons) {
    if(cJSON_AddStringToObject(end_buttons, "", end_buttonsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // touch_curve_input_request->normalized
    if(touch_curve_input_request->normalized) {
    if(cJSON_AddBoolToObject(item, "normalized", touch_curve_input_request->normalized) == NULL) {
    goto fail; //Bool
    }
    }


    // touch_curve_input_request->wait
    if(touch_curve_input_request->wait) {
    if(cJSON_AddNumberToObject(item, "wait", touch_curve_input_request->wait) == NULL) {
    goto fail; //Numeric
    }
    }


    // touch_curve_input_request->duration
    if (!touch_curve_input_request->duration) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "duration", touch_curve_input_request->duration) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

touch_curve_input_request_t *touch_curve_input_request_parseFromJSON(cJSON *touch_curve_input_requestJSON){

    touch_curve_input_request_t *touch_curve_input_request_local_var = NULL;

    // define the local list for touch_curve_input_request->start
    list_t *startList = NULL;

    // define the local list for touch_curve_input_request->end
    list_t *endList = NULL;

    // define the local list for touch_curve_input_request->bezier_points
    list_t *bezier_pointsList = NULL;

    // define the local list for touch_curve_input_request->start_buttons
    list_t *start_buttonsList = NULL;

    // define the local list for touch_curve_input_request->end_buttons
    list_t *end_buttonsList = NULL;

    // touch_curve_input_request->start
    cJSON *start = cJSON_GetObjectItemCaseSensitive(touch_curve_input_requestJSON, "start");
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

    // touch_curve_input_request->end
    cJSON *end = cJSON_GetObjectItemCaseSensitive(touch_curve_input_requestJSON, "end");
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

    // touch_curve_input_request->bezier_points
    cJSON *bezier_points = cJSON_GetObjectItemCaseSensitive(touch_curve_input_requestJSON, "bezierPoints");
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

    // touch_curve_input_request->start_buttons
    cJSON *start_buttons = cJSON_GetObjectItemCaseSensitive(touch_curve_input_requestJSON, "startButtons");
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

    // touch_curve_input_request->end_buttons
    cJSON *end_buttons = cJSON_GetObjectItemCaseSensitive(touch_curve_input_requestJSON, "endButtons");
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

    // touch_curve_input_request->normalized
    cJSON *normalized = cJSON_GetObjectItemCaseSensitive(touch_curve_input_requestJSON, "normalized");
    if (cJSON_IsNull(normalized)) {
        normalized = NULL;
    }
    if (normalized) { 
    if(!cJSON_IsBool(normalized))
    {
    goto end; //Bool
    }
    }

    // touch_curve_input_request->wait
    cJSON *wait = cJSON_GetObjectItemCaseSensitive(touch_curve_input_requestJSON, "wait");
    if (cJSON_IsNull(wait)) {
        wait = NULL;
    }
    if (wait) { 
    if(!cJSON_IsNumber(wait))
    {
    goto end; //Numeric
    }
    }

    // touch_curve_input_request->duration
    cJSON *duration = cJSON_GetObjectItemCaseSensitive(touch_curve_input_requestJSON, "duration");
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


    touch_curve_input_request_local_var = touch_curve_input_request_create_internal (
        startList,
        endList,
        bezier_points ? bezier_pointsList : NULL,
        start_buttonsList,
        end_buttons ? end_buttonsList : NULL,
        normalized ? normalized->valueint : 0,
        wait ? wait->valuedouble : 0,
        duration->valuedouble
        );

    return touch_curve_input_request_local_var;
end:
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
