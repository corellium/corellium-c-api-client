#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "flavor_frame_inner.h"



static flavor_frame_inner_t *flavor_frame_inner_create_internal(
    double top,
    double left,
    double width,
    double height
    ) {
    flavor_frame_inner_t *flavor_frame_inner_local_var = malloc(sizeof(flavor_frame_inner_t));
    if (!flavor_frame_inner_local_var) {
        return NULL;
    }
    flavor_frame_inner_local_var->top = top;
    flavor_frame_inner_local_var->left = left;
    flavor_frame_inner_local_var->width = width;
    flavor_frame_inner_local_var->height = height;

    flavor_frame_inner_local_var->_library_owned = 1;
    return flavor_frame_inner_local_var;
}

__attribute__((deprecated)) flavor_frame_inner_t *flavor_frame_inner_create(
    double top,
    double left,
    double width,
    double height
    ) {
    return flavor_frame_inner_create_internal (
        top,
        left,
        width,
        height
        );
}

void flavor_frame_inner_free(flavor_frame_inner_t *flavor_frame_inner) {
    if(NULL == flavor_frame_inner){
        return ;
    }
    if(flavor_frame_inner->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "flavor_frame_inner_free");
        return ;
    }
    listEntry_t *listEntry;
    free(flavor_frame_inner);
}

cJSON *flavor_frame_inner_convertToJSON(flavor_frame_inner_t *flavor_frame_inner) {
    cJSON *item = cJSON_CreateObject();

    // flavor_frame_inner->top
    if (!flavor_frame_inner->top) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "top", flavor_frame_inner->top) == NULL) {
    goto fail; //Numeric
    }


    // flavor_frame_inner->left
    if (!flavor_frame_inner->left) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "left", flavor_frame_inner->left) == NULL) {
    goto fail; //Numeric
    }


    // flavor_frame_inner->width
    if (!flavor_frame_inner->width) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "width", flavor_frame_inner->width) == NULL) {
    goto fail; //Numeric
    }


    // flavor_frame_inner->height
    if (!flavor_frame_inner->height) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "height", flavor_frame_inner->height) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

flavor_frame_inner_t *flavor_frame_inner_parseFromJSON(cJSON *flavor_frame_innerJSON){

    flavor_frame_inner_t *flavor_frame_inner_local_var = NULL;

    // flavor_frame_inner->top
    cJSON *top = cJSON_GetObjectItemCaseSensitive(flavor_frame_innerJSON, "top");
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

    // flavor_frame_inner->left
    cJSON *left = cJSON_GetObjectItemCaseSensitive(flavor_frame_innerJSON, "left");
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

    // flavor_frame_inner->width
    cJSON *width = cJSON_GetObjectItemCaseSensitive(flavor_frame_innerJSON, "width");
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

    // flavor_frame_inner->height
    cJSON *height = cJSON_GetObjectItemCaseSensitive(flavor_frame_innerJSON, "height");
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


    flavor_frame_inner_local_var = flavor_frame_inner_create_internal (
        top->valuedouble,
        left->valuedouble,
        width->valuedouble,
        height->valuedouble
        );

    return flavor_frame_inner_local_var;
end:
    return NULL;

}
