#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "flavor_frame_dimensions.h"



static flavor_frame_dimensions_t *flavor_frame_dimensions_create_internal(
    double width,
    double height
    ) {
    flavor_frame_dimensions_t *flavor_frame_dimensions_local_var = malloc(sizeof(flavor_frame_dimensions_t));
    if (!flavor_frame_dimensions_local_var) {
        return NULL;
    }
    flavor_frame_dimensions_local_var->width = width;
    flavor_frame_dimensions_local_var->height = height;

    flavor_frame_dimensions_local_var->_library_owned = 1;
    return flavor_frame_dimensions_local_var;
}

__attribute__((deprecated)) flavor_frame_dimensions_t *flavor_frame_dimensions_create(
    double width,
    double height
    ) {
    return flavor_frame_dimensions_create_internal (
        width,
        height
        );
}

void flavor_frame_dimensions_free(flavor_frame_dimensions_t *flavor_frame_dimensions) {
    if(NULL == flavor_frame_dimensions){
        return ;
    }
    if(flavor_frame_dimensions->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "flavor_frame_dimensions_free");
        return ;
    }
    listEntry_t *listEntry;
    free(flavor_frame_dimensions);
}

cJSON *flavor_frame_dimensions_convertToJSON(flavor_frame_dimensions_t *flavor_frame_dimensions) {
    cJSON *item = cJSON_CreateObject();

    // flavor_frame_dimensions->width
    if (!flavor_frame_dimensions->width) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "width", flavor_frame_dimensions->width) == NULL) {
    goto fail; //Numeric
    }


    // flavor_frame_dimensions->height
    if (!flavor_frame_dimensions->height) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "height", flavor_frame_dimensions->height) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

flavor_frame_dimensions_t *flavor_frame_dimensions_parseFromJSON(cJSON *flavor_frame_dimensionsJSON){

    flavor_frame_dimensions_t *flavor_frame_dimensions_local_var = NULL;

    // flavor_frame_dimensions->width
    cJSON *width = cJSON_GetObjectItemCaseSensitive(flavor_frame_dimensionsJSON, "width");
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

    // flavor_frame_dimensions->height
    cJSON *height = cJSON_GetObjectItemCaseSensitive(flavor_frame_dimensionsJSON, "height");
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


    flavor_frame_dimensions_local_var = flavor_frame_dimensions_create_internal (
        width->valuedouble,
        height->valuedouble
        );

    return flavor_frame_dimensions_local_var;
end:
    return NULL;

}
