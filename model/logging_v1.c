#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "logging_v1.h"



static logging_v1_t *logging_v1_create_internal(
    int development,
    int throw_warnings
    ) {
    logging_v1_t *logging_v1_local_var = malloc(sizeof(logging_v1_t));
    if (!logging_v1_local_var) {
        return NULL;
    }
    logging_v1_local_var->development = development;
    logging_v1_local_var->throw_warnings = throw_warnings;

    logging_v1_local_var->_library_owned = 1;
    return logging_v1_local_var;
}

__attribute__((deprecated)) logging_v1_t *logging_v1_create(
    int development,
    int throw_warnings
    ) {
    return logging_v1_create_internal (
        development,
        throw_warnings
        );
}

void logging_v1_free(logging_v1_t *logging_v1) {
    if(NULL == logging_v1){
        return ;
    }
    if(logging_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "logging_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    free(logging_v1);
}

cJSON *logging_v1_convertToJSON(logging_v1_t *logging_v1) {
    cJSON *item = cJSON_CreateObject();

    // logging_v1->development
    if(logging_v1->development) {
    if(cJSON_AddBoolToObject(item, "development", logging_v1->development) == NULL) {
    goto fail; //Bool
    }
    }


    // logging_v1->throw_warnings
    if(logging_v1->throw_warnings) {
    if(cJSON_AddBoolToObject(item, "throwWarnings", logging_v1->throw_warnings) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

logging_v1_t *logging_v1_parseFromJSON(cJSON *logging_v1JSON){

    logging_v1_t *logging_v1_local_var = NULL;

    // logging_v1->development
    cJSON *development = cJSON_GetObjectItemCaseSensitive(logging_v1JSON, "development");
    if (cJSON_IsNull(development)) {
        development = NULL;
    }
    if (development) { 
    if(!cJSON_IsBool(development))
    {
    goto end; //Bool
    }
    }

    // logging_v1->throw_warnings
    cJSON *throw_warnings = cJSON_GetObjectItemCaseSensitive(logging_v1JSON, "throwWarnings");
    if (cJSON_IsNull(throw_warnings)) {
        throw_warnings = NULL;
    }
    if (throw_warnings) { 
    if(!cJSON_IsBool(throw_warnings))
    {
    goto end; //Bool
    }
    }


    logging_v1_local_var = logging_v1_create_internal (
        development ? development->valueint : 0,
        throw_warnings ? throw_warnings->valueint : 0
        );

    return logging_v1_local_var;
end:
    return NULL;

}
