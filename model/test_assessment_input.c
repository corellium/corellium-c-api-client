#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "test_assessment_input.h"



static test_assessment_input_t *test_assessment_input_create_internal(
    int invert,
    char *grep
    ) {
    test_assessment_input_t *test_assessment_input_local_var = malloc(sizeof(test_assessment_input_t));
    if (!test_assessment_input_local_var) {
        return NULL;
    }
    test_assessment_input_local_var->invert = invert;
    test_assessment_input_local_var->grep = grep;

    test_assessment_input_local_var->_library_owned = 1;
    return test_assessment_input_local_var;
}

__attribute__((deprecated)) test_assessment_input_t *test_assessment_input_create(
    int invert,
    char *grep
    ) {
    return test_assessment_input_create_internal (
        invert,
        grep
        );
}

void test_assessment_input_free(test_assessment_input_t *test_assessment_input) {
    if(NULL == test_assessment_input){
        return ;
    }
    if(test_assessment_input->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "test_assessment_input_free");
        return ;
    }
    listEntry_t *listEntry;
    if (test_assessment_input->grep) {
        free(test_assessment_input->grep);
        test_assessment_input->grep = NULL;
    }
    free(test_assessment_input);
}

cJSON *test_assessment_input_convertToJSON(test_assessment_input_t *test_assessment_input) {
    cJSON *item = cJSON_CreateObject();

    // test_assessment_input->invert
    if(test_assessment_input->invert) {
    if(cJSON_AddBoolToObject(item, "invert", test_assessment_input->invert) == NULL) {
    goto fail; //Bool
    }
    }


    // test_assessment_input->grep
    if(test_assessment_input->grep) {
    if(cJSON_AddStringToObject(item, "grep", test_assessment_input->grep) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

test_assessment_input_t *test_assessment_input_parseFromJSON(cJSON *test_assessment_inputJSON){

    test_assessment_input_t *test_assessment_input_local_var = NULL;

    // test_assessment_input->invert
    cJSON *invert = cJSON_GetObjectItemCaseSensitive(test_assessment_inputJSON, "invert");
    if (cJSON_IsNull(invert)) {
        invert = NULL;
    }
    if (invert) { 
    if(!cJSON_IsBool(invert))
    {
    goto end; //Bool
    }
    }

    // test_assessment_input->grep
    cJSON *grep = cJSON_GetObjectItemCaseSensitive(test_assessment_inputJSON, "grep");
    if (cJSON_IsNull(grep)) {
        grep = NULL;
    }
    if (grep) { 
    if(!cJSON_IsString(grep) && !cJSON_IsNull(grep))
    {
    goto end; //String
    }
    }


    test_assessment_input_local_var = test_assessment_input_create_internal (
        invert ? invert->valueint : 0,
        grep && !cJSON_IsNull(grep) ? strdup(grep->valuestring) : NULL
        );

    return test_assessment_input_local_var;
end:
    return NULL;

}
