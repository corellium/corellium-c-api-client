#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "logging.h"



static logging_t *logging_create_internal(
    int development,
    int throw_warnings
    ) {
    logging_t *logging_local_var = malloc(sizeof(logging_t));
    if (!logging_local_var) {
        return NULL;
    }
    logging_local_var->development = development;
    logging_local_var->throw_warnings = throw_warnings;

    logging_local_var->_library_owned = 1;
    return logging_local_var;
}

__attribute__((deprecated)) logging_t *logging_create(
    int development,
    int throw_warnings
    ) {
    return logging_create_internal (
        development,
        throw_warnings
        );
}

void logging_free(logging_t *logging) {
    if(NULL == logging){
        return ;
    }
    if(logging->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "logging_free");
        return ;
    }
    listEntry_t *listEntry;
    free(logging);
}

cJSON *logging_convertToJSON(logging_t *logging) {
    cJSON *item = cJSON_CreateObject();

    // logging->development
    if (!logging->development) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "development", logging->development) == NULL) {
    goto fail; //Bool
    }


    // logging->throw_warnings
    if (!logging->throw_warnings) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "throwWarnings", logging->throw_warnings) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

logging_t *logging_parseFromJSON(cJSON *loggingJSON){

    logging_t *logging_local_var = NULL;

    // logging->development
    cJSON *development = cJSON_GetObjectItemCaseSensitive(loggingJSON, "development");
    if (cJSON_IsNull(development)) {
        development = NULL;
    }
    if (!development) {
        goto end;
    }

    
    if(!cJSON_IsBool(development))
    {
    goto end; //Bool
    }

    // logging->throw_warnings
    cJSON *throw_warnings = cJSON_GetObjectItemCaseSensitive(loggingJSON, "throwWarnings");
    if (cJSON_IsNull(throw_warnings)) {
        throw_warnings = NULL;
    }
    if (!throw_warnings) {
        goto end;
    }

    
    if(!cJSON_IsBool(throw_warnings))
    {
    goto end; //Bool
    }


    logging_local_var = logging_create_internal (
        development->valueint,
        throw_warnings->valueint
        );

    return logging_local_var;
end:
    return NULL;

}
