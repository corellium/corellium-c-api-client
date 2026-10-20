#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "model_frame_dimensions.h"



static model_frame_dimensions_t *model_frame_dimensions_create_internal(
    double width,
    double height
    ) {
    model_frame_dimensions_t *model_frame_dimensions_local_var = malloc(sizeof(model_frame_dimensions_t));
    if (!model_frame_dimensions_local_var) {
        return NULL;
    }
    model_frame_dimensions_local_var->width = width;
    model_frame_dimensions_local_var->height = height;

    model_frame_dimensions_local_var->_library_owned = 1;
    return model_frame_dimensions_local_var;
}

__attribute__((deprecated)) model_frame_dimensions_t *model_frame_dimensions_create(
    double width,
    double height
    ) {
    return model_frame_dimensions_create_internal (
        width,
        height
        );
}

void model_frame_dimensions_free(model_frame_dimensions_t *model_frame_dimensions) {
    if(NULL == model_frame_dimensions){
        return ;
    }
    if(model_frame_dimensions->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "model_frame_dimensions_free");
        return ;
    }
    listEntry_t *listEntry;
    free(model_frame_dimensions);
}

cJSON *model_frame_dimensions_convertToJSON(model_frame_dimensions_t *model_frame_dimensions) {
    cJSON *item = cJSON_CreateObject();

    // model_frame_dimensions->width
    if (!model_frame_dimensions->width) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "width", model_frame_dimensions->width) == NULL) {
    goto fail; //Numeric
    }


    // model_frame_dimensions->height
    if (!model_frame_dimensions->height) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "height", model_frame_dimensions->height) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

model_frame_dimensions_t *model_frame_dimensions_parseFromJSON(cJSON *model_frame_dimensionsJSON){

    model_frame_dimensions_t *model_frame_dimensions_local_var = NULL;

    // model_frame_dimensions->width
    cJSON *width = cJSON_GetObjectItemCaseSensitive(model_frame_dimensionsJSON, "width");
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

    // model_frame_dimensions->height
    cJSON *height = cJSON_GetObjectItemCaseSensitive(model_frame_dimensionsJSON, "height");
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


    model_frame_dimensions_local_var = model_frame_dimensions_create_internal (
        width->valuedouble,
        height->valuedouble
        );

    return model_frame_dimensions_local_var;
end:
    return NULL;

}
