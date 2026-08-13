#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "rotate_body.h"



static rotate_body_t *rotate_body_create_internal(
    rotate_body_orientation_t *orientation
    ) {
    rotate_body_t *rotate_body_local_var = malloc(sizeof(rotate_body_t));
    if (!rotate_body_local_var) {
        return NULL;
    }
    rotate_body_local_var->orientation = orientation;

    rotate_body_local_var->_library_owned = 1;
    return rotate_body_local_var;
}

__attribute__((deprecated)) rotate_body_t *rotate_body_create(
    rotate_body_orientation_t *orientation
    ) {
    return rotate_body_create_internal (
        orientation
        );
}

void rotate_body_free(rotate_body_t *rotate_body) {
    if(NULL == rotate_body){
        return ;
    }
    if(rotate_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "rotate_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (rotate_body->orientation) {
        rotate_body_orientation_free(rotate_body->orientation);
        rotate_body->orientation = NULL;
    }
    free(rotate_body);
}

cJSON *rotate_body_convertToJSON(rotate_body_t *rotate_body) {
    cJSON *item = cJSON_CreateObject();

    // rotate_body->orientation
    if (!rotate_body->orientation) {
        goto fail;
    }
    cJSON *orientation_local_JSON = rotate_body_orientation_convertToJSON(rotate_body->orientation);
    if(orientation_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "orientation", orientation_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

rotate_body_t *rotate_body_parseFromJSON(cJSON *rotate_bodyJSON){

    rotate_body_t *rotate_body_local_var = NULL;

    // define the local variable for rotate_body->orientation
    rotate_body_orientation_t *orientation_local_nonprim = NULL;

    // rotate_body->orientation
    cJSON *orientation = cJSON_GetObjectItemCaseSensitive(rotate_bodyJSON, "orientation");
    if (cJSON_IsNull(orientation)) {
        orientation = NULL;
    }
    if (!orientation) {
        goto end;
    }

    
    orientation_local_nonprim = rotate_body_orientation_parseFromJSON(orientation); //nonprimitive


    rotate_body_local_var = rotate_body_create_internal (
        orientation_local_nonprim
        );

    return rotate_body_local_var;
end:
    if (orientation_local_nonprim) {
        rotate_body_orientation_free(orientation_local_nonprim);
        orientation_local_nonprim = NULL;
    }
    return NULL;

}
