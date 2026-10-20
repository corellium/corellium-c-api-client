#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "model_frame_home.h"



static model_frame_home_t *model_frame_home_create_internal(
    double top,
    double left,
    double width,
    double height,
    double radius
    ) {
    model_frame_home_t *model_frame_home_local_var = malloc(sizeof(model_frame_home_t));
    if (!model_frame_home_local_var) {
        return NULL;
    }
    model_frame_home_local_var->top = top;
    model_frame_home_local_var->left = left;
    model_frame_home_local_var->width = width;
    model_frame_home_local_var->height = height;
    model_frame_home_local_var->radius = radius;

    model_frame_home_local_var->_library_owned = 1;
    return model_frame_home_local_var;
}

__attribute__((deprecated)) model_frame_home_t *model_frame_home_create(
    double top,
    double left,
    double width,
    double height,
    double radius
    ) {
    return model_frame_home_create_internal (
        top,
        left,
        width,
        height,
        radius
        );
}

void model_frame_home_free(model_frame_home_t *model_frame_home) {
    if(NULL == model_frame_home){
        return ;
    }
    if(model_frame_home->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "model_frame_home_free");
        return ;
    }
    listEntry_t *listEntry;
    free(model_frame_home);
}

cJSON *model_frame_home_convertToJSON(model_frame_home_t *model_frame_home) {
    cJSON *item = cJSON_CreateObject();

    // model_frame_home->top
    if (!model_frame_home->top) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "top", model_frame_home->top) == NULL) {
    goto fail; //Numeric
    }


    // model_frame_home->left
    if (!model_frame_home->left) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "left", model_frame_home->left) == NULL) {
    goto fail; //Numeric
    }


    // model_frame_home->width
    if (!model_frame_home->width) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "width", model_frame_home->width) == NULL) {
    goto fail; //Numeric
    }


    // model_frame_home->height
    if (!model_frame_home->height) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "height", model_frame_home->height) == NULL) {
    goto fail; //Numeric
    }


    // model_frame_home->radius
    if(model_frame_home->radius) {
    if(cJSON_AddNumberToObject(item, "radius", model_frame_home->radius) == NULL) {
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

model_frame_home_t *model_frame_home_parseFromJSON(cJSON *model_frame_homeJSON){

    model_frame_home_t *model_frame_home_local_var = NULL;

    // model_frame_home->top
    cJSON *top = cJSON_GetObjectItemCaseSensitive(model_frame_homeJSON, "top");
    if (cJSON_IsNull(top)) {
        top = NULL;
    }
    if (!top) {
        goto end;
    }

    
    if(!cJSON_IsNumber(top))
    {
    goto end; //Numeric
    }

    // model_frame_home->left
    cJSON *left = cJSON_GetObjectItemCaseSensitive(model_frame_homeJSON, "left");
    if (cJSON_IsNull(left)) {
        left = NULL;
    }
    if (!left) {
        goto end;
    }

    
    if(!cJSON_IsNumber(left))
    {
    goto end; //Numeric
    }

    // model_frame_home->width
    cJSON *width = cJSON_GetObjectItemCaseSensitive(model_frame_homeJSON, "width");
    if (cJSON_IsNull(width)) {
        width = NULL;
    }
    if (!width) {
        goto end;
    }

    
    if(!cJSON_IsNumber(width))
    {
    goto end; //Numeric
    }

    // model_frame_home->height
    cJSON *height = cJSON_GetObjectItemCaseSensitive(model_frame_homeJSON, "height");
    if (cJSON_IsNull(height)) {
        height = NULL;
    }
    if (!height) {
        goto end;
    }

    
    if(!cJSON_IsNumber(height))
    {
    goto end; //Numeric
    }

    // model_frame_home->radius
    cJSON *radius = cJSON_GetObjectItemCaseSensitive(model_frame_homeJSON, "radius");
    if (cJSON_IsNull(radius)) {
        radius = NULL;
    }
    if (radius) { 
    if(!cJSON_IsNumber(radius))
    {
    goto end; //Numeric
    }
    }


    model_frame_home_local_var = model_frame_home_create_internal (
        top->valuedouble,
        left->valuedouble,
        width->valuedouble,
        height->valuedouble,
        radius ? radius->valuedouble : 0
        );

    return model_frame_home_local_var;
end:
    return NULL;

}
