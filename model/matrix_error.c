#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "matrix_error.h"



static matrix_error_t *matrix_error_create_internal(
    char *error
    ) {
    matrix_error_t *matrix_error_local_var = malloc(sizeof(matrix_error_t));
    if (!matrix_error_local_var) {
        return NULL;
    }
    matrix_error_local_var->error = error;

    matrix_error_local_var->_library_owned = 1;
    return matrix_error_local_var;
}

__attribute__((deprecated)) matrix_error_t *matrix_error_create(
    char *error
    ) {
    return matrix_error_create_internal (
        error
        );
}

void matrix_error_free(matrix_error_t *matrix_error) {
    if(NULL == matrix_error){
        return ;
    }
    if(matrix_error->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "matrix_error_free");
        return ;
    }
    listEntry_t *listEntry;
    if (matrix_error->error) {
        free(matrix_error->error);
        matrix_error->error = NULL;
    }
    free(matrix_error);
}

cJSON *matrix_error_convertToJSON(matrix_error_t *matrix_error) {
    cJSON *item = cJSON_CreateObject();

    // matrix_error->error
    if (!matrix_error->error) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "error", matrix_error->error) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

matrix_error_t *matrix_error_parseFromJSON(cJSON *matrix_errorJSON){

    matrix_error_t *matrix_error_local_var = NULL;

    // matrix_error->error
    cJSON *error = cJSON_GetObjectItemCaseSensitive(matrix_errorJSON, "error");
    if (cJSON_IsNull(error)) {
        error = NULL;
    }
    if (!error) {
        goto end;
    }

    
    if(!cJSON_IsString(error))
    {
    goto end; //String
    }


    matrix_error_local_var = matrix_error_create_internal (
        strdup(error->valuestring)
        );

    return matrix_error_local_var;
end:
    return NULL;

}
