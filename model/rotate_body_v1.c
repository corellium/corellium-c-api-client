#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "rotate_body_v1.h"


char* rotate_body_v1_orientation_ToString(corellium_api_rotate_body_v1_ORIENTATION_e orientation) {
    char* orientationArray[] =  { "NULL", "1", "2", "3", "4" };
    return orientationArray[orientation];
}

corellium_api_rotate_body_v1_ORIENTATION_e rotate_body_v1_orientation_FromString(char* orientation){
    int stringToReturn = 0;
    char *orientationArray[] =  { "NULL", "1", "2", "3", "4" };
    size_t sizeofArray = sizeof(orientationArray) / sizeof(orientationArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(orientation, orientationArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static rotate_body_v1_t *rotate_body_v1_create_internal(
    double orientation
    ) {
    rotate_body_v1_t *rotate_body_v1_local_var = malloc(sizeof(rotate_body_v1_t));
    if (!rotate_body_v1_local_var) {
        return NULL;
    }
    rotate_body_v1_local_var->orientation = orientation;

    rotate_body_v1_local_var->_library_owned = 1;
    return rotate_body_v1_local_var;
}

__attribute__((deprecated)) rotate_body_v1_t *rotate_body_v1_create(
    double orientation
    ) {
    return rotate_body_v1_create_internal (
        orientation
        );
}

void rotate_body_v1_free(rotate_body_v1_t *rotate_body_v1) {
    if(NULL == rotate_body_v1){
        return ;
    }
    if(rotate_body_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "rotate_body_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    free(rotate_body_v1);
}

cJSON *rotate_body_v1_convertToJSON(rotate_body_v1_t *rotate_body_v1) {
    cJSON *item = cJSON_CreateObject();

    // rotate_body_v1->orientation
    if (corellium_api_rotate_body_v1_ORIENTATION_NULL == rotate_body_v1->orientation) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "orientation", rotate_body_v1->orientation) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

rotate_body_v1_t *rotate_body_v1_parseFromJSON(cJSON *rotate_body_v1JSON){

    rotate_body_v1_t *rotate_body_v1_local_var = NULL;

    // rotate_body_v1->orientation
    cJSON *orientation = cJSON_GetObjectItemCaseSensitive(rotate_body_v1JSON, "orientation");
    if (cJSON_IsNull(orientation)) {
        orientation = NULL;
    }
    if (!orientation) {
        goto end;
    }

    
    if(!cJSON_IsNumber(orientation))
    {
    goto end; //Numeric
    }


    rotate_body_v1_local_var = rotate_body_v1_create_internal (
        orientation->valuedouble
        );

    return rotate_body_v1_local_var;
end:
    return NULL;

}
