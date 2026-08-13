#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "rotate_body_orientation.h"



static rotate_body_orientation_t *rotate_body_orientation_create_internal(
    ) {
    rotate_body_orientation_t *rotate_body_orientation_local_var = malloc(sizeof(rotate_body_orientation_t));
    if (!rotate_body_orientation_local_var) {
        return NULL;
    }

    rotate_body_orientation_local_var->_library_owned = 1;
    return rotate_body_orientation_local_var;
}

__attribute__((deprecated)) rotate_body_orientation_t *rotate_body_orientation_create(
    ) {
    return rotate_body_orientation_create_internal (
        );
}

void rotate_body_orientation_free(rotate_body_orientation_t *rotate_body_orientation) {
    if(NULL == rotate_body_orientation){
        return ;
    }
    if(rotate_body_orientation->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "rotate_body_orientation_free");
        return ;
    }
    listEntry_t *listEntry;
    free(rotate_body_orientation);
}

cJSON *rotate_body_orientation_convertToJSON(rotate_body_orientation_t *rotate_body_orientation) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

rotate_body_orientation_t *rotate_body_orientation_parseFromJSON(cJSON *rotate_body_orientationJSON){

    rotate_body_orientation_t *rotate_body_orientation_local_var = NULL;


    rotate_body_orientation_local_var = rotate_body_orientation_create_internal (
        );

    return rotate_body_orientation_local_var;
end:
    return NULL;

}
