#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "model_frame.h"



static model_frame_t *model_frame_create_internal(
    double width,
    double height,
    model_rect_t *inner,
    model_frame_home_t *home,
    flavor_frame_dimensions_t *dimensions,
    double scale,
    int has_image
    ) {
    model_frame_t *model_frame_local_var = malloc(sizeof(model_frame_t));
    if (!model_frame_local_var) {
        return NULL;
    }
    model_frame_local_var->width = width;
    model_frame_local_var->height = height;
    model_frame_local_var->inner = inner;
    model_frame_local_var->home = home;
    model_frame_local_var->dimensions = dimensions;
    model_frame_local_var->scale = scale;
    model_frame_local_var->has_image = has_image;

    model_frame_local_var->_library_owned = 1;
    return model_frame_local_var;
}

__attribute__((deprecated)) model_frame_t *model_frame_create(
    double width,
    double height,
    model_rect_t *inner,
    model_frame_home_t *home,
    flavor_frame_dimensions_t *dimensions,
    double scale,
    int has_image
    ) {
    return model_frame_create_internal (
        width,
        height,
        inner,
        home,
        dimensions,
        scale,
        has_image
        );
}

void model_frame_free(model_frame_t *model_frame) {
    if(NULL == model_frame){
        return ;
    }
    if(model_frame->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "model_frame_free");
        return ;
    }
    listEntry_t *listEntry;
    if (model_frame->inner) {
        model_rect_free(model_frame->inner);
        model_frame->inner = NULL;
    }
    if (model_frame->home) {
        model_frame_home_free(model_frame->home);
        model_frame->home = NULL;
    }
    if (model_frame->dimensions) {
        flavor_frame_dimensions_free(model_frame->dimensions);
        model_frame->dimensions = NULL;
    }
    free(model_frame);
}

cJSON *model_frame_convertToJSON(model_frame_t *model_frame) {
    cJSON *item = cJSON_CreateObject();

    // model_frame->width
    if (!model_frame->width) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "width", model_frame->width) == NULL) {
    goto fail; //Numeric
    }


    // model_frame->height
    if (!model_frame->height) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "height", model_frame->height) == NULL) {
    goto fail; //Numeric
    }


    // model_frame->inner
    if(model_frame->inner) {
    cJSON *inner_local_JSON = model_rect_convertToJSON(model_frame->inner);
    if(inner_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "inner", inner_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // model_frame->home
    if(model_frame->home) {
    cJSON *home_local_JSON = model_frame_home_convertToJSON(model_frame->home);
    if(home_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "home", home_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // model_frame->dimensions
    if(model_frame->dimensions) {
    cJSON *dimensions_local_JSON = flavor_frame_dimensions_convertToJSON(model_frame->dimensions);
    if(dimensions_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "dimensions", dimensions_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // model_frame->scale
    if(model_frame->scale) {
    if(cJSON_AddNumberToObject(item, "scale", model_frame->scale) == NULL) {
    goto fail; //Numeric
    }
    }


    // model_frame->has_image
    if (!model_frame->has_image) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "hasImage", model_frame->has_image) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

model_frame_t *model_frame_parseFromJSON(cJSON *model_frameJSON){

    model_frame_t *model_frame_local_var = NULL;

    // define the local variable for model_frame->inner
    model_rect_t *inner_local_nonprim = NULL;

    // define the local variable for model_frame->home
    model_frame_home_t *home_local_nonprim = NULL;

    // define the local variable for model_frame->dimensions
    flavor_frame_dimensions_t *dimensions_local_nonprim = NULL;

    // model_frame->width
    cJSON *width = cJSON_GetObjectItemCaseSensitive(model_frameJSON, "width");
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

    // model_frame->height
    cJSON *height = cJSON_GetObjectItemCaseSensitive(model_frameJSON, "height");
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

    // model_frame->inner
    cJSON *inner = cJSON_GetObjectItemCaseSensitive(model_frameJSON, "inner");
    if (cJSON_IsNull(inner)) {
        inner = NULL;
    }
    if (inner) { 
    inner_local_nonprim = model_rect_parseFromJSON(inner); //nonprimitive
    }

    // model_frame->home
    cJSON *home = cJSON_GetObjectItemCaseSensitive(model_frameJSON, "home");
    if (cJSON_IsNull(home)) {
        home = NULL;
    }
    if (home) { 
    home_local_nonprim = model_frame_home_parseFromJSON(home); //nonprimitive
    }

    // model_frame->dimensions
    cJSON *dimensions = cJSON_GetObjectItemCaseSensitive(model_frameJSON, "dimensions");
    if (cJSON_IsNull(dimensions)) {
        dimensions = NULL;
    }
    if (dimensions) { 
    dimensions_local_nonprim = flavor_frame_dimensions_parseFromJSON(dimensions); //nonprimitive
    }

    // model_frame->scale
    cJSON *scale = cJSON_GetObjectItemCaseSensitive(model_frameJSON, "scale");
    if (cJSON_IsNull(scale)) {
        scale = NULL;
    }
    if (scale) { 
    if(!cJSON_IsNumber(scale))
    {
    goto end; //Numeric
    }
    }

    // model_frame->has_image
    cJSON *has_image = cJSON_GetObjectItemCaseSensitive(model_frameJSON, "hasImage");
    if (cJSON_IsNull(has_image)) {
        has_image = NULL;
    }
    if (!has_image) {
        goto end;
    }

    
    if(!cJSON_IsBool(has_image))
    {
    goto end; //Bool
    }


    model_frame_local_var = model_frame_create_internal (
        width->valuedouble,
        height->valuedouble,
        inner ? inner_local_nonprim : NULL,
        home ? home_local_nonprim : NULL,
        dimensions ? dimensions_local_nonprim : NULL,
        scale ? scale->valuedouble : 0,
        has_image->valueint
        );

    return model_frame_local_var;
end:
    if (inner_local_nonprim) {
        model_rect_free(inner_local_nonprim);
        inner_local_nonprim = NULL;
    }
    if (home_local_nonprim) {
        model_frame_home_free(home_local_nonprim);
        home_local_nonprim = NULL;
    }
    if (dimensions_local_nonprim) {
        flavor_frame_dimensions_free(dimensions_local_nonprim);
        dimensions_local_nonprim = NULL;
    }
    return NULL;

}
