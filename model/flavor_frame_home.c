#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "flavor_frame_home.h"



static flavor_frame_home_t *flavor_frame_home_create_internal(
    double top,
    double left,
    double width,
    double height
    ) {
    flavor_frame_home_t *flavor_frame_home_local_var = malloc(sizeof(flavor_frame_home_t));
    if (!flavor_frame_home_local_var) {
        return NULL;
    }
    flavor_frame_home_local_var->top = top;
    flavor_frame_home_local_var->left = left;
    flavor_frame_home_local_var->width = width;
    flavor_frame_home_local_var->height = height;

    flavor_frame_home_local_var->_library_owned = 1;
    return flavor_frame_home_local_var;
}

__attribute__((deprecated)) flavor_frame_home_t *flavor_frame_home_create(
    double top,
    double left,
    double width,
    double height
    ) {
    return flavor_frame_home_create_internal (
        top,
        left,
        width,
        height
        );
}

void flavor_frame_home_free(flavor_frame_home_t *flavor_frame_home) {
    if(NULL == flavor_frame_home){
        return ;
    }
    if(flavor_frame_home->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "flavor_frame_home_free");
        return ;
    }
    listEntry_t *listEntry;
    free(flavor_frame_home);
}

cJSON *flavor_frame_home_convertToJSON(flavor_frame_home_t *flavor_frame_home) {
    cJSON *item = cJSON_CreateObject();

    // flavor_frame_home->top
    if (!flavor_frame_home->top) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "top", flavor_frame_home->top) == NULL) {
    goto fail; //Numeric
    }


    // flavor_frame_home->left
    if (!flavor_frame_home->left) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "left", flavor_frame_home->left) == NULL) {
    goto fail; //Numeric
    }


    // flavor_frame_home->width
    if (!flavor_frame_home->width) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "width", flavor_frame_home->width) == NULL) {
    goto fail; //Numeric
    }


    // flavor_frame_home->height
    if (!flavor_frame_home->height) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "height", flavor_frame_home->height) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

flavor_frame_home_t *flavor_frame_home_parseFromJSON(cJSON *flavor_frame_homeJSON){

    flavor_frame_home_t *flavor_frame_home_local_var = NULL;

    // flavor_frame_home->top
    cJSON *top = cJSON_GetObjectItemCaseSensitive(flavor_frame_homeJSON, "top");
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

    // flavor_frame_home->left
    cJSON *left = cJSON_GetObjectItemCaseSensitive(flavor_frame_homeJSON, "left");
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

    // flavor_frame_home->width
    cJSON *width = cJSON_GetObjectItemCaseSensitive(flavor_frame_homeJSON, "width");
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

    // flavor_frame_home->height
    cJSON *height = cJSON_GetObjectItemCaseSensitive(flavor_frame_homeJSON, "height");
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


    flavor_frame_home_local_var = flavor_frame_home_create_internal (
        top->valuedouble,
        left->valuedouble,
        width->valuedouble,
        height->valuedouble
        );

    return flavor_frame_home_local_var;
end:
    return NULL;

}
