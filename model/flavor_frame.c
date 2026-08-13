#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "flavor_frame.h"



static flavor_frame_t *flavor_frame_create_internal(
    char *url,
    double width,
    double height,
    flavor_frame_inner_t *inner,
    flavor_frame_home_t *home,
    flavor_frame_dimensions_t *dimensions,
    double scale
    ) {
    flavor_frame_t *flavor_frame_local_var = malloc(sizeof(flavor_frame_t));
    if (!flavor_frame_local_var) {
        return NULL;
    }
    flavor_frame_local_var->url = url;
    flavor_frame_local_var->width = width;
    flavor_frame_local_var->height = height;
    flavor_frame_local_var->inner = inner;
    flavor_frame_local_var->home = home;
    flavor_frame_local_var->dimensions = dimensions;
    flavor_frame_local_var->scale = scale;

    flavor_frame_local_var->_library_owned = 1;
    return flavor_frame_local_var;
}

__attribute__((deprecated)) flavor_frame_t *flavor_frame_create(
    char *url,
    double width,
    double height,
    flavor_frame_inner_t *inner,
    flavor_frame_home_t *home,
    flavor_frame_dimensions_t *dimensions,
    double scale
    ) {
    return flavor_frame_create_internal (
        url,
        width,
        height,
        inner,
        home,
        dimensions,
        scale
        );
}

void flavor_frame_free(flavor_frame_t *flavor_frame) {
    if(NULL == flavor_frame){
        return ;
    }
    if(flavor_frame->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "flavor_frame_free");
        return ;
    }
    listEntry_t *listEntry;
    if (flavor_frame->url) {
        free(flavor_frame->url);
        flavor_frame->url = NULL;
    }
    if (flavor_frame->inner) {
        flavor_frame_inner_free(flavor_frame->inner);
        flavor_frame->inner = NULL;
    }
    if (flavor_frame->home) {
        flavor_frame_home_free(flavor_frame->home);
        flavor_frame->home = NULL;
    }
    if (flavor_frame->dimensions) {
        flavor_frame_dimensions_free(flavor_frame->dimensions);
        flavor_frame->dimensions = NULL;
    }
    free(flavor_frame);
}

cJSON *flavor_frame_convertToJSON(flavor_frame_t *flavor_frame) {
    cJSON *item = cJSON_CreateObject();

    // flavor_frame->url
    if (!flavor_frame->url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "url", flavor_frame->url) == NULL) {
    goto fail; //String
    }


    // flavor_frame->width
    if (!flavor_frame->width) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "width", flavor_frame->width) == NULL) {
    goto fail; //Numeric
    }


    // flavor_frame->height
    if (!flavor_frame->height) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "height", flavor_frame->height) == NULL) {
    goto fail; //Numeric
    }


    // flavor_frame->inner
    if (!flavor_frame->inner) {
        goto fail;
    }
    cJSON *inner_local_JSON = flavor_frame_inner_convertToJSON(flavor_frame->inner);
    if(inner_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "inner", inner_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // flavor_frame->home
    if (!flavor_frame->home) {
        goto fail;
    }
    cJSON *home_local_JSON = flavor_frame_home_convertToJSON(flavor_frame->home);
    if(home_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "home", home_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // flavor_frame->dimensions
    if (!flavor_frame->dimensions) {
        goto fail;
    }
    cJSON *dimensions_local_JSON = flavor_frame_dimensions_convertToJSON(flavor_frame->dimensions);
    if(dimensions_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "dimensions", dimensions_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // flavor_frame->scale
    if (!flavor_frame->scale) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "scale", flavor_frame->scale) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

flavor_frame_t *flavor_frame_parseFromJSON(cJSON *flavor_frameJSON){

    flavor_frame_t *flavor_frame_local_var = NULL;

    // define the local variable for flavor_frame->inner
    flavor_frame_inner_t *inner_local_nonprim = NULL;

    // define the local variable for flavor_frame->home
    flavor_frame_home_t *home_local_nonprim = NULL;

    // define the local variable for flavor_frame->dimensions
    flavor_frame_dimensions_t *dimensions_local_nonprim = NULL;

    // flavor_frame->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(flavor_frameJSON, "url");
    if (cJSON_IsNull(url)) {
        url = NULL;
    }
    if (!url) {
        goto end;
    }

    
    if(!cJSON_IsString(url))
    {
    goto end; //String
    }

    // flavor_frame->width
    cJSON *width = cJSON_GetObjectItemCaseSensitive(flavor_frameJSON, "width");
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

    // flavor_frame->height
    cJSON *height = cJSON_GetObjectItemCaseSensitive(flavor_frameJSON, "height");
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

    // flavor_frame->inner
    cJSON *inner = cJSON_GetObjectItemCaseSensitive(flavor_frameJSON, "inner");
    if (cJSON_IsNull(inner)) {
        inner = NULL;
    }
    if (!inner) {
        goto end;
    }

    
    inner_local_nonprim = flavor_frame_inner_parseFromJSON(inner); //nonprimitive

    // flavor_frame->home
    cJSON *home = cJSON_GetObjectItemCaseSensitive(flavor_frameJSON, "home");
    if (cJSON_IsNull(home)) {
        home = NULL;
    }
    if (!home) {
        goto end;
    }

    
    home_local_nonprim = flavor_frame_home_parseFromJSON(home); //nonprimitive

    // flavor_frame->dimensions
    cJSON *dimensions = cJSON_GetObjectItemCaseSensitive(flavor_frameJSON, "dimensions");
    if (cJSON_IsNull(dimensions)) {
        dimensions = NULL;
    }
    if (!dimensions) {
        goto end;
    }

    
    dimensions_local_nonprim = flavor_frame_dimensions_parseFromJSON(dimensions); //nonprimitive

    // flavor_frame->scale
    cJSON *scale = cJSON_GetObjectItemCaseSensitive(flavor_frameJSON, "scale");
    if (cJSON_IsNull(scale)) {
        scale = NULL;
    }
    if (!scale) {
        goto end;
    }

    
    if(!cJSON_IsNumber(scale))
    {
    goto end; //Numeric
    }


    flavor_frame_local_var = flavor_frame_create_internal (
        strdup(url->valuestring),
        width->valuedouble,
        height->valuedouble,
        inner_local_nonprim,
        home_local_nonprim,
        dimensions_local_nonprim,
        scale->valuedouble
        );

    return flavor_frame_local_var;
end:
    if (inner_local_nonprim) {
        flavor_frame_inner_free(inner_local_nonprim);
        inner_local_nonprim = NULL;
    }
    if (home_local_nonprim) {
        flavor_frame_home_free(home_local_nonprim);
        home_local_nonprim = NULL;
    }
    if (dimensions_local_nonprim) {
        flavor_frame_dimensions_free(dimensions_local_nonprim);
        dimensions_local_nonprim = NULL;
    }
    return NULL;

}
